// Includes
#include <webgpu/webgpu.h>
#include <webgpu/webgpu-utils.cpp>
#include <iostream>
#include <cassert>
#include <vector>

#include <webgpu/webgpu.h>
#ifdef WEBGPU_BACKEND_WGPU
#  include <webgpu/wgpu.h>
#endif

int main (int, char**) {

    // Descriptor
    WGPUInstanceDescriptor desc = {};
    desc.nextInChain = nullptr;

    // Instance
    WGPUInstance instance = wgpuCreateInstance(&desc);

    // Check if Instance was created
    if (!instance) {
        std::cerr << "Could not initialize WebGPU!" << std::endl;
        return 1;
    }

    // Display object (WGPUInstance is a simple pointer)
    std::cout << "WGPU instance: " << instance << std::endl;

	// Requesting Adapter
	std::cout << "Requesting adapter..." << std::endl;
	WGPURequestAdapterOptions adapterOpts = {};
	adapterOpts.nextInChain = nullptr;
	WGPUAdapter adapter = requestAdapterSync(instance, &adapterOpts);
	std::cout << "Received Adapter: " << adapter << std::endl;

	// Display adapter information
	inspectAdapter(adapter);

	// Release instance after receiving adapter
	wgpuInstanceRelease(instance);

	// Requesting Device
	std::cout << "Requesting device..." << std::endl;
	WGPUDeviceDescriptor deviceDesc = {};
	deviceDesc.nextInChain = nullptr;
	deviceDesc.label = "My Device"; 
	deviceDesc.requiredFeatureCount = 0; // No specific feature required
	deviceDesc.requiredLimits = nullptr; // No specific limit required
	deviceDesc.defaultQueue.nextInChain = nullptr;
	deviceDesc.defaultQueue.label = "The default queue";

	// If device becomes unavailable
	deviceDesc.deviceLostCallback = [](WGPUDeviceLostReason reason, char const* message, void* /* pUserData */) {
		std::cout << "Device lost: reason " << reason;
		if (message) std::cout << " (" << message << ")";
		std::cout << std::endl;
	};

	WGPUDevice device = requestDeviceSync(adapter, &deviceDesc);
	std::cout << "Received device: " << device << std::endl;

	// If device encounters an error
	auto onDeviceError = [](WGPUErrorType type, char const* message, void* /* pUserData */) {
		std::cout << "Uncaptured device error: type " << type;
		if (message) std::cout << " (" << message << ")";
		std::cout << std::endl;
	};
	wgpuDeviceSetUncapturedErrorCallback(device, onDeviceError, nullptr /* pUserData */);

	// Release adapter after receiving Device
	wgpuAdapterRelease(adapter);

	// Display Device information
	inspectDevice(device);

	WGPUQueue queue = wgpuDeviceGetQueue(device);
	// Add a callback to monitor the moment queued work finished
	auto onQueueWorkDone = [](WGPUQueueWorkDoneStatus status, void* /* pUserData */) {
		std::cout << "Queued work finished with status: " << status << std::endl;
	};

	wgpuQueueOnSubmittedWorkDone(queue, onQueueWorkDone, nullptr /* pUserData */);

	WGPUCommandEncoderDescriptor encoderDesc = {};
	encoderDesc.nextInChain = nullptr;
	encoderDesc.label = "My command encoder";
	WGPUCommandEncoder encoder = wgpuDeviceCreateCommandEncoder(device, &encoderDesc);

	wgpuCommandEncoderInsertDebugMarker(encoder, "Do one thing");
	wgpuCommandEncoderInsertDebugMarker(encoder, "Do another thing");

	WGPUCommandBufferDescriptor cmdBufferDescriptor = {};
	cmdBufferDescriptor.nextInChain = nullptr;
	cmdBufferDescriptor.label = "Command buffer";
	WGPUCommandBuffer command = wgpuCommandEncoderFinish(encoder, &cmdBufferDescriptor);
	wgpuCommandEncoderRelease(encoder); // release encoder after it's finished

	// Finally submit the command queue
	std::cout << "Submitting command..." << std::endl;
	wgpuQueueSubmit(queue, 1, &command);
	wgpuCommandBufferRelease(command);
	std::cout << "Command submitted." << std::endl;
	for (int i = 0 ; i < 5 ; ++i) {
		std::cout << "Tick/Poll device..." << std::endl;

#if defined(WEBGPU_BACKEND_DAWN)
	wgpuDeviceTick(device);
#elif defined(WEBGPU_BACKEND_WGPU)
		wgpuDevicePoll(device, false, nullptr);
#elif defined(WEBGPU_BACKEND_EMSCRIPTEN)
		emscripten_sleep(100);
#endif
	}

	wgpuQueueRelease(queue);
	wgpuDeviceRelease(device);

	return 0;
  
}