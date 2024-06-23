#include <glfw3webgpu.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_FORCE_LEFT_HANDED
#include <glm/glm.hpp> // all types inspired from GLSL
#include <glm/ext.hpp>

#define WEBGPU_CPP_IMPLEMENTATION
#include <webgpu/webgpu.hpp>

#define TINYOBJLOADER_IMPLEMENTATION // add this to exactly 1 of your C++ files
#include "tiny_obj_loader.h"

#include <iostream>
#include <cassert>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <array>

using namespace wgpu;
namespace fs = std::filesystem;
using glm::mat4x4;
using glm::vec4;
using glm::vec3;

constexpr float PI = 3.14159265358979323846f;

// Embedded shader module source
const char* shaderSource = R"(
@vertex
fn vs_main(@location(0) in_vertex_position: vec2f) -> @builtin(position) vec4f {
return vec4f(in_vertex_position, 0.0, 1.0); 
}

@fragment
fn fs_main() -> @location(0) vec4f {
	return vec4f(0.0, 0.4, 1.0, 1.0);
}
)";

// //  Function to hide implementation-specific device polling variants
// void wgpuPollEvents([[maybe_unused]] Device device, [[maybe_unused]] bool yieldToWebBrowser) {
// #if defined(WEBGPU_BACKEND_DAWN)
//     device.tick();
// #elif defined(WEBGPU_BACKEND_WGPU)
//     device.poll(false);
// #elif defined(WEBGPU_BACKEND_EMSCRIPTEN)
//     if (yieldToWebBrowser) {
//         emscripten_sleep(100);
//     }
// #endif
// }

class Application {
public:
	// Initialize application components and return success status
	bool Initialize();

	// Clean up all initialized resources and state
	void Terminate();

	// Process events and render a frame
	void MainLoop();

	// Determine if application's main loop should continue running
	bool IsRunning();

private:
	TextureView GetNextSurfaceTextureView();

	// Create the render pipline during initialization
	void InitializePipeline();

	RequiredLimits GetRequiredLimits(Adapter adapter) const;

	// Buffer 
	void InitializeBuffers();

private:
	// Variables shared between initialization and main loop
	GLFWwindow *window;
	Device device;
	Queue queue;
	Surface surface;
	std::unique_ptr<ErrorCallback> uncapturedErrorCallbackHandle;
	TextureFormat surfaceFormat = TextureFormat::Undefined;
	RenderPipeline pipeline;
	Buffer vertexBuffer;
	uint32_t vertexCount;
};

int main() {
	Application app;

	if (!app.Initialize()) {
		return 1;
	}

#ifdef __EMSCRIPTEN__
	// Equivalent of the main loop when using Emscripten:
	auto callback = [](void *arg) {
		Application* pApp = reinterpret_cast<Application*>(arg);
		pApp->MainLoop();
	};
	emscripten_set_main_loop_arg(callback, &app, 0, true);
#else // __EMSCRIPTEN__
	while (app.IsRunning()) {
		app.MainLoop();
	}
#endif // __EMSCRIPTEN__

	return 0;
}

