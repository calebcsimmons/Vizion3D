// Copyright 2017 The Dawn & Tint Authors
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
#ifndef WEBGPU_CPP_H_
#define WEBGPU_CPP_H_

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <functional>

#include "webgpu/webgpu.h"
#include "webgpu/webgpu_cpp_chained_struct.h"
#include "webgpu/webgpu_enum_class_bitmasks.h"  // IWYU pragma: export

namespace wgpu {

namespace detail {
constexpr size_t ConstexprMax(size_t a, size_t b) {
    return a > b ? a : b;
}

template <typename T>
static T& AsNonConstReference(const T& value) {
    return const_cast<T&>(value);
}
}  // namespace detail

static constexpr uint32_t kArrayLayerCountUndefined = WGPU_ARRAY_LAYER_COUNT_UNDEFINED;
static constexpr uint32_t kCopyStrideUndefined = WGPU_COPY_STRIDE_UNDEFINED;
static constexpr uint32_t kDepthSliceUndefined = WGPU_DEPTH_SLICE_UNDEFINED;
static constexpr uint32_t kLimitU32Undefined = WGPU_LIMIT_U32_UNDEFINED;
static constexpr uint64_t kLimitU64Undefined = WGPU_LIMIT_U64_UNDEFINED;
static constexpr uint32_t kMipLevelCountUndefined = WGPU_MIP_LEVEL_COUNT_UNDEFINED;
static constexpr uint32_t kQuerySetIndexUndefined = WGPU_QUERY_SET_INDEX_UNDEFINED;
static constexpr size_t kWholeMapSize = WGPU_WHOLE_MAP_SIZE;
static constexpr uint64_t kWholeSize = WGPU_WHOLE_SIZE;
enum class WGSLFeatureName : uint32_t {
    Undefined = WGPUWGSLFeatureName_Undefined,
    ReadonlyAndReadwriteStorageTextures = WGPUWGSLFeatureName_ReadonlyAndReadwriteStorageTextures,
    Packed4x8IntegerDotProduct = WGPUWGSLFeatureName_Packed4x8IntegerDotProduct,
    UnrestrictedPointerParameters = WGPUWGSLFeatureName_UnrestrictedPointerParameters,
    PointerCompositeAccess = WGPUWGSLFeatureName_PointerCompositeAccess,
};
static_assert(sizeof(WGSLFeatureName) == sizeof(WGPUWGSLFeatureName), "sizeof mismatch for WGSLFeatureName");
static_assert(alignof(WGSLFeatureName) == alignof(WGPUWGSLFeatureName), "alignof mismatch for WGSLFeatureName");

enum class AdapterType : uint32_t {
    DiscreteGPU = WGPUAdapterType_DiscreteGPU,
    IntegratedGPU = WGPUAdapterType_IntegratedGPU,
    CPU = WGPUAdapterType_CPU,
    Unknown = WGPUAdapterType_Unknown,
};
static_assert(sizeof(AdapterType) == sizeof(WGPUAdapterType), "sizeof mismatch for AdapterType");
static_assert(alignof(AdapterType) == alignof(WGPUAdapterType), "alignof mismatch for AdapterType");

enum class AddressMode : uint32_t {
    Undefined = WGPUAddressMode_Undefined,
    ClampToEdge = WGPUAddressMode_ClampToEdge,
    Repeat = WGPUAddressMode_Repeat,
    MirrorRepeat = WGPUAddressMode_MirrorRepeat,
};
static_assert(sizeof(AddressMode) == sizeof(WGPUAddressMode), "sizeof mismatch for AddressMode");
static_assert(alignof(AddressMode) == alignof(WGPUAddressMode), "alignof mismatch for AddressMode");

enum class BackendType : uint32_t {
    Undefined = WGPUBackendType_Undefined,
    Null = WGPUBackendType_Null,
    WebGPU = WGPUBackendType_WebGPU,
    D3D11 = WGPUBackendType_D3D11,
    D3D12 = WGPUBackendType_D3D12,
    Metal = WGPUBackendType_Metal,
    Vulkan = WGPUBackendType_Vulkan,
    OpenGL = WGPUBackendType_OpenGL,
    OpenGLES = WGPUBackendType_OpenGLES,
};
static_assert(sizeof(BackendType) == sizeof(WGPUBackendType), "sizeof mismatch for BackendType");
static_assert(alignof(BackendType) == alignof(WGPUBackendType), "alignof mismatch for BackendType");

enum class BlendFactor : uint32_t {
    Undefined = WGPUBlendFactor_Undefined,
    Zero = WGPUBlendFactor_Zero,
    One = WGPUBlendFactor_One,
    Src = WGPUBlendFactor_Src,
    OneMinusSrc = WGPUBlendFactor_OneMinusSrc,
    SrcAlpha = WGPUBlendFactor_SrcAlpha,
    OneMinusSrcAlpha = WGPUBlendFactor_OneMinusSrcAlpha,
    Dst = WGPUBlendFactor_Dst,
    OneMinusDst = WGPUBlendFactor_OneMinusDst,
    DstAlpha = WGPUBlendFactor_DstAlpha,
    OneMinusDstAlpha = WGPUBlendFactor_OneMinusDstAlpha,
    SrcAlphaSaturated = WGPUBlendFactor_SrcAlphaSaturated,
    Constant = WGPUBlendFactor_Constant,
    OneMinusConstant = WGPUBlendFactor_OneMinusConstant,
};
static_assert(sizeof(BlendFactor) == sizeof(WGPUBlendFactor), "sizeof mismatch for BlendFactor");
static_assert(alignof(BlendFactor) == alignof(WGPUBlendFactor), "alignof mismatch for BlendFactor");

enum class BlendOperation : uint32_t {
    Undefined = WGPUBlendOperation_Undefined,
    Add = WGPUBlendOperation_Add,
    Subtract = WGPUBlendOperation_Subtract,
    ReverseSubtract = WGPUBlendOperation_ReverseSubtract,
    Min = WGPUBlendOperation_Min,
    Max = WGPUBlendOperation_Max,
};
static_assert(sizeof(BlendOperation) == sizeof(WGPUBlendOperation), "sizeof mismatch for BlendOperation");
static_assert(alignof(BlendOperation) == alignof(WGPUBlendOperation), "alignof mismatch for BlendOperation");

enum class BufferBindingType : uint32_t {
    Undefined = WGPUBufferBindingType_Undefined,
    Uniform = WGPUBufferBindingType_Uniform,
    Storage = WGPUBufferBindingType_Storage,
    ReadOnlyStorage = WGPUBufferBindingType_ReadOnlyStorage,
};
static_assert(sizeof(BufferBindingType) == sizeof(WGPUBufferBindingType), "sizeof mismatch for BufferBindingType");
static_assert(alignof(BufferBindingType) == alignof(WGPUBufferBindingType), "alignof mismatch for BufferBindingType");

enum class BufferMapAsyncStatus : uint32_t {
    Success = WGPUBufferMapAsyncStatus_Success,
    InstanceDropped = WGPUBufferMapAsyncStatus_InstanceDropped,
    ValidationError = WGPUBufferMapAsyncStatus_ValidationError,
    Unknown = WGPUBufferMapAsyncStatus_Unknown,
    DeviceLost = WGPUBufferMapAsyncStatus_DeviceLost,
    DestroyedBeforeCallback = WGPUBufferMapAsyncStatus_DestroyedBeforeCallback,
    UnmappedBeforeCallback = WGPUBufferMapAsyncStatus_UnmappedBeforeCallback,
    MappingAlreadyPending = WGPUBufferMapAsyncStatus_MappingAlreadyPending,
    OffsetOutOfRange = WGPUBufferMapAsyncStatus_OffsetOutOfRange,
    SizeOutOfRange = WGPUBufferMapAsyncStatus_SizeOutOfRange,
};
static_assert(sizeof(BufferMapAsyncStatus) == sizeof(WGPUBufferMapAsyncStatus), "sizeof mismatch for BufferMapAsyncStatus");
static_assert(alignof(BufferMapAsyncStatus) == alignof(WGPUBufferMapAsyncStatus), "alignof mismatch for BufferMapAsyncStatus");

enum class BufferMapState : uint32_t {
    Unmapped = WGPUBufferMapState_Unmapped,
    Pending = WGPUBufferMapState_Pending,
    Mapped = WGPUBufferMapState_Mapped,
};
static_assert(sizeof(BufferMapState) == sizeof(WGPUBufferMapState), "sizeof mismatch for BufferMapState");
static_assert(alignof(BufferMapState) == alignof(WGPUBufferMapState), "alignof mismatch for BufferMapState");

enum class CallbackMode : uint32_t {
    WaitAnyOnly = WGPUCallbackMode_WaitAnyOnly,
    AllowProcessEvents = WGPUCallbackMode_AllowProcessEvents,
    AllowSpontaneous = WGPUCallbackMode_AllowSpontaneous,
};
static_assert(sizeof(CallbackMode) == sizeof(WGPUCallbackMode), "sizeof mismatch for CallbackMode");
static_assert(alignof(CallbackMode) == alignof(WGPUCallbackMode), "alignof mismatch for CallbackMode");

enum class CompareFunction : uint32_t {
    Undefined = WGPUCompareFunction_Undefined,
    Never = WGPUCompareFunction_Never,
    Less = WGPUCompareFunction_Less,
    Equal = WGPUCompareFunction_Equal,
    LessEqual = WGPUCompareFunction_LessEqual,
    Greater = WGPUCompareFunction_Greater,
    NotEqual = WGPUCompareFunction_NotEqual,
    GreaterEqual = WGPUCompareFunction_GreaterEqual,
    Always = WGPUCompareFunction_Always,
};
static_assert(sizeof(CompareFunction) == sizeof(WGPUCompareFunction), "sizeof mismatch for CompareFunction");
static_assert(alignof(CompareFunction) == alignof(WGPUCompareFunction), "alignof mismatch for CompareFunction");

enum class CompilationInfoRequestStatus : uint32_t {
    Success = WGPUCompilationInfoRequestStatus_Success,
    InstanceDropped = WGPUCompilationInfoRequestStatus_InstanceDropped,
    Error = WGPUCompilationInfoRequestStatus_Error,
    DeviceLost = WGPUCompilationInfoRequestStatus_DeviceLost,
    Unknown = WGPUCompilationInfoRequestStatus_Unknown,
};
static_assert(sizeof(CompilationInfoRequestStatus) == sizeof(WGPUCompilationInfoRequestStatus), "sizeof mismatch for CompilationInfoRequestStatus");
static_assert(alignof(CompilationInfoRequestStatus) == alignof(WGPUCompilationInfoRequestStatus), "alignof mismatch for CompilationInfoRequestStatus");

enum class CompilationMessageType : uint32_t {
    Error = WGPUCompilationMessageType_Error,
    Warning = WGPUCompilationMessageType_Warning,
    Info = WGPUCompilationMessageType_Info,
};
static_assert(sizeof(CompilationMessageType) == sizeof(WGPUCompilationMessageType), "sizeof mismatch for CompilationMessageType");
static_assert(alignof(CompilationMessageType) == alignof(WGPUCompilationMessageType), "alignof mismatch for CompilationMessageType");

enum class CompositeAlphaMode : uint32_t {
    Auto = WGPUCompositeAlphaMode_Auto,
    Opaque = WGPUCompositeAlphaMode_Opaque,
    Premultiplied = WGPUCompositeAlphaMode_Premultiplied,
    Unpremultiplied = WGPUCompositeAlphaMode_Unpremultiplied,
    Inherit = WGPUCompositeAlphaMode_Inherit,
};
static_assert(sizeof(CompositeAlphaMode) == sizeof(WGPUCompositeAlphaMode), "sizeof mismatch for CompositeAlphaMode");
static_assert(alignof(CompositeAlphaMode) == alignof(WGPUCompositeAlphaMode), "alignof mismatch for CompositeAlphaMode");

enum class CreatePipelineAsyncStatus : uint32_t {
    Success = WGPUCreatePipelineAsyncStatus_Success,
    InstanceDropped = WGPUCreatePipelineAsyncStatus_InstanceDropped,
    ValidationError = WGPUCreatePipelineAsyncStatus_ValidationError,
    InternalError = WGPUCreatePipelineAsyncStatus_InternalError,
    DeviceLost = WGPUCreatePipelineAsyncStatus_DeviceLost,
    DeviceDestroyed = WGPUCreatePipelineAsyncStatus_DeviceDestroyed,
    Unknown = WGPUCreatePipelineAsyncStatus_Unknown,
};
static_assert(sizeof(CreatePipelineAsyncStatus) == sizeof(WGPUCreatePipelineAsyncStatus), "sizeof mismatch for CreatePipelineAsyncStatus");
static_assert(alignof(CreatePipelineAsyncStatus) == alignof(WGPUCreatePipelineAsyncStatus), "alignof mismatch for CreatePipelineAsyncStatus");

enum class CullMode : uint32_t {
    Undefined = WGPUCullMode_Undefined,
    None = WGPUCullMode_None,
    Front = WGPUCullMode_Front,
    Back = WGPUCullMode_Back,
};
static_assert(sizeof(CullMode) == sizeof(WGPUCullMode), "sizeof mismatch for CullMode");
static_assert(alignof(CullMode) == alignof(WGPUCullMode), "alignof mismatch for CullMode");

enum class DeviceLostReason : uint32_t {
    Unknown = WGPUDeviceLostReason_Unknown,
    Destroyed = WGPUDeviceLostReason_Destroyed,
    InstanceDropped = WGPUDeviceLostReason_InstanceDropped,
    FailedCreation = WGPUDeviceLostReason_FailedCreation,
};
static_assert(sizeof(DeviceLostReason) == sizeof(WGPUDeviceLostReason), "sizeof mismatch for DeviceLostReason");
static_assert(alignof(DeviceLostReason) == alignof(WGPUDeviceLostReason), "alignof mismatch for DeviceLostReason");

enum class ErrorFilter : uint32_t {
    Validation = WGPUErrorFilter_Validation,
    OutOfMemory = WGPUErrorFilter_OutOfMemory,
    Internal = WGPUErrorFilter_Internal,
};
static_assert(sizeof(ErrorFilter) == sizeof(WGPUErrorFilter), "sizeof mismatch for ErrorFilter");
static_assert(alignof(ErrorFilter) == alignof(WGPUErrorFilter), "alignof mismatch for ErrorFilter");

enum class ErrorType : uint32_t {
    NoError = WGPUErrorType_NoError,
    Validation = WGPUErrorType_Validation,
    OutOfMemory = WGPUErrorType_OutOfMemory,
    Internal = WGPUErrorType_Internal,
    Unknown = WGPUErrorType_Unknown,
    DeviceLost = WGPUErrorType_DeviceLost,
};
static_assert(sizeof(ErrorType) == sizeof(WGPUErrorType), "sizeof mismatch for ErrorType");
static_assert(alignof(ErrorType) == alignof(WGPUErrorType), "alignof mismatch for ErrorType");

enum class FeatureName : uint32_t {
    Undefined = WGPUFeatureName_Undefined,
    DepthClipControl = WGPUFeatureName_DepthClipControl,
    Depth32FloatStencil8 = WGPUFeatureName_Depth32FloatStencil8,
    TimestampQuery = WGPUFeatureName_TimestampQuery,
    TextureCompressionBC = WGPUFeatureName_TextureCompressionBC,
    TextureCompressionETC2 = WGPUFeatureName_TextureCompressionETC2,
    TextureCompressionASTC = WGPUFeatureName_TextureCompressionASTC,
    IndirectFirstInstance = WGPUFeatureName_IndirectFirstInstance,
    ShaderF16 = WGPUFeatureName_ShaderF16,
    RG11B10UfloatRenderable = WGPUFeatureName_RG11B10UfloatRenderable,
    BGRA8UnormStorage = WGPUFeatureName_BGRA8UnormStorage,
    Float32Filterable = WGPUFeatureName_Float32Filterable,
};
static_assert(sizeof(FeatureName) == sizeof(WGPUFeatureName), "sizeof mismatch for FeatureName");
static_assert(alignof(FeatureName) == alignof(WGPUFeatureName), "alignof mismatch for FeatureName");

enum class FilterMode : uint32_t {
    Undefined = WGPUFilterMode_Undefined,
    Nearest = WGPUFilterMode_Nearest,
    Linear = WGPUFilterMode_Linear,
};
static_assert(sizeof(FilterMode) == sizeof(WGPUFilterMode), "sizeof mismatch for FilterMode");
static_assert(alignof(FilterMode) == alignof(WGPUFilterMode), "alignof mismatch for FilterMode");

enum class FrontFace : uint32_t {
    Undefined = WGPUFrontFace_Undefined,
    CCW = WGPUFrontFace_CCW,
    CW = WGPUFrontFace_CW,
};
static_assert(sizeof(FrontFace) == sizeof(WGPUFrontFace), "sizeof mismatch for FrontFace");
static_assert(alignof(FrontFace) == alignof(WGPUFrontFace), "alignof mismatch for FrontFace");

enum class IndexFormat : uint32_t {
    Undefined = WGPUIndexFormat_Undefined,
    Uint16 = WGPUIndexFormat_Uint16,
    Uint32 = WGPUIndexFormat_Uint32,
};
static_assert(sizeof(IndexFormat) == sizeof(WGPUIndexFormat), "sizeof mismatch for IndexFormat");
static_assert(alignof(IndexFormat) == alignof(WGPUIndexFormat), "alignof mismatch for IndexFormat");

enum class LoadOp : uint32_t {
    Undefined = WGPULoadOp_Undefined,
    Clear = WGPULoadOp_Clear,
    Load = WGPULoadOp_Load,
};
static_assert(sizeof(LoadOp) == sizeof(WGPULoadOp), "sizeof mismatch for LoadOp");
static_assert(alignof(LoadOp) == alignof(WGPULoadOp), "alignof mismatch for LoadOp");

enum class MipmapFilterMode : uint32_t {
    Undefined = WGPUMipmapFilterMode_Undefined,
    Nearest = WGPUMipmapFilterMode_Nearest,
    Linear = WGPUMipmapFilterMode_Linear,
};
static_assert(sizeof(MipmapFilterMode) == sizeof(WGPUMipmapFilterMode), "sizeof mismatch for MipmapFilterMode");
static_assert(alignof(MipmapFilterMode) == alignof(WGPUMipmapFilterMode), "alignof mismatch for MipmapFilterMode");

enum class PopErrorScopeStatus : uint32_t {
    Success = WGPUPopErrorScopeStatus_Success,
    InstanceDropped = WGPUPopErrorScopeStatus_InstanceDropped,
};
static_assert(sizeof(PopErrorScopeStatus) == sizeof(WGPUPopErrorScopeStatus), "sizeof mismatch for PopErrorScopeStatus");
static_assert(alignof(PopErrorScopeStatus) == alignof(WGPUPopErrorScopeStatus), "alignof mismatch for PopErrorScopeStatus");

enum class PowerPreference : uint32_t {
    Undefined = WGPUPowerPreference_Undefined,
    LowPower = WGPUPowerPreference_LowPower,
    HighPerformance = WGPUPowerPreference_HighPerformance,
};
static_assert(sizeof(PowerPreference) == sizeof(WGPUPowerPreference), "sizeof mismatch for PowerPreference");
static_assert(alignof(PowerPreference) == alignof(WGPUPowerPreference), "alignof mismatch for PowerPreference");

enum class PresentMode : uint32_t {
    Fifo = WGPUPresentMode_Fifo,
    FifoRelaxed = WGPUPresentMode_FifoRelaxed,
    Immediate = WGPUPresentMode_Immediate,
    Mailbox = WGPUPresentMode_Mailbox,
};
static_assert(sizeof(PresentMode) == sizeof(WGPUPresentMode), "sizeof mismatch for PresentMode");
static_assert(alignof(PresentMode) == alignof(WGPUPresentMode), "alignof mismatch for PresentMode");

enum class PrimitiveTopology : uint32_t {
    Undefined = WGPUPrimitiveTopology_Undefined,
    PointList = WGPUPrimitiveTopology_PointList,
    LineList = WGPUPrimitiveTopology_LineList,
    LineStrip = WGPUPrimitiveTopology_LineStrip,
    TriangleList = WGPUPrimitiveTopology_TriangleList,
    TriangleStrip = WGPUPrimitiveTopology_TriangleStrip,
};
static_assert(sizeof(PrimitiveTopology) == sizeof(WGPUPrimitiveTopology), "sizeof mismatch for PrimitiveTopology");
static_assert(alignof(PrimitiveTopology) == alignof(WGPUPrimitiveTopology), "alignof mismatch for PrimitiveTopology");

enum class QueryType : uint32_t {
    Occlusion = WGPUQueryType_Occlusion,
    Timestamp = WGPUQueryType_Timestamp,
};
static_assert(sizeof(QueryType) == sizeof(WGPUQueryType), "sizeof mismatch for QueryType");
static_assert(alignof(QueryType) == alignof(WGPUQueryType), "alignof mismatch for QueryType");

enum class QueueWorkDoneStatus : uint32_t {
    Success = WGPUQueueWorkDoneStatus_Success,
    InstanceDropped = WGPUQueueWorkDoneStatus_InstanceDropped,
    Error = WGPUQueueWorkDoneStatus_Error,
    Unknown = WGPUQueueWorkDoneStatus_Unknown,
    DeviceLost = WGPUQueueWorkDoneStatus_DeviceLost,
};
static_assert(sizeof(QueueWorkDoneStatus) == sizeof(WGPUQueueWorkDoneStatus), "sizeof mismatch for QueueWorkDoneStatus");
static_assert(alignof(QueueWorkDoneStatus) == alignof(WGPUQueueWorkDoneStatus), "alignof mismatch for QueueWorkDoneStatus");

enum class RequestAdapterStatus : uint32_t {
    Success = WGPURequestAdapterStatus_Success,
    InstanceDropped = WGPURequestAdapterStatus_InstanceDropped,
    Unavailable = WGPURequestAdapterStatus_Unavailable,
    Error = WGPURequestAdapterStatus_Error,
    Unknown = WGPURequestAdapterStatus_Unknown,
};
static_assert(sizeof(RequestAdapterStatus) == sizeof(WGPURequestAdapterStatus), "sizeof mismatch for RequestAdapterStatus");
static_assert(alignof(RequestAdapterStatus) == alignof(WGPURequestAdapterStatus), "alignof mismatch for RequestAdapterStatus");

enum class RequestDeviceStatus : uint32_t {
    Success = WGPURequestDeviceStatus_Success,
    InstanceDropped = WGPURequestDeviceStatus_InstanceDropped,
    Error = WGPURequestDeviceStatus_Error,
    Unknown = WGPURequestDeviceStatus_Unknown,
};
static_assert(sizeof(RequestDeviceStatus) == sizeof(WGPURequestDeviceStatus), "sizeof mismatch for RequestDeviceStatus");
static_assert(alignof(RequestDeviceStatus) == alignof(WGPURequestDeviceStatus), "alignof mismatch for RequestDeviceStatus");

enum class SType : uint32_t {
    Invalid = WGPUSType_Invalid,
    SurfaceDescriptorFromCanvasHTMLSelector = WGPUSType_SurfaceDescriptorFromCanvasHTMLSelector,
    ShaderModuleSPIRVDescriptor = WGPUSType_ShaderModuleSPIRVDescriptor,
    ShaderModuleWGSLDescriptor = WGPUSType_ShaderModuleWGSLDescriptor,
    PrimitiveDepthClipControl = WGPUSType_PrimitiveDepthClipControl,
    RenderPassDescriptorMaxDrawCount = WGPUSType_RenderPassDescriptorMaxDrawCount,
    TextureBindingViewDimensionDescriptor = WGPUSType_TextureBindingViewDimensionDescriptor,
};
static_assert(sizeof(SType) == sizeof(WGPUSType), "sizeof mismatch for SType");
static_assert(alignof(SType) == alignof(WGPUSType), "alignof mismatch for SType");

enum class SamplerBindingType : uint32_t {
    Undefined = WGPUSamplerBindingType_Undefined,
    Filtering = WGPUSamplerBindingType_Filtering,
    NonFiltering = WGPUSamplerBindingType_NonFiltering,
    Comparison = WGPUSamplerBindingType_Comparison,
};
static_assert(sizeof(SamplerBindingType) == sizeof(WGPUSamplerBindingType), "sizeof mismatch for SamplerBindingType");
static_assert(alignof(SamplerBindingType) == alignof(WGPUSamplerBindingType), "alignof mismatch for SamplerBindingType");

enum class Status : uint32_t {
    Success = WGPUStatus_Success,
    Error = WGPUStatus_Error,
};
static_assert(sizeof(Status) == sizeof(WGPUStatus), "sizeof mismatch for Status");
static_assert(alignof(Status) == alignof(WGPUStatus), "alignof mismatch for Status");

enum class StencilOperation : uint32_t {
    Undefined = WGPUStencilOperation_Undefined,
    Keep = WGPUStencilOperation_Keep,
    Zero = WGPUStencilOperation_Zero,
    Replace = WGPUStencilOperation_Replace,
    Invert = WGPUStencilOperation_Invert,
    IncrementClamp = WGPUStencilOperation_IncrementClamp,
    DecrementClamp = WGPUStencilOperation_DecrementClamp,
    IncrementWrap = WGPUStencilOperation_IncrementWrap,
    DecrementWrap = WGPUStencilOperation_DecrementWrap,
};
static_assert(sizeof(StencilOperation) == sizeof(WGPUStencilOperation), "sizeof mismatch for StencilOperation");
static_assert(alignof(StencilOperation) == alignof(WGPUStencilOperation), "alignof mismatch for StencilOperation");

enum class StorageTextureAccess : uint32_t {
    Undefined = WGPUStorageTextureAccess_Undefined,
    WriteOnly = WGPUStorageTextureAccess_WriteOnly,
    ReadOnly = WGPUStorageTextureAccess_ReadOnly,
    ReadWrite = WGPUStorageTextureAccess_ReadWrite,
};
static_assert(sizeof(StorageTextureAccess) == sizeof(WGPUStorageTextureAccess), "sizeof mismatch for StorageTextureAccess");
static_assert(alignof(StorageTextureAccess) == alignof(WGPUStorageTextureAccess), "alignof mismatch for StorageTextureAccess");

enum class StoreOp : uint32_t {
    Undefined = WGPUStoreOp_Undefined,
    Store = WGPUStoreOp_Store,
    Discard = WGPUStoreOp_Discard,
};
static_assert(sizeof(StoreOp) == sizeof(WGPUStoreOp), "sizeof mismatch for StoreOp");
static_assert(alignof(StoreOp) == alignof(WGPUStoreOp), "alignof mismatch for StoreOp");

enum class SurfaceGetCurrentTextureStatus : uint32_t {
    Success = WGPUSurfaceGetCurrentTextureStatus_Success,
    Timeout = WGPUSurfaceGetCurrentTextureStatus_Timeout,
    Outdated = WGPUSurfaceGetCurrentTextureStatus_Outdated,
    Lost = WGPUSurfaceGetCurrentTextureStatus_Lost,
    OutOfMemory = WGPUSurfaceGetCurrentTextureStatus_OutOfMemory,
    DeviceLost = WGPUSurfaceGetCurrentTextureStatus_DeviceLost,
};
static_assert(sizeof(SurfaceGetCurrentTextureStatus) == sizeof(WGPUSurfaceGetCurrentTextureStatus), "sizeof mismatch for SurfaceGetCurrentTextureStatus");
static_assert(alignof(SurfaceGetCurrentTextureStatus) == alignof(WGPUSurfaceGetCurrentTextureStatus), "alignof mismatch for SurfaceGetCurrentTextureStatus");

enum class TextureAspect : uint32_t {
    Undefined = WGPUTextureAspect_Undefined,
    All = WGPUTextureAspect_All,
    StencilOnly = WGPUTextureAspect_StencilOnly,
    DepthOnly = WGPUTextureAspect_DepthOnly,
};
static_assert(sizeof(TextureAspect) == sizeof(WGPUTextureAspect), "sizeof mismatch for TextureAspect");
static_assert(alignof(TextureAspect) == alignof(WGPUTextureAspect), "alignof mismatch for TextureAspect");

enum class TextureDimension : uint32_t {
    Undefined = WGPUTextureDimension_Undefined,
    e1D = WGPUTextureDimension_1D,
    e2D = WGPUTextureDimension_2D,
    e3D = WGPUTextureDimension_3D,
};
static_assert(sizeof(TextureDimension) == sizeof(WGPUTextureDimension), "sizeof mismatch for TextureDimension");
static_assert(alignof(TextureDimension) == alignof(WGPUTextureDimension), "alignof mismatch for TextureDimension");

enum class TextureFormat : uint32_t {
    Undefined = WGPUTextureFormat_Undefined,
    R8Unorm = WGPUTextureFormat_R8Unorm,
    R8Snorm = WGPUTextureFormat_R8Snorm,
    R8Uint = WGPUTextureFormat_R8Uint,
    R8Sint = WGPUTextureFormat_R8Sint,
    R16Uint = WGPUTextureFormat_R16Uint,
    R16Sint = WGPUTextureFormat_R16Sint,
    R16Float = WGPUTextureFormat_R16Float,
    RG8Unorm = WGPUTextureFormat_RG8Unorm,
    RG8Snorm = WGPUTextureFormat_RG8Snorm,
    RG8Uint = WGPUTextureFormat_RG8Uint,
    RG8Sint = WGPUTextureFormat_RG8Sint,
    R32Float = WGPUTextureFormat_R32Float,
    R32Uint = WGPUTextureFormat_R32Uint,
    R32Sint = WGPUTextureFormat_R32Sint,
    RG16Uint = WGPUTextureFormat_RG16Uint,
    RG16Sint = WGPUTextureFormat_RG16Sint,
    RG16Float = WGPUTextureFormat_RG16Float,
    RGBA8Unorm = WGPUTextureFormat_RGBA8Unorm,
    RGBA8UnormSrgb = WGPUTextureFormat_RGBA8UnormSrgb,
    RGBA8Snorm = WGPUTextureFormat_RGBA8Snorm,
    RGBA8Uint = WGPUTextureFormat_RGBA8Uint,
    RGBA8Sint = WGPUTextureFormat_RGBA8Sint,
    BGRA8Unorm = WGPUTextureFormat_BGRA8Unorm,
    BGRA8UnormSrgb = WGPUTextureFormat_BGRA8UnormSrgb,
    RGB10A2Uint = WGPUTextureFormat_RGB10A2Uint,
    RGB10A2Unorm = WGPUTextureFormat_RGB10A2Unorm,
    RG11B10Ufloat = WGPUTextureFormat_RG11B10Ufloat,
    RGB9E5Ufloat = WGPUTextureFormat_RGB9E5Ufloat,
    RG32Float = WGPUTextureFormat_RG32Float,
    RG32Uint = WGPUTextureFormat_RG32Uint,
    RG32Sint = WGPUTextureFormat_RG32Sint,
    RGBA16Uint = WGPUTextureFormat_RGBA16Uint,
    RGBA16Sint = WGPUTextureFormat_RGBA16Sint,
    RGBA16Float = WGPUTextureFormat_RGBA16Float,
    RGBA32Float = WGPUTextureFormat_RGBA32Float,
    RGBA32Uint = WGPUTextureFormat_RGBA32Uint,
    RGBA32Sint = WGPUTextureFormat_RGBA32Sint,
    Stencil8 = WGPUTextureFormat_Stencil8,
    Depth16Unorm = WGPUTextureFormat_Depth16Unorm,
    Depth24Plus = WGPUTextureFormat_Depth24Plus,
    Depth24PlusStencil8 = WGPUTextureFormat_Depth24PlusStencil8,
    Depth32Float = WGPUTextureFormat_Depth32Float,
    Depth32FloatStencil8 = WGPUTextureFormat_Depth32FloatStencil8,
    BC1RGBAUnorm = WGPUTextureFormat_BC1RGBAUnorm,
    BC1RGBAUnormSrgb = WGPUTextureFormat_BC1RGBAUnormSrgb,
    BC2RGBAUnorm = WGPUTextureFormat_BC2RGBAUnorm,
    BC2RGBAUnormSrgb = WGPUTextureFormat_BC2RGBAUnormSrgb,
    BC3RGBAUnorm = WGPUTextureFormat_BC3RGBAUnorm,
    BC3RGBAUnormSrgb = WGPUTextureFormat_BC3RGBAUnormSrgb,
    BC4RUnorm = WGPUTextureFormat_BC4RUnorm,
    BC4RSnorm = WGPUTextureFormat_BC4RSnorm,
    BC5RGUnorm = WGPUTextureFormat_BC5RGUnorm,
    BC5RGSnorm = WGPUTextureFormat_BC5RGSnorm,
    BC6HRGBUfloat = WGPUTextureFormat_BC6HRGBUfloat,
    BC6HRGBFloat = WGPUTextureFormat_BC6HRGBFloat,
    BC7RGBAUnorm = WGPUTextureFormat_BC7RGBAUnorm,
    BC7RGBAUnormSrgb = WGPUTextureFormat_BC7RGBAUnormSrgb,
    ETC2RGB8Unorm = WGPUTextureFormat_ETC2RGB8Unorm,
    ETC2RGB8UnormSrgb = WGPUTextureFormat_ETC2RGB8UnormSrgb,
    ETC2RGB8A1Unorm = WGPUTextureFormat_ETC2RGB8A1Unorm,
    ETC2RGB8A1UnormSrgb = WGPUTextureFormat_ETC2RGB8A1UnormSrgb,
    ETC2RGBA8Unorm = WGPUTextureFormat_ETC2RGBA8Unorm,
    ETC2RGBA8UnormSrgb = WGPUTextureFormat_ETC2RGBA8UnormSrgb,
    EACR11Unorm = WGPUTextureFormat_EACR11Unorm,
    EACR11Snorm = WGPUTextureFormat_EACR11Snorm,
    EACRG11Unorm = WGPUTextureFormat_EACRG11Unorm,
    EACRG11Snorm = WGPUTextureFormat_EACRG11Snorm,
    ASTC4x4Unorm = WGPUTextureFormat_ASTC4x4Unorm,
    ASTC4x4UnormSrgb = WGPUTextureFormat_ASTC4x4UnormSrgb,
    ASTC5x4Unorm = WGPUTextureFormat_ASTC5x4Unorm,
    ASTC5x4UnormSrgb = WGPUTextureFormat_ASTC5x4UnormSrgb,
    ASTC5x5Unorm = WGPUTextureFormat_ASTC5x5Unorm,
    ASTC5x5UnormSrgb = WGPUTextureFormat_ASTC5x5UnormSrgb,
    ASTC6x5Unorm = WGPUTextureFormat_ASTC6x5Unorm,
    ASTC6x5UnormSrgb = WGPUTextureFormat_ASTC6x5UnormSrgb,
    ASTC6x6Unorm = WGPUTextureFormat_ASTC6x6Unorm,
    ASTC6x6UnormSrgb = WGPUTextureFormat_ASTC6x6UnormSrgb,
    ASTC8x5Unorm = WGPUTextureFormat_ASTC8x5Unorm,
    ASTC8x5UnormSrgb = WGPUTextureFormat_ASTC8x5UnormSrgb,
    ASTC8x6Unorm = WGPUTextureFormat_ASTC8x6Unorm,
    ASTC8x6UnormSrgb = WGPUTextureFormat_ASTC8x6UnormSrgb,
    ASTC8x8Unorm = WGPUTextureFormat_ASTC8x8Unorm,
    ASTC8x8UnormSrgb = WGPUTextureFormat_ASTC8x8UnormSrgb,
    ASTC10x5Unorm = WGPUTextureFormat_ASTC10x5Unorm,
    ASTC10x5UnormSrgb = WGPUTextureFormat_ASTC10x5UnormSrgb,
    ASTC10x6Unorm = WGPUTextureFormat_ASTC10x6Unorm,
    ASTC10x6UnormSrgb = WGPUTextureFormat_ASTC10x6UnormSrgb,
    ASTC10x8Unorm = WGPUTextureFormat_ASTC10x8Unorm,
    ASTC10x8UnormSrgb = WGPUTextureFormat_ASTC10x8UnormSrgb,
    ASTC10x10Unorm = WGPUTextureFormat_ASTC10x10Unorm,
    ASTC10x10UnormSrgb = WGPUTextureFormat_ASTC10x10UnormSrgb,
    ASTC12x10Unorm = WGPUTextureFormat_ASTC12x10Unorm,
    ASTC12x10UnormSrgb = WGPUTextureFormat_ASTC12x10UnormSrgb,
    ASTC12x12Unorm = WGPUTextureFormat_ASTC12x12Unorm,
    ASTC12x12UnormSrgb = WGPUTextureFormat_ASTC12x12UnormSrgb,
};
static_assert(sizeof(TextureFormat) == sizeof(WGPUTextureFormat), "sizeof mismatch for TextureFormat");
static_assert(alignof(TextureFormat) == alignof(WGPUTextureFormat), "alignof mismatch for TextureFormat");

enum class TextureSampleType : uint32_t {
    Undefined = WGPUTextureSampleType_Undefined,
    Float = WGPUTextureSampleType_Float,
    UnfilterableFloat = WGPUTextureSampleType_UnfilterableFloat,
    Depth = WGPUTextureSampleType_Depth,
    Sint = WGPUTextureSampleType_Sint,
    Uint = WGPUTextureSampleType_Uint,
};
static_assert(sizeof(TextureSampleType) == sizeof(WGPUTextureSampleType), "sizeof mismatch for TextureSampleType");
static_assert(alignof(TextureSampleType) == alignof(WGPUTextureSampleType), "alignof mismatch for TextureSampleType");

enum class TextureViewDimension : uint32_t {
    Undefined = WGPUTextureViewDimension_Undefined,
    e1D = WGPUTextureViewDimension_1D,
    e2D = WGPUTextureViewDimension_2D,
    e2DArray = WGPUTextureViewDimension_2DArray,
    Cube = WGPUTextureViewDimension_Cube,
    CubeArray = WGPUTextureViewDimension_CubeArray,
    e3D = WGPUTextureViewDimension_3D,
};
static_assert(sizeof(TextureViewDimension) == sizeof(WGPUTextureViewDimension), "sizeof mismatch for TextureViewDimension");
static_assert(alignof(TextureViewDimension) == alignof(WGPUTextureViewDimension), "alignof mismatch for TextureViewDimension");

enum class VertexFormat : uint32_t {
    Undefined = WGPUVertexFormat_Undefined,
    Uint8x2 = WGPUVertexFormat_Uint8x2,
    Uint8x4 = WGPUVertexFormat_Uint8x4,
    Sint8x2 = WGPUVertexFormat_Sint8x2,
    Sint8x4 = WGPUVertexFormat_Sint8x4,
    Unorm8x2 = WGPUVertexFormat_Unorm8x2,
    Unorm8x4 = WGPUVertexFormat_Unorm8x4,
    Snorm8x2 = WGPUVertexFormat_Snorm8x2,
    Snorm8x4 = WGPUVertexFormat_Snorm8x4,
    Uint16x2 = WGPUVertexFormat_Uint16x2,
    Uint16x4 = WGPUVertexFormat_Uint16x4,
    Sint16x2 = WGPUVertexFormat_Sint16x2,
    Sint16x4 = WGPUVertexFormat_Sint16x4,
    Unorm16x2 = WGPUVertexFormat_Unorm16x2,
    Unorm16x4 = WGPUVertexFormat_Unorm16x4,
    Snorm16x2 = WGPUVertexFormat_Snorm16x2,
    Snorm16x4 = WGPUVertexFormat_Snorm16x4,
    Float16x2 = WGPUVertexFormat_Float16x2,
    Float16x4 = WGPUVertexFormat_Float16x4,
    Float32 = WGPUVertexFormat_Float32,
    Float32x2 = WGPUVertexFormat_Float32x2,
    Float32x3 = WGPUVertexFormat_Float32x3,
    Float32x4 = WGPUVertexFormat_Float32x4,
    Uint32 = WGPUVertexFormat_Uint32,
    Uint32x2 = WGPUVertexFormat_Uint32x2,
    Uint32x3 = WGPUVertexFormat_Uint32x3,
    Uint32x4 = WGPUVertexFormat_Uint32x4,
    Sint32 = WGPUVertexFormat_Sint32,
    Sint32x2 = WGPUVertexFormat_Sint32x2,
    Sint32x3 = WGPUVertexFormat_Sint32x3,
    Sint32x4 = WGPUVertexFormat_Sint32x4,
    Unorm10_10_10_2 = WGPUVertexFormat_Unorm10_10_10_2,
};
static_assert(sizeof(VertexFormat) == sizeof(WGPUVertexFormat), "sizeof mismatch for VertexFormat");
static_assert(alignof(VertexFormat) == alignof(WGPUVertexFormat), "alignof mismatch for VertexFormat");

enum class VertexStepMode : uint32_t {
    Undefined = WGPUVertexStepMode_Undefined,
    VertexBufferNotUsed = WGPUVertexStepMode_VertexBufferNotUsed,
    Vertex = WGPUVertexStepMode_Vertex,
    Instance = WGPUVertexStepMode_Instance,
};
static_assert(sizeof(VertexStepMode) == sizeof(WGPUVertexStepMode), "sizeof mismatch for VertexStepMode");
static_assert(alignof(VertexStepMode) == alignof(WGPUVertexStepMode), "alignof mismatch for VertexStepMode");

enum class WaitStatus : uint32_t {
    Success = WGPUWaitStatus_Success,
    TimedOut = WGPUWaitStatus_TimedOut,
    UnsupportedTimeout = WGPUWaitStatus_UnsupportedTimeout,
    UnsupportedCount = WGPUWaitStatus_UnsupportedCount,
    UnsupportedMixedSources = WGPUWaitStatus_UnsupportedMixedSources,
    Unknown = WGPUWaitStatus_Unknown,
};
static_assert(sizeof(WaitStatus) == sizeof(WGPUWaitStatus), "sizeof mismatch for WaitStatus");
static_assert(alignof(WaitStatus) == alignof(WGPUWaitStatus), "alignof mismatch for WaitStatus");


enum class BufferUsage : uint32_t {
    None = WGPUBufferUsage_None,
    MapRead = WGPUBufferUsage_MapRead,
    MapWrite = WGPUBufferUsage_MapWrite,
    CopySrc = WGPUBufferUsage_CopySrc,
    CopyDst = WGPUBufferUsage_CopyDst,
    Index = WGPUBufferUsage_Index,
    Vertex = WGPUBufferUsage_Vertex,
    Uniform = WGPUBufferUsage_Uniform,
    Storage = WGPUBufferUsage_Storage,
    Indirect = WGPUBufferUsage_Indirect,
    QueryResolve = WGPUBufferUsage_QueryResolve,
};
static_assert(sizeof(BufferUsage) == sizeof(WGPUBufferUsageFlags), "sizeof mismatch for BufferUsage");
static_assert(alignof(BufferUsage) == alignof(WGPUBufferUsageFlags), "alignof mismatch for BufferUsage");

enum class ColorWriteMask : uint32_t {
    None = WGPUColorWriteMask_None,
    Red = WGPUColorWriteMask_Red,
    Green = WGPUColorWriteMask_Green,
    Blue = WGPUColorWriteMask_Blue,
    Alpha = WGPUColorWriteMask_Alpha,
    All = WGPUColorWriteMask_All,
};
static_assert(sizeof(ColorWriteMask) == sizeof(WGPUColorWriteMaskFlags), "sizeof mismatch for ColorWriteMask");
static_assert(alignof(ColorWriteMask) == alignof(WGPUColorWriteMaskFlags), "alignof mismatch for ColorWriteMask");

enum class MapMode : uint32_t {
    None = WGPUMapMode_None,
    Read = WGPUMapMode_Read,
    Write = WGPUMapMode_Write,
};
static_assert(sizeof(MapMode) == sizeof(WGPUMapModeFlags), "sizeof mismatch for MapMode");
static_assert(alignof(MapMode) == alignof(WGPUMapModeFlags), "alignof mismatch for MapMode");

enum class ShaderStage : uint32_t {
    None = WGPUShaderStage_None,
    Vertex = WGPUShaderStage_Vertex,
    Fragment = WGPUShaderStage_Fragment,
    Compute = WGPUShaderStage_Compute,
};
static_assert(sizeof(ShaderStage) == sizeof(WGPUShaderStageFlags), "sizeof mismatch for ShaderStage");
static_assert(alignof(ShaderStage) == alignof(WGPUShaderStageFlags), "alignof mismatch for ShaderStage");

enum class TextureUsage : uint32_t {
    None = WGPUTextureUsage_None,
    CopySrc = WGPUTextureUsage_CopySrc,
    CopyDst = WGPUTextureUsage_CopyDst,
    TextureBinding = WGPUTextureUsage_TextureBinding,
    StorageBinding = WGPUTextureUsage_StorageBinding,
    RenderAttachment = WGPUTextureUsage_RenderAttachment,
};
static_assert(sizeof(TextureUsage) == sizeof(WGPUTextureUsageFlags), "sizeof mismatch for TextureUsage");
static_assert(alignof(TextureUsage) == alignof(WGPUTextureUsageFlags), "alignof mismatch for TextureUsage");


using BufferMapCallback = WGPUBufferMapCallback;
using CompilationInfoCallback = WGPUCompilationInfoCallback;
using CreateComputePipelineAsyncCallback = WGPUCreateComputePipelineAsyncCallback;
using CreateRenderPipelineAsyncCallback = WGPUCreateRenderPipelineAsyncCallback;
using DeviceLostCallback = WGPUDeviceLostCallback;
using DeviceLostCallbackNew = WGPUDeviceLostCallbackNew;
using ErrorCallback = WGPUErrorCallback;
using PopErrorScopeCallback = WGPUPopErrorScopeCallback;
using Proc = WGPUProc;
using QueueWorkDoneCallback = WGPUQueueWorkDoneCallback;
using RequestAdapterCallback = WGPURequestAdapterCallback;
using RequestDeviceCallback = WGPURequestDeviceCallback;

// Special class for booleans in order to allow implicit conversions.
class Bool {
  public:
    constexpr Bool() = default;
    // NOLINTNEXTLINE(runtime/explicit) allow implicit construction
    constexpr Bool(bool value) : mValue(static_cast<WGPUBool>(value)) {}
    // NOLINTNEXTLINE(runtime/explicit) allow implicit construction
    Bool(WGPUBool value): mValue(value) {}

