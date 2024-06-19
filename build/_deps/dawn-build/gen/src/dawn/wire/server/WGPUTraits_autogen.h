
#ifndef DAWNWIRE_SERVER_WGPUTRAITS_AUTOGEN_H_
#define DAWNWIRE_SERVER_WGPUTRAITS_AUTOGEN_H_

#include "dawn/dawn_proc_table.h"

namespace dawn::wire::server {

template <typename T>
struct WGPUTraits;

template <>
struct WGPUTraits<WGPUAdapter> {
    static constexpr auto Release = &DawnProcTable::adapterRelease;
};
template <>
struct WGPUTraits<WGPUBindGroup> {
    static constexpr auto Release = &DawnProcTable::bindGroupRelease;
};
template <>
struct WGPUTraits<WGPUBindGroupLayout> {
    static constexpr auto Release = &DawnProcTable::bindGroupLayoutRelease;
};
template <>
struct WGPUTraits<WGPUBuffer> {
    static constexpr auto Release = &DawnProcTable::bufferRelease;
};
template <>
struct WGPUTraits<WGPUCommandBuffer> {
    static constexpr auto Release = &DawnProcTable::commandBufferRelease;
};
template <>
struct WGPUTraits<WGPUCommandEncoder> {
    static constexpr auto Release = &DawnProcTable::commandEncoderRelease;
};
template <>
struct WGPUTraits<WGPUComputePassEncoder> {
    static constexpr auto Release = &DawnProcTable::computePassEncoderRelease;
};
template <>
struct WGPUTraits<WGPUComputePipeline> {
    static constexpr auto Release = &DawnProcTable::computePipelineRelease;
};
template <>
struct WGPUTraits<WGPUDevice> {
    static constexpr auto Release = &DawnProcTable::deviceRelease;
};
template <>
struct WGPUTraits<WGPUExternalTexture> {
    static constexpr auto Release = &DawnProcTable::externalTextureRelease;
};
template <>
struct WGPUTraits<WGPUInstance> {
    static constexpr auto Release = &DawnProcTable::instanceRelease;
};
template <>
struct WGPUTraits<WGPUPipelineLayout> {
    static constexpr auto Release = &DawnProcTable::pipelineLayoutRelease;
};
template <>
struct WGPUTraits<WGPUQuerySet> {
    static constexpr auto Release = &DawnProcTable::querySetRelease;
};
template <>
struct WGPUTraits<WGPUQueue> {
    static constexpr auto Release = &DawnProcTable::queueRelease;
};
template <>
struct WGPUTraits<WGPURenderBundle> {
    static constexpr auto Release = &DawnProcTable::renderBundleRelease;
};
template <>
struct WGPUTraits<WGPURenderBundleEncoder> {
    static constexpr auto Release = &DawnProcTable::renderBundleEncoderRelease;
};
template <>
struct WGPUTraits<WGPURenderPassEncoder> {
    static constexpr auto Release = &DawnProcTable::renderPassEncoderRelease;
};
template <>
struct WGPUTraits<WGPURenderPipeline> {
    static constexpr auto Release = &DawnProcTable::renderPipelineRelease;
};
template <>
struct WGPUTraits<WGPUSampler> {
    static constexpr auto Release = &DawnProcTable::samplerRelease;
};
template <>
struct WGPUTraits<WGPUShaderModule> {
    static constexpr auto Release = &DawnProcTable::shaderModuleRelease;
};
template <>
struct WGPUTraits<WGPUSurface> {
    static constexpr auto Release = &DawnProcTable::surfaceRelease;
};
template <>
struct WGPUTraits<WGPUSwapChain> {
    static constexpr auto Release = &DawnProcTable::swapChainRelease;
};
template <>
struct WGPUTraits<WGPUTexture> {
    static constexpr auto Release = &DawnProcTable::textureRelease;
};
template <>
struct WGPUTraits<WGPUTextureView> {
    static constexpr auto Release = &DawnProcTable::textureViewRelease;
};

}  // namespace dawn::wire::server

#endif  // DAWNWIRE_SERVER_WGPUTRAITS_AUTOGEN_H_
