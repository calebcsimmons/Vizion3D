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

/**
 * MyUniforms structure to hold transformation matricies, color, and time data for shader programs
 */
struct MyUniforms {
	// We add transform matrices
    mat4x4 projectionMatrix;
    mat4x4 viewMatrix;
    mat4x4 modelMatrix;
    std::array<float, 4> color;
    float time;
    float _pad[3];
};

/**
 * VertexAttributes structure to contain position, normals, and color vectors for vertex data
 */
struct VertexAttributes {
	vec3 position;
	vec3 normal;
	vec3 color;
};

// Have the compiler check byte alignment
static_assert(sizeof(MyUniforms) % 16 == 0);
// Loads a shader module from a file path for the given device.
ShaderModule loadShaderModule(const fs::path& path, Device device);

// Loading procedure
bool loadGeometryFromObj(const fs::path& path, std::vector<VertexAttributes>& vertexData);

int main (int, char**) {

	// Create a webGPU instance
	Instance instance = createInstance(InstanceDescriptor{});
	if (!instance) {
		std::cerr << "Could not initialize WebGPU!" << std::endl;
		return 1;
	}

	// Initialize GLFW
	if (!glfwInit()) {
		std::cerr << "Could not initialize GLFW!" << std::endl;
		return 1;
	}

	// Configure GLFW window hints
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	GLFWwindow* window = glfwCreateWindow(640, 480, "Learn WebGPU", NULL, NULL);
	if (!window) {
		std::cerr << "Could not open window!" << std::endl;
		return 1;
	}

	// Create a GLFW window.
	std::cout << "Requesting adapter..." << std::endl;
	Surface surface = glfwGetWGPUSurface(instance, window);
	RequestAdapterOptions adapterOpts{};
	adapterOpts.compatibleSurface = surface;
	Adapter adapter = instance.requestAdapter(adapterOpts);
	std::cout << "Got adapter: " << adapter << std::endl;

	SupportedLimits supportedLimits;
	adapter.getLimits(&supportedLimits);

	std::cout << "Requesting device..." << std::endl;
	RequiredLimits requiredLimits = Default;
	requiredLimits.limits.maxVertexAttributes = 3;
	requiredLimits.limits.maxVertexBuffers = 1;
	// Update max buffer size to allow up to 10000 vertices in the loaded file:
	requiredLimits.limits.maxBufferSize = 10000 * sizeof(VertexAttributes);
	requiredLimits.limits.maxVertexBufferArrayStride = sizeof(VertexAttributes);
	requiredLimits.limits.minStorageBufferOffsetAlignment = supportedLimits.limits.minStorageBufferOffsetAlignment;
	requiredLimits.limits.minUniformBufferOffsetAlignment = supportedLimits.limits.minUniformBufferOffsetAlignment;
	requiredLimits.limits.maxInterStageShaderComponents = 6;
	requiredLimits.limits.maxBindGroups = 1;
	requiredLimits.limits.maxUniformBuffersPerShaderStage = 1;
	requiredLimits.limits.maxUniformBufferBindingSize = 16 * 4 * sizeof(float);
	requiredLimits.limits.maxTextureDimension1D = 480;
	requiredLimits.limits.maxTextureDimension2D = 640;
	requiredLimits.limits.maxTextureArrayLayers = 1;

	DeviceDescriptor deviceDesc;
	deviceDesc.label = "My Device";
	deviceDesc.requiredFeaturesCount = 0;
	deviceDesc.requiredLimits = &requiredLimits;
	deviceDesc.defaultQueue.label = "The default queue";
	Device device = adapter.requestDevice(deviceDesc);
	std::cout << "Got device: " << device << std::endl;

	// Add an error callback for more debug info
	auto h = device.setUncapturedErrorCallback([](ErrorType type, char const* message) {
		std::cout << "Device error: type " << type;
		if (message) std::cout << " (message: " << message << ")";
		std::cout << std::endl;
	});

	Queue queue = device.getQueue();

	std::cout << "Creating swapchain..." << std::endl;
#ifdef WEBGPU_BACKEND_WGPU
	TextureFormat swapChainFormat = surface.getPreferredFormat(adapter);
#else
	TextureFormat swapChainFormat = TextureFormat::BGRA8Unorm;
#endif
	SwapChainDescriptor swapChainDesc;
	swapChainDesc.width = 640;
	swapChainDesc.height = 480;
	swapChainDesc.usage = TextureUsage::RenderAttachment;
	swapChainDesc.format = swapChainFormat;
	swapChainDesc.presentMode = PresentMode::Fifo;
	SwapChain swapChain = device.createSwapChain(surface, swapChainDesc);
	std::cout << "Swapchain: " << swapChain << std::endl;

	std::cout << "Creating shader module..." << std::endl;
	ShaderModule shaderModule = loadShaderModule(RESOURCE_DIR "/shader.wgsl", device);
	std::cout << "Shader module: " << shaderModule << std::endl;

	std::cout << "Creating render pipeline..." << std::endl;
	RenderPipelineDescriptor pipelineDesc;

	// Vertex fetch
	std::vector<VertexAttribute> vertexAttribs(3);
	//                                         ^ This was a 2

	// Position attribute
	vertexAttribs[0].shaderLocation = 0;
	vertexAttribs[0].format = VertexFormat::Float32x3;
	vertexAttribs[0].offset = 0;

	// Normal attribute
	vertexAttribs[1].shaderLocation = 1;
	vertexAttribs[1].format = VertexFormat::Float32x3;
	vertexAttribs[1].offset = offsetof(VertexAttributes, normal);

	// Color attribute
	vertexAttribs[2].shaderLocation = 2;
	vertexAttribs[2].format = VertexFormat::Float32x3;
	vertexAttribs[2].offset = offsetof(VertexAttributes, color);

	VertexBufferLayout vertexBufferLayout;
	vertexBufferLayout.attributeCount = (uint32_t)vertexAttribs.size();
	vertexBufferLayout.attributes = vertexAttribs.data();
	vertexBufferLayout.arrayStride = sizeof(VertexAttributes);
	//                               ^^^^^^^^^^^^^^^^^^^^^^^^ This was 6 * sizeof(float)
	vertexBufferLayout.stepMode = VertexStepMode::Vertex;

	pipelineDesc.vertex.bufferCount = 1;
	pipelineDesc.vertex.buffers = &vertexBufferLayout;

	pipelineDesc.vertex.module = shaderModule;
	pipelineDesc.vertex.entryPoint = "vs_main";
	pipelineDesc.vertex.constantCount = 0;
	pipelineDesc.vertex.constants = nullptr;

	pipelineDesc.primitive.topology = PrimitiveTopology::TriangleList;
	pipelineDesc.primitive.stripIndexFormat = IndexFormat::Undefined;
	pipelineDesc.primitive.frontFace = FrontFace::CCW;
	pipelineDesc.primitive.cullMode = CullMode::None;

	FragmentState fragmentState;
	pipelineDesc.fragment = &fragmentState;
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
	colorTarget.format = swapChainFormat;
	colorTarget.blend = &blendState;
	colorTarget.writeMask = ColorWriteMask::All;

	fragmentState.targetCount = 1;
	fragmentState.targets = &colorTarget;

	DepthStencilState depthStencilState = Default;
	depthStencilState.depthCompare = CompareFunction::Less;
	depthStencilState.depthWriteEnabled = true;
	TextureFormat depthTextureFormat = TextureFormat::Depth24Plus;
	depthStencilState.format = depthTextureFormat;
	depthStencilState.stencilReadMask = 0;
	depthStencilState.stencilWriteMask = 0;
	
	pipelineDesc.depthStencil = &depthStencilState;

	pipelineDesc.multisample.count = 1;
	pipelineDesc.multisample.mask = ~0u;
	pipelineDesc.multisample.alphaToCoverageEnabled = false;

	// Create binding layout (don't forget to = Default)
	BindGroupLayoutEntry bindingLayout = Default;
	bindingLayout.binding = 0;
	bindingLayout.visibility = ShaderStage::Vertex | ShaderStage::Fragment;
	bindingLayout.buffer.type = BufferBindingType::Uniform;
	bindingLayout.buffer.minBindingSize = sizeof(MyUniforms);

	// Create a bind group layout
	BindGroupLayoutDescriptor bindGroupLayoutDesc{};
	bindGroupLayoutDesc.entryCount = 1;
	bindGroupLayoutDesc.entries = &bindingLayout;
	BindGroupLayout bindGroupLayout = device.createBindGroupLayout(bindGroupLayoutDesc);

	// Create the pipeline layout
	PipelineLayoutDescriptor layoutDesc{};
	layoutDesc.bindGroupLayoutCount = 1;
	layoutDesc.bindGroupLayouts = (WGPUBindGroupLayout*)&bindGroupLayout;
	PipelineLayout layout = device.createPipelineLayout(layoutDesc);
	pipelineDesc.layout = layout;

	RenderPipeline pipeline = device.createRenderPipeline(pipelineDesc);
	std::cout << "Render pipeline: " << pipeline << std::endl;

	// Create the depth texture
	TextureDescriptor depthTextureDesc;
	depthTextureDesc.dimension = TextureDimension::_2D;
	depthTextureDesc.format = depthTextureFormat;
	depthTextureDesc.mipLevelCount = 1;
	depthTextureDesc.sampleCount = 1;
	depthTextureDesc.size = {640, 480, 1};
	depthTextureDesc.usage = TextureUsage::RenderAttachment;
	depthTextureDesc.viewFormatCount = 1;
	depthTextureDesc.viewFormats = (WGPUTextureFormat*)&depthTextureFormat;
	Texture depthTexture = device.createTexture(depthTextureDesc);
	std::cout << "Depth texture: " << depthTexture << std::endl;

	// Create the view of the depth texture manipulated by the rasterizer
	TextureViewDescriptor depthTextureViewDesc;
	depthTextureViewDesc.aspect = TextureAspect::DepthOnly;
	depthTextureViewDesc.baseArrayLayer = 0;
	depthTextureViewDesc.arrayLayerCount = 1;
	depthTextureViewDesc.baseMipLevel = 0;
	depthTextureViewDesc.mipLevelCount = 1;
	depthTextureViewDesc.dimension = TextureViewDimension::_2D;
	depthTextureViewDesc.format = depthTextureFormat;
	TextureView depthTextureView = depthTexture.createView(depthTextureViewDesc);
	std::cout << "Depth texture view: " << depthTextureView << std::endl;

	std::vector<float> pointData;
	std::vector<uint16_t> indexData;

	// Load mesh data from OBJ file
	std::vector<VertexAttributes> vertexData;
	bool success = loadGeometryFromObj(RESOURCE_DIR "/pyramid.obj", vertexData);
	if (!success) {
		std::cerr << "Could not load geometry!" << std::endl;
		return 1;
	}

	// Create vertex buffer
	BufferDescriptor bufferDesc;
	bufferDesc.size = vertexData.size() * sizeof(VertexAttributes); // changed
	bufferDesc.usage = BufferUsage::CopyDst | BufferUsage::Vertex;
	bufferDesc.mappedAtCreation = false;
	Buffer vertexBuffer = device.createBuffer(bufferDesc);
	queue.writeBuffer(vertexBuffer, 0, vertexData.data(), bufferDesc.size); // changed

	int indexCount = static_cast<int>(vertexData.size()); // changed
	
	// Create uniform buffer
	bufferDesc.size = sizeof(MyUniforms);
	bufferDesc.usage = BufferUsage::CopyDst | BufferUsage::Uniform;
	bufferDesc.mappedAtCreation = false;
	Buffer uniformBuffer = device.createBuffer(bufferDesc);

	// Upload the initial value of the uniforms
	MyUniforms uniforms;

	// Build transform matrices

	// Translate the view
	vec3 focalPoint(0.0, 0.0, -1.0);
	// Rotate the object
	float angle1 = 2.0f; // arbitrary time
	// Rotate the view point
	float angle2 = 3.0f * PI / 4.0f;

	mat4x4 S = glm::scale(mat4x4(1.0), vec3(0.3f));
	mat4x4 T1 = mat4x4(1.0);
	mat4x4 R1 = glm::rotate(mat4x4(1.0), angle1, vec3(0.0, 0.0, 1.0));
	uniforms.modelMatrix = R1 * T1 * S;

	mat4x4 R2 = glm::rotate(mat4x4(1.0), -angle2, vec3(1.0, 0.0, 0.0));
	mat4x4 T2 = glm::translate(mat4x4(1.0), -focalPoint);
	uniforms.viewMatrix = T2 * R2;

	float ratio = 640.0f / 480.0f;
	float focalLength = 2.0;
	float near = 0.01f;
	float far = 100.0f;
	float divider = 1 / (focalLength * (far - near));
	uniforms.projectionMatrix = transpose(mat4x4(
		1.0, 0.0, 0.0, 0.0,
		0.0, ratio, 0.0, 0.0,
		0.0, 0.0, far * divider, -far * near * divider,
		0.0, 0.0, 1.0 / focalLength, 0.0
	));

	uniforms.time = 1.0f;
	uniforms.color = { 0.0f, 1.0f, 0.4f, 1.0f };
	queue.writeBuffer(uniformBuffer, 0, &uniforms, sizeof(MyUniforms));

	// Create a binding
	BindGroupEntry binding{};
	binding.binding = 0;
	binding.buffer = uniformBuffer;
	binding.offset = 0;
	binding.size = sizeof(MyUniforms);

	// A bind group contains one or multiple bindings
	BindGroupDescriptor bindGroupDesc;
	bindGroupDesc.layout = bindGroupLayout;
	bindGroupDesc.entryCount = bindGroupLayoutDesc.entryCount;
	bindGroupDesc.entries = &binding;
	BindGroup bindGroup = device.createBindGroup(bindGroupDesc);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		// Update uniform buffer
		uniforms.time = static_cast<float>(glfwGetTime()); // glfwGetTime returns a double
		// Only update the 1-st float of the buffer
		queue.writeBuffer(uniformBuffer, offsetof(MyUniforms, time), &uniforms.time, sizeof(MyUniforms::time));

		// Update view matrix
		angle1 = uniforms.time;
		R1 = glm::rotate(mat4x4(1.0), angle1, vec3(0.0, 0.0, 1.0));
		uniforms.modelMatrix = R1 * T1 * S;
		queue.writeBuffer(uniformBuffer, offsetof(MyUniforms, modelMatrix), &uniforms.modelMatrix, sizeof(MyUniforms::modelMatrix));

		TextureView nextTexture = swapChain.getCurrentTextureView();
		if (!nextTexture) {
			std::cerr << "Cannot acquire next swap chain texture" << std::endl;
			return 1;
		}

		CommandEncoderDescriptor commandEncoderDesc;
		commandEncoderDesc.label = "Command Encoder";
		CommandEncoder encoder = device.createCommandEncoder(commandEncoderDesc);
		
		RenderPassDescriptor renderPassDesc{};

		RenderPassColorAttachment renderPassColorAttachment{};
		renderPassColorAttachment.view = nextTexture;
		renderPassColorAttachment.resolveTarget = nullptr;
		renderPassColorAttachment.loadOp = LoadOp::Clear;
		renderPassColorAttachment.storeOp = StoreOp::Store;
		renderPassColorAttachment.clearValue = Color{ 0.05, 0.05, 0.05, 1.0 };
		renderPassDesc.colorAttachmentCount = 1;
		renderPassDesc.colorAttachments = &renderPassColorAttachment;

		RenderPassDepthStencilAttachment depthStencilAttachment;
		depthStencilAttachment.view = depthTextureView;
		depthStencilAttachment.depthClearValue = 1.0f;
		depthStencilAttachment.depthLoadOp = LoadOp::Clear;
		depthStencilAttachment.depthStoreOp = StoreOp::Store;
		depthStencilAttachment.depthReadOnly = false;
		depthStencilAttachment.stencilClearValue = 0;
#ifdef WEBGPU_BACKEND_WGPU
		depthStencilAttachment.stencilLoadOp = LoadOp::Clear;
		depthStencilAttachment.stencilStoreOp = StoreOp::Store;
#else
		depthStencilAttachment.stencilLoadOp = LoadOp::Undefined;
		depthStencilAttachment.stencilStoreOp = StoreOp::Undefined;
#endif
		depthStencilAttachment.stencilReadOnly = true;

		renderPassDesc.depthStencilAttachment = &depthStencilAttachment;

		renderPassDesc.timestampWriteCount = 0;
		renderPassDesc.timestampWrites = nullptr;
		RenderPassEncoder renderPass = encoder.beginRenderPass(renderPassDesc);

		renderPass.setPipeline(pipeline);

		renderPass.setVertexBuffer(0, vertexBuffer, 0, vertexData.size() * sizeof(VertexAttributes)); // changed

		// Set binding group
		renderPass.setBindGroup(0, bindGroup, 0, nullptr);

		renderPass.draw(indexCount, 1, 0, 0); // changed

		renderPass.end();
		renderPass.release();
		
		nextTexture.release();

		CommandBufferDescriptor cmdBufferDescriptor{};
		cmdBufferDescriptor.label = "Command buffer";
		CommandBuffer command = encoder.finish(cmdBufferDescriptor);
		encoder.release();
		queue.submit(command);
		command.release();

		swapChain.present();

#ifdef WEBGPU_BACKEND_DAWN
		// Check for pending error callbacks
		device.tick();
#endif
	}

	vertexBuffer.destroy();
	vertexBuffer.release();

	// Destroy the depth texture and its view
	depthTextureView.release();
	depthTexture.destroy();
	depthTexture.release();

	pipeline.release();
	shaderModule.release();
	swapChain.release();
	device.release();
	adapter.release();
	instance.release();
	surface.release();
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