    constexpr operator bool() const { return static_cast<bool>(mValue); }

  private:
    friend struct std::hash<Bool>;
    // Default to false.
    WGPUBool mValue = static_cast<WGPUBool>(false);
};

// Helper class to wrap Status which allows implicit conversion to bool.
// Used while callers switch to checking the Status enum instead of booleans.
// TODO(crbug.com/42241199): Remove when all callers check the enum.
struct ConvertibleStatus {
    // NOLINTNEXTLINE(runtime/explicit) allow implicit construction
    constexpr ConvertibleStatus(Status status) : status(status) {}
    // NOLINTNEXTLINE(runtime/explicit) allow implicit conversion
    constexpr operator bool() const {
        return status == Status::Success;
    }
    // NOLINTNEXTLINE(runtime/explicit) allow implicit conversion
    constexpr operator Status() const {
        return status;
    }
    Status status;
};

template<typename Derived, typename CType>
class ObjectBase {
  public:
    ObjectBase() = default;
    ObjectBase(CType handle): mHandle(handle) {
        if (mHandle) Derived::WGPUAddRef(mHandle);
    }
    ~ObjectBase() {
        if (mHandle) Derived::WGPURelease(mHandle);
    }

    ObjectBase(ObjectBase const& other)
        : ObjectBase(other.Get()) {
    }
    Derived& operator=(ObjectBase const& other) {
        if (&other != this) {
            if (mHandle) Derived::WGPURelease(mHandle);
            mHandle = other.mHandle;
            if (mHandle) Derived::WGPUAddRef(mHandle);
        }

        return static_cast<Derived&>(*this);
    }

    ObjectBase(ObjectBase&& other) {
        mHandle = other.mHandle;
        other.mHandle = 0;
    }
    Derived& operator=(ObjectBase&& other) {
        if (&other != this) {
            if (mHandle) Derived::WGPURelease(mHandle);
            mHandle = other.mHandle;
            other.mHandle = 0;
        }

        return static_cast<Derived&>(*this);
    }

    ObjectBase(std::nullptr_t) {}
    Derived& operator=(std::nullptr_t) {
        if (mHandle != nullptr) {
            Derived::WGPURelease(mHandle);
            mHandle = nullptr;
        }
        return static_cast<Derived&>(*this);
    }

    bool operator==(std::nullptr_t) const {
        return mHandle == nullptr;
    }
    bool operator!=(std::nullptr_t) const {
        return mHandle != nullptr;
    }

    explicit operator bool() const {
        return mHandle != nullptr;
    }
    CType Get() const {
        return mHandle;
    }
    CType MoveToCHandle() {
        CType result = mHandle;
        mHandle = 0;
        return result;
    }
    static Derived Acquire(CType handle) {
        Derived result;
        result.mHandle = handle;
        return result;
    }

  protected:
    CType mHandle = nullptr;
};






class Adapter;
class BindGroup;
class BindGroupLayout;
class Buffer;
class CommandBuffer;
class CommandEncoder;
class ComputePassEncoder;
class ComputePipeline;
class Device;
class Instance;
class PipelineLayout;
class QuerySet;
class Queue;
class RenderBundle;
class RenderBundleEncoder;
class RenderPassEncoder;
class RenderPipeline;
class Sampler;
class ShaderModule;
class Surface;
class SwapChain;
class Texture;
class TextureView;

struct AdapterInfo;
struct AdapterProperties;
struct BindGroupEntry;
struct BlendComponent;
struct BufferBindingLayout;
struct BufferDescriptor;
struct BufferMapCallbackInfo;
struct Color;
struct CommandBufferDescriptor;
struct CommandEncoderDescriptor;
struct CompilationInfoCallbackInfo;
struct CompilationMessage;
struct ComputePassTimestampWrites;
struct ConstantEntry;
struct CreateComputePipelineAsyncCallbackInfo;
struct CreateRenderPipelineAsyncCallbackInfo;
struct DeviceLostCallbackInfo;
struct Extent3D;
struct Future;
struct InstanceFeatures;
struct Limits;
struct MultisampleState;
struct Origin3D;
struct PipelineLayoutDescriptor;
struct PopErrorScopeCallbackInfo;
struct PrimitiveDepthClipControl;
struct PrimitiveState;
struct QuerySetDescriptor;
struct QueueDescriptor;
struct QueueWorkDoneCallbackInfo;
struct RenderBundleDescriptor;
struct RenderBundleEncoderDescriptor;
struct RenderPassDepthStencilAttachment;
struct RenderPassDescriptorMaxDrawCount;
struct RenderPassTimestampWrites;
struct RequestAdapterCallbackInfo;
struct RequestAdapterOptions;
struct RequestDeviceCallbackInfo;
struct SamplerBindingLayout;
struct SamplerDescriptor;
struct ShaderModuleSPIRVDescriptor;
struct ShaderModuleWGSLDescriptor;
struct ShaderModuleDescriptor;
struct StencilFaceState;
struct StorageTextureBindingLayout;
struct SurfaceCapabilities;
struct SurfaceConfiguration;
struct SurfaceDescriptor;
struct SurfaceDescriptorFromCanvasHTMLSelector;
struct SurfaceTexture;
struct SwapChainDescriptor;
struct TextureBindingLayout;
struct TextureBindingViewDimensionDescriptor;
struct TextureDataLayout;
struct TextureViewDescriptor;
struct UncapturedErrorCallbackInfo;
struct VertexAttribute;
struct BindGroupDescriptor;
struct BindGroupLayoutEntry;
struct BlendState;
struct CompilationInfo;
struct ComputePassDescriptor;
struct DepthStencilState;
struct FutureWaitInfo;
struct ImageCopyBuffer;
struct ImageCopyTexture;
struct InstanceDescriptor;
struct ProgrammableStageDescriptor;
struct RenderPassColorAttachment;
struct RequiredLimits;
struct SupportedLimits;
struct TextureDescriptor;
struct VertexBufferLayout;
struct BindGroupLayoutDescriptor;
struct ColorTargetState;
struct ComputePipelineDescriptor;
struct DeviceDescriptor;
struct RenderPassDescriptor;
struct VertexState;
struct FragmentState;
struct RenderPipelineDescriptor;




class Adapter : public ObjectBase<Adapter, WGPUAdapter> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline size_t EnumerateFeatures(FeatureName * features) const;
    inline ConvertibleStatus GetInfo(AdapterInfo * info) const;
    inline ConvertibleStatus GetLimits(SupportedLimits * limits) const;
    inline ConvertibleStatus GetProperties(AdapterProperties * properties) const;
    inline Bool HasFeature(FeatureName feature) const;
    inline void RequestDevice(DeviceDescriptor const * descriptor, RequestDeviceCallback callback, void * userdata) const;
    template <typename F, typename T,
              typename Cb = void (RequestDeviceStatus status, Device device, char const * message, T userdata),
              typename = std::enable_if_t<std::is_convertible_v<F, Cb*>>>
    Future RequestDevice(DeviceDescriptor const * options, CallbackMode mode, F callback, T userdata) const;
    template <typename L,
              typename Cb = std::function<void(RequestDeviceStatus status, Device device, char const * message)>,
              typename = std::enable_if_t<std::is_convertible_v<L, Cb>>>
    Future RequestDevice(DeviceDescriptor const * options, CallbackMode mode, L callback) const;
    inline Future RequestDevice(DeviceDescriptor const * options, RequestDeviceCallbackInfo callbackInfo) const;

  private:
    friend ObjectBase<Adapter, WGPUAdapter>;
    static inline void WGPUAddRef(WGPUAdapter handle);
    static inline void WGPURelease(WGPUAdapter handle);
};

class BindGroup : public ObjectBase<BindGroup, WGPUBindGroup> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void SetLabel(char const * label) const;

  private:
    friend ObjectBase<BindGroup, WGPUBindGroup>;
    static inline void WGPUAddRef(WGPUBindGroup handle);
    static inline void WGPURelease(WGPUBindGroup handle);
};

class BindGroupLayout : public ObjectBase<BindGroupLayout, WGPUBindGroupLayout> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void SetLabel(char const * label) const;

  private:
    friend ObjectBase<BindGroupLayout, WGPUBindGroupLayout>;
    static inline void WGPUAddRef(WGPUBindGroupLayout handle);
    static inline void WGPURelease(WGPUBindGroupLayout handle);
};

class Buffer : public ObjectBase<Buffer, WGPUBuffer> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void Destroy() const;
    inline void const * GetConstMappedRange(size_t offset = 0, size_t size = WGPU_WHOLE_MAP_SIZE) const;
    inline BufferMapState GetMapState() const;
    inline void * GetMappedRange(size_t offset = 0, size_t size = WGPU_WHOLE_MAP_SIZE) const;
    inline uint64_t GetSize() const;
    inline BufferUsage GetUsage() const;
    inline void MapAsync(MapMode mode, size_t offset, size_t size, BufferMapCallback callback, void * userdata) const;
    inline Future MapAsync(MapMode mode, size_t offset, size_t size, BufferMapCallbackInfo callbackInfo) const;
    inline void SetLabel(char const * label) const;
    inline void Unmap() const;

  private:
    friend ObjectBase<Buffer, WGPUBuffer>;
    static inline void WGPUAddRef(WGPUBuffer handle);
    static inline void WGPURelease(WGPUBuffer handle);
};

class CommandBuffer : public ObjectBase<CommandBuffer, WGPUCommandBuffer> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void SetLabel(char const * label) const;

  private:
    friend ObjectBase<CommandBuffer, WGPUCommandBuffer>;
    static inline void WGPUAddRef(WGPUCommandBuffer handle);
    static inline void WGPURelease(WGPUCommandBuffer handle);
};

class CommandEncoder : public ObjectBase<CommandEncoder, WGPUCommandEncoder> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline ComputePassEncoder BeginComputePass(ComputePassDescriptor const * descriptor = nullptr) const;
    inline RenderPassEncoder BeginRenderPass(RenderPassDescriptor const * descriptor) const;
    inline void ClearBuffer(Buffer const& buffer, uint64_t offset = 0, uint64_t size = WGPU_WHOLE_SIZE) const;
    inline void CopyBufferToBuffer(Buffer const& source, uint64_t sourceOffset, Buffer const& destination, uint64_t destinationOffset, uint64_t size) const;
    inline void CopyBufferToTexture(ImageCopyBuffer const * source, ImageCopyTexture const * destination, Extent3D const * copySize) const;
    inline void CopyTextureToBuffer(ImageCopyTexture const * source, ImageCopyBuffer const * destination, Extent3D const * copySize) const;
    inline void CopyTextureToTexture(ImageCopyTexture const * source, ImageCopyTexture const * destination, Extent3D const * copySize) const;
    inline CommandBuffer Finish(CommandBufferDescriptor const * descriptor = nullptr) const;
    inline void InsertDebugMarker(char const * markerLabel) const;
    inline void PopDebugGroup() const;
    inline void PushDebugGroup(char const * groupLabel) const;
    inline void ResolveQuerySet(QuerySet const& querySet, uint32_t firstQuery, uint32_t queryCount, Buffer const& destination, uint64_t destinationOffset) const;
    inline void SetLabel(char const * label) const;
    inline void WriteTimestamp(QuerySet const& querySet, uint32_t queryIndex) const;

  private:
    friend ObjectBase<CommandEncoder, WGPUCommandEncoder>;
    static inline void WGPUAddRef(WGPUCommandEncoder handle);
    static inline void WGPURelease(WGPUCommandEncoder handle);
};

class ComputePassEncoder : public ObjectBase<ComputePassEncoder, WGPUComputePassEncoder> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void DispatchWorkgroups(uint32_t workgroupCountX, uint32_t workgroupCountY = 1, uint32_t workgroupCountZ = 1) const;
    inline void DispatchWorkgroupsIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const;
    inline void End() const;
    inline void InsertDebugMarker(char const * markerLabel) const;
    inline void PopDebugGroup() const;
    inline void PushDebugGroup(char const * groupLabel) const;
    inline void SetBindGroup(uint32_t groupIndex, BindGroup const& group, size_t dynamicOffsetCount = 0, uint32_t const * dynamicOffsets = nullptr) const;
    inline void SetLabel(char const * label) const;
    inline void SetPipeline(ComputePipeline const& pipeline) const;
    inline void WriteTimestamp(QuerySet const& querySet, uint32_t queryIndex) const;

  private:
    friend ObjectBase<ComputePassEncoder, WGPUComputePassEncoder>;
    static inline void WGPUAddRef(WGPUComputePassEncoder handle);
    static inline void WGPURelease(WGPUComputePassEncoder handle);
};

class ComputePipeline : public ObjectBase<ComputePipeline, WGPUComputePipeline> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline BindGroupLayout GetBindGroupLayout(uint32_t groupIndex) const;
    inline void SetLabel(char const * label) const;

  private:
    friend ObjectBase<ComputePipeline, WGPUComputePipeline>;
    static inline void WGPUAddRef(WGPUComputePipeline handle);
    static inline void WGPURelease(WGPUComputePipeline handle);
};

class Device : public ObjectBase<Device, WGPUDevice> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline BindGroup CreateBindGroup(BindGroupDescriptor const * descriptor) const;
    inline BindGroupLayout CreateBindGroupLayout(BindGroupLayoutDescriptor const * descriptor) const;
    inline Buffer CreateBuffer(BufferDescriptor const * descriptor) const;
    inline CommandEncoder CreateCommandEncoder(CommandEncoderDescriptor const * descriptor = nullptr) const;
    inline ComputePipeline CreateComputePipeline(ComputePipelineDescriptor const * descriptor) const;
    inline void CreateComputePipelineAsync(ComputePipelineDescriptor const * descriptor, CreateComputePipelineAsyncCallback callback, void * userdata) const;
    template <typename F, typename T,
              typename Cb = void (CreatePipelineAsyncStatus status, ComputePipeline pipeline, char const * message, T userdata),
              typename = std::enable_if_t<std::is_convertible_v<F, Cb*>>>
    Future CreateComputePipelineAsync(ComputePipelineDescriptor const * descriptor, CallbackMode mode, F callback, T userdata) const;
    template <typename L,
              typename Cb = std::function<void(CreatePipelineAsyncStatus status, ComputePipeline pipeline, char const * message)>,
              typename = std::enable_if_t<std::is_convertible_v<L, Cb>>>
    Future CreateComputePipelineAsync(ComputePipelineDescriptor const * descriptor, CallbackMode mode, L callback) const;
    inline Future CreateComputePipelineAsync(ComputePipelineDescriptor const * descriptor, CreateComputePipelineAsyncCallbackInfo callbackInfo) const;
    inline PipelineLayout CreatePipelineLayout(PipelineLayoutDescriptor const * descriptor) const;
    inline QuerySet CreateQuerySet(QuerySetDescriptor const * descriptor) const;
    inline RenderBundleEncoder CreateRenderBundleEncoder(RenderBundleEncoderDescriptor const * descriptor) const;
    inline RenderPipeline CreateRenderPipeline(RenderPipelineDescriptor const * descriptor) const;
    inline void CreateRenderPipelineAsync(RenderPipelineDescriptor const * descriptor, CreateRenderPipelineAsyncCallback callback, void * userdata) const;
    template <typename F, typename T,
              typename Cb = void (CreatePipelineAsyncStatus status, RenderPipeline pipeline, char const * message, T userdata),
              typename = std::enable_if_t<std::is_convertible_v<F, Cb*>>>
    Future CreateRenderPipelineAsync(RenderPipelineDescriptor const * descriptor, CallbackMode mode, F callback, T userdata) const;
    template <typename L,
              typename Cb = std::function<void(CreatePipelineAsyncStatus status, RenderPipeline pipeline, char const * message)>,
              typename = std::enable_if_t<std::is_convertible_v<L, Cb>>>
    Future CreateRenderPipelineAsync(RenderPipelineDescriptor const * descriptor, CallbackMode mode, L callback) const;
    inline Future CreateRenderPipelineAsync(RenderPipelineDescriptor const * descriptor, CreateRenderPipelineAsyncCallbackInfo callbackInfo) const;
    inline Sampler CreateSampler(SamplerDescriptor const * descriptor = nullptr) const;
    inline ShaderModule CreateShaderModule(ShaderModuleDescriptor const * descriptor) const;
    inline SwapChain CreateSwapChain(Surface const& surface, SwapChainDescriptor const * descriptor) const;
    inline Texture CreateTexture(TextureDescriptor const * descriptor) const;
    inline void Destroy() const;
    inline size_t EnumerateFeatures(FeatureName * features) const;
    inline ConvertibleStatus GetLimits(SupportedLimits * limits) const;
    inline Queue GetQueue() const;
    inline Bool HasFeature(FeatureName feature) const;
    inline void PopErrorScope(ErrorCallback oldCallback, void * userdata) const;
    template <typename F, typename T,
              typename Cb = void (PopErrorScopeStatus status, ErrorType type, char const * message, T userdata),
              typename = std::enable_if_t<std::is_convertible_v<F, Cb*>>>
    Future PopErrorScope(CallbackMode mode, F callback, T userdata) const;
    template <typename L,
              typename Cb = std::function<void(PopErrorScopeStatus status, ErrorType type, char const * message)>,
              typename = std::enable_if_t<std::is_convertible_v<L, Cb>>>
    Future PopErrorScope(CallbackMode mode, L callback) const;
    inline Future PopErrorScope(PopErrorScopeCallbackInfo callbackInfo) const;
    inline void PushErrorScope(ErrorFilter filter) const;
    inline void SetLabel(char const * label) const;
    inline void SetUncapturedErrorCallback(ErrorCallback callback, void * userdata) const;

  private:
    friend ObjectBase<Device, WGPUDevice>;
    static inline void WGPUAddRef(WGPUDevice handle);
    static inline void WGPURelease(WGPUDevice handle);
};

class Instance : public ObjectBase<Instance, WGPUInstance> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline Surface CreateSurface(SurfaceDescriptor const * descriptor) const;
    inline size_t EnumerateWGSLLanguageFeatures(WGSLFeatureName * features) const;
    inline Bool HasWGSLLanguageFeature(WGSLFeatureName feature) const;
    inline void ProcessEvents() const;
    inline void RequestAdapter(RequestAdapterOptions const * options, RequestAdapterCallback callback, void * userdata) const;
    template <typename F, typename T,
              typename Cb = void (RequestAdapterStatus status, Adapter adapter, char const * message, T userdata),
              typename = std::enable_if_t<std::is_convertible_v<F, Cb*>>>
    Future RequestAdapter(RequestAdapterOptions const * options, CallbackMode mode, F callback, T userdata) const;
    template <typename L,
              typename Cb = std::function<void(RequestAdapterStatus status, Adapter adapter, char const * message)>,
              typename = std::enable_if_t<std::is_convertible_v<L, Cb>>>
    Future RequestAdapter(RequestAdapterOptions const * options, CallbackMode mode, L callback) const;
    inline Future RequestAdapter(RequestAdapterOptions const * options, RequestAdapterCallbackInfo callbackInfo) const;
    inline WaitStatus WaitAny(size_t futureCount, FutureWaitInfo * futures, uint64_t timeoutNS) const;

  private:
    friend ObjectBase<Instance, WGPUInstance>;
    static inline void WGPUAddRef(WGPUInstance handle);
    static inline void WGPURelease(WGPUInstance handle);
};

class PipelineLayout : public ObjectBase<PipelineLayout, WGPUPipelineLayout> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void SetLabel(char const * label) const;

  private:
    friend ObjectBase<PipelineLayout, WGPUPipelineLayout>;
    static inline void WGPUAddRef(WGPUPipelineLayout handle);
    static inline void WGPURelease(WGPUPipelineLayout handle);
};

class QuerySet : public ObjectBase<QuerySet, WGPUQuerySet> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void Destroy() const;
    inline uint32_t GetCount() const;
    inline QueryType GetType() const;
    inline void SetLabel(char const * label) const;

  private:
    friend ObjectBase<QuerySet, WGPUQuerySet>;
    static inline void WGPUAddRef(WGPUQuerySet handle);
    static inline void WGPURelease(WGPUQuerySet handle);
};

class Queue : public ObjectBase<Queue, WGPUQueue> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void OnSubmittedWorkDone(uint64_t signalValue, QueueWorkDoneCallback callback, void * userdata) const;
    template <typename F, typename T,
              typename Cb = void (QueueWorkDoneStatus status, T userdata),
              typename = std::enable_if_t<std::is_convertible_v<F, Cb*>>>
    Future OnSubmittedWorkDone(CallbackMode mode, F callback, T userdata) const;
    template <typename L,
              typename Cb = std::function<void(QueueWorkDoneStatus status)>,
              typename = std::enable_if_t<std::is_convertible_v<L, Cb>>>
    Future OnSubmittedWorkDone(CallbackMode mode, L callback) const;
    inline Future OnSubmittedWorkDone(QueueWorkDoneCallbackInfo callbackInfo) const;
    inline void SetLabel(char const * label) const;
    inline void Submit(size_t commandCount, CommandBuffer const * commands) const;
    inline void WriteBuffer(Buffer const& buffer, uint64_t bufferOffset, void const * data, size_t size) const;
    inline void WriteTexture(ImageCopyTexture const * destination, void const * data, size_t dataSize, TextureDataLayout const * dataLayout, Extent3D const * writeSize) const;

  private:
    friend ObjectBase<Queue, WGPUQueue>;
    static inline void WGPUAddRef(WGPUQueue handle);
    static inline void WGPURelease(WGPUQueue handle);
};

class RenderBundle : public ObjectBase<RenderBundle, WGPURenderBundle> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void SetLabel(char const * label) const;

  private:
    friend ObjectBase<RenderBundle, WGPURenderBundle>;
    static inline void WGPUAddRef(WGPURenderBundle handle);
    static inline void WGPURelease(WGPURenderBundle handle);
};

class RenderBundleEncoder : public ObjectBase<RenderBundleEncoder, WGPURenderBundleEncoder> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void Draw(uint32_t vertexCount, uint32_t instanceCount = 1, uint32_t firstVertex = 0, uint32_t firstInstance = 0) const;
    inline void DrawIndexed(uint32_t indexCount, uint32_t instanceCount = 1, uint32_t firstIndex = 0, int32_t baseVertex = 0, uint32_t firstInstance = 0) const;
    inline void DrawIndexedIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const;
    inline void DrawIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const;
    inline RenderBundle Finish(RenderBundleDescriptor const * descriptor = nullptr) const;
    inline void InsertDebugMarker(char const * markerLabel) const;
    inline void PopDebugGroup() const;
    inline void PushDebugGroup(char const * groupLabel) const;
    inline void SetBindGroup(uint32_t groupIndex, BindGroup const& group, size_t dynamicOffsetCount = 0, uint32_t const * dynamicOffsets = nullptr) const;
    inline void SetIndexBuffer(Buffer const& buffer, IndexFormat format, uint64_t offset = 0, uint64_t size = WGPU_WHOLE_SIZE) const;
    inline void SetLabel(char const * label) const;
    inline void SetPipeline(RenderPipeline const& pipeline) const;
    inline void SetVertexBuffer(uint32_t slot, Buffer const& buffer, uint64_t offset = 0, uint64_t size = WGPU_WHOLE_SIZE) const;

  private:
    friend ObjectBase<RenderBundleEncoder, WGPURenderBundleEncoder>;
    static inline void WGPUAddRef(WGPURenderBundleEncoder handle);
    static inline void WGPURelease(WGPURenderBundleEncoder handle);
};

class RenderPassEncoder : public ObjectBase<RenderPassEncoder, WGPURenderPassEncoder> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void BeginOcclusionQuery(uint32_t queryIndex) const;
    inline void Draw(uint32_t vertexCount, uint32_t instanceCount = 1, uint32_t firstVertex = 0, uint32_t firstInstance = 0) const;
    inline void DrawIndexed(uint32_t indexCount, uint32_t instanceCount = 1, uint32_t firstIndex = 0, int32_t baseVertex = 0, uint32_t firstInstance = 0) const;
    inline void DrawIndexedIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const;
    inline void DrawIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const;
    inline void End() const;
    inline void EndOcclusionQuery() const;
    inline void ExecuteBundles(size_t bundleCount, RenderBundle const * bundles) const;
    inline void InsertDebugMarker(char const * markerLabel) const;
    inline void PopDebugGroup() const;
    inline void PushDebugGroup(char const * groupLabel) const;
    inline void SetBindGroup(uint32_t groupIndex, BindGroup const& group, size_t dynamicOffsetCount = 0, uint32_t const * dynamicOffsets = nullptr) const;
    inline void SetBlendConstant(Color const * color) const;
    inline void SetIndexBuffer(Buffer const& buffer, IndexFormat format, uint64_t offset = 0, uint64_t size = WGPU_WHOLE_SIZE) const;
    inline void SetLabel(char const * label) const;
    inline void SetPipeline(RenderPipeline const& pipeline) const;
    inline void SetScissorRect(uint32_t x, uint32_t y, uint32_t width, uint32_t height) const;
    inline void SetStencilReference(uint32_t reference) const;
    inline void SetVertexBuffer(uint32_t slot, Buffer const& buffer, uint64_t offset = 0, uint64_t size = WGPU_WHOLE_SIZE) const;
    inline void SetViewport(float x, float y, float width, float height, float minDepth, float maxDepth) const;
    inline void WriteTimestamp(QuerySet const& querySet, uint32_t queryIndex) const;

  private:
    friend ObjectBase<RenderPassEncoder, WGPURenderPassEncoder>;
    static inline void WGPUAddRef(WGPURenderPassEncoder handle);
    static inline void WGPURelease(WGPURenderPassEncoder handle);
};

class RenderPipeline : public ObjectBase<RenderPipeline, WGPURenderPipeline> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline BindGroupLayout GetBindGroupLayout(uint32_t groupIndex) const;
    inline void SetLabel(char const * label) const;

  private:
    friend ObjectBase<RenderPipeline, WGPURenderPipeline>;
    static inline void WGPUAddRef(WGPURenderPipeline handle);
    static inline void WGPURelease(WGPURenderPipeline handle);
};

class Sampler : public ObjectBase<Sampler, WGPUSampler> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void SetLabel(char const * label) const;

  private:
    friend ObjectBase<Sampler, WGPUSampler>;
    static inline void WGPUAddRef(WGPUSampler handle);
    static inline void WGPURelease(WGPUSampler handle);
};

