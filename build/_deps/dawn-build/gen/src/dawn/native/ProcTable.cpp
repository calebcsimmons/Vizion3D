
#include "dawn/native/dawn_platform.h"
#include "dawn/native/DawnNative.h"

#include <algorithm>
#include <vector>

#include "dawn/native/Adapter.h"
#include "dawn/native/BindGroup.h"
#include "dawn/native/BindGroupLayout.h"
#include "dawn/native/Buffer.h"
#include "dawn/native/CommandBuffer.h"
#include "dawn/native/CommandEncoder.h"
#include "dawn/native/ComputePassEncoder.h"
#include "dawn/native/ComputePipeline.h"
#include "dawn/native/Device.h"
#include "dawn/native/ExternalTexture.h"
#include "dawn/native/Instance.h"
#include "dawn/native/PipelineLayout.h"
#include "dawn/native/QuerySet.h"
#include "dawn/native/Queue.h"
#include "dawn/native/RenderBundle.h"
#include "dawn/native/RenderBundleEncoder.h"
#include "dawn/native/RenderPassEncoder.h"
#include "dawn/native/RenderPipeline.h"
#include "dawn/native/Sampler.h"
#include "dawn/native/ShaderModule.h"
#include "dawn/native/SharedBufferMemory.h"
#include "dawn/native/SharedFence.h"
#include "dawn/native/SharedTextureMemory.h"
#include "dawn/native/Surface.h"
#include "dawn/native/SwapChain.h"
#include "dawn/native/Texture.h"

namespace dawn::native {


    WGPUDevice NativeAdapterCreateDevice(WGPUAdapter cSelf, WGPUDeviceDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<DeviceDescriptor const * >(descriptor);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APICreateDevice(descriptor_);
        return ToAPI(result);
    }

    size_t NativeAdapterEnumerateFeatures(WGPUAdapter cSelf, WGPUFeatureName * features) {
        auto self = FromAPI(cSelf);

        auto features_ = reinterpret_cast<wgpu::FeatureName * >(features);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIEnumerateFeatures(features_);
        return result;
    }

    WGPUStatus NativeAdapterGetFormatCapabilities(WGPUAdapter cSelf, WGPUTextureFormat format, WGPUFormatCapabilities * capabilities) {
        auto self = FromAPI(cSelf);

        auto format_ = static_cast<wgpu::TextureFormat>(format);
        auto capabilities_ = reinterpret_cast<FormatCapabilities * >(capabilities);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIGetFormatCapabilities(format_, capabilities_);
        return ToAPI(result);
    }

    WGPUStatus NativeAdapterGetInfo(WGPUAdapter cSelf, WGPUAdapterInfo * info) {
        auto self = FromAPI(cSelf);

        auto info_ = reinterpret_cast<AdapterInfo * >(info);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIGetInfo(info_);
        return ToAPI(result);
    }

    WGPUInstance NativeAdapterGetInstance(WGPUAdapter cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIGetInstance();
        return ToAPI(result);
    }

    WGPUStatus NativeAdapterGetLimits(WGPUAdapter cSelf, WGPUSupportedLimits * limits) {
        auto self = FromAPI(cSelf);

        auto limits_ = reinterpret_cast<SupportedLimits * >(limits);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIGetLimits(limits_);
        return ToAPI(result);
    }

    WGPUStatus NativeAdapterGetProperties(WGPUAdapter cSelf, WGPUAdapterProperties * properties) {
        auto self = FromAPI(cSelf);

        auto properties_ = reinterpret_cast<AdapterProperties * >(properties);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIGetProperties(properties_);
        return ToAPI(result);
    }

    WGPUBool NativeAdapterHasFeature(WGPUAdapter cSelf, WGPUFeatureName feature) {
        auto self = FromAPI(cSelf);

        auto feature_ = static_cast<wgpu::FeatureName>(feature);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIHasFeature(feature_);
        return result;
    }

