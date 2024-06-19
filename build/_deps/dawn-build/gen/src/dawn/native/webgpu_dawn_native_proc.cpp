// Copyright 2021 The Dawn & Tint Authors
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "dawn/webgpu.h"

namespace dawn::native {

// This file should be kept in sync with generator/templates/dawn/native/ProcTable.cpp

extern void NativeAdapterInfoFreeMembers(WGPUAdapterInfo value);
extern void NativeAdapterPropertiesFreeMembers(WGPUAdapterProperties value);
extern void NativeAdapterPropertiesMemoryHeapsFreeMembers(WGPUAdapterPropertiesMemoryHeaps value);
extern WGPUInstance NativeCreateInstance(WGPUInstanceDescriptor const * descriptor);
extern void NativeDrmFormatCapabilitiesFreeMembers(WGPUDrmFormatCapabilities value);
extern WGPUStatus NativeGetInstanceFeatures(WGPUInstanceFeatures * features);
extern WGPUProc NativeGetProcAddress(WGPUDevice device, char const * procName);
extern void NativeSharedBufferMemoryEndAccessStateFreeMembers(WGPUSharedBufferMemoryEndAccessState value);
extern void NativeSharedTextureMemoryEndAccessStateFreeMembers(WGPUSharedTextureMemoryEndAccessState value);
extern void NativeSurfaceCapabilitiesFreeMembers(WGPUSurfaceCapabilities value);
extern WGPUDevice NativeAdapterCreateDevice(WGPUAdapter cSelf, WGPUDeviceDescriptor const * descriptor);
extern size_t NativeAdapterEnumerateFeatures(WGPUAdapter cSelf, WGPUFeatureName * features);
extern WGPUStatus NativeAdapterGetFormatCapabilities(WGPUAdapter cSelf, WGPUTextureFormat format, WGPUFormatCapabilities * capabilities);
extern WGPUStatus NativeAdapterGetInfo(WGPUAdapter cSelf, WGPUAdapterInfo * info);
extern WGPUInstance NativeAdapterGetInstance(WGPUAdapter cSelf);
extern WGPUStatus NativeAdapterGetLimits(WGPUAdapter cSelf, WGPUSupportedLimits * limits);
extern WGPUStatus NativeAdapterGetProperties(WGPUAdapter cSelf, WGPUAdapterProperties * properties);
extern WGPUBool NativeAdapterHasFeature(WGPUAdapter cSelf, WGPUFeatureName feature);
extern void NativeAdapterRequestDevice(WGPUAdapter cSelf, WGPUDeviceDescriptor const * descriptor, WGPURequestDeviceCallback callback, void * userdata);
extern WGPUFuture NativeAdapterRequestDevice2(WGPUAdapter cSelf, WGPUDeviceDescriptor const * options, WGPURequestDeviceCallbackInfo2 callbackInfo);
extern WGPUFuture NativeAdapterRequestDeviceF(WGPUAdapter cSelf, WGPUDeviceDescriptor const * options, WGPURequestDeviceCallbackInfo callbackInfo);
extern void NativeAdapterAddRef(WGPUAdapter cSelf);
extern void NativeAdapterRelease(WGPUAdapter cSelf);
extern void NativeBindGroupSetLabel(WGPUBindGroup cSelf, char const * label);
extern void NativeBindGroupAddRef(WGPUBindGroup cSelf);
extern void NativeBindGroupRelease(WGPUBindGroup cSelf);
extern void NativeBindGroupLayoutSetLabel(WGPUBindGroupLayout cSelf, char const * label);
extern void NativeBindGroupLayoutAddRef(WGPUBindGroupLayout cSelf);
extern void NativeBindGroupLayoutRelease(WGPUBindGroupLayout cSelf);
extern void NativeBufferDestroy(WGPUBuffer cSelf);
extern void const * NativeBufferGetConstMappedRange(WGPUBuffer cSelf, size_t offset, size_t size);
extern WGPUBufferMapState NativeBufferGetMapState(WGPUBuffer cSelf);
extern void * NativeBufferGetMappedRange(WGPUBuffer cSelf, size_t offset, size_t size);
extern uint64_t NativeBufferGetSize(WGPUBuffer cSelf);
extern WGPUBufferUsageFlags NativeBufferGetUsage(WGPUBuffer cSelf);
extern void NativeBufferMapAsync(WGPUBuffer cSelf, WGPUMapModeFlags mode, size_t offset, size_t size, WGPUBufferMapCallback callback, void * userdata);
extern WGPUFuture NativeBufferMapAsyncF(WGPUBuffer cSelf, WGPUMapModeFlags mode, size_t offset, size_t size, WGPUBufferMapCallbackInfo callbackInfo);
extern void NativeBufferSetLabel(WGPUBuffer cSelf, char const * label);
extern void NativeBufferUnmap(WGPUBuffer cSelf);
extern void NativeBufferAddRef(WGPUBuffer cSelf);
extern void NativeBufferRelease(WGPUBuffer cSelf);
extern void NativeCommandBufferSetLabel(WGPUCommandBuffer cSelf, char const * label);
extern void NativeCommandBufferAddRef(WGPUCommandBuffer cSelf);
extern void NativeCommandBufferRelease(WGPUCommandBuffer cSelf);
extern WGPUComputePassEncoder NativeCommandEncoderBeginComputePass(WGPUCommandEncoder cSelf, WGPUComputePassDescriptor const * descriptor);
extern WGPURenderPassEncoder NativeCommandEncoderBeginRenderPass(WGPUCommandEncoder cSelf, WGPURenderPassDescriptor const * descriptor);
extern void NativeCommandEncoderClearBuffer(WGPUCommandEncoder cSelf, WGPUBuffer buffer, uint64_t offset, uint64_t size);
extern void NativeCommandEncoderCopyBufferToBuffer(WGPUCommandEncoder cSelf, WGPUBuffer source, uint64_t sourceOffset, WGPUBuffer destination, uint64_t destinationOffset, uint64_t size);
extern void NativeCommandEncoderCopyBufferToTexture(WGPUCommandEncoder cSelf, WGPUImageCopyBuffer const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize);
extern void NativeCommandEncoderCopyTextureToBuffer(WGPUCommandEncoder cSelf, WGPUImageCopyTexture const * source, WGPUImageCopyBuffer const * destination, WGPUExtent3D const * copySize);
extern void NativeCommandEncoderCopyTextureToTexture(WGPUCommandEncoder cSelf, WGPUImageCopyTexture const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize);
extern WGPUCommandBuffer NativeCommandEncoderFinish(WGPUCommandEncoder cSelf, WGPUCommandBufferDescriptor const * descriptor);
extern void NativeCommandEncoderInjectValidationError(WGPUCommandEncoder cSelf, char const * message);
extern void NativeCommandEncoderInsertDebugMarker(WGPUCommandEncoder cSelf, char const * markerLabel);
extern void NativeCommandEncoderPopDebugGroup(WGPUCommandEncoder cSelf);
extern void NativeCommandEncoderPushDebugGroup(WGPUCommandEncoder cSelf, char const * groupLabel);
extern void NativeCommandEncoderResolveQuerySet(WGPUCommandEncoder cSelf, WGPUQuerySet querySet, uint32_t firstQuery, uint32_t queryCount, WGPUBuffer destination, uint64_t destinationOffset);
extern void NativeCommandEncoderSetLabel(WGPUCommandEncoder cSelf, char const * label);
extern void NativeCommandEncoderWriteBuffer(WGPUCommandEncoder cSelf, WGPUBuffer buffer, uint64_t bufferOffset, uint8_t const * data, uint64_t size);
extern void NativeCommandEncoderWriteTimestamp(WGPUCommandEncoder cSelf, WGPUQuerySet querySet, uint32_t queryIndex);
extern void NativeCommandEncoderAddRef(WGPUCommandEncoder cSelf);
extern void NativeCommandEncoderRelease(WGPUCommandEncoder cSelf);
extern void NativeComputePassEncoderDispatchWorkgroups(WGPUComputePassEncoder cSelf, uint32_t workgroupCountX, uint32_t workgroupCountY, uint32_t workgroupCountZ);
extern void NativeComputePassEncoderDispatchWorkgroupsIndirect(WGPUComputePassEncoder cSelf, WGPUBuffer indirectBuffer, uint64_t indirectOffset);
extern void NativeComputePassEncoderEnd(WGPUComputePassEncoder cSelf);
extern void NativeComputePassEncoderInsertDebugMarker(WGPUComputePassEncoder cSelf, char const * markerLabel);
extern void NativeComputePassEncoderPopDebugGroup(WGPUComputePassEncoder cSelf);
extern void NativeComputePassEncoderPushDebugGroup(WGPUComputePassEncoder cSelf, char const * groupLabel);
extern void NativeComputePassEncoderSetBindGroup(WGPUComputePassEncoder cSelf, uint32_t groupIndex, WGPUBindGroup group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets);
extern void NativeComputePassEncoderSetLabel(WGPUComputePassEncoder cSelf, char const * label);
extern void NativeComputePassEncoderSetPipeline(WGPUComputePassEncoder cSelf, WGPUComputePipeline pipeline);
extern void NativeComputePassEncoderWriteTimestamp(WGPUComputePassEncoder cSelf, WGPUQuerySet querySet, uint32_t queryIndex);
extern void NativeComputePassEncoderAddRef(WGPUComputePassEncoder cSelf);
extern void NativeComputePassEncoderRelease(WGPUComputePassEncoder cSelf);
extern WGPUBindGroupLayout NativeComputePipelineGetBindGroupLayout(WGPUComputePipeline cSelf, uint32_t groupIndex);
extern void NativeComputePipelineSetLabel(WGPUComputePipeline cSelf, char const * label);
extern void NativeComputePipelineAddRef(WGPUComputePipeline cSelf);
extern void NativeComputePipelineRelease(WGPUComputePipeline cSelf);
extern WGPUBindGroup NativeDeviceCreateBindGroup(WGPUDevice cSelf, WGPUBindGroupDescriptor const * descriptor);
extern WGPUBindGroupLayout NativeDeviceCreateBindGroupLayout(WGPUDevice cSelf, WGPUBindGroupLayoutDescriptor const * descriptor);
extern WGPUBuffer NativeDeviceCreateBuffer(WGPUDevice cSelf, WGPUBufferDescriptor const * descriptor);
extern WGPUCommandEncoder NativeDeviceCreateCommandEncoder(WGPUDevice cSelf, WGPUCommandEncoderDescriptor const * descriptor);
extern WGPUComputePipeline NativeDeviceCreateComputePipeline(WGPUDevice cSelf, WGPUComputePipelineDescriptor const * descriptor);
extern void NativeDeviceCreateComputePipelineAsync(WGPUDevice cSelf, WGPUComputePipelineDescriptor const * descriptor, WGPUCreateComputePipelineAsyncCallback callback, void * userdata);
extern WGPUFuture NativeDeviceCreateComputePipelineAsync2(WGPUDevice cSelf, WGPUComputePipelineDescriptor const * descriptor, WGPUCreateComputePipelineAsyncCallbackInfo2 callbackInfo);
extern WGPUFuture NativeDeviceCreateComputePipelineAsyncF(WGPUDevice cSelf, WGPUComputePipelineDescriptor const * descriptor, WGPUCreateComputePipelineAsyncCallbackInfo callbackInfo);
extern WGPUBuffer NativeDeviceCreateErrorBuffer(WGPUDevice cSelf, WGPUBufferDescriptor const * descriptor);
extern WGPUExternalTexture NativeDeviceCreateErrorExternalTexture(WGPUDevice cSelf);
extern WGPUShaderModule NativeDeviceCreateErrorShaderModule(WGPUDevice cSelf, WGPUShaderModuleDescriptor const * descriptor, char const * errorMessage);
extern WGPUTexture NativeDeviceCreateErrorTexture(WGPUDevice cSelf, WGPUTextureDescriptor const * descriptor);
extern WGPUExternalTexture NativeDeviceCreateExternalTexture(WGPUDevice cSelf, WGPUExternalTextureDescriptor const * externalTextureDescriptor);
extern WGPUPipelineLayout NativeDeviceCreatePipelineLayout(WGPUDevice cSelf, WGPUPipelineLayoutDescriptor const * descriptor);
extern WGPUQuerySet NativeDeviceCreateQuerySet(WGPUDevice cSelf, WGPUQuerySetDescriptor const * descriptor);
extern WGPURenderBundleEncoder NativeDeviceCreateRenderBundleEncoder(WGPUDevice cSelf, WGPURenderBundleEncoderDescriptor const * descriptor);
extern WGPURenderPipeline NativeDeviceCreateRenderPipeline(WGPUDevice cSelf, WGPURenderPipelineDescriptor const * descriptor);
extern void NativeDeviceCreateRenderPipelineAsync(WGPUDevice cSelf, WGPURenderPipelineDescriptor const * descriptor, WGPUCreateRenderPipelineAsyncCallback callback, void * userdata);
extern WGPUFuture NativeDeviceCreateRenderPipelineAsync2(WGPUDevice cSelf, WGPURenderPipelineDescriptor const * descriptor, WGPUCreateRenderPipelineAsyncCallbackInfo2 callbackInfo);
extern WGPUFuture NativeDeviceCreateRenderPipelineAsyncF(WGPUDevice cSelf, WGPURenderPipelineDescriptor const * descriptor, WGPUCreateRenderPipelineAsyncCallbackInfo callbackInfo);
extern WGPUSampler NativeDeviceCreateSampler(WGPUDevice cSelf, WGPUSamplerDescriptor const * descriptor);
extern WGPUShaderModule NativeDeviceCreateShaderModule(WGPUDevice cSelf, WGPUShaderModuleDescriptor const * descriptor);
extern WGPUSwapChain NativeDeviceCreateSwapChain(WGPUDevice cSelf, WGPUSurface surface, WGPUSwapChainDescriptor const * descriptor);
extern WGPUTexture NativeDeviceCreateTexture(WGPUDevice cSelf, WGPUTextureDescriptor const * descriptor);
extern void NativeDeviceDestroy(WGPUDevice cSelf);
extern size_t NativeDeviceEnumerateFeatures(WGPUDevice cSelf, WGPUFeatureName * features);
extern void NativeDeviceForceLoss(WGPUDevice cSelf, WGPUDeviceLostReason type, char const * message);
extern WGPUStatus NativeDeviceGetAHardwareBufferProperties(WGPUDevice cSelf, void * handle, WGPUAHardwareBufferProperties * properties);
extern WGPUAdapter NativeDeviceGetAdapter(WGPUDevice cSelf);
extern WGPUStatus NativeDeviceGetLimits(WGPUDevice cSelf, WGPUSupportedLimits * limits);
extern WGPUQueue NativeDeviceGetQueue(WGPUDevice cSelf);
extern WGPUTextureUsageFlags NativeDeviceGetSupportedSurfaceUsage(WGPUDevice cSelf, WGPUSurface surface);
extern WGPUBool NativeDeviceHasFeature(WGPUDevice cSelf, WGPUFeatureName feature);
extern WGPUSharedBufferMemory NativeDeviceImportSharedBufferMemory(WGPUDevice cSelf, WGPUSharedBufferMemoryDescriptor const * descriptor);
extern WGPUSharedFence NativeDeviceImportSharedFence(WGPUDevice cSelf, WGPUSharedFenceDescriptor const * descriptor);
extern WGPUSharedTextureMemory NativeDeviceImportSharedTextureMemory(WGPUDevice cSelf, WGPUSharedTextureMemoryDescriptor const * descriptor);
extern void NativeDeviceInjectError(WGPUDevice cSelf, WGPUErrorType type, char const * message);
extern void NativeDevicePopErrorScope(WGPUDevice cSelf, WGPUErrorCallback oldCallback, void * userdata);
extern WGPUFuture NativeDevicePopErrorScope2(WGPUDevice cSelf, WGPUPopErrorScopeCallbackInfo2 callbackInfo);
extern WGPUFuture NativeDevicePopErrorScopeF(WGPUDevice cSelf, WGPUPopErrorScopeCallbackInfo callbackInfo);
extern void NativeDevicePushErrorScope(WGPUDevice cSelf, WGPUErrorFilter filter);
extern void NativeDeviceSetDeviceLostCallback(WGPUDevice cSelf, WGPUDeviceLostCallback callback, void * userdata);
extern void NativeDeviceSetLabel(WGPUDevice cSelf, char const * label);
extern void NativeDeviceSetLoggingCallback(WGPUDevice cSelf, WGPULoggingCallback callback, void * userdata);
extern void NativeDeviceSetUncapturedErrorCallback(WGPUDevice cSelf, WGPUErrorCallback callback, void * userdata);
extern void NativeDeviceTick(WGPUDevice cSelf);
extern void NativeDeviceValidateTextureDescriptor(WGPUDevice cSelf, WGPUTextureDescriptor const * descriptor);
extern void NativeDeviceAddRef(WGPUDevice cSelf);
extern void NativeDeviceRelease(WGPUDevice cSelf);
extern void NativeExternalTextureDestroy(WGPUExternalTexture cSelf);
extern void NativeExternalTextureExpire(WGPUExternalTexture cSelf);
extern void NativeExternalTextureRefresh(WGPUExternalTexture cSelf);
extern void NativeExternalTextureSetLabel(WGPUExternalTexture cSelf, char const * label);
extern void NativeExternalTextureAddRef(WGPUExternalTexture cSelf);
extern void NativeExternalTextureRelease(WGPUExternalTexture cSelf);
extern WGPUSurface NativeInstanceCreateSurface(WGPUInstance cSelf, WGPUSurfaceDescriptor const * descriptor);
extern size_t NativeInstanceEnumerateWGSLLanguageFeatures(WGPUInstance cSelf, WGPUWGSLFeatureName * features);
extern WGPUBool NativeInstanceHasWGSLLanguageFeature(WGPUInstance cSelf, WGPUWGSLFeatureName feature);
extern void NativeInstanceProcessEvents(WGPUInstance cSelf);
extern void NativeInstanceRequestAdapter(WGPUInstance cSelf, WGPURequestAdapterOptions const * options, WGPURequestAdapterCallback callback, void * userdata);
extern WGPUFuture NativeInstanceRequestAdapter2(WGPUInstance cSelf, WGPURequestAdapterOptions const * options, WGPURequestAdapterCallbackInfo2 callbackInfo);
extern WGPUFuture NativeInstanceRequestAdapterF(WGPUInstance cSelf, WGPURequestAdapterOptions const * options, WGPURequestAdapterCallbackInfo callbackInfo);
extern WGPUWaitStatus NativeInstanceWaitAny(WGPUInstance cSelf, size_t futureCount, WGPUFutureWaitInfo * futures, uint64_t timeoutNS);
extern void NativeInstanceAddRef(WGPUInstance cSelf);
extern void NativeInstanceRelease(WGPUInstance cSelf);
extern void NativePipelineLayoutSetLabel(WGPUPipelineLayout cSelf, char const * label);
extern void NativePipelineLayoutAddRef(WGPUPipelineLayout cSelf);
extern void NativePipelineLayoutRelease(WGPUPipelineLayout cSelf);
extern void NativeQuerySetDestroy(WGPUQuerySet cSelf);
extern uint32_t NativeQuerySetGetCount(WGPUQuerySet cSelf);
extern WGPUQueryType NativeQuerySetGetType(WGPUQuerySet cSelf);
extern void NativeQuerySetSetLabel(WGPUQuerySet cSelf, char const * label);
extern void NativeQuerySetAddRef(WGPUQuerySet cSelf);
extern void NativeQuerySetRelease(WGPUQuerySet cSelf);
extern void NativeQueueCopyExternalTextureForBrowser(WGPUQueue cSelf, WGPUImageCopyExternalTexture const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize, WGPUCopyTextureForBrowserOptions const * options);
extern void NativeQueueCopyTextureForBrowser(WGPUQueue cSelf, WGPUImageCopyTexture const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize, WGPUCopyTextureForBrowserOptions const * options);
extern void NativeQueueOnSubmittedWorkDone(WGPUQueue cSelf, WGPUQueueWorkDoneCallback callback, void * userdata);
extern WGPUFuture NativeQueueOnSubmittedWorkDone2(WGPUQueue cSelf, WGPUQueueWorkDoneCallbackInfo2 callbackInfo);
extern WGPUFuture NativeQueueOnSubmittedWorkDoneF(WGPUQueue cSelf, WGPUQueueWorkDoneCallbackInfo callbackInfo);
extern void NativeQueueSetLabel(WGPUQueue cSelf, char const * label);
extern void NativeQueueSubmit(WGPUQueue cSelf, size_t commandCount, WGPUCommandBuffer const * commands);
extern void NativeQueueWriteBuffer(WGPUQueue cSelf, WGPUBuffer buffer, uint64_t bufferOffset, void const * data, size_t size);
extern void NativeQueueWriteTexture(WGPUQueue cSelf, WGPUImageCopyTexture const * destination, void const * data, size_t dataSize, WGPUTextureDataLayout const * dataLayout, WGPUExtent3D const * writeSize);
extern void NativeQueueAddRef(WGPUQueue cSelf);
extern void NativeQueueRelease(WGPUQueue cSelf);
extern void NativeRenderBundleSetLabel(WGPURenderBundle cSelf, char const * label);
extern void NativeRenderBundleAddRef(WGPURenderBundle cSelf);
extern void NativeRenderBundleRelease(WGPURenderBundle cSelf);
extern void NativeRenderBundleEncoderDraw(WGPURenderBundleEncoder cSelf, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
extern void NativeRenderBundleEncoderDrawIndexed(WGPURenderBundleEncoder cSelf, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance);
extern void NativeRenderBundleEncoderDrawIndexedIndirect(WGPURenderBundleEncoder cSelf, WGPUBuffer indirectBuffer, uint64_t indirectOffset);
extern void NativeRenderBundleEncoderDrawIndirect(WGPURenderBundleEncoder cSelf, WGPUBuffer indirectBuffer, uint64_t indirectOffset);
extern WGPURenderBundle NativeRenderBundleEncoderFinish(WGPURenderBundleEncoder cSelf, WGPURenderBundleDescriptor const * descriptor);
extern void NativeRenderBundleEncoderInsertDebugMarker(WGPURenderBundleEncoder cSelf, char const * markerLabel);
extern void NativeRenderBundleEncoderPopDebugGroup(WGPURenderBundleEncoder cSelf);
extern void NativeRenderBundleEncoderPushDebugGroup(WGPURenderBundleEncoder cSelf, char const * groupLabel);
extern void NativeRenderBundleEncoderSetBindGroup(WGPURenderBundleEncoder cSelf, uint32_t groupIndex, WGPUBindGroup group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets);
extern void NativeRenderBundleEncoderSetIndexBuffer(WGPURenderBundleEncoder cSelf, WGPUBuffer buffer, WGPUIndexFormat format, uint64_t offset, uint64_t size);
extern void NativeRenderBundleEncoderSetLabel(WGPURenderBundleEncoder cSelf, char const * label);
extern void NativeRenderBundleEncoderSetPipeline(WGPURenderBundleEncoder cSelf, WGPURenderPipeline pipeline);
extern void NativeRenderBundleEncoderSetVertexBuffer(WGPURenderBundleEncoder cSelf, uint32_t slot, WGPUBuffer buffer, uint64_t offset, uint64_t size);
extern void NativeRenderBundleEncoderAddRef(WGPURenderBundleEncoder cSelf);
extern void NativeRenderBundleEncoderRelease(WGPURenderBundleEncoder cSelf);
extern void NativeRenderPassEncoderBeginOcclusionQuery(WGPURenderPassEncoder cSelf, uint32_t queryIndex);
extern void NativeRenderPassEncoderDraw(WGPURenderPassEncoder cSelf, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance);
extern void NativeRenderPassEncoderDrawIndexed(WGPURenderPassEncoder cSelf, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance);
extern void NativeRenderPassEncoderDrawIndexedIndirect(WGPURenderPassEncoder cSelf, WGPUBuffer indirectBuffer, uint64_t indirectOffset);
extern void NativeRenderPassEncoderDrawIndirect(WGPURenderPassEncoder cSelf, WGPUBuffer indirectBuffer, uint64_t indirectOffset);
extern void NativeRenderPassEncoderEnd(WGPURenderPassEncoder cSelf);
extern void NativeRenderPassEncoderEndOcclusionQuery(WGPURenderPassEncoder cSelf);
extern void NativeRenderPassEncoderExecuteBundles(WGPURenderPassEncoder cSelf, size_t bundleCount, WGPURenderBundle const * bundles);
extern void NativeRenderPassEncoderInsertDebugMarker(WGPURenderPassEncoder cSelf, char const * markerLabel);
extern void NativeRenderPassEncoderPixelLocalStorageBarrier(WGPURenderPassEncoder cSelf);
extern void NativeRenderPassEncoderPopDebugGroup(WGPURenderPassEncoder cSelf);
extern void NativeRenderPassEncoderPushDebugGroup(WGPURenderPassEncoder cSelf, char const * groupLabel);
extern void NativeRenderPassEncoderSetBindGroup(WGPURenderPassEncoder cSelf, uint32_t groupIndex, WGPUBindGroup group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets);
extern void NativeRenderPassEncoderSetBlendConstant(WGPURenderPassEncoder cSelf, WGPUColor const * color);
extern void NativeRenderPassEncoderSetIndexBuffer(WGPURenderPassEncoder cSelf, WGPUBuffer buffer, WGPUIndexFormat format, uint64_t offset, uint64_t size);
extern void NativeRenderPassEncoderSetLabel(WGPURenderPassEncoder cSelf, char const * label);
extern void NativeRenderPassEncoderSetPipeline(WGPURenderPassEncoder cSelf, WGPURenderPipeline pipeline);
extern void NativeRenderPassEncoderSetScissorRect(WGPURenderPassEncoder cSelf, uint32_t x, uint32_t y, uint32_t width, uint32_t height);
extern void NativeRenderPassEncoderSetStencilReference(WGPURenderPassEncoder cSelf, uint32_t reference);
extern void NativeRenderPassEncoderSetVertexBuffer(WGPURenderPassEncoder cSelf, uint32_t slot, WGPUBuffer buffer, uint64_t offset, uint64_t size);
extern void NativeRenderPassEncoderSetViewport(WGPURenderPassEncoder cSelf, float x, float y, float width, float height, float minDepth, float maxDepth);
extern void NativeRenderPassEncoderWriteTimestamp(WGPURenderPassEncoder cSelf, WGPUQuerySet querySet, uint32_t queryIndex);
extern void NativeRenderPassEncoderAddRef(WGPURenderPassEncoder cSelf);
extern void NativeRenderPassEncoderRelease(WGPURenderPassEncoder cSelf);
extern WGPUBindGroupLayout NativeRenderPipelineGetBindGroupLayout(WGPURenderPipeline cSelf, uint32_t groupIndex);
extern void NativeRenderPipelineSetLabel(WGPURenderPipeline cSelf, char const * label);
extern void NativeRenderPipelineAddRef(WGPURenderPipeline cSelf);
extern void NativeRenderPipelineRelease(WGPURenderPipeline cSelf);
extern void NativeSamplerSetLabel(WGPUSampler cSelf, char const * label);
extern void NativeSamplerAddRef(WGPUSampler cSelf);
extern void NativeSamplerRelease(WGPUSampler cSelf);
extern void NativeShaderModuleGetCompilationInfo(WGPUShaderModule cSelf, WGPUCompilationInfoCallback callback, void * userdata);
extern WGPUFuture NativeShaderModuleGetCompilationInfoF(WGPUShaderModule cSelf, WGPUCompilationInfoCallbackInfo callbackInfo);
extern void NativeShaderModuleSetLabel(WGPUShaderModule cSelf, char const * label);
extern void NativeShaderModuleAddRef(WGPUShaderModule cSelf);
extern void NativeShaderModuleRelease(WGPUShaderModule cSelf);
extern WGPUBool NativeSharedBufferMemoryBeginAccess(WGPUSharedBufferMemory cSelf, WGPUBuffer buffer, WGPUSharedBufferMemoryBeginAccessDescriptor const * descriptor);
extern WGPUBuffer NativeSharedBufferMemoryCreateBuffer(WGPUSharedBufferMemory cSelf, WGPUBufferDescriptor const * descriptor);
extern WGPUBool NativeSharedBufferMemoryEndAccess(WGPUSharedBufferMemory cSelf, WGPUBuffer buffer, WGPUSharedBufferMemoryEndAccessState * descriptor);
extern WGPUStatus NativeSharedBufferMemoryGetProperties(WGPUSharedBufferMemory cSelf, WGPUSharedBufferMemoryProperties * properties);
extern WGPUBool NativeSharedBufferMemoryIsDeviceLost(WGPUSharedBufferMemory cSelf);
extern void NativeSharedBufferMemorySetLabel(WGPUSharedBufferMemory cSelf, char const * label);
extern void NativeSharedBufferMemoryAddRef(WGPUSharedBufferMemory cSelf);
extern void NativeSharedBufferMemoryRelease(WGPUSharedBufferMemory cSelf);
extern void NativeSharedFenceExportInfo(WGPUSharedFence cSelf, WGPUSharedFenceExportInfo * info);
extern void NativeSharedFenceAddRef(WGPUSharedFence cSelf);
extern void NativeSharedFenceRelease(WGPUSharedFence cSelf);
extern WGPUBool NativeSharedTextureMemoryBeginAccess(WGPUSharedTextureMemory cSelf, WGPUTexture texture, WGPUSharedTextureMemoryBeginAccessDescriptor const * descriptor);
extern WGPUTexture NativeSharedTextureMemoryCreateTexture(WGPUSharedTextureMemory cSelf, WGPUTextureDescriptor const * descriptor);
extern WGPUBool NativeSharedTextureMemoryEndAccess(WGPUSharedTextureMemory cSelf, WGPUTexture texture, WGPUSharedTextureMemoryEndAccessState * descriptor);
extern WGPUStatus NativeSharedTextureMemoryGetProperties(WGPUSharedTextureMemory cSelf, WGPUSharedTextureMemoryProperties * properties);
extern WGPUBool NativeSharedTextureMemoryIsDeviceLost(WGPUSharedTextureMemory cSelf);
extern void NativeSharedTextureMemorySetLabel(WGPUSharedTextureMemory cSelf, char const * label);
extern void NativeSharedTextureMemoryAddRef(WGPUSharedTextureMemory cSelf);
extern void NativeSharedTextureMemoryRelease(WGPUSharedTextureMemory cSelf);
extern void NativeSurfaceConfigure(WGPUSurface cSelf, WGPUSurfaceConfiguration const * config);
extern WGPUStatus NativeSurfaceGetCapabilities(WGPUSurface cSelf, WGPUAdapter adapter, WGPUSurfaceCapabilities * capabilities);
extern void NativeSurfaceGetCurrentTexture(WGPUSurface cSelf, WGPUSurfaceTexture * surfaceTexture);
extern WGPUTextureFormat NativeSurfaceGetPreferredFormat(WGPUSurface cSelf, WGPUAdapter adapter);
extern void NativeSurfacePresent(WGPUSurface cSelf);
extern void NativeSurfaceUnconfigure(WGPUSurface cSelf);
extern void NativeSurfaceAddRef(WGPUSurface cSelf);
extern void NativeSurfaceRelease(WGPUSurface cSelf);
extern WGPUTexture NativeSwapChainGetCurrentTexture(WGPUSwapChain cSelf);
extern WGPUTextureView NativeSwapChainGetCurrentTextureView(WGPUSwapChain cSelf);
extern void NativeSwapChainPresent(WGPUSwapChain cSelf);
extern void NativeSwapChainAddRef(WGPUSwapChain cSelf);
extern void NativeSwapChainRelease(WGPUSwapChain cSelf);
extern WGPUTextureView NativeTextureCreateErrorView(WGPUTexture cSelf, WGPUTextureViewDescriptor const * descriptor);
extern WGPUTextureView NativeTextureCreateView(WGPUTexture cSelf, WGPUTextureViewDescriptor const * descriptor);
extern void NativeTextureDestroy(WGPUTexture cSelf);
extern uint32_t NativeTextureGetDepthOrArrayLayers(WGPUTexture cSelf);
extern WGPUTextureDimension NativeTextureGetDimension(WGPUTexture cSelf);
extern WGPUTextureFormat NativeTextureGetFormat(WGPUTexture cSelf);
extern uint32_t NativeTextureGetHeight(WGPUTexture cSelf);
extern uint32_t NativeTextureGetMipLevelCount(WGPUTexture cSelf);
extern uint32_t NativeTextureGetSampleCount(WGPUTexture cSelf);
extern WGPUTextureUsageFlags NativeTextureGetUsage(WGPUTexture cSelf);
extern uint32_t NativeTextureGetWidth(WGPUTexture cSelf);
extern void NativeTextureSetLabel(WGPUTexture cSelf, char const * label);
extern void NativeTextureAddRef(WGPUTexture cSelf);
extern void NativeTextureRelease(WGPUTexture cSelf);
extern void NativeTextureViewSetLabel(WGPUTextureView cSelf, char const * label);
extern void NativeTextureViewAddRef(WGPUTextureView cSelf);
extern void NativeTextureViewRelease(WGPUTextureView cSelf);

}

extern "C" {
    using namespace dawn::native;

    void wgpuAdapterInfoFreeMembers (WGPUAdapterInfo value) {
        return NativeAdapterInfoFreeMembers(value);
    }
    void wgpuAdapterPropertiesFreeMembers (WGPUAdapterProperties value) {
        return NativeAdapterPropertiesFreeMembers(value);
    }
    void wgpuAdapterPropertiesMemoryHeapsFreeMembers (WGPUAdapterPropertiesMemoryHeaps value) {
        return NativeAdapterPropertiesMemoryHeapsFreeMembers(value);
    }
    WGPUInstance wgpuCreateInstance (WGPUInstanceDescriptor const * descriptor) {
        return NativeCreateInstance(descriptor);
    }
    void wgpuDrmFormatCapabilitiesFreeMembers (WGPUDrmFormatCapabilities value) {
        return NativeDrmFormatCapabilitiesFreeMembers(value);
    }
    WGPUStatus wgpuGetInstanceFeatures (WGPUInstanceFeatures * features) {
        return NativeGetInstanceFeatures(features);
    }
    WGPUProc wgpuGetProcAddress (WGPUDevice device, char const * procName) {
        return NativeGetProcAddress(device, procName);
    }
    void wgpuSharedBufferMemoryEndAccessStateFreeMembers (WGPUSharedBufferMemoryEndAccessState value) {
        return NativeSharedBufferMemoryEndAccessStateFreeMembers(value);
    }
    void wgpuSharedTextureMemoryEndAccessStateFreeMembers (WGPUSharedTextureMemoryEndAccessState value) {
        return NativeSharedTextureMemoryEndAccessStateFreeMembers(value);
    }
    void wgpuSurfaceCapabilitiesFreeMembers (WGPUSurfaceCapabilities value) {
        return NativeSurfaceCapabilitiesFreeMembers(value);
    }

    WGPUDevice wgpuAdapterCreateDevice(WGPUAdapter cSelf, WGPUDeviceDescriptor const * descriptor) {
        return NativeAdapterCreateDevice(
            cSelf, descriptor);
    }
    size_t wgpuAdapterEnumerateFeatures(WGPUAdapter cSelf, WGPUFeatureName * features) {
        return NativeAdapterEnumerateFeatures(
            cSelf, features);
    }
    WGPUStatus wgpuAdapterGetFormatCapabilities(WGPUAdapter cSelf, WGPUTextureFormat format, WGPUFormatCapabilities * capabilities) {
        return NativeAdapterGetFormatCapabilities(
            cSelf, format, capabilities);
    }
    WGPUStatus wgpuAdapterGetInfo(WGPUAdapter cSelf, WGPUAdapterInfo * info) {
        return NativeAdapterGetInfo(
            cSelf, info);
    }
    WGPUInstance wgpuAdapterGetInstance(WGPUAdapter cSelf) {
        return NativeAdapterGetInstance(
            cSelf);
    }
    WGPUStatus wgpuAdapterGetLimits(WGPUAdapter cSelf, WGPUSupportedLimits * limits) {
        return NativeAdapterGetLimits(
            cSelf, limits);
    }
    WGPUStatus wgpuAdapterGetProperties(WGPUAdapter cSelf, WGPUAdapterProperties * properties) {
        return NativeAdapterGetProperties(
            cSelf, properties);
    }
    WGPUBool wgpuAdapterHasFeature(WGPUAdapter cSelf, WGPUFeatureName feature) {
        return NativeAdapterHasFeature(
            cSelf, feature);
    }
    void wgpuAdapterRequestDevice(WGPUAdapter cSelf, WGPUDeviceDescriptor const * descriptor, WGPURequestDeviceCallback callback, void * userdata) {
        return NativeAdapterRequestDevice(
            cSelf, descriptor, callback, userdata);
    }
    WGPUFuture wgpuAdapterRequestDevice2(WGPUAdapter cSelf, WGPUDeviceDescriptor const * options, WGPURequestDeviceCallbackInfo2 callbackInfo) {
        return NativeAdapterRequestDevice2(
            cSelf, options, callbackInfo);
    }
    WGPUFuture wgpuAdapterRequestDeviceF(WGPUAdapter cSelf, WGPUDeviceDescriptor const * options, WGPURequestDeviceCallbackInfo callbackInfo) {
        return NativeAdapterRequestDeviceF(
            cSelf, options, callbackInfo);
    }
    void wgpuAdapterAddRef(WGPUAdapter cSelf) {
        return NativeAdapterAddRef(
            cSelf);
    }
    void wgpuAdapterRelease(WGPUAdapter cSelf) {
        return NativeAdapterRelease(
            cSelf);
    }
    void wgpuBindGroupSetLabel(WGPUBindGroup cSelf, char const * label) {
        return NativeBindGroupSetLabel(
            cSelf, label);
    }
    void wgpuBindGroupAddRef(WGPUBindGroup cSelf) {
        return NativeBindGroupAddRef(
            cSelf);
    }
    void wgpuBindGroupRelease(WGPUBindGroup cSelf) {
        return NativeBindGroupRelease(
            cSelf);
    }
    void wgpuBindGroupLayoutSetLabel(WGPUBindGroupLayout cSelf, char const * label) {
        return NativeBindGroupLayoutSetLabel(
            cSelf, label);
    }
    void wgpuBindGroupLayoutAddRef(WGPUBindGroupLayout cSelf) {
        return NativeBindGroupLayoutAddRef(
            cSelf);
    }
    void wgpuBindGroupLayoutRelease(WGPUBindGroupLayout cSelf) {
        return NativeBindGroupLayoutRelease(
            cSelf);
    }
    void wgpuBufferDestroy(WGPUBuffer cSelf) {
        return NativeBufferDestroy(
            cSelf);
    }
    void const * wgpuBufferGetConstMappedRange(WGPUBuffer cSelf, size_t offset, size_t size) {
        return NativeBufferGetConstMappedRange(
            cSelf, offset, size);
    }
    WGPUBufferMapState wgpuBufferGetMapState(WGPUBuffer cSelf) {
        return NativeBufferGetMapState(
            cSelf);
    }
    void * wgpuBufferGetMappedRange(WGPUBuffer cSelf, size_t offset, size_t size) {
        return NativeBufferGetMappedRange(
            cSelf, offset, size);
    }
    uint64_t wgpuBufferGetSize(WGPUBuffer cSelf) {
        return NativeBufferGetSize(
            cSelf);
    }
    WGPUBufferUsageFlags wgpuBufferGetUsage(WGPUBuffer cSelf) {
        return NativeBufferGetUsage(
            cSelf);
    }
    void wgpuBufferMapAsync(WGPUBuffer cSelf, WGPUMapModeFlags mode, size_t offset, size_t size, WGPUBufferMapCallback callback, void * userdata) {
        return NativeBufferMapAsync(
            cSelf, mode, offset, size, callback, userdata);
    }
    WGPUFuture wgpuBufferMapAsyncF(WGPUBuffer cSelf, WGPUMapModeFlags mode, size_t offset, size_t size, WGPUBufferMapCallbackInfo callbackInfo) {
        return NativeBufferMapAsyncF(
            cSelf, mode, offset, size, callbackInfo);
    }
    void wgpuBufferSetLabel(WGPUBuffer cSelf, char const * label) {
        return NativeBufferSetLabel(
            cSelf, label);
    }
    void wgpuBufferUnmap(WGPUBuffer cSelf) {
        return NativeBufferUnmap(
            cSelf);
    }
    void wgpuBufferAddRef(WGPUBuffer cSelf) {
        return NativeBufferAddRef(
            cSelf);
    }
    void wgpuBufferRelease(WGPUBuffer cSelf) {
        return NativeBufferRelease(
            cSelf);
    }
    void wgpuCommandBufferSetLabel(WGPUCommandBuffer cSelf, char const * label) {
        return NativeCommandBufferSetLabel(
            cSelf, label);
    }
    void wgpuCommandBufferAddRef(WGPUCommandBuffer cSelf) {
        return NativeCommandBufferAddRef(
            cSelf);
    }
    void wgpuCommandBufferRelease(WGPUCommandBuffer cSelf) {
        return NativeCommandBufferRelease(
            cSelf);
    }
    WGPUComputePassEncoder wgpuCommandEncoderBeginComputePass(WGPUCommandEncoder cSelf, WGPUComputePassDescriptor const * descriptor) {
        return NativeCommandEncoderBeginComputePass(
            cSelf, descriptor);
    }
    WGPURenderPassEncoder wgpuCommandEncoderBeginRenderPass(WGPUCommandEncoder cSelf, WGPURenderPassDescriptor const * descriptor) {
        return NativeCommandEncoderBeginRenderPass(
            cSelf, descriptor);
    }
    void wgpuCommandEncoderClearBuffer(WGPUCommandEncoder cSelf, WGPUBuffer buffer, uint64_t offset, uint64_t size) {
        return NativeCommandEncoderClearBuffer(
            cSelf, buffer, offset, size);
    }
    void wgpuCommandEncoderCopyBufferToBuffer(WGPUCommandEncoder cSelf, WGPUBuffer source, uint64_t sourceOffset, WGPUBuffer destination, uint64_t destinationOffset, uint64_t size) {
        return NativeCommandEncoderCopyBufferToBuffer(
            cSelf, source, sourceOffset, destination, destinationOffset, size);
    }
    void wgpuCommandEncoderCopyBufferToTexture(WGPUCommandEncoder cSelf, WGPUImageCopyBuffer const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize) {
        return NativeCommandEncoderCopyBufferToTexture(
            cSelf, source, destination, copySize);
    }
    void wgpuCommandEncoderCopyTextureToBuffer(WGPUCommandEncoder cSelf, WGPUImageCopyTexture const * source, WGPUImageCopyBuffer const * destination, WGPUExtent3D const * copySize) {
        return NativeCommandEncoderCopyTextureToBuffer(
            cSelf, source, destination, copySize);
    }
    void wgpuCommandEncoderCopyTextureToTexture(WGPUCommandEncoder cSelf, WGPUImageCopyTexture const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize) {
        return NativeCommandEncoderCopyTextureToTexture(
            cSelf, source, destination, copySize);
    }
    WGPUCommandBuffer wgpuCommandEncoderFinish(WGPUCommandEncoder cSelf, WGPUCommandBufferDescriptor const * descriptor) {
        return NativeCommandEncoderFinish(
            cSelf, descriptor);
    }
    void wgpuCommandEncoderInjectValidationError(WGPUCommandEncoder cSelf, char const * message) {
        return NativeCommandEncoderInjectValidationError(
            cSelf, message);
    }
    void wgpuCommandEncoderInsertDebugMarker(WGPUCommandEncoder cSelf, char const * markerLabel) {
        return NativeCommandEncoderInsertDebugMarker(
            cSelf, markerLabel);
    }
    void wgpuCommandEncoderPopDebugGroup(WGPUCommandEncoder cSelf) {
        return NativeCommandEncoderPopDebugGroup(
            cSelf);
    }
    void wgpuCommandEncoderPushDebugGroup(WGPUCommandEncoder cSelf, char const * groupLabel) {
        return NativeCommandEncoderPushDebugGroup(
            cSelf, groupLabel);
    }
    void wgpuCommandEncoderResolveQuerySet(WGPUCommandEncoder cSelf, WGPUQuerySet querySet, uint32_t firstQuery, uint32_t queryCount, WGPUBuffer destination, uint64_t destinationOffset) {
        return NativeCommandEncoderResolveQuerySet(
            cSelf, querySet, firstQuery, queryCount, destination, destinationOffset);
    }
    void wgpuCommandEncoderSetLabel(WGPUCommandEncoder cSelf, char const * label) {
        return NativeCommandEncoderSetLabel(
            cSelf, label);
    }
    void wgpuCommandEncoderWriteBuffer(WGPUCommandEncoder cSelf, WGPUBuffer buffer, uint64_t bufferOffset, uint8_t const * data, uint64_t size) {
        return NativeCommandEncoderWriteBuffer(
            cSelf, buffer, bufferOffset, data, size);
    }
    void wgpuCommandEncoderWriteTimestamp(WGPUCommandEncoder cSelf, WGPUQuerySet querySet, uint32_t queryIndex) {
        return NativeCommandEncoderWriteTimestamp(
            cSelf, querySet, queryIndex);
    }
    void wgpuCommandEncoderAddRef(WGPUCommandEncoder cSelf) {
        return NativeCommandEncoderAddRef(
            cSelf);
    }
    void wgpuCommandEncoderRelease(WGPUCommandEncoder cSelf) {
        return NativeCommandEncoderRelease(
            cSelf);
    }
    void wgpuComputePassEncoderDispatchWorkgroups(WGPUComputePassEncoder cSelf, uint32_t workgroupCountX, uint32_t workgroupCountY, uint32_t workgroupCountZ) {
        return NativeComputePassEncoderDispatchWorkgroups(
            cSelf, workgroupCountX, workgroupCountY, workgroupCountZ);
    }
    void wgpuComputePassEncoderDispatchWorkgroupsIndirect(WGPUComputePassEncoder cSelf, WGPUBuffer indirectBuffer, uint64_t indirectOffset) {
        return NativeComputePassEncoderDispatchWorkgroupsIndirect(
            cSelf, indirectBuffer, indirectOffset);
    }
    void wgpuComputePassEncoderEnd(WGPUComputePassEncoder cSelf) {
        return NativeComputePassEncoderEnd(
            cSelf);
    }
    void wgpuComputePassEncoderInsertDebugMarker(WGPUComputePassEncoder cSelf, char const * markerLabel) {
        return NativeComputePassEncoderInsertDebugMarker(
            cSelf, markerLabel);
    }
    void wgpuComputePassEncoderPopDebugGroup(WGPUComputePassEncoder cSelf) {
        return NativeComputePassEncoderPopDebugGroup(
            cSelf);
    }
    void wgpuComputePassEncoderPushDebugGroup(WGPUComputePassEncoder cSelf, char const * groupLabel) {
        return NativeComputePassEncoderPushDebugGroup(
            cSelf, groupLabel);
    }
    void wgpuComputePassEncoderSetBindGroup(WGPUComputePassEncoder cSelf, uint32_t groupIndex, WGPUBindGroup group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) {
        return NativeComputePassEncoderSetBindGroup(
            cSelf, groupIndex, group, dynamicOffsetCount, dynamicOffsets);
    }
    void wgpuComputePassEncoderSetLabel(WGPUComputePassEncoder cSelf, char const * label) {
        return NativeComputePassEncoderSetLabel(
            cSelf, label);
    }
    void wgpuComputePassEncoderSetPipeline(WGPUComputePassEncoder cSelf, WGPUComputePipeline pipeline) {
        return NativeComputePassEncoderSetPipeline(
            cSelf, pipeline);
    }
    void wgpuComputePassEncoderWriteTimestamp(WGPUComputePassEncoder cSelf, WGPUQuerySet querySet, uint32_t queryIndex) {
        return NativeComputePassEncoderWriteTimestamp(
            cSelf, querySet, queryIndex);
    }
    void wgpuComputePassEncoderAddRef(WGPUComputePassEncoder cSelf) {
        return NativeComputePassEncoderAddRef(
            cSelf);
    }
    void wgpuComputePassEncoderRelease(WGPUComputePassEncoder cSelf) {
        return NativeComputePassEncoderRelease(
            cSelf);
    }
    WGPUBindGroupLayout wgpuComputePipelineGetBindGroupLayout(WGPUComputePipeline cSelf, uint32_t groupIndex) {
        return NativeComputePipelineGetBindGroupLayout(
            cSelf, groupIndex);
    }
    void wgpuComputePipelineSetLabel(WGPUComputePipeline cSelf, char const * label) {
        return NativeComputePipelineSetLabel(
            cSelf, label);
    }
    void wgpuComputePipelineAddRef(WGPUComputePipeline cSelf) {
        return NativeComputePipelineAddRef(
            cSelf);
    }
    void wgpuComputePipelineRelease(WGPUComputePipeline cSelf) {
        return NativeComputePipelineRelease(
            cSelf);
    }
    WGPUBindGroup wgpuDeviceCreateBindGroup(WGPUDevice cSelf, WGPUBindGroupDescriptor const * descriptor) {
        return NativeDeviceCreateBindGroup(
            cSelf, descriptor);
    }
    WGPUBindGroupLayout wgpuDeviceCreateBindGroupLayout(WGPUDevice cSelf, WGPUBindGroupLayoutDescriptor const * descriptor) {
        return NativeDeviceCreateBindGroupLayout(
            cSelf, descriptor);
    }
    WGPUBuffer wgpuDeviceCreateBuffer(WGPUDevice cSelf, WGPUBufferDescriptor const * descriptor) {
        return NativeDeviceCreateBuffer(
            cSelf, descriptor);
    }
    WGPUCommandEncoder wgpuDeviceCreateCommandEncoder(WGPUDevice cSelf, WGPUCommandEncoderDescriptor const * descriptor) {
        return NativeDeviceCreateCommandEncoder(
            cSelf, descriptor);
    }
    WGPUComputePipeline wgpuDeviceCreateComputePipeline(WGPUDevice cSelf, WGPUComputePipelineDescriptor const * descriptor) {
        return NativeDeviceCreateComputePipeline(
            cSelf, descriptor);
    }
    void wgpuDeviceCreateComputePipelineAsync(WGPUDevice cSelf, WGPUComputePipelineDescriptor const * descriptor, WGPUCreateComputePipelineAsyncCallback callback, void * userdata) {
        return NativeDeviceCreateComputePipelineAsync(
            cSelf, descriptor, callback, userdata);
    }
    WGPUFuture wgpuDeviceCreateComputePipelineAsync2(WGPUDevice cSelf, WGPUComputePipelineDescriptor const * descriptor, WGPUCreateComputePipelineAsyncCallbackInfo2 callbackInfo) {
        return NativeDeviceCreateComputePipelineAsync2(
            cSelf, descriptor, callbackInfo);
    }
    WGPUFuture wgpuDeviceCreateComputePipelineAsyncF(WGPUDevice cSelf, WGPUComputePipelineDescriptor const * descriptor, WGPUCreateComputePipelineAsyncCallbackInfo callbackInfo) {
        return NativeDeviceCreateComputePipelineAsyncF(
            cSelf, descriptor, callbackInfo);
    }
    WGPUBuffer wgpuDeviceCreateErrorBuffer(WGPUDevice cSelf, WGPUBufferDescriptor const * descriptor) {
        return NativeDeviceCreateErrorBuffer(
            cSelf, descriptor);
    }
    WGPUExternalTexture wgpuDeviceCreateErrorExternalTexture(WGPUDevice cSelf) {
        return NativeDeviceCreateErrorExternalTexture(
            cSelf);
    }
    WGPUShaderModule wgpuDeviceCreateErrorShaderModule(WGPUDevice cSelf, WGPUShaderModuleDescriptor const * descriptor, char const * errorMessage) {
        return NativeDeviceCreateErrorShaderModule(
            cSelf, descriptor, errorMessage);
    }
    WGPUTexture wgpuDeviceCreateErrorTexture(WGPUDevice cSelf, WGPUTextureDescriptor const * descriptor) {
        return NativeDeviceCreateErrorTexture(
            cSelf, descriptor);
    }
    WGPUExternalTexture wgpuDeviceCreateExternalTexture(WGPUDevice cSelf, WGPUExternalTextureDescriptor const * externalTextureDescriptor) {
        return NativeDeviceCreateExternalTexture(
            cSelf, externalTextureDescriptor);
    }
    WGPUPipelineLayout wgpuDeviceCreatePipelineLayout(WGPUDevice cSelf, WGPUPipelineLayoutDescriptor const * descriptor) {
        return NativeDeviceCreatePipelineLayout(
            cSelf, descriptor);
    }
    WGPUQuerySet wgpuDeviceCreateQuerySet(WGPUDevice cSelf, WGPUQuerySetDescriptor const * descriptor) {
        return NativeDeviceCreateQuerySet(
            cSelf, descriptor);
    }
    WGPURenderBundleEncoder wgpuDeviceCreateRenderBundleEncoder(WGPUDevice cSelf, WGPURenderBundleEncoderDescriptor const * descriptor) {
        return NativeDeviceCreateRenderBundleEncoder(
            cSelf, descriptor);
    }
    WGPURenderPipeline wgpuDeviceCreateRenderPipeline(WGPUDevice cSelf, WGPURenderPipelineDescriptor const * descriptor) {
        return NativeDeviceCreateRenderPipeline(
            cSelf, descriptor);
    }
    void wgpuDeviceCreateRenderPipelineAsync(WGPUDevice cSelf, WGPURenderPipelineDescriptor const * descriptor, WGPUCreateRenderPipelineAsyncCallback callback, void * userdata) {
        return NativeDeviceCreateRenderPipelineAsync(
            cSelf, descriptor, callback, userdata);
    }
    WGPUFuture wgpuDeviceCreateRenderPipelineAsync2(WGPUDevice cSelf, WGPURenderPipelineDescriptor const * descriptor, WGPUCreateRenderPipelineAsyncCallbackInfo2 callbackInfo) {
        return NativeDeviceCreateRenderPipelineAsync2(
            cSelf, descriptor, callbackInfo);
    }
    WGPUFuture wgpuDeviceCreateRenderPipelineAsyncF(WGPUDevice cSelf, WGPURenderPipelineDescriptor const * descriptor, WGPUCreateRenderPipelineAsyncCallbackInfo callbackInfo) {
        return NativeDeviceCreateRenderPipelineAsyncF(
            cSelf, descriptor, callbackInfo);
    }
    WGPUSampler wgpuDeviceCreateSampler(WGPUDevice cSelf, WGPUSamplerDescriptor const * descriptor) {
        return NativeDeviceCreateSampler(
            cSelf, descriptor);
    }
    WGPUShaderModule wgpuDeviceCreateShaderModule(WGPUDevice cSelf, WGPUShaderModuleDescriptor const * descriptor) {
        return NativeDeviceCreateShaderModule(
            cSelf, descriptor);
    }
    WGPUSwapChain wgpuDeviceCreateSwapChain(WGPUDevice cSelf, WGPUSurface surface, WGPUSwapChainDescriptor const * descriptor) {
        return NativeDeviceCreateSwapChain(
            cSelf, surface, descriptor);
    }
    WGPUTexture wgpuDeviceCreateTexture(WGPUDevice cSelf, WGPUTextureDescriptor const * descriptor) {
        return NativeDeviceCreateTexture(
            cSelf, descriptor);
    }
    void wgpuDeviceDestroy(WGPUDevice cSelf) {
        return NativeDeviceDestroy(
            cSelf);
    }
    size_t wgpuDeviceEnumerateFeatures(WGPUDevice cSelf, WGPUFeatureName * features) {
        return NativeDeviceEnumerateFeatures(
            cSelf, features);
    }
    void wgpuDeviceForceLoss(WGPUDevice cSelf, WGPUDeviceLostReason type, char const * message) {
        return NativeDeviceForceLoss(
            cSelf, type, message);
    }
    WGPUStatus wgpuDeviceGetAHardwareBufferProperties(WGPUDevice cSelf, void * handle, WGPUAHardwareBufferProperties * properties) {
        return NativeDeviceGetAHardwareBufferProperties(
            cSelf, handle, properties);
    }
    WGPUAdapter wgpuDeviceGetAdapter(WGPUDevice cSelf) {
        return NativeDeviceGetAdapter(
            cSelf);
    }
    WGPUStatus wgpuDeviceGetLimits(WGPUDevice cSelf, WGPUSupportedLimits * limits) {
        return NativeDeviceGetLimits(
            cSelf, limits);
    }
    WGPUQueue wgpuDeviceGetQueue(WGPUDevice cSelf) {
        return NativeDeviceGetQueue(
            cSelf);
    }
    WGPUTextureUsageFlags wgpuDeviceGetSupportedSurfaceUsage(WGPUDevice cSelf, WGPUSurface surface) {
        return NativeDeviceGetSupportedSurfaceUsage(
            cSelf, surface);
    }
    WGPUBool wgpuDeviceHasFeature(WGPUDevice cSelf, WGPUFeatureName feature) {
        return NativeDeviceHasFeature(
            cSelf, feature);
    }
    WGPUSharedBufferMemory wgpuDeviceImportSharedBufferMemory(WGPUDevice cSelf, WGPUSharedBufferMemoryDescriptor const * descriptor) {
        return NativeDeviceImportSharedBufferMemory(
            cSelf, descriptor);
    }
    WGPUSharedFence wgpuDeviceImportSharedFence(WGPUDevice cSelf, WGPUSharedFenceDescriptor const * descriptor) {
        return NativeDeviceImportSharedFence(
            cSelf, descriptor);
    }
    WGPUSharedTextureMemory wgpuDeviceImportSharedTextureMemory(WGPUDevice cSelf, WGPUSharedTextureMemoryDescriptor const * descriptor) {
        return NativeDeviceImportSharedTextureMemory(
            cSelf, descriptor);
    }
    void wgpuDeviceInjectError(WGPUDevice cSelf, WGPUErrorType type, char const * message) {
        return NativeDeviceInjectError(
            cSelf, type, message);
    }
    void wgpuDevicePopErrorScope(WGPUDevice cSelf, WGPUErrorCallback oldCallback, void * userdata) {
        return NativeDevicePopErrorScope(
            cSelf, oldCallback, userdata);
    }
    WGPUFuture wgpuDevicePopErrorScope2(WGPUDevice cSelf, WGPUPopErrorScopeCallbackInfo2 callbackInfo) {
        return NativeDevicePopErrorScope2(
            cSelf, callbackInfo);
    }
    WGPUFuture wgpuDevicePopErrorScopeF(WGPUDevice cSelf, WGPUPopErrorScopeCallbackInfo callbackInfo) {
        return NativeDevicePopErrorScopeF(
            cSelf, callbackInfo);
    }
    void wgpuDevicePushErrorScope(WGPUDevice cSelf, WGPUErrorFilter filter) {
        return NativeDevicePushErrorScope(
            cSelf, filter);
    }
    void wgpuDeviceSetDeviceLostCallback(WGPUDevice cSelf, WGPUDeviceLostCallback callback, void * userdata) {
        return NativeDeviceSetDeviceLostCallback(
            cSelf, callback, userdata);
    }
    void wgpuDeviceSetLabel(WGPUDevice cSelf, char const * label) {
        return NativeDeviceSetLabel(
            cSelf, label);
    }
    void wgpuDeviceSetLoggingCallback(WGPUDevice cSelf, WGPULoggingCallback callback, void * userdata) {
        return NativeDeviceSetLoggingCallback(
            cSelf, callback, userdata);
    }
    void wgpuDeviceSetUncapturedErrorCallback(WGPUDevice cSelf, WGPUErrorCallback callback, void * userdata) {
        return NativeDeviceSetUncapturedErrorCallback(
            cSelf, callback, userdata);
    }
    void wgpuDeviceTick(WGPUDevice cSelf) {
        return NativeDeviceTick(
            cSelf);
    }
    void wgpuDeviceValidateTextureDescriptor(WGPUDevice cSelf, WGPUTextureDescriptor const * descriptor) {
        return NativeDeviceValidateTextureDescriptor(
            cSelf, descriptor);
    }
    void wgpuDeviceAddRef(WGPUDevice cSelf) {
        return NativeDeviceAddRef(
            cSelf);
    }
    void wgpuDeviceRelease(WGPUDevice cSelf) {
        return NativeDeviceRelease(
            cSelf);
    }
    void wgpuExternalTextureDestroy(WGPUExternalTexture cSelf) {
        return NativeExternalTextureDestroy(
            cSelf);
    }
    void wgpuExternalTextureExpire(WGPUExternalTexture cSelf) {
        return NativeExternalTextureExpire(
            cSelf);
    }
    void wgpuExternalTextureRefresh(WGPUExternalTexture cSelf) {
        return NativeExternalTextureRefresh(
            cSelf);
    }
    void wgpuExternalTextureSetLabel(WGPUExternalTexture cSelf, char const * label) {
        return NativeExternalTextureSetLabel(
            cSelf, label);
    }
    void wgpuExternalTextureAddRef(WGPUExternalTexture cSelf) {
        return NativeExternalTextureAddRef(
            cSelf);
    }
    void wgpuExternalTextureRelease(WGPUExternalTexture cSelf) {
        return NativeExternalTextureRelease(
            cSelf);
    }
    WGPUSurface wgpuInstanceCreateSurface(WGPUInstance cSelf, WGPUSurfaceDescriptor const * descriptor) {
        return NativeInstanceCreateSurface(
            cSelf, descriptor);
    }
    size_t wgpuInstanceEnumerateWGSLLanguageFeatures(WGPUInstance cSelf, WGPUWGSLFeatureName * features) {
        return NativeInstanceEnumerateWGSLLanguageFeatures(
            cSelf, features);
    }
    WGPUBool wgpuInstanceHasWGSLLanguageFeature(WGPUInstance cSelf, WGPUWGSLFeatureName feature) {
        return NativeInstanceHasWGSLLanguageFeature(
            cSelf, feature);
    }
    void wgpuInstanceProcessEvents(WGPUInstance cSelf) {
        return NativeInstanceProcessEvents(
            cSelf);
    }
    void wgpuInstanceRequestAdapter(WGPUInstance cSelf, WGPURequestAdapterOptions const * options, WGPURequestAdapterCallback callback, void * userdata) {
        return NativeInstanceRequestAdapter(
            cSelf, options, callback, userdata);
    }
    WGPUFuture wgpuInstanceRequestAdapter2(WGPUInstance cSelf, WGPURequestAdapterOptions const * options, WGPURequestAdapterCallbackInfo2 callbackInfo) {
        return NativeInstanceRequestAdapter2(
            cSelf, options, callbackInfo);
    }
    WGPUFuture wgpuInstanceRequestAdapterF(WGPUInstance cSelf, WGPURequestAdapterOptions const * options, WGPURequestAdapterCallbackInfo callbackInfo) {
        return NativeInstanceRequestAdapterF(
            cSelf, options, callbackInfo);
    }
    WGPUWaitStatus wgpuInstanceWaitAny(WGPUInstance cSelf, size_t futureCount, WGPUFutureWaitInfo * futures, uint64_t timeoutNS) {
        return NativeInstanceWaitAny(
            cSelf, futureCount, futures, timeoutNS);
    }
    void wgpuInstanceAddRef(WGPUInstance cSelf) {
        return NativeInstanceAddRef(
            cSelf);
    }
    void wgpuInstanceRelease(WGPUInstance cSelf) {
        return NativeInstanceRelease(
            cSelf);
    }
    void wgpuPipelineLayoutSetLabel(WGPUPipelineLayout cSelf, char const * label) {
        return NativePipelineLayoutSetLabel(
            cSelf, label);
    }
    void wgpuPipelineLayoutAddRef(WGPUPipelineLayout cSelf) {
        return NativePipelineLayoutAddRef(
            cSelf);
    }
    void wgpuPipelineLayoutRelease(WGPUPipelineLayout cSelf) {
        return NativePipelineLayoutRelease(
            cSelf);
    }
    void wgpuQuerySetDestroy(WGPUQuerySet cSelf) {
        return NativeQuerySetDestroy(
            cSelf);
    }
    uint32_t wgpuQuerySetGetCount(WGPUQuerySet cSelf) {
        return NativeQuerySetGetCount(
            cSelf);
    }
    WGPUQueryType wgpuQuerySetGetType(WGPUQuerySet cSelf) {
        return NativeQuerySetGetType(
            cSelf);
    }
    void wgpuQuerySetSetLabel(WGPUQuerySet cSelf, char const * label) {
        return NativeQuerySetSetLabel(
            cSelf, label);
    }
    void wgpuQuerySetAddRef(WGPUQuerySet cSelf) {
        return NativeQuerySetAddRef(
            cSelf);
    }
    void wgpuQuerySetRelease(WGPUQuerySet cSelf) {
        return NativeQuerySetRelease(
            cSelf);
    }
    void wgpuQueueCopyExternalTextureForBrowser(WGPUQueue cSelf, WGPUImageCopyExternalTexture const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize, WGPUCopyTextureForBrowserOptions const * options) {
        return NativeQueueCopyExternalTextureForBrowser(
            cSelf, source, destination, copySize, options);
    }
    void wgpuQueueCopyTextureForBrowser(WGPUQueue cSelf, WGPUImageCopyTexture const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize, WGPUCopyTextureForBrowserOptions const * options) {
        return NativeQueueCopyTextureForBrowser(
            cSelf, source, destination, copySize, options);
    }
    void wgpuQueueOnSubmittedWorkDone(WGPUQueue cSelf, WGPUQueueWorkDoneCallback callback, void * userdata) {
        return NativeQueueOnSubmittedWorkDone(
            cSelf, callback, userdata);
    }
    WGPUFuture wgpuQueueOnSubmittedWorkDone2(WGPUQueue cSelf, WGPUQueueWorkDoneCallbackInfo2 callbackInfo) {
        return NativeQueueOnSubmittedWorkDone2(
            cSelf, callbackInfo);
    }
    WGPUFuture wgpuQueueOnSubmittedWorkDoneF(WGPUQueue cSelf, WGPUQueueWorkDoneCallbackInfo callbackInfo) {
        return NativeQueueOnSubmittedWorkDoneF(
            cSelf, callbackInfo);
    }
    void wgpuQueueSetLabel(WGPUQueue cSelf, char const * label) {
        return NativeQueueSetLabel(
            cSelf, label);
    }
    void wgpuQueueSubmit(WGPUQueue cSelf, size_t commandCount, WGPUCommandBuffer const * commands) {
        return NativeQueueSubmit(
            cSelf, commandCount, commands);
    }
    void wgpuQueueWriteBuffer(WGPUQueue cSelf, WGPUBuffer buffer, uint64_t bufferOffset, void const * data, size_t size) {
        return NativeQueueWriteBuffer(
            cSelf, buffer, bufferOffset, data, size);
    }
    void wgpuQueueWriteTexture(WGPUQueue cSelf, WGPUImageCopyTexture const * destination, void const * data, size_t dataSize, WGPUTextureDataLayout const * dataLayout, WGPUExtent3D const * writeSize) {
        return NativeQueueWriteTexture(
            cSelf, destination, data, dataSize, dataLayout, writeSize);
    }
    void wgpuQueueAddRef(WGPUQueue cSelf) {
        return NativeQueueAddRef(
            cSelf);
    }
    void wgpuQueueRelease(WGPUQueue cSelf) {
        return NativeQueueRelease(
            cSelf);
    }
    void wgpuRenderBundleSetLabel(WGPURenderBundle cSelf, char const * label) {
        return NativeRenderBundleSetLabel(
            cSelf, label);
    }
    void wgpuRenderBundleAddRef(WGPURenderBundle cSelf) {
        return NativeRenderBundleAddRef(
            cSelf);
    }
    void wgpuRenderBundleRelease(WGPURenderBundle cSelf) {
        return NativeRenderBundleRelease(
            cSelf);
    }
    void wgpuRenderBundleEncoderDraw(WGPURenderBundleEncoder cSelf, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) {
        return NativeRenderBundleEncoderDraw(
            cSelf, vertexCount, instanceCount, firstVertex, firstInstance);
    }
    void wgpuRenderBundleEncoderDrawIndexed(WGPURenderBundleEncoder cSelf, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance) {
        return NativeRenderBundleEncoderDrawIndexed(
            cSelf, indexCount, instanceCount, firstIndex, baseVertex, firstInstance);
    }
    void wgpuRenderBundleEncoderDrawIndexedIndirect(WGPURenderBundleEncoder cSelf, WGPUBuffer indirectBuffer, uint64_t indirectOffset) {
        return NativeRenderBundleEncoderDrawIndexedIndirect(
            cSelf, indirectBuffer, indirectOffset);
    }
    void wgpuRenderBundleEncoderDrawIndirect(WGPURenderBundleEncoder cSelf, WGPUBuffer indirectBuffer, uint64_t indirectOffset) {
        return NativeRenderBundleEncoderDrawIndirect(
            cSelf, indirectBuffer, indirectOffset);
    }
    WGPURenderBundle wgpuRenderBundleEncoderFinish(WGPURenderBundleEncoder cSelf, WGPURenderBundleDescriptor const * descriptor) {
        return NativeRenderBundleEncoderFinish(
            cSelf, descriptor);
    }
    void wgpuRenderBundleEncoderInsertDebugMarker(WGPURenderBundleEncoder cSelf, char const * markerLabel) {
        return NativeRenderBundleEncoderInsertDebugMarker(
            cSelf, markerLabel);
    }
    void wgpuRenderBundleEncoderPopDebugGroup(WGPURenderBundleEncoder cSelf) {
        return NativeRenderBundleEncoderPopDebugGroup(
            cSelf);
    }
    void wgpuRenderBundleEncoderPushDebugGroup(WGPURenderBundleEncoder cSelf, char const * groupLabel) {
        return NativeRenderBundleEncoderPushDebugGroup(
            cSelf, groupLabel);
    }
    void wgpuRenderBundleEncoderSetBindGroup(WGPURenderBundleEncoder cSelf, uint32_t groupIndex, WGPUBindGroup group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) {
        return NativeRenderBundleEncoderSetBindGroup(
            cSelf, groupIndex, group, dynamicOffsetCount, dynamicOffsets);
    }
    void wgpuRenderBundleEncoderSetIndexBuffer(WGPURenderBundleEncoder cSelf, WGPUBuffer buffer, WGPUIndexFormat format, uint64_t offset, uint64_t size) {
        return NativeRenderBundleEncoderSetIndexBuffer(
            cSelf, buffer, format, offset, size);
    }
    void wgpuRenderBundleEncoderSetLabel(WGPURenderBundleEncoder cSelf, char const * label) {
        return NativeRenderBundleEncoderSetLabel(
            cSelf, label);
    }
    void wgpuRenderBundleEncoderSetPipeline(WGPURenderBundleEncoder cSelf, WGPURenderPipeline pipeline) {
        return NativeRenderBundleEncoderSetPipeline(
            cSelf, pipeline);
    }
    void wgpuRenderBundleEncoderSetVertexBuffer(WGPURenderBundleEncoder cSelf, uint32_t slot, WGPUBuffer buffer, uint64_t offset, uint64_t size) {
        return NativeRenderBundleEncoderSetVertexBuffer(
            cSelf, slot, buffer, offset, size);
    }
    void wgpuRenderBundleEncoderAddRef(WGPURenderBundleEncoder cSelf) {
        return NativeRenderBundleEncoderAddRef(
            cSelf);
    }
    void wgpuRenderBundleEncoderRelease(WGPURenderBundleEncoder cSelf) {
        return NativeRenderBundleEncoderRelease(
            cSelf);
    }
    void wgpuRenderPassEncoderBeginOcclusionQuery(WGPURenderPassEncoder cSelf, uint32_t queryIndex) {
        return NativeRenderPassEncoderBeginOcclusionQuery(
            cSelf, queryIndex);
    }
    void wgpuRenderPassEncoderDraw(WGPURenderPassEncoder cSelf, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) {
        return NativeRenderPassEncoderDraw(
            cSelf, vertexCount, instanceCount, firstVertex, firstInstance);
    }
    void wgpuRenderPassEncoderDrawIndexed(WGPURenderPassEncoder cSelf, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance) {
        return NativeRenderPassEncoderDrawIndexed(
            cSelf, indexCount, instanceCount, firstIndex, baseVertex, firstInstance);
    }
    void wgpuRenderPassEncoderDrawIndexedIndirect(WGPURenderPassEncoder cSelf, WGPUBuffer indirectBuffer, uint64_t indirectOffset) {
        return NativeRenderPassEncoderDrawIndexedIndirect(
            cSelf, indirectBuffer, indirectOffset);
    }
    void wgpuRenderPassEncoderDrawIndirect(WGPURenderPassEncoder cSelf, WGPUBuffer indirectBuffer, uint64_t indirectOffset) {
        return NativeRenderPassEncoderDrawIndirect(
            cSelf, indirectBuffer, indirectOffset);
    }
    void wgpuRenderPassEncoderEnd(WGPURenderPassEncoder cSelf) {
        return NativeRenderPassEncoderEnd(
            cSelf);
    }
    void wgpuRenderPassEncoderEndOcclusionQuery(WGPURenderPassEncoder cSelf) {
        return NativeRenderPassEncoderEndOcclusionQuery(
            cSelf);
    }
    void wgpuRenderPassEncoderExecuteBundles(WGPURenderPassEncoder cSelf, size_t bundleCount, WGPURenderBundle const * bundles) {
        return NativeRenderPassEncoderExecuteBundles(
            cSelf, bundleCount, bundles);
    }
    void wgpuRenderPassEncoderInsertDebugMarker(WGPURenderPassEncoder cSelf, char const * markerLabel) {
        return NativeRenderPassEncoderInsertDebugMarker(
            cSelf, markerLabel);
    }
    void wgpuRenderPassEncoderPixelLocalStorageBarrier(WGPURenderPassEncoder cSelf) {
        return NativeRenderPassEncoderPixelLocalStorageBarrier(
            cSelf);
    }
    void wgpuRenderPassEncoderPopDebugGroup(WGPURenderPassEncoder cSelf) {
        return NativeRenderPassEncoderPopDebugGroup(
            cSelf);
    }
    void wgpuRenderPassEncoderPushDebugGroup(WGPURenderPassEncoder cSelf, char const * groupLabel) {
        return NativeRenderPassEncoderPushDebugGroup(
            cSelf, groupLabel);
    }
    void wgpuRenderPassEncoderSetBindGroup(WGPURenderPassEncoder cSelf, uint32_t groupIndex, WGPUBindGroup group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) {
        return NativeRenderPassEncoderSetBindGroup(
            cSelf, groupIndex, group, dynamicOffsetCount, dynamicOffsets);
    }
    void wgpuRenderPassEncoderSetBlendConstant(WGPURenderPassEncoder cSelf, WGPUColor const * color) {
        return NativeRenderPassEncoderSetBlendConstant(
            cSelf, color);
    }
    void wgpuRenderPassEncoderSetIndexBuffer(WGPURenderPassEncoder cSelf, WGPUBuffer buffer, WGPUIndexFormat format, uint64_t offset, uint64_t size) {
        return NativeRenderPassEncoderSetIndexBuffer(
            cSelf, buffer, format, offset, size);
    }
    void wgpuRenderPassEncoderSetLabel(WGPURenderPassEncoder cSelf, char const * label) {
        return NativeRenderPassEncoderSetLabel(
            cSelf, label);
    }
    void wgpuRenderPassEncoderSetPipeline(WGPURenderPassEncoder cSelf, WGPURenderPipeline pipeline) {
        return NativeRenderPassEncoderSetPipeline(
            cSelf, pipeline);
    }
    void wgpuRenderPassEncoderSetScissorRect(WGPURenderPassEncoder cSelf, uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
        return NativeRenderPassEncoderSetScissorRect(
            cSelf, x, y, width, height);
    }
    void wgpuRenderPassEncoderSetStencilReference(WGPURenderPassEncoder cSelf, uint32_t reference) {
        return NativeRenderPassEncoderSetStencilReference(
            cSelf, reference);
    }
    void wgpuRenderPassEncoderSetVertexBuffer(WGPURenderPassEncoder cSelf, uint32_t slot, WGPUBuffer buffer, uint64_t offset, uint64_t size) {
        return NativeRenderPassEncoderSetVertexBuffer(
            cSelf, slot, buffer, offset, size);
    }
    void wgpuRenderPassEncoderSetViewport(WGPURenderPassEncoder cSelf, float x, float y, float width, float height, float minDepth, float maxDepth) {
        return NativeRenderPassEncoderSetViewport(
            cSelf, x, y, width, height, minDepth, maxDepth);
    }
    void wgpuRenderPassEncoderWriteTimestamp(WGPURenderPassEncoder cSelf, WGPUQuerySet querySet, uint32_t queryIndex) {
        return NativeRenderPassEncoderWriteTimestamp(
            cSelf, querySet, queryIndex);
    }
    void wgpuRenderPassEncoderAddRef(WGPURenderPassEncoder cSelf) {
        return NativeRenderPassEncoderAddRef(
            cSelf);
    }
    void wgpuRenderPassEncoderRelease(WGPURenderPassEncoder cSelf) {
        return NativeRenderPassEncoderRelease(
            cSelf);
    }
    WGPUBindGroupLayout wgpuRenderPipelineGetBindGroupLayout(WGPURenderPipeline cSelf, uint32_t groupIndex) {
        return NativeRenderPipelineGetBindGroupLayout(
            cSelf, groupIndex);
    }
    void wgpuRenderPipelineSetLabel(WGPURenderPipeline cSelf, char const * label) {
        return NativeRenderPipelineSetLabel(
            cSelf, label);
    }
    void wgpuRenderPipelineAddRef(WGPURenderPipeline cSelf) {
        return NativeRenderPipelineAddRef(
            cSelf);
    }
    void wgpuRenderPipelineRelease(WGPURenderPipeline cSelf) {
        return NativeRenderPipelineRelease(
            cSelf);
    }
    void wgpuSamplerSetLabel(WGPUSampler cSelf, char const * label) {
        return NativeSamplerSetLabel(
            cSelf, label);
    }
    void wgpuSamplerAddRef(WGPUSampler cSelf) {
        return NativeSamplerAddRef(
            cSelf);
    }
    void wgpuSamplerRelease(WGPUSampler cSelf) {
        return NativeSamplerRelease(
            cSelf);
    }
    void wgpuShaderModuleGetCompilationInfo(WGPUShaderModule cSelf, WGPUCompilationInfoCallback callback, void * userdata) {
        return NativeShaderModuleGetCompilationInfo(
            cSelf, callback, userdata);
    }
    WGPUFuture wgpuShaderModuleGetCompilationInfoF(WGPUShaderModule cSelf, WGPUCompilationInfoCallbackInfo callbackInfo) {
        return NativeShaderModuleGetCompilationInfoF(
            cSelf, callbackInfo);
    }
    void wgpuShaderModuleSetLabel(WGPUShaderModule cSelf, char const * label) {
        return NativeShaderModuleSetLabel(
            cSelf, label);
    }
    void wgpuShaderModuleAddRef(WGPUShaderModule cSelf) {
        return NativeShaderModuleAddRef(
            cSelf);
    }
    void wgpuShaderModuleRelease(WGPUShaderModule cSelf) {
        return NativeShaderModuleRelease(
            cSelf);
    }
    WGPUBool wgpuSharedBufferMemoryBeginAccess(WGPUSharedBufferMemory cSelf, WGPUBuffer buffer, WGPUSharedBufferMemoryBeginAccessDescriptor const * descriptor) {
        return NativeSharedBufferMemoryBeginAccess(
            cSelf, buffer, descriptor);
    }
    WGPUBuffer wgpuSharedBufferMemoryCreateBuffer(WGPUSharedBufferMemory cSelf, WGPUBufferDescriptor const * descriptor) {
        return NativeSharedBufferMemoryCreateBuffer(
            cSelf, descriptor);
    }
    WGPUBool wgpuSharedBufferMemoryEndAccess(WGPUSharedBufferMemory cSelf, WGPUBuffer buffer, WGPUSharedBufferMemoryEndAccessState * descriptor) {
        return NativeSharedBufferMemoryEndAccess(
            cSelf, buffer, descriptor);
    }
    WGPUStatus wgpuSharedBufferMemoryGetProperties(WGPUSharedBufferMemory cSelf, WGPUSharedBufferMemoryProperties * properties) {
        return NativeSharedBufferMemoryGetProperties(
            cSelf, properties);
    }
    WGPUBool wgpuSharedBufferMemoryIsDeviceLost(WGPUSharedBufferMemory cSelf) {
        return NativeSharedBufferMemoryIsDeviceLost(
            cSelf);
    }
    void wgpuSharedBufferMemorySetLabel(WGPUSharedBufferMemory cSelf, char const * label) {
        return NativeSharedBufferMemorySetLabel(
            cSelf, label);
    }
    void wgpuSharedBufferMemoryAddRef(WGPUSharedBufferMemory cSelf) {
        return NativeSharedBufferMemoryAddRef(
            cSelf);
    }
    void wgpuSharedBufferMemoryRelease(WGPUSharedBufferMemory cSelf) {
        return NativeSharedBufferMemoryRelease(
            cSelf);
    }
    void wgpuSharedFenceExportInfo(WGPUSharedFence cSelf, WGPUSharedFenceExportInfo * info) {
        return NativeSharedFenceExportInfo(
            cSelf, info);
    }
    void wgpuSharedFenceAddRef(WGPUSharedFence cSelf) {
        return NativeSharedFenceAddRef(
            cSelf);
    }
    void wgpuSharedFenceRelease(WGPUSharedFence cSelf) {
        return NativeSharedFenceRelease(
            cSelf);
    }
    WGPUBool wgpuSharedTextureMemoryBeginAccess(WGPUSharedTextureMemory cSelf, WGPUTexture texture, WGPUSharedTextureMemoryBeginAccessDescriptor const * descriptor) {
        return NativeSharedTextureMemoryBeginAccess(
            cSelf, texture, descriptor);
    }
    WGPUTexture wgpuSharedTextureMemoryCreateTexture(WGPUSharedTextureMemory cSelf, WGPUTextureDescriptor const * descriptor) {
        return NativeSharedTextureMemoryCreateTexture(
            cSelf, descriptor);
    }
    WGPUBool wgpuSharedTextureMemoryEndAccess(WGPUSharedTextureMemory cSelf, WGPUTexture texture, WGPUSharedTextureMemoryEndAccessState * descriptor) {
        return NativeSharedTextureMemoryEndAccess(
            cSelf, texture, descriptor);
    }
    WGPUStatus wgpuSharedTextureMemoryGetProperties(WGPUSharedTextureMemory cSelf, WGPUSharedTextureMemoryProperties * properties) {
        return NativeSharedTextureMemoryGetProperties(
            cSelf, properties);
    }
    WGPUBool wgpuSharedTextureMemoryIsDeviceLost(WGPUSharedTextureMemory cSelf) {
        return NativeSharedTextureMemoryIsDeviceLost(
            cSelf);
    }
    void wgpuSharedTextureMemorySetLabel(WGPUSharedTextureMemory cSelf, char const * label) {
        return NativeSharedTextureMemorySetLabel(
            cSelf, label);
    }
    void wgpuSharedTextureMemoryAddRef(WGPUSharedTextureMemory cSelf) {
        return NativeSharedTextureMemoryAddRef(
            cSelf);
    }
    void wgpuSharedTextureMemoryRelease(WGPUSharedTextureMemory cSelf) {
        return NativeSharedTextureMemoryRelease(
            cSelf);
    }
    void wgpuSurfaceConfigure(WGPUSurface cSelf, WGPUSurfaceConfiguration const * config) {
        return NativeSurfaceConfigure(
            cSelf, config);
    }
    WGPUStatus wgpuSurfaceGetCapabilities(WGPUSurface cSelf, WGPUAdapter adapter, WGPUSurfaceCapabilities * capabilities) {
        return NativeSurfaceGetCapabilities(
            cSelf, adapter, capabilities);
    }
    void wgpuSurfaceGetCurrentTexture(WGPUSurface cSelf, WGPUSurfaceTexture * surfaceTexture) {
        return NativeSurfaceGetCurrentTexture(
            cSelf, surfaceTexture);
    }
    WGPUTextureFormat wgpuSurfaceGetPreferredFormat(WGPUSurface cSelf, WGPUAdapter adapter) {
        return NativeSurfaceGetPreferredFormat(
            cSelf, adapter);
    }
    void wgpuSurfacePresent(WGPUSurface cSelf) {
        return NativeSurfacePresent(
            cSelf);
    }
    void wgpuSurfaceUnconfigure(WGPUSurface cSelf) {
        return NativeSurfaceUnconfigure(
            cSelf);
    }
    void wgpuSurfaceAddRef(WGPUSurface cSelf) {
        return NativeSurfaceAddRef(
            cSelf);
    }
    void wgpuSurfaceRelease(WGPUSurface cSelf) {
        return NativeSurfaceRelease(
            cSelf);
    }
    WGPUTexture wgpuSwapChainGetCurrentTexture(WGPUSwapChain cSelf) {
        return NativeSwapChainGetCurrentTexture(
            cSelf);
    }
    WGPUTextureView wgpuSwapChainGetCurrentTextureView(WGPUSwapChain cSelf) {
        return NativeSwapChainGetCurrentTextureView(
            cSelf);
    }
    void wgpuSwapChainPresent(WGPUSwapChain cSelf) {
        return NativeSwapChainPresent(
            cSelf);
    }
    void wgpuSwapChainAddRef(WGPUSwapChain cSelf) {
        return NativeSwapChainAddRef(
            cSelf);
    }
    void wgpuSwapChainRelease(WGPUSwapChain cSelf) {
        return NativeSwapChainRelease(
            cSelf);
    }
    WGPUTextureView wgpuTextureCreateErrorView(WGPUTexture cSelf, WGPUTextureViewDescriptor const * descriptor) {
        return NativeTextureCreateErrorView(
            cSelf, descriptor);
    }
    WGPUTextureView wgpuTextureCreateView(WGPUTexture cSelf, WGPUTextureViewDescriptor const * descriptor) {
        return NativeTextureCreateView(
            cSelf, descriptor);
    }
    void wgpuTextureDestroy(WGPUTexture cSelf) {
        return NativeTextureDestroy(
            cSelf);
    }
    uint32_t wgpuTextureGetDepthOrArrayLayers(WGPUTexture cSelf) {
        return NativeTextureGetDepthOrArrayLayers(
            cSelf);
    }
    WGPUTextureDimension wgpuTextureGetDimension(WGPUTexture cSelf) {
        return NativeTextureGetDimension(
            cSelf);
    }
    WGPUTextureFormat wgpuTextureGetFormat(WGPUTexture cSelf) {
        return NativeTextureGetFormat(
            cSelf);
    }
    uint32_t wgpuTextureGetHeight(WGPUTexture cSelf) {
        return NativeTextureGetHeight(
            cSelf);
    }
    uint32_t wgpuTextureGetMipLevelCount(WGPUTexture cSelf) {
        return NativeTextureGetMipLevelCount(
            cSelf);
    }
    uint32_t wgpuTextureGetSampleCount(WGPUTexture cSelf) {
        return NativeTextureGetSampleCount(
            cSelf);
    }
    WGPUTextureUsageFlags wgpuTextureGetUsage(WGPUTexture cSelf) {
        return NativeTextureGetUsage(
            cSelf);
    }
    uint32_t wgpuTextureGetWidth(WGPUTexture cSelf) {
        return NativeTextureGetWidth(
            cSelf);
    }
    void wgpuTextureSetLabel(WGPUTexture cSelf, char const * label) {
        return NativeTextureSetLabel(
            cSelf, label);
    }
    void wgpuTextureAddRef(WGPUTexture cSelf) {
        return NativeTextureAddRef(
            cSelf);
    }
    void wgpuTextureRelease(WGPUTexture cSelf) {
        return NativeTextureRelease(
            cSelf);
    }
    void wgpuTextureViewSetLabel(WGPUTextureView cSelf, char const * label) {
        return NativeTextureViewSetLabel(
            cSelf, label);
    }
    void wgpuTextureViewAddRef(WGPUTextureView cSelf) {
        return NativeTextureViewAddRef(
            cSelf);
    }
    void wgpuTextureViewRelease(WGPUTextureView cSelf) {
        return NativeTextureViewRelease(
            cSelf);
    }
}