class ShaderModule : public ObjectBase<ShaderModule, WGPUShaderModule> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void GetCompilationInfo(CompilationInfoCallback callback, void * userdata) const;
    inline Future GetCompilationInfo(CompilationInfoCallbackInfo callbackInfo) const;
    inline void SetLabel(char const * label) const;

  private:
    friend ObjectBase<ShaderModule, WGPUShaderModule>;
    static inline void WGPUAddRef(WGPUShaderModule handle);
    static inline void WGPURelease(WGPUShaderModule handle);
};

class Surface : public ObjectBase<Surface, WGPUSurface> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void Configure(SurfaceConfiguration const * config) const;
    inline ConvertibleStatus GetCapabilities(Adapter const& adapter, SurfaceCapabilities * capabilities) const;
    inline void GetCurrentTexture(SurfaceTexture * surfaceTexture) const;
    inline TextureFormat GetPreferredFormat(Adapter const& adapter) const;
    inline void Present() const;
    inline void Unconfigure() const;

  private:
    friend ObjectBase<Surface, WGPUSurface>;
    static inline void WGPUAddRef(WGPUSurface handle);
    static inline void WGPURelease(WGPUSurface handle);
};

class SwapChain : public ObjectBase<SwapChain, WGPUSwapChain> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline TextureView GetCurrentTextureView() const;
    inline void Present() const;

  private:
    friend ObjectBase<SwapChain, WGPUSwapChain>;
    static inline void WGPUAddRef(WGPUSwapChain handle);
    static inline void WGPURelease(WGPUSwapChain handle);
};

class Texture : public ObjectBase<Texture, WGPUTexture> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline TextureView CreateView(TextureViewDescriptor const * descriptor = nullptr) const;
    inline void Destroy() const;
    inline uint32_t GetDepthOrArrayLayers() const;
    inline TextureDimension GetDimension() const;
    inline TextureFormat GetFormat() const;
    inline uint32_t GetHeight() const;
    inline uint32_t GetMipLevelCount() const;
    inline uint32_t GetSampleCount() const;
    inline TextureUsage GetUsage() const;
    inline uint32_t GetWidth() const;
    inline void SetLabel(char const * label) const;

  private:
    friend ObjectBase<Texture, WGPUTexture>;
    static inline void WGPUAddRef(WGPUTexture handle);
    static inline void WGPURelease(WGPUTexture handle);
};

class TextureView : public ObjectBase<TextureView, WGPUTextureView> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void SetLabel(char const * label) const;

  private:
    friend ObjectBase<TextureView, WGPUTextureView>;
    static inline void WGPUAddRef(WGPUTextureView handle);
    static inline void WGPURelease(WGPUTextureView handle);
};


// ChainedStruct
static_assert(sizeof(ChainedStruct) == sizeof(WGPUChainedStruct),
    "sizeof mismatch for ChainedStruct");
static_assert(alignof(ChainedStruct) == alignof(WGPUChainedStruct),
    "alignof mismatch for ChainedStruct");
static_assert(offsetof(ChainedStruct, nextInChain) == offsetof(WGPUChainedStruct, next),
    "offsetof mismatch for ChainedStruct::nextInChain");
static_assert(offsetof(ChainedStruct, sType) == offsetof(WGPUChainedStruct, sType),
    "offsetof mismatch for ChainedStruct::sType");

struct AdapterInfo {
    inline AdapterInfo();
    inline ~AdapterInfo();
    AdapterInfo(const AdapterInfo&) = delete;
    AdapterInfo& operator=(const AdapterInfo&) = delete;
    inline AdapterInfo(AdapterInfo&&);
    inline AdapterInfo& operator=(AdapterInfo&&);
    inline operator const WGPUAdapterInfo&() const noexcept;

    ChainedStructOut  * nextInChain = nullptr;
    char const * const vendor = nullptr;
    char const * const architecture = nullptr;
    char const * const device = nullptr;
    char const * const description = nullptr;
    BackendType const backendType = {};
    AdapterType const adapterType = {};
    uint32_t const vendorID = {};
    uint32_t const deviceID = {};

  private:
    static inline void Reset(AdapterInfo& value);
};

struct AdapterProperties {
    inline AdapterProperties();
    inline ~AdapterProperties();
    AdapterProperties(const AdapterProperties&) = delete;
    AdapterProperties& operator=(const AdapterProperties&) = delete;
    inline AdapterProperties(AdapterProperties&&);
    inline AdapterProperties& operator=(AdapterProperties&&);
    inline operator const WGPUAdapterProperties&() const noexcept;

    ChainedStructOut  * nextInChain = nullptr;
    uint32_t const vendorID = {};
    char const * const vendorName = nullptr;
    char const * const architecture = nullptr;
    uint32_t const deviceID = {};
    char const * const name = nullptr;
    char const * const driverDescription = nullptr;
    AdapterType const adapterType = {};
    BackendType const backendType = {};
    Bool const compatibilityMode = false;

  private:
    static inline void Reset(AdapterProperties& value);
};

struct BindGroupEntry {
    inline operator const WGPUBindGroupEntry&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    uint32_t binding;
    Buffer buffer = nullptr;
    uint64_t offset = 0;
    uint64_t size = WGPU_WHOLE_SIZE;
    Sampler sampler = nullptr;
    TextureView textureView = nullptr;
};

struct BlendComponent {
    inline operator const WGPUBlendComponent&() const noexcept;

    BlendOperation operation = BlendOperation::Add;
    BlendFactor srcFactor = BlendFactor::One;
    BlendFactor dstFactor = BlendFactor::Zero;
};

struct BufferBindingLayout {
    inline operator const WGPUBufferBindingLayout&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    BufferBindingType type = BufferBindingType::Undefined;
    Bool hasDynamicOffset = false;
    uint64_t minBindingSize = 0;
};

struct BufferDescriptor {
    inline operator const WGPUBufferDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
    BufferUsage usage;
    uint64_t size;
    Bool mappedAtCreation = false;
};

struct BufferMapCallbackInfo {
    inline operator const WGPUBufferMapCallbackInfo&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    CallbackMode mode;
    BufferMapCallback callback;
    void * userdata;
};

struct Color {
    inline operator const WGPUColor&() const noexcept;

    double r;
    double g;
    double b;
    double a;
};

struct CommandBufferDescriptor {
    inline operator const WGPUCommandBufferDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
};

struct CommandEncoderDescriptor {
    inline operator const WGPUCommandEncoderDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
};

struct CompilationInfoCallbackInfo {
    inline operator const WGPUCompilationInfoCallbackInfo&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    CallbackMode mode;
    CompilationInfoCallback callback;
    void * userdata = nullptr;
};

struct CompilationMessage {
    inline operator const WGPUCompilationMessage&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * message = nullptr;
    CompilationMessageType type;
    uint64_t lineNum;
    uint64_t linePos;
    uint64_t offset;
    uint64_t length;
    uint64_t utf16LinePos;
    uint64_t utf16Offset;
    uint64_t utf16Length;
};

struct ComputePassTimestampWrites {
    inline operator const WGPUComputePassTimestampWrites&() const noexcept;

    QuerySet querySet;
    uint32_t beginningOfPassWriteIndex = WGPU_QUERY_SET_INDEX_UNDEFINED;
    uint32_t endOfPassWriteIndex = WGPU_QUERY_SET_INDEX_UNDEFINED;
};

struct ConstantEntry {
    inline operator const WGPUConstantEntry&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * key;
    double value;
};

struct CreateComputePipelineAsyncCallbackInfo {
    inline operator const WGPUCreateComputePipelineAsyncCallbackInfo&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    CallbackMode mode;
    CreateComputePipelineAsyncCallback callback;
    void * userdata;
};

struct CreateRenderPipelineAsyncCallbackInfo {
    inline operator const WGPUCreateRenderPipelineAsyncCallbackInfo&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    CallbackMode mode;
    CreateRenderPipelineAsyncCallback callback;
    void * userdata;
};

struct DeviceLostCallbackInfo {
    inline operator const WGPUDeviceLostCallbackInfo&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    CallbackMode mode = CallbackMode::WaitAnyOnly;
    DeviceLostCallbackNew callback = nullptr;
    void * userdata = nullptr;
};

struct Extent3D {
    inline operator const WGPUExtent3D&() const noexcept;

    uint32_t width;
    uint32_t height = 1;
    uint32_t depthOrArrayLayers = 1;
};

struct Future {
    inline operator const WGPUFuture&() const noexcept;

    uint64_t id;
};

struct InstanceFeatures {
    inline operator const WGPUInstanceFeatures&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    Bool timedWaitAnyEnable = false;
    size_t timedWaitAnyMaxCount = 0;
};

struct Limits {
    inline operator const WGPULimits&() const noexcept;

    uint32_t maxTextureDimension1D = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxTextureDimension2D = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxTextureDimension3D = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxTextureArrayLayers = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxBindGroups = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxBindGroupsPlusVertexBuffers = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxBindingsPerBindGroup = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxDynamicUniformBuffersPerPipelineLayout = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxDynamicStorageBuffersPerPipelineLayout = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxSampledTexturesPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxSamplersPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxStorageBuffersPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxStorageTexturesPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxUniformBuffersPerShaderStage = WGPU_LIMIT_U32_UNDEFINED;
    uint64_t maxUniformBufferBindingSize = WGPU_LIMIT_U64_UNDEFINED;
    uint64_t maxStorageBufferBindingSize = WGPU_LIMIT_U64_UNDEFINED;
    uint32_t minUniformBufferOffsetAlignment = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t minStorageBufferOffsetAlignment = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxVertexBuffers = WGPU_LIMIT_U32_UNDEFINED;
    uint64_t maxBufferSize = WGPU_LIMIT_U64_UNDEFINED;
    uint32_t maxVertexAttributes = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxVertexBufferArrayStride = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxInterStageShaderComponents = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxInterStageShaderVariables = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxColorAttachments = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxColorAttachmentBytesPerSample = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxComputeWorkgroupStorageSize = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxComputeInvocationsPerWorkgroup = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxComputeWorkgroupSizeX = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxComputeWorkgroupSizeY = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxComputeWorkgroupSizeZ = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxComputeWorkgroupsPerDimension = WGPU_LIMIT_U32_UNDEFINED;
};

struct MultisampleState {
    inline operator const WGPUMultisampleState&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    uint32_t count = 1;
    uint32_t mask = 0xFFFFFFFF;
    Bool alphaToCoverageEnabled = false;
};

struct Origin3D {
    inline operator const WGPUOrigin3D&() const noexcept;

    uint32_t x = 0;
    uint32_t y = 0;
    uint32_t z = 0;
};

struct PipelineLayoutDescriptor {
    inline operator const WGPUPipelineLayoutDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
    size_t bindGroupLayoutCount;
    BindGroupLayout const * bindGroupLayouts;
};

struct PopErrorScopeCallbackInfo {
    inline operator const WGPUPopErrorScopeCallbackInfo&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    CallbackMode mode = CallbackMode::WaitAnyOnly;
    PopErrorScopeCallback callback;
    ErrorCallback oldCallback;
    void * userdata = nullptr;
};

// Can be chained in PrimitiveState
struct PrimitiveDepthClipControl : ChainedStruct {
    inline PrimitiveDepthClipControl();

    struct Init;
    inline PrimitiveDepthClipControl(Init&& init);
    inline operator const WGPUPrimitiveDepthClipControl&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(Bool ));
    alignas(kFirstMemberAlignment) Bool unclippedDepth = false;
};

struct PrimitiveState {
    inline operator const WGPUPrimitiveState&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    PrimitiveTopology topology = PrimitiveTopology::TriangleList;
    IndexFormat stripIndexFormat = IndexFormat::Undefined;
    FrontFace frontFace = FrontFace::CCW;
    CullMode cullMode = CullMode::None;
};

struct QuerySetDescriptor {
    inline operator const WGPUQuerySetDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
    QueryType type;
    uint32_t count;
};

struct QueueDescriptor {
    inline operator const WGPUQueueDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
};

struct QueueWorkDoneCallbackInfo {
    inline operator const WGPUQueueWorkDoneCallbackInfo&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    CallbackMode mode;
    QueueWorkDoneCallback callback;
    void * userdata;
};

struct RenderBundleDescriptor {
    inline operator const WGPURenderBundleDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
};

struct RenderBundleEncoderDescriptor {
    inline operator const WGPURenderBundleEncoderDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
    size_t colorFormatCount;
    TextureFormat const * colorFormats;
    TextureFormat depthStencilFormat = TextureFormat::Undefined;
    uint32_t sampleCount = 1;
    Bool depthReadOnly = false;
    Bool stencilReadOnly = false;
};

struct RenderPassDepthStencilAttachment {
    inline operator const WGPURenderPassDepthStencilAttachment&() const noexcept;

    TextureView view;
    LoadOp depthLoadOp = LoadOp::Undefined;
    StoreOp depthStoreOp = StoreOp::Undefined;
    float depthClearValue = NAN;
    Bool depthReadOnly = false;
    LoadOp stencilLoadOp = LoadOp::Undefined;
    StoreOp stencilStoreOp = StoreOp::Undefined;
    uint32_t stencilClearValue = 0;
    Bool stencilReadOnly = false;
};

// Can be chained in RenderPassDescriptor
struct RenderPassDescriptorMaxDrawCount : ChainedStruct {
    inline RenderPassDescriptorMaxDrawCount();

    struct Init;
    inline RenderPassDescriptorMaxDrawCount(Init&& init);
    inline operator const WGPURenderPassDescriptorMaxDrawCount&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(uint64_t ));
    alignas(kFirstMemberAlignment) uint64_t maxDrawCount = 50000000;
};

struct RenderPassTimestampWrites {
    inline operator const WGPURenderPassTimestampWrites&() const noexcept;

    QuerySet querySet;
    uint32_t beginningOfPassWriteIndex = WGPU_QUERY_SET_INDEX_UNDEFINED;
    uint32_t endOfPassWriteIndex = WGPU_QUERY_SET_INDEX_UNDEFINED;
};

struct RequestAdapterCallbackInfo {
    inline operator const WGPURequestAdapterCallbackInfo&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    CallbackMode mode;
    RequestAdapterCallback callback;
    void * userdata;
};

struct RequestAdapterOptions {
    inline operator const WGPURequestAdapterOptions&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    Surface compatibleSurface = nullptr;
    PowerPreference powerPreference = PowerPreference::Undefined;
    BackendType backendType = BackendType::Undefined;
    Bool forceFallbackAdapter = false;
    Bool compatibilityMode = false;
};

struct RequestDeviceCallbackInfo {
    inline operator const WGPURequestDeviceCallbackInfo&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    CallbackMode mode;
    RequestDeviceCallback callback;
    void * userdata;
};

struct SamplerBindingLayout {
    inline operator const WGPUSamplerBindingLayout&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    SamplerBindingType type = SamplerBindingType::Undefined;
};

struct SamplerDescriptor {
    inline operator const WGPUSamplerDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
    AddressMode addressModeU = AddressMode::ClampToEdge;
    AddressMode addressModeV = AddressMode::ClampToEdge;
    AddressMode addressModeW = AddressMode::ClampToEdge;
    FilterMode magFilter = FilterMode::Nearest;
    FilterMode minFilter = FilterMode::Nearest;
    MipmapFilterMode mipmapFilter = MipmapFilterMode::Nearest;
    float lodMinClamp = 0.0f;
    float lodMaxClamp = 32.0f;
    CompareFunction compare = CompareFunction::Undefined;
    uint16_t maxAnisotropy = 1;
};

// Can be chained in ShaderModuleDescriptor
struct ShaderModuleSPIRVDescriptor : ChainedStruct {
    inline ShaderModuleSPIRVDescriptor();

    struct Init;
    inline ShaderModuleSPIRVDescriptor(Init&& init);
    inline operator const WGPUShaderModuleSPIRVDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(uint32_t ));
    alignas(kFirstMemberAlignment) uint32_t codeSize;
    uint32_t const * code;
};

// Can be chained in ShaderModuleDescriptor
struct ShaderModuleWGSLDescriptor : ChainedStruct {
    inline ShaderModuleWGSLDescriptor();

    struct Init;
    inline ShaderModuleWGSLDescriptor(Init&& init);
    inline operator const WGPUShaderModuleWGSLDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(char const * ));
    alignas(kFirstMemberAlignment) char const * code;
};

struct ShaderModuleDescriptor {
    inline operator const WGPUShaderModuleDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
};

struct StencilFaceState {
    inline operator const WGPUStencilFaceState&() const noexcept;

    CompareFunction compare = CompareFunction::Always;
    StencilOperation failOp = StencilOperation::Keep;
    StencilOperation depthFailOp = StencilOperation::Keep;
    StencilOperation passOp = StencilOperation::Keep;
};

struct StorageTextureBindingLayout {
    inline operator const WGPUStorageTextureBindingLayout&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    StorageTextureAccess access = StorageTextureAccess::Undefined;
    TextureFormat format = TextureFormat::Undefined;
    TextureViewDimension viewDimension = TextureViewDimension::e2D;
};

struct SurfaceCapabilities {
    inline SurfaceCapabilities();
    inline ~SurfaceCapabilities();
    SurfaceCapabilities(const SurfaceCapabilities&) = delete;
    SurfaceCapabilities& operator=(const SurfaceCapabilities&) = delete;
    inline SurfaceCapabilities(SurfaceCapabilities&&);
    inline SurfaceCapabilities& operator=(SurfaceCapabilities&&);
    inline operator const WGPUSurfaceCapabilities&() const noexcept;

    ChainedStructOut  * nextInChain = nullptr;
    TextureUsage const usages = {};
    size_t const formatCount = {};
    TextureFormat const * const formats = {};
    size_t const presentModeCount = {};
    PresentMode const * const presentModes = {};
    size_t const alphaModeCount = {};
    CompositeAlphaMode const * const alphaModes = {};

  private:
    static inline void Reset(SurfaceCapabilities& value);
};

struct SurfaceConfiguration {
    inline operator const WGPUSurfaceConfiguration&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    Device device;
    TextureFormat format;
    TextureUsage usage = TextureUsage::RenderAttachment;
    size_t viewFormatCount = 0;
    TextureFormat const * viewFormats;
    CompositeAlphaMode alphaMode = CompositeAlphaMode::Auto;
    uint32_t width;
    uint32_t height;
    PresentMode presentMode = PresentMode::Fifo;
};

struct SurfaceDescriptor {
    inline operator const WGPUSurfaceDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromCanvasHTMLSelector : ChainedStruct {
    inline SurfaceDescriptorFromCanvasHTMLSelector();

    struct Init;
    inline SurfaceDescriptorFromCanvasHTMLSelector(Init&& init);
    inline operator const WGPUSurfaceDescriptorFromCanvasHTMLSelector&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(char const * ));
    alignas(kFirstMemberAlignment) char const * selector;
};

struct SurfaceTexture {
    inline operator const WGPUSurfaceTexture&() const noexcept;

    Texture texture;
    Bool suboptimal;
    SurfaceGetCurrentTextureStatus status;
};

struct SwapChainDescriptor {
    inline operator const WGPUSwapChainDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
    TextureUsage usage;
    TextureFormat format;
    uint32_t width;
    uint32_t height;
    PresentMode presentMode;
};

struct TextureBindingLayout {
    inline operator const WGPUTextureBindingLayout&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    TextureSampleType sampleType = TextureSampleType::Undefined;
    TextureViewDimension viewDimension = TextureViewDimension::e2D;
    Bool multisampled = false;
};

// Can be chained in TextureDescriptor
struct TextureBindingViewDimensionDescriptor : ChainedStruct {
    inline TextureBindingViewDimensionDescriptor();

    struct Init;
    inline TextureBindingViewDimensionDescriptor(Init&& init);
    inline operator const WGPUTextureBindingViewDimensionDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(TextureViewDimension ));
    alignas(kFirstMemberAlignment) TextureViewDimension textureBindingViewDimension = TextureViewDimension::Undefined;
};

struct TextureDataLayout {
    inline operator const WGPUTextureDataLayout&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    uint64_t offset = 0;
    uint32_t bytesPerRow = WGPU_COPY_STRIDE_UNDEFINED;
    uint32_t rowsPerImage = WGPU_COPY_STRIDE_UNDEFINED;
};

struct TextureViewDescriptor {
    inline operator const WGPUTextureViewDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
    TextureFormat format = TextureFormat::Undefined;
    TextureViewDimension dimension = TextureViewDimension::Undefined;
    uint32_t baseMipLevel = 0;
    uint32_t mipLevelCount = WGPU_MIP_LEVEL_COUNT_UNDEFINED;
    uint32_t baseArrayLayer = 0;
    uint32_t arrayLayerCount = WGPU_ARRAY_LAYER_COUNT_UNDEFINED;
    TextureAspect aspect = TextureAspect::All;
};

struct UncapturedErrorCallbackInfo {
    inline operator const WGPUUncapturedErrorCallbackInfo&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    ErrorCallback callback = nullptr;
    void * userdata = nullptr;
};

struct VertexAttribute {
    inline operator const WGPUVertexAttribute&() const noexcept;

    VertexFormat format;
    uint64_t offset;
    uint32_t shaderLocation;
};

struct BindGroupDescriptor {
    inline operator const WGPUBindGroupDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
    BindGroupLayout layout;
    size_t entryCount;
    BindGroupEntry const * entries;
};

struct BindGroupLayoutEntry {
    inline operator const WGPUBindGroupLayoutEntry&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    uint32_t binding;
    ShaderStage visibility;
    BufferBindingLayout buffer;
    SamplerBindingLayout sampler;
    TextureBindingLayout texture;
    StorageTextureBindingLayout storageTexture;
};

struct BlendState {
    inline operator const WGPUBlendState&() const noexcept;

    BlendComponent color;
    BlendComponent alpha;
};

struct CompilationInfo {
    inline operator const WGPUCompilationInfo&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    size_t messageCount;
    CompilationMessage const * messages;
};

struct ComputePassDescriptor {
    inline operator const WGPUComputePassDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
    ComputePassTimestampWrites const * timestampWrites = nullptr;
};

struct DepthStencilState {
    inline operator const WGPUDepthStencilState&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    TextureFormat format;
    Bool depthWriteEnabled = false;
    CompareFunction depthCompare = CompareFunction::Undefined;
    StencilFaceState stencilFront;
    StencilFaceState stencilBack;
    uint32_t stencilReadMask = 0xFFFFFFFF;
    uint32_t stencilWriteMask = 0xFFFFFFFF;
    int32_t depthBias = 0;
    float depthBiasSlopeScale = 0.0f;
    float depthBiasClamp = 0.0f;
};

struct FutureWaitInfo {
    inline operator const WGPUFutureWaitInfo&() const noexcept;

    Future future;
    Bool completed = false;
};

struct ImageCopyBuffer {
    inline operator const WGPUImageCopyBuffer&() const noexcept;

    TextureDataLayout layout;
    Buffer buffer;
};

struct ImageCopyTexture {
    inline operator const WGPUImageCopyTexture&() const noexcept;

    Texture texture;
    uint32_t mipLevel = 0;
    Origin3D origin;
    TextureAspect aspect = TextureAspect::All;
};

struct InstanceDescriptor {
    inline operator const WGPUInstanceDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    InstanceFeatures features;
};

struct ProgrammableStageDescriptor {
    inline operator const WGPUProgrammableStageDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    ShaderModule module;
    char const * entryPoint = nullptr;
    size_t constantCount = 0;
    ConstantEntry const * constants;
};

struct RenderPassColorAttachment {
    inline operator const WGPURenderPassColorAttachment&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    TextureView view = nullptr;
    uint32_t depthSlice = WGPU_DEPTH_SLICE_UNDEFINED;
    TextureView resolveTarget = nullptr;
    LoadOp loadOp;
    StoreOp storeOp;
    Color clearValue;
};

struct RequiredLimits {
    inline operator const WGPURequiredLimits&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    Limits limits;
};

struct SupportedLimits {
    inline operator const WGPUSupportedLimits&() const noexcept;

    ChainedStructOut  * nextInChain = nullptr;
    Limits limits;
};

struct TextureDescriptor {
    inline operator const WGPUTextureDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
    TextureUsage usage;
    TextureDimension dimension = TextureDimension::e2D;
    Extent3D size;
    TextureFormat format;
    uint32_t mipLevelCount = 1;
    uint32_t sampleCount = 1;
    size_t viewFormatCount = 0;
    TextureFormat const * viewFormats;
};

struct VertexBufferLayout {
    inline operator const WGPUVertexBufferLayout&() const noexcept;

    uint64_t arrayStride;
    VertexStepMode stepMode = VertexStepMode::Vertex;
    size_t attributeCount;
    VertexAttribute const * attributes;
};

struct BindGroupLayoutDescriptor {
    inline operator const WGPUBindGroupLayoutDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
    size_t entryCount;
    BindGroupLayoutEntry const * entries;
};

struct ColorTargetState {
    inline operator const WGPUColorTargetState&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    TextureFormat format;
    BlendState const * blend = nullptr;
    ColorWriteMask writeMask = ColorWriteMask::All;
};

struct ComputePipelineDescriptor {
    inline operator const WGPUComputePipelineDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
    PipelineLayout layout = nullptr;
    ProgrammableStageDescriptor compute;
};

struct DeviceDescriptor {
    inline operator const WGPUDeviceDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
    size_t requiredFeatureCount = 0;
    FeatureName const * requiredFeatures = nullptr;
    RequiredLimits const * requiredLimits = nullptr;
    QueueDescriptor defaultQueue;
    DeviceLostCallbackInfo deviceLostCallbackInfo;
    UncapturedErrorCallbackInfo uncapturedErrorCallbackInfo;
};

struct RenderPassDescriptor {
    inline operator const WGPURenderPassDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
    size_t colorAttachmentCount;
    RenderPassColorAttachment const * colorAttachments;
    RenderPassDepthStencilAttachment const * depthStencilAttachment = nullptr;
    QuerySet occlusionQuerySet = nullptr;
    RenderPassTimestampWrites const * timestampWrites = nullptr;
};

struct VertexState {
    inline operator const WGPUVertexState&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    ShaderModule module;
    char const * entryPoint = nullptr;
    size_t constantCount = 0;
    ConstantEntry const * constants;
    size_t bufferCount = 0;
    VertexBufferLayout const * buffers;
};

struct FragmentState {
    inline operator const WGPUFragmentState&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    ShaderModule module;
    char const * entryPoint = nullptr;
    size_t constantCount = 0;
    ConstantEntry const * constants;
    size_t targetCount;
    ColorTargetState const * targets;
};

struct RenderPipelineDescriptor {
    inline operator const WGPURenderPipelineDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
    PipelineLayout layout = nullptr;
    VertexState vertex;
    PrimitiveState primitive;
    DepthStencilState const * depthStencil = nullptr;
    MultisampleState multisample;
    FragmentState const * fragment = nullptr;
};


#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
// error: 'offsetof' within non-standard-layout type 'wgpu::XXX' is conditionally-supported
#pragma GCC diagnostic ignored "-Winvalid-offsetof"
#endif
// AdapterInfo implementation
AdapterInfo::AdapterInfo() = default;
AdapterInfo::~AdapterInfo() {
    if (this->vendor != nullptr || this->architecture != nullptr || this->device != nullptr || this->description != nullptr) {
        wgpuAdapterInfoFreeMembers(
            *reinterpret_cast<WGPUAdapterInfo*>(this));
    }
}

AdapterInfo::AdapterInfo(AdapterInfo&& rhs)
    : vendor(rhs.vendor),
            architecture(rhs.architecture),
            device(rhs.device),
            description(rhs.description),
            backendType(rhs.backendType),
            adapterType(rhs.adapterType),
            vendorID(rhs.vendorID),
            deviceID(rhs.deviceID){
    Reset(rhs);
}

AdapterInfo& AdapterInfo::operator=(AdapterInfo&& rhs) {
    if (&rhs == this) {
        return *this;
    }
    this->~AdapterInfo();
    detail::AsNonConstReference(this->vendor) = std::move(rhs.vendor);
    detail::AsNonConstReference(this->architecture) = std::move(rhs.architecture);
    detail::AsNonConstReference(this->device) = std::move(rhs.device);
    detail::AsNonConstReference(this->description) = std::move(rhs.description);
    detail::AsNonConstReference(this->backendType) = std::move(rhs.backendType);
    detail::AsNonConstReference(this->adapterType) = std::move(rhs.adapterType);
    detail::AsNonConstReference(this->vendorID) = std::move(rhs.vendorID);
    detail::AsNonConstReference(this->deviceID) = std::move(rhs.deviceID);
    Reset(rhs);
    return *this;
}

    // static
void AdapterInfo::Reset(AdapterInfo& value) {
    AdapterInfo defaultValue{};
    detail::AsNonConstReference(value.vendor) = defaultValue.vendor;
    detail::AsNonConstReference(value.architecture) = defaultValue.architecture;
    detail::AsNonConstReference(value.device) = defaultValue.device;
    detail::AsNonConstReference(value.description) = defaultValue.description;
    detail::AsNonConstReference(value.backendType) = defaultValue.backendType;
    detail::AsNonConstReference(value.adapterType) = defaultValue.adapterType;
    detail::AsNonConstReference(value.vendorID) = defaultValue.vendorID;
    detail::AsNonConstReference(value.deviceID) = defaultValue.deviceID;
}

AdapterInfo::operator const WGPUAdapterInfo&() const noexcept {
    return *reinterpret_cast<const WGPUAdapterInfo*>(this);
}

static_assert(sizeof(AdapterInfo) == sizeof(WGPUAdapterInfo), "sizeof mismatch for AdapterInfo");
static_assert(alignof(AdapterInfo) == alignof(WGPUAdapterInfo), "alignof mismatch for AdapterInfo");
static_assert(offsetof(AdapterInfo, nextInChain) == offsetof(WGPUAdapterInfo, nextInChain),
        "offsetof mismatch for AdapterInfo::nextInChain");
static_assert(offsetof(AdapterInfo, vendor) == offsetof(WGPUAdapterInfo, vendor),
        "offsetof mismatch for AdapterInfo::vendor");
static_assert(offsetof(AdapterInfo, architecture) == offsetof(WGPUAdapterInfo, architecture),
        "offsetof mismatch for AdapterInfo::architecture");
static_assert(offsetof(AdapterInfo, device) == offsetof(WGPUAdapterInfo, device),
        "offsetof mismatch for AdapterInfo::device");
static_assert(offsetof(AdapterInfo, description) == offsetof(WGPUAdapterInfo, description),
        "offsetof mismatch for AdapterInfo::description");
static_assert(offsetof(AdapterInfo, backendType) == offsetof(WGPUAdapterInfo, backendType),
        "offsetof mismatch for AdapterInfo::backendType");
static_assert(offsetof(AdapterInfo, adapterType) == offsetof(WGPUAdapterInfo, adapterType),
        "offsetof mismatch for AdapterInfo::adapterType");
static_assert(offsetof(AdapterInfo, vendorID) == offsetof(WGPUAdapterInfo, vendorID),
        "offsetof mismatch for AdapterInfo::vendorID");
static_assert(offsetof(AdapterInfo, deviceID) == offsetof(WGPUAdapterInfo, deviceID),
        "offsetof mismatch for AdapterInfo::deviceID");

// AdapterProperties implementation
AdapterProperties::AdapterProperties() = default;
AdapterProperties::~AdapterProperties() {
    if (this->vendorName != nullptr || this->architecture != nullptr || this->name != nullptr || this->driverDescription != nullptr) {
        wgpuAdapterPropertiesFreeMembers(
            *reinterpret_cast<WGPUAdapterProperties*>(this));
    }
}

AdapterProperties::AdapterProperties(AdapterProperties&& rhs)
    : vendorID(rhs.vendorID),
            vendorName(rhs.vendorName),
            architecture(rhs.architecture),
            deviceID(rhs.deviceID),
            name(rhs.name),
            driverDescription(rhs.driverDescription),
            adapterType(rhs.adapterType),
            backendType(rhs.backendType),
            compatibilityMode(rhs.compatibilityMode){
    Reset(rhs);
}

AdapterProperties& AdapterProperties::operator=(AdapterProperties&& rhs) {
    if (&rhs == this) {
        return *this;
    }
    this->~AdapterProperties();
    detail::AsNonConstReference(this->vendorID) = std::move(rhs.vendorID);
    detail::AsNonConstReference(this->vendorName) = std::move(rhs.vendorName);
    detail::AsNonConstReference(this->architecture) = std::move(rhs.architecture);
    detail::AsNonConstReference(this->deviceID) = std::move(rhs.deviceID);
    detail::AsNonConstReference(this->name) = std::move(rhs.name);
    detail::AsNonConstReference(this->driverDescription) = std::move(rhs.driverDescription);
    detail::AsNonConstReference(this->adapterType) = std::move(rhs.adapterType);
    detail::AsNonConstReference(this->backendType) = std::move(rhs.backendType);
    detail::AsNonConstReference(this->compatibilityMode) = std::move(rhs.compatibilityMode);
    Reset(rhs);
    return *this;
}

    // static
void AdapterProperties::Reset(AdapterProperties& value) {
    AdapterProperties defaultValue{};
    detail::AsNonConstReference(value.vendorID) = defaultValue.vendorID;
    detail::AsNonConstReference(value.vendorName) = defaultValue.vendorName;
    detail::AsNonConstReference(value.architecture) = defaultValue.architecture;
    detail::AsNonConstReference(value.deviceID) = defaultValue.deviceID;
    detail::AsNonConstReference(value.name) = defaultValue.name;
    detail::AsNonConstReference(value.driverDescription) = defaultValue.driverDescription;
    detail::AsNonConstReference(value.adapterType) = defaultValue.adapterType;
    detail::AsNonConstReference(value.backendType) = defaultValue.backendType;
    detail::AsNonConstReference(value.compatibilityMode) = defaultValue.compatibilityMode;
}

AdapterProperties::operator const WGPUAdapterProperties&() const noexcept {
    return *reinterpret_cast<const WGPUAdapterProperties*>(this);
}

static_assert(sizeof(AdapterProperties) == sizeof(WGPUAdapterProperties), "sizeof mismatch for AdapterProperties");
static_assert(alignof(AdapterProperties) == alignof(WGPUAdapterProperties), "alignof mismatch for AdapterProperties");
static_assert(offsetof(AdapterProperties, nextInChain) == offsetof(WGPUAdapterProperties, nextInChain),
        "offsetof mismatch for AdapterProperties::nextInChain");
static_assert(offsetof(AdapterProperties, vendorID) == offsetof(WGPUAdapterProperties, vendorID),
        "offsetof mismatch for AdapterProperties::vendorID");
static_assert(offsetof(AdapterProperties, vendorName) == offsetof(WGPUAdapterProperties, vendorName),
        "offsetof mismatch for AdapterProperties::vendorName");
static_assert(offsetof(AdapterProperties, architecture) == offsetof(WGPUAdapterProperties, architecture),
        "offsetof mismatch for AdapterProperties::architecture");
static_assert(offsetof(AdapterProperties, deviceID) == offsetof(WGPUAdapterProperties, deviceID),
        "offsetof mismatch for AdapterProperties::deviceID");
static_assert(offsetof(AdapterProperties, name) == offsetof(WGPUAdapterProperties, name),
        "offsetof mismatch for AdapterProperties::name");
static_assert(offsetof(AdapterProperties, driverDescription) == offsetof(WGPUAdapterProperties, driverDescription),
        "offsetof mismatch for AdapterProperties::driverDescription");
static_assert(offsetof(AdapterProperties, adapterType) == offsetof(WGPUAdapterProperties, adapterType),
        "offsetof mismatch for AdapterProperties::adapterType");
static_assert(offsetof(AdapterProperties, backendType) == offsetof(WGPUAdapterProperties, backendType),
        "offsetof mismatch for AdapterProperties::backendType");
static_assert(offsetof(AdapterProperties, compatibilityMode) == offsetof(WGPUAdapterProperties, compatibilityMode),
        "offsetof mismatch for AdapterProperties::compatibilityMode");

// BindGroupEntry implementation

BindGroupEntry::operator const WGPUBindGroupEntry&() const noexcept {
    return *reinterpret_cast<const WGPUBindGroupEntry*>(this);
}

static_assert(sizeof(BindGroupEntry) == sizeof(WGPUBindGroupEntry), "sizeof mismatch for BindGroupEntry");
static_assert(alignof(BindGroupEntry) == alignof(WGPUBindGroupEntry), "alignof mismatch for BindGroupEntry");
static_assert(offsetof(BindGroupEntry, nextInChain) == offsetof(WGPUBindGroupEntry, nextInChain),
        "offsetof mismatch for BindGroupEntry::nextInChain");