bool Application::Initialize() {
	// Open GLFW window
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	window = glfwCreateWindow(640, 480, "Learn WebGPU", nullptr, nullptr);
	
	// Create webGPU instance
	Instance instance = wgpuCreateInstance(nullptr);
	
	// Get webGPU surface from window
	surface = glfwGetWGPUSurface(instance, window);
	
	// Request adapter
	std::cout << "Requesting adapter..." << std::endl;
	RequestAdapterOptions adapterOpts = {};
	adapterOpts.compatibleSurface = surface;
	Adapter adapter = instance.requestAdapter(adapterOpts);
	std::cout << "Got adapter: " << adapter << std::endl;
	
	instance.release(); // release adapter after request
	
	// Request device
	std::cout << "Requesting device..." << std::endl;
	DeviceDescriptor deviceDesc = {};
	deviceDesc.label = "My Device";
	deviceDesc.requiredFeatureCount = 0;
	deviceDesc.requiredLimits = nullptr;
	deviceDesc.defaultQueue.nextInChain = nullptr;
	deviceDesc.defaultQueue.label = "The default queue";
	deviceDesc.deviceLostCallback = [](WGPUDeviceLostReason reason, char const* message, void* /* pUserData */) {
		std::cout << "Device lost: reason " << reason;
		if (message) std::cout << " (" << message << ")";
		std::cout << std::endl;
	};

	// Request device from adapter
	RequiredLimits requiredLimits = GetRequiredLimits(adapter);
	deviceDesc.requiredLimits = &requiredLimits;
	device = adapter.requestDevice(deviceDesc);
	std::cout << "Got device: " << device << std::endl;
	
	// Set uncaptured error callback
	uncapturedErrorCallbackHandle = device.setUncapturedErrorCallback([](ErrorType type, char const* message) {
		std::cout << "Uncaptured device error: type " << type;
		if (message) std::cout << " (" << message << ")";
		std::cout << std::endl;
	});

	queue = device.getQueue();

	// Configure the surface
	SurfaceConfiguration config = {};
	
	// Configure textures for swap chain
	config.width = 640;
	config.height = 480;
	config.usage = TextureUsage::RenderAttachment;
	surfaceFormat = surface.getPreferredFormat(adapter);
	config.format = surfaceFormat;

	// Configure swap chain settings
	config.viewFormatCount = 0;
	config.viewFormats = nullptr;
	config.device = device;
	config.presentMode = PresentMode::Fifo;
	config.alphaMode = CompositeAlphaMode::Auto;

	// Apply configuration to surface
	surface.configure(config);

	// Release adapter
	adapter.release();

	InitializePipeline();
	InitializeBuffers();

	return true;
}