ShaderModule loadShaderModule(const fs::path& path, Device device) {
	std::ifstream file(path);
	if (!file.is_open()) {
		return nullptr;
	}
	file.seekg(0, std::ios::end);
	size_t size = file.tellg();
	std::string shaderSource(size, ' ');
	file.seekg(0);
	file.read(shaderSource.data(), size);

	ShaderModuleWGSLDescriptor shaderCodeDesc;
	shaderCodeDesc.chain.next = nullptr;
	shaderCodeDesc.chain.sType = SType::ShaderModuleWGSLDescriptor;
	shaderCodeDesc.code = shaderSource.c_str();
	ShaderModuleDescriptor shaderDesc;
	shaderDesc.nextInChain = &shaderCodeDesc.chain;
#ifdef WEBGPU_BACKEND_WGPU
	shaderDesc.hintCount = 0;
	shaderDesc.hints = nullptr;
#endif

	return device.createShaderModule(shaderDesc);
}

bool loadGeometryFromObj(const fs::path& path, std::vector<VertexAttributes>& vertexData) {
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;

	std::string warn;
	std::string err;

	// Call the core loading procedure of TinyOBJLoader
	bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, path.string().c_str());

	// Check errors
	if (!warn.empty()) {
		std::cout << warn << std::endl;
	}

	if (!err.empty()) {
		std::cerr << err << std::endl;
	}

	if (!ret) {
		return false;
	}

	// Filling in vertexData:
	vertexData.clear();
	for (const auto& shape : shapes) {
		size_t offset = vertexData.size();
		vertexData.resize(offset + shape.mesh.indices.size());

		for (size_t i = 0; i < shape.mesh.indices.size(); ++i) {
			const tinyobj::index_t& idx = shape.mesh.indices[i];

			vertexData[offset + i].position = {
				attrib.vertices[3 * idx.vertex_index + 0],
				-attrib.vertices[3 * idx.vertex_index + 2], // Add a minus to avoid mirroring
				attrib.vertices[3 * idx.vertex_index + 1]
			};

			// Also apply the transform to normals!!
			vertexData[offset + i].normal = {
				attrib.normals[3 * idx.normal_index + 0],
				-attrib.normals[3 * idx.normal_index + 2],
				attrib.normals[3 * idx.normal_index + 1]
			};

			vertexData[offset + i].color = {
				attrib.colors[3 * idx.vertex_index + 0],
				attrib.colors[3 * idx.vertex_index + 1],
				attrib.colors[3 * idx.vertex_index + 2]
			};
		}
	}

	return true;
}