static_assert(offsetof(BindGroupEntry, binding) == offsetof(WGPUBindGroupEntry, binding),
        "offsetof mismatch for BindGroupEntry::binding");
static_assert(offsetof(BindGroupEntry, buffer) == offsetof(WGPUBindGroupEntry, buffer),
        "offsetof mismatch for BindGroupEntry::buffer");
static_assert(offsetof(BindGroupEntry, offset) == offsetof(WGPUBindGroupEntry, offset),
        "offsetof mismatch for BindGroupEntry::offset");
static_assert(offsetof(BindGroupEntry, size) == offsetof(WGPUBindGroupEntry, size),
        "offsetof mismatch for BindGroupEntry::size");
static_assert(offsetof(BindGroupEntry, sampler) == offsetof(WGPUBindGroupEntry, sampler),
        "offsetof mismatch for BindGroupEntry::sampler");
static_assert(offsetof(BindGroupEntry, textureView) == offsetof(WGPUBindGroupEntry, textureView),
        "offsetof mismatch for BindGroupEntry::textureView");

// BlendComponent implementation

BlendComponent::operator const WGPUBlendComponent&() const noexcept {
    return *reinterpret_cast<const WGPUBlendComponent*>(this);
}

static_assert(sizeof(BlendComponent) == sizeof(WGPUBlendComponent), "sizeof mismatch for BlendComponent");
static_assert(alignof(BlendComponent) == alignof(WGPUBlendComponent), "alignof mismatch for BlendComponent");
static_assert(offsetof(BlendComponent, operation) == offsetof(WGPUBlendComponent, operation),
        "offsetof mismatch for BlendComponent::operation");
static_assert(offsetof(BlendComponent, srcFactor) == offsetof(WGPUBlendComponent, srcFactor),
        "offsetof mismatch for BlendComponent::srcFactor");
static_assert(offsetof(BlendComponent, dstFactor) == offsetof(WGPUBlendComponent, dstFactor),
        "offsetof mismatch for BlendComponent::dstFactor");

// BufferBindingLayout implementation

BufferBindingLayout::operator const WGPUBufferBindingLayout&() const noexcept {
    return *reinterpret_cast<const WGPUBufferBindingLayout*>(this);
}

static_assert(sizeof(BufferBindingLayout) == sizeof(WGPUBufferBindingLayout), "sizeof mismatch for BufferBindingLayout");
static_assert(alignof(BufferBindingLayout) == alignof(WGPUBufferBindingLayout), "alignof mismatch for BufferBindingLayout");
static_assert(offsetof(BufferBindingLayout, nextInChain) == offsetof(WGPUBufferBindingLayout, nextInChain),
        "offsetof mismatch for BufferBindingLayout::nextInChain");
static_assert(offsetof(BufferBindingLayout, type) == offsetof(WGPUBufferBindingLayout, type),
        "offsetof mismatch for BufferBindingLayout::type");
static_assert(offsetof(BufferBindingLayout, hasDynamicOffset) == offsetof(WGPUBufferBindingLayout, hasDynamicOffset),
        "offsetof mismatch for BufferBindingLayout::hasDynamicOffset");
static_assert(offsetof(BufferBindingLayout, minBindingSize) == offsetof(WGPUBufferBindingLayout, minBindingSize),
        "offsetof mismatch for BufferBindingLayout::minBindingSize");

// BufferDescriptor implementation

BufferDescriptor::operator const WGPUBufferDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUBufferDescriptor*>(this);
}

static_assert(sizeof(BufferDescriptor) == sizeof(WGPUBufferDescriptor), "sizeof mismatch for BufferDescriptor");
static_assert(alignof(BufferDescriptor) == alignof(WGPUBufferDescriptor), "alignof mismatch for BufferDescriptor");
static_assert(offsetof(BufferDescriptor, nextInChain) == offsetof(WGPUBufferDescriptor, nextInChain),
        "offsetof mismatch for BufferDescriptor::nextInChain");
static_assert(offsetof(BufferDescriptor, label) == offsetof(WGPUBufferDescriptor, label),
        "offsetof mismatch for BufferDescriptor::label");
static_assert(offsetof(BufferDescriptor, usage) == offsetof(WGPUBufferDescriptor, usage),
        "offsetof mismatch for BufferDescriptor::usage");
static_assert(offsetof(BufferDescriptor, size) == offsetof(WGPUBufferDescriptor, size),
        "offsetof mismatch for BufferDescriptor::size");
static_assert(offsetof(BufferDescriptor, mappedAtCreation) == offsetof(WGPUBufferDescriptor, mappedAtCreation),
        "offsetof mismatch for BufferDescriptor::mappedAtCreation");

// BufferMapCallbackInfo implementation

BufferMapCallbackInfo::operator const WGPUBufferMapCallbackInfo&() const noexcept {
    return *reinterpret_cast<const WGPUBufferMapCallbackInfo*>(this);
}

static_assert(sizeof(BufferMapCallbackInfo) == sizeof(WGPUBufferMapCallbackInfo), "sizeof mismatch for BufferMapCallbackInfo");
static_assert(alignof(BufferMapCallbackInfo) == alignof(WGPUBufferMapCallbackInfo), "alignof mismatch for BufferMapCallbackInfo");
static_assert(offsetof(BufferMapCallbackInfo, nextInChain) == offsetof(WGPUBufferMapCallbackInfo, nextInChain),
        "offsetof mismatch for BufferMapCallbackInfo::nextInChain");
static_assert(offsetof(BufferMapCallbackInfo, mode) == offsetof(WGPUBufferMapCallbackInfo, mode),
        "offsetof mismatch for BufferMapCallbackInfo::mode");
static_assert(offsetof(BufferMapCallbackInfo, callback) == offsetof(WGPUBufferMapCallbackInfo, callback),
        "offsetof mismatch for BufferMapCallbackInfo::callback");
static_assert(offsetof(BufferMapCallbackInfo, userdata) == offsetof(WGPUBufferMapCallbackInfo, userdata),
        "offsetof mismatch for BufferMapCallbackInfo::userdata");

// Color implementation

Color::operator const WGPUColor&() const noexcept {
    return *reinterpret_cast<const WGPUColor*>(this);
}

static_assert(sizeof(Color) == sizeof(WGPUColor), "sizeof mismatch for Color");
static_assert(alignof(Color) == alignof(WGPUColor), "alignof mismatch for Color");
static_assert(offsetof(Color, r) == offsetof(WGPUColor, r),
        "offsetof mismatch for Color::r");
static_assert(offsetof(Color, g) == offsetof(WGPUColor, g),
        "offsetof mismatch for Color::g");
static_assert(offsetof(Color, b) == offsetof(WGPUColor, b),
        "offsetof mismatch for Color::b");
static_assert(offsetof(Color, a) == offsetof(WGPUColor, a),
        "offsetof mismatch for Color::a");

// CommandBufferDescriptor implementation

CommandBufferDescriptor::operator const WGPUCommandBufferDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUCommandBufferDescriptor*>(this);
}

static_assert(sizeof(CommandBufferDescriptor) == sizeof(WGPUCommandBufferDescriptor), "sizeof mismatch for CommandBufferDescriptor");
static_assert(alignof(CommandBufferDescriptor) == alignof(WGPUCommandBufferDescriptor), "alignof mismatch for CommandBufferDescriptor");
static_assert(offsetof(CommandBufferDescriptor, nextInChain) == offsetof(WGPUCommandBufferDescriptor, nextInChain),
        "offsetof mismatch for CommandBufferDescriptor::nextInChain");
static_assert(offsetof(CommandBufferDescriptor, label) == offsetof(WGPUCommandBufferDescriptor, label),
        "offsetof mismatch for CommandBufferDescriptor::label");

// CommandEncoderDescriptor implementation

CommandEncoderDescriptor::operator const WGPUCommandEncoderDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUCommandEncoderDescriptor*>(this);
}

static_assert(sizeof(CommandEncoderDescriptor) == sizeof(WGPUCommandEncoderDescriptor), "sizeof mismatch for CommandEncoderDescriptor");
static_assert(alignof(CommandEncoderDescriptor) == alignof(WGPUCommandEncoderDescriptor), "alignof mismatch for CommandEncoderDescriptor");
static_assert(offsetof(CommandEncoderDescriptor, nextInChain) == offsetof(WGPUCommandEncoderDescriptor, nextInChain),
        "offsetof mismatch for CommandEncoderDescriptor::nextInChain");
static_assert(offsetof(CommandEncoderDescriptor, label) == offsetof(WGPUCommandEncoderDescriptor, label),
        "offsetof mismatch for CommandEncoderDescriptor::label");

// CompilationInfoCallbackInfo implementation

CompilationInfoCallbackInfo::operator const WGPUCompilationInfoCallbackInfo&() const noexcept {
    return *reinterpret_cast<const WGPUCompilationInfoCallbackInfo*>(this);
}

static_assert(sizeof(CompilationInfoCallbackInfo) == sizeof(WGPUCompilationInfoCallbackInfo), "sizeof mismatch for CompilationInfoCallbackInfo");
static_assert(alignof(CompilationInfoCallbackInfo) == alignof(WGPUCompilationInfoCallbackInfo), "alignof mismatch for CompilationInfoCallbackInfo");
static_assert(offsetof(CompilationInfoCallbackInfo, nextInChain) == offsetof(WGPUCompilationInfoCallbackInfo, nextInChain),
        "offsetof mismatch for CompilationInfoCallbackInfo::nextInChain");
static_assert(offsetof(CompilationInfoCallbackInfo, mode) == offsetof(WGPUCompilationInfoCallbackInfo, mode),
        "offsetof mismatch for CompilationInfoCallbackInfo::mode");
static_assert(offsetof(CompilationInfoCallbackInfo, callback) == offsetof(WGPUCompilationInfoCallbackInfo, callback),
        "offsetof mismatch for CompilationInfoCallbackInfo::callback");
static_assert(offsetof(CompilationInfoCallbackInfo, userdata) == offsetof(WGPUCompilationInfoCallbackInfo, userdata),
        "offsetof mismatch for CompilationInfoCallbackInfo::userdata");

// CompilationMessage implementation

CompilationMessage::operator const WGPUCompilationMessage&() const noexcept {
    return *reinterpret_cast<const WGPUCompilationMessage*>(this);
}

static_assert(sizeof(CompilationMessage) == sizeof(WGPUCompilationMessage), "sizeof mismatch for CompilationMessage");
static_assert(alignof(CompilationMessage) == alignof(WGPUCompilationMessage), "alignof mismatch for CompilationMessage");
static_assert(offsetof(CompilationMessage, nextInChain) == offsetof(WGPUCompilationMessage, nextInChain),
        "offsetof mismatch for CompilationMessage::nextInChain");
static_assert(offsetof(CompilationMessage, message) == offsetof(WGPUCompilationMessage, message),
        "offsetof mismatch for CompilationMessage::message");
static_assert(offsetof(CompilationMessage, type) == offsetof(WGPUCompilationMessage, type),
        "offsetof mismatch for CompilationMessage::type");
static_assert(offsetof(CompilationMessage, lineNum) == offsetof(WGPUCompilationMessage, lineNum),
        "offsetof mismatch for CompilationMessage::lineNum");
static_assert(offsetof(CompilationMessage, linePos) == offsetof(WGPUCompilationMessage, linePos),
        "offsetof mismatch for CompilationMessage::linePos");
static_assert(offsetof(CompilationMessage, offset) == offsetof(WGPUCompilationMessage, offset),
        "offsetof mismatch for CompilationMessage::offset");
static_assert(offsetof(CompilationMessage, length) == offsetof(WGPUCompilationMessage, length),
        "offsetof mismatch for CompilationMessage::length");
static_assert(offsetof(CompilationMessage, utf16LinePos) == offsetof(WGPUCompilationMessage, utf16LinePos),
        "offsetof mismatch for CompilationMessage::utf16LinePos");
static_assert(offsetof(CompilationMessage, utf16Offset) == offsetof(WGPUCompilationMessage, utf16Offset),
        "offsetof mismatch for CompilationMessage::utf16Offset");
static_assert(offsetof(CompilationMessage, utf16Length) == offsetof(WGPUCompilationMessage, utf16Length),
        "offsetof mismatch for CompilationMessage::utf16Length");

// ComputePassTimestampWrites implementation

ComputePassTimestampWrites::operator const WGPUComputePassTimestampWrites&() const noexcept {
    return *reinterpret_cast<const WGPUComputePassTimestampWrites*>(this);
}

static_assert(sizeof(ComputePassTimestampWrites) == sizeof(WGPUComputePassTimestampWrites), "sizeof mismatch for ComputePassTimestampWrites");
static_assert(alignof(ComputePassTimestampWrites) == alignof(WGPUComputePassTimestampWrites), "alignof mismatch for ComputePassTimestampWrites");
static_assert(offsetof(ComputePassTimestampWrites, querySet) == offsetof(WGPUComputePassTimestampWrites, querySet),
        "offsetof mismatch for ComputePassTimestampWrites::querySet");
static_assert(offsetof(ComputePassTimestampWrites, beginningOfPassWriteIndex) == offsetof(WGPUComputePassTimestampWrites, beginningOfPassWriteIndex),
        "offsetof mismatch for ComputePassTimestampWrites::beginningOfPassWriteIndex");
static_assert(offsetof(ComputePassTimestampWrites, endOfPassWriteIndex) == offsetof(WGPUComputePassTimestampWrites, endOfPassWriteIndex),
        "offsetof mismatch for ComputePassTimestampWrites::endOfPassWriteIndex");

// ConstantEntry implementation

ConstantEntry::operator const WGPUConstantEntry&() const noexcept {
    return *reinterpret_cast<const WGPUConstantEntry*>(this);
}

static_assert(sizeof(ConstantEntry) == sizeof(WGPUConstantEntry), "sizeof mismatch for ConstantEntry");
static_assert(alignof(ConstantEntry) == alignof(WGPUConstantEntry), "alignof mismatch for ConstantEntry");
static_assert(offsetof(ConstantEntry, nextInChain) == offsetof(WGPUConstantEntry, nextInChain),
        "offsetof mismatch for ConstantEntry::nextInChain");
static_assert(offsetof(ConstantEntry, key) == offsetof(WGPUConstantEntry, key),
        "offsetof mismatch for ConstantEntry::key");
static_assert(offsetof(ConstantEntry, value) == offsetof(WGPUConstantEntry, value),
        "offsetof mismatch for ConstantEntry::value");

// CreateComputePipelineAsyncCallbackInfo implementation

CreateComputePipelineAsyncCallbackInfo::operator const WGPUCreateComputePipelineAsyncCallbackInfo&() const noexcept {
    return *reinterpret_cast<const WGPUCreateComputePipelineAsyncCallbackInfo*>(this);
}

static_assert(sizeof(CreateComputePipelineAsyncCallbackInfo) == sizeof(WGPUCreateComputePipelineAsyncCallbackInfo), "sizeof mismatch for CreateComputePipelineAsyncCallbackInfo");
static_assert(alignof(CreateComputePipelineAsyncCallbackInfo) == alignof(WGPUCreateComputePipelineAsyncCallbackInfo), "alignof mismatch for CreateComputePipelineAsyncCallbackInfo");
static_assert(offsetof(CreateComputePipelineAsyncCallbackInfo, nextInChain) == offsetof(WGPUCreateComputePipelineAsyncCallbackInfo, nextInChain),
        "offsetof mismatch for CreateComputePipelineAsyncCallbackInfo::nextInChain");
static_assert(offsetof(CreateComputePipelineAsyncCallbackInfo, mode) == offsetof(WGPUCreateComputePipelineAsyncCallbackInfo, mode),
        "offsetof mismatch for CreateComputePipelineAsyncCallbackInfo::mode");
static_assert(offsetof(CreateComputePipelineAsyncCallbackInfo, callback) == offsetof(WGPUCreateComputePipelineAsyncCallbackInfo, callback),
        "offsetof mismatch for CreateComputePipelineAsyncCallbackInfo::callback");
static_assert(offsetof(CreateComputePipelineAsyncCallbackInfo, userdata) == offsetof(WGPUCreateComputePipelineAsyncCallbackInfo, userdata),
        "offsetof mismatch for CreateComputePipelineAsyncCallbackInfo::userdata");

// CreateRenderPipelineAsyncCallbackInfo implementation

CreateRenderPipelineAsyncCallbackInfo::operator const WGPUCreateRenderPipelineAsyncCallbackInfo&() const noexcept {
    return *reinterpret_cast<const WGPUCreateRenderPipelineAsyncCallbackInfo*>(this);
}

static_assert(sizeof(CreateRenderPipelineAsyncCallbackInfo) == sizeof(WGPUCreateRenderPipelineAsyncCallbackInfo), "sizeof mismatch for CreateRenderPipelineAsyncCallbackInfo");
static_assert(alignof(CreateRenderPipelineAsyncCallbackInfo) == alignof(WGPUCreateRenderPipelineAsyncCallbackInfo), "alignof mismatch for CreateRenderPipelineAsyncCallbackInfo");
static_assert(offsetof(CreateRenderPipelineAsyncCallbackInfo, nextInChain) == offsetof(WGPUCreateRenderPipelineAsyncCallbackInfo, nextInChain),
        "offsetof mismatch for CreateRenderPipelineAsyncCallbackInfo::nextInChain");
static_assert(offsetof(CreateRenderPipelineAsyncCallbackInfo, mode) == offsetof(WGPUCreateRenderPipelineAsyncCallbackInfo, mode),
        "offsetof mismatch for CreateRenderPipelineAsyncCallbackInfo::mode");
static_assert(offsetof(CreateRenderPipelineAsyncCallbackInfo, callback) == offsetof(WGPUCreateRenderPipelineAsyncCallbackInfo, callback),
        "offsetof mismatch for CreateRenderPipelineAsyncCallbackInfo::callback");
static_assert(offsetof(CreateRenderPipelineAsyncCallbackInfo, userdata) == offsetof(WGPUCreateRenderPipelineAsyncCallbackInfo, userdata),
        "offsetof mismatch for CreateRenderPipelineAsyncCallbackInfo::userdata");

// DeviceLostCallbackInfo implementation

DeviceLostCallbackInfo::operator const WGPUDeviceLostCallbackInfo&() const noexcept {
    return *reinterpret_cast<const WGPUDeviceLostCallbackInfo*>(this);
}

static_assert(sizeof(DeviceLostCallbackInfo) == sizeof(WGPUDeviceLostCallbackInfo), "sizeof mismatch for DeviceLostCallbackInfo");
static_assert(alignof(DeviceLostCallbackInfo) == alignof(WGPUDeviceLostCallbackInfo), "alignof mismatch for DeviceLostCallbackInfo");
static_assert(offsetof(DeviceLostCallbackInfo, nextInChain) == offsetof(WGPUDeviceLostCallbackInfo, nextInChain),
        "offsetof mismatch for DeviceLostCallbackInfo::nextInChain");
static_assert(offsetof(DeviceLostCallbackInfo, mode) == offsetof(WGPUDeviceLostCallbackInfo, mode),
        "offsetof mismatch for DeviceLostCallbackInfo::mode");
static_assert(offsetof(DeviceLostCallbackInfo, callback) == offsetof(WGPUDeviceLostCallbackInfo, callback),
        "offsetof mismatch for DeviceLostCallbackInfo::callback");
static_assert(offsetof(DeviceLostCallbackInfo, userdata) == offsetof(WGPUDeviceLostCallbackInfo, userdata),
        "offsetof mismatch for DeviceLostCallbackInfo::userdata");

// Extent3D implementation

Extent3D::operator const WGPUExtent3D&() const noexcept {
    return *reinterpret_cast<const WGPUExtent3D*>(this);
}

static_assert(sizeof(Extent3D) == sizeof(WGPUExtent3D), "sizeof mismatch for Extent3D");
static_assert(alignof(Extent3D) == alignof(WGPUExtent3D), "alignof mismatch for Extent3D");
static_assert(offsetof(Extent3D, width) == offsetof(WGPUExtent3D, width),
        "offsetof mismatch for Extent3D::width");
static_assert(offsetof(Extent3D, height) == offsetof(WGPUExtent3D, height),
        "offsetof mismatch for Extent3D::height");
static_assert(offsetof(Extent3D, depthOrArrayLayers) == offsetof(WGPUExtent3D, depthOrArrayLayers),
        "offsetof mismatch for Extent3D::depthOrArrayLayers");

// Future implementation

Future::operator const WGPUFuture&() const noexcept {
    return *reinterpret_cast<const WGPUFuture*>(this);
}

static_assert(sizeof(Future) == sizeof(WGPUFuture), "sizeof mismatch for Future");
static_assert(alignof(Future) == alignof(WGPUFuture), "alignof mismatch for Future");
static_assert(offsetof(Future, id) == offsetof(WGPUFuture, id),
        "offsetof mismatch for Future::id");

// InstanceFeatures implementation

InstanceFeatures::operator const WGPUInstanceFeatures&() const noexcept {
    return *reinterpret_cast<const WGPUInstanceFeatures*>(this);
}

static_assert(sizeof(InstanceFeatures) == sizeof(WGPUInstanceFeatures), "sizeof mismatch for InstanceFeatures");
static_assert(alignof(InstanceFeatures) == alignof(WGPUInstanceFeatures), "alignof mismatch for InstanceFeatures");
static_assert(offsetof(InstanceFeatures, nextInChain) == offsetof(WGPUInstanceFeatures, nextInChain),
        "offsetof mismatch for InstanceFeatures::nextInChain");
static_assert(offsetof(InstanceFeatures, timedWaitAnyEnable) == offsetof(WGPUInstanceFeatures, timedWaitAnyEnable),
        "offsetof mismatch for InstanceFeatures::timedWaitAnyEnable");
static_assert(offsetof(InstanceFeatures, timedWaitAnyMaxCount) == offsetof(WGPUInstanceFeatures, timedWaitAnyMaxCount),
        "offsetof mismatch for InstanceFeatures::timedWaitAnyMaxCount");

// Limits implementation

Limits::operator const WGPULimits&() const noexcept {
    return *reinterpret_cast<const WGPULimits*>(this);
}

static_assert(sizeof(Limits) == sizeof(WGPULimits), "sizeof mismatch for Limits");
static_assert(alignof(Limits) == alignof(WGPULimits), "alignof mismatch for Limits");
static_assert(offsetof(Limits, maxTextureDimension1D) == offsetof(WGPULimits, maxTextureDimension1D),
        "offsetof mismatch for Limits::maxTextureDimension1D");
static_assert(offsetof(Limits, maxTextureDimension2D) == offsetof(WGPULimits, maxTextureDimension2D),
        "offsetof mismatch for Limits::maxTextureDimension2D");
static_assert(offsetof(Limits, maxTextureDimension3D) == offsetof(WGPULimits, maxTextureDimension3D),
        "offsetof mismatch for Limits::maxTextureDimension3D");
static_assert(offsetof(Limits, maxTextureArrayLayers) == offsetof(WGPULimits, maxTextureArrayLayers),
        "offsetof mismatch for Limits::maxTextureArrayLayers");
static_assert(offsetof(Limits, maxBindGroups) == offsetof(WGPULimits, maxBindGroups),
        "offsetof mismatch for Limits::maxBindGroups");
static_assert(offsetof(Limits, maxBindGroupsPlusVertexBuffers) == offsetof(WGPULimits, maxBindGroupsPlusVertexBuffers),
        "offsetof mismatch for Limits::maxBindGroupsPlusVertexBuffers");
static_assert(offsetof(Limits, maxBindingsPerBindGroup) == offsetof(WGPULimits, maxBindingsPerBindGroup),
        "offsetof mismatch for Limits::maxBindingsPerBindGroup");
static_assert(offsetof(Limits, maxDynamicUniformBuffersPerPipelineLayout) == offsetof(WGPULimits, maxDynamicUniformBuffersPerPipelineLayout),
        "offsetof mismatch for Limits::maxDynamicUniformBuffersPerPipelineLayout");
static_assert(offsetof(Limits, maxDynamicStorageBuffersPerPipelineLayout) == offsetof(WGPULimits, maxDynamicStorageBuffersPerPipelineLayout),
        "offsetof mismatch for Limits::maxDynamicStorageBuffersPerPipelineLayout");
static_assert(offsetof(Limits, maxSampledTexturesPerShaderStage) == offsetof(WGPULimits, maxSampledTexturesPerShaderStage),
        "offsetof mismatch for Limits::maxSampledTexturesPerShaderStage");
static_assert(offsetof(Limits, maxSamplersPerShaderStage) == offsetof(WGPULimits, maxSamplersPerShaderStage),
        "offsetof mismatch for Limits::maxSamplersPerShaderStage");
static_assert(offsetof(Limits, maxStorageBuffersPerShaderStage) == offsetof(WGPULimits, maxStorageBuffersPerShaderStage),
        "offsetof mismatch for Limits::maxStorageBuffersPerShaderStage");
static_assert(offsetof(Limits, maxStorageTexturesPerShaderStage) == offsetof(WGPULimits, maxStorageTexturesPerShaderStage),
        "offsetof mismatch for Limits::maxStorageTexturesPerShaderStage");
static_assert(offsetof(Limits, maxUniformBuffersPerShaderStage) == offsetof(WGPULimits, maxUniformBuffersPerShaderStage),
        "offsetof mismatch for Limits::maxUniformBuffersPerShaderStage");
static_assert(offsetof(Limits, maxUniformBufferBindingSize) == offsetof(WGPULimits, maxUniformBufferBindingSize),
        "offsetof mismatch for Limits::maxUniformBufferBindingSize");
static_assert(offsetof(Limits, maxStorageBufferBindingSize) == offsetof(WGPULimits, maxStorageBufferBindingSize),
        "offsetof mismatch for Limits::maxStorageBufferBindingSize");
static_assert(offsetof(Limits, minUniformBufferOffsetAlignment) == offsetof(WGPULimits, minUniformBufferOffsetAlignment),
        "offsetof mismatch for Limits::minUniformBufferOffsetAlignment");
static_assert(offsetof(Limits, minStorageBufferOffsetAlignment) == offsetof(WGPULimits, minStorageBufferOffsetAlignment),
        "offsetof mismatch for Limits::minStorageBufferOffsetAlignment");
static_assert(offsetof(Limits, maxVertexBuffers) == offsetof(WGPULimits, maxVertexBuffers),
        "offsetof mismatch for Limits::maxVertexBuffers");
static_assert(offsetof(Limits, maxBufferSize) == offsetof(WGPULimits, maxBufferSize),
        "offsetof mismatch for Limits::maxBufferSize");
static_assert(offsetof(Limits, maxVertexAttributes) == offsetof(WGPULimits, maxVertexAttributes),
        "offsetof mismatch for Limits::maxVertexAttributes");
static_assert(offsetof(Limits, maxVertexBufferArrayStride) == offsetof(WGPULimits, maxVertexBufferArrayStride),
        "offsetof mismatch for Limits::maxVertexBufferArrayStride");
static_assert(offsetof(Limits, maxInterStageShaderComponents) == offsetof(WGPULimits, maxInterStageShaderComponents),
        "offsetof mismatch for Limits::maxInterStageShaderComponents");
static_assert(offsetof(Limits, maxInterStageShaderVariables) == offsetof(WGPULimits, maxInterStageShaderVariables),
        "offsetof mismatch for Limits::maxInterStageShaderVariables");
static_assert(offsetof(Limits, maxColorAttachments) == offsetof(WGPULimits, maxColorAttachments),
        "offsetof mismatch for Limits::maxColorAttachments");
static_assert(offsetof(Limits, maxColorAttachmentBytesPerSample) == offsetof(WGPULimits, maxColorAttachmentBytesPerSample),
        "offsetof mismatch for Limits::maxColorAttachmentBytesPerSample");
static_assert(offsetof(Limits, maxComputeWorkgroupStorageSize) == offsetof(WGPULimits, maxComputeWorkgroupStorageSize),
        "offsetof mismatch for Limits::maxComputeWorkgroupStorageSize");
static_assert(offsetof(Limits, maxComputeInvocationsPerWorkgroup) == offsetof(WGPULimits, maxComputeInvocationsPerWorkgroup),
        "offsetof mismatch for Limits::maxComputeInvocationsPerWorkgroup");
static_assert(offsetof(Limits, maxComputeWorkgroupSizeX) == offsetof(WGPULimits, maxComputeWorkgroupSizeX),
        "offsetof mismatch for Limits::maxComputeWorkgroupSizeX");
static_assert(offsetof(Limits, maxComputeWorkgroupSizeY) == offsetof(WGPULimits, maxComputeWorkgroupSizeY),
        "offsetof mismatch for Limits::maxComputeWorkgroupSizeY");
static_assert(offsetof(Limits, maxComputeWorkgroupSizeZ) == offsetof(WGPULimits, maxComputeWorkgroupSizeZ),
        "offsetof mismatch for Limits::maxComputeWorkgroupSizeZ");
static_assert(offsetof(Limits, maxComputeWorkgroupsPerDimension) == offsetof(WGPULimits, maxComputeWorkgroupsPerDimension),
        "offsetof mismatch for Limits::maxComputeWorkgroupsPerDimension");

// MultisampleState implementation

MultisampleState::operator const WGPUMultisampleState&() const noexcept {
    return *reinterpret_cast<const WGPUMultisampleState*>(this);
}

static_assert(sizeof(MultisampleState) == sizeof(WGPUMultisampleState), "sizeof mismatch for MultisampleState");
static_assert(alignof(MultisampleState) == alignof(WGPUMultisampleState), "alignof mismatch for MultisampleState");
static_assert(offsetof(MultisampleState, nextInChain) == offsetof(WGPUMultisampleState, nextInChain),
        "offsetof mismatch for MultisampleState::nextInChain");
static_assert(offsetof(MultisampleState, count) == offsetof(WGPUMultisampleState, count),
        "offsetof mismatch for MultisampleState::count");
static_assert(offsetof(MultisampleState, mask) == offsetof(WGPUMultisampleState, mask),
        "offsetof mismatch for MultisampleState::mask");
static_assert(offsetof(MultisampleState, alphaToCoverageEnabled) == offsetof(WGPUMultisampleState, alphaToCoverageEnabled),
        "offsetof mismatch for MultisampleState::alphaToCoverageEnabled");

// Origin3D implementation

Origin3D::operator const WGPUOrigin3D&() const noexcept {
    return *reinterpret_cast<const WGPUOrigin3D*>(this);
}

static_assert(sizeof(Origin3D) == sizeof(WGPUOrigin3D), "sizeof mismatch for Origin3D");
static_assert(alignof(Origin3D) == alignof(WGPUOrigin3D), "alignof mismatch for Origin3D");
static_assert(offsetof(Origin3D, x) == offsetof(WGPUOrigin3D, x),
        "offsetof mismatch for Origin3D::x");
static_assert(offsetof(Origin3D, y) == offsetof(WGPUOrigin3D, y),
        "offsetof mismatch for Origin3D::y");
static_assert(offsetof(Origin3D, z) == offsetof(WGPUOrigin3D, z),
        "offsetof mismatch for Origin3D::z");

// PipelineLayoutDescriptor implementation

PipelineLayoutDescriptor::operator const WGPUPipelineLayoutDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUPipelineLayoutDescriptor*>(this);
}

static_assert(sizeof(PipelineLayoutDescriptor) == sizeof(WGPUPipelineLayoutDescriptor), "sizeof mismatch for PipelineLayoutDescriptor");
static_assert(alignof(PipelineLayoutDescriptor) == alignof(WGPUPipelineLayoutDescriptor), "alignof mismatch for PipelineLayoutDescriptor");
static_assert(offsetof(PipelineLayoutDescriptor, nextInChain) == offsetof(WGPUPipelineLayoutDescriptor, nextInChain),
        "offsetof mismatch for PipelineLayoutDescriptor::nextInChain");
static_assert(offsetof(PipelineLayoutDescriptor, label) == offsetof(WGPUPipelineLayoutDescriptor, label),
        "offsetof mismatch for PipelineLayoutDescriptor::label");
static_assert(offsetof(PipelineLayoutDescriptor, bindGroupLayoutCount) == offsetof(WGPUPipelineLayoutDescriptor, bindGroupLayoutCount),
        "offsetof mismatch for PipelineLayoutDescriptor::bindGroupLayoutCount");
static_assert(offsetof(PipelineLayoutDescriptor, bindGroupLayouts) == offsetof(WGPUPipelineLayoutDescriptor, bindGroupLayouts),
        "offsetof mismatch for PipelineLayoutDescriptor::bindGroupLayouts");

// PopErrorScopeCallbackInfo implementation

PopErrorScopeCallbackInfo::operator const WGPUPopErrorScopeCallbackInfo&() const noexcept {
    return *reinterpret_cast<const WGPUPopErrorScopeCallbackInfo*>(this);
}

static_assert(sizeof(PopErrorScopeCallbackInfo) == sizeof(WGPUPopErrorScopeCallbackInfo), "sizeof mismatch for PopErrorScopeCallbackInfo");
static_assert(alignof(PopErrorScopeCallbackInfo) == alignof(WGPUPopErrorScopeCallbackInfo), "alignof mismatch for PopErrorScopeCallbackInfo");
static_assert(offsetof(PopErrorScopeCallbackInfo, nextInChain) == offsetof(WGPUPopErrorScopeCallbackInfo, nextInChain),
        "offsetof mismatch for PopErrorScopeCallbackInfo::nextInChain");
static_assert(offsetof(PopErrorScopeCallbackInfo, mode) == offsetof(WGPUPopErrorScopeCallbackInfo, mode),
        "offsetof mismatch for PopErrorScopeCallbackInfo::mode");
static_assert(offsetof(PopErrorScopeCallbackInfo, callback) == offsetof(WGPUPopErrorScopeCallbackInfo, callback),
        "offsetof mismatch for PopErrorScopeCallbackInfo::callback");
static_assert(offsetof(PopErrorScopeCallbackInfo, oldCallback) == offsetof(WGPUPopErrorScopeCallbackInfo, oldCallback),
        "offsetof mismatch for PopErrorScopeCallbackInfo::oldCallback");
static_assert(offsetof(PopErrorScopeCallbackInfo, userdata) == offsetof(WGPUPopErrorScopeCallbackInfo, userdata),
        "offsetof mismatch for PopErrorScopeCallbackInfo::userdata");

// PrimitiveDepthClipControl implementation
PrimitiveDepthClipControl::PrimitiveDepthClipControl()
  : ChainedStruct { nullptr, SType::PrimitiveDepthClipControl } {}
struct PrimitiveDepthClipControl::Init {
    ChainedStruct * const nextInChain;
    Bool unclippedDepth = false;
};
PrimitiveDepthClipControl::PrimitiveDepthClipControl(PrimitiveDepthClipControl::Init&& init)
  : ChainedStruct { init.nextInChain, SType::PrimitiveDepthClipControl }, 
    unclippedDepth(std::move(init.unclippedDepth)){}

PrimitiveDepthClipControl::operator const WGPUPrimitiveDepthClipControl&() const noexcept {
    return *reinterpret_cast<const WGPUPrimitiveDepthClipControl*>(this);
}

static_assert(sizeof(PrimitiveDepthClipControl) == sizeof(WGPUPrimitiveDepthClipControl), "sizeof mismatch for PrimitiveDepthClipControl");
static_assert(alignof(PrimitiveDepthClipControl) == alignof(WGPUPrimitiveDepthClipControl), "alignof mismatch for PrimitiveDepthClipControl");
static_assert(offsetof(PrimitiveDepthClipControl, unclippedDepth) == offsetof(WGPUPrimitiveDepthClipControl, unclippedDepth),
        "offsetof mismatch for PrimitiveDepthClipControl::unclippedDepth");

// PrimitiveState implementation

PrimitiveState::operator const WGPUPrimitiveState&() const noexcept {
    return *reinterpret_cast<const WGPUPrimitiveState*>(this);
}

static_assert(sizeof(PrimitiveState) == sizeof(WGPUPrimitiveState), "sizeof mismatch for PrimitiveState");
static_assert(alignof(PrimitiveState) == alignof(WGPUPrimitiveState), "alignof mismatch for PrimitiveState");
static_assert(offsetof(PrimitiveState, nextInChain) == offsetof(WGPUPrimitiveState, nextInChain),
        "offsetof mismatch for PrimitiveState::nextInChain");
static_assert(offsetof(PrimitiveState, topology) == offsetof(WGPUPrimitiveState, topology),
        "offsetof mismatch for PrimitiveState::topology");