void Application::Terminate() {
	vertexBuffer.release();
	pipeline.release();
	surface.unconfigure();
	queue.release();
	surface.release();
	device.release();
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Application::MainLoop() {
	glfwPollEvents();

	// Get the next target texture view for rendering
	TextureView targetView = GetNextSurfaceTextureView();
	if (!targetView) return; // return if target view is not available

	// Create a command encoder for the draw call
	CommandEncoderDescriptor encoderDesc = {};
	encoderDesc.label = "My command encoder";
	CommandEncoder encoder = wgpuDeviceCreateCommandEncoder(device, &encoderDesc);

	// Create the render pass descriptor to clear the screen with specified color
	RenderPassDescriptor renderPassDesc = {};

	// Configure the color attachment of the render pass
	RenderPassColorAttachment renderPassColorAttachment = {};
	renderPassColorAttachment.view = targetView;
	renderPassColorAttachment.resolveTarget = nullptr;
	renderPassColorAttachment.loadOp = LoadOp::Clear;
	renderPassColorAttachment.storeOp = StoreOp::Store;
	renderPassColorAttachment.clearValue = WGPUColor{ 0.9, 0.1, 0.2, 1.0 };
#ifndef WEBGPU_BACKEND_WGPU
	renderPassColorAttachment.depthSlice = WGPU_DEPTH_SLICE_UNDEFINED;
#endif // NOT WEBGPU_BACKEND_WGPU

	// Assign the color attachment to the render pass descriptor
	renderPassDesc.colorAttachmentCount = 1;
	renderPassDesc.colorAttachments = &renderPassColorAttachment;
	renderPassDesc.depthStencilAttachment = nullptr;
	renderPassDesc.timestampWrites = nullptr;

	// Begin the render pass
	RenderPassEncoder renderPass = encoder.beginRenderPass(renderPassDesc);

	// Set the render pipeline for rendering
	renderPass.setPipeline(pipeline);

	// Set vertex buffer while encoding the render pass
	renderPass.setVertexBuffer(0, vertexBuffer, 0, vertexBuffer.getSize());

	// We use the `vertexCount` variable instead of hard-coding the vertex count
	renderPass.draw(vertexCount, 1, 0, 0);

	// End and release the render pass
	renderPass.end();
	renderPass.release();

	// Encode and submit the command buffer
	CommandBufferDescriptor cmdBufferDescriptor = {};
	cmdBufferDescriptor.label = "Command buffer";
	CommandBuffer command = encoder.finish(cmdBufferDescriptor);
	encoder.release();

	std::cout << "Submitting command..." << std::endl;
	queue.submit(1, &command); // Submit command buffer to queue
	command.release(); // Release command buffer
	std::cout << "Command submitted." << std::endl;

	// Release target texture view at end of frame
	targetView.release();

#ifndef __EMSCRIPTEN__
surface.present(); // Present the surface (swap chain) contents
#endif

#if defined(WEBGPU_BACKEND_DAWN)
device.tick(); // Tick the device for DAWN backend
#elif defined(WEBGPU_BACKEND_WGPU)
device.poll(false); // Poll the device for WGPU backend
#endif
}

bool Application::IsRunning() {
	return !glfwWindowShouldClose(window); // Check if the GLFW window should close
}

TextureView Application::GetNextSurfaceTextureView() {
	// Get the surface texture
	SurfaceTexture surfaceTexture;
	surface.getCurrentTexture(&surfaceTexture);

	// Check if getting the surface texture was successful
	if (surfaceTexture.status != SurfaceGetCurrentTextureStatus::Success) {
		return nullptr; // Return nullptr if failed to get surface texture
	}

	Texture texture = surfaceTexture.texture; // Get the texture from the surface texture

	// Create a view descriptor for the surface texture
	TextureViewDescriptor viewDescriptor;
	viewDescriptor.label = "Surface texture view";
	viewDescriptor.format = texture.getFormat();
	viewDescriptor.dimension = TextureViewDimension::_2D;
	viewDescriptor.baseMipLevel = 0;
	viewDescriptor.mipLevelCount = 1;
	viewDescriptor.baseArrayLayer = 0;
	viewDescriptor.arrayLayerCount = 1;
	viewDescriptor.aspect = TextureAspect::All;

	// Create a view for the surface texture
	TextureView targetView = texture.createView(viewDescriptor);

	return targetView; // Return the created texture view
}

void Application::InitializePipeline() {
	// Load the shader module
	ShaderModuleDescriptor shaderDesc;
#ifdef WEBGPU_BACKEND_WGPU
	shaderDesc.hintCount = 0;
	shaderDesc.hints = nullptr;
#endif

	// Configure the WGSL shader code descriptor
	ShaderModuleWGSLDescriptor shaderCodeDesc;

	// Set the chained struct's header
	shaderCodeDesc.chain.next = nullptr;
	shaderCodeDesc.chain.sType = SType::ShaderModuleWGSLDescriptor;

	// Connect the chain
	shaderDesc.nextInChain = &shaderCodeDesc.chain;
	shaderCodeDesc.code = shaderSource;
	ShaderModule shaderModule = device.createShaderModule(shaderDesc);

	// Create the render pipeline descriptor
	RenderPipelineDescriptor pipelineDesc;

	// Configure the vertex pipeline
	// We use one vertex buffer
	VertexBufferLayout vertexBufferLayout;
	VertexAttribute positionAttrib;
	// == For each attribute, describe its layout, i.e., how to interpret the raw data ==
	// Corresponds to @location(...)
	positionAttrib.shaderLocation = 0;
	// Means vec2f in the shader
	positionAttrib.format = VertexFormat::Float32x2;
	// Index of the first element
	positionAttrib.offset = 0;
	
	vertexBufferLayout.attributeCount = 1;
	vertexBufferLayout.attributes = &positionAttrib;
	
	// == Common to attributes from the same buffer ==
	vertexBufferLayout.arrayStride = 2 * sizeof(float);
	vertexBufferLayout.stepMode = VertexStepMode::Vertex;
	
	pipelineDesc.vertex.bufferCount = 1;
	pipelineDesc.vertex.buffers = &vertexBufferLayout;

	// NB: We define the 'shaderModule' in the second part of this chapter.
	// Here we tell that the programmable vertex shader stage is described
	// by the function called 'vs_main' in that module.
	pipelineDesc.vertex.module = shaderModule;
	pipelineDesc.vertex.entryPoint = "vs_main";
	pipelineDesc.vertex.constantCount = 0;
	pipelineDesc.vertex.constants = nullptr;

	// Primitive assembly configuration (triangle list, no strip indices, counter-clockwise front face)
	pipelineDesc.primitive.topology = PrimitiveTopology::TriangleList;
	pipelineDesc.primitive.stripIndexFormat = IndexFormat::Undefined;
	pipelineDesc.primitive.frontFace = FrontFace::CCW;
	pipelineDesc.primitive.cullMode = CullMode::None; // Disable face culling

	// Fragment stage configuration (fragment shader entry point, blending, color target)
	FragmentState fragmentState;
	fragmentState.module = shaderModule;
	fragmentState.entryPoint = "fs_main";
	fragmentState.constantCount = 0;
	fragmentState.constants = nullptr;

	BlendState blendState;
	blendState.color.srcFactor = BlendFactor::SrcAlpha;
	blendState.color.dstFactor = BlendFactor::OneMinusSrcAlpha;
	blendState.color.operation = BlendOperation::Add;
	blendState.alpha.srcFactor = BlendFactor::Zero;
	blendState.alpha.dstFactor = BlendFactor::One;
	blendState.alpha.operation = BlendOperation::Add;
	
	ColorTargetState colorTarget;
	colorTarget.format = surfaceFormat;
	colorTarget.blend = &blendState;
	colorTarget.writeMask = ColorWriteMask::All;

	fragmentState.targetCount = 1;
	fragmentState.targets = &colorTarget;
	pipelineDesc.fragment = &fragmentState;

	// Depth and stencil testing (none used in this example)
	pipelineDesc.depthStencil = nullptr;

	// Multisampling configuration (single sample per pixel)
	pipelineDesc.multisample.count = 1;
	pipelineDesc.multisample.mask = ~0u; // Default value, all bits enabled
	pipelineDesc.multisample.alphaToCoverageEnabled = false;
	pipelineDesc.layout = nullptr;
	
	// Create render pipeline
	pipeline = device.createRenderPipeline(pipelineDesc);

	// Release shader module
	shaderModule.release();
}

void Application::InitializeBuffers() {
	// Vertex buffer data
	// There are 2 floats per vertex, one for x and one for y.
	std::vector<float> vertexData = {
		// Define a first triangle:
		-0.5, -0.5,
		+0.5, -0.5,
		+0.0, +0.5,
	
		// Add a second triangle:
		-0.55f, -0.5,
		-0.05f, +0.5,
		-0.55f, +0.5
	};
	vertexCount = static_cast<uint32_t>(vertexData.size() / 2);
	
	// Create vertex buffer
	BufferDescriptor bufferDesc;
	bufferDesc.size = vertexData.size() * sizeof(float);
	bufferDesc.usage = BufferUsage::CopyDst | BufferUsage::Vertex; // Vertex usage here!
	bufferDesc.mappedAtCreation = false;
	vertexBuffer = device.createBuffer(bufferDesc);
	
	// Upload geometry data to the buffer
	queue.writeBuffer(vertexBuffer, 0, vertexData.data(), bufferDesc.size);
}

RequiredLimits Application::GetRequiredLimits(Adapter adapter) const {
	// Get adapter supported limits, in case we need them
	SupportedLimits supportedLimits;
	adapter.getLimits(&supportedLimits);

	// Don't forget to = Default
	RequiredLimits requiredLimits = Default;

	// We use at most 1 vertex attribute for now
	requiredLimits.limits.maxVertexAttributes = 1;
	// We should also tell that we use 1 vertex buffers
	requiredLimits.limits.maxVertexBuffers = 1;
	// Maximum size of a buffer is 6 vertices of 2 float each
	requiredLimits.limits.maxBufferSize = 6 * 2 * sizeof(float);
	// Maximum stride between 2 consecutive vertices in the vertex buffer
	requiredLimits.limits.maxVertexBufferArrayStride = 2 * sizeof(float);
	// This must be set even if we do not use storage buffers for now
	requiredLimits.limits.minStorageBufferOffsetAlignment = supportedLimits.limits.minStorageBufferOffsetAlignment;

	return requiredLimits;
}