    void NativeAdapterRequestDevice(WGPUAdapter cSelf, WGPUDeviceDescriptor const * descriptor, WGPURequestDeviceCallback callback, void * userdata) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<DeviceDescriptor const * >(descriptor);
        auto callback_ = callback;
        auto userdata_ = userdata;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRequestDevice(descriptor_, callback_, userdata_);
    }

    WGPUFuture NativeAdapterRequestDevice2(WGPUAdapter cSelf, WGPUDeviceDescriptor const * options, WGPURequestDeviceCallbackInfo2 callbackInfo) {
        auto self = FromAPI(cSelf);

        auto options_ = reinterpret_cast<DeviceDescriptor const * >(options);
        auto callbackInfo_ = callbackInfo;
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIRequestDevice2(options_, callbackInfo_);
        return *ToAPI(&result);
    }

    WGPUFuture NativeAdapterRequestDeviceF(WGPUAdapter cSelf, WGPUDeviceDescriptor const * options, WGPURequestDeviceCallbackInfo callbackInfo) {
        auto self = FromAPI(cSelf);

        auto options_ = reinterpret_cast<DeviceDescriptor const * >(options);
        auto callbackInfo_ = *reinterpret_cast<RequestDeviceCallbackInfo*>(&callbackInfo);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIRequestDeviceF(options_, callbackInfo_);
        return *ToAPI(&result);
    }

    void NativeAdapterAddRef(WGPUAdapter cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeAdapterRelease(WGPUAdapter cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeBindGroupSetLabel(WGPUBindGroup cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeBindGroupAddRef(WGPUBindGroup cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeBindGroupRelease(WGPUBindGroup cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeBindGroupLayoutSetLabel(WGPUBindGroupLayout cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeBindGroupLayoutAddRef(WGPUBindGroupLayout cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeBindGroupLayoutRelease(WGPUBindGroupLayout cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeBufferDestroy(WGPUBuffer cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APIDestroy();
    }

    void const * NativeBufferGetConstMappedRange(WGPUBuffer cSelf, size_t offset, size_t size) {
        auto self = FromAPI(cSelf);

        auto offset_ = offset;
        auto size_ = size;
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetConstMappedRange(offset_, size_);
        return result;
    }

    WGPUBufferMapState NativeBufferGetMapState(WGPUBuffer cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetMapState();
        return ToAPI(result);
    }

    void * NativeBufferGetMappedRange(WGPUBuffer cSelf, size_t offset, size_t size) {
        auto self = FromAPI(cSelf);

        auto offset_ = offset;
        auto size_ = size;
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetMappedRange(offset_, size_);
        return result;
    }

    uint64_t NativeBufferGetSize(WGPUBuffer cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIGetSize();
        return result;
    }

    WGPUBufferUsageFlags NativeBufferGetUsage(WGPUBuffer cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIGetUsage();
        return ToAPI(result);
    }

    void NativeBufferMapAsync(WGPUBuffer cSelf, WGPUMapModeFlags mode, size_t offset, size_t size, WGPUBufferMapCallback callback, void * userdata) {
        auto self = FromAPI(cSelf);

        auto mode_ = static_cast<wgpu::MapMode>(mode);
        auto offset_ = offset;
        auto size_ = size;
        auto callback_ = callback;
        auto userdata_ = userdata;
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APIMapAsync(mode_, offset_, size_, callback_, userdata_);
    }

    WGPUFuture NativeBufferMapAsyncF(WGPUBuffer cSelf, WGPUMapModeFlags mode, size_t offset, size_t size, WGPUBufferMapCallbackInfo callbackInfo) {
        auto self = FromAPI(cSelf);

        auto mode_ = static_cast<wgpu::MapMode>(mode);
        auto offset_ = offset;
        auto size_ = size;
        auto callbackInfo_ = *reinterpret_cast<BufferMapCallbackInfo*>(&callbackInfo);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIMapAsyncF(mode_, offset_, size_, callbackInfo_);
        return *ToAPI(&result);
    }

    void NativeBufferSetLabel(WGPUBuffer cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeBufferUnmap(WGPUBuffer cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APIUnmap();
    }

    void NativeBufferAddRef(WGPUBuffer cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeBufferRelease(WGPUBuffer cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeCommandBufferSetLabel(WGPUCommandBuffer cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeCommandBufferAddRef(WGPUCommandBuffer cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeCommandBufferRelease(WGPUCommandBuffer cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    WGPUComputePassEncoder NativeCommandEncoderBeginComputePass(WGPUCommandEncoder cSelf, WGPUComputePassDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<ComputePassDescriptor const * >(descriptor);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIBeginComputePass(descriptor_);
        return ToAPI(result);
    }

    WGPURenderPassEncoder NativeCommandEncoderBeginRenderPass(WGPUCommandEncoder cSelf, WGPURenderPassDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<RenderPassDescriptor const * >(descriptor);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIBeginRenderPass(descriptor_);
        return ToAPI(result);
    }

    void NativeCommandEncoderClearBuffer(WGPUCommandEncoder cSelf, WGPUBuffer buffer, uint64_t offset, uint64_t size) {
        auto self = FromAPI(cSelf);

        auto buffer_ = reinterpret_cast<BufferBase* >(buffer);
        auto offset_ = offset;
        auto size_ = size;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIClearBuffer(buffer_, offset_, size_);
    }

    void NativeCommandEncoderCopyBufferToBuffer(WGPUCommandEncoder cSelf, WGPUBuffer source, uint64_t sourceOffset, WGPUBuffer destination, uint64_t destinationOffset, uint64_t size) {
        auto self = FromAPI(cSelf);

        auto source_ = reinterpret_cast<BufferBase* >(source);
        auto sourceOffset_ = sourceOffset;
        auto destination_ = reinterpret_cast<BufferBase* >(destination);
        auto destinationOffset_ = destinationOffset;
        auto size_ = size;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APICopyBufferToBuffer(source_, sourceOffset_, destination_, destinationOffset_, size_);
    }

    void NativeCommandEncoderCopyBufferToTexture(WGPUCommandEncoder cSelf, WGPUImageCopyBuffer const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize) {
        auto self = FromAPI(cSelf);

        auto source_ = reinterpret_cast<ImageCopyBuffer const * >(source);
        auto destination_ = reinterpret_cast<ImageCopyTexture const * >(destination);
        auto copySize_ = reinterpret_cast<Extent3D const * >(copySize);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APICopyBufferToTexture(source_, destination_, copySize_);
    }

    void NativeCommandEncoderCopyTextureToBuffer(WGPUCommandEncoder cSelf, WGPUImageCopyTexture const * source, WGPUImageCopyBuffer const * destination, WGPUExtent3D const * copySize) {
        auto self = FromAPI(cSelf);

        auto source_ = reinterpret_cast<ImageCopyTexture const * >(source);
        auto destination_ = reinterpret_cast<ImageCopyBuffer const * >(destination);
        auto copySize_ = reinterpret_cast<Extent3D const * >(copySize);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APICopyTextureToBuffer(source_, destination_, copySize_);
    }

    void NativeCommandEncoderCopyTextureToTexture(WGPUCommandEncoder cSelf, WGPUImageCopyTexture const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize) {
        auto self = FromAPI(cSelf);

        auto source_ = reinterpret_cast<ImageCopyTexture const * >(source);
        auto destination_ = reinterpret_cast<ImageCopyTexture const * >(destination);
        auto copySize_ = reinterpret_cast<Extent3D const * >(copySize);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APICopyTextureToTexture(source_, destination_, copySize_);
    }

    WGPUCommandBuffer NativeCommandEncoderFinish(WGPUCommandEncoder cSelf, WGPUCommandBufferDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<CommandBufferDescriptor const * >(descriptor);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIFinish(descriptor_);
        return ToAPI(result);
    }

    void NativeCommandEncoderInjectValidationError(WGPUCommandEncoder cSelf, char const * message) {
        auto self = FromAPI(cSelf);

        auto message_ = reinterpret_cast<char const * >(message);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIInjectValidationError(message_);
    }

    void NativeCommandEncoderInsertDebugMarker(WGPUCommandEncoder cSelf, char const * markerLabel) {
        auto self = FromAPI(cSelf);

        auto markerLabel_ = reinterpret_cast<char const * >(markerLabel);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIInsertDebugMarker(markerLabel_);
    }

    void NativeCommandEncoderPopDebugGroup(WGPUCommandEncoder cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIPopDebugGroup();
    }

    void NativeCommandEncoderPushDebugGroup(WGPUCommandEncoder cSelf, char const * groupLabel) {
        auto self = FromAPI(cSelf);

        auto groupLabel_ = reinterpret_cast<char const * >(groupLabel);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIPushDebugGroup(groupLabel_);
    }

    void NativeCommandEncoderResolveQuerySet(WGPUCommandEncoder cSelf, WGPUQuerySet querySet, uint32_t firstQuery, uint32_t queryCount, WGPUBuffer destination, uint64_t destinationOffset) {
        auto self = FromAPI(cSelf);

        auto querySet_ = reinterpret_cast<QuerySetBase* >(querySet);
        auto firstQuery_ = firstQuery;
        auto queryCount_ = queryCount;
        auto destination_ = reinterpret_cast<BufferBase* >(destination);
        auto destinationOffset_ = destinationOffset;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIResolveQuerySet(querySet_, firstQuery_, queryCount_, destination_, destinationOffset_);
    }

    void NativeCommandEncoderSetLabel(WGPUCommandEncoder cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetLabel(label_);
    }

    void NativeCommandEncoderWriteBuffer(WGPUCommandEncoder cSelf, WGPUBuffer buffer, uint64_t bufferOffset, uint8_t const * data, uint64_t size) {
        auto self = FromAPI(cSelf);

        auto buffer_ = reinterpret_cast<BufferBase* >(buffer);
        auto bufferOffset_ = bufferOffset;
        auto data_ = reinterpret_cast<uint8_t const * >(data);
        auto size_ = size;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIWriteBuffer(buffer_, bufferOffset_, data_, size_);
    }

    void NativeCommandEncoderWriteTimestamp(WGPUCommandEncoder cSelf, WGPUQuerySet querySet, uint32_t queryIndex) {
        auto self = FromAPI(cSelf);

        auto querySet_ = reinterpret_cast<QuerySetBase* >(querySet);
        auto queryIndex_ = queryIndex;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIWriteTimestamp(querySet_, queryIndex_);
    }

    void NativeCommandEncoderAddRef(WGPUCommandEncoder cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeCommandEncoderRelease(WGPUCommandEncoder cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeComputePassEncoderDispatchWorkgroups(WGPUComputePassEncoder cSelf, uint32_t workgroupCountX, uint32_t workgroupCountY, uint32_t workgroupCountZ) {
        auto self = FromAPI(cSelf);

        auto workgroupCountX_ = workgroupCountX;
        auto workgroupCountY_ = workgroupCountY;
        auto workgroupCountZ_ = workgroupCountZ;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIDispatchWorkgroups(workgroupCountX_, workgroupCountY_, workgroupCountZ_);
    }

    void NativeComputePassEncoderDispatchWorkgroupsIndirect(WGPUComputePassEncoder cSelf, WGPUBuffer indirectBuffer, uint64_t indirectOffset) {
        auto self = FromAPI(cSelf);

        auto indirectBuffer_ = reinterpret_cast<BufferBase* >(indirectBuffer);
        auto indirectOffset_ = indirectOffset;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIDispatchWorkgroupsIndirect(indirectBuffer_, indirectOffset_);
    }

    void NativeComputePassEncoderEnd(WGPUComputePassEncoder cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIEnd();
    }

    void NativeComputePassEncoderInsertDebugMarker(WGPUComputePassEncoder cSelf, char const * markerLabel) {
        auto self = FromAPI(cSelf);

        auto markerLabel_ = reinterpret_cast<char const * >(markerLabel);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIInsertDebugMarker(markerLabel_);
    }

    void NativeComputePassEncoderPopDebugGroup(WGPUComputePassEncoder cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIPopDebugGroup();
    }

    void NativeComputePassEncoderPushDebugGroup(WGPUComputePassEncoder cSelf, char const * groupLabel) {
        auto self = FromAPI(cSelf);

        auto groupLabel_ = reinterpret_cast<char const * >(groupLabel);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIPushDebugGroup(groupLabel_);
    }

    void NativeComputePassEncoderSetBindGroup(WGPUComputePassEncoder cSelf, uint32_t groupIndex, WGPUBindGroup group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) {
        auto self = FromAPI(cSelf);

        auto groupIndex_ = groupIndex;
        auto group_ = reinterpret_cast<BindGroupBase* >(group);
        auto dynamicOffsetCount_ = dynamicOffsetCount;
        auto dynamicOffsets_ = reinterpret_cast<uint32_t const * >(dynamicOffsets);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetBindGroup(groupIndex_, group_, dynamicOffsetCount_, dynamicOffsets_);
    }

    void NativeComputePassEncoderSetLabel(WGPUComputePassEncoder cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetLabel(label_);
    }

    void NativeComputePassEncoderSetPipeline(WGPUComputePassEncoder cSelf, WGPUComputePipeline pipeline) {
        auto self = FromAPI(cSelf);

        auto pipeline_ = reinterpret_cast<ComputePipelineBase* >(pipeline);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetPipeline(pipeline_);
    }

    void NativeComputePassEncoderWriteTimestamp(WGPUComputePassEncoder cSelf, WGPUQuerySet querySet, uint32_t queryIndex) {
        auto self = FromAPI(cSelf);

        auto querySet_ = reinterpret_cast<QuerySetBase* >(querySet);
        auto queryIndex_ = queryIndex;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIWriteTimestamp(querySet_, queryIndex_);
    }

    void NativeComputePassEncoderAddRef(WGPUComputePassEncoder cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeComputePassEncoderRelease(WGPUComputePassEncoder cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    WGPUBindGroupLayout NativeComputePipelineGetBindGroupLayout(WGPUComputePipeline cSelf, uint32_t groupIndex) {
        auto self = FromAPI(cSelf);

        auto groupIndex_ = groupIndex;
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetBindGroupLayout(groupIndex_);
        return ToAPI(result);
    }

    void NativeComputePipelineSetLabel(WGPUComputePipeline cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeComputePipelineAddRef(WGPUComputePipeline cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeComputePipelineRelease(WGPUComputePipeline cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    WGPUBindGroup NativeDeviceCreateBindGroup(WGPUDevice cSelf, WGPUBindGroupDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<BindGroupDescriptor const * >(descriptor);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateBindGroup(descriptor_);
        return ToAPI(result);
    }

    WGPUBindGroupLayout NativeDeviceCreateBindGroupLayout(WGPUDevice cSelf, WGPUBindGroupLayoutDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<BindGroupLayoutDescriptor const * >(descriptor);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateBindGroupLayout(descriptor_);
        return ToAPI(result);
    }

    WGPUBuffer NativeDeviceCreateBuffer(WGPUDevice cSelf, WGPUBufferDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<BufferDescriptor const * >(descriptor);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APICreateBuffer(descriptor_);
        return ToAPI(result);
    }

    WGPUCommandEncoder NativeDeviceCreateCommandEncoder(WGPUDevice cSelf, WGPUCommandEncoderDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<CommandEncoderDescriptor const * >(descriptor);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateCommandEncoder(descriptor_);
        return ToAPI(result);
    }

    WGPUComputePipeline NativeDeviceCreateComputePipeline(WGPUDevice cSelf, WGPUComputePipelineDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<ComputePipelineDescriptor const * >(descriptor);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APICreateComputePipeline(descriptor_);
        return ToAPI(result);
    }

    void NativeDeviceCreateComputePipelineAsync(WGPUDevice cSelf, WGPUComputePipelineDescriptor const * descriptor, WGPUCreateComputePipelineAsyncCallback callback, void * userdata) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<ComputePipelineDescriptor const * >(descriptor);
        auto callback_ = callback;
        auto userdata_ = userdata;
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        self->APICreateComputePipelineAsync(descriptor_, callback_, userdata_);
    }

    WGPUFuture NativeDeviceCreateComputePipelineAsync2(WGPUDevice cSelf, WGPUComputePipelineDescriptor const * descriptor, WGPUCreateComputePipelineAsyncCallbackInfo2 callbackInfo) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<ComputePipelineDescriptor const * >(descriptor);
        auto callbackInfo_ = callbackInfo;
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APICreateComputePipelineAsync2(descriptor_, callbackInfo_);
        return *ToAPI(&result);
    }

    WGPUFuture NativeDeviceCreateComputePipelineAsyncF(WGPUDevice cSelf, WGPUComputePipelineDescriptor const * descriptor, WGPUCreateComputePipelineAsyncCallbackInfo callbackInfo) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<ComputePipelineDescriptor const * >(descriptor);
        auto callbackInfo_ = *reinterpret_cast<CreateComputePipelineAsyncCallbackInfo*>(&callbackInfo);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APICreateComputePipelineAsyncF(descriptor_, callbackInfo_);
        return *ToAPI(&result);
    }

    WGPUBuffer NativeDeviceCreateErrorBuffer(WGPUDevice cSelf, WGPUBufferDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<BufferDescriptor const * >(descriptor);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateErrorBuffer(descriptor_);
        return ToAPI(result);
    }

    WGPUExternalTexture NativeDeviceCreateErrorExternalTexture(WGPUDevice cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateErrorExternalTexture();
        return ToAPI(result);
    }

    WGPUShaderModule NativeDeviceCreateErrorShaderModule(WGPUDevice cSelf, WGPUShaderModuleDescriptor const * descriptor, char const * errorMessage) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<ShaderModuleDescriptor const * >(descriptor);
        auto errorMessage_ = reinterpret_cast<char const * >(errorMessage);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateErrorShaderModule(descriptor_, errorMessage_);
        return ToAPI(result);
    }

    WGPUTexture NativeDeviceCreateErrorTexture(WGPUDevice cSelf, WGPUTextureDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<TextureDescriptor const * >(descriptor);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateErrorTexture(descriptor_);
        return ToAPI(result);
    }

    WGPUExternalTexture NativeDeviceCreateExternalTexture(WGPUDevice cSelf, WGPUExternalTextureDescriptor const * externalTextureDescriptor) {
        auto self = FromAPI(cSelf);

        auto externalTextureDescriptor_ = reinterpret_cast<ExternalTextureDescriptor const * >(externalTextureDescriptor);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateExternalTexture(externalTextureDescriptor_);
        return ToAPI(result);
    }

    WGPUPipelineLayout NativeDeviceCreatePipelineLayout(WGPUDevice cSelf, WGPUPipelineLayoutDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<PipelineLayoutDescriptor const * >(descriptor);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreatePipelineLayout(descriptor_);
        return ToAPI(result);
    }

    WGPUQuerySet NativeDeviceCreateQuerySet(WGPUDevice cSelf, WGPUQuerySetDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<QuerySetDescriptor const * >(descriptor);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateQuerySet(descriptor_);
        return ToAPI(result);
    }

    WGPURenderBundleEncoder NativeDeviceCreateRenderBundleEncoder(WGPUDevice cSelf, WGPURenderBundleEncoderDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<RenderBundleEncoderDescriptor const * >(descriptor);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateRenderBundleEncoder(descriptor_);
        return ToAPI(result);
    }

    WGPURenderPipeline NativeDeviceCreateRenderPipeline(WGPUDevice cSelf, WGPURenderPipelineDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<RenderPipelineDescriptor const * >(descriptor);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APICreateRenderPipeline(descriptor_);
        return ToAPI(result);
    }

    void NativeDeviceCreateRenderPipelineAsync(WGPUDevice cSelf, WGPURenderPipelineDescriptor const * descriptor, WGPUCreateRenderPipelineAsyncCallback callback, void * userdata) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<RenderPipelineDescriptor const * >(descriptor);
        auto callback_ = callback;
        auto userdata_ = userdata;
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        self->APICreateRenderPipelineAsync(descriptor_, callback_, userdata_);
    }

    WGPUFuture NativeDeviceCreateRenderPipelineAsync2(WGPUDevice cSelf, WGPURenderPipelineDescriptor const * descriptor, WGPUCreateRenderPipelineAsyncCallbackInfo2 callbackInfo) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<RenderPipelineDescriptor const * >(descriptor);
        auto callbackInfo_ = callbackInfo;
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APICreateRenderPipelineAsync2(descriptor_, callbackInfo_);
        return *ToAPI(&result);
    }

    WGPUFuture NativeDeviceCreateRenderPipelineAsyncF(WGPUDevice cSelf, WGPURenderPipelineDescriptor const * descriptor, WGPUCreateRenderPipelineAsyncCallbackInfo callbackInfo) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<RenderPipelineDescriptor const * >(descriptor);
        auto callbackInfo_ = *reinterpret_cast<CreateRenderPipelineAsyncCallbackInfo*>(&callbackInfo);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APICreateRenderPipelineAsyncF(descriptor_, callbackInfo_);
        return *ToAPI(&result);
    }

    WGPUSampler NativeDeviceCreateSampler(WGPUDevice cSelf, WGPUSamplerDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<SamplerDescriptor const * >(descriptor);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateSampler(descriptor_);
        return ToAPI(result);
    }

    WGPUShaderModule NativeDeviceCreateShaderModule(WGPUDevice cSelf, WGPUShaderModuleDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<ShaderModuleDescriptor const * >(descriptor);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APICreateShaderModule(descriptor_);
        return ToAPI(result);
    }

    WGPUSwapChain NativeDeviceCreateSwapChain(WGPUDevice cSelf, WGPUSurface surface, WGPUSwapChainDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto surface_ = reinterpret_cast<SurfaceBase* >(surface);
        auto descriptor_ = reinterpret_cast<SwapChainDescriptor const * >(descriptor);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateSwapChain(surface_, descriptor_);
        return ToAPI(result);
    }

    WGPUTexture NativeDeviceCreateTexture(WGPUDevice cSelf, WGPUTextureDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<TextureDescriptor const * >(descriptor);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateTexture(descriptor_);
        return ToAPI(result);
    }

    void NativeDeviceDestroy(WGPUDevice cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self;
        auto deviceLock(device->GetScopedLock());

        self->APIDestroy();
    }

    size_t NativeDeviceEnumerateFeatures(WGPUDevice cSelf, WGPUFeatureName * features) {
        auto self = FromAPI(cSelf);

        auto features_ = reinterpret_cast<wgpu::FeatureName * >(features);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIEnumerateFeatures(features_);
        return result;
    }

    void NativeDeviceForceLoss(WGPUDevice cSelf, WGPUDeviceLostReason type, char const * message) {
        auto self = FromAPI(cSelf);

        auto type_ = static_cast<wgpu::DeviceLostReason>(type);
        auto message_ = reinterpret_cast<char const * >(message);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        self->APIForceLoss(type_, message_);
    }

    WGPUStatus NativeDeviceGetAHardwareBufferProperties(WGPUDevice cSelf, void * handle, WGPUAHardwareBufferProperties * properties) {
        auto self = FromAPI(cSelf);

        auto handle_ = handle;
        auto properties_ = reinterpret_cast<AHardwareBufferProperties * >(properties);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetAHardwareBufferProperties(handle_, properties_);
        return ToAPI(result);
    }

    WGPUAdapter NativeDeviceGetAdapter(WGPUDevice cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetAdapter();
        return ToAPI(result);
    }

    WGPUStatus NativeDeviceGetLimits(WGPUDevice cSelf, WGPUSupportedLimits * limits) {
        auto self = FromAPI(cSelf);

        auto limits_ = reinterpret_cast<SupportedLimits * >(limits);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetLimits(limits_);
        return ToAPI(result);
    }

    WGPUQueue NativeDeviceGetQueue(WGPUDevice cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetQueue();
        return ToAPI(result);
    }

    WGPUTextureUsageFlags NativeDeviceGetSupportedSurfaceUsage(WGPUDevice cSelf, WGPUSurface surface) {
        auto self = FromAPI(cSelf);

        auto surface_ = reinterpret_cast<SurfaceBase* >(surface);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetSupportedSurfaceUsage(surface_);
        return ToAPI(result);
    }

    WGPUBool NativeDeviceHasFeature(WGPUDevice cSelf, WGPUFeatureName feature) {
        auto self = FromAPI(cSelf);

        auto feature_ = static_cast<wgpu::FeatureName>(feature);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIHasFeature(feature_);
        return result;
    }

    WGPUSharedBufferMemory NativeDeviceImportSharedBufferMemory(WGPUDevice cSelf, WGPUSharedBufferMemoryDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<SharedBufferMemoryDescriptor const * >(descriptor);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIImportSharedBufferMemory(descriptor_);
        return ToAPI(result);
    }

    WGPUSharedFence NativeDeviceImportSharedFence(WGPUDevice cSelf, WGPUSharedFenceDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<SharedFenceDescriptor const * >(descriptor);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIImportSharedFence(descriptor_);
        return ToAPI(result);
    }

    WGPUSharedTextureMemory NativeDeviceImportSharedTextureMemory(WGPUDevice cSelf, WGPUSharedTextureMemoryDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<SharedTextureMemoryDescriptor const * >(descriptor);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIImportSharedTextureMemory(descriptor_);
        return ToAPI(result);
    }

    void NativeDeviceInjectError(WGPUDevice cSelf, WGPUErrorType type, char const * message) {
        auto self = FromAPI(cSelf);

        auto type_ = static_cast<wgpu::ErrorType>(type);
        auto message_ = reinterpret_cast<char const * >(message);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        self->APIInjectError(type_, message_);
    }

    void NativeDevicePopErrorScope(WGPUDevice cSelf, WGPUErrorCallback oldCallback, void * userdata) {
        auto self = FromAPI(cSelf);

        auto oldCallback_ = oldCallback;
        auto userdata_ = userdata;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIPopErrorScope(oldCallback_, userdata_);
    }

    WGPUFuture NativeDevicePopErrorScope2(WGPUDevice cSelf, WGPUPopErrorScopeCallbackInfo2 callbackInfo) {
        auto self = FromAPI(cSelf);

        auto callbackInfo_ = callbackInfo;
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIPopErrorScope2(callbackInfo_);
        return *ToAPI(&result);
    }

    WGPUFuture NativeDevicePopErrorScopeF(WGPUDevice cSelf, WGPUPopErrorScopeCallbackInfo callbackInfo) {
        auto self = FromAPI(cSelf);

        auto callbackInfo_ = *reinterpret_cast<PopErrorScopeCallbackInfo*>(&callbackInfo);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIPopErrorScopeF(callbackInfo_);
        return *ToAPI(&result);
    }

    void NativeDevicePushErrorScope(WGPUDevice cSelf, WGPUErrorFilter filter) {
        auto self = FromAPI(cSelf);

        auto filter_ = static_cast<wgpu::ErrorFilter>(filter);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        self->APIPushErrorScope(filter_);
    }

    void NativeDeviceSetDeviceLostCallback(WGPUDevice cSelf, WGPUDeviceLostCallback callback, void * userdata) {
        auto self = FromAPI(cSelf);

        auto callback_ = callback;
        auto userdata_ = userdata;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetDeviceLostCallback(callback_, userdata_);
    }

    void NativeDeviceSetLabel(WGPUDevice cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeDeviceSetLoggingCallback(WGPUDevice cSelf, WGPULoggingCallback callback, void * userdata) {
        auto self = FromAPI(cSelf);

        auto callback_ = callback;
        auto userdata_ = userdata;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetLoggingCallback(callback_, userdata_);
    }

    void NativeDeviceSetUncapturedErrorCallback(WGPUDevice cSelf, WGPUErrorCallback callback, void * userdata) {
        auto self = FromAPI(cSelf);

        auto callback_ = callback;
        auto userdata_ = userdata;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetUncapturedErrorCallback(callback_, userdata_);
    }

    void NativeDeviceTick(WGPUDevice cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APITick();
    }

    void NativeDeviceValidateTextureDescriptor(WGPUDevice cSelf, WGPUTextureDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<TextureDescriptor const * >(descriptor);
        auto device = self;
        auto deviceLock(device->GetScopedLock());

        self->APIValidateTextureDescriptor(descriptor_);
    }

    void NativeDeviceAddRef(WGPUDevice cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeDeviceRelease(WGPUDevice cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeExternalTextureDestroy(WGPUExternalTexture cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APIDestroy();
    }

    void NativeExternalTextureExpire(WGPUExternalTexture cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APIExpire();
    }

    void NativeExternalTextureRefresh(WGPUExternalTexture cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APIRefresh();
    }

    void NativeExternalTextureSetLabel(WGPUExternalTexture cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeExternalTextureAddRef(WGPUExternalTexture cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeExternalTextureRelease(WGPUExternalTexture cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    WGPUSurface NativeInstanceCreateSurface(WGPUInstance cSelf, WGPUSurfaceDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<SurfaceDescriptor const * >(descriptor);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APICreateSurface(descriptor_);
        return ToAPI(result);
    }

    size_t NativeInstanceEnumerateWGSLLanguageFeatures(WGPUInstance cSelf, WGPUWGSLFeatureName * features) {
        auto self = FromAPI(cSelf);

        auto features_ = reinterpret_cast<wgpu::WGSLFeatureName * >(features);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIEnumerateWGSLLanguageFeatures(features_);
        return result;
    }

    WGPUBool NativeInstanceHasWGSLLanguageFeature(WGPUInstance cSelf, WGPUWGSLFeatureName feature) {
        auto self = FromAPI(cSelf);

        auto feature_ = static_cast<wgpu::WGSLFeatureName>(feature);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIHasWGSLLanguageFeature(feature_);
        return result;
    }

    void NativeInstanceProcessEvents(WGPUInstance cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIProcessEvents();
    }

    void NativeInstanceRequestAdapter(WGPUInstance cSelf, WGPURequestAdapterOptions const * options, WGPURequestAdapterCallback callback, void * userdata) {
        auto self = FromAPI(cSelf);

        auto options_ = reinterpret_cast<RequestAdapterOptions const * >(options);
        auto callback_ = callback;
        auto userdata_ = userdata;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRequestAdapter(options_, callback_, userdata_);
    }

    WGPUFuture NativeInstanceRequestAdapter2(WGPUInstance cSelf, WGPURequestAdapterOptions const * options, WGPURequestAdapterCallbackInfo2 callbackInfo) {
        auto self = FromAPI(cSelf);

        auto options_ = reinterpret_cast<RequestAdapterOptions const * >(options);
        auto callbackInfo_ = callbackInfo;
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIRequestAdapter2(options_, callbackInfo_);
        return *ToAPI(&result);
    }

    WGPUFuture NativeInstanceRequestAdapterF(WGPUInstance cSelf, WGPURequestAdapterOptions const * options, WGPURequestAdapterCallbackInfo callbackInfo) {
        auto self = FromAPI(cSelf);

        auto options_ = reinterpret_cast<RequestAdapterOptions const * >(options);
        auto callbackInfo_ = *reinterpret_cast<RequestAdapterCallbackInfo*>(&callbackInfo);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIRequestAdapterF(options_, callbackInfo_);
        return *ToAPI(&result);
    }

    WGPUWaitStatus NativeInstanceWaitAny(WGPUInstance cSelf, size_t futureCount, WGPUFutureWaitInfo * futures, uint64_t timeoutNS) {
        auto self = FromAPI(cSelf);

        auto futureCount_ = futureCount;
        auto futures_ = reinterpret_cast<FutureWaitInfo * >(futures);
        auto timeoutNS_ = timeoutNS;
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIWaitAny(futureCount_, futures_, timeoutNS_);
        return ToAPI(result);
    }

    void NativeInstanceAddRef(WGPUInstance cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeInstanceRelease(WGPUInstance cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativePipelineLayoutSetLabel(WGPUPipelineLayout cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativePipelineLayoutAddRef(WGPUPipelineLayout cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativePipelineLayoutRelease(WGPUPipelineLayout cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeQuerySetDestroy(WGPUQuerySet cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APIDestroy();
    }

    uint32_t NativeQuerySetGetCount(WGPUQuerySet cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetCount();
        return result;
    }

    WGPUQueryType NativeQuerySetGetType(WGPUQuerySet cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetType();
        return ToAPI(result);
    }

    void NativeQuerySetSetLabel(WGPUQuerySet cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeQuerySetAddRef(WGPUQuerySet cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeQuerySetRelease(WGPUQuerySet cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeQueueCopyExternalTextureForBrowser(WGPUQueue cSelf, WGPUImageCopyExternalTexture const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize, WGPUCopyTextureForBrowserOptions const * options) {
        auto self = FromAPI(cSelf);

        auto source_ = reinterpret_cast<ImageCopyExternalTexture const * >(source);
        auto destination_ = reinterpret_cast<ImageCopyTexture const * >(destination);
        auto copySize_ = reinterpret_cast<Extent3D const * >(copySize);
        auto options_ = reinterpret_cast<CopyTextureForBrowserOptions const * >(options);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APICopyExternalTextureForBrowser(source_, destination_, copySize_, options_);
    }

    void NativeQueueCopyTextureForBrowser(WGPUQueue cSelf, WGPUImageCopyTexture const * source, WGPUImageCopyTexture const * destination, WGPUExtent3D const * copySize, WGPUCopyTextureForBrowserOptions const * options) {
        auto self = FromAPI(cSelf);

        auto source_ = reinterpret_cast<ImageCopyTexture const * >(source);
        auto destination_ = reinterpret_cast<ImageCopyTexture const * >(destination);
        auto copySize_ = reinterpret_cast<Extent3D const * >(copySize);
        auto options_ = reinterpret_cast<CopyTextureForBrowserOptions const * >(options);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APICopyTextureForBrowser(source_, destination_, copySize_, options_);
    }

    void NativeQueueOnSubmittedWorkDone(WGPUQueue cSelf, WGPUQueueWorkDoneCallback callback, void * userdata) {
        auto self = FromAPI(cSelf);

        auto callback_ = callback;
        auto userdata_ = userdata;
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APIOnSubmittedWorkDone(callback_, userdata_);
    }

    WGPUFuture NativeQueueOnSubmittedWorkDone2(WGPUQueue cSelf, WGPUQueueWorkDoneCallbackInfo2 callbackInfo) {
        auto self = FromAPI(cSelf);

        auto callbackInfo_ = callbackInfo;
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIOnSubmittedWorkDone2(callbackInfo_);
        return *ToAPI(&result);
    }

    WGPUFuture NativeQueueOnSubmittedWorkDoneF(WGPUQueue cSelf, WGPUQueueWorkDoneCallbackInfo callbackInfo) {
        auto self = FromAPI(cSelf);

        auto callbackInfo_ = *reinterpret_cast<QueueWorkDoneCallbackInfo*>(&callbackInfo);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIOnSubmittedWorkDoneF(callbackInfo_);
        return *ToAPI(&result);
    }

    void NativeQueueSetLabel(WGPUQueue cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeQueueSubmit(WGPUQueue cSelf, size_t commandCount, WGPUCommandBuffer const * commands) {
        auto self = FromAPI(cSelf);

        auto commandCount_ = commandCount;
        auto commands_ = reinterpret_cast<CommandBufferBase* const * >(commands);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISubmit(commandCount_, commands_);
    }

    void NativeQueueWriteBuffer(WGPUQueue cSelf, WGPUBuffer buffer, uint64_t bufferOffset, void const * data, size_t size) {
        auto self = FromAPI(cSelf);

        auto buffer_ = reinterpret_cast<BufferBase* >(buffer);
        auto bufferOffset_ = bufferOffset;
        auto data_ = reinterpret_cast<void const * >(data);
        auto size_ = size;
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APIWriteBuffer(buffer_, bufferOffset_, data_, size_);
    }

    void NativeQueueWriteTexture(WGPUQueue cSelf, WGPUImageCopyTexture const * destination, void const * data, size_t dataSize, WGPUTextureDataLayout const * dataLayout, WGPUExtent3D const * writeSize) {
        auto self = FromAPI(cSelf);

        auto destination_ = reinterpret_cast<ImageCopyTexture const * >(destination);
        auto data_ = reinterpret_cast<void const * >(data);
        auto dataSize_ = dataSize;
        auto dataLayout_ = reinterpret_cast<TextureDataLayout const * >(dataLayout);
        auto writeSize_ = reinterpret_cast<Extent3D const * >(writeSize);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APIWriteTexture(destination_, data_, dataSize_, dataLayout_, writeSize_);
    }

    void NativeQueueAddRef(WGPUQueue cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeQueueRelease(WGPUQueue cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeRenderBundleSetLabel(WGPURenderBundle cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeRenderBundleAddRef(WGPURenderBundle cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeRenderBundleRelease(WGPURenderBundle cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeRenderBundleEncoderDraw(WGPURenderBundleEncoder cSelf, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) {
        auto self = FromAPI(cSelf);

        auto vertexCount_ = vertexCount;
        auto instanceCount_ = instanceCount;
        auto firstVertex_ = firstVertex;
        auto firstInstance_ = firstInstance;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIDraw(vertexCount_, instanceCount_, firstVertex_, firstInstance_);
    }

    void NativeRenderBundleEncoderDrawIndexed(WGPURenderBundleEncoder cSelf, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance) {
        auto self = FromAPI(cSelf);

        auto indexCount_ = indexCount;
        auto instanceCount_ = instanceCount;
        auto firstIndex_ = firstIndex;
        auto baseVertex_ = baseVertex;
        auto firstInstance_ = firstInstance;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIDrawIndexed(indexCount_, instanceCount_, firstIndex_, baseVertex_, firstInstance_);
    }

    void NativeRenderBundleEncoderDrawIndexedIndirect(WGPURenderBundleEncoder cSelf, WGPUBuffer indirectBuffer, uint64_t indirectOffset) {
        auto self = FromAPI(cSelf);

        auto indirectBuffer_ = reinterpret_cast<BufferBase* >(indirectBuffer);
        auto indirectOffset_ = indirectOffset;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIDrawIndexedIndirect(indirectBuffer_, indirectOffset_);
    }

    void NativeRenderBundleEncoderDrawIndirect(WGPURenderBundleEncoder cSelf, WGPUBuffer indirectBuffer, uint64_t indirectOffset) {
        auto self = FromAPI(cSelf);

        auto indirectBuffer_ = reinterpret_cast<BufferBase* >(indirectBuffer);
        auto indirectOffset_ = indirectOffset;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIDrawIndirect(indirectBuffer_, indirectOffset_);
    }

    WGPURenderBundle NativeRenderBundleEncoderFinish(WGPURenderBundleEncoder cSelf, WGPURenderBundleDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<RenderBundleDescriptor const * >(descriptor);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIFinish(descriptor_);
        return ToAPI(result);
    }

    void NativeRenderBundleEncoderInsertDebugMarker(WGPURenderBundleEncoder cSelf, char const * markerLabel) {
        auto self = FromAPI(cSelf);

        auto markerLabel_ = reinterpret_cast<char const * >(markerLabel);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIInsertDebugMarker(markerLabel_);
    }

    void NativeRenderBundleEncoderPopDebugGroup(WGPURenderBundleEncoder cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIPopDebugGroup();
    }

    void NativeRenderBundleEncoderPushDebugGroup(WGPURenderBundleEncoder cSelf, char const * groupLabel) {
        auto self = FromAPI(cSelf);

        auto groupLabel_ = reinterpret_cast<char const * >(groupLabel);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIPushDebugGroup(groupLabel_);
    }

    void NativeRenderBundleEncoderSetBindGroup(WGPURenderBundleEncoder cSelf, uint32_t groupIndex, WGPUBindGroup group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) {
        auto self = FromAPI(cSelf);

        auto groupIndex_ = groupIndex;
        auto group_ = reinterpret_cast<BindGroupBase* >(group);
        auto dynamicOffsetCount_ = dynamicOffsetCount;
        auto dynamicOffsets_ = reinterpret_cast<uint32_t const * >(dynamicOffsets);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetBindGroup(groupIndex_, group_, dynamicOffsetCount_, dynamicOffsets_);
    }

    void NativeRenderBundleEncoderSetIndexBuffer(WGPURenderBundleEncoder cSelf, WGPUBuffer buffer, WGPUIndexFormat format, uint64_t offset, uint64_t size) {
        auto self = FromAPI(cSelf);

        auto buffer_ = reinterpret_cast<BufferBase* >(buffer);
        auto format_ = static_cast<wgpu::IndexFormat>(format);
        auto offset_ = offset;
        auto size_ = size;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetIndexBuffer(buffer_, format_, offset_, size_);
    }

    void NativeRenderBundleEncoderSetLabel(WGPURenderBundleEncoder cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetLabel(label_);
    }

    void NativeRenderBundleEncoderSetPipeline(WGPURenderBundleEncoder cSelf, WGPURenderPipeline pipeline) {
        auto self = FromAPI(cSelf);

        auto pipeline_ = reinterpret_cast<RenderPipelineBase* >(pipeline);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetPipeline(pipeline_);
    }

    void NativeRenderBundleEncoderSetVertexBuffer(WGPURenderBundleEncoder cSelf, uint32_t slot, WGPUBuffer buffer, uint64_t offset, uint64_t size) {
        auto self = FromAPI(cSelf);

        auto slot_ = slot;
        auto buffer_ = reinterpret_cast<BufferBase* >(buffer);
        auto offset_ = offset;
        auto size_ = size;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetVertexBuffer(slot_, buffer_, offset_, size_);
    }

    void NativeRenderBundleEncoderAddRef(WGPURenderBundleEncoder cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeRenderBundleEncoderRelease(WGPURenderBundleEncoder cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeRenderPassEncoderBeginOcclusionQuery(WGPURenderPassEncoder cSelf, uint32_t queryIndex) {
        auto self = FromAPI(cSelf);

        auto queryIndex_ = queryIndex;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIBeginOcclusionQuery(queryIndex_);
    }

    void NativeRenderPassEncoderDraw(WGPURenderPassEncoder cSelf, uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) {
        auto self = FromAPI(cSelf);

        auto vertexCount_ = vertexCount;
        auto instanceCount_ = instanceCount;
        auto firstVertex_ = firstVertex;
        auto firstInstance_ = firstInstance;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIDraw(vertexCount_, instanceCount_, firstVertex_, firstInstance_);
    }

    void NativeRenderPassEncoderDrawIndexed(WGPURenderPassEncoder cSelf, uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance) {
        auto self = FromAPI(cSelf);

        auto indexCount_ = indexCount;
        auto instanceCount_ = instanceCount;
        auto firstIndex_ = firstIndex;
        auto baseVertex_ = baseVertex;
        auto firstInstance_ = firstInstance;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIDrawIndexed(indexCount_, instanceCount_, firstIndex_, baseVertex_, firstInstance_);
    }

    void NativeRenderPassEncoderDrawIndexedIndirect(WGPURenderPassEncoder cSelf, WGPUBuffer indirectBuffer, uint64_t indirectOffset) {
        auto self = FromAPI(cSelf);

        auto indirectBuffer_ = reinterpret_cast<BufferBase* >(indirectBuffer);
        auto indirectOffset_ = indirectOffset;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIDrawIndexedIndirect(indirectBuffer_, indirectOffset_);
    }

    void NativeRenderPassEncoderDrawIndirect(WGPURenderPassEncoder cSelf, WGPUBuffer indirectBuffer, uint64_t indirectOffset) {
        auto self = FromAPI(cSelf);

        auto indirectBuffer_ = reinterpret_cast<BufferBase* >(indirectBuffer);
        auto indirectOffset_ = indirectOffset;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIDrawIndirect(indirectBuffer_, indirectOffset_);
    }

    void NativeRenderPassEncoderEnd(WGPURenderPassEncoder cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIEnd();
    }

    void NativeRenderPassEncoderEndOcclusionQuery(WGPURenderPassEncoder cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIEndOcclusionQuery();
    }

    void NativeRenderPassEncoderExecuteBundles(WGPURenderPassEncoder cSelf, size_t bundleCount, WGPURenderBundle const * bundles) {
        auto self = FromAPI(cSelf);

        auto bundleCount_ = bundleCount;
        auto bundles_ = reinterpret_cast<RenderBundleBase* const * >(bundles);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIExecuteBundles(bundleCount_, bundles_);
    }

    void NativeRenderPassEncoderInsertDebugMarker(WGPURenderPassEncoder cSelf, char const * markerLabel) {
        auto self = FromAPI(cSelf);

        auto markerLabel_ = reinterpret_cast<char const * >(markerLabel);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIInsertDebugMarker(markerLabel_);
    }

    void NativeRenderPassEncoderPixelLocalStorageBarrier(WGPURenderPassEncoder cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIPixelLocalStorageBarrier();
    }

    void NativeRenderPassEncoderPopDebugGroup(WGPURenderPassEncoder cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIPopDebugGroup();
    }

    void NativeRenderPassEncoderPushDebugGroup(WGPURenderPassEncoder cSelf, char const * groupLabel) {
        auto self = FromAPI(cSelf);

        auto groupLabel_ = reinterpret_cast<char const * >(groupLabel);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIPushDebugGroup(groupLabel_);
    }

    void NativeRenderPassEncoderSetBindGroup(WGPURenderPassEncoder cSelf, uint32_t groupIndex, WGPUBindGroup group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) {
        auto self = FromAPI(cSelf);

        auto groupIndex_ = groupIndex;
        auto group_ = reinterpret_cast<BindGroupBase* >(group);
        auto dynamicOffsetCount_ = dynamicOffsetCount;
        auto dynamicOffsets_ = reinterpret_cast<uint32_t const * >(dynamicOffsets);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetBindGroup(groupIndex_, group_, dynamicOffsetCount_, dynamicOffsets_);
    }

    void NativeRenderPassEncoderSetBlendConstant(WGPURenderPassEncoder cSelf, WGPUColor const * color) {
        auto self = FromAPI(cSelf);

        auto color_ = reinterpret_cast<Color const * >(color);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetBlendConstant(color_);
    }

    void NativeRenderPassEncoderSetIndexBuffer(WGPURenderPassEncoder cSelf, WGPUBuffer buffer, WGPUIndexFormat format, uint64_t offset, uint64_t size) {
        auto self = FromAPI(cSelf);

        auto buffer_ = reinterpret_cast<BufferBase* >(buffer);
        auto format_ = static_cast<wgpu::IndexFormat>(format);
        auto offset_ = offset;
        auto size_ = size;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetIndexBuffer(buffer_, format_, offset_, size_);
    }

    void NativeRenderPassEncoderSetLabel(WGPURenderPassEncoder cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetLabel(label_);
    }

    void NativeRenderPassEncoderSetPipeline(WGPURenderPassEncoder cSelf, WGPURenderPipeline pipeline) {
        auto self = FromAPI(cSelf);

        auto pipeline_ = reinterpret_cast<RenderPipelineBase* >(pipeline);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetPipeline(pipeline_);
    }

    void NativeRenderPassEncoderSetScissorRect(WGPURenderPassEncoder cSelf, uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
        auto self = FromAPI(cSelf);

        auto x_ = x;
        auto y_ = y;
        auto width_ = width;
        auto height_ = height;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetScissorRect(x_, y_, width_, height_);
    }

    void NativeRenderPassEncoderSetStencilReference(WGPURenderPassEncoder cSelf, uint32_t reference) {
        auto self = FromAPI(cSelf);

        auto reference_ = reference;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetStencilReference(reference_);
    }

    void NativeRenderPassEncoderSetVertexBuffer(WGPURenderPassEncoder cSelf, uint32_t slot, WGPUBuffer buffer, uint64_t offset, uint64_t size) {
        auto self = FromAPI(cSelf);

        auto slot_ = slot;
        auto buffer_ = reinterpret_cast<BufferBase* >(buffer);
        auto offset_ = offset;
        auto size_ = size;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetVertexBuffer(slot_, buffer_, offset_, size_);
    }

    void NativeRenderPassEncoderSetViewport(WGPURenderPassEncoder cSelf, float x, float y, float width, float height, float minDepth, float maxDepth) {
        auto self = FromAPI(cSelf);

        auto x_ = x;
        auto y_ = y;
        auto width_ = width;
        auto height_ = height;
        auto minDepth_ = minDepth;
        auto maxDepth_ = maxDepth;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APISetViewport(x_, y_, width_, height_, minDepth_, maxDepth_);
    }

    void NativeRenderPassEncoderWriteTimestamp(WGPURenderPassEncoder cSelf, WGPUQuerySet querySet, uint32_t queryIndex) {
        auto self = FromAPI(cSelf);

        auto querySet_ = reinterpret_cast<QuerySetBase* >(querySet);
        auto queryIndex_ = queryIndex;
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIWriteTimestamp(querySet_, queryIndex_);
    }

    void NativeRenderPassEncoderAddRef(WGPURenderPassEncoder cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeRenderPassEncoderRelease(WGPURenderPassEncoder cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    WGPUBindGroupLayout NativeRenderPipelineGetBindGroupLayout(WGPURenderPipeline cSelf, uint32_t groupIndex) {
        auto self = FromAPI(cSelf);

        auto groupIndex_ = groupIndex;
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetBindGroupLayout(groupIndex_);
        return ToAPI(result);
    }

    void NativeRenderPipelineSetLabel(WGPURenderPipeline cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeRenderPipelineAddRef(WGPURenderPipeline cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeRenderPipelineRelease(WGPURenderPipeline cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeSamplerSetLabel(WGPUSampler cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeSamplerAddRef(WGPUSampler cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeSamplerRelease(WGPUSampler cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeShaderModuleGetCompilationInfo(WGPUShaderModule cSelf, WGPUCompilationInfoCallback callback, void * userdata) {
        auto self = FromAPI(cSelf);

        auto callback_ = callback;
        auto userdata_ = userdata;
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APIGetCompilationInfo(callback_, userdata_);
    }

    WGPUFuture NativeShaderModuleGetCompilationInfoF(WGPUShaderModule cSelf, WGPUCompilationInfoCallbackInfo callbackInfo) {
        auto self = FromAPI(cSelf);

        auto callbackInfo_ = *reinterpret_cast<CompilationInfoCallbackInfo*>(&callbackInfo);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIGetCompilationInfoF(callbackInfo_);
        return *ToAPI(&result);
    }

    void NativeShaderModuleSetLabel(WGPUShaderModule cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeShaderModuleAddRef(WGPUShaderModule cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeShaderModuleRelease(WGPUShaderModule cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    WGPUBool NativeSharedBufferMemoryBeginAccess(WGPUSharedBufferMemory cSelf, WGPUBuffer buffer, WGPUSharedBufferMemoryBeginAccessDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto buffer_ = reinterpret_cast<BufferBase* >(buffer);
        auto descriptor_ = reinterpret_cast<SharedBufferMemoryBeginAccessDescriptor const * >(descriptor);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIBeginAccess(buffer_, descriptor_);
        return result;
    }

    WGPUBuffer NativeSharedBufferMemoryCreateBuffer(WGPUSharedBufferMemory cSelf, WGPUBufferDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<BufferDescriptor const * >(descriptor);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateBuffer(descriptor_);
        return ToAPI(result);
    }

    WGPUBool NativeSharedBufferMemoryEndAccess(WGPUSharedBufferMemory cSelf, WGPUBuffer buffer, WGPUSharedBufferMemoryEndAccessState * descriptor) {
        auto self = FromAPI(cSelf);

        auto buffer_ = reinterpret_cast<BufferBase* >(buffer);
        auto descriptor_ = reinterpret_cast<SharedBufferMemoryEndAccessState * >(descriptor);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIEndAccess(buffer_, descriptor_);
        return result;
    }

    WGPUStatus NativeSharedBufferMemoryGetProperties(WGPUSharedBufferMemory cSelf, WGPUSharedBufferMemoryProperties * properties) {
        auto self = FromAPI(cSelf);

        auto properties_ = reinterpret_cast<SharedBufferMemoryProperties * >(properties);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetProperties(properties_);
        return ToAPI(result);
    }

    WGPUBool NativeSharedBufferMemoryIsDeviceLost(WGPUSharedBufferMemory cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIIsDeviceLost();
        return result;
    }

    void NativeSharedBufferMemorySetLabel(WGPUSharedBufferMemory cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeSharedBufferMemoryAddRef(WGPUSharedBufferMemory cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeSharedBufferMemoryRelease(WGPUSharedBufferMemory cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeSharedFenceExportInfo(WGPUSharedFence cSelf, WGPUSharedFenceExportInfo * info) {
        auto self = FromAPI(cSelf);

        auto info_ = reinterpret_cast<SharedFenceExportInfo * >(info);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APIExportInfo(info_);
    }

    void NativeSharedFenceAddRef(WGPUSharedFence cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeSharedFenceRelease(WGPUSharedFence cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    WGPUBool NativeSharedTextureMemoryBeginAccess(WGPUSharedTextureMemory cSelf, WGPUTexture texture, WGPUSharedTextureMemoryBeginAccessDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto texture_ = reinterpret_cast<TextureBase* >(texture);
        auto descriptor_ = reinterpret_cast<SharedTextureMemoryBeginAccessDescriptor const * >(descriptor);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIBeginAccess(texture_, descriptor_);
        return result;
    }

    WGPUTexture NativeSharedTextureMemoryCreateTexture(WGPUSharedTextureMemory cSelf, WGPUTextureDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<TextureDescriptor const * >(descriptor);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateTexture(descriptor_);
        return ToAPI(result);
    }

    WGPUBool NativeSharedTextureMemoryEndAccess(WGPUSharedTextureMemory cSelf, WGPUTexture texture, WGPUSharedTextureMemoryEndAccessState * descriptor) {
        auto self = FromAPI(cSelf);

        auto texture_ = reinterpret_cast<TextureBase* >(texture);
        auto descriptor_ = reinterpret_cast<SharedTextureMemoryEndAccessState * >(descriptor);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIEndAccess(texture_, descriptor_);
        return result;
    }

    WGPUStatus NativeSharedTextureMemoryGetProperties(WGPUSharedTextureMemory cSelf, WGPUSharedTextureMemoryProperties * properties) {
        auto self = FromAPI(cSelf);

        auto properties_ = reinterpret_cast<SharedTextureMemoryProperties * >(properties);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetProperties(properties_);
        return ToAPI(result);
    }

    WGPUBool NativeSharedTextureMemoryIsDeviceLost(WGPUSharedTextureMemory cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIIsDeviceLost();
        return result;
    }

    void NativeSharedTextureMemorySetLabel(WGPUSharedTextureMemory cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeSharedTextureMemoryAddRef(WGPUSharedTextureMemory cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeSharedTextureMemoryRelease(WGPUSharedTextureMemory cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeSurfaceConfigure(WGPUSurface cSelf, WGPUSurfaceConfiguration const * config) {
        auto self = FromAPI(cSelf);

        auto config_ = reinterpret_cast<SurfaceConfiguration const * >(config);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIConfigure(config_);
    }

    WGPUStatus NativeSurfaceGetCapabilities(WGPUSurface cSelf, WGPUAdapter adapter, WGPUSurfaceCapabilities * capabilities) {
        auto self = FromAPI(cSelf);

        auto adapter_ = reinterpret_cast<AdapterBase* >(adapter);
        auto capabilities_ = reinterpret_cast<SurfaceCapabilities * >(capabilities);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIGetCapabilities(adapter_, capabilities_);
        return ToAPI(result);
    }

    void NativeSurfaceGetCurrentTexture(WGPUSurface cSelf, WGPUSurfaceTexture * surfaceTexture) {
        auto self = FromAPI(cSelf);

        auto surfaceTexture_ = reinterpret_cast<SurfaceTexture * >(surfaceTexture);
        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIGetCurrentTexture(surfaceTexture_);
    }

    WGPUTextureFormat NativeSurfaceGetPreferredFormat(WGPUSurface cSelf, WGPUAdapter adapter) {
        auto self = FromAPI(cSelf);

        auto adapter_ = reinterpret_cast<AdapterBase* >(adapter);
        // This method is specified to not use AutoLock in json script or it returns a future.

        auto result =        self->APIGetPreferredFormat(adapter_);
        return ToAPI(result);
    }

    void NativeSurfacePresent(WGPUSurface cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIPresent();
    }

    void NativeSurfaceUnconfigure(WGPUSurface cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIUnconfigure();
    }

    void NativeSurfaceAddRef(WGPUSurface cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeSurfaceRelease(WGPUSurface cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    WGPUTexture NativeSwapChainGetCurrentTexture(WGPUSwapChain cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetCurrentTexture();
        return ToAPI(result);
    }

    WGPUTextureView NativeSwapChainGetCurrentTextureView(WGPUSwapChain cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetCurrentTextureView();
        return ToAPI(result);
    }

    void NativeSwapChainPresent(WGPUSwapChain cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APIPresent();
    }

    void NativeSwapChainAddRef(WGPUSwapChain cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeSwapChainRelease(WGPUSwapChain cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    WGPUTextureView NativeTextureCreateErrorView(WGPUTexture cSelf, WGPUTextureViewDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<TextureViewDescriptor const * >(descriptor);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateErrorView(descriptor_);
        return ToAPI(result);
    }

    WGPUTextureView NativeTextureCreateView(WGPUTexture cSelf, WGPUTextureViewDescriptor const * descriptor) {
        auto self = FromAPI(cSelf);

        auto descriptor_ = reinterpret_cast<TextureViewDescriptor const * >(descriptor);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APICreateView(descriptor_);
        return ToAPI(result);
    }

    void NativeTextureDestroy(WGPUTexture cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APIDestroy();
    }

    uint32_t NativeTextureGetDepthOrArrayLayers(WGPUTexture cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetDepthOrArrayLayers();
        return result;
    }

    WGPUTextureDimension NativeTextureGetDimension(WGPUTexture cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetDimension();
        return ToAPI(result);
    }

    WGPUTextureFormat NativeTextureGetFormat(WGPUTexture cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetFormat();
        return ToAPI(result);
    }

    uint32_t NativeTextureGetHeight(WGPUTexture cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetHeight();
        return result;
    }

    uint32_t NativeTextureGetMipLevelCount(WGPUTexture cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetMipLevelCount();
        return result;
    }

    uint32_t NativeTextureGetSampleCount(WGPUTexture cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetSampleCount();
        return result;
    }

    WGPUTextureUsageFlags NativeTextureGetUsage(WGPUTexture cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetUsage();
        return ToAPI(result);
    }

    uint32_t NativeTextureGetWidth(WGPUTexture cSelf) {
        auto self = FromAPI(cSelf);

        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        auto result =        self->APIGetWidth();
        return result;
    }

    void NativeTextureSetLabel(WGPUTexture cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeTextureAddRef(WGPUTexture cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeTextureRelease(WGPUTexture cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeTextureViewSetLabel(WGPUTextureView cSelf, char const * label) {
        auto self = FromAPI(cSelf);

        auto label_ = reinterpret_cast<char const * >(label);
        auto device = self->GetDevice();
        auto deviceLock(device->GetScopedLock());

        self->APISetLabel(label_);
    }

    void NativeTextureViewAddRef(WGPUTextureView cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIAddRef();
    }

    void NativeTextureViewRelease(WGPUTextureView cSelf) {
        auto self = FromAPI(cSelf);

        // This method is specified to not use AutoLock in json script or it returns a future.

        self->APIRelease();
    }

    void NativeAdapterInfoFreeMembers(WGPUAdapterInfo value) {
        auto value_ = value;
        APIAdapterInfoFreeMembers(value_);
    }
    void NativeAdapterPropertiesFreeMembers(WGPUAdapterProperties value) {
        auto value_ = value;
        APIAdapterPropertiesFreeMembers(value_);
    }
    void NativeAdapterPropertiesMemoryHeapsFreeMembers(WGPUAdapterPropertiesMemoryHeaps value) {
        auto value_ = value;
        APIAdapterPropertiesMemoryHeapsFreeMembers(value_);
    }
    WGPUInstance NativeCreateInstance(WGPUInstanceDescriptor const * descriptor) {
        auto descriptor_ = reinterpret_cast<InstanceDescriptor const * >(descriptor);
        auto result =        APICreateInstance(descriptor_);
        return ToAPI(result);
    }
    void NativeDrmFormatCapabilitiesFreeMembers(WGPUDrmFormatCapabilities value) {
        auto value_ = value;
        APIDrmFormatCapabilitiesFreeMembers(value_);
    }
    WGPUStatus NativeGetInstanceFeatures(WGPUInstanceFeatures * features) {
        auto features_ = reinterpret_cast<InstanceFeatures * >(features);
        auto result =        APIGetInstanceFeatures(features_);
        return ToAPI(result);
    }
    void NativeSharedBufferMemoryEndAccessStateFreeMembers(WGPUSharedBufferMemoryEndAccessState value) {
        auto value_ = value;
        APISharedBufferMemoryEndAccessStateFreeMembers(value_);
    }
    void NativeSharedTextureMemoryEndAccessStateFreeMembers(WGPUSharedTextureMemoryEndAccessState value) {
        auto value_ = value;
        APISharedTextureMemoryEndAccessStateFreeMembers(value_);
    }
    void NativeSurfaceCapabilitiesFreeMembers(WGPUSurfaceCapabilities value) {
        auto value_ = value;
        APISurfaceCapabilitiesFreeMembers(value_);
    }

    namespace {

        struct ProcEntry {
            WGPUProc proc;
            const char* name;
        };
        static const ProcEntry sProcMap[] = {
            { reinterpret_cast<WGPUProc>(NativeAdapterAddRef), "wgpuAdapterAddRef" },
            { reinterpret_cast<WGPUProc>(NativeAdapterCreateDevice), "wgpuAdapterCreateDevice" },
            { reinterpret_cast<WGPUProc>(NativeAdapterEnumerateFeatures), "wgpuAdapterEnumerateFeatures" },
            { reinterpret_cast<WGPUProc>(NativeAdapterGetFormatCapabilities), "wgpuAdapterGetFormatCapabilities" },
            { reinterpret_cast<WGPUProc>(NativeAdapterGetInfo), "wgpuAdapterGetInfo" },
            { reinterpret_cast<WGPUProc>(NativeAdapterGetInstance), "wgpuAdapterGetInstance" },
            { reinterpret_cast<WGPUProc>(NativeAdapterGetLimits), "wgpuAdapterGetLimits" },
            { reinterpret_cast<WGPUProc>(NativeAdapterGetProperties), "wgpuAdapterGetProperties" },
            { reinterpret_cast<WGPUProc>(NativeAdapterHasFeature), "wgpuAdapterHasFeature" },
            { reinterpret_cast<WGPUProc>(NativeAdapterRelease), "wgpuAdapterRelease" },
            { reinterpret_cast<WGPUProc>(NativeAdapterRequestDevice), "wgpuAdapterRequestDevice" },
            { reinterpret_cast<WGPUProc>(NativeAdapterRequestDevice2), "wgpuAdapterRequestDevice2" },
            { reinterpret_cast<WGPUProc>(NativeAdapterRequestDeviceF), "wgpuAdapterRequestDeviceF" },
            { reinterpret_cast<WGPUProc>(NativeBindGroupAddRef), "wgpuBindGroupAddRef" },
            { reinterpret_cast<WGPUProc>(NativeBindGroupLayoutAddRef), "wgpuBindGroupLayoutAddRef" },
            { reinterpret_cast<WGPUProc>(NativeBindGroupLayoutRelease), "wgpuBindGroupLayoutRelease" },
            { reinterpret_cast<WGPUProc>(NativeBindGroupLayoutSetLabel), "wgpuBindGroupLayoutSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeBindGroupRelease), "wgpuBindGroupRelease" },
            { reinterpret_cast<WGPUProc>(NativeBindGroupSetLabel), "wgpuBindGroupSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeBufferAddRef), "wgpuBufferAddRef" },
            { reinterpret_cast<WGPUProc>(NativeBufferDestroy), "wgpuBufferDestroy" },
            { reinterpret_cast<WGPUProc>(NativeBufferGetConstMappedRange), "wgpuBufferGetConstMappedRange" },
            { reinterpret_cast<WGPUProc>(NativeBufferGetMapState), "wgpuBufferGetMapState" },
            { reinterpret_cast<WGPUProc>(NativeBufferGetMappedRange), "wgpuBufferGetMappedRange" },
            { reinterpret_cast<WGPUProc>(NativeBufferGetSize), "wgpuBufferGetSize" },
            { reinterpret_cast<WGPUProc>(NativeBufferGetUsage), "wgpuBufferGetUsage" },
            { reinterpret_cast<WGPUProc>(NativeBufferMapAsync), "wgpuBufferMapAsync" },
            { reinterpret_cast<WGPUProc>(NativeBufferMapAsyncF), "wgpuBufferMapAsyncF" },
            { reinterpret_cast<WGPUProc>(NativeBufferRelease), "wgpuBufferRelease" },
            { reinterpret_cast<WGPUProc>(NativeBufferSetLabel), "wgpuBufferSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeBufferUnmap), "wgpuBufferUnmap" },
            { reinterpret_cast<WGPUProc>(NativeCommandBufferAddRef), "wgpuCommandBufferAddRef" },
            { reinterpret_cast<WGPUProc>(NativeCommandBufferRelease), "wgpuCommandBufferRelease" },
            { reinterpret_cast<WGPUProc>(NativeCommandBufferSetLabel), "wgpuCommandBufferSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderAddRef), "wgpuCommandEncoderAddRef" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderBeginComputePass), "wgpuCommandEncoderBeginComputePass" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderBeginRenderPass), "wgpuCommandEncoderBeginRenderPass" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderClearBuffer), "wgpuCommandEncoderClearBuffer" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderCopyBufferToBuffer), "wgpuCommandEncoderCopyBufferToBuffer" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderCopyBufferToTexture), "wgpuCommandEncoderCopyBufferToTexture" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderCopyTextureToBuffer), "wgpuCommandEncoderCopyTextureToBuffer" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderCopyTextureToTexture), "wgpuCommandEncoderCopyTextureToTexture" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderFinish), "wgpuCommandEncoderFinish" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderInjectValidationError), "wgpuCommandEncoderInjectValidationError" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderInsertDebugMarker), "wgpuCommandEncoderInsertDebugMarker" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderPopDebugGroup), "wgpuCommandEncoderPopDebugGroup" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderPushDebugGroup), "wgpuCommandEncoderPushDebugGroup" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderRelease), "wgpuCommandEncoderRelease" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderResolveQuerySet), "wgpuCommandEncoderResolveQuerySet" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderSetLabel), "wgpuCommandEncoderSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderWriteBuffer), "wgpuCommandEncoderWriteBuffer" },
            { reinterpret_cast<WGPUProc>(NativeCommandEncoderWriteTimestamp), "wgpuCommandEncoderWriteTimestamp" },
            { reinterpret_cast<WGPUProc>(NativeComputePassEncoderAddRef), "wgpuComputePassEncoderAddRef" },
            { reinterpret_cast<WGPUProc>(NativeComputePassEncoderDispatchWorkgroups), "wgpuComputePassEncoderDispatchWorkgroups" },
            { reinterpret_cast<WGPUProc>(NativeComputePassEncoderDispatchWorkgroupsIndirect), "wgpuComputePassEncoderDispatchWorkgroupsIndirect" },
            { reinterpret_cast<WGPUProc>(NativeComputePassEncoderEnd), "wgpuComputePassEncoderEnd" },
            { reinterpret_cast<WGPUProc>(NativeComputePassEncoderInsertDebugMarker), "wgpuComputePassEncoderInsertDebugMarker" },
            { reinterpret_cast<WGPUProc>(NativeComputePassEncoderPopDebugGroup), "wgpuComputePassEncoderPopDebugGroup" },
            { reinterpret_cast<WGPUProc>(NativeComputePassEncoderPushDebugGroup), "wgpuComputePassEncoderPushDebugGroup" },
            { reinterpret_cast<WGPUProc>(NativeComputePassEncoderRelease), "wgpuComputePassEncoderRelease" },
            { reinterpret_cast<WGPUProc>(NativeComputePassEncoderSetBindGroup), "wgpuComputePassEncoderSetBindGroup" },
            { reinterpret_cast<WGPUProc>(NativeComputePassEncoderSetLabel), "wgpuComputePassEncoderSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeComputePassEncoderSetPipeline), "wgpuComputePassEncoderSetPipeline" },
            { reinterpret_cast<WGPUProc>(NativeComputePassEncoderWriteTimestamp), "wgpuComputePassEncoderWriteTimestamp" },
            { reinterpret_cast<WGPUProc>(NativeComputePipelineAddRef), "wgpuComputePipelineAddRef" },
            { reinterpret_cast<WGPUProc>(NativeComputePipelineGetBindGroupLayout), "wgpuComputePipelineGetBindGroupLayout" },
            { reinterpret_cast<WGPUProc>(NativeComputePipelineRelease), "wgpuComputePipelineRelease" },
            { reinterpret_cast<WGPUProc>(NativeComputePipelineSetLabel), "wgpuComputePipelineSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeDeviceAddRef), "wgpuDeviceAddRef" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateBindGroup), "wgpuDeviceCreateBindGroup" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateBindGroupLayout), "wgpuDeviceCreateBindGroupLayout" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateBuffer), "wgpuDeviceCreateBuffer" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateCommandEncoder), "wgpuDeviceCreateCommandEncoder" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateComputePipeline), "wgpuDeviceCreateComputePipeline" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateComputePipelineAsync), "wgpuDeviceCreateComputePipelineAsync" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateComputePipelineAsync2), "wgpuDeviceCreateComputePipelineAsync2" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateComputePipelineAsyncF), "wgpuDeviceCreateComputePipelineAsyncF" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateErrorBuffer), "wgpuDeviceCreateErrorBuffer" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateErrorExternalTexture), "wgpuDeviceCreateErrorExternalTexture" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateErrorShaderModule), "wgpuDeviceCreateErrorShaderModule" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateErrorTexture), "wgpuDeviceCreateErrorTexture" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateExternalTexture), "wgpuDeviceCreateExternalTexture" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreatePipelineLayout), "wgpuDeviceCreatePipelineLayout" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateQuerySet), "wgpuDeviceCreateQuerySet" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateRenderBundleEncoder), "wgpuDeviceCreateRenderBundleEncoder" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateRenderPipeline), "wgpuDeviceCreateRenderPipeline" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateRenderPipelineAsync), "wgpuDeviceCreateRenderPipelineAsync" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateRenderPipelineAsync2), "wgpuDeviceCreateRenderPipelineAsync2" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateRenderPipelineAsyncF), "wgpuDeviceCreateRenderPipelineAsyncF" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateSampler), "wgpuDeviceCreateSampler" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateShaderModule), "wgpuDeviceCreateShaderModule" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateSwapChain), "wgpuDeviceCreateSwapChain" },
            { reinterpret_cast<WGPUProc>(NativeDeviceCreateTexture), "wgpuDeviceCreateTexture" },
            { reinterpret_cast<WGPUProc>(NativeDeviceDestroy), "wgpuDeviceDestroy" },
            { reinterpret_cast<WGPUProc>(NativeDeviceEnumerateFeatures), "wgpuDeviceEnumerateFeatures" },
            { reinterpret_cast<WGPUProc>(NativeDeviceForceLoss), "wgpuDeviceForceLoss" },
            { reinterpret_cast<WGPUProc>(NativeDeviceGetAHardwareBufferProperties), "wgpuDeviceGetAHardwareBufferProperties" },
            { reinterpret_cast<WGPUProc>(NativeDeviceGetAdapter), "wgpuDeviceGetAdapter" },
            { reinterpret_cast<WGPUProc>(NativeDeviceGetLimits), "wgpuDeviceGetLimits" },
            { reinterpret_cast<WGPUProc>(NativeDeviceGetQueue), "wgpuDeviceGetQueue" },
            { reinterpret_cast<WGPUProc>(NativeDeviceGetSupportedSurfaceUsage), "wgpuDeviceGetSupportedSurfaceUsage" },
            { reinterpret_cast<WGPUProc>(NativeDeviceHasFeature), "wgpuDeviceHasFeature" },
            { reinterpret_cast<WGPUProc>(NativeDeviceImportSharedBufferMemory), "wgpuDeviceImportSharedBufferMemory" },
            { reinterpret_cast<WGPUProc>(NativeDeviceImportSharedFence), "wgpuDeviceImportSharedFence" },
            { reinterpret_cast<WGPUProc>(NativeDeviceImportSharedTextureMemory), "wgpuDeviceImportSharedTextureMemory" },
            { reinterpret_cast<WGPUProc>(NativeDeviceInjectError), "wgpuDeviceInjectError" },
            { reinterpret_cast<WGPUProc>(NativeDevicePopErrorScope), "wgpuDevicePopErrorScope" },
            { reinterpret_cast<WGPUProc>(NativeDevicePopErrorScope2), "wgpuDevicePopErrorScope2" },
            { reinterpret_cast<WGPUProc>(NativeDevicePopErrorScopeF), "wgpuDevicePopErrorScopeF" },
            { reinterpret_cast<WGPUProc>(NativeDevicePushErrorScope), "wgpuDevicePushErrorScope" },
            { reinterpret_cast<WGPUProc>(NativeDeviceRelease), "wgpuDeviceRelease" },
            { reinterpret_cast<WGPUProc>(NativeDeviceSetDeviceLostCallback), "wgpuDeviceSetDeviceLostCallback" },
            { reinterpret_cast<WGPUProc>(NativeDeviceSetLabel), "wgpuDeviceSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeDeviceSetLoggingCallback), "wgpuDeviceSetLoggingCallback" },
            { reinterpret_cast<WGPUProc>(NativeDeviceSetUncapturedErrorCallback), "wgpuDeviceSetUncapturedErrorCallback" },
            { reinterpret_cast<WGPUProc>(NativeDeviceTick), "wgpuDeviceTick" },
            { reinterpret_cast<WGPUProc>(NativeDeviceValidateTextureDescriptor), "wgpuDeviceValidateTextureDescriptor" },
            { reinterpret_cast<WGPUProc>(NativeExternalTextureAddRef), "wgpuExternalTextureAddRef" },
            { reinterpret_cast<WGPUProc>(NativeExternalTextureDestroy), "wgpuExternalTextureDestroy" },
            { reinterpret_cast<WGPUProc>(NativeExternalTextureExpire), "wgpuExternalTextureExpire" },
            { reinterpret_cast<WGPUProc>(NativeExternalTextureRefresh), "wgpuExternalTextureRefresh" },
            { reinterpret_cast<WGPUProc>(NativeExternalTextureRelease), "wgpuExternalTextureRelease" },
            { reinterpret_cast<WGPUProc>(NativeExternalTextureSetLabel), "wgpuExternalTextureSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeInstanceAddRef), "wgpuInstanceAddRef" },
            { reinterpret_cast<WGPUProc>(NativeInstanceCreateSurface), "wgpuInstanceCreateSurface" },
            { reinterpret_cast<WGPUProc>(NativeInstanceEnumerateWGSLLanguageFeatures), "wgpuInstanceEnumerateWGSLLanguageFeatures" },
            { reinterpret_cast<WGPUProc>(NativeInstanceHasWGSLLanguageFeature), "wgpuInstanceHasWGSLLanguageFeature" },
            { reinterpret_cast<WGPUProc>(NativeInstanceProcessEvents), "wgpuInstanceProcessEvents" },
            { reinterpret_cast<WGPUProc>(NativeInstanceRelease), "wgpuInstanceRelease" },
            { reinterpret_cast<WGPUProc>(NativeInstanceRequestAdapter), "wgpuInstanceRequestAdapter" },
            { reinterpret_cast<WGPUProc>(NativeInstanceRequestAdapter2), "wgpuInstanceRequestAdapter2" },
            { reinterpret_cast<WGPUProc>(NativeInstanceRequestAdapterF), "wgpuInstanceRequestAdapterF" },
            { reinterpret_cast<WGPUProc>(NativeInstanceWaitAny), "wgpuInstanceWaitAny" },
            { reinterpret_cast<WGPUProc>(NativePipelineLayoutAddRef), "wgpuPipelineLayoutAddRef" },
            { reinterpret_cast<WGPUProc>(NativePipelineLayoutRelease), "wgpuPipelineLayoutRelease" },
            { reinterpret_cast<WGPUProc>(NativePipelineLayoutSetLabel), "wgpuPipelineLayoutSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeQuerySetAddRef), "wgpuQuerySetAddRef" },
            { reinterpret_cast<WGPUProc>(NativeQuerySetDestroy), "wgpuQuerySetDestroy" },
            { reinterpret_cast<WGPUProc>(NativeQuerySetGetCount), "wgpuQuerySetGetCount" },
            { reinterpret_cast<WGPUProc>(NativeQuerySetGetType), "wgpuQuerySetGetType" },
            { reinterpret_cast<WGPUProc>(NativeQuerySetRelease), "wgpuQuerySetRelease" },
            { reinterpret_cast<WGPUProc>(NativeQuerySetSetLabel), "wgpuQuerySetSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeQueueAddRef), "wgpuQueueAddRef" },
            { reinterpret_cast<WGPUProc>(NativeQueueCopyExternalTextureForBrowser), "wgpuQueueCopyExternalTextureForBrowser" },
            { reinterpret_cast<WGPUProc>(NativeQueueCopyTextureForBrowser), "wgpuQueueCopyTextureForBrowser" },
            { reinterpret_cast<WGPUProc>(NativeQueueOnSubmittedWorkDone), "wgpuQueueOnSubmittedWorkDone" },
            { reinterpret_cast<WGPUProc>(NativeQueueOnSubmittedWorkDone2), "wgpuQueueOnSubmittedWorkDone2" },
            { reinterpret_cast<WGPUProc>(NativeQueueOnSubmittedWorkDoneF), "wgpuQueueOnSubmittedWorkDoneF" },
            { reinterpret_cast<WGPUProc>(NativeQueueRelease), "wgpuQueueRelease" },
            { reinterpret_cast<WGPUProc>(NativeQueueSetLabel), "wgpuQueueSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeQueueSubmit), "wgpuQueueSubmit" },
            { reinterpret_cast<WGPUProc>(NativeQueueWriteBuffer), "wgpuQueueWriteBuffer" },
            { reinterpret_cast<WGPUProc>(NativeQueueWriteTexture), "wgpuQueueWriteTexture" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleAddRef), "wgpuRenderBundleAddRef" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleEncoderAddRef), "wgpuRenderBundleEncoderAddRef" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleEncoderDraw), "wgpuRenderBundleEncoderDraw" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleEncoderDrawIndexed), "wgpuRenderBundleEncoderDrawIndexed" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleEncoderDrawIndexedIndirect), "wgpuRenderBundleEncoderDrawIndexedIndirect" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleEncoderDrawIndirect), "wgpuRenderBundleEncoderDrawIndirect" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleEncoderFinish), "wgpuRenderBundleEncoderFinish" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleEncoderInsertDebugMarker), "wgpuRenderBundleEncoderInsertDebugMarker" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleEncoderPopDebugGroup), "wgpuRenderBundleEncoderPopDebugGroup" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleEncoderPushDebugGroup), "wgpuRenderBundleEncoderPushDebugGroup" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleEncoderRelease), "wgpuRenderBundleEncoderRelease" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleEncoderSetBindGroup), "wgpuRenderBundleEncoderSetBindGroup" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleEncoderSetIndexBuffer), "wgpuRenderBundleEncoderSetIndexBuffer" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleEncoderSetLabel), "wgpuRenderBundleEncoderSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleEncoderSetPipeline), "wgpuRenderBundleEncoderSetPipeline" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleEncoderSetVertexBuffer), "wgpuRenderBundleEncoderSetVertexBuffer" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleRelease), "wgpuRenderBundleRelease" },
            { reinterpret_cast<WGPUProc>(NativeRenderBundleSetLabel), "wgpuRenderBundleSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderAddRef), "wgpuRenderPassEncoderAddRef" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderBeginOcclusionQuery), "wgpuRenderPassEncoderBeginOcclusionQuery" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderDraw), "wgpuRenderPassEncoderDraw" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderDrawIndexed), "wgpuRenderPassEncoderDrawIndexed" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderDrawIndexedIndirect), "wgpuRenderPassEncoderDrawIndexedIndirect" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderDrawIndirect), "wgpuRenderPassEncoderDrawIndirect" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderEnd), "wgpuRenderPassEncoderEnd" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderEndOcclusionQuery), "wgpuRenderPassEncoderEndOcclusionQuery" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderExecuteBundles), "wgpuRenderPassEncoderExecuteBundles" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderInsertDebugMarker), "wgpuRenderPassEncoderInsertDebugMarker" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderPixelLocalStorageBarrier), "wgpuRenderPassEncoderPixelLocalStorageBarrier" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderPopDebugGroup), "wgpuRenderPassEncoderPopDebugGroup" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderPushDebugGroup), "wgpuRenderPassEncoderPushDebugGroup" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderRelease), "wgpuRenderPassEncoderRelease" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderSetBindGroup), "wgpuRenderPassEncoderSetBindGroup" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderSetBlendConstant), "wgpuRenderPassEncoderSetBlendConstant" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderSetIndexBuffer), "wgpuRenderPassEncoderSetIndexBuffer" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderSetLabel), "wgpuRenderPassEncoderSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderSetPipeline), "wgpuRenderPassEncoderSetPipeline" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderSetScissorRect), "wgpuRenderPassEncoderSetScissorRect" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderSetStencilReference), "wgpuRenderPassEncoderSetStencilReference" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderSetVertexBuffer), "wgpuRenderPassEncoderSetVertexBuffer" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderSetViewport), "wgpuRenderPassEncoderSetViewport" },
            { reinterpret_cast<WGPUProc>(NativeRenderPassEncoderWriteTimestamp), "wgpuRenderPassEncoderWriteTimestamp" },
            { reinterpret_cast<WGPUProc>(NativeRenderPipelineAddRef), "wgpuRenderPipelineAddRef" },
            { reinterpret_cast<WGPUProc>(NativeRenderPipelineGetBindGroupLayout), "wgpuRenderPipelineGetBindGroupLayout" },
            { reinterpret_cast<WGPUProc>(NativeRenderPipelineRelease), "wgpuRenderPipelineRelease" },
            { reinterpret_cast<WGPUProc>(NativeRenderPipelineSetLabel), "wgpuRenderPipelineSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeSamplerAddRef), "wgpuSamplerAddRef" },
            { reinterpret_cast<WGPUProc>(NativeSamplerRelease), "wgpuSamplerRelease" },
            { reinterpret_cast<WGPUProc>(NativeSamplerSetLabel), "wgpuSamplerSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeShaderModuleAddRef), "wgpuShaderModuleAddRef" },
            { reinterpret_cast<WGPUProc>(NativeShaderModuleGetCompilationInfo), "wgpuShaderModuleGetCompilationInfo" },
            { reinterpret_cast<WGPUProc>(NativeShaderModuleGetCompilationInfoF), "wgpuShaderModuleGetCompilationInfoF" },
            { reinterpret_cast<WGPUProc>(NativeShaderModuleRelease), "wgpuShaderModuleRelease" },
            { reinterpret_cast<WGPUProc>(NativeShaderModuleSetLabel), "wgpuShaderModuleSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeSharedBufferMemoryAddRef), "wgpuSharedBufferMemoryAddRef" },
            { reinterpret_cast<WGPUProc>(NativeSharedBufferMemoryBeginAccess), "wgpuSharedBufferMemoryBeginAccess" },
            { reinterpret_cast<WGPUProc>(NativeSharedBufferMemoryCreateBuffer), "wgpuSharedBufferMemoryCreateBuffer" },
            { reinterpret_cast<WGPUProc>(NativeSharedBufferMemoryEndAccess), "wgpuSharedBufferMemoryEndAccess" },
            { reinterpret_cast<WGPUProc>(NativeSharedBufferMemoryGetProperties), "wgpuSharedBufferMemoryGetProperties" },
            { reinterpret_cast<WGPUProc>(NativeSharedBufferMemoryIsDeviceLost), "wgpuSharedBufferMemoryIsDeviceLost" },
            { reinterpret_cast<WGPUProc>(NativeSharedBufferMemoryRelease), "wgpuSharedBufferMemoryRelease" },
            { reinterpret_cast<WGPUProc>(NativeSharedBufferMemorySetLabel), "wgpuSharedBufferMemorySetLabel" },
            { reinterpret_cast<WGPUProc>(NativeSharedFenceAddRef), "wgpuSharedFenceAddRef" },
            { reinterpret_cast<WGPUProc>(NativeSharedFenceExportInfo), "wgpuSharedFenceExportInfo" },
            { reinterpret_cast<WGPUProc>(NativeSharedFenceRelease), "wgpuSharedFenceRelease" },
            { reinterpret_cast<WGPUProc>(NativeSharedTextureMemoryAddRef), "wgpuSharedTextureMemoryAddRef" },
            { reinterpret_cast<WGPUProc>(NativeSharedTextureMemoryBeginAccess), "wgpuSharedTextureMemoryBeginAccess" },
            { reinterpret_cast<WGPUProc>(NativeSharedTextureMemoryCreateTexture), "wgpuSharedTextureMemoryCreateTexture" },
            { reinterpret_cast<WGPUProc>(NativeSharedTextureMemoryEndAccess), "wgpuSharedTextureMemoryEndAccess" },
            { reinterpret_cast<WGPUProc>(NativeSharedTextureMemoryGetProperties), "wgpuSharedTextureMemoryGetProperties" },
            { reinterpret_cast<WGPUProc>(NativeSharedTextureMemoryIsDeviceLost), "wgpuSharedTextureMemoryIsDeviceLost" },
            { reinterpret_cast<WGPUProc>(NativeSharedTextureMemoryRelease), "wgpuSharedTextureMemoryRelease" },
            { reinterpret_cast<WGPUProc>(NativeSharedTextureMemorySetLabel), "wgpuSharedTextureMemorySetLabel" },
            { reinterpret_cast<WGPUProc>(NativeSurfaceAddRef), "wgpuSurfaceAddRef" },
            { reinterpret_cast<WGPUProc>(NativeSurfaceConfigure), "wgpuSurfaceConfigure" },
            { reinterpret_cast<WGPUProc>(NativeSurfaceGetCapabilities), "wgpuSurfaceGetCapabilities" },
            { reinterpret_cast<WGPUProc>(NativeSurfaceGetCurrentTexture), "wgpuSurfaceGetCurrentTexture" },
            { reinterpret_cast<WGPUProc>(NativeSurfaceGetPreferredFormat), "wgpuSurfaceGetPreferredFormat" },
            { reinterpret_cast<WGPUProc>(NativeSurfacePresent), "wgpuSurfacePresent" },
            { reinterpret_cast<WGPUProc>(NativeSurfaceRelease), "wgpuSurfaceRelease" },
            { reinterpret_cast<WGPUProc>(NativeSurfaceUnconfigure), "wgpuSurfaceUnconfigure" },
            { reinterpret_cast<WGPUProc>(NativeSwapChainAddRef), "wgpuSwapChainAddRef" },
            { reinterpret_cast<WGPUProc>(NativeSwapChainGetCurrentTexture), "wgpuSwapChainGetCurrentTexture" },
            { reinterpret_cast<WGPUProc>(NativeSwapChainGetCurrentTextureView), "wgpuSwapChainGetCurrentTextureView" },
            { reinterpret_cast<WGPUProc>(NativeSwapChainPresent), "wgpuSwapChainPresent" },
            { reinterpret_cast<WGPUProc>(NativeSwapChainRelease), "wgpuSwapChainRelease" },
            { reinterpret_cast<WGPUProc>(NativeTextureAddRef), "wgpuTextureAddRef" },
            { reinterpret_cast<WGPUProc>(NativeTextureCreateErrorView), "wgpuTextureCreateErrorView" },
            { reinterpret_cast<WGPUProc>(NativeTextureCreateView), "wgpuTextureCreateView" },
            { reinterpret_cast<WGPUProc>(NativeTextureDestroy), "wgpuTextureDestroy" },
            { reinterpret_cast<WGPUProc>(NativeTextureGetDepthOrArrayLayers), "wgpuTextureGetDepthOrArrayLayers" },
            { reinterpret_cast<WGPUProc>(NativeTextureGetDimension), "wgpuTextureGetDimension" },
            { reinterpret_cast<WGPUProc>(NativeTextureGetFormat), "wgpuTextureGetFormat" },
            { reinterpret_cast<WGPUProc>(NativeTextureGetHeight), "wgpuTextureGetHeight" },
            { reinterpret_cast<WGPUProc>(NativeTextureGetMipLevelCount), "wgpuTextureGetMipLevelCount" },
            { reinterpret_cast<WGPUProc>(NativeTextureGetSampleCount), "wgpuTextureGetSampleCount" },
            { reinterpret_cast<WGPUProc>(NativeTextureGetUsage), "wgpuTextureGetUsage" },
            { reinterpret_cast<WGPUProc>(NativeTextureGetWidth), "wgpuTextureGetWidth" },
            { reinterpret_cast<WGPUProc>(NativeTextureRelease), "wgpuTextureRelease" },
            { reinterpret_cast<WGPUProc>(NativeTextureSetLabel), "wgpuTextureSetLabel" },
            { reinterpret_cast<WGPUProc>(NativeTextureViewAddRef), "wgpuTextureViewAddRef" },
            { reinterpret_cast<WGPUProc>(NativeTextureViewRelease), "wgpuTextureViewRelease" },
            { reinterpret_cast<WGPUProc>(NativeTextureViewSetLabel), "wgpuTextureViewSetLabel" },
        };
        static constexpr size_t sProcMapSize = sizeof(sProcMap) / sizeof(sProcMap[0]);

    }  // anonymous namespace

    WGPUProc NativeGetProcAddress(WGPUDevice, const char* procName) {
        if (procName == nullptr) {
            return nullptr;
        }

        const ProcEntry* entry = std::lower_bound(&sProcMap[0], &sProcMap[sProcMapSize], procName,
            [](const ProcEntry &a, const char *b) -> bool {
                return strcmp(a.name, b) < 0;
            }
        );

        if (entry != &sProcMap[sProcMapSize] && strcmp(entry->name, procName) == 0) {
            return entry->proc;
        }

        // Special case the free-standing functions of the API.
        // TODO(dawn:1238) Checking string one by one is slow, it needs to be optimized.
        if (strcmp(procName, "wgpuAdapterInfoFreeMembers") == 0) {
            return reinterpret_cast<WGPUProc>(NativeAdapterInfoFreeMembers);
        }

        if (strcmp(procName, "wgpuAdapterPropertiesFreeMembers") == 0) {
            return reinterpret_cast<WGPUProc>(NativeAdapterPropertiesFreeMembers);
        }

        if (strcmp(procName, "wgpuAdapterPropertiesMemoryHeapsFreeMembers") == 0) {
            return reinterpret_cast<WGPUProc>(NativeAdapterPropertiesMemoryHeapsFreeMembers);
        }

        if (strcmp(procName, "wgpuCreateInstance") == 0) {
            return reinterpret_cast<WGPUProc>(NativeCreateInstance);
        }

        if (strcmp(procName, "wgpuDrmFormatCapabilitiesFreeMembers") == 0) {
            return reinterpret_cast<WGPUProc>(NativeDrmFormatCapabilitiesFreeMembers);
        }

        if (strcmp(procName, "wgpuGetInstanceFeatures") == 0) {
            return reinterpret_cast<WGPUProc>(NativeGetInstanceFeatures);
        }

        if (strcmp(procName, "wgpuGetProcAddress") == 0) {
            return reinterpret_cast<WGPUProc>(NativeGetProcAddress);
        }

        if (strcmp(procName, "wgpuSharedBufferMemoryEndAccessStateFreeMembers") == 0) {
            return reinterpret_cast<WGPUProc>(NativeSharedBufferMemoryEndAccessStateFreeMembers);
        }

        if (strcmp(procName, "wgpuSharedTextureMemoryEndAccessStateFreeMembers") == 0) {
            return reinterpret_cast<WGPUProc>(NativeSharedTextureMemoryEndAccessStateFreeMembers);
        }

        if (strcmp(procName, "wgpuSurfaceCapabilitiesFreeMembers") == 0) {
            return reinterpret_cast<WGPUProc>(NativeSurfaceCapabilitiesFreeMembers);
        }

        return nullptr;
    }

    std::vector<const char*> GetProcMapNamesForTestingInternal() {
        std::vector<const char*> result;
        result.reserve(sProcMapSize);
        for (const ProcEntry& entry : sProcMap) {
            result.push_back(entry.name);
        }
        return result;
    }

    constexpr DawnProcTable MakeProcTable() {
        DawnProcTable procs = {};
        procs.adapterInfoFreeMembers = NativeAdapterInfoFreeMembers;
        procs.adapterPropertiesFreeMembers = NativeAdapterPropertiesFreeMembers;
        procs.adapterPropertiesMemoryHeapsFreeMembers = NativeAdapterPropertiesMemoryHeapsFreeMembers;
        procs.createInstance = NativeCreateInstance;
        procs.drmFormatCapabilitiesFreeMembers = NativeDrmFormatCapabilitiesFreeMembers;
        procs.getInstanceFeatures = NativeGetInstanceFeatures;
        procs.getProcAddress = NativeGetProcAddress;
        procs.sharedBufferMemoryEndAccessStateFreeMembers = NativeSharedBufferMemoryEndAccessStateFreeMembers;
        procs.sharedTextureMemoryEndAccessStateFreeMembers = NativeSharedTextureMemoryEndAccessStateFreeMembers;
        procs.surfaceCapabilitiesFreeMembers = NativeSurfaceCapabilitiesFreeMembers;
        procs.adapterCreateDevice = NativeAdapterCreateDevice;
        procs.adapterEnumerateFeatures = NativeAdapterEnumerateFeatures;
        procs.adapterGetFormatCapabilities = NativeAdapterGetFormatCapabilities;
        procs.adapterGetInfo = NativeAdapterGetInfo;
        procs.adapterGetInstance = NativeAdapterGetInstance;
        procs.adapterGetLimits = NativeAdapterGetLimits;
        procs.adapterGetProperties = NativeAdapterGetProperties;
        procs.adapterHasFeature = NativeAdapterHasFeature;
        procs.adapterRequestDevice = NativeAdapterRequestDevice;
        procs.adapterRequestDevice2 = NativeAdapterRequestDevice2;
        procs.adapterRequestDeviceF = NativeAdapterRequestDeviceF;
        procs.adapterAddRef = NativeAdapterAddRef;
        procs.adapterRelease = NativeAdapterRelease;
        procs.bindGroupSetLabel = NativeBindGroupSetLabel;
        procs.bindGroupAddRef = NativeBindGroupAddRef;
        procs.bindGroupRelease = NativeBindGroupRelease;
        procs.bindGroupLayoutSetLabel = NativeBindGroupLayoutSetLabel;
        procs.bindGroupLayoutAddRef = NativeBindGroupLayoutAddRef;
        procs.bindGroupLayoutRelease = NativeBindGroupLayoutRelease;
        procs.bufferDestroy = NativeBufferDestroy;
        procs.bufferGetConstMappedRange = NativeBufferGetConstMappedRange;
        procs.bufferGetMapState = NativeBufferGetMapState;
        procs.bufferGetMappedRange = NativeBufferGetMappedRange;
        procs.bufferGetSize = NativeBufferGetSize;
        procs.bufferGetUsage = NativeBufferGetUsage;
        procs.bufferMapAsync = NativeBufferMapAsync;
        procs.bufferMapAsyncF = NativeBufferMapAsyncF;
        procs.bufferSetLabel = NativeBufferSetLabel;
        procs.bufferUnmap = NativeBufferUnmap;
        procs.bufferAddRef = NativeBufferAddRef;
        procs.bufferRelease = NativeBufferRelease;
        procs.commandBufferSetLabel = NativeCommandBufferSetLabel;
        procs.commandBufferAddRef = NativeCommandBufferAddRef;
        procs.commandBufferRelease = NativeCommandBufferRelease;
        procs.commandEncoderBeginComputePass = NativeCommandEncoderBeginComputePass;
        procs.commandEncoderBeginRenderPass = NativeCommandEncoderBeginRenderPass;
        procs.commandEncoderClearBuffer = NativeCommandEncoderClearBuffer;
        procs.commandEncoderCopyBufferToBuffer = NativeCommandEncoderCopyBufferToBuffer;
        procs.commandEncoderCopyBufferToTexture = NativeCommandEncoderCopyBufferToTexture;
        procs.commandEncoderCopyTextureToBuffer = NativeCommandEncoderCopyTextureToBuffer;
        procs.commandEncoderCopyTextureToTexture = NativeCommandEncoderCopyTextureToTexture;
        procs.commandEncoderFinish = NativeCommandEncoderFinish;
        procs.commandEncoderInjectValidationError = NativeCommandEncoderInjectValidationError;
        procs.commandEncoderInsertDebugMarker = NativeCommandEncoderInsertDebugMarker;
        procs.commandEncoderPopDebugGroup = NativeCommandEncoderPopDebugGroup;
        procs.commandEncoderPushDebugGroup = NativeCommandEncoderPushDebugGroup;
        procs.commandEncoderResolveQuerySet = NativeCommandEncoderResolveQuerySet;
        procs.commandEncoderSetLabel = NativeCommandEncoderSetLabel;
        procs.commandEncoderWriteBuffer = NativeCommandEncoderWriteBuffer;
        procs.commandEncoderWriteTimestamp = NativeCommandEncoderWriteTimestamp;
        procs.commandEncoderAddRef = NativeCommandEncoderAddRef;
        procs.commandEncoderRelease = NativeCommandEncoderRelease;
        procs.computePassEncoderDispatchWorkgroups = NativeComputePassEncoderDispatchWorkgroups;
        procs.computePassEncoderDispatchWorkgroupsIndirect = NativeComputePassEncoderDispatchWorkgroupsIndirect;
        procs.computePassEncoderEnd = NativeComputePassEncoderEnd;
        procs.computePassEncoderInsertDebugMarker = NativeComputePassEncoderInsertDebugMarker;
        procs.computePassEncoderPopDebugGroup = NativeComputePassEncoderPopDebugGroup;
        procs.computePassEncoderPushDebugGroup = NativeComputePassEncoderPushDebugGroup;
        procs.computePassEncoderSetBindGroup = NativeComputePassEncoderSetBindGroup;
        procs.computePassEncoderSetLabel = NativeComputePassEncoderSetLabel;
        procs.computePassEncoderSetPipeline = NativeComputePassEncoderSetPipeline;
        procs.computePassEncoderWriteTimestamp = NativeComputePassEncoderWriteTimestamp;
        procs.computePassEncoderAddRef = NativeComputePassEncoderAddRef;
        procs.computePassEncoderRelease = NativeComputePassEncoderRelease;
        procs.computePipelineGetBindGroupLayout = NativeComputePipelineGetBindGroupLayout;
        procs.computePipelineSetLabel = NativeComputePipelineSetLabel;
        procs.computePipelineAddRef = NativeComputePipelineAddRef;
        procs.computePipelineRelease = NativeComputePipelineRelease;
        procs.deviceCreateBindGroup = NativeDeviceCreateBindGroup;
        procs.deviceCreateBindGroupLayout = NativeDeviceCreateBindGroupLayout;
        procs.deviceCreateBuffer = NativeDeviceCreateBuffer;
        procs.deviceCreateCommandEncoder = NativeDeviceCreateCommandEncoder;
        procs.deviceCreateComputePipeline = NativeDeviceCreateComputePipeline;
        procs.deviceCreateComputePipelineAsync = NativeDeviceCreateComputePipelineAsync;
        procs.deviceCreateComputePipelineAsync2 = NativeDeviceCreateComputePipelineAsync2;
        procs.deviceCreateComputePipelineAsyncF = NativeDeviceCreateComputePipelineAsyncF;
        procs.deviceCreateErrorBuffer = NativeDeviceCreateErrorBuffer;
        procs.deviceCreateErrorExternalTexture = NativeDeviceCreateErrorExternalTexture;
        procs.deviceCreateErrorShaderModule = NativeDeviceCreateErrorShaderModule;
        procs.deviceCreateErrorTexture = NativeDeviceCreateErrorTexture;
        procs.deviceCreateExternalTexture = NativeDeviceCreateExternalTexture;
        procs.deviceCreatePipelineLayout = NativeDeviceCreatePipelineLayout;
        procs.deviceCreateQuerySet = NativeDeviceCreateQuerySet;
        procs.deviceCreateRenderBundleEncoder = NativeDeviceCreateRenderBundleEncoder;
        procs.deviceCreateRenderPipeline = NativeDeviceCreateRenderPipeline;
        procs.deviceCreateRenderPipelineAsync = NativeDeviceCreateRenderPipelineAsync;
        procs.deviceCreateRenderPipelineAsync2 = NativeDeviceCreateRenderPipelineAsync2;
        procs.deviceCreateRenderPipelineAsyncF = NativeDeviceCreateRenderPipelineAsyncF;
        procs.deviceCreateSampler = NativeDeviceCreateSampler;
        procs.deviceCreateShaderModule = NativeDeviceCreateShaderModule;
        procs.deviceCreateSwapChain = NativeDeviceCreateSwapChain;
        procs.deviceCreateTexture = NativeDeviceCreateTexture;
        procs.deviceDestroy = NativeDeviceDestroy;
        procs.deviceEnumerateFeatures = NativeDeviceEnumerateFeatures;
        procs.deviceForceLoss = NativeDeviceForceLoss;
        procs.deviceGetAHardwareBufferProperties = NativeDeviceGetAHardwareBufferProperties;
        procs.deviceGetAdapter = NativeDeviceGetAdapter;
        procs.deviceGetLimits = NativeDeviceGetLimits;
        procs.deviceGetQueue = NativeDeviceGetQueue;
        procs.deviceGetSupportedSurfaceUsage = NativeDeviceGetSupportedSurfaceUsage;
        procs.deviceHasFeature = NativeDeviceHasFeature;
        procs.deviceImportSharedBufferMemory = NativeDeviceImportSharedBufferMemory;
        procs.deviceImportSharedFence = NativeDeviceImportSharedFence;
        procs.deviceImportSharedTextureMemory = NativeDeviceImportSharedTextureMemory;
        procs.deviceInjectError = NativeDeviceInjectError;
        procs.devicePopErrorScope = NativeDevicePopErrorScope;
        procs.devicePopErrorScope2 = NativeDevicePopErrorScope2;
        procs.devicePopErrorScopeF = NativeDevicePopErrorScopeF;
        procs.devicePushErrorScope = NativeDevicePushErrorScope;
        procs.deviceSetDeviceLostCallback = NativeDeviceSetDeviceLostCallback;
        procs.deviceSetLabel = NativeDeviceSetLabel;
        procs.deviceSetLoggingCallback = NativeDeviceSetLoggingCallback;
        procs.deviceSetUncapturedErrorCallback = NativeDeviceSetUncapturedErrorCallback;
        procs.deviceTick = NativeDeviceTick;
        procs.deviceValidateTextureDescriptor = NativeDeviceValidateTextureDescriptor;
        procs.deviceAddRef = NativeDeviceAddRef;
        procs.deviceRelease = NativeDeviceRelease;
        procs.externalTextureDestroy = NativeExternalTextureDestroy;
        procs.externalTextureExpire = NativeExternalTextureExpire;
        procs.externalTextureRefresh = NativeExternalTextureRefresh;
        procs.externalTextureSetLabel = NativeExternalTextureSetLabel;
        procs.externalTextureAddRef = NativeExternalTextureAddRef;
        procs.externalTextureRelease = NativeExternalTextureRelease;
        procs.instanceCreateSurface = NativeInstanceCreateSurface;
        procs.instanceEnumerateWGSLLanguageFeatures = NativeInstanceEnumerateWGSLLanguageFeatures;
        procs.instanceHasWGSLLanguageFeature = NativeInstanceHasWGSLLanguageFeature;
        procs.instanceProcessEvents = NativeInstanceProcessEvents;
        procs.instanceRequestAdapter = NativeInstanceRequestAdapter;
        procs.instanceRequestAdapter2 = NativeInstanceRequestAdapter2;
        procs.instanceRequestAdapterF = NativeInstanceRequestAdapterF;
        procs.instanceWaitAny = NativeInstanceWaitAny;
        procs.instanceAddRef = NativeInstanceAddRef;
        procs.instanceRelease = NativeInstanceRelease;
        procs.pipelineLayoutSetLabel = NativePipelineLayoutSetLabel;
        procs.pipelineLayoutAddRef = NativePipelineLayoutAddRef;
        procs.pipelineLayoutRelease = NativePipelineLayoutRelease;
        procs.querySetDestroy = NativeQuerySetDestroy;
        procs.querySetGetCount = NativeQuerySetGetCount;
        procs.querySetGetType = NativeQuerySetGetType;
        procs.querySetSetLabel = NativeQuerySetSetLabel;
        procs.querySetAddRef = NativeQuerySetAddRef;
        procs.querySetRelease = NativeQuerySetRelease;
        procs.queueCopyExternalTextureForBrowser = NativeQueueCopyExternalTextureForBrowser;
        procs.queueCopyTextureForBrowser = NativeQueueCopyTextureForBrowser;
        procs.queueOnSubmittedWorkDone = NativeQueueOnSubmittedWorkDone;
        procs.queueOnSubmittedWorkDone2 = NativeQueueOnSubmittedWorkDone2;
        procs.queueOnSubmittedWorkDoneF = NativeQueueOnSubmittedWorkDoneF;
        procs.queueSetLabel = NativeQueueSetLabel;
        procs.queueSubmit = NativeQueueSubmit;
        procs.queueWriteBuffer = NativeQueueWriteBuffer;
        procs.queueWriteTexture = NativeQueueWriteTexture;
        procs.queueAddRef = NativeQueueAddRef;
        procs.queueRelease = NativeQueueRelease;
        procs.renderBundleSetLabel = NativeRenderBundleSetLabel;
        procs.renderBundleAddRef = NativeRenderBundleAddRef;
        procs.renderBundleRelease = NativeRenderBundleRelease;
        procs.renderBundleEncoderDraw = NativeRenderBundleEncoderDraw;
        procs.renderBundleEncoderDrawIndexed = NativeRenderBundleEncoderDrawIndexed;
        procs.renderBundleEncoderDrawIndexedIndirect = NativeRenderBundleEncoderDrawIndexedIndirect;
        procs.renderBundleEncoderDrawIndirect = NativeRenderBundleEncoderDrawIndirect;
        procs.renderBundleEncoderFinish = NativeRenderBundleEncoderFinish;
        procs.renderBundleEncoderInsertDebugMarker = NativeRenderBundleEncoderInsertDebugMarker;
        procs.renderBundleEncoderPopDebugGroup = NativeRenderBundleEncoderPopDebugGroup;
        procs.renderBundleEncoderPushDebugGroup = NativeRenderBundleEncoderPushDebugGroup;
        procs.renderBundleEncoderSetBindGroup = NativeRenderBundleEncoderSetBindGroup;
        procs.renderBundleEncoderSetIndexBuffer = NativeRenderBundleEncoderSetIndexBuffer;
        procs.renderBundleEncoderSetLabel = NativeRenderBundleEncoderSetLabel;
        procs.renderBundleEncoderSetPipeline = NativeRenderBundleEncoderSetPipeline;
        procs.renderBundleEncoderSetVertexBuffer = NativeRenderBundleEncoderSetVertexBuffer;
        procs.renderBundleEncoderAddRef = NativeRenderBundleEncoderAddRef;
        procs.renderBundleEncoderRelease = NativeRenderBundleEncoderRelease;
        procs.renderPassEncoderBeginOcclusionQuery = NativeRenderPassEncoderBeginOcclusionQuery;
        procs.renderPassEncoderDraw = NativeRenderPassEncoderDraw;
        procs.renderPassEncoderDrawIndexed = NativeRenderPassEncoderDrawIndexed;
        procs.renderPassEncoderDrawIndexedIndirect = NativeRenderPassEncoderDrawIndexedIndirect;
        procs.renderPassEncoderDrawIndirect = NativeRenderPassEncoderDrawIndirect;
        procs.renderPassEncoderEnd = NativeRenderPassEncoderEnd;
        procs.renderPassEncoderEndOcclusionQuery = NativeRenderPassEncoderEndOcclusionQuery;
        procs.renderPassEncoderExecuteBundles = NativeRenderPassEncoderExecuteBundles;
        procs.renderPassEncoderInsertDebugMarker = NativeRenderPassEncoderInsertDebugMarker;
        procs.renderPassEncoderPixelLocalStorageBarrier = NativeRenderPassEncoderPixelLocalStorageBarrier;
        procs.renderPassEncoderPopDebugGroup = NativeRenderPassEncoderPopDebugGroup;
        procs.renderPassEncoderPushDebugGroup = NativeRenderPassEncoderPushDebugGroup;
        procs.renderPassEncoderSetBindGroup = NativeRenderPassEncoderSetBindGroup;
        procs.renderPassEncoderSetBlendConstant = NativeRenderPassEncoderSetBlendConstant;
        procs.renderPassEncoderSetIndexBuffer = NativeRenderPassEncoderSetIndexBuffer;
        procs.renderPassEncoderSetLabel = NativeRenderPassEncoderSetLabel;
        procs.renderPassEncoderSetPipeline = NativeRenderPassEncoderSetPipeline;
        procs.renderPassEncoderSetScissorRect = NativeRenderPassEncoderSetScissorRect;
        procs.renderPassEncoderSetStencilReference = NativeRenderPassEncoderSetStencilReference;
        procs.renderPassEncoderSetVertexBuffer = NativeRenderPassEncoderSetVertexBuffer;
        procs.renderPassEncoderSetViewport = NativeRenderPassEncoderSetViewport;
        procs.renderPassEncoderWriteTimestamp = NativeRenderPassEncoderWriteTimestamp;
        procs.renderPassEncoderAddRef = NativeRenderPassEncoderAddRef;
        procs.renderPassEncoderRelease = NativeRenderPassEncoderRelease;
        procs.renderPipelineGetBindGroupLayout = NativeRenderPipelineGetBindGroupLayout;
        procs.renderPipelineSetLabel = NativeRenderPipelineSetLabel;
        procs.renderPipelineAddRef = NativeRenderPipelineAddRef;
        procs.renderPipelineRelease = NativeRenderPipelineRelease;
        procs.samplerSetLabel = NativeSamplerSetLabel;
        procs.samplerAddRef = NativeSamplerAddRef;
        procs.samplerRelease = NativeSamplerRelease;
        procs.shaderModuleGetCompilationInfo = NativeShaderModuleGetCompilationInfo;
        procs.shaderModuleGetCompilationInfoF = NativeShaderModuleGetCompilationInfoF;
        procs.shaderModuleSetLabel = NativeShaderModuleSetLabel;
        procs.shaderModuleAddRef = NativeShaderModuleAddRef;
        procs.shaderModuleRelease = NativeShaderModuleRelease;
        procs.sharedBufferMemoryBeginAccess = NativeSharedBufferMemoryBeginAccess;
        procs.sharedBufferMemoryCreateBuffer = NativeSharedBufferMemoryCreateBuffer;
        procs.sharedBufferMemoryEndAccess = NativeSharedBufferMemoryEndAccess;
        procs.sharedBufferMemoryGetProperties = NativeSharedBufferMemoryGetProperties;
        procs.sharedBufferMemoryIsDeviceLost = NativeSharedBufferMemoryIsDeviceLost;
        procs.sharedBufferMemorySetLabel = NativeSharedBufferMemorySetLabel;
        procs.sharedBufferMemoryAddRef = NativeSharedBufferMemoryAddRef;
        procs.sharedBufferMemoryRelease = NativeSharedBufferMemoryRelease;
        procs.sharedFenceExportInfo = NativeSharedFenceExportInfo;
        procs.sharedFenceAddRef = NativeSharedFenceAddRef;
        procs.sharedFenceRelease = NativeSharedFenceRelease;
        procs.sharedTextureMemoryBeginAccess = NativeSharedTextureMemoryBeginAccess;
        procs.sharedTextureMemoryCreateTexture = NativeSharedTextureMemoryCreateTexture;
        procs.sharedTextureMemoryEndAccess = NativeSharedTextureMemoryEndAccess;
        procs.sharedTextureMemoryGetProperties = NativeSharedTextureMemoryGetProperties;
        procs.sharedTextureMemoryIsDeviceLost = NativeSharedTextureMemoryIsDeviceLost;
        procs.sharedTextureMemorySetLabel = NativeSharedTextureMemorySetLabel;
        procs.sharedTextureMemoryAddRef = NativeSharedTextureMemoryAddRef;
        procs.sharedTextureMemoryRelease = NativeSharedTextureMemoryRelease;
        procs.surfaceConfigure = NativeSurfaceConfigure;
        procs.surfaceGetCapabilities = NativeSurfaceGetCapabilities;
        procs.surfaceGetCurrentTexture = NativeSurfaceGetCurrentTexture;
        procs.surfaceGetPreferredFormat = NativeSurfaceGetPreferredFormat;
        procs.surfacePresent = NativeSurfacePresent;
        procs.surfaceUnconfigure = NativeSurfaceUnconfigure;
        procs.surfaceAddRef = NativeSurfaceAddRef;
        procs.surfaceRelease = NativeSurfaceRelease;
        procs.swapChainGetCurrentTexture = NativeSwapChainGetCurrentTexture;
        procs.swapChainGetCurrentTextureView = NativeSwapChainGetCurrentTextureView;
        procs.swapChainPresent = NativeSwapChainPresent;
        procs.swapChainAddRef = NativeSwapChainAddRef;
        procs.swapChainRelease = NativeSwapChainRelease;
        procs.textureCreateErrorView = NativeTextureCreateErrorView;
        procs.textureCreateView = NativeTextureCreateView;
        procs.textureDestroy = NativeTextureDestroy;
        procs.textureGetDepthOrArrayLayers = NativeTextureGetDepthOrArrayLayers;
        procs.textureGetDimension = NativeTextureGetDimension;
        procs.textureGetFormat = NativeTextureGetFormat;
        procs.textureGetHeight = NativeTextureGetHeight;
        procs.textureGetMipLevelCount = NativeTextureGetMipLevelCount;
        procs.textureGetSampleCount = NativeTextureGetSampleCount;
        procs.textureGetUsage = NativeTextureGetUsage;
        procs.textureGetWidth = NativeTextureGetWidth;
        procs.textureSetLabel = NativeTextureSetLabel;
        procs.textureAddRef = NativeTextureAddRef;
        procs.textureRelease = NativeTextureRelease;
        procs.textureViewSetLabel = NativeTextureViewSetLabel;
        procs.textureViewAddRef = NativeTextureViewAddRef;
        procs.textureViewRelease = NativeTextureViewRelease;
        return procs;
    }

    static DawnProcTable gProcTable = MakeProcTable();

    const DawnProcTable& GetProcsAutogen() {
        return gProcTable;
    }
}