static_assert(offsetof(PrimitiveState, stripIndexFormat) == offsetof(WGPUPrimitiveState, stripIndexFormat),
        "offsetof mismatch for PrimitiveState::stripIndexFormat");
static_assert(offsetof(PrimitiveState, frontFace) == offsetof(WGPUPrimitiveState, frontFace),
        "offsetof mismatch for PrimitiveState::frontFace");
static_assert(offsetof(PrimitiveState, cullMode) == offsetof(WGPUPrimitiveState, cullMode),
        "offsetof mismatch for PrimitiveState::cullMode");

// QuerySetDescriptor implementation

QuerySetDescriptor::operator const WGPUQuerySetDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUQuerySetDescriptor*>(this);
}

static_assert(sizeof(QuerySetDescriptor) == sizeof(WGPUQuerySetDescriptor), "sizeof mismatch for QuerySetDescriptor");
static_assert(alignof(QuerySetDescriptor) == alignof(WGPUQuerySetDescriptor), "alignof mismatch for QuerySetDescriptor");
static_assert(offsetof(QuerySetDescriptor, nextInChain) == offsetof(WGPUQuerySetDescriptor, nextInChain),
        "offsetof mismatch for QuerySetDescriptor::nextInChain");
static_assert(offsetof(QuerySetDescriptor, label) == offsetof(WGPUQuerySetDescriptor, label),
        "offsetof mismatch for QuerySetDescriptor::label");
static_assert(offsetof(QuerySetDescriptor, type) == offsetof(WGPUQuerySetDescriptor, type),
        "offsetof mismatch for QuerySetDescriptor::type");
static_assert(offsetof(QuerySetDescriptor, count) == offsetof(WGPUQuerySetDescriptor, count),
        "offsetof mismatch for QuerySetDescriptor::count");

// QueueDescriptor implementation

QueueDescriptor::operator const WGPUQueueDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUQueueDescriptor*>(this);
}

static_assert(sizeof(QueueDescriptor) == sizeof(WGPUQueueDescriptor), "sizeof mismatch for QueueDescriptor");
static_assert(alignof(QueueDescriptor) == alignof(WGPUQueueDescriptor), "alignof mismatch for QueueDescriptor");
static_assert(offsetof(QueueDescriptor, nextInChain) == offsetof(WGPUQueueDescriptor, nextInChain),
        "offsetof mismatch for QueueDescriptor::nextInChain");
static_assert(offsetof(QueueDescriptor, label) == offsetof(WGPUQueueDescriptor, label),
        "offsetof mismatch for QueueDescriptor::label");

// QueueWorkDoneCallbackInfo implementation

QueueWorkDoneCallbackInfo::operator const WGPUQueueWorkDoneCallbackInfo&() const noexcept {
    return *reinterpret_cast<const WGPUQueueWorkDoneCallbackInfo*>(this);
}

static_assert(sizeof(QueueWorkDoneCallbackInfo) == sizeof(WGPUQueueWorkDoneCallbackInfo), "sizeof mismatch for QueueWorkDoneCallbackInfo");
static_assert(alignof(QueueWorkDoneCallbackInfo) == alignof(WGPUQueueWorkDoneCallbackInfo), "alignof mismatch for QueueWorkDoneCallbackInfo");
static_assert(offsetof(QueueWorkDoneCallbackInfo, nextInChain) == offsetof(WGPUQueueWorkDoneCallbackInfo, nextInChain),
        "offsetof mismatch for QueueWorkDoneCallbackInfo::nextInChain");
static_assert(offsetof(QueueWorkDoneCallbackInfo, mode) == offsetof(WGPUQueueWorkDoneCallbackInfo, mode),
        "offsetof mismatch for QueueWorkDoneCallbackInfo::mode");
static_assert(offsetof(QueueWorkDoneCallbackInfo, callback) == offsetof(WGPUQueueWorkDoneCallbackInfo, callback),
        "offsetof mismatch for QueueWorkDoneCallbackInfo::callback");
static_assert(offsetof(QueueWorkDoneCallbackInfo, userdata) == offsetof(WGPUQueueWorkDoneCallbackInfo, userdata),
        "offsetof mismatch for QueueWorkDoneCallbackInfo::userdata");

// RenderBundleDescriptor implementation

RenderBundleDescriptor::operator const WGPURenderBundleDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPURenderBundleDescriptor*>(this);
}

static_assert(sizeof(RenderBundleDescriptor) == sizeof(WGPURenderBundleDescriptor), "sizeof mismatch for RenderBundleDescriptor");
static_assert(alignof(RenderBundleDescriptor) == alignof(WGPURenderBundleDescriptor), "alignof mismatch for RenderBundleDescriptor");
static_assert(offsetof(RenderBundleDescriptor, nextInChain) == offsetof(WGPURenderBundleDescriptor, nextInChain),
        "offsetof mismatch for RenderBundleDescriptor::nextInChain");
static_assert(offsetof(RenderBundleDescriptor, label) == offsetof(WGPURenderBundleDescriptor, label),
        "offsetof mismatch for RenderBundleDescriptor::label");

// RenderBundleEncoderDescriptor implementation

RenderBundleEncoderDescriptor::operator const WGPURenderBundleEncoderDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPURenderBundleEncoderDescriptor*>(this);
}

static_assert(sizeof(RenderBundleEncoderDescriptor) == sizeof(WGPURenderBundleEncoderDescriptor), "sizeof mismatch for RenderBundleEncoderDescriptor");
static_assert(alignof(RenderBundleEncoderDescriptor) == alignof(WGPURenderBundleEncoderDescriptor), "alignof mismatch for RenderBundleEncoderDescriptor");
static_assert(offsetof(RenderBundleEncoderDescriptor, nextInChain) == offsetof(WGPURenderBundleEncoderDescriptor, nextInChain),
        "offsetof mismatch for RenderBundleEncoderDescriptor::nextInChain");
static_assert(offsetof(RenderBundleEncoderDescriptor, label) == offsetof(WGPURenderBundleEncoderDescriptor, label),
        "offsetof mismatch for RenderBundleEncoderDescriptor::label");
static_assert(offsetof(RenderBundleEncoderDescriptor, colorFormatCount) == offsetof(WGPURenderBundleEncoderDescriptor, colorFormatCount),
        "offsetof mismatch for RenderBundleEncoderDescriptor::colorFormatCount");
static_assert(offsetof(RenderBundleEncoderDescriptor, colorFormats) == offsetof(WGPURenderBundleEncoderDescriptor, colorFormats),
        "offsetof mismatch for RenderBundleEncoderDescriptor::colorFormats");
static_assert(offsetof(RenderBundleEncoderDescriptor, depthStencilFormat) == offsetof(WGPURenderBundleEncoderDescriptor, depthStencilFormat),
        "offsetof mismatch for RenderBundleEncoderDescriptor::depthStencilFormat");
static_assert(offsetof(RenderBundleEncoderDescriptor, sampleCount) == offsetof(WGPURenderBundleEncoderDescriptor, sampleCount),
        "offsetof mismatch for RenderBundleEncoderDescriptor::sampleCount");
static_assert(offsetof(RenderBundleEncoderDescriptor, depthReadOnly) == offsetof(WGPURenderBundleEncoderDescriptor, depthReadOnly),
        "offsetof mismatch for RenderBundleEncoderDescriptor::depthReadOnly");
static_assert(offsetof(RenderBundleEncoderDescriptor, stencilReadOnly) == offsetof(WGPURenderBundleEncoderDescriptor, stencilReadOnly),
        "offsetof mismatch for RenderBundleEncoderDescriptor::stencilReadOnly");

// RenderPassDepthStencilAttachment implementation

RenderPassDepthStencilAttachment::operator const WGPURenderPassDepthStencilAttachment&() const noexcept {
    return *reinterpret_cast<const WGPURenderPassDepthStencilAttachment*>(this);
}

static_assert(sizeof(RenderPassDepthStencilAttachment) == sizeof(WGPURenderPassDepthStencilAttachment), "sizeof mismatch for RenderPassDepthStencilAttachment");
static_assert(alignof(RenderPassDepthStencilAttachment) == alignof(WGPURenderPassDepthStencilAttachment), "alignof mismatch for RenderPassDepthStencilAttachment");
static_assert(offsetof(RenderPassDepthStencilAttachment, view) == offsetof(WGPURenderPassDepthStencilAttachment, view),
        "offsetof mismatch for RenderPassDepthStencilAttachment::view");
static_assert(offsetof(RenderPassDepthStencilAttachment, depthLoadOp) == offsetof(WGPURenderPassDepthStencilAttachment, depthLoadOp),
        "offsetof mismatch for RenderPassDepthStencilAttachment::depthLoadOp");
static_assert(offsetof(RenderPassDepthStencilAttachment, depthStoreOp) == offsetof(WGPURenderPassDepthStencilAttachment, depthStoreOp),
        "offsetof mismatch for RenderPassDepthStencilAttachment::depthStoreOp");
static_assert(offsetof(RenderPassDepthStencilAttachment, depthClearValue) == offsetof(WGPURenderPassDepthStencilAttachment, depthClearValue),
        "offsetof mismatch for RenderPassDepthStencilAttachment::depthClearValue");
static_assert(offsetof(RenderPassDepthStencilAttachment, depthReadOnly) == offsetof(WGPURenderPassDepthStencilAttachment, depthReadOnly),
        "offsetof mismatch for RenderPassDepthStencilAttachment::depthReadOnly");
static_assert(offsetof(RenderPassDepthStencilAttachment, stencilLoadOp) == offsetof(WGPURenderPassDepthStencilAttachment, stencilLoadOp),
        "offsetof mismatch for RenderPassDepthStencilAttachment::stencilLoadOp");
static_assert(offsetof(RenderPassDepthStencilAttachment, stencilStoreOp) == offsetof(WGPURenderPassDepthStencilAttachment, stencilStoreOp),
        "offsetof mismatch for RenderPassDepthStencilAttachment::stencilStoreOp");
static_assert(offsetof(RenderPassDepthStencilAttachment, stencilClearValue) == offsetof(WGPURenderPassDepthStencilAttachment, stencilClearValue),
        "offsetof mismatch for RenderPassDepthStencilAttachment::stencilClearValue");
static_assert(offsetof(RenderPassDepthStencilAttachment, stencilReadOnly) == offsetof(WGPURenderPassDepthStencilAttachment, stencilReadOnly),
        "offsetof mismatch for RenderPassDepthStencilAttachment::stencilReadOnly");

// RenderPassDescriptorMaxDrawCount implementation
RenderPassDescriptorMaxDrawCount::RenderPassDescriptorMaxDrawCount()
  : ChainedStruct { nullptr, SType::RenderPassDescriptorMaxDrawCount } {}
struct RenderPassDescriptorMaxDrawCount::Init {
    ChainedStruct * const nextInChain;
    uint64_t maxDrawCount = 50000000;
};
RenderPassDescriptorMaxDrawCount::RenderPassDescriptorMaxDrawCount(RenderPassDescriptorMaxDrawCount::Init&& init)
  : ChainedStruct { init.nextInChain, SType::RenderPassDescriptorMaxDrawCount }, 
    maxDrawCount(std::move(init.maxDrawCount)){}

RenderPassDescriptorMaxDrawCount::operator const WGPURenderPassDescriptorMaxDrawCount&() const noexcept {
    return *reinterpret_cast<const WGPURenderPassDescriptorMaxDrawCount*>(this);
}

static_assert(sizeof(RenderPassDescriptorMaxDrawCount) == sizeof(WGPURenderPassDescriptorMaxDrawCount), "sizeof mismatch for RenderPassDescriptorMaxDrawCount");
static_assert(alignof(RenderPassDescriptorMaxDrawCount) == alignof(WGPURenderPassDescriptorMaxDrawCount), "alignof mismatch for RenderPassDescriptorMaxDrawCount");
static_assert(offsetof(RenderPassDescriptorMaxDrawCount, maxDrawCount) == offsetof(WGPURenderPassDescriptorMaxDrawCount, maxDrawCount),
        "offsetof mismatch for RenderPassDescriptorMaxDrawCount::maxDrawCount");

// RenderPassTimestampWrites implementation

RenderPassTimestampWrites::operator const WGPURenderPassTimestampWrites&() const noexcept {
    return *reinterpret_cast<const WGPURenderPassTimestampWrites*>(this);
}

static_assert(sizeof(RenderPassTimestampWrites) == sizeof(WGPURenderPassTimestampWrites), "sizeof mismatch for RenderPassTimestampWrites");
static_assert(alignof(RenderPassTimestampWrites) == alignof(WGPURenderPassTimestampWrites), "alignof mismatch for RenderPassTimestampWrites");
static_assert(offsetof(RenderPassTimestampWrites, querySet) == offsetof(WGPURenderPassTimestampWrites, querySet),
        "offsetof mismatch for RenderPassTimestampWrites::querySet");
static_assert(offsetof(RenderPassTimestampWrites, beginningOfPassWriteIndex) == offsetof(WGPURenderPassTimestampWrites, beginningOfPassWriteIndex),
        "offsetof mismatch for RenderPassTimestampWrites::beginningOfPassWriteIndex");
static_assert(offsetof(RenderPassTimestampWrites, endOfPassWriteIndex) == offsetof(WGPURenderPassTimestampWrites, endOfPassWriteIndex),
        "offsetof mismatch for RenderPassTimestampWrites::endOfPassWriteIndex");

// RequestAdapterCallbackInfo implementation

RequestAdapterCallbackInfo::operator const WGPURequestAdapterCallbackInfo&() const noexcept {
    return *reinterpret_cast<const WGPURequestAdapterCallbackInfo*>(this);
}

static_assert(sizeof(RequestAdapterCallbackInfo) == sizeof(WGPURequestAdapterCallbackInfo), "sizeof mismatch for RequestAdapterCallbackInfo");
static_assert(alignof(RequestAdapterCallbackInfo) == alignof(WGPURequestAdapterCallbackInfo), "alignof mismatch for RequestAdapterCallbackInfo");
static_assert(offsetof(RequestAdapterCallbackInfo, nextInChain) == offsetof(WGPURequestAdapterCallbackInfo, nextInChain),
        "offsetof mismatch for RequestAdapterCallbackInfo::nextInChain");
static_assert(offsetof(RequestAdapterCallbackInfo, mode) == offsetof(WGPURequestAdapterCallbackInfo, mode),
        "offsetof mismatch for RequestAdapterCallbackInfo::mode");
static_assert(offsetof(RequestAdapterCallbackInfo, callback) == offsetof(WGPURequestAdapterCallbackInfo, callback),
        "offsetof mismatch for RequestAdapterCallbackInfo::callback");
static_assert(offsetof(RequestAdapterCallbackInfo, userdata) == offsetof(WGPURequestAdapterCallbackInfo, userdata),
        "offsetof mismatch for RequestAdapterCallbackInfo::userdata");

// RequestAdapterOptions implementation

RequestAdapterOptions::operator const WGPURequestAdapterOptions&() const noexcept {
    return *reinterpret_cast<const WGPURequestAdapterOptions*>(this);
}

static_assert(sizeof(RequestAdapterOptions) == sizeof(WGPURequestAdapterOptions), "sizeof mismatch for RequestAdapterOptions");
static_assert(alignof(RequestAdapterOptions) == alignof(WGPURequestAdapterOptions), "alignof mismatch for RequestAdapterOptions");
static_assert(offsetof(RequestAdapterOptions, nextInChain) == offsetof(WGPURequestAdapterOptions, nextInChain),
        "offsetof mismatch for RequestAdapterOptions::nextInChain");
static_assert(offsetof(RequestAdapterOptions, compatibleSurface) == offsetof(WGPURequestAdapterOptions, compatibleSurface),
        "offsetof mismatch for RequestAdapterOptions::compatibleSurface");
static_assert(offsetof(RequestAdapterOptions, powerPreference) == offsetof(WGPURequestAdapterOptions, powerPreference),
        "offsetof mismatch for RequestAdapterOptions::powerPreference");
static_assert(offsetof(RequestAdapterOptions, backendType) == offsetof(WGPURequestAdapterOptions, backendType),
        "offsetof mismatch for RequestAdapterOptions::backendType");
static_assert(offsetof(RequestAdapterOptions, forceFallbackAdapter) == offsetof(WGPURequestAdapterOptions, forceFallbackAdapter),
        "offsetof mismatch for RequestAdapterOptions::forceFallbackAdapter");
static_assert(offsetof(RequestAdapterOptions, compatibilityMode) == offsetof(WGPURequestAdapterOptions, compatibilityMode),
        "offsetof mismatch for RequestAdapterOptions::compatibilityMode");

// RequestDeviceCallbackInfo implementation

RequestDeviceCallbackInfo::operator const WGPURequestDeviceCallbackInfo&() const noexcept {
    return *reinterpret_cast<const WGPURequestDeviceCallbackInfo*>(this);
}

static_assert(sizeof(RequestDeviceCallbackInfo) == sizeof(WGPURequestDeviceCallbackInfo), "sizeof mismatch for RequestDeviceCallbackInfo");
static_assert(alignof(RequestDeviceCallbackInfo) == alignof(WGPURequestDeviceCallbackInfo), "alignof mismatch for RequestDeviceCallbackInfo");
static_assert(offsetof(RequestDeviceCallbackInfo, nextInChain) == offsetof(WGPURequestDeviceCallbackInfo, nextInChain),
        "offsetof mismatch for RequestDeviceCallbackInfo::nextInChain");
static_assert(offsetof(RequestDeviceCallbackInfo, mode) == offsetof(WGPURequestDeviceCallbackInfo, mode),
        "offsetof mismatch for RequestDeviceCallbackInfo::mode");
static_assert(offsetof(RequestDeviceCallbackInfo, callback) == offsetof(WGPURequestDeviceCallbackInfo, callback),
        "offsetof mismatch for RequestDeviceCallbackInfo::callback");
static_assert(offsetof(RequestDeviceCallbackInfo, userdata) == offsetof(WGPURequestDeviceCallbackInfo, userdata),
        "offsetof mismatch for RequestDeviceCallbackInfo::userdata");

// SamplerBindingLayout implementation

SamplerBindingLayout::operator const WGPUSamplerBindingLayout&() const noexcept {
    return *reinterpret_cast<const WGPUSamplerBindingLayout*>(this);
}

static_assert(sizeof(SamplerBindingLayout) == sizeof(WGPUSamplerBindingLayout), "sizeof mismatch for SamplerBindingLayout");
static_assert(alignof(SamplerBindingLayout) == alignof(WGPUSamplerBindingLayout), "alignof mismatch for SamplerBindingLayout");
static_assert(offsetof(SamplerBindingLayout, nextInChain) == offsetof(WGPUSamplerBindingLayout, nextInChain),
        "offsetof mismatch for SamplerBindingLayout::nextInChain");
static_assert(offsetof(SamplerBindingLayout, type) == offsetof(WGPUSamplerBindingLayout, type),
        "offsetof mismatch for SamplerBindingLayout::type");

// SamplerDescriptor implementation

SamplerDescriptor::operator const WGPUSamplerDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSamplerDescriptor*>(this);
}

static_assert(sizeof(SamplerDescriptor) == sizeof(WGPUSamplerDescriptor), "sizeof mismatch for SamplerDescriptor");
static_assert(alignof(SamplerDescriptor) == alignof(WGPUSamplerDescriptor), "alignof mismatch for SamplerDescriptor");
static_assert(offsetof(SamplerDescriptor, nextInChain) == offsetof(WGPUSamplerDescriptor, nextInChain),
        "offsetof mismatch for SamplerDescriptor::nextInChain");
static_assert(offsetof(SamplerDescriptor, label) == offsetof(WGPUSamplerDescriptor, label),
        "offsetof mismatch for SamplerDescriptor::label");
static_assert(offsetof(SamplerDescriptor, addressModeU) == offsetof(WGPUSamplerDescriptor, addressModeU),
        "offsetof mismatch for SamplerDescriptor::addressModeU");
static_assert(offsetof(SamplerDescriptor, addressModeV) == offsetof(WGPUSamplerDescriptor, addressModeV),
        "offsetof mismatch for SamplerDescriptor::addressModeV");
static_assert(offsetof(SamplerDescriptor, addressModeW) == offsetof(WGPUSamplerDescriptor, addressModeW),
        "offsetof mismatch for SamplerDescriptor::addressModeW");
static_assert(offsetof(SamplerDescriptor, magFilter) == offsetof(WGPUSamplerDescriptor, magFilter),
        "offsetof mismatch for SamplerDescriptor::magFilter");
static_assert(offsetof(SamplerDescriptor, minFilter) == offsetof(WGPUSamplerDescriptor, minFilter),
        "offsetof mismatch for SamplerDescriptor::minFilter");
static_assert(offsetof(SamplerDescriptor, mipmapFilter) == offsetof(WGPUSamplerDescriptor, mipmapFilter),
        "offsetof mismatch for SamplerDescriptor::mipmapFilter");
static_assert(offsetof(SamplerDescriptor, lodMinClamp) == offsetof(WGPUSamplerDescriptor, lodMinClamp),
        "offsetof mismatch for SamplerDescriptor::lodMinClamp");
static_assert(offsetof(SamplerDescriptor, lodMaxClamp) == offsetof(WGPUSamplerDescriptor, lodMaxClamp),
        "offsetof mismatch for SamplerDescriptor::lodMaxClamp");
static_assert(offsetof(SamplerDescriptor, compare) == offsetof(WGPUSamplerDescriptor, compare),
        "offsetof mismatch for SamplerDescriptor::compare");
static_assert(offsetof(SamplerDescriptor, maxAnisotropy) == offsetof(WGPUSamplerDescriptor, maxAnisotropy),
        "offsetof mismatch for SamplerDescriptor::maxAnisotropy");

// ShaderModuleSPIRVDescriptor implementation
ShaderModuleSPIRVDescriptor::ShaderModuleSPIRVDescriptor()
  : ChainedStruct { nullptr, SType::ShaderModuleSPIRVDescriptor } {}
struct ShaderModuleSPIRVDescriptor::Init {
    ChainedStruct * const nextInChain;
    uint32_t codeSize;
    uint32_t const * code;
};
ShaderModuleSPIRVDescriptor::ShaderModuleSPIRVDescriptor(ShaderModuleSPIRVDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::ShaderModuleSPIRVDescriptor }, 
    codeSize(std::move(init.codeSize)), 
    code(std::move(init.code)){}

ShaderModuleSPIRVDescriptor::operator const WGPUShaderModuleSPIRVDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUShaderModuleSPIRVDescriptor*>(this);
}

static_assert(sizeof(ShaderModuleSPIRVDescriptor) == sizeof(WGPUShaderModuleSPIRVDescriptor), "sizeof mismatch for ShaderModuleSPIRVDescriptor");
static_assert(alignof(ShaderModuleSPIRVDescriptor) == alignof(WGPUShaderModuleSPIRVDescriptor), "alignof mismatch for ShaderModuleSPIRVDescriptor");
static_assert(offsetof(ShaderModuleSPIRVDescriptor, codeSize) == offsetof(WGPUShaderModuleSPIRVDescriptor, codeSize),
        "offsetof mismatch for ShaderModuleSPIRVDescriptor::codeSize");
static_assert(offsetof(ShaderModuleSPIRVDescriptor, code) == offsetof(WGPUShaderModuleSPIRVDescriptor, code),
        "offsetof mismatch for ShaderModuleSPIRVDescriptor::code");

// ShaderModuleWGSLDescriptor implementation
ShaderModuleWGSLDescriptor::ShaderModuleWGSLDescriptor()
  : ChainedStruct { nullptr, SType::ShaderModuleWGSLDescriptor } {}
struct ShaderModuleWGSLDescriptor::Init {
    ChainedStruct * const nextInChain;
    char const * code;
};
ShaderModuleWGSLDescriptor::ShaderModuleWGSLDescriptor(ShaderModuleWGSLDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::ShaderModuleWGSLDescriptor }, 
    code(std::move(init.code)){}

ShaderModuleWGSLDescriptor::operator const WGPUShaderModuleWGSLDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUShaderModuleWGSLDescriptor*>(this);
}

static_assert(sizeof(ShaderModuleWGSLDescriptor) == sizeof(WGPUShaderModuleWGSLDescriptor), "sizeof mismatch for ShaderModuleWGSLDescriptor");
static_assert(alignof(ShaderModuleWGSLDescriptor) == alignof(WGPUShaderModuleWGSLDescriptor), "alignof mismatch for ShaderModuleWGSLDescriptor");
static_assert(offsetof(ShaderModuleWGSLDescriptor, code) == offsetof(WGPUShaderModuleWGSLDescriptor, code),
        "offsetof mismatch for ShaderModuleWGSLDescriptor::code");

// ShaderModuleDescriptor implementation

ShaderModuleDescriptor::operator const WGPUShaderModuleDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUShaderModuleDescriptor*>(this);
}

static_assert(sizeof(ShaderModuleDescriptor) == sizeof(WGPUShaderModuleDescriptor), "sizeof mismatch for ShaderModuleDescriptor");
static_assert(alignof(ShaderModuleDescriptor) == alignof(WGPUShaderModuleDescriptor), "alignof mismatch for ShaderModuleDescriptor");
static_assert(offsetof(ShaderModuleDescriptor, nextInChain) == offsetof(WGPUShaderModuleDescriptor, nextInChain),
        "offsetof mismatch for ShaderModuleDescriptor::nextInChain");
static_assert(offsetof(ShaderModuleDescriptor, label) == offsetof(WGPUShaderModuleDescriptor, label),
        "offsetof mismatch for ShaderModuleDescriptor::label");

// StencilFaceState implementation

StencilFaceState::operator const WGPUStencilFaceState&() const noexcept {
    return *reinterpret_cast<const WGPUStencilFaceState*>(this);
}

static_assert(sizeof(StencilFaceState) == sizeof(WGPUStencilFaceState), "sizeof mismatch for StencilFaceState");
static_assert(alignof(StencilFaceState) == alignof(WGPUStencilFaceState), "alignof mismatch for StencilFaceState");
static_assert(offsetof(StencilFaceState, compare) == offsetof(WGPUStencilFaceState, compare),
        "offsetof mismatch for StencilFaceState::compare");
static_assert(offsetof(StencilFaceState, failOp) == offsetof(WGPUStencilFaceState, failOp),
        "offsetof mismatch for StencilFaceState::failOp");
static_assert(offsetof(StencilFaceState, depthFailOp) == offsetof(WGPUStencilFaceState, depthFailOp),
        "offsetof mismatch for StencilFaceState::depthFailOp");
static_assert(offsetof(StencilFaceState, passOp) == offsetof(WGPUStencilFaceState, passOp),
        "offsetof mismatch for StencilFaceState::passOp");

// StorageTextureBindingLayout implementation

StorageTextureBindingLayout::operator const WGPUStorageTextureBindingLayout&() const noexcept {
    return *reinterpret_cast<const WGPUStorageTextureBindingLayout*>(this);
}

static_assert(sizeof(StorageTextureBindingLayout) == sizeof(WGPUStorageTextureBindingLayout), "sizeof mismatch for StorageTextureBindingLayout");
static_assert(alignof(StorageTextureBindingLayout) == alignof(WGPUStorageTextureBindingLayout), "alignof mismatch for StorageTextureBindingLayout");
static_assert(offsetof(StorageTextureBindingLayout, nextInChain) == offsetof(WGPUStorageTextureBindingLayout, nextInChain),
        "offsetof mismatch for StorageTextureBindingLayout::nextInChain");
static_assert(offsetof(StorageTextureBindingLayout, access) == offsetof(WGPUStorageTextureBindingLayout, access),
        "offsetof mismatch for StorageTextureBindingLayout::access");
static_assert(offsetof(StorageTextureBindingLayout, format) == offsetof(WGPUStorageTextureBindingLayout, format),
        "offsetof mismatch for StorageTextureBindingLayout::format");
static_assert(offsetof(StorageTextureBindingLayout, viewDimension) == offsetof(WGPUStorageTextureBindingLayout, viewDimension),
        "offsetof mismatch for StorageTextureBindingLayout::viewDimension");

// SurfaceCapabilities implementation
SurfaceCapabilities::SurfaceCapabilities() = default;
SurfaceCapabilities::~SurfaceCapabilities() {
    if (this->formats != nullptr || this->presentModes != nullptr || this->alphaModes != nullptr) {
        wgpuSurfaceCapabilitiesFreeMembers(
            *reinterpret_cast<WGPUSurfaceCapabilities*>(this));
    }
}

SurfaceCapabilities::SurfaceCapabilities(SurfaceCapabilities&& rhs)
    : usages(rhs.usages),
            formatCount(rhs.formatCount),
            formats(rhs.formats),
            presentModeCount(rhs.presentModeCount),
            presentModes(rhs.presentModes),
            alphaModeCount(rhs.alphaModeCount),
            alphaModes(rhs.alphaModes){
    Reset(rhs);
}

SurfaceCapabilities& SurfaceCapabilities::operator=(SurfaceCapabilities&& rhs) {
    if (&rhs == this) {
        return *this;
    }
    this->~SurfaceCapabilities();
    detail::AsNonConstReference(this->usages) = std::move(rhs.usages);
    detail::AsNonConstReference(this->formatCount) = std::move(rhs.formatCount);
    detail::AsNonConstReference(this->formats) = std::move(rhs.formats);
    detail::AsNonConstReference(this->presentModeCount) = std::move(rhs.presentModeCount);
    detail::AsNonConstReference(this->presentModes) = std::move(rhs.presentModes);
    detail::AsNonConstReference(this->alphaModeCount) = std::move(rhs.alphaModeCount);
    detail::AsNonConstReference(this->alphaModes) = std::move(rhs.alphaModes);
    Reset(rhs);
    return *this;
}

    // static
void SurfaceCapabilities::Reset(SurfaceCapabilities& value) {
    SurfaceCapabilities defaultValue{};
    detail::AsNonConstReference(value.usages) = defaultValue.usages;
    detail::AsNonConstReference(value.formatCount) = defaultValue.formatCount;
    detail::AsNonConstReference(value.formats) = defaultValue.formats;
    detail::AsNonConstReference(value.presentModeCount) = defaultValue.presentModeCount;
    detail::AsNonConstReference(value.presentModes) = defaultValue.presentModes;
    detail::AsNonConstReference(value.alphaModeCount) = defaultValue.alphaModeCount;
    detail::AsNonConstReference(value.alphaModes) = defaultValue.alphaModes;
}

SurfaceCapabilities::operator const WGPUSurfaceCapabilities&() const noexcept {
    return *reinterpret_cast<const WGPUSurfaceCapabilities*>(this);
}

static_assert(sizeof(SurfaceCapabilities) == sizeof(WGPUSurfaceCapabilities), "sizeof mismatch for SurfaceCapabilities");
static_assert(alignof(SurfaceCapabilities) == alignof(WGPUSurfaceCapabilities), "alignof mismatch for SurfaceCapabilities");
static_assert(offsetof(SurfaceCapabilities, nextInChain) == offsetof(WGPUSurfaceCapabilities, nextInChain),
        "offsetof mismatch for SurfaceCapabilities::nextInChain");
static_assert(offsetof(SurfaceCapabilities, usages) == offsetof(WGPUSurfaceCapabilities, usages),
        "offsetof mismatch for SurfaceCapabilities::usages");
static_assert(offsetof(SurfaceCapabilities, formatCount) == offsetof(WGPUSurfaceCapabilities, formatCount),
        "offsetof mismatch for SurfaceCapabilities::formatCount");
static_assert(offsetof(SurfaceCapabilities, formats) == offsetof(WGPUSurfaceCapabilities, formats),
        "offsetof mismatch for SurfaceCapabilities::formats");
static_assert(offsetof(SurfaceCapabilities, presentModeCount) == offsetof(WGPUSurfaceCapabilities, presentModeCount),
        "offsetof mismatch for SurfaceCapabilities::presentModeCount");
static_assert(offsetof(SurfaceCapabilities, presentModes) == offsetof(WGPUSurfaceCapabilities, presentModes),
        "offsetof mismatch for SurfaceCapabilities::presentModes");
static_assert(offsetof(SurfaceCapabilities, alphaModeCount) == offsetof(WGPUSurfaceCapabilities, alphaModeCount),
        "offsetof mismatch for SurfaceCapabilities::alphaModeCount");
static_assert(offsetof(SurfaceCapabilities, alphaModes) == offsetof(WGPUSurfaceCapabilities, alphaModes),
        "offsetof mismatch for SurfaceCapabilities::alphaModes");

// SurfaceConfiguration implementation

SurfaceConfiguration::operator const WGPUSurfaceConfiguration&() const noexcept {
    return *reinterpret_cast<const WGPUSurfaceConfiguration*>(this);
}

static_assert(sizeof(SurfaceConfiguration) == sizeof(WGPUSurfaceConfiguration), "sizeof mismatch for SurfaceConfiguration");
static_assert(alignof(SurfaceConfiguration) == alignof(WGPUSurfaceConfiguration), "alignof mismatch for SurfaceConfiguration");
static_assert(offsetof(SurfaceConfiguration, nextInChain) == offsetof(WGPUSurfaceConfiguration, nextInChain),
        "offsetof mismatch for SurfaceConfiguration::nextInChain");
static_assert(offsetof(SurfaceConfiguration, device) == offsetof(WGPUSurfaceConfiguration, device),
        "offsetof mismatch for SurfaceConfiguration::device");
static_assert(offsetof(SurfaceConfiguration, format) == offsetof(WGPUSurfaceConfiguration, format),
        "offsetof mismatch for SurfaceConfiguration::format");
static_assert(offsetof(SurfaceConfiguration, usage) == offsetof(WGPUSurfaceConfiguration, usage),
        "offsetof mismatch for SurfaceConfiguration::usage");
static_assert(offsetof(SurfaceConfiguration, viewFormatCount) == offsetof(WGPUSurfaceConfiguration, viewFormatCount),
        "offsetof mismatch for SurfaceConfiguration::viewFormatCount");
static_assert(offsetof(SurfaceConfiguration, viewFormats) == offsetof(WGPUSurfaceConfiguration, viewFormats),
        "offsetof mismatch for SurfaceConfiguration::viewFormats");
static_assert(offsetof(SurfaceConfiguration, alphaMode) == offsetof(WGPUSurfaceConfiguration, alphaMode),
        "offsetof mismatch for SurfaceConfiguration::alphaMode");
static_assert(offsetof(SurfaceConfiguration, width) == offsetof(WGPUSurfaceConfiguration, width),
        "offsetof mismatch for SurfaceConfiguration::width");
static_assert(offsetof(SurfaceConfiguration, height) == offsetof(WGPUSurfaceConfiguration, height),
        "offsetof mismatch for SurfaceConfiguration::height");
static_assert(offsetof(SurfaceConfiguration, presentMode) == offsetof(WGPUSurfaceConfiguration, presentMode),
        "offsetof mismatch for SurfaceConfiguration::presentMode");

// SurfaceDescriptor implementation

SurfaceDescriptor::operator const WGPUSurfaceDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSurfaceDescriptor*>(this);
}

static_assert(sizeof(SurfaceDescriptor) == sizeof(WGPUSurfaceDescriptor), "sizeof mismatch for SurfaceDescriptor");
static_assert(alignof(SurfaceDescriptor) == alignof(WGPUSurfaceDescriptor), "alignof mismatch for SurfaceDescriptor");
static_assert(offsetof(SurfaceDescriptor, nextInChain) == offsetof(WGPUSurfaceDescriptor, nextInChain),
        "offsetof mismatch for SurfaceDescriptor::nextInChain");
static_assert(offsetof(SurfaceDescriptor, label) == offsetof(WGPUSurfaceDescriptor, label),
        "offsetof mismatch for SurfaceDescriptor::label");

// SurfaceDescriptorFromCanvasHTMLSelector implementation
SurfaceDescriptorFromCanvasHTMLSelector::SurfaceDescriptorFromCanvasHTMLSelector()
  : ChainedStruct { nullptr, SType::SurfaceDescriptorFromCanvasHTMLSelector } {}
struct SurfaceDescriptorFromCanvasHTMLSelector::Init {
    ChainedStruct * const nextInChain;
    char const * selector;
};
SurfaceDescriptorFromCanvasHTMLSelector::SurfaceDescriptorFromCanvasHTMLSelector(SurfaceDescriptorFromCanvasHTMLSelector::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SurfaceDescriptorFromCanvasHTMLSelector }, 
    selector(std::move(init.selector)){}

