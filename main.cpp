// Includes
#include <webgpu/webgpu.h>
#include <iostream>

// Defines
#define WEBGPU_BACKEND_DAWN

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

    // Destroy Instance
    wgpuInstanceRelease(instance);
}