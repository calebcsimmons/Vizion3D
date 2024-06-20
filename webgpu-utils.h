
#pragma once

#include <webgpu/webgpu.h>

// Utility function to get a WebGPU adapter
WGPUAdapter requestAdapterSync(WGPUInstance instance, WGPURequestAdapterOptions const * options);

// Utility function to get a WebGPU device
WGPUDevice requestDeviceSync(WGPUAdapter adapter, WGPUDeviceDescriptor const * descriptor);

// Adapter inspection
void inspectAdapter(WGPUAdapter adapter);

//Device inspection
void inspectDevice(WGPUDevice device);