SurfaceDescriptorFromCanvasHTMLSelector::operator const WGPUSurfaceDescriptorFromCanvasHTMLSelector&() const noexcept {
    return *reinterpret_cast<const WGPUSurfaceDescriptorFromCanvasHTMLSelector*>(this);
}

static_assert(sizeof(SurfaceDescriptorFromCanvasHTMLSelector) == sizeof(WGPUSurfaceDescriptorFromCanvasHTMLSelector), "sizeof mismatch for SurfaceDescriptorFromCanvasHTMLSelector");
static_assert(alignof(SurfaceDescriptorFromCanvasHTMLSelector) == alignof(WGPUSurfaceDescriptorFromCanvasHTMLSelector), "alignof mismatch for SurfaceDescriptorFromCanvasHTMLSelector");
static_assert(offsetof(SurfaceDescriptorFromCanvasHTMLSelector, selector) == offsetof(WGPUSurfaceDescriptorFromCanvasHTMLSelector, selector),
        "offsetof mismatch for SurfaceDescriptorFromCanvasHTMLSelector::selector");

// SurfaceTexture implementation

SurfaceTexture::operator const WGPUSurfaceTexture&() const noexcept {
    return *reinterpret_cast<const WGPUSurfaceTexture*>(this);
}

static_assert(sizeof(SurfaceTexture) == sizeof(WGPUSurfaceTexture), "sizeof mismatch for SurfaceTexture");
static_assert(alignof(SurfaceTexture) == alignof(WGPUSurfaceTexture), "alignof mismatch for SurfaceTexture");
static_assert(offsetof(SurfaceTexture, texture) == offsetof(WGPUSurfaceTexture, texture),
        "offsetof mismatch for SurfaceTexture::texture");
static_assert(offsetof(SurfaceTexture, suboptimal) == offsetof(WGPUSurfaceTexture, suboptimal),
        "offsetof mismatch for SurfaceTexture::suboptimal");
static_assert(offsetof(SurfaceTexture, status) == offsetof(WGPUSurfaceTexture, status),
        "offsetof mismatch for SurfaceTexture::status");

// SwapChainDescriptor implementation

SwapChainDescriptor::operator const WGPUSwapChainDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSwapChainDescriptor*>(this);
}

static_assert(sizeof(SwapChainDescriptor) == sizeof(WGPUSwapChainDescriptor), "sizeof mismatch for SwapChainDescriptor");
static_assert(alignof(SwapChainDescriptor) == alignof(WGPUSwapChainDescriptor), "alignof mismatch for SwapChainDescriptor");
static_assert(offsetof(SwapChainDescriptor, nextInChain) == offsetof(WGPUSwapChainDescriptor, nextInChain),
        "offsetof mismatch for SwapChainDescriptor::nextInChain");
static_assert(offsetof(SwapChainDescriptor, label) == offsetof(WGPUSwapChainDescriptor, label),
        "offsetof mismatch for SwapChainDescriptor::label");
static_assert(offsetof(SwapChainDescriptor, usage) == offsetof(WGPUSwapChainDescriptor, usage),
        "offsetof mismatch for SwapChainDescriptor::usage");
static_assert(offsetof(SwapChainDescriptor, format) == offsetof(WGPUSwapChainDescriptor, format),
        "offsetof mismatch for SwapChainDescriptor::format");
static_assert(offsetof(SwapChainDescriptor, width) == offsetof(WGPUSwapChainDescriptor, width),
        "offsetof mismatch for SwapChainDescriptor::width");
static_assert(offsetof(SwapChainDescriptor, height) == offsetof(WGPUSwapChainDescriptor, height),
        "offsetof mismatch for SwapChainDescriptor::height");
static_assert(offsetof(SwapChainDescriptor, presentMode) == offsetof(WGPUSwapChainDescriptor, presentMode),
        "offsetof mismatch for SwapChainDescriptor::presentMode");

// TextureBindingLayout implementation

TextureBindingLayout::operator const WGPUTextureBindingLayout&() const noexcept {
    return *reinterpret_cast<const WGPUTextureBindingLayout*>(this);
}

static_assert(sizeof(TextureBindingLayout) == sizeof(WGPUTextureBindingLayout), "sizeof mismatch for TextureBindingLayout");
static_assert(alignof(TextureBindingLayout) == alignof(WGPUTextureBindingLayout), "alignof mismatch for TextureBindingLayout");
static_assert(offsetof(TextureBindingLayout, nextInChain) == offsetof(WGPUTextureBindingLayout, nextInChain),
        "offsetof mismatch for TextureBindingLayout::nextInChain");
static_assert(offsetof(TextureBindingLayout, sampleType) == offsetof(WGPUTextureBindingLayout, sampleType),
        "offsetof mismatch for TextureBindingLayout::sampleType");
static_assert(offsetof(TextureBindingLayout, viewDimension) == offsetof(WGPUTextureBindingLayout, viewDimension),
        "offsetof mismatch for TextureBindingLayout::viewDimension");
static_assert(offsetof(TextureBindingLayout, multisampled) == offsetof(WGPUTextureBindingLayout, multisampled),
        "offsetof mismatch for TextureBindingLayout::multisampled");

// TextureBindingViewDimensionDescriptor implementation
TextureBindingViewDimensionDescriptor::TextureBindingViewDimensionDescriptor()
  : ChainedStruct { nullptr, SType::TextureBindingViewDimensionDescriptor } {}
struct TextureBindingViewDimensionDescriptor::Init {
    ChainedStruct * const nextInChain;
    TextureViewDimension textureBindingViewDimension = TextureViewDimension::Undefined;
};
TextureBindingViewDimensionDescriptor::TextureBindingViewDimensionDescriptor(TextureBindingViewDimensionDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::TextureBindingViewDimensionDescriptor }, 
    textureBindingViewDimension(std::move(init.textureBindingViewDimension)){}

TextureBindingViewDimensionDescriptor::operator const WGPUTextureBindingViewDimensionDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUTextureBindingViewDimensionDescriptor*>(this);
}

static_assert(sizeof(TextureBindingViewDimensionDescriptor) == sizeof(WGPUTextureBindingViewDimensionDescriptor), "sizeof mismatch for TextureBindingViewDimensionDescriptor");
static_assert(alignof(TextureBindingViewDimensionDescriptor) == alignof(WGPUTextureBindingViewDimensionDescriptor), "alignof mismatch for TextureBindingViewDimensionDescriptor");
static_assert(offsetof(TextureBindingViewDimensionDescriptor, textureBindingViewDimension) == offsetof(WGPUTextureBindingViewDimensionDescriptor, textureBindingViewDimension),
        "offsetof mismatch for TextureBindingViewDimensionDescriptor::textureBindingViewDimension");

// TextureDataLayout implementation

TextureDataLayout::operator const WGPUTextureDataLayout&() const noexcept {
    return *reinterpret_cast<const WGPUTextureDataLayout*>(this);
}

static_assert(sizeof(TextureDataLayout) == sizeof(WGPUTextureDataLayout), "sizeof mismatch for TextureDataLayout");
static_assert(alignof(TextureDataLayout) == alignof(WGPUTextureDataLayout), "alignof mismatch for TextureDataLayout");
static_assert(offsetof(TextureDataLayout, nextInChain) == offsetof(WGPUTextureDataLayout, nextInChain),
        "offsetof mismatch for TextureDataLayout::nextInChain");
static_assert(offsetof(TextureDataLayout, offset) == offsetof(WGPUTextureDataLayout, offset),
        "offsetof mismatch for TextureDataLayout::offset");
static_assert(offsetof(TextureDataLayout, bytesPerRow) == offsetof(WGPUTextureDataLayout, bytesPerRow),
        "offsetof mismatch for TextureDataLayout::bytesPerRow");
static_assert(offsetof(TextureDataLayout, rowsPerImage) == offsetof(WGPUTextureDataLayout, rowsPerImage),
        "offsetof mismatch for TextureDataLayout::rowsPerImage");

// TextureViewDescriptor implementation

TextureViewDescriptor::operator const WGPUTextureViewDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUTextureViewDescriptor*>(this);
}

static_assert(sizeof(TextureViewDescriptor) == sizeof(WGPUTextureViewDescriptor), "sizeof mismatch for TextureViewDescriptor");
static_assert(alignof(TextureViewDescriptor) == alignof(WGPUTextureViewDescriptor), "alignof mismatch for TextureViewDescriptor");
static_assert(offsetof(TextureViewDescriptor, nextInChain) == offsetof(WGPUTextureViewDescriptor, nextInChain),
        "offsetof mismatch for TextureViewDescriptor::nextInChain");
static_assert(offsetof(TextureViewDescriptor, label) == offsetof(WGPUTextureViewDescriptor, label),
        "offsetof mismatch for TextureViewDescriptor::label");
static_assert(offsetof(TextureViewDescriptor, format) == offsetof(WGPUTextureViewDescriptor, format),
        "offsetof mismatch for TextureViewDescriptor::format");
static_assert(offsetof(TextureViewDescriptor, dimension) == offsetof(WGPUTextureViewDescriptor, dimension),
        "offsetof mismatch for TextureViewDescriptor::dimension");
static_assert(offsetof(TextureViewDescriptor, baseMipLevel) == offsetof(WGPUTextureViewDescriptor, baseMipLevel),
        "offsetof mismatch for TextureViewDescriptor::baseMipLevel");
static_assert(offsetof(TextureViewDescriptor, mipLevelCount) == offsetof(WGPUTextureViewDescriptor, mipLevelCount),
        "offsetof mismatch for TextureViewDescriptor::mipLevelCount");
static_assert(offsetof(TextureViewDescriptor, baseArrayLayer) == offsetof(WGPUTextureViewDescriptor, baseArrayLayer),
        "offsetof mismatch for TextureViewDescriptor::baseArrayLayer");
static_assert(offsetof(TextureViewDescriptor, arrayLayerCount) == offsetof(WGPUTextureViewDescriptor, arrayLayerCount),
        "offsetof mismatch for TextureViewDescriptor::arrayLayerCount");
static_assert(offsetof(TextureViewDescriptor, aspect) == offsetof(WGPUTextureViewDescriptor, aspect),
        "offsetof mismatch for TextureViewDescriptor::aspect");

// UncapturedErrorCallbackInfo implementation

UncapturedErrorCallbackInfo::operator const WGPUUncapturedErrorCallbackInfo&() const noexcept {
    return *reinterpret_cast<const WGPUUncapturedErrorCallbackInfo*>(this);
}

static_assert(sizeof(UncapturedErrorCallbackInfo) == sizeof(WGPUUncapturedErrorCallbackInfo), "sizeof mismatch for UncapturedErrorCallbackInfo");
static_assert(alignof(UncapturedErrorCallbackInfo) == alignof(WGPUUncapturedErrorCallbackInfo), "alignof mismatch for UncapturedErrorCallbackInfo");
static_assert(offsetof(UncapturedErrorCallbackInfo, nextInChain) == offsetof(WGPUUncapturedErrorCallbackInfo, nextInChain),
        "offsetof mismatch for UncapturedErrorCallbackInfo::nextInChain");
static_assert(offsetof(UncapturedErrorCallbackInfo, callback) == offsetof(WGPUUncapturedErrorCallbackInfo, callback),
        "offsetof mismatch for UncapturedErrorCallbackInfo::callback");
static_assert(offsetof(UncapturedErrorCallbackInfo, userdata) == offsetof(WGPUUncapturedErrorCallbackInfo, userdata),
        "offsetof mismatch for UncapturedErrorCallbackInfo::userdata");

// VertexAttribute implementation

VertexAttribute::operator const WGPUVertexAttribute&() const noexcept {
    return *reinterpret_cast<const WGPUVertexAttribute*>(this);
}

static_assert(sizeof(VertexAttribute) == sizeof(WGPUVertexAttribute), "sizeof mismatch for VertexAttribute");
static_assert(alignof(VertexAttribute) == alignof(WGPUVertexAttribute), "alignof mismatch for VertexAttribute");
static_assert(offsetof(VertexAttribute, format) == offsetof(WGPUVertexAttribute, format),
        "offsetof mismatch for VertexAttribute::format");
static_assert(offsetof(VertexAttribute, offset) == offsetof(WGPUVertexAttribute, offset),
        "offsetof mismatch for VertexAttribute::offset");
static_assert(offsetof(VertexAttribute, shaderLocation) == offsetof(WGPUVertexAttribute, shaderLocation),
        "offsetof mismatch for VertexAttribute::shaderLocation");

// BindGroupDescriptor implementation

BindGroupDescriptor::operator const WGPUBindGroupDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUBindGroupDescriptor*>(this);
}

static_assert(sizeof(BindGroupDescriptor) == sizeof(WGPUBindGroupDescriptor), "sizeof mismatch for BindGroupDescriptor");
static_assert(alignof(BindGroupDescriptor) == alignof(WGPUBindGroupDescriptor), "alignof mismatch for BindGroupDescriptor");
static_assert(offsetof(BindGroupDescriptor, nextInChain) == offsetof(WGPUBindGroupDescriptor, nextInChain),
        "offsetof mismatch for BindGroupDescriptor::nextInChain");
static_assert(offsetof(BindGroupDescriptor, label) == offsetof(WGPUBindGroupDescriptor, label),
        "offsetof mismatch for BindGroupDescriptor::label");
static_assert(offsetof(BindGroupDescriptor, layout) == offsetof(WGPUBindGroupDescriptor, layout),
        "offsetof mismatch for BindGroupDescriptor::layout");
static_assert(offsetof(BindGroupDescriptor, entryCount) == offsetof(WGPUBindGroupDescriptor, entryCount),
        "offsetof mismatch for BindGroupDescriptor::entryCount");
static_assert(offsetof(BindGroupDescriptor, entries) == offsetof(WGPUBindGroupDescriptor, entries),
        "offsetof mismatch for BindGroupDescriptor::entries");

// BindGroupLayoutEntry implementation

BindGroupLayoutEntry::operator const WGPUBindGroupLayoutEntry&() const noexcept {
    return *reinterpret_cast<const WGPUBindGroupLayoutEntry*>(this);
}

static_assert(sizeof(BindGroupLayoutEntry) == sizeof(WGPUBindGroupLayoutEntry), "sizeof mismatch for BindGroupLayoutEntry");
static_assert(alignof(BindGroupLayoutEntry) == alignof(WGPUBindGroupLayoutEntry), "alignof mismatch for BindGroupLayoutEntry");
static_assert(offsetof(BindGroupLayoutEntry, nextInChain) == offsetof(WGPUBindGroupLayoutEntry, nextInChain),
        "offsetof mismatch for BindGroupLayoutEntry::nextInChain");
static_assert(offsetof(BindGroupLayoutEntry, binding) == offsetof(WGPUBindGroupLayoutEntry, binding),
        "offsetof mismatch for BindGroupLayoutEntry::binding");
static_assert(offsetof(BindGroupLayoutEntry, visibility) == offsetof(WGPUBindGroupLayoutEntry, visibility),
        "offsetof mismatch for BindGroupLayoutEntry::visibility");
static_assert(offsetof(BindGroupLayoutEntry, buffer) == offsetof(WGPUBindGroupLayoutEntry, buffer),
        "offsetof mismatch for BindGroupLayoutEntry::buffer");
static_assert(offsetof(BindGroupLayoutEntry, sampler) == offsetof(WGPUBindGroupLayoutEntry, sampler),
        "offsetof mismatch for BindGroupLayoutEntry::sampler");
static_assert(offsetof(BindGroupLayoutEntry, texture) == offsetof(WGPUBindGroupLayoutEntry, texture),
        "offsetof mismatch for BindGroupLayoutEntry::texture");
static_assert(offsetof(BindGroupLayoutEntry, storageTexture) == offsetof(WGPUBindGroupLayoutEntry, storageTexture),
        "offsetof mismatch for BindGroupLayoutEntry::storageTexture");

// BlendState implementation

BlendState::operator const WGPUBlendState&() const noexcept {
    return *reinterpret_cast<const WGPUBlendState*>(this);
}

static_assert(sizeof(BlendState) == sizeof(WGPUBlendState), "sizeof mismatch for BlendState");
static_assert(alignof(BlendState) == alignof(WGPUBlendState), "alignof mismatch for BlendState");
static_assert(offsetof(BlendState, color) == offsetof(WGPUBlendState, color),
        "offsetof mismatch for BlendState::color");
static_assert(offsetof(BlendState, alpha) == offsetof(WGPUBlendState, alpha),
        "offsetof mismatch for BlendState::alpha");

// CompilationInfo implementation

CompilationInfo::operator const WGPUCompilationInfo&() const noexcept {
    return *reinterpret_cast<const WGPUCompilationInfo*>(this);
}

static_assert(sizeof(CompilationInfo) == sizeof(WGPUCompilationInfo), "sizeof mismatch for CompilationInfo");
static_assert(alignof(CompilationInfo) == alignof(WGPUCompilationInfo), "alignof mismatch for CompilationInfo");
static_assert(offsetof(CompilationInfo, nextInChain) == offsetof(WGPUCompilationInfo, nextInChain),
        "offsetof mismatch for CompilationInfo::nextInChain");
static_assert(offsetof(CompilationInfo, messageCount) == offsetof(WGPUCompilationInfo, messageCount),
        "offsetof mismatch for CompilationInfo::messageCount");
static_assert(offsetof(CompilationInfo, messages) == offsetof(WGPUCompilationInfo, messages),
        "offsetof mismatch for CompilationInfo::messages");

// ComputePassDescriptor implementation

ComputePassDescriptor::operator const WGPUComputePassDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUComputePassDescriptor*>(this);
}

static_assert(sizeof(ComputePassDescriptor) == sizeof(WGPUComputePassDescriptor), "sizeof mismatch for ComputePassDescriptor");
static_assert(alignof(ComputePassDescriptor) == alignof(WGPUComputePassDescriptor), "alignof mismatch for ComputePassDescriptor");
static_assert(offsetof(ComputePassDescriptor, nextInChain) == offsetof(WGPUComputePassDescriptor, nextInChain),
        "offsetof mismatch for ComputePassDescriptor::nextInChain");
static_assert(offsetof(ComputePassDescriptor, label) == offsetof(WGPUComputePassDescriptor, label),
        "offsetof mismatch for ComputePassDescriptor::label");
static_assert(offsetof(ComputePassDescriptor, timestampWrites) == offsetof(WGPUComputePassDescriptor, timestampWrites),
        "offsetof mismatch for ComputePassDescriptor::timestampWrites");

// DepthStencilState implementation

DepthStencilState::operator const WGPUDepthStencilState&() const noexcept {
    return *reinterpret_cast<const WGPUDepthStencilState*>(this);
}

static_assert(sizeof(DepthStencilState) == sizeof(WGPUDepthStencilState), "sizeof mismatch for DepthStencilState");
static_assert(alignof(DepthStencilState) == alignof(WGPUDepthStencilState), "alignof mismatch for DepthStencilState");
static_assert(offsetof(DepthStencilState, nextInChain) == offsetof(WGPUDepthStencilState, nextInChain),
        "offsetof mismatch for DepthStencilState::nextInChain");
static_assert(offsetof(DepthStencilState, format) == offsetof(WGPUDepthStencilState, format),
        "offsetof mismatch for DepthStencilState::format");
static_assert(offsetof(DepthStencilState, depthWriteEnabled) == offsetof(WGPUDepthStencilState, depthWriteEnabled),
        "offsetof mismatch for DepthStencilState::depthWriteEnabled");
static_assert(offsetof(DepthStencilState, depthCompare) == offsetof(WGPUDepthStencilState, depthCompare),
        "offsetof mismatch for DepthStencilState::depthCompare");
static_assert(offsetof(DepthStencilState, stencilFront) == offsetof(WGPUDepthStencilState, stencilFront),
        "offsetof mismatch for DepthStencilState::stencilFront");
static_assert(offsetof(DepthStencilState, stencilBack) == offsetof(WGPUDepthStencilState, stencilBack),
        "offsetof mismatch for DepthStencilState::stencilBack");
static_assert(offsetof(DepthStencilState, stencilReadMask) == offsetof(WGPUDepthStencilState, stencilReadMask),
        "offsetof mismatch for DepthStencilState::stencilReadMask");
static_assert(offsetof(DepthStencilState, stencilWriteMask) == offsetof(WGPUDepthStencilState, stencilWriteMask),
        "offsetof mismatch for DepthStencilState::stencilWriteMask");
static_assert(offsetof(DepthStencilState, depthBias) == offsetof(WGPUDepthStencilState, depthBias),
        "offsetof mismatch for DepthStencilState::depthBias");
static_assert(offsetof(DepthStencilState, depthBiasSlopeScale) == offsetof(WGPUDepthStencilState, depthBiasSlopeScale),
        "offsetof mismatch for DepthStencilState::depthBiasSlopeScale");
static_assert(offsetof(DepthStencilState, depthBiasClamp) == offsetof(WGPUDepthStencilState, depthBiasClamp),
        "offsetof mismatch for DepthStencilState::depthBiasClamp");

// FutureWaitInfo implementation

FutureWaitInfo::operator const WGPUFutureWaitInfo&() const noexcept {
    return *reinterpret_cast<const WGPUFutureWaitInfo*>(this);
}

static_assert(sizeof(FutureWaitInfo) == sizeof(WGPUFutureWaitInfo), "sizeof mismatch for FutureWaitInfo");
static_assert(alignof(FutureWaitInfo) == alignof(WGPUFutureWaitInfo), "alignof mismatch for FutureWaitInfo");
static_assert(offsetof(FutureWaitInfo, future) == offsetof(WGPUFutureWaitInfo, future),
        "offsetof mismatch for FutureWaitInfo::future");
static_assert(offsetof(FutureWaitInfo, completed) == offsetof(WGPUFutureWaitInfo, completed),
        "offsetof mismatch for FutureWaitInfo::completed");

// ImageCopyBuffer implementation

ImageCopyBuffer::operator const WGPUImageCopyBuffer&() const noexcept {
    return *reinterpret_cast<const WGPUImageCopyBuffer*>(this);
}

static_assert(sizeof(ImageCopyBuffer) == sizeof(WGPUImageCopyBuffer), "sizeof mismatch for ImageCopyBuffer");
static_assert(alignof(ImageCopyBuffer) == alignof(WGPUImageCopyBuffer), "alignof mismatch for ImageCopyBuffer");
static_assert(offsetof(ImageCopyBuffer, layout) == offsetof(WGPUImageCopyBuffer, layout),
        "offsetof mismatch for ImageCopyBuffer::layout");
static_assert(offsetof(ImageCopyBuffer, buffer) == offsetof(WGPUImageCopyBuffer, buffer),
        "offsetof mismatch for ImageCopyBuffer::buffer");

// ImageCopyTexture implementation

ImageCopyTexture::operator const WGPUImageCopyTexture&() const noexcept {
    return *reinterpret_cast<const WGPUImageCopyTexture*>(this);
}

static_assert(sizeof(ImageCopyTexture) == sizeof(WGPUImageCopyTexture), "sizeof mismatch for ImageCopyTexture");
static_assert(alignof(ImageCopyTexture) == alignof(WGPUImageCopyTexture), "alignof mismatch for ImageCopyTexture");
static_assert(offsetof(ImageCopyTexture, texture) == offsetof(WGPUImageCopyTexture, texture),
        "offsetof mismatch for ImageCopyTexture::texture");
static_assert(offsetof(ImageCopyTexture, mipLevel) == offsetof(WGPUImageCopyTexture, mipLevel),
        "offsetof mismatch for ImageCopyTexture::mipLevel");
static_assert(offsetof(ImageCopyTexture, origin) == offsetof(WGPUImageCopyTexture, origin),
        "offsetof mismatch for ImageCopyTexture::origin");
static_assert(offsetof(ImageCopyTexture, aspect) == offsetof(WGPUImageCopyTexture, aspect),
        "offsetof mismatch for ImageCopyTexture::aspect");

// InstanceDescriptor implementation

InstanceDescriptor::operator const WGPUInstanceDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUInstanceDescriptor*>(this);
}

static_assert(sizeof(InstanceDescriptor) == sizeof(WGPUInstanceDescriptor), "sizeof mismatch for InstanceDescriptor");
static_assert(alignof(InstanceDescriptor) == alignof(WGPUInstanceDescriptor), "alignof mismatch for InstanceDescriptor");
static_assert(offsetof(InstanceDescriptor, nextInChain) == offsetof(WGPUInstanceDescriptor, nextInChain),
        "offsetof mismatch for InstanceDescriptor::nextInChain");
static_assert(offsetof(InstanceDescriptor, features) == offsetof(WGPUInstanceDescriptor, features),
        "offsetof mismatch for InstanceDescriptor::features");

// ProgrammableStageDescriptor implementation

ProgrammableStageDescriptor::operator const WGPUProgrammableStageDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUProgrammableStageDescriptor*>(this);
}

static_assert(sizeof(ProgrammableStageDescriptor) == sizeof(WGPUProgrammableStageDescriptor), "sizeof mismatch for ProgrammableStageDescriptor");
static_assert(alignof(ProgrammableStageDescriptor) == alignof(WGPUProgrammableStageDescriptor), "alignof mismatch for ProgrammableStageDescriptor");
static_assert(offsetof(ProgrammableStageDescriptor, nextInChain) == offsetof(WGPUProgrammableStageDescriptor, nextInChain),
        "offsetof mismatch for ProgrammableStageDescriptor::nextInChain");
static_assert(offsetof(ProgrammableStageDescriptor, module) == offsetof(WGPUProgrammableStageDescriptor, module),
        "offsetof mismatch for ProgrammableStageDescriptor::module");
static_assert(offsetof(ProgrammableStageDescriptor, entryPoint) == offsetof(WGPUProgrammableStageDescriptor, entryPoint),
        "offsetof mismatch for ProgrammableStageDescriptor::entryPoint");
static_assert(offsetof(ProgrammableStageDescriptor, constantCount) == offsetof(WGPUProgrammableStageDescriptor, constantCount),
        "offsetof mismatch for ProgrammableStageDescriptor::constantCount");
static_assert(offsetof(ProgrammableStageDescriptor, constants) == offsetof(WGPUProgrammableStageDescriptor, constants),
        "offsetof mismatch for ProgrammableStageDescriptor::constants");

// RenderPassColorAttachment implementation

RenderPassColorAttachment::operator const WGPURenderPassColorAttachment&() const noexcept {
    return *reinterpret_cast<const WGPURenderPassColorAttachment*>(this);
}

static_assert(sizeof(RenderPassColorAttachment) == sizeof(WGPURenderPassColorAttachment), "sizeof mismatch for RenderPassColorAttachment");
static_assert(alignof(RenderPassColorAttachment) == alignof(WGPURenderPassColorAttachment), "alignof mismatch for RenderPassColorAttachment");
static_assert(offsetof(RenderPassColorAttachment, nextInChain) == offsetof(WGPURenderPassColorAttachment, nextInChain),
        "offsetof mismatch for RenderPassColorAttachment::nextInChain");
static_assert(offsetof(RenderPassColorAttachment, view) == offsetof(WGPURenderPassColorAttachment, view),
        "offsetof mismatch for RenderPassColorAttachment::view");
static_assert(offsetof(RenderPassColorAttachment, depthSlice) == offsetof(WGPURenderPassColorAttachment, depthSlice),
        "offsetof mismatch for RenderPassColorAttachment::depthSlice");
static_assert(offsetof(RenderPassColorAttachment, resolveTarget) == offsetof(WGPURenderPassColorAttachment, resolveTarget),
        "offsetof mismatch for RenderPassColorAttachment::resolveTarget");
static_assert(offsetof(RenderPassColorAttachment, loadOp) == offsetof(WGPURenderPassColorAttachment, loadOp),
        "offsetof mismatch for RenderPassColorAttachment::loadOp");
static_assert(offsetof(RenderPassColorAttachment, storeOp) == offsetof(WGPURenderPassColorAttachment, storeOp),
        "offsetof mismatch for RenderPassColorAttachment::storeOp");
static_assert(offsetof(RenderPassColorAttachment, clearValue) == offsetof(WGPURenderPassColorAttachment, clearValue),
        "offsetof mismatch for RenderPassColorAttachment::clearValue");

// RequiredLimits implementation

RequiredLimits::operator const WGPURequiredLimits&() const noexcept {
    return *reinterpret_cast<const WGPURequiredLimits*>(this);
}

static_assert(sizeof(RequiredLimits) == sizeof(WGPURequiredLimits), "sizeof mismatch for RequiredLimits");
static_assert(alignof(RequiredLimits) == alignof(WGPURequiredLimits), "alignof mismatch for RequiredLimits");
static_assert(offsetof(RequiredLimits, nextInChain) == offsetof(WGPURequiredLimits, nextInChain),
        "offsetof mismatch for RequiredLimits::nextInChain");
static_assert(offsetof(RequiredLimits, limits) == offsetof(WGPURequiredLimits, limits),
        "offsetof mismatch for RequiredLimits::limits");

// SupportedLimits implementation

SupportedLimits::operator const WGPUSupportedLimits&() const noexcept {
    return *reinterpret_cast<const WGPUSupportedLimits*>(this);
}

static_assert(sizeof(SupportedLimits) == sizeof(WGPUSupportedLimits), "sizeof mismatch for SupportedLimits");
static_assert(alignof(SupportedLimits) == alignof(WGPUSupportedLimits), "alignof mismatch for SupportedLimits");
static_assert(offsetof(SupportedLimits, nextInChain) == offsetof(WGPUSupportedLimits, nextInChain),
        "offsetof mismatch for SupportedLimits::nextInChain");
static_assert(offsetof(SupportedLimits, limits) == offsetof(WGPUSupportedLimits, limits),
        "offsetof mismatch for SupportedLimits::limits");

// TextureDescriptor implementation

TextureDescriptor::operator const WGPUTextureDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUTextureDescriptor*>(this);
}

static_assert(sizeof(TextureDescriptor) == sizeof(WGPUTextureDescriptor), "sizeof mismatch for TextureDescriptor");
static_assert(alignof(TextureDescriptor) == alignof(WGPUTextureDescriptor), "alignof mismatch for TextureDescriptor");
static_assert(offsetof(TextureDescriptor, nextInChain) == offsetof(WGPUTextureDescriptor, nextInChain),
        "offsetof mismatch for TextureDescriptor::nextInChain");
static_assert(offsetof(TextureDescriptor, label) == offsetof(WGPUTextureDescriptor, label),
        "offsetof mismatch for TextureDescriptor::label");
static_assert(offsetof(TextureDescriptor, usage) == offsetof(WGPUTextureDescriptor, usage),
        "offsetof mismatch for TextureDescriptor::usage");
static_assert(offsetof(TextureDescriptor, dimension) == offsetof(WGPUTextureDescriptor, dimension),
        "offsetof mismatch for TextureDescriptor::dimension");
static_assert(offsetof(TextureDescriptor, size) == offsetof(WGPUTextureDescriptor, size),
        "offsetof mismatch for TextureDescriptor::size");
static_assert(offsetof(TextureDescriptor, format) == offsetof(WGPUTextureDescriptor, format),
        "offsetof mismatch for TextureDescriptor::format");
static_assert(offsetof(TextureDescriptor, mipLevelCount) == offsetof(WGPUTextureDescriptor, mipLevelCount),
        "offsetof mismatch for TextureDescriptor::mipLevelCount");
static_assert(offsetof(TextureDescriptor, sampleCount) == offsetof(WGPUTextureDescriptor, sampleCount),
        "offsetof mismatch for TextureDescriptor::sampleCount");
static_assert(offsetof(TextureDescriptor, viewFormatCount) == offsetof(WGPUTextureDescriptor, viewFormatCount),
        "offsetof mismatch for TextureDescriptor::viewFormatCount");
static_assert(offsetof(TextureDescriptor, viewFormats) == offsetof(WGPUTextureDescriptor, viewFormats),
        "offsetof mismatch for TextureDescriptor::viewFormats");

// VertexBufferLayout implementation

VertexBufferLayout::operator const WGPUVertexBufferLayout&() const noexcept {
    return *reinterpret_cast<const WGPUVertexBufferLayout*>(this);
}

static_assert(sizeof(VertexBufferLayout) == sizeof(WGPUVertexBufferLayout), "sizeof mismatch for VertexBufferLayout");
static_assert(alignof(VertexBufferLayout) == alignof(WGPUVertexBufferLayout), "alignof mismatch for VertexBufferLayout");
static_assert(offsetof(VertexBufferLayout, arrayStride) == offsetof(WGPUVertexBufferLayout, arrayStride),
        "offsetof mismatch for VertexBufferLayout::arrayStride");
static_assert(offsetof(VertexBufferLayout, stepMode) == offsetof(WGPUVertexBufferLayout, stepMode),
        "offsetof mismatch for VertexBufferLayout::stepMode");
static_assert(offsetof(VertexBufferLayout, attributeCount) == offsetof(WGPUVertexBufferLayout, attributeCount),
        "offsetof mismatch for VertexBufferLayout::attributeCount");
static_assert(offsetof(VertexBufferLayout, attributes) == offsetof(WGPUVertexBufferLayout, attributes),
        "offsetof mismatch for VertexBufferLayout::attributes");

// BindGroupLayoutDescriptor implementation

BindGroupLayoutDescriptor::operator const WGPUBindGroupLayoutDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUBindGroupLayoutDescriptor*>(this);
}

static_assert(sizeof(BindGroupLayoutDescriptor) == sizeof(WGPUBindGroupLayoutDescriptor), "sizeof mismatch for BindGroupLayoutDescriptor");
static_assert(alignof(BindGroupLayoutDescriptor) == alignof(WGPUBindGroupLayoutDescriptor), "alignof mismatch for BindGroupLayoutDescriptor");
static_assert(offsetof(BindGroupLayoutDescriptor, nextInChain) == offsetof(WGPUBindGroupLayoutDescriptor, nextInChain),
        "offsetof mismatch for BindGroupLayoutDescriptor::nextInChain");
static_assert(offsetof(BindGroupLayoutDescriptor, label) == offsetof(WGPUBindGroupLayoutDescriptor, label),
        "offsetof mismatch for BindGroupLayoutDescriptor::label");
static_assert(offsetof(BindGroupLayoutDescriptor, entryCount) == offsetof(WGPUBindGroupLayoutDescriptor, entryCount),
        "offsetof mismatch for BindGroupLayoutDescriptor::entryCount");
static_assert(offsetof(BindGroupLayoutDescriptor, entries) == offsetof(WGPUBindGroupLayoutDescriptor, entries),
        "offsetof mismatch for BindGroupLayoutDescriptor::entries");

// ColorTargetState implementation

ColorTargetState::operator const WGPUColorTargetState&() const noexcept {
    return *reinterpret_cast<const WGPUColorTargetState*>(this);
}

static_assert(sizeof(ColorTargetState) == sizeof(WGPUColorTargetState), "sizeof mismatch for ColorTargetState");
static_assert(alignof(ColorTargetState) == alignof(WGPUColorTargetState), "alignof mismatch for ColorTargetState");
static_assert(offsetof(ColorTargetState, nextInChain) == offsetof(WGPUColorTargetState, nextInChain),
        "offsetof mismatch for ColorTargetState::nextInChain");
static_assert(offsetof(ColorTargetState, format) == offsetof(WGPUColorTargetState, format),
        "offsetof mismatch for ColorTargetState::format");
static_assert(offsetof(ColorTargetState, blend) == offsetof(WGPUColorTargetState, blend),
        "offsetof mismatch for ColorTargetState::blend");
static_assert(offsetof(ColorTargetState, writeMask) == offsetof(WGPUColorTargetState, writeMask),
        "offsetof mismatch for ColorTargetState::writeMask");

// ComputePipelineDescriptor implementation

ComputePipelineDescriptor::operator const WGPUComputePipelineDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUComputePipelineDescriptor*>(this);
}

static_assert(sizeof(ComputePipelineDescriptor) == sizeof(WGPUComputePipelineDescriptor), "sizeof mismatch for ComputePipelineDescriptor");
static_assert(alignof(ComputePipelineDescriptor) == alignof(WGPUComputePipelineDescriptor), "alignof mismatch for ComputePipelineDescriptor");
static_assert(offsetof(ComputePipelineDescriptor, nextInChain) == offsetof(WGPUComputePipelineDescriptor, nextInChain),
        "offsetof mismatch for ComputePipelineDescriptor::nextInChain");
static_assert(offsetof(ComputePipelineDescriptor, label) == offsetof(WGPUComputePipelineDescriptor, label),
        "offsetof mismatch for ComputePipelineDescriptor::label");
static_assert(offsetof(ComputePipelineDescriptor, layout) == offsetof(WGPUComputePipelineDescriptor, layout),
        "offsetof mismatch for ComputePipelineDescriptor::layout");
static_assert(offsetof(ComputePipelineDescriptor, compute) == offsetof(WGPUComputePipelineDescriptor, compute),
        "offsetof mismatch for ComputePipelineDescriptor::compute");

// DeviceDescriptor implementation

DeviceDescriptor::operator const WGPUDeviceDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUDeviceDescriptor*>(this);
}

static_assert(sizeof(DeviceDescriptor) == sizeof(WGPUDeviceDescriptor), "sizeof mismatch for DeviceDescriptor");
static_assert(alignof(DeviceDescriptor) == alignof(WGPUDeviceDescriptor), "alignof mismatch for DeviceDescriptor");
static_assert(offsetof(DeviceDescriptor, nextInChain) == offsetof(WGPUDeviceDescriptor, nextInChain),
        "offsetof mismatch for DeviceDescriptor::nextInChain");
static_assert(offsetof(DeviceDescriptor, label) == offsetof(WGPUDeviceDescriptor, label),
        "offsetof mismatch for DeviceDescriptor::label");
static_assert(offsetof(DeviceDescriptor, requiredFeatureCount) == offsetof(WGPUDeviceDescriptor, requiredFeatureCount),
        "offsetof mismatch for DeviceDescriptor::requiredFeatureCount");
static_assert(offsetof(DeviceDescriptor, requiredFeatures) == offsetof(WGPUDeviceDescriptor, requiredFeatures),
        "offsetof mismatch for DeviceDescriptor::requiredFeatures");
static_assert(offsetof(DeviceDescriptor, requiredLimits) == offsetof(WGPUDeviceDescriptor, requiredLimits),
        "offsetof mismatch for DeviceDescriptor::requiredLimits");
static_assert(offsetof(DeviceDescriptor, defaultQueue) == offsetof(WGPUDeviceDescriptor, defaultQueue),
        "offsetof mismatch for DeviceDescriptor::defaultQueue");
static_assert(offsetof(DeviceDescriptor, deviceLostCallbackInfo) == offsetof(WGPUDeviceDescriptor, deviceLostCallbackInfo),
        "offsetof mismatch for DeviceDescriptor::deviceLostCallbackInfo");
static_assert(offsetof(DeviceDescriptor, uncapturedErrorCallbackInfo) == offsetof(WGPUDeviceDescriptor, uncapturedErrorCallbackInfo),
        "offsetof mismatch for DeviceDescriptor::uncapturedErrorCallbackInfo");

// RenderPassDescriptor implementation

RenderPassDescriptor::operator const WGPURenderPassDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPURenderPassDescriptor*>(this);
}

static_assert(sizeof(RenderPassDescriptor) == sizeof(WGPURenderPassDescriptor), "sizeof mismatch for RenderPassDescriptor");
static_assert(alignof(RenderPassDescriptor) == alignof(WGPURenderPassDescriptor), "alignof mismatch for RenderPassDescriptor");
static_assert(offsetof(RenderPassDescriptor, nextInChain) == offsetof(WGPURenderPassDescriptor, nextInChain),
        "offsetof mismatch for RenderPassDescriptor::nextInChain");
static_assert(offsetof(RenderPassDescriptor, label) == offsetof(WGPURenderPassDescriptor, label),
        "offsetof mismatch for RenderPassDescriptor::label");
static_assert(offsetof(RenderPassDescriptor, colorAttachmentCount) == offsetof(WGPURenderPassDescriptor, colorAttachmentCount),
        "offsetof mismatch for RenderPassDescriptor::colorAttachmentCount");
static_assert(offsetof(RenderPassDescriptor, colorAttachments) == offsetof(WGPURenderPassDescriptor, colorAttachments),
        "offsetof mismatch for RenderPassDescriptor::colorAttachments");
static_assert(offsetof(RenderPassDescriptor, depthStencilAttachment) == offsetof(WGPURenderPassDescriptor, depthStencilAttachment),
        "offsetof mismatch for RenderPassDescriptor::depthStencilAttachment");
static_assert(offsetof(RenderPassDescriptor, occlusionQuerySet) == offsetof(WGPURenderPassDescriptor, occlusionQuerySet),
        "offsetof mismatch for RenderPassDescriptor::occlusionQuerySet");
static_assert(offsetof(RenderPassDescriptor, timestampWrites) == offsetof(WGPURenderPassDescriptor, timestampWrites),
        "offsetof mismatch for RenderPassDescriptor::timestampWrites");

// VertexState implementation

VertexState::operator const WGPUVertexState&() const noexcept {
    return *reinterpret_cast<const WGPUVertexState*>(this);
}

static_assert(sizeof(VertexState) == sizeof(WGPUVertexState), "sizeof mismatch for VertexState");
static_assert(alignof(VertexState) == alignof(WGPUVertexState), "alignof mismatch for VertexState");
static_assert(offsetof(VertexState, nextInChain) == offsetof(WGPUVertexState, nextInChain),
        "offsetof mismatch for VertexState::nextInChain");
static_assert(offsetof(VertexState, module) == offsetof(WGPUVertexState, module),
        "offsetof mismatch for VertexState::module");
static_assert(offsetof(VertexState, entryPoint) == offsetof(WGPUVertexState, entryPoint),
        "offsetof mismatch for VertexState::entryPoint");
static_assert(offsetof(VertexState, constantCount) == offsetof(WGPUVertexState, constantCount),
        "offsetof mismatch for VertexState::constantCount");
static_assert(offsetof(VertexState, constants) == offsetof(WGPUVertexState, constants),
        "offsetof mismatch for VertexState::constants");
static_assert(offsetof(VertexState, bufferCount) == offsetof(WGPUVertexState, bufferCount),
        "offsetof mismatch for VertexState::bufferCount");
static_assert(offsetof(VertexState, buffers) == offsetof(WGPUVertexState, buffers),
        "offsetof mismatch for VertexState::buffers");

// FragmentState implementation

FragmentState::operator const WGPUFragmentState&() const noexcept {
    return *reinterpret_cast<const WGPUFragmentState*>(this);
}

static_assert(sizeof(FragmentState) == sizeof(WGPUFragmentState), "sizeof mismatch for FragmentState");
static_assert(alignof(FragmentState) == alignof(WGPUFragmentState), "alignof mismatch for FragmentState");
static_assert(offsetof(FragmentState, nextInChain) == offsetof(WGPUFragmentState, nextInChain),
        "offsetof mismatch for FragmentState::nextInChain");
static_assert(offsetof(FragmentState, module) == offsetof(WGPUFragmentState, module),
        "offsetof mismatch for FragmentState::module");
static_assert(offsetof(FragmentState, entryPoint) == offsetof(WGPUFragmentState, entryPoint),
        "offsetof mismatch for FragmentState::entryPoint");
static_assert(offsetof(FragmentState, constantCount) == offsetof(WGPUFragmentState, constantCount),
        "offsetof mismatch for FragmentState::constantCount");
static_assert(offsetof(FragmentState, constants) == offsetof(WGPUFragmentState, constants),
        "offsetof mismatch for FragmentState::constants");
static_assert(offsetof(FragmentState, targetCount) == offsetof(WGPUFragmentState, targetCount),
        "offsetof mismatch for FragmentState::targetCount");
static_assert(offsetof(FragmentState, targets) == offsetof(WGPUFragmentState, targets),
        "offsetof mismatch for FragmentState::targets");

// RenderPipelineDescriptor implementation

RenderPipelineDescriptor::operator const WGPURenderPipelineDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPURenderPipelineDescriptor*>(this);
}

static_assert(sizeof(RenderPipelineDescriptor) == sizeof(WGPURenderPipelineDescriptor), "sizeof mismatch for RenderPipelineDescriptor");
static_assert(alignof(RenderPipelineDescriptor) == alignof(WGPURenderPipelineDescriptor), "alignof mismatch for RenderPipelineDescriptor");
static_assert(offsetof(RenderPipelineDescriptor, nextInChain) == offsetof(WGPURenderPipelineDescriptor, nextInChain),
        "offsetof mismatch for RenderPipelineDescriptor::nextInChain");
static_assert(offsetof(RenderPipelineDescriptor, label) == offsetof(WGPURenderPipelineDescriptor, label),
        "offsetof mismatch for RenderPipelineDescriptor::label");
static_assert(offsetof(RenderPipelineDescriptor, layout) == offsetof(WGPURenderPipelineDescriptor, layout),
        "offsetof mismatch for RenderPipelineDescriptor::layout");
static_assert(offsetof(RenderPipelineDescriptor, vertex) == offsetof(WGPURenderPipelineDescriptor, vertex),
        "offsetof mismatch for RenderPipelineDescriptor::vertex");
static_assert(offsetof(RenderPipelineDescriptor, primitive) == offsetof(WGPURenderPipelineDescriptor, primitive),
        "offsetof mismatch for RenderPipelineDescriptor::primitive");
static_assert(offsetof(RenderPipelineDescriptor, depthStencil) == offsetof(WGPURenderPipelineDescriptor, depthStencil),
        "offsetof mismatch for RenderPipelineDescriptor::depthStencil");
static_assert(offsetof(RenderPipelineDescriptor, multisample) == offsetof(WGPURenderPipelineDescriptor, multisample),
        "offsetof mismatch for RenderPipelineDescriptor::multisample");
static_assert(offsetof(RenderPipelineDescriptor, fragment) == offsetof(WGPURenderPipelineDescriptor, fragment),
        "offsetof mismatch for RenderPipelineDescriptor::fragment");

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

// Adapter implementation

size_t Adapter::EnumerateFeatures(FeatureName * features) const {
    auto result = wgpuAdapterEnumerateFeatures(Get(), reinterpret_cast<WGPUFeatureName * >(features));
    return result;
}
ConvertibleStatus Adapter::GetInfo(AdapterInfo * info) const {
    *info = AdapterInfo();
    auto result = wgpuAdapterGetInfo(Get(), reinterpret_cast<WGPUAdapterInfo * >(info));
    return static_cast<Status>(result);
}
ConvertibleStatus Adapter::GetLimits(SupportedLimits * limits) const {
    auto result = wgpuAdapterGetLimits(Get(), reinterpret_cast<WGPUSupportedLimits * >(limits));
    return static_cast<Status>(result);
}
ConvertibleStatus Adapter::GetProperties(AdapterProperties * properties) const {
    *properties = AdapterProperties();
    auto result = wgpuAdapterGetProperties(Get(), reinterpret_cast<WGPUAdapterProperties * >(properties));
    return static_cast<Status>(result);
}
Bool Adapter::HasFeature(FeatureName feature) const {
    auto result = wgpuAdapterHasFeature(Get(), static_cast<WGPUFeatureName>(feature));
    return result;
}
void Adapter::RequestDevice(DeviceDescriptor const * descriptor, RequestDeviceCallback callback, void * userdata) const {
    wgpuAdapterRequestDevice(Get(), reinterpret_cast<WGPUDeviceDescriptor const * >(descriptor), callback, userdata);
}
template <typename F, typename T,
          typename Cb,
          typename>
Future Adapter::RequestDevice(DeviceDescriptor const * options, CallbackMode mode, F callback, T userdata) const {
    WGPURequestDeviceCallbackInfo2 callbackInfo = {};
    callbackInfo.mode = static_cast<WGPUCallbackMode>(mode);
    callbackInfo.callback = [](WGPURequestDeviceStatus status, WGPUDevice device, char const * message, void* callback, void* userdata) {
        auto cb = reinterpret_cast<Cb*>(callback);
        (*cb)(static_cast<RequestDeviceStatus>(status), Device::Acquire(device), message, static_cast<T>(userdata));
    };
    callbackInfo.userdata1 = reinterpret_cast<void*>(+callback);
    callbackInfo.userdata2 = reinterpret_cast<void*>(userdata);
    auto result = wgpuAdapterRequestDevice2(Get(), reinterpret_cast<WGPUDeviceDescriptor const * >(options), callbackInfo);
    return Future {
        result.id
    };
}
template <typename L,
          typename Cb,
          typename>
Future Adapter::RequestDevice(DeviceDescriptor const * options, CallbackMode mode, L callback) const {
    using F = void (RequestDeviceStatus status, Device device, char const * message);

    WGPURequestDeviceCallbackInfo2 callbackInfo = {};
    callbackInfo.mode = static_cast<WGPUCallbackMode>(mode);
    if constexpr (std::is_convertible_v<L, F*>) {
        callbackInfo.callback = [](WGPURequestDeviceStatus status, WGPUDevice device, char const * message, void* callback, void*) {
            auto cb = reinterpret_cast<F*>(callback);
            (*cb)(static_cast<RequestDeviceStatus>(status), Device::Acquire(device), message);
        };
        callbackInfo.userdata1 = reinterpret_cast<void*>(+callback);
        callbackInfo.userdata2 = nullptr;
        auto result = wgpuAdapterRequestDevice2(Get(), reinterpret_cast<WGPUDeviceDescriptor const * >(options), callbackInfo);
        return Future {
            result.id
        };
    } else {
        auto* lambda = new L(callback);
        callbackInfo.callback = [](WGPURequestDeviceStatus status, WGPUDevice device, char const * message, void* callback, void*) {
            std::unique_ptr<L> lambda(reinterpret_cast<L*>(callback));
            (*lambda)(static_cast<RequestDeviceStatus>(status), Device::Acquire(device), message);
        };
        callbackInfo.userdata1 = reinterpret_cast<void*>(lambda);
        callbackInfo.userdata2 = nullptr;
        auto result = wgpuAdapterRequestDevice2(Get(), reinterpret_cast<WGPUDeviceDescriptor const * >(options), callbackInfo);
        return Future {
            result.id
        };
    }
}
Future Adapter::RequestDevice(DeviceDescriptor const * options, RequestDeviceCallbackInfo callbackInfo) const {
    auto result = wgpuAdapterRequestDeviceF(Get(), reinterpret_cast<WGPUDeviceDescriptor const * >(options), *reinterpret_cast<WGPURequestDeviceCallbackInfo const*>(&callbackInfo));
    return Future {
            result.id
        };
}
void Adapter::WGPUAddRef(WGPUAdapter handle) {
    if (handle != nullptr) {
        wgpuAdapterAddRef(handle);
    }
}
void Adapter::WGPURelease(WGPUAdapter handle) {
    if (handle != nullptr) {
        wgpuAdapterRelease(handle);
    }
}
static_assert(sizeof(Adapter) == sizeof(WGPUAdapter), "sizeof mismatch for Adapter");
static_assert(alignof(Adapter) == alignof(WGPUAdapter), "alignof mismatch for Adapter");

// BindGroup implementation

void BindGroup::SetLabel(char const * label) const {
    wgpuBindGroupSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void BindGroup::WGPUAddRef(WGPUBindGroup handle) {
    if (handle != nullptr) {
        wgpuBindGroupAddRef(handle);
    }
}
void BindGroup::WGPURelease(WGPUBindGroup handle) {
    if (handle != nullptr) {
        wgpuBindGroupRelease(handle);
    }
}
static_assert(sizeof(BindGroup) == sizeof(WGPUBindGroup), "sizeof mismatch for BindGroup");
static_assert(alignof(BindGroup) == alignof(WGPUBindGroup), "alignof mismatch for BindGroup");

// BindGroupLayout implementation

void BindGroupLayout::SetLabel(char const * label) const {
    wgpuBindGroupLayoutSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void BindGroupLayout::WGPUAddRef(WGPUBindGroupLayout handle) {
    if (handle != nullptr) {
        wgpuBindGroupLayoutAddRef(handle);
    }
}
void BindGroupLayout::WGPURelease(WGPUBindGroupLayout handle) {
    if (handle != nullptr) {
        wgpuBindGroupLayoutRelease(handle);
    }
}
static_assert(sizeof(BindGroupLayout) == sizeof(WGPUBindGroupLayout), "sizeof mismatch for BindGroupLayout");
static_assert(alignof(BindGroupLayout) == alignof(WGPUBindGroupLayout), "alignof mismatch for BindGroupLayout");

// Buffer implementation

void Buffer::Destroy() const {
    wgpuBufferDestroy(Get());
}
void const * Buffer::GetConstMappedRange(size_t offset, size_t size) const {
    auto result = wgpuBufferGetConstMappedRange(Get(), offset, size);
    return result;
}
BufferMapState Buffer::GetMapState() const {
    auto result = wgpuBufferGetMapState(Get());
    return static_cast<BufferMapState>(result);
}
void * Buffer::GetMappedRange(size_t offset, size_t size) const {
    auto result = wgpuBufferGetMappedRange(Get(), offset, size);
    return result;
}
uint64_t Buffer::GetSize() const {
    auto result = wgpuBufferGetSize(Get());
    return result;
}
BufferUsage Buffer::GetUsage() const {
    auto result = wgpuBufferGetUsage(Get());
    return static_cast<BufferUsage>(result);
}
void Buffer::MapAsync(MapMode mode, size_t offset, size_t size, BufferMapCallback callback, void * userdata) const {
    wgpuBufferMapAsync(Get(), static_cast<WGPUMapMode>(mode), offset, size, callback, userdata);
}
Future Buffer::MapAsync(MapMode mode, size_t offset, size_t size, BufferMapCallbackInfo callbackInfo) const {
    auto result = wgpuBufferMapAsyncF(Get(), static_cast<WGPUMapMode>(mode), offset, size, *reinterpret_cast<WGPUBufferMapCallbackInfo const*>(&callbackInfo));
    return Future {
            result.id
        };
}
void Buffer::SetLabel(char const * label) const {
    wgpuBufferSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void Buffer::Unmap() const {
    wgpuBufferUnmap(Get());
}
void Buffer::WGPUAddRef(WGPUBuffer handle) {
    if (handle != nullptr) {
        wgpuBufferAddRef(handle);
    }
}
void Buffer::WGPURelease(WGPUBuffer handle) {
    if (handle != nullptr) {
        wgpuBufferRelease(handle);
    }
}
static_assert(sizeof(Buffer) == sizeof(WGPUBuffer), "sizeof mismatch for Buffer");
static_assert(alignof(Buffer) == alignof(WGPUBuffer), "alignof mismatch for Buffer");

// CommandBuffer implementation

void CommandBuffer::SetLabel(char const * label) const {
    wgpuCommandBufferSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void CommandBuffer::WGPUAddRef(WGPUCommandBuffer handle) {
    if (handle != nullptr) {
        wgpuCommandBufferAddRef(handle);
    }
}
void CommandBuffer::WGPURelease(WGPUCommandBuffer handle) {
    if (handle != nullptr) {
        wgpuCommandBufferRelease(handle);
    }
}
static_assert(sizeof(CommandBuffer) == sizeof(WGPUCommandBuffer), "sizeof mismatch for CommandBuffer");
static_assert(alignof(CommandBuffer) == alignof(WGPUCommandBuffer), "alignof mismatch for CommandBuffer");

// CommandEncoder implementation

ComputePassEncoder CommandEncoder::BeginComputePass(ComputePassDescriptor const * descriptor) const {
    auto result = wgpuCommandEncoderBeginComputePass(Get(), reinterpret_cast<WGPUComputePassDescriptor const * >(descriptor));
    return ComputePassEncoder::Acquire(result);
}
RenderPassEncoder CommandEncoder::BeginRenderPass(RenderPassDescriptor const * descriptor) const {
    auto result = wgpuCommandEncoderBeginRenderPass(Get(), reinterpret_cast<WGPURenderPassDescriptor const * >(descriptor));
    return RenderPassEncoder::Acquire(result);
}
void CommandEncoder::ClearBuffer(Buffer const& buffer, uint64_t offset, uint64_t size) const {
    wgpuCommandEncoderClearBuffer(Get(), buffer.Get(), offset, size);
}
void CommandEncoder::CopyBufferToBuffer(Buffer const& source, uint64_t sourceOffset, Buffer const& destination, uint64_t destinationOffset, uint64_t size) const {
    wgpuCommandEncoderCopyBufferToBuffer(Get(), source.Get(), sourceOffset, destination.Get(), destinationOffset, size);
}
void CommandEncoder::CopyBufferToTexture(ImageCopyBuffer const * source, ImageCopyTexture const * destination, Extent3D const * copySize) const {
    wgpuCommandEncoderCopyBufferToTexture(Get(), reinterpret_cast<WGPUImageCopyBuffer const * >(source), reinterpret_cast<WGPUImageCopyTexture const * >(destination), reinterpret_cast<WGPUExtent3D const * >(copySize));
}
void CommandEncoder::CopyTextureToBuffer(ImageCopyTexture const * source, ImageCopyBuffer const * destination, Extent3D const * copySize) const {
    wgpuCommandEncoderCopyTextureToBuffer(Get(), reinterpret_cast<WGPUImageCopyTexture const * >(source), reinterpret_cast<WGPUImageCopyBuffer const * >(destination), reinterpret_cast<WGPUExtent3D const * >(copySize));
}
void CommandEncoder::CopyTextureToTexture(ImageCopyTexture const * source, ImageCopyTexture const * destination, Extent3D const * copySize) const {
    wgpuCommandEncoderCopyTextureToTexture(Get(), reinterpret_cast<WGPUImageCopyTexture const * >(source), reinterpret_cast<WGPUImageCopyTexture const * >(destination), reinterpret_cast<WGPUExtent3D const * >(copySize));
}
CommandBuffer CommandEncoder::Finish(CommandBufferDescriptor const * descriptor) const {
    auto result = wgpuCommandEncoderFinish(Get(), reinterpret_cast<WGPUCommandBufferDescriptor const * >(descriptor));
    return CommandBuffer::Acquire(result);
}
void CommandEncoder::InsertDebugMarker(char const * markerLabel) const {
    wgpuCommandEncoderInsertDebugMarker(Get(), reinterpret_cast<char const * >(markerLabel));
}
void CommandEncoder::PopDebugGroup() const {
    wgpuCommandEncoderPopDebugGroup(Get());
}
void CommandEncoder::PushDebugGroup(char const * groupLabel) const {
    wgpuCommandEncoderPushDebugGroup(Get(), reinterpret_cast<char const * >(groupLabel));
}
void CommandEncoder::ResolveQuerySet(QuerySet const& querySet, uint32_t firstQuery, uint32_t queryCount, Buffer const& destination, uint64_t destinationOffset) const {
    wgpuCommandEncoderResolveQuerySet(Get(), querySet.Get(), firstQuery, queryCount, destination.Get(), destinationOffset);
}
void CommandEncoder::SetLabel(char const * label) const {
    wgpuCommandEncoderSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void CommandEncoder::WriteTimestamp(QuerySet const& querySet, uint32_t queryIndex) const {
    wgpuCommandEncoderWriteTimestamp(Get(), querySet.Get(), queryIndex);
}
void CommandEncoder::WGPUAddRef(WGPUCommandEncoder handle) {
    if (handle != nullptr) {
        wgpuCommandEncoderAddRef(handle);
    }
}
void CommandEncoder::WGPURelease(WGPUCommandEncoder handle) {
    if (handle != nullptr) {
        wgpuCommandEncoderRelease(handle);
    }
}
static_assert(sizeof(CommandEncoder) == sizeof(WGPUCommandEncoder), "sizeof mismatch for CommandEncoder");
static_assert(alignof(CommandEncoder) == alignof(WGPUCommandEncoder), "alignof mismatch for CommandEncoder");

// ComputePassEncoder implementation

void ComputePassEncoder::DispatchWorkgroups(uint32_t workgroupCountX, uint32_t workgroupCountY, uint32_t workgroupCountZ) const {
    wgpuComputePassEncoderDispatchWorkgroups(Get(), workgroupCountX, workgroupCountY, workgroupCountZ);
}
void ComputePassEncoder::DispatchWorkgroupsIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const {
    wgpuComputePassEncoderDispatchWorkgroupsIndirect(Get(), indirectBuffer.Get(), indirectOffset);
}
void ComputePassEncoder::End() const {
    wgpuComputePassEncoderEnd(Get());
}
void ComputePassEncoder::InsertDebugMarker(char const * markerLabel) const {
    wgpuComputePassEncoderInsertDebugMarker(Get(), reinterpret_cast<char const * >(markerLabel));
}
void ComputePassEncoder::PopDebugGroup() const {
    wgpuComputePassEncoderPopDebugGroup(Get());
}
void ComputePassEncoder::PushDebugGroup(char const * groupLabel) const {
    wgpuComputePassEncoderPushDebugGroup(Get(), reinterpret_cast<char const * >(groupLabel));
}
void ComputePassEncoder::SetBindGroup(uint32_t groupIndex, BindGroup const& group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) const {
    wgpuComputePassEncoderSetBindGroup(Get(), groupIndex, group.Get(), dynamicOffsetCount, reinterpret_cast<uint32_t const * >(dynamicOffsets));
}
void ComputePassEncoder::SetLabel(char const * label) const {
    wgpuComputePassEncoderSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void ComputePassEncoder::SetPipeline(ComputePipeline const& pipeline) const {
    wgpuComputePassEncoderSetPipeline(Get(), pipeline.Get());
}
void ComputePassEncoder::WriteTimestamp(QuerySet const& querySet, uint32_t queryIndex) const {
    wgpuComputePassEncoderWriteTimestamp(Get(), querySet.Get(), queryIndex);
}
void ComputePassEncoder::WGPUAddRef(WGPUComputePassEncoder handle) {
    if (handle != nullptr) {
        wgpuComputePassEncoderAddRef(handle);
    }
}
void ComputePassEncoder::WGPURelease(WGPUComputePassEncoder handle) {
    if (handle != nullptr) {
        wgpuComputePassEncoderRelease(handle);
    }
}
static_assert(sizeof(ComputePassEncoder) == sizeof(WGPUComputePassEncoder), "sizeof mismatch for ComputePassEncoder");
static_assert(alignof(ComputePassEncoder) == alignof(WGPUComputePassEncoder), "alignof mismatch for ComputePassEncoder");

// ComputePipeline implementation

BindGroupLayout ComputePipeline::GetBindGroupLayout(uint32_t groupIndex) const {
    auto result = wgpuComputePipelineGetBindGroupLayout(Get(), groupIndex);
    return BindGroupLayout::Acquire(result);
}
void ComputePipeline::SetLabel(char const * label) const {
    wgpuComputePipelineSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void ComputePipeline::WGPUAddRef(WGPUComputePipeline handle) {
    if (handle != nullptr) {
        wgpuComputePipelineAddRef(handle);
    }
}
void ComputePipeline::WGPURelease(WGPUComputePipeline handle) {
    if (handle != nullptr) {
        wgpuComputePipelineRelease(handle);
    }
}
static_assert(sizeof(ComputePipeline) == sizeof(WGPUComputePipeline), "sizeof mismatch for ComputePipeline");
static_assert(alignof(ComputePipeline) == alignof(WGPUComputePipeline), "alignof mismatch for ComputePipeline");

// Device implementation

BindGroup Device::CreateBindGroup(BindGroupDescriptor const * descriptor) const {
    auto result = wgpuDeviceCreateBindGroup(Get(), reinterpret_cast<WGPUBindGroupDescriptor const * >(descriptor));
    return BindGroup::Acquire(result);
}
BindGroupLayout Device::CreateBindGroupLayout(BindGroupLayoutDescriptor const * descriptor) const {
    auto result = wgpuDeviceCreateBindGroupLayout(Get(), reinterpret_cast<WGPUBindGroupLayoutDescriptor const * >(descriptor));
    return BindGroupLayout::Acquire(result);
}
Buffer Device::CreateBuffer(BufferDescriptor const * descriptor) const {
    auto result = wgpuDeviceCreateBuffer(Get(), reinterpret_cast<WGPUBufferDescriptor const * >(descriptor));
    return Buffer::Acquire(result);
}
CommandEncoder Device::CreateCommandEncoder(CommandEncoderDescriptor const * descriptor) const {
    auto result = wgpuDeviceCreateCommandEncoder(Get(), reinterpret_cast<WGPUCommandEncoderDescriptor const * >(descriptor));
    return CommandEncoder::Acquire(result);
}
ComputePipeline Device::CreateComputePipeline(ComputePipelineDescriptor const * descriptor) const {
    auto result = wgpuDeviceCreateComputePipeline(Get(), reinterpret_cast<WGPUComputePipelineDescriptor const * >(descriptor));
    return ComputePipeline::Acquire(result);
}
void Device::CreateComputePipelineAsync(ComputePipelineDescriptor const * descriptor, CreateComputePipelineAsyncCallback callback, void * userdata) const {
    wgpuDeviceCreateComputePipelineAsync(Get(), reinterpret_cast<WGPUComputePipelineDescriptor const * >(descriptor), callback, userdata);
}
template <typename F, typename T,
          typename Cb,
          typename>
Future Device::CreateComputePipelineAsync(ComputePipelineDescriptor const * descriptor, CallbackMode mode, F callback, T userdata) const {
    WGPUCreateComputePipelineAsyncCallbackInfo2 callbackInfo = {};
    callbackInfo.mode = static_cast<WGPUCallbackMode>(mode);
    callbackInfo.callback = [](WGPUCreatePipelineAsyncStatus status, WGPUComputePipeline pipeline, char const * message, void* callback, void* userdata) {
        auto cb = reinterpret_cast<Cb*>(callback);
        (*cb)(static_cast<CreatePipelineAsyncStatus>(status), ComputePipeline::Acquire(pipeline), message, static_cast<T>(userdata));
    };
    callbackInfo.userdata1 = reinterpret_cast<void*>(+callback);
    callbackInfo.userdata2 = reinterpret_cast<void*>(userdata);
    auto result = wgpuDeviceCreateComputePipelineAsync2(Get(), reinterpret_cast<WGPUComputePipelineDescriptor const * >(descriptor), callbackInfo);
    return Future {
        result.id
    };
}
template <typename L,
          typename Cb,
          typename>
Future Device::CreateComputePipelineAsync(ComputePipelineDescriptor const * descriptor, CallbackMode mode, L callback) const {
    using F = void (CreatePipelineAsyncStatus status, ComputePipeline pipeline, char const * message);

    WGPUCreateComputePipelineAsyncCallbackInfo2 callbackInfo = {};
    callbackInfo.mode = static_cast<WGPUCallbackMode>(mode);
    if constexpr (std::is_convertible_v<L, F*>) {
        callbackInfo.callback = [](WGPUCreatePipelineAsyncStatus status, WGPUComputePipeline pipeline, char const * message, void* callback, void*) {
            auto cb = reinterpret_cast<F*>(callback);
            (*cb)(static_cast<CreatePipelineAsyncStatus>(status), ComputePipeline::Acquire(pipeline), message);
        };
        callbackInfo.userdata1 = reinterpret_cast<void*>(+callback);
        callbackInfo.userdata2 = nullptr;
        auto result = wgpuDeviceCreateComputePipelineAsync2(Get(), reinterpret_cast<WGPUComputePipelineDescriptor const * >(descriptor), callbackInfo);
        return Future {
            result.id
        };
    } else {
        auto* lambda = new L(callback);
        callbackInfo.callback = [](WGPUCreatePipelineAsyncStatus status, WGPUComputePipeline pipeline, char const * message, void* callback, void*) {
            std::unique_ptr<L> lambda(reinterpret_cast<L*>(callback));
            (*lambda)(static_cast<CreatePipelineAsyncStatus>(status), ComputePipeline::Acquire(pipeline), message);
        };
        callbackInfo.userdata1 = reinterpret_cast<void*>(lambda);
        callbackInfo.userdata2 = nullptr;
        auto result = wgpuDeviceCreateComputePipelineAsync2(Get(), reinterpret_cast<WGPUComputePipelineDescriptor const * >(descriptor), callbackInfo);
        return Future {
            result.id
        };
    }
}
Future Device::CreateComputePipelineAsync(ComputePipelineDescriptor const * descriptor, CreateComputePipelineAsyncCallbackInfo callbackInfo) const {
    auto result = wgpuDeviceCreateComputePipelineAsyncF(Get(), reinterpret_cast<WGPUComputePipelineDescriptor const * >(descriptor), *reinterpret_cast<WGPUCreateComputePipelineAsyncCallbackInfo const*>(&callbackInfo));
    return Future {
            result.id
        };
}
PipelineLayout Device::CreatePipelineLayout(PipelineLayoutDescriptor const * descriptor) const {
    auto result = wgpuDeviceCreatePipelineLayout(Get(), reinterpret_cast<WGPUPipelineLayoutDescriptor const * >(descriptor));
    return PipelineLayout::Acquire(result);
}
QuerySet Device::CreateQuerySet(QuerySetDescriptor const * descriptor) const {
    auto result = wgpuDeviceCreateQuerySet(Get(), reinterpret_cast<WGPUQuerySetDescriptor const * >(descriptor));
    return QuerySet::Acquire(result);
}
RenderBundleEncoder Device::CreateRenderBundleEncoder(RenderBundleEncoderDescriptor const * descriptor) const {
    auto result = wgpuDeviceCreateRenderBundleEncoder(Get(), reinterpret_cast<WGPURenderBundleEncoderDescriptor const * >(descriptor));
    return RenderBundleEncoder::Acquire(result);
}
RenderPipeline Device::CreateRenderPipeline(RenderPipelineDescriptor const * descriptor) const {
    auto result = wgpuDeviceCreateRenderPipeline(Get(), reinterpret_cast<WGPURenderPipelineDescriptor const * >(descriptor));
    return RenderPipeline::Acquire(result);
}
void Device::CreateRenderPipelineAsync(RenderPipelineDescriptor const * descriptor, CreateRenderPipelineAsyncCallback callback, void * userdata) const {
    wgpuDeviceCreateRenderPipelineAsync(Get(), reinterpret_cast<WGPURenderPipelineDescriptor const * >(descriptor), callback, userdata);
}
template <typename F, typename T,
          typename Cb,
          typename>
Future Device::CreateRenderPipelineAsync(RenderPipelineDescriptor const * descriptor, CallbackMode mode, F callback, T userdata) const {
    WGPUCreateRenderPipelineAsyncCallbackInfo2 callbackInfo = {};
    callbackInfo.mode = static_cast<WGPUCallbackMode>(mode);
    callbackInfo.callback = [](WGPUCreatePipelineAsyncStatus status, WGPURenderPipeline pipeline, char const * message, void* callback, void* userdata) {
        auto cb = reinterpret_cast<Cb*>(callback);
        (*cb)(static_cast<CreatePipelineAsyncStatus>(status), RenderPipeline::Acquire(pipeline), message, static_cast<T>(userdata));
    };
    callbackInfo.userdata1 = reinterpret_cast<void*>(+callback);
    callbackInfo.userdata2 = reinterpret_cast<void*>(userdata);
    auto result = wgpuDeviceCreateRenderPipelineAsync2(Get(), reinterpret_cast<WGPURenderPipelineDescriptor const * >(descriptor), callbackInfo);
    return Future {
        result.id
    };
}
template <typename L,
          typename Cb,
          typename>
Future Device::CreateRenderPipelineAsync(RenderPipelineDescriptor const * descriptor, CallbackMode mode, L callback) const {
    using F = void (CreatePipelineAsyncStatus status, RenderPipeline pipeline, char const * message);

    WGPUCreateRenderPipelineAsyncCallbackInfo2 callbackInfo = {};
    callbackInfo.mode = static_cast<WGPUCallbackMode>(mode);
    if constexpr (std::is_convertible_v<L, F*>) {
        callbackInfo.callback = [](WGPUCreatePipelineAsyncStatus status, WGPURenderPipeline pipeline, char const * message, void* callback, void*) {
            auto cb = reinterpret_cast<F*>(callback);
            (*cb)(static_cast<CreatePipelineAsyncStatus>(status), RenderPipeline::Acquire(pipeline), message);
        };
        callbackInfo.userdata1 = reinterpret_cast<void*>(+callback);
        callbackInfo.userdata2 = nullptr;
        auto result = wgpuDeviceCreateRenderPipelineAsync2(Get(), reinterpret_cast<WGPURenderPipelineDescriptor const * >(descriptor), callbackInfo);
        return Future {
            result.id
        };
    } else {
        auto* lambda = new L(callback);
        callbackInfo.callback = [](WGPUCreatePipelineAsyncStatus status, WGPURenderPipeline pipeline, char const * message, void* callback, void*) {
            std::unique_ptr<L> lambda(reinterpret_cast<L*>(callback));
            (*lambda)(static_cast<CreatePipelineAsyncStatus>(status), RenderPipeline::Acquire(pipeline), message);
        };
        callbackInfo.userdata1 = reinterpret_cast<void*>(lambda);
        callbackInfo.userdata2 = nullptr;
        auto result = wgpuDeviceCreateRenderPipelineAsync2(Get(), reinterpret_cast<WGPURenderPipelineDescriptor const * >(descriptor), callbackInfo);
        return Future {
            result.id
        };
    }
}
Future Device::CreateRenderPipelineAsync(RenderPipelineDescriptor const * descriptor, CreateRenderPipelineAsyncCallbackInfo callbackInfo) const {
    auto result = wgpuDeviceCreateRenderPipelineAsyncF(Get(), reinterpret_cast<WGPURenderPipelineDescriptor const * >(descriptor), *reinterpret_cast<WGPUCreateRenderPipelineAsyncCallbackInfo const*>(&callbackInfo));
    return Future {
            result.id
        };
}
Sampler Device::CreateSampler(SamplerDescriptor const * descriptor) const {
    auto result = wgpuDeviceCreateSampler(Get(), reinterpret_cast<WGPUSamplerDescriptor const * >(descriptor));
    return Sampler::Acquire(result);
}
ShaderModule Device::CreateShaderModule(ShaderModuleDescriptor const * descriptor) const {
    auto result = wgpuDeviceCreateShaderModule(Get(), reinterpret_cast<WGPUShaderModuleDescriptor const * >(descriptor));
    return ShaderModule::Acquire(result);
}
SwapChain Device::CreateSwapChain(Surface const& surface, SwapChainDescriptor const * descriptor) const {
    auto result = wgpuDeviceCreateSwapChain(Get(), surface.Get(), reinterpret_cast<WGPUSwapChainDescriptor const * >(descriptor));
    return SwapChain::Acquire(result);
}
Texture Device::CreateTexture(TextureDescriptor const * descriptor) const {
    auto result = wgpuDeviceCreateTexture(Get(), reinterpret_cast<WGPUTextureDescriptor const * >(descriptor));
    return Texture::Acquire(result);
}
void Device::Destroy() const {
    wgpuDeviceDestroy(Get());
}
size_t Device::EnumerateFeatures(FeatureName * features) const {
    auto result = wgpuDeviceEnumerateFeatures(Get(), reinterpret_cast<WGPUFeatureName * >(features));
    return result;
}
ConvertibleStatus Device::GetLimits(SupportedLimits * limits) const {
    auto result = wgpuDeviceGetLimits(Get(), reinterpret_cast<WGPUSupportedLimits * >(limits));
    return static_cast<Status>(result);
}
Queue Device::GetQueue() const {
    auto result = wgpuDeviceGetQueue(Get());
    return Queue::Acquire(result);
}
Bool Device::HasFeature(FeatureName feature) const {
    auto result = wgpuDeviceHasFeature(Get(), static_cast<WGPUFeatureName>(feature));
    return result;
}
void Device::PopErrorScope(ErrorCallback oldCallback, void * userdata) const {
    wgpuDevicePopErrorScope(Get(), oldCallback, userdata);
}
template <typename F, typename T,
          typename Cb,
          typename>
Future Device::PopErrorScope(CallbackMode mode, F callback, T userdata) const {
    WGPUPopErrorScopeCallbackInfo2 callbackInfo = {};
    callbackInfo.mode = static_cast<WGPUCallbackMode>(mode);
    callbackInfo.callback = [](WGPUPopErrorScopeStatus status, WGPUErrorType type, char const * message, void* callback, void* userdata) {
        auto cb = reinterpret_cast<Cb*>(callback);
        (*cb)(static_cast<PopErrorScopeStatus>(status), static_cast<ErrorType>(type), message, static_cast<T>(userdata));
    };
    callbackInfo.userdata1 = reinterpret_cast<void*>(+callback);
    callbackInfo.userdata2 = reinterpret_cast<void*>(userdata);
    auto result = wgpuDevicePopErrorScope2(Get(), callbackInfo);
    return Future {
        result.id
    };
}
template <typename L,
          typename Cb,
          typename>
Future Device::PopErrorScope(CallbackMode mode, L callback) const {
    using F = void (PopErrorScopeStatus status, ErrorType type, char const * message);

    WGPUPopErrorScopeCallbackInfo2 callbackInfo = {};
    callbackInfo.mode = static_cast<WGPUCallbackMode>(mode);
    if constexpr (std::is_convertible_v<L, F*>) {
        callbackInfo.callback = [](WGPUPopErrorScopeStatus status, WGPUErrorType type, char const * message, void* callback, void*) {
            auto cb = reinterpret_cast<F*>(callback);
            (*cb)(static_cast<PopErrorScopeStatus>(status), static_cast<ErrorType>(type), message);
        };
        callbackInfo.userdata1 = reinterpret_cast<void*>(+callback);
        callbackInfo.userdata2 = nullptr;
        auto result = wgpuDevicePopErrorScope2(Get(), callbackInfo);
        return Future {
            result.id
        };
    } else {
        auto* lambda = new L(callback);
        callbackInfo.callback = [](WGPUPopErrorScopeStatus status, WGPUErrorType type, char const * message, void* callback, void*) {
            std::unique_ptr<L> lambda(reinterpret_cast<L*>(callback));
            (*lambda)(static_cast<PopErrorScopeStatus>(status), static_cast<ErrorType>(type), message);
        };
        callbackInfo.userdata1 = reinterpret_cast<void*>(lambda);
        callbackInfo.userdata2 = nullptr;
        auto result = wgpuDevicePopErrorScope2(Get(), callbackInfo);
        return Future {
            result.id
        };
    }
}
Future Device::PopErrorScope(PopErrorScopeCallbackInfo callbackInfo) const {
    auto result = wgpuDevicePopErrorScopeF(Get(), *reinterpret_cast<WGPUPopErrorScopeCallbackInfo const*>(&callbackInfo));
    return Future {
            result.id
        };
}
void Device::PushErrorScope(ErrorFilter filter) const {
    wgpuDevicePushErrorScope(Get(), static_cast<WGPUErrorFilter>(filter));
}
void Device::SetLabel(char const * label) const {
    wgpuDeviceSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void Device::SetUncapturedErrorCallback(ErrorCallback callback, void * userdata) const {
    wgpuDeviceSetUncapturedErrorCallback(Get(), callback, userdata);
}
void Device::WGPUAddRef(WGPUDevice handle) {
    if (handle != nullptr) {
        wgpuDeviceAddRef(handle);
    }
}
void Device::WGPURelease(WGPUDevice handle) {
    if (handle != nullptr) {
        wgpuDeviceRelease(handle);
    }
}
static_assert(sizeof(Device) == sizeof(WGPUDevice), "sizeof mismatch for Device");
static_assert(alignof(Device) == alignof(WGPUDevice), "alignof mismatch for Device");

// Instance implementation

Surface Instance::CreateSurface(SurfaceDescriptor const * descriptor) const {
    auto result = wgpuInstanceCreateSurface(Get(), reinterpret_cast<WGPUSurfaceDescriptor const * >(descriptor));
    return Surface::Acquire(result);
}
size_t Instance::EnumerateWGSLLanguageFeatures(WGSLFeatureName * features) const {
    auto result = wgpuInstanceEnumerateWGSLLanguageFeatures(Get(), reinterpret_cast<WGPUWGSLFeatureName * >(features));
    return result;
}
Bool Instance::HasWGSLLanguageFeature(WGSLFeatureName feature) const {
    auto result = wgpuInstanceHasWGSLLanguageFeature(Get(), static_cast<WGPUWGSLFeatureName>(feature));
    return result;
}
void Instance::ProcessEvents() const {
    wgpuInstanceProcessEvents(Get());
}
void Instance::RequestAdapter(RequestAdapterOptions const * options, RequestAdapterCallback callback, void * userdata) const {
    wgpuInstanceRequestAdapter(Get(), reinterpret_cast<WGPURequestAdapterOptions const * >(options), callback, userdata);
}
template <typename F, typename T,
          typename Cb,
          typename>
Future Instance::RequestAdapter(RequestAdapterOptions const * options, CallbackMode mode, F callback, T userdata) const {
    WGPURequestAdapterCallbackInfo2 callbackInfo = {};
    callbackInfo.mode = static_cast<WGPUCallbackMode>(mode);
    callbackInfo.callback = [](WGPURequestAdapterStatus status, WGPUAdapter adapter, char const * message, void* callback, void* userdata) {
        auto cb = reinterpret_cast<Cb*>(callback);
        (*cb)(static_cast<RequestAdapterStatus>(status), Adapter::Acquire(adapter), message, static_cast<T>(userdata));
    };
    callbackInfo.userdata1 = reinterpret_cast<void*>(+callback);
    callbackInfo.userdata2 = reinterpret_cast<void*>(userdata);
    auto result = wgpuInstanceRequestAdapter2(Get(), reinterpret_cast<WGPURequestAdapterOptions const * >(options), callbackInfo);
    return Future {
        result.id
    };
}
template <typename L,
          typename Cb,
          typename>
Future Instance::RequestAdapter(RequestAdapterOptions const * options, CallbackMode mode, L callback) const {
    using F = void (RequestAdapterStatus status, Adapter adapter, char const * message);

    WGPURequestAdapterCallbackInfo2 callbackInfo = {};
    callbackInfo.mode = static_cast<WGPUCallbackMode>(mode);
    if constexpr (std::is_convertible_v<L, F*>) {
        callbackInfo.callback = [](WGPURequestAdapterStatus status, WGPUAdapter adapter, char const * message, void* callback, void*) {
            auto cb = reinterpret_cast<F*>(callback);
            (*cb)(static_cast<RequestAdapterStatus>(status), Adapter::Acquire(adapter), message);
        };
        callbackInfo.userdata1 = reinterpret_cast<void*>(+callback);
        callbackInfo.userdata2 = nullptr;
        auto result = wgpuInstanceRequestAdapter2(Get(), reinterpret_cast<WGPURequestAdapterOptions const * >(options), callbackInfo);
        return Future {
            result.id
        };
    } else {
        auto* lambda = new L(callback);
        callbackInfo.callback = [](WGPURequestAdapterStatus status, WGPUAdapter adapter, char const * message, void* callback, void*) {
            std::unique_ptr<L> lambda(reinterpret_cast<L*>(callback));
            (*lambda)(static_cast<RequestAdapterStatus>(status), Adapter::Acquire(adapter), message);
        };
        callbackInfo.userdata1 = reinterpret_cast<void*>(lambda);
        callbackInfo.userdata2 = nullptr;
        auto result = wgpuInstanceRequestAdapter2(Get(), reinterpret_cast<WGPURequestAdapterOptions const * >(options), callbackInfo);
        return Future {
            result.id
        };
    }
}
Future Instance::RequestAdapter(RequestAdapterOptions const * options, RequestAdapterCallbackInfo callbackInfo) const {
    auto result = wgpuInstanceRequestAdapterF(Get(), reinterpret_cast<WGPURequestAdapterOptions const * >(options), *reinterpret_cast<WGPURequestAdapterCallbackInfo const*>(&callbackInfo));
    return Future {
            result.id
        };
}
WaitStatus Instance::WaitAny(size_t futureCount, FutureWaitInfo * futures, uint64_t timeoutNS) const {
    auto result = wgpuInstanceWaitAny(Get(), futureCount, reinterpret_cast<WGPUFutureWaitInfo * >(futures), timeoutNS);
    return static_cast<WaitStatus>(result);
}
void Instance::WGPUAddRef(WGPUInstance handle) {
    if (handle != nullptr) {
        wgpuInstanceAddRef(handle);
    }
}
void Instance::WGPURelease(WGPUInstance handle) {
    if (handle != nullptr) {
        wgpuInstanceRelease(handle);
    }
}
static_assert(sizeof(Instance) == sizeof(WGPUInstance), "sizeof mismatch for Instance");
static_assert(alignof(Instance) == alignof(WGPUInstance), "alignof mismatch for Instance");

// PipelineLayout implementation

void PipelineLayout::SetLabel(char const * label) const {
    wgpuPipelineLayoutSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void PipelineLayout::WGPUAddRef(WGPUPipelineLayout handle) {
    if (handle != nullptr) {
        wgpuPipelineLayoutAddRef(handle);
    }
}
void PipelineLayout::WGPURelease(WGPUPipelineLayout handle) {
    if (handle != nullptr) {
        wgpuPipelineLayoutRelease(handle);
    }
}
static_assert(sizeof(PipelineLayout) == sizeof(WGPUPipelineLayout), "sizeof mismatch for PipelineLayout");
static_assert(alignof(PipelineLayout) == alignof(WGPUPipelineLayout), "alignof mismatch for PipelineLayout");

// QuerySet implementation

void QuerySet::Destroy() const {
    wgpuQuerySetDestroy(Get());
}
uint32_t QuerySet::GetCount() const {
    auto result = wgpuQuerySetGetCount(Get());
    return result;
}
QueryType QuerySet::GetType() const {
    auto result = wgpuQuerySetGetType(Get());
    return static_cast<QueryType>(result);
}
void QuerySet::SetLabel(char const * label) const {
    wgpuQuerySetSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void QuerySet::WGPUAddRef(WGPUQuerySet handle) {
    if (handle != nullptr) {
        wgpuQuerySetAddRef(handle);
    }
}
void QuerySet::WGPURelease(WGPUQuerySet handle) {
    if (handle != nullptr) {
        wgpuQuerySetRelease(handle);
    }
}
static_assert(sizeof(QuerySet) == sizeof(WGPUQuerySet), "sizeof mismatch for QuerySet");
static_assert(alignof(QuerySet) == alignof(WGPUQuerySet), "alignof mismatch for QuerySet");

// Queue implementation

void Queue::OnSubmittedWorkDone(uint64_t signalValue, QueueWorkDoneCallback callback, void * userdata) const {
    wgpuQueueOnSubmittedWorkDone(Get(), signalValue, callback, userdata);
}
template <typename F, typename T,
          typename Cb,
          typename>
Future Queue::OnSubmittedWorkDone(CallbackMode mode, F callback, T userdata) const {
    WGPUQueueWorkDoneCallbackInfo2 callbackInfo = {};
    callbackInfo.mode = static_cast<WGPUCallbackMode>(mode);
    callbackInfo.callback = [](WGPUQueueWorkDoneStatus status, void* callback, void* userdata) {
        auto cb = reinterpret_cast<Cb*>(callback);
        (*cb)(static_cast<QueueWorkDoneStatus>(status), static_cast<T>(userdata));
    };
    callbackInfo.userdata1 = reinterpret_cast<void*>(+callback);
    callbackInfo.userdata2 = reinterpret_cast<void*>(userdata);
    auto result = wgpuQueueOnSubmittedWorkDone2(Get(), callbackInfo);
    return Future {
        result.id
    };
}
template <typename L,
          typename Cb,
          typename>
Future Queue::OnSubmittedWorkDone(CallbackMode mode, L callback) const {
    using F = void (QueueWorkDoneStatus status);

    WGPUQueueWorkDoneCallbackInfo2 callbackInfo = {};
    callbackInfo.mode = static_cast<WGPUCallbackMode>(mode);
    if constexpr (std::is_convertible_v<L, F*>) {
        callbackInfo.callback = [](WGPUQueueWorkDoneStatus status, void* callback, void*) {
            auto cb = reinterpret_cast<F*>(callback);
            (*cb)(static_cast<QueueWorkDoneStatus>(status));
        };
        callbackInfo.userdata1 = reinterpret_cast<void*>(+callback);
        callbackInfo.userdata2 = nullptr;
        auto result = wgpuQueueOnSubmittedWorkDone2(Get(), callbackInfo);
        return Future {
            result.id
        };
    } else {
        auto* lambda = new L(callback);
        callbackInfo.callback = [](WGPUQueueWorkDoneStatus status, void* callback, void*) {
            std::unique_ptr<L> lambda(reinterpret_cast<L*>(callback));
            (*lambda)(static_cast<QueueWorkDoneStatus>(status));
        };
        callbackInfo.userdata1 = reinterpret_cast<void*>(lambda);
        callbackInfo.userdata2 = nullptr;
        auto result = wgpuQueueOnSubmittedWorkDone2(Get(), callbackInfo);
        return Future {
            result.id
        };
    }
}
Future Queue::OnSubmittedWorkDone(QueueWorkDoneCallbackInfo callbackInfo) const {
    auto result = wgpuQueueOnSubmittedWorkDoneF(Get(), *reinterpret_cast<WGPUQueueWorkDoneCallbackInfo const*>(&callbackInfo));
    return Future {
            result.id
        };
}
void Queue::SetLabel(char const * label) const {
    wgpuQueueSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void Queue::Submit(size_t commandCount, CommandBuffer const * commands) const {
    wgpuQueueSubmit(Get(), commandCount, reinterpret_cast<WGPUCommandBuffer const * >(commands));
}
void Queue::WriteBuffer(Buffer const& buffer, uint64_t bufferOffset, void const * data, size_t size) const {
    wgpuQueueWriteBuffer(Get(), buffer.Get(), bufferOffset, reinterpret_cast<void const * >(data), size);
}
void Queue::WriteTexture(ImageCopyTexture const * destination, void const * data, size_t dataSize, TextureDataLayout const * dataLayout, Extent3D const * writeSize) const {
    wgpuQueueWriteTexture(Get(), reinterpret_cast<WGPUImageCopyTexture const * >(destination), reinterpret_cast<void const * >(data), dataSize, reinterpret_cast<WGPUTextureDataLayout const * >(dataLayout), reinterpret_cast<WGPUExtent3D const * >(writeSize));
}
void Queue::WGPUAddRef(WGPUQueue handle) {
    if (handle != nullptr) {
        wgpuQueueAddRef(handle);
    }
}
void Queue::WGPURelease(WGPUQueue handle) {
    if (handle != nullptr) {
        wgpuQueueRelease(handle);
    }
}
static_assert(sizeof(Queue) == sizeof(WGPUQueue), "sizeof mismatch for Queue");
static_assert(alignof(Queue) == alignof(WGPUQueue), "alignof mismatch for Queue");

// RenderBundle implementation

void RenderBundle::SetLabel(char const * label) const {
    wgpuRenderBundleSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void RenderBundle::WGPUAddRef(WGPURenderBundle handle) {
    if (handle != nullptr) {
        wgpuRenderBundleAddRef(handle);
    }
}
void RenderBundle::WGPURelease(WGPURenderBundle handle) {
    if (handle != nullptr) {
        wgpuRenderBundleRelease(handle);
    }
}
static_assert(sizeof(RenderBundle) == sizeof(WGPURenderBundle), "sizeof mismatch for RenderBundle");
static_assert(alignof(RenderBundle) == alignof(WGPURenderBundle), "alignof mismatch for RenderBundle");

// RenderBundleEncoder implementation

void RenderBundleEncoder::Draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) const {
    wgpuRenderBundleEncoderDraw(Get(), vertexCount, instanceCount, firstVertex, firstInstance);
}
void RenderBundleEncoder::DrawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance) const {
    wgpuRenderBundleEncoderDrawIndexed(Get(), indexCount, instanceCount, firstIndex, baseVertex, firstInstance);
}
void RenderBundleEncoder::DrawIndexedIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const {
    wgpuRenderBundleEncoderDrawIndexedIndirect(Get(), indirectBuffer.Get(), indirectOffset);
}
void RenderBundleEncoder::DrawIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const {
    wgpuRenderBundleEncoderDrawIndirect(Get(), indirectBuffer.Get(), indirectOffset);
}
RenderBundle RenderBundleEncoder::Finish(RenderBundleDescriptor const * descriptor) const {
    auto result = wgpuRenderBundleEncoderFinish(Get(), reinterpret_cast<WGPURenderBundleDescriptor const * >(descriptor));
    return RenderBundle::Acquire(result);
}
void RenderBundleEncoder::InsertDebugMarker(char const * markerLabel) const {
    wgpuRenderBundleEncoderInsertDebugMarker(Get(), reinterpret_cast<char const * >(markerLabel));
}
void RenderBundleEncoder::PopDebugGroup() const {
    wgpuRenderBundleEncoderPopDebugGroup(Get());
}
void RenderBundleEncoder::PushDebugGroup(char const * groupLabel) const {
    wgpuRenderBundleEncoderPushDebugGroup(Get(), reinterpret_cast<char const * >(groupLabel));
}
void RenderBundleEncoder::SetBindGroup(uint32_t groupIndex, BindGroup const& group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) const {
    wgpuRenderBundleEncoderSetBindGroup(Get(), groupIndex, group.Get(), dynamicOffsetCount, reinterpret_cast<uint32_t const * >(dynamicOffsets));
}
void RenderBundleEncoder::SetIndexBuffer(Buffer const& buffer, IndexFormat format, uint64_t offset, uint64_t size) const {
    wgpuRenderBundleEncoderSetIndexBuffer(Get(), buffer.Get(), static_cast<WGPUIndexFormat>(format), offset, size);
}
void RenderBundleEncoder::SetLabel(char const * label) const {
    wgpuRenderBundleEncoderSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void RenderBundleEncoder::SetPipeline(RenderPipeline const& pipeline) const {
    wgpuRenderBundleEncoderSetPipeline(Get(), pipeline.Get());
}
void RenderBundleEncoder::SetVertexBuffer(uint32_t slot, Buffer const& buffer, uint64_t offset, uint64_t size) const {
    wgpuRenderBundleEncoderSetVertexBuffer(Get(), slot, buffer.Get(), offset, size);
}
void RenderBundleEncoder::WGPUAddRef(WGPURenderBundleEncoder handle) {
    if (handle != nullptr) {
        wgpuRenderBundleEncoderAddRef(handle);
    }
}
void RenderBundleEncoder::WGPURelease(WGPURenderBundleEncoder handle) {
    if (handle != nullptr) {
        wgpuRenderBundleEncoderRelease(handle);
    }
}
static_assert(sizeof(RenderBundleEncoder) == sizeof(WGPURenderBundleEncoder), "sizeof mismatch for RenderBundleEncoder");
static_assert(alignof(RenderBundleEncoder) == alignof(WGPURenderBundleEncoder), "alignof mismatch for RenderBundleEncoder");

// RenderPassEncoder implementation

void RenderPassEncoder::BeginOcclusionQuery(uint32_t queryIndex) const {
    wgpuRenderPassEncoderBeginOcclusionQuery(Get(), queryIndex);
}
void RenderPassEncoder::Draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) const {
    wgpuRenderPassEncoderDraw(Get(), vertexCount, instanceCount, firstVertex, firstInstance);
}
void RenderPassEncoder::DrawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance) const {
    wgpuRenderPassEncoderDrawIndexed(Get(), indexCount, instanceCount, firstIndex, baseVertex, firstInstance);
}
void RenderPassEncoder::DrawIndexedIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const {
    wgpuRenderPassEncoderDrawIndexedIndirect(Get(), indirectBuffer.Get(), indirectOffset);
}
void RenderPassEncoder::DrawIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const {
    wgpuRenderPassEncoderDrawIndirect(Get(), indirectBuffer.Get(), indirectOffset);
}
void RenderPassEncoder::End() const {
    wgpuRenderPassEncoderEnd(Get());
}
void RenderPassEncoder::EndOcclusionQuery() const {
    wgpuRenderPassEncoderEndOcclusionQuery(Get());
}
void RenderPassEncoder::ExecuteBundles(size_t bundleCount, RenderBundle const * bundles) const {
    wgpuRenderPassEncoderExecuteBundles(Get(), bundleCount, reinterpret_cast<WGPURenderBundle const * >(bundles));
}
void RenderPassEncoder::InsertDebugMarker(char const * markerLabel) const {
    wgpuRenderPassEncoderInsertDebugMarker(Get(), reinterpret_cast<char const * >(markerLabel));
}
void RenderPassEncoder::PopDebugGroup() const {
    wgpuRenderPassEncoderPopDebugGroup(Get());
}
void RenderPassEncoder::PushDebugGroup(char const * groupLabel) const {
    wgpuRenderPassEncoderPushDebugGroup(Get(), reinterpret_cast<char const * >(groupLabel));
}
void RenderPassEncoder::SetBindGroup(uint32_t groupIndex, BindGroup const& group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) const {
    wgpuRenderPassEncoderSetBindGroup(Get(), groupIndex, group.Get(), dynamicOffsetCount, reinterpret_cast<uint32_t const * >(dynamicOffsets));
}
void RenderPassEncoder::SetBlendConstant(Color const * color) const {
    wgpuRenderPassEncoderSetBlendConstant(Get(), reinterpret_cast<WGPUColor const * >(color));
}
void RenderPassEncoder::SetIndexBuffer(Buffer const& buffer, IndexFormat format, uint64_t offset, uint64_t size) const {
    wgpuRenderPassEncoderSetIndexBuffer(Get(), buffer.Get(), static_cast<WGPUIndexFormat>(format), offset, size);
}
void RenderPassEncoder::SetLabel(char const * label) const {
    wgpuRenderPassEncoderSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void RenderPassEncoder::SetPipeline(RenderPipeline const& pipeline) const {
    wgpuRenderPassEncoderSetPipeline(Get(), pipeline.Get());
}
void RenderPassEncoder::SetScissorRect(uint32_t x, uint32_t y, uint32_t width, uint32_t height) const {
    wgpuRenderPassEncoderSetScissorRect(Get(), x, y, width, height);
}
void RenderPassEncoder::SetStencilReference(uint32_t reference) const {
    wgpuRenderPassEncoderSetStencilReference(Get(), reference);
}
void RenderPassEncoder::SetVertexBuffer(uint32_t slot, Buffer const& buffer, uint64_t offset, uint64_t size) const {
    wgpuRenderPassEncoderSetVertexBuffer(Get(), slot, buffer.Get(), offset, size);
}
void RenderPassEncoder::SetViewport(float x, float y, float width, float height, float minDepth, float maxDepth) const {
    wgpuRenderPassEncoderSetViewport(Get(), x, y, width, height, minDepth, maxDepth);
}
void RenderPassEncoder::WriteTimestamp(QuerySet const& querySet, uint32_t queryIndex) const {
    wgpuRenderPassEncoderWriteTimestamp(Get(), querySet.Get(), queryIndex);
}
void RenderPassEncoder::WGPUAddRef(WGPURenderPassEncoder handle) {
    if (handle != nullptr) {
        wgpuRenderPassEncoderAddRef(handle);
    }
}
void RenderPassEncoder::WGPURelease(WGPURenderPassEncoder handle) {
    if (handle != nullptr) {
        wgpuRenderPassEncoderRelease(handle);
    }
}
static_assert(sizeof(RenderPassEncoder) == sizeof(WGPURenderPassEncoder), "sizeof mismatch for RenderPassEncoder");
static_assert(alignof(RenderPassEncoder) == alignof(WGPURenderPassEncoder), "alignof mismatch for RenderPassEncoder");

// RenderPipeline implementation

BindGroupLayout RenderPipeline::GetBindGroupLayout(uint32_t groupIndex) const {
    auto result = wgpuRenderPipelineGetBindGroupLayout(Get(), groupIndex);
    return BindGroupLayout::Acquire(result);
}
void RenderPipeline::SetLabel(char const * label) const {
    wgpuRenderPipelineSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void RenderPipeline::WGPUAddRef(WGPURenderPipeline handle) {
    if (handle != nullptr) {
        wgpuRenderPipelineAddRef(handle);
    }
}
void RenderPipeline::WGPURelease(WGPURenderPipeline handle) {
    if (handle != nullptr) {
        wgpuRenderPipelineRelease(handle);
    }
}
static_assert(sizeof(RenderPipeline) == sizeof(WGPURenderPipeline), "sizeof mismatch for RenderPipeline");
static_assert(alignof(RenderPipeline) == alignof(WGPURenderPipeline), "alignof mismatch for RenderPipeline");

// Sampler implementation

void Sampler::SetLabel(char const * label) const {
    wgpuSamplerSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void Sampler::WGPUAddRef(WGPUSampler handle) {
    if (handle != nullptr) {
        wgpuSamplerAddRef(handle);
    }
}
void Sampler::WGPURelease(WGPUSampler handle) {
    if (handle != nullptr) {
        wgpuSamplerRelease(handle);
    }
}
static_assert(sizeof(Sampler) == sizeof(WGPUSampler), "sizeof mismatch for Sampler");
static_assert(alignof(Sampler) == alignof(WGPUSampler), "alignof mismatch for Sampler");

// ShaderModule implementation

void ShaderModule::GetCompilationInfo(CompilationInfoCallback callback, void * userdata) const {
    wgpuShaderModuleGetCompilationInfo(Get(), callback, userdata);
}
Future ShaderModule::GetCompilationInfo(CompilationInfoCallbackInfo callbackInfo) const {
    auto result = wgpuShaderModuleGetCompilationInfoF(Get(), *reinterpret_cast<WGPUCompilationInfoCallbackInfo const*>(&callbackInfo));
    return Future {
            result.id
        };
}
void ShaderModule::SetLabel(char const * label) const {
    wgpuShaderModuleSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void ShaderModule::WGPUAddRef(WGPUShaderModule handle) {
    if (handle != nullptr) {
        wgpuShaderModuleAddRef(handle);
    }
}
void ShaderModule::WGPURelease(WGPUShaderModule handle) {
    if (handle != nullptr) {
        wgpuShaderModuleRelease(handle);
    }
}
static_assert(sizeof(ShaderModule) == sizeof(WGPUShaderModule), "sizeof mismatch for ShaderModule");
static_assert(alignof(ShaderModule) == alignof(WGPUShaderModule), "alignof mismatch for ShaderModule");

// Surface implementation

void Surface::Configure(SurfaceConfiguration const * config) const {
    wgpuSurfaceConfigure(Get(), reinterpret_cast<WGPUSurfaceConfiguration const * >(config));
}
ConvertibleStatus Surface::GetCapabilities(Adapter const& adapter, SurfaceCapabilities * capabilities) const {
    *capabilities = SurfaceCapabilities();
    auto result = wgpuSurfaceGetCapabilities(Get(), adapter.Get(), reinterpret_cast<WGPUSurfaceCapabilities * >(capabilities));
    return static_cast<Status>(result);
}
void Surface::GetCurrentTexture(SurfaceTexture * surfaceTexture) const {
    wgpuSurfaceGetCurrentTexture(Get(), reinterpret_cast<WGPUSurfaceTexture * >(surfaceTexture));
}
TextureFormat Surface::GetPreferredFormat(Adapter const& adapter) const {
    auto result = wgpuSurfaceGetPreferredFormat(Get(), adapter.Get());
    return static_cast<TextureFormat>(result);
}
void Surface::Present() const {
    wgpuSurfacePresent(Get());
}
void Surface::Unconfigure() const {
    wgpuSurfaceUnconfigure(Get());
}
void Surface::WGPUAddRef(WGPUSurface handle) {
    if (handle != nullptr) {
        wgpuSurfaceAddRef(handle);
    }
}
void Surface::WGPURelease(WGPUSurface handle) {
    if (handle != nullptr) {
        wgpuSurfaceRelease(handle);
    }
}
static_assert(sizeof(Surface) == sizeof(WGPUSurface), "sizeof mismatch for Surface");
static_assert(alignof(Surface) == alignof(WGPUSurface), "alignof mismatch for Surface");

// SwapChain implementation

TextureView SwapChain::GetCurrentTextureView() const {
    auto result = wgpuSwapChainGetCurrentTextureView(Get());
    return TextureView::Acquire(result);
}
void SwapChain::Present() const {
    wgpuSwapChainPresent(Get());
}
void SwapChain::WGPUAddRef(WGPUSwapChain handle) {
    if (handle != nullptr) {
        wgpuSwapChainAddRef(handle);
    }
}
void SwapChain::WGPURelease(WGPUSwapChain handle) {
    if (handle != nullptr) {
        wgpuSwapChainRelease(handle);
    }
}
static_assert(sizeof(SwapChain) == sizeof(WGPUSwapChain), "sizeof mismatch for SwapChain");
static_assert(alignof(SwapChain) == alignof(WGPUSwapChain), "alignof mismatch for SwapChain");

// Texture implementation

TextureView Texture::CreateView(TextureViewDescriptor const * descriptor) const {
    auto result = wgpuTextureCreateView(Get(), reinterpret_cast<WGPUTextureViewDescriptor const * >(descriptor));
    return TextureView::Acquire(result);
}
void Texture::Destroy() const {
    wgpuTextureDestroy(Get());
}
uint32_t Texture::GetDepthOrArrayLayers() const {
    auto result = wgpuTextureGetDepthOrArrayLayers(Get());
    return result;
}
TextureDimension Texture::GetDimension() const {
    auto result = wgpuTextureGetDimension(Get());
    return static_cast<TextureDimension>(result);
}
TextureFormat Texture::GetFormat() const {
    auto result = wgpuTextureGetFormat(Get());
    return static_cast<TextureFormat>(result);
}
uint32_t Texture::GetHeight() const {
    auto result = wgpuTextureGetHeight(Get());
    return result;
}
uint32_t Texture::GetMipLevelCount() const {
    auto result = wgpuTextureGetMipLevelCount(Get());
    return result;
}
uint32_t Texture::GetSampleCount() const {
    auto result = wgpuTextureGetSampleCount(Get());
    return result;
}
TextureUsage Texture::GetUsage() const {
    auto result = wgpuTextureGetUsage(Get());
    return static_cast<TextureUsage>(result);
}
uint32_t Texture::GetWidth() const {
    auto result = wgpuTextureGetWidth(Get());
    return result;
}
void Texture::SetLabel(char const * label) const {
    wgpuTextureSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void Texture::WGPUAddRef(WGPUTexture handle) {
    if (handle != nullptr) {
        wgpuTextureAddRef(handle);
    }
}
void Texture::WGPURelease(WGPUTexture handle) {
    if (handle != nullptr) {
        wgpuTextureRelease(handle);
    }
}
static_assert(sizeof(Texture) == sizeof(WGPUTexture), "sizeof mismatch for Texture");
static_assert(alignof(Texture) == alignof(WGPUTexture), "alignof mismatch for Texture");

// TextureView implementation

void TextureView::SetLabel(char const * label) const {
    wgpuTextureViewSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void TextureView::WGPUAddRef(WGPUTextureView handle) {
    if (handle != nullptr) {
        wgpuTextureViewAddRef(handle);
    }
}
void TextureView::WGPURelease(WGPUTextureView handle) {
    if (handle != nullptr) {
        wgpuTextureViewRelease(handle);
    }
}
static_assert(sizeof(TextureView) == sizeof(WGPUTextureView), "sizeof mismatch for TextureView");
static_assert(alignof(TextureView) == alignof(WGPUTextureView), "alignof mismatch for TextureView");




// Free Functions
static inline Instance CreateInstance(InstanceDescriptor const * descriptor = nullptr) {
    auto result = wgpuCreateInstance(reinterpret_cast<WGPUInstanceDescriptor const * >(descriptor));
    return Instance::Acquire(result);
}
static inline Status GetInstanceFeatures(InstanceFeatures * features) {
    auto result = wgpuGetInstanceFeatures(reinterpret_cast<WGPUInstanceFeatures * >(features));
    return static_cast<Status>(result);
}
static inline Proc GetProcAddress(Device device, char const * procName) {
    auto result = wgpuGetProcAddress(device.Get(), reinterpret_cast<char const * >(procName));
    return reinterpret_cast<Proc>(result);
}

}  // namespace wgpu

namespace wgpu {
template<>
struct IsWGPUBitmask<wgpu::BufferUsage> {
    static constexpr bool enable = true;
};

template<>
struct IsWGPUBitmask<wgpu::ColorWriteMask> {
    static constexpr bool enable = true;
};

template<>
struct IsWGPUBitmask<wgpu::MapMode> {
    static constexpr bool enable = true;
};

template<>
struct IsWGPUBitmask<wgpu::ShaderStage> {
    static constexpr bool enable = true;
};

template<>
struct IsWGPUBitmask<wgpu::TextureUsage> {
    static constexpr bool enable = true;
};

} // namespace wgpu

namespace std {
// Custom boolean class needs corresponding hash function so that it appears as a transparent bool.
template <>
struct hash<wgpu::Bool> {
  public:
    size_t operator()(const wgpu::Bool &v) const {
        return hash<bool>()(v);
    }
};
}  // namespace std

#endif // WEBGPU_CPP_H_
