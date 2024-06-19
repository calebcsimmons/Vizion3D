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
#ifdef __EMSCRIPTEN__
#error "Do not include this header. Emscripten already provides headers needed for WebGPU."
#endif
#ifndef DAWN_WIRE_CLIENT_WEBGPU_CPP_H_
#define DAWN_WIRE_CLIENT_WEBGPU_CPP_H_

#include <cmath>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <functional>

#include "dawn/wire/client/webgpu.h"
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
    ChromiumTestingUnimplemented = WGPUWGSLFeatureName_ChromiumTestingUnimplemented,
    ChromiumTestingUnsafeExperimental = WGPUWGSLFeatureName_ChromiumTestingUnsafeExperimental,
    ChromiumTestingExperimental = WGPUWGSLFeatureName_ChromiumTestingExperimental,
    ChromiumTestingShippedWithKillswitch = WGPUWGSLFeatureName_ChromiumTestingShippedWithKillswitch,
    ChromiumTestingShipped = WGPUWGSLFeatureName_ChromiumTestingShipped,
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

enum class AlphaMode : uint32_t {
    Opaque = WGPUAlphaMode_Opaque,
    Premultiplied = WGPUAlphaMode_Premultiplied,
    Unpremultiplied = WGPUAlphaMode_Unpremultiplied,
};
static_assert(sizeof(AlphaMode) == sizeof(WGPUAlphaMode), "sizeof mismatch for AlphaMode");
static_assert(alignof(AlphaMode) == alignof(WGPUAlphaMode), "alignof mismatch for AlphaMode");

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
    Src1 = WGPUBlendFactor_Src1,
    OneMinusSrc1 = WGPUBlendFactor_OneMinusSrc1,
    Src1Alpha = WGPUBlendFactor_Src1Alpha,
    OneMinusSrc1Alpha = WGPUBlendFactor_OneMinusSrc1Alpha,
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

enum class ExternalTextureRotation : uint32_t {
    Rotate0Degrees = WGPUExternalTextureRotation_Rotate0Degrees,
    Rotate90Degrees = WGPUExternalTextureRotation_Rotate90Degrees,
    Rotate180Degrees = WGPUExternalTextureRotation_Rotate180Degrees,
    Rotate270Degrees = WGPUExternalTextureRotation_Rotate270Degrees,
};
static_assert(sizeof(ExternalTextureRotation) == sizeof(WGPUExternalTextureRotation), "sizeof mismatch for ExternalTextureRotation");
static_assert(alignof(ExternalTextureRotation) == alignof(WGPUExternalTextureRotation), "alignof mismatch for ExternalTextureRotation");

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
    DawnInternalUsages = WGPUFeatureName_DawnInternalUsages,
    DawnMultiPlanarFormats = WGPUFeatureName_DawnMultiPlanarFormats,
    DawnNative = WGPUFeatureName_DawnNative,
    ChromiumExperimentalTimestampQueryInsidePasses = WGPUFeatureName_ChromiumExperimentalTimestampQueryInsidePasses,
    ImplicitDeviceSynchronization = WGPUFeatureName_ImplicitDeviceSynchronization,
    SurfaceCapabilities = WGPUFeatureName_SurfaceCapabilities,
    TransientAttachments = WGPUFeatureName_TransientAttachments,
    MSAARenderToSingleSampled = WGPUFeatureName_MSAARenderToSingleSampled,
    DualSourceBlending = WGPUFeatureName_DualSourceBlending,
    D3D11MultithreadProtected = WGPUFeatureName_D3D11MultithreadProtected,
    ANGLETextureSharing = WGPUFeatureName_ANGLETextureSharing,
    ChromiumExperimentalSubgroups = WGPUFeatureName_ChromiumExperimentalSubgroups,
    ChromiumExperimentalSubgroupUniformControlFlow = WGPUFeatureName_ChromiumExperimentalSubgroupUniformControlFlow,
    PixelLocalStorageCoherent = WGPUFeatureName_PixelLocalStorageCoherent,
    PixelLocalStorageNonCoherent = WGPUFeatureName_PixelLocalStorageNonCoherent,
    Unorm16TextureFormats = WGPUFeatureName_Unorm16TextureFormats,
    Snorm16TextureFormats = WGPUFeatureName_Snorm16TextureFormats,
    MultiPlanarFormatExtendedUsages = WGPUFeatureName_MultiPlanarFormatExtendedUsages,
    MultiPlanarFormatP010 = WGPUFeatureName_MultiPlanarFormatP010,
    HostMappedPointer = WGPUFeatureName_HostMappedPointer,
    MultiPlanarRenderTargets = WGPUFeatureName_MultiPlanarRenderTargets,
    MultiPlanarFormatNv12a = WGPUFeatureName_MultiPlanarFormatNv12a,
    FramebufferFetch = WGPUFeatureName_FramebufferFetch,
    BufferMapExtendedUsages = WGPUFeatureName_BufferMapExtendedUsages,
    AdapterPropertiesMemoryHeaps = WGPUFeatureName_AdapterPropertiesMemoryHeaps,
    AdapterPropertiesD3D = WGPUFeatureName_AdapterPropertiesD3D,
    AdapterPropertiesVk = WGPUFeatureName_AdapterPropertiesVk,
    R8UnormStorage = WGPUFeatureName_R8UnormStorage,
    FormatCapabilities = WGPUFeatureName_FormatCapabilities,
    DrmFormatCapabilities = WGPUFeatureName_DrmFormatCapabilities,
    Norm16TextureFormats = WGPUFeatureName_Norm16TextureFormats,
    MultiPlanarFormatNv16 = WGPUFeatureName_MultiPlanarFormatNv16,
    MultiPlanarFormatNv24 = WGPUFeatureName_MultiPlanarFormatNv24,
    MultiPlanarFormatP210 = WGPUFeatureName_MultiPlanarFormatP210,
    MultiPlanarFormatP410 = WGPUFeatureName_MultiPlanarFormatP410,
    SharedTextureMemoryVkDedicatedAllocation = WGPUFeatureName_SharedTextureMemoryVkDedicatedAllocation,
    SharedTextureMemoryAHardwareBuffer = WGPUFeatureName_SharedTextureMemoryAHardwareBuffer,
    SharedTextureMemoryDmaBuf = WGPUFeatureName_SharedTextureMemoryDmaBuf,
    SharedTextureMemoryOpaqueFD = WGPUFeatureName_SharedTextureMemoryOpaqueFD,
    SharedTextureMemoryZirconHandle = WGPUFeatureName_SharedTextureMemoryZirconHandle,
    SharedTextureMemoryDXGISharedHandle = WGPUFeatureName_SharedTextureMemoryDXGISharedHandle,
    SharedTextureMemoryD3D11Texture2D = WGPUFeatureName_SharedTextureMemoryD3D11Texture2D,
    SharedTextureMemoryIOSurface = WGPUFeatureName_SharedTextureMemoryIOSurface,
    SharedTextureMemoryEGLImage = WGPUFeatureName_SharedTextureMemoryEGLImage,
    SharedFenceVkSemaphoreOpaqueFD = WGPUFeatureName_SharedFenceVkSemaphoreOpaqueFD,
    SharedFenceVkSemaphoreSyncFD = WGPUFeatureName_SharedFenceVkSemaphoreSyncFD,
    SharedFenceVkSemaphoreZirconHandle = WGPUFeatureName_SharedFenceVkSemaphoreZirconHandle,
    SharedFenceDXGISharedHandle = WGPUFeatureName_SharedFenceDXGISharedHandle,
    SharedFenceMTLSharedEvent = WGPUFeatureName_SharedFenceMTLSharedEvent,
    SharedBufferMemoryD3D12Resource = WGPUFeatureName_SharedBufferMemoryD3D12Resource,
    StaticSamplers = WGPUFeatureName_StaticSamplers,
    YCbCrVulkanSamplers = WGPUFeatureName_YCbCrVulkanSamplers,
    ShaderModuleCompilationOptions = WGPUFeatureName_ShaderModuleCompilationOptions,
    DawnLoadResolveTexture = WGPUFeatureName_DawnLoadResolveTexture,
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
    ExpandResolveTexture = WGPULoadOp_ExpandResolveTexture,
};
static_assert(sizeof(LoadOp) == sizeof(WGPULoadOp), "sizeof mismatch for LoadOp");
static_assert(alignof(LoadOp) == alignof(WGPULoadOp), "alignof mismatch for LoadOp");

enum class LoggingType : uint32_t {
    Verbose = WGPULoggingType_Verbose,
    Info = WGPULoggingType_Info,
    Warning = WGPULoggingType_Warning,
    Error = WGPULoggingType_Error,
};
static_assert(sizeof(LoggingType) == sizeof(WGPULoggingType), "sizeof mismatch for LoggingType");
static_assert(alignof(LoggingType) == alignof(WGPULoggingType), "alignof mismatch for LoggingType");

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
    SurfaceDescriptorFromMetalLayer = WGPUSType_SurfaceDescriptorFromMetalLayer,
    SurfaceDescriptorFromWindowsHWND = WGPUSType_SurfaceDescriptorFromWindowsHWND,
    SurfaceDescriptorFromXlibWindow = WGPUSType_SurfaceDescriptorFromXlibWindow,
    SurfaceDescriptorFromCanvasHTMLSelector = WGPUSType_SurfaceDescriptorFromCanvasHTMLSelector,
    ShaderModuleSPIRVDescriptor = WGPUSType_ShaderModuleSPIRVDescriptor,
    ShaderModuleWGSLDescriptor = WGPUSType_ShaderModuleWGSLDescriptor,
    PrimitiveDepthClipControl = WGPUSType_PrimitiveDepthClipControl,
    SurfaceDescriptorFromWaylandSurface = WGPUSType_SurfaceDescriptorFromWaylandSurface,
    SurfaceDescriptorFromAndroidNativeWindow = WGPUSType_SurfaceDescriptorFromAndroidNativeWindow,
    SurfaceDescriptorFromWindowsCoreWindow = WGPUSType_SurfaceDescriptorFromWindowsCoreWindow,
    ExternalTextureBindingEntry = WGPUSType_ExternalTextureBindingEntry,
    ExternalTextureBindingLayout = WGPUSType_ExternalTextureBindingLayout,
    SurfaceDescriptorFromWindowsSwapChainPanel = WGPUSType_SurfaceDescriptorFromWindowsSwapChainPanel,
    RenderPassDescriptorMaxDrawCount = WGPUSType_RenderPassDescriptorMaxDrawCount,
    DepthStencilStateDepthWriteDefinedDawn = WGPUSType_DepthStencilStateDepthWriteDefinedDawn,
    TextureBindingViewDimensionDescriptor = WGPUSType_TextureBindingViewDimensionDescriptor,
    DawnTextureInternalUsageDescriptor = WGPUSType_DawnTextureInternalUsageDescriptor,
    DawnEncoderInternalUsageDescriptor = WGPUSType_DawnEncoderInternalUsageDescriptor,
    DawnInstanceDescriptor = WGPUSType_DawnInstanceDescriptor,
    DawnCacheDeviceDescriptor = WGPUSType_DawnCacheDeviceDescriptor,
    DawnAdapterPropertiesPowerPreference = WGPUSType_DawnAdapterPropertiesPowerPreference,
    DawnBufferDescriptorErrorInfoFromWireClient = WGPUSType_DawnBufferDescriptorErrorInfoFromWireClient,
    DawnTogglesDescriptor = WGPUSType_DawnTogglesDescriptor,
    DawnShaderModuleSPIRVOptionsDescriptor = WGPUSType_DawnShaderModuleSPIRVOptionsDescriptor,
    RequestAdapterOptionsLUID = WGPUSType_RequestAdapterOptionsLUID,
    RequestAdapterOptionsGetGLProc = WGPUSType_RequestAdapterOptionsGetGLProc,
    RequestAdapterOptionsD3D11Device = WGPUSType_RequestAdapterOptionsD3D11Device,
    DawnMultisampleStateRenderToSingleSampled = WGPUSType_DawnMultisampleStateRenderToSingleSampled,
    DawnRenderPassColorAttachmentRenderToSingleSampled = WGPUSType_DawnRenderPassColorAttachmentRenderToSingleSampled,
    RenderPassPixelLocalStorage = WGPUSType_RenderPassPixelLocalStorage,
    PipelineLayoutPixelLocalStorage = WGPUSType_PipelineLayoutPixelLocalStorage,
    BufferHostMappedPointer = WGPUSType_BufferHostMappedPointer,
    DawnExperimentalSubgroupLimits = WGPUSType_DawnExperimentalSubgroupLimits,
    AdapterPropertiesMemoryHeaps = WGPUSType_AdapterPropertiesMemoryHeaps,
    AdapterPropertiesD3D = WGPUSType_AdapterPropertiesD3D,
    AdapterPropertiesVk = WGPUSType_AdapterPropertiesVk,
    DawnComputePipelineFullSubgroups = WGPUSType_DawnComputePipelineFullSubgroups,
    DawnWireWGSLControl = WGPUSType_DawnWireWGSLControl,
    DawnWGSLBlocklist = WGPUSType_DawnWGSLBlocklist,
    DrmFormatCapabilities = WGPUSType_DrmFormatCapabilities,
    ShaderModuleCompilationOptions = WGPUSType_ShaderModuleCompilationOptions,
    ColorTargetStateExpandResolveTextureDawn = WGPUSType_ColorTargetStateExpandResolveTextureDawn,
    SharedTextureMemoryVkDedicatedAllocationDescriptor = WGPUSType_SharedTextureMemoryVkDedicatedAllocationDescriptor,
    SharedTextureMemoryAHardwareBufferDescriptor = WGPUSType_SharedTextureMemoryAHardwareBufferDescriptor,
    SharedTextureMemoryDmaBufDescriptor = WGPUSType_SharedTextureMemoryDmaBufDescriptor,
    SharedTextureMemoryOpaqueFDDescriptor = WGPUSType_SharedTextureMemoryOpaqueFDDescriptor,
    SharedTextureMemoryZirconHandleDescriptor = WGPUSType_SharedTextureMemoryZirconHandleDescriptor,
    SharedTextureMemoryDXGISharedHandleDescriptor = WGPUSType_SharedTextureMemoryDXGISharedHandleDescriptor,
    SharedTextureMemoryD3D11Texture2DDescriptor = WGPUSType_SharedTextureMemoryD3D11Texture2DDescriptor,
    SharedTextureMemoryIOSurfaceDescriptor = WGPUSType_SharedTextureMemoryIOSurfaceDescriptor,
    SharedTextureMemoryEGLImageDescriptor = WGPUSType_SharedTextureMemoryEGLImageDescriptor,
    SharedTextureMemoryInitializedBeginState = WGPUSType_SharedTextureMemoryInitializedBeginState,
    SharedTextureMemoryInitializedEndState = WGPUSType_SharedTextureMemoryInitializedEndState,
    SharedTextureMemoryVkImageLayoutBeginState = WGPUSType_SharedTextureMemoryVkImageLayoutBeginState,
    SharedTextureMemoryVkImageLayoutEndState = WGPUSType_SharedTextureMemoryVkImageLayoutEndState,
    SharedTextureMemoryD3DSwapchainBeginState = WGPUSType_SharedTextureMemoryD3DSwapchainBeginState,
    SharedFenceVkSemaphoreOpaqueFDDescriptor = WGPUSType_SharedFenceVkSemaphoreOpaqueFDDescriptor,
    SharedFenceVkSemaphoreOpaqueFDExportInfo = WGPUSType_SharedFenceVkSemaphoreOpaqueFDExportInfo,
    SharedFenceVkSemaphoreSyncFDDescriptor = WGPUSType_SharedFenceVkSemaphoreSyncFDDescriptor,
    SharedFenceVkSemaphoreSyncFDExportInfo = WGPUSType_SharedFenceVkSemaphoreSyncFDExportInfo,
    SharedFenceVkSemaphoreZirconHandleDescriptor = WGPUSType_SharedFenceVkSemaphoreZirconHandleDescriptor,
    SharedFenceVkSemaphoreZirconHandleExportInfo = WGPUSType_SharedFenceVkSemaphoreZirconHandleExportInfo,
    SharedFenceDXGISharedHandleDescriptor = WGPUSType_SharedFenceDXGISharedHandleDescriptor,
    SharedFenceDXGISharedHandleExportInfo = WGPUSType_SharedFenceDXGISharedHandleExportInfo,
    SharedFenceMTLSharedEventDescriptor = WGPUSType_SharedFenceMTLSharedEventDescriptor,
    SharedFenceMTLSharedEventExportInfo = WGPUSType_SharedFenceMTLSharedEventExportInfo,
    SharedBufferMemoryD3D12ResourceDescriptor = WGPUSType_SharedBufferMemoryD3D12ResourceDescriptor,
    StaticSamplerBindingLayout = WGPUSType_StaticSamplerBindingLayout,
    YCbCrVkDescriptor = WGPUSType_YCbCrVkDescriptor,
    SharedTextureMemoryAHardwareBufferProperties = WGPUSType_SharedTextureMemoryAHardwareBufferProperties,
    AHardwareBufferProperties = WGPUSType_AHardwareBufferProperties,
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

enum class SharedFenceType : uint32_t {
    Undefined = WGPUSharedFenceType_Undefined,
    VkSemaphoreOpaqueFD = WGPUSharedFenceType_VkSemaphoreOpaqueFD,
    VkSemaphoreSyncFD = WGPUSharedFenceType_VkSemaphoreSyncFD,
    VkSemaphoreZirconHandle = WGPUSharedFenceType_VkSemaphoreZirconHandle,
    DXGISharedHandle = WGPUSharedFenceType_DXGISharedHandle,
    MTLSharedEvent = WGPUSharedFenceType_MTLSharedEvent,
};
static_assert(sizeof(SharedFenceType) == sizeof(WGPUSharedFenceType), "sizeof mismatch for SharedFenceType");
static_assert(alignof(SharedFenceType) == alignof(WGPUSharedFenceType), "alignof mismatch for SharedFenceType");

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
    Plane0Only = WGPUTextureAspect_Plane0Only,
    Plane1Only = WGPUTextureAspect_Plane1Only,
    Plane2Only = WGPUTextureAspect_Plane2Only,
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
    R16Unorm = WGPUTextureFormat_R16Unorm,
    RG16Unorm = WGPUTextureFormat_RG16Unorm,
    RGBA16Unorm = WGPUTextureFormat_RGBA16Unorm,
    R16Snorm = WGPUTextureFormat_R16Snorm,
    RG16Snorm = WGPUTextureFormat_RG16Snorm,
    RGBA16Snorm = WGPUTextureFormat_RGBA16Snorm,
    R8BG8Biplanar420Unorm = WGPUTextureFormat_R8BG8Biplanar420Unorm,
    R10X6BG10X6Biplanar420Unorm = WGPUTextureFormat_R10X6BG10X6Biplanar420Unorm,
    R8BG8A8Triplanar420Unorm = WGPUTextureFormat_R8BG8A8Triplanar420Unorm,
    R8BG8Biplanar422Unorm = WGPUTextureFormat_R8BG8Biplanar422Unorm,
    R8BG8Biplanar444Unorm = WGPUTextureFormat_R8BG8Biplanar444Unorm,
    R10X6BG10X6Biplanar422Unorm = WGPUTextureFormat_R10X6BG10X6Biplanar422Unorm,
    R10X6BG10X6Biplanar444Unorm = WGPUTextureFormat_R10X6BG10X6Biplanar444Unorm,
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

enum class HeapProperty : uint32_t {
    Undefined = WGPUHeapProperty_Undefined,
    DeviceLocal = WGPUHeapProperty_DeviceLocal,
    HostVisible = WGPUHeapProperty_HostVisible,
    HostCoherent = WGPUHeapProperty_HostCoherent,
    HostUncached = WGPUHeapProperty_HostUncached,
    HostCached = WGPUHeapProperty_HostCached,
};
static_assert(sizeof(HeapProperty) == sizeof(WGPUHeapPropertyFlags), "sizeof mismatch for HeapProperty");
static_assert(alignof(HeapProperty) == alignof(WGPUHeapPropertyFlags), "alignof mismatch for HeapProperty");

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
    TransientAttachment = WGPUTextureUsage_TransientAttachment,
    StorageAttachment = WGPUTextureUsage_StorageAttachment,
};
static_assert(sizeof(TextureUsage) == sizeof(WGPUTextureUsageFlags), "sizeof mismatch for TextureUsage");
static_assert(alignof(TextureUsage) == alignof(WGPUTextureUsageFlags), "alignof mismatch for TextureUsage");


using BufferMapCallback = WGPUBufferMapCallback;
using Callback = WGPUCallback;
using CompilationInfoCallback = WGPUCompilationInfoCallback;
using CreateComputePipelineAsyncCallback = WGPUCreateComputePipelineAsyncCallback;
using CreateRenderPipelineAsyncCallback = WGPUCreateRenderPipelineAsyncCallback;
using DawnLoadCacheDataFunction = WGPUDawnLoadCacheDataFunction;
using DawnStoreCacheDataFunction = WGPUDawnStoreCacheDataFunction;
using DeviceLostCallback = WGPUDeviceLostCallback;
using DeviceLostCallbackNew = WGPUDeviceLostCallbackNew;
using ErrorCallback = WGPUErrorCallback;
using LoggingCallback = WGPULoggingCallback;
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





namespace dawn::wire::client {

class Adapter;
class BindGroup;
class BindGroupLayout;
class Buffer;
class CommandBuffer;
class CommandEncoder;
class ComputePassEncoder;
class ComputePipeline;
class Device;
class ExternalTexture;
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
class SharedBufferMemory;
class SharedFence;
class SharedTextureMemory;
class Surface;
class SwapChain;
class Texture;
class TextureView;

struct AdapterInfo;
struct AdapterProperties;
struct AdapterPropertiesD3D;
struct AdapterPropertiesVk;
struct BindGroupEntry;
struct BlendComponent;
struct BufferBindingLayout;
struct BufferDescriptor;
struct BufferHostMappedPointer;
struct BufferMapCallbackInfo;
struct Color;
struct ColorTargetStateExpandResolveTextureDawn;
struct CommandBufferDescriptor;
struct CommandEncoderDescriptor;
struct CompilationInfoCallbackInfo;
struct CompilationMessage;
struct ComputePassTimestampWrites;
struct ConstantEntry;
struct CopyTextureForBrowserOptions;
struct CreateComputePipelineAsyncCallbackInfo;
struct CreateRenderPipelineAsyncCallbackInfo;
struct DawnWGSLBlocklist;
struct DawnAdapterPropertiesPowerPreference;
struct DawnBufferDescriptorErrorInfoFromWireClient;
struct DawnCacheDeviceDescriptor;
struct DawnComputePipelineFullSubgroups;
struct DawnEncoderInternalUsageDescriptor;
struct DawnExperimentalSubgroupLimits;
struct DawnMultisampleStateRenderToSingleSampled;
struct DawnRenderPassColorAttachmentRenderToSingleSampled;
struct DawnShaderModuleSPIRVOptionsDescriptor;
struct DawnTextureInternalUsageDescriptor;
struct DawnTogglesDescriptor;
struct DawnWireWGSLControl;
struct DepthStencilStateDepthWriteDefinedDawn;
struct DeviceLostCallbackInfo;
struct DrmFormatProperties;
struct Extent2D;
struct Extent3D;
struct ExternalTextureBindingEntry;
struct ExternalTextureBindingLayout;
struct FormatCapabilities;
struct Future;
struct InstanceFeatures;
struct Limits;
struct MemoryHeapInfo;
struct MultisampleState;
struct Origin2D;
struct Origin3D;
struct PipelineLayoutDescriptor;
struct PipelineLayoutStorageAttachment;
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
struct ShaderModuleCompilationOptions;
struct ShaderModuleDescriptor;
struct SharedBufferMemoryBeginAccessDescriptor;
struct SharedBufferMemoryDescriptor;
struct SharedBufferMemoryEndAccessState;
struct SharedBufferMemoryProperties;
struct SharedFenceDXGISharedHandleDescriptor;
struct SharedFenceDXGISharedHandleExportInfo;
struct SharedFenceMTLSharedEventDescriptor;
struct SharedFenceMTLSharedEventExportInfo;
struct SharedFenceDescriptor;
struct SharedFenceExportInfo;
struct SharedFenceVkSemaphoreOpaqueFDDescriptor;
struct SharedFenceVkSemaphoreOpaqueFDExportInfo;
struct SharedFenceVkSemaphoreSyncFDDescriptor;
struct SharedFenceVkSemaphoreSyncFDExportInfo;
struct SharedFenceVkSemaphoreZirconHandleDescriptor;
struct SharedFenceVkSemaphoreZirconHandleExportInfo;
struct SharedTextureMemoryD3DSwapchainBeginState;
struct SharedTextureMemoryDXGISharedHandleDescriptor;
struct SharedTextureMemoryEGLImageDescriptor;
struct SharedTextureMemoryIOSurfaceDescriptor;
struct SharedTextureMemoryAHardwareBufferDescriptor;
struct SharedTextureMemoryBeginAccessDescriptor;
struct SharedTextureMemoryDescriptor;
struct SharedTextureMemoryDmaBufPlane;
struct SharedTextureMemoryEndAccessState;
struct SharedTextureMemoryOpaqueFDDescriptor;
struct SharedTextureMemoryVkDedicatedAllocationDescriptor;
struct SharedTextureMemoryVkImageLayoutBeginState;
struct SharedTextureMemoryVkImageLayoutEndState;
struct SharedTextureMemoryZirconHandleDescriptor;
struct StaticSamplerBindingLayout;
struct StencilFaceState;
struct StorageTextureBindingLayout;
struct SurfaceCapabilities;
struct SurfaceConfiguration;
struct SurfaceDescriptor;
struct SurfaceDescriptorFromAndroidNativeWindow;
struct SurfaceDescriptorFromCanvasHTMLSelector;
struct SurfaceDescriptorFromMetalLayer;
struct SurfaceDescriptorFromWaylandSurface;
struct SurfaceDescriptorFromWindowsHWND;
struct SurfaceDescriptorFromWindowsCoreWindow;
struct SurfaceDescriptorFromWindowsSwapChainPanel;
struct SurfaceDescriptorFromXlibWindow;
struct SurfaceTexture;
struct SwapChainDescriptor;
struct TextureBindingLayout;
struct TextureBindingViewDimensionDescriptor;
struct TextureDataLayout;
struct TextureViewDescriptor;
struct UncapturedErrorCallbackInfo;
struct VertexAttribute;
struct YCbCrVkDescriptor;
struct AHardwareBufferProperties;
struct AdapterPropertiesMemoryHeaps;
struct BindGroupDescriptor;
struct BindGroupLayoutEntry;
struct BlendState;
struct CompilationInfo;
struct ComputePassDescriptor;
struct DepthStencilState;
struct DrmFormatCapabilities;
struct ExternalTextureDescriptor;
struct FutureWaitInfo;
struct ImageCopyBuffer;
struct ImageCopyExternalTexture;
struct ImageCopyTexture;
struct InstanceDescriptor;
struct PipelineLayoutPixelLocalStorage;
struct ProgrammableStageDescriptor;
struct RenderPassColorAttachment;
struct RenderPassStorageAttachment;
struct RequiredLimits;
struct SharedTextureMemoryAHardwareBufferProperties;
struct SharedTextureMemoryDmaBufDescriptor;
struct SharedTextureMemoryProperties;
struct SupportedLimits;
struct TextureDescriptor;
struct VertexBufferLayout;
struct BindGroupLayoutDescriptor;
struct ColorTargetState;
struct ComputePipelineDescriptor;
struct DeviceDescriptor;
struct RenderPassDescriptor;
struct RenderPassPixelLocalStorage;
struct VertexState;
struct FragmentState;
struct RenderPipelineDescriptor;




class Adapter : public ObjectBase<Adapter, WGPUAdapter> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline Device CreateDevice(DeviceDescriptor const * descriptor = nullptr) const;
    inline size_t EnumerateFeatures(FeatureName * features) const;
    inline ConvertibleStatus GetFormatCapabilities(TextureFormat format, FormatCapabilities * capabilities) const;
    inline ConvertibleStatus GetInfo(AdapterInfo * info) const;
    inline Instance GetInstance() const;
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
    inline void InjectValidationError(char const * message) const;
    inline void InsertDebugMarker(char const * markerLabel) const;
    inline void PopDebugGroup() const;
    inline void PushDebugGroup(char const * groupLabel) const;
    inline void ResolveQuerySet(QuerySet const& querySet, uint32_t firstQuery, uint32_t queryCount, Buffer const& destination, uint64_t destinationOffset) const;
    inline void SetLabel(char const * label) const;
    inline void WriteBuffer(Buffer const& buffer, uint64_t bufferOffset, uint8_t const * data, uint64_t size) const;
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
    inline Buffer CreateErrorBuffer(BufferDescriptor const * descriptor) const;
    inline ExternalTexture CreateErrorExternalTexture() const;
    inline ShaderModule CreateErrorShaderModule(ShaderModuleDescriptor const * descriptor, char const * errorMessage) const;
    inline Texture CreateErrorTexture(TextureDescriptor const * descriptor) const;
    inline ExternalTexture CreateExternalTexture(ExternalTextureDescriptor const * externalTextureDescriptor) const;
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
    inline void ForceLoss(DeviceLostReason type, char const * message) const;
    inline ConvertibleStatus GetAHardwareBufferProperties(void * handle, AHardwareBufferProperties * properties) const;
    inline Adapter GetAdapter() const;
    inline ConvertibleStatus GetLimits(SupportedLimits * limits) const;
    inline Queue GetQueue() const;
    inline TextureUsage GetSupportedSurfaceUsage(Surface const& surface) const;
    inline Bool HasFeature(FeatureName feature) const;
    inline SharedBufferMemory ImportSharedBufferMemory(SharedBufferMemoryDescriptor const * descriptor) const;
    inline SharedFence ImportSharedFence(SharedFenceDescriptor const * descriptor) const;
    inline SharedTextureMemory ImportSharedTextureMemory(SharedTextureMemoryDescriptor const * descriptor) const;
    inline void InjectError(ErrorType type, char const * message) const;
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
    inline void SetDeviceLostCallback(DeviceLostCallback callback, void * userdata) const;
    inline void SetLabel(char const * label) const;
    inline void SetLoggingCallback(LoggingCallback callback, void * userdata) const;
    inline void SetUncapturedErrorCallback(ErrorCallback callback, void * userdata) const;
    inline void Tick() const;
    inline void ValidateTextureDescriptor(TextureDescriptor const * descriptor) const;

  private:
    friend ObjectBase<Device, WGPUDevice>;
    static inline void WGPUAddRef(WGPUDevice handle);
    static inline void WGPURelease(WGPUDevice handle);
};

class ExternalTexture : public ObjectBase<ExternalTexture, WGPUExternalTexture> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void Destroy() const;
    inline void Expire() const;
    inline void Refresh() const;
    inline void SetLabel(char const * label) const;

  private:
    friend ObjectBase<ExternalTexture, WGPUExternalTexture>;
    static inline void WGPUAddRef(WGPUExternalTexture handle);
    static inline void WGPURelease(WGPUExternalTexture handle);
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

    inline void CopyExternalTextureForBrowser(ImageCopyExternalTexture const * source, ImageCopyTexture const * destination, Extent3D const * copySize, CopyTextureForBrowserOptions const * options) const;
    inline void CopyTextureForBrowser(ImageCopyTexture const * source, ImageCopyTexture const * destination, Extent3D const * copySize, CopyTextureForBrowserOptions const * options) const;
    inline void OnSubmittedWorkDone(QueueWorkDoneCallback callback, void * userdata) const;
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
    inline void PixelLocalStorageBarrier() const;
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

class SharedBufferMemory : public ObjectBase<SharedBufferMemory, WGPUSharedBufferMemory> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline Bool BeginAccess(Buffer const& buffer, SharedBufferMemoryBeginAccessDescriptor const * descriptor) const;
    inline Buffer CreateBuffer(BufferDescriptor const * descriptor = nullptr) const;
    inline Bool EndAccess(Buffer const& buffer, SharedBufferMemoryEndAccessState * descriptor) const;
    inline ConvertibleStatus GetProperties(SharedBufferMemoryProperties * properties) const;
    inline Bool IsDeviceLost() const;
    inline void SetLabel(char const * label) const;

  private:
    friend ObjectBase<SharedBufferMemory, WGPUSharedBufferMemory>;
    static inline void WGPUAddRef(WGPUSharedBufferMemory handle);
    static inline void WGPURelease(WGPUSharedBufferMemory handle);
};

class SharedFence : public ObjectBase<SharedFence, WGPUSharedFence> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline void ExportInfo(SharedFenceExportInfo * info) const;

  private:
    friend ObjectBase<SharedFence, WGPUSharedFence>;
    static inline void WGPUAddRef(WGPUSharedFence handle);
    static inline void WGPURelease(WGPUSharedFence handle);
};

class SharedTextureMemory : public ObjectBase<SharedTextureMemory, WGPUSharedTextureMemory> {
  public:
    using ObjectBase::ObjectBase;
    using ObjectBase::operator=;

    inline Bool BeginAccess(Texture const& texture, SharedTextureMemoryBeginAccessDescriptor const * descriptor) const;
    inline Texture CreateTexture(TextureDescriptor const * descriptor = nullptr) const;
    inline Bool EndAccess(Texture const& texture, SharedTextureMemoryEndAccessState * descriptor) const;
    inline ConvertibleStatus GetProperties(SharedTextureMemoryProperties * properties) const;
    inline Bool IsDeviceLost() const;
    inline void SetLabel(char const * label) const;

  private:
    friend ObjectBase<SharedTextureMemory, WGPUSharedTextureMemory>;
    static inline void WGPUAddRef(WGPUSharedTextureMemory handle);
    static inline void WGPURelease(WGPUSharedTextureMemory handle);
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

    inline Texture GetCurrentTexture() const;
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

    inline TextureView CreateErrorView(TextureViewDescriptor const * descriptor = nullptr) const;
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

// Can be chained in AdapterProperties
struct AdapterPropertiesD3D : ChainedStructOut {
    inline AdapterPropertiesD3D();

    struct Init;
    inline AdapterPropertiesD3D(Init&& init);
    inline operator const WGPUAdapterPropertiesD3D&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(uint32_t ));
    alignas(kFirstMemberAlignment) uint32_t shaderModel;
};

// Can be chained in AdapterProperties
struct AdapterPropertiesVk : ChainedStructOut {
    inline AdapterPropertiesVk();

    struct Init;
    inline AdapterPropertiesVk(Init&& init);
    inline operator const WGPUAdapterPropertiesVk&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(uint32_t ));
    alignas(kFirstMemberAlignment) uint32_t driverVersion;
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

// Can be chained in BufferDescriptor
struct BufferHostMappedPointer : ChainedStruct {
    inline BufferHostMappedPointer();

    struct Init;
    inline BufferHostMappedPointer(Init&& init);
    inline operator const WGPUBufferHostMappedPointer&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void * ));
    alignas(kFirstMemberAlignment) void * pointer;
    Callback disposeCallback;
    void * userdata;
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

// Can be chained in ColorTargetState
struct ColorTargetStateExpandResolveTextureDawn : ChainedStruct {
    inline ColorTargetStateExpandResolveTextureDawn();

    struct Init;
    inline ColorTargetStateExpandResolveTextureDawn(Init&& init);
    inline operator const WGPUColorTargetStateExpandResolveTextureDawn&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(Bool ));
    alignas(kFirstMemberAlignment) Bool enabled = false;
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

struct CopyTextureForBrowserOptions {
    inline operator const WGPUCopyTextureForBrowserOptions&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    Bool flipY = false;
    Bool needsColorSpaceConversion = false;
    AlphaMode srcAlphaMode = AlphaMode::Unpremultiplied;
    float const * srcTransferFunctionParameters = nullptr;
    float const * conversionMatrix = nullptr;
    float const * dstTransferFunctionParameters = nullptr;
    AlphaMode dstAlphaMode = AlphaMode::Unpremultiplied;
    Bool internalUsage = false;
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

// Can be chained in InstanceDescriptor
struct DawnWGSLBlocklist : ChainedStruct {
    inline DawnWGSLBlocklist();

    struct Init;
    inline DawnWGSLBlocklist(Init&& init);
    inline operator const WGPUDawnWGSLBlocklist&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(size_t ));
    alignas(kFirstMemberAlignment) size_t blocklistedFeatureCount = 0;
    const char* const * blocklistedFeatures;
};

// Can be chained in AdapterProperties
struct DawnAdapterPropertiesPowerPreference : ChainedStructOut {
    inline DawnAdapterPropertiesPowerPreference();

    struct Init;
    inline DawnAdapterPropertiesPowerPreference(Init&& init);
    inline operator const WGPUDawnAdapterPropertiesPowerPreference&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(PowerPreference ));
    alignas(kFirstMemberAlignment) PowerPreference powerPreference = PowerPreference::Undefined;
};

// Can be chained in BufferDescriptor
struct DawnBufferDescriptorErrorInfoFromWireClient : ChainedStruct {
    inline DawnBufferDescriptorErrorInfoFromWireClient();

    struct Init;
    inline DawnBufferDescriptorErrorInfoFromWireClient(Init&& init);
    inline operator const WGPUDawnBufferDescriptorErrorInfoFromWireClient&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(Bool ));
    alignas(kFirstMemberAlignment) Bool outOfMemory = false;
};

// Can be chained in DeviceDescriptor
struct DawnCacheDeviceDescriptor : ChainedStruct {
    inline DawnCacheDeviceDescriptor();

    struct Init;
    inline DawnCacheDeviceDescriptor(Init&& init);
    inline operator const WGPUDawnCacheDeviceDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(char const * ));
    alignas(kFirstMemberAlignment) char const * isolationKey = "";
    DawnLoadCacheDataFunction loadDataFunction = nullptr;
    DawnStoreCacheDataFunction storeDataFunction = nullptr;
    void * functionUserdata = nullptr;
};

// Can be chained in ComputePipelineDescriptor
struct DawnComputePipelineFullSubgroups : ChainedStruct {
    inline DawnComputePipelineFullSubgroups();

    struct Init;
    inline DawnComputePipelineFullSubgroups(Init&& init);
    inline operator const WGPUDawnComputePipelineFullSubgroups&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(Bool ));
    alignas(kFirstMemberAlignment) Bool requiresFullSubgroups = false;
};

// Can be chained in CommandEncoderDescriptor
struct DawnEncoderInternalUsageDescriptor : ChainedStruct {
    inline DawnEncoderInternalUsageDescriptor();

    struct Init;
    inline DawnEncoderInternalUsageDescriptor(Init&& init);
    inline operator const WGPUDawnEncoderInternalUsageDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(Bool ));
    alignas(kFirstMemberAlignment) Bool useInternalUsages = false;
};

// Can be chained in SupportedLimits
struct DawnExperimentalSubgroupLimits : ChainedStructOut {
    inline DawnExperimentalSubgroupLimits();

    struct Init;
    inline DawnExperimentalSubgroupLimits(Init&& init);
    inline operator const WGPUDawnExperimentalSubgroupLimits&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(uint32_t ));
    alignas(kFirstMemberAlignment) uint32_t minSubgroupSize = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxSubgroupSize = WGPU_LIMIT_U32_UNDEFINED;
};

// Can be chained in MultisampleState
struct DawnMultisampleStateRenderToSingleSampled : ChainedStruct {
    inline DawnMultisampleStateRenderToSingleSampled();

    struct Init;
    inline DawnMultisampleStateRenderToSingleSampled(Init&& init);
    inline operator const WGPUDawnMultisampleStateRenderToSingleSampled&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(Bool ));
    alignas(kFirstMemberAlignment) Bool enabled = false;
};

// Can be chained in RenderPassColorAttachment
struct DawnRenderPassColorAttachmentRenderToSingleSampled : ChainedStruct {
    inline DawnRenderPassColorAttachmentRenderToSingleSampled();

    struct Init;
    inline DawnRenderPassColorAttachmentRenderToSingleSampled(Init&& init);
    inline operator const WGPUDawnRenderPassColorAttachmentRenderToSingleSampled&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(uint32_t ));
    alignas(kFirstMemberAlignment) uint32_t implicitSampleCount = 1;
};

// Can be chained in ShaderModuleDescriptor
struct DawnShaderModuleSPIRVOptionsDescriptor : ChainedStruct {
    inline DawnShaderModuleSPIRVOptionsDescriptor();

    struct Init;
    inline DawnShaderModuleSPIRVOptionsDescriptor(Init&& init);
    inline operator const WGPUDawnShaderModuleSPIRVOptionsDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(Bool ));
    alignas(kFirstMemberAlignment) Bool allowNonUniformDerivatives = false;
};

// Can be chained in TextureDescriptor
struct DawnTextureInternalUsageDescriptor : ChainedStruct {
    inline DawnTextureInternalUsageDescriptor();

    struct Init;
    inline DawnTextureInternalUsageDescriptor(Init&& init);
    inline operator const WGPUDawnTextureInternalUsageDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(TextureUsage ));
    alignas(kFirstMemberAlignment) TextureUsage internalUsage = TextureUsage::None;
};

// Can be chained in InstanceDescriptor
// Can be chained in RequestAdapterOptions
// Can be chained in DeviceDescriptor
struct DawnTogglesDescriptor : ChainedStruct {
    inline DawnTogglesDescriptor();

    struct Init;
    inline DawnTogglesDescriptor(Init&& init);
    inline operator const WGPUDawnTogglesDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(size_t ));
    alignas(kFirstMemberAlignment) size_t enabledToggleCount = 0;
    const char* const * enabledToggles;
    size_t disabledToggleCount = 0;
    const char* const * disabledToggles;
};

// Can be chained in InstanceDescriptor
struct DawnWireWGSLControl : ChainedStruct {
    inline DawnWireWGSLControl();

    struct Init;
    inline DawnWireWGSLControl(Init&& init);
    inline operator const WGPUDawnWireWGSLControl&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(Bool ));
    alignas(kFirstMemberAlignment) Bool enableExperimental = false;
    Bool enableUnsafe = false;
    Bool enableTesting = false;
};

// Can be chained in DepthStencilState
struct DepthStencilStateDepthWriteDefinedDawn : ChainedStruct {
    inline DepthStencilStateDepthWriteDefinedDawn();

    struct Init;
    inline DepthStencilStateDepthWriteDefinedDawn(Init&& init);
    inline operator const WGPUDepthStencilStateDepthWriteDefinedDawn&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(Bool ));
    alignas(kFirstMemberAlignment) Bool depthWriteDefined;
};

struct DeviceLostCallbackInfo {
    inline operator const WGPUDeviceLostCallbackInfo&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    CallbackMode mode = CallbackMode::WaitAnyOnly;
    DeviceLostCallbackNew callback = nullptr;
    void * userdata = nullptr;
};

struct DrmFormatProperties {
    inline operator const WGPUDrmFormatProperties&() const noexcept;

    uint64_t modifier;
    uint32_t modifierPlaneCount;
};

struct Extent2D {
    inline operator const WGPUExtent2D&() const noexcept;

    uint32_t width;
    uint32_t height;
};

struct Extent3D {
    inline operator const WGPUExtent3D&() const noexcept;

    uint32_t width;
    uint32_t height = 1;
    uint32_t depthOrArrayLayers = 1;
};

// Can be chained in BindGroupEntry
struct ExternalTextureBindingEntry : ChainedStruct {
    inline ExternalTextureBindingEntry();

    struct Init;
    inline ExternalTextureBindingEntry(Init&& init);
    inline operator const WGPUExternalTextureBindingEntry&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(ExternalTexture ));
    alignas(kFirstMemberAlignment) ExternalTexture externalTexture;
};

// Can be chained in BindGroupLayoutEntry
struct ExternalTextureBindingLayout : ChainedStruct {
    inline ExternalTextureBindingLayout();

    struct Init;
    inline ExternalTextureBindingLayout(Init&& init);
    inline operator const WGPUExternalTextureBindingLayout&() const noexcept;

};

struct FormatCapabilities {
    inline operator const WGPUFormatCapabilities&() const noexcept;

    ChainedStructOut  * nextInChain = nullptr;
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

struct MemoryHeapInfo {
    inline operator const WGPUMemoryHeapInfo&() const noexcept;

    HeapProperty properties;
    uint64_t size;
};

struct MultisampleState {
    inline operator const WGPUMultisampleState&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    uint32_t count = 1;
    uint32_t mask = 0xFFFFFFFF;
    Bool alphaToCoverageEnabled = false;
};

struct Origin2D {
    inline operator const WGPUOrigin2D&() const noexcept;

    uint32_t x = 0;
    uint32_t y = 0;
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

struct PipelineLayoutStorageAttachment {
    inline operator const WGPUPipelineLayoutStorageAttachment&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    uint64_t offset = 0;
    TextureFormat format;
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

// Can be chained in ShaderModuleDescriptor
struct ShaderModuleCompilationOptions : ChainedStruct {
    inline ShaderModuleCompilationOptions();

    struct Init;
    inline ShaderModuleCompilationOptions(Init&& init);
    inline operator const WGPUShaderModuleCompilationOptions&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(Bool ));
    alignas(kFirstMemberAlignment) Bool strictMath;
};

struct ShaderModuleDescriptor {
    inline operator const WGPUShaderModuleDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
};

struct SharedBufferMemoryBeginAccessDescriptor {
    inline operator const WGPUSharedBufferMemoryBeginAccessDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    Bool initialized;
    size_t fenceCount = 0;
    SharedFence const * fences;
    uint64_t const * signaledValues;
};

struct SharedBufferMemoryDescriptor {
    inline operator const WGPUSharedBufferMemoryDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
};

struct SharedBufferMemoryEndAccessState {
    inline SharedBufferMemoryEndAccessState();
    inline ~SharedBufferMemoryEndAccessState();
    SharedBufferMemoryEndAccessState(const SharedBufferMemoryEndAccessState&) = delete;
    SharedBufferMemoryEndAccessState& operator=(const SharedBufferMemoryEndAccessState&) = delete;
    inline SharedBufferMemoryEndAccessState(SharedBufferMemoryEndAccessState&&);
    inline SharedBufferMemoryEndAccessState& operator=(SharedBufferMemoryEndAccessState&&);
    inline operator const WGPUSharedBufferMemoryEndAccessState&() const noexcept;

    ChainedStructOut  * nextInChain = nullptr;
    Bool const initialized = {};
    size_t const fenceCount = 0;
    SharedFence const * const fences = {};
    uint64_t const * const signaledValues = {};

  private:
    static inline void Reset(SharedBufferMemoryEndAccessState& value);
};

struct SharedBufferMemoryProperties {
    inline operator const WGPUSharedBufferMemoryProperties&() const noexcept;

    ChainedStructOut  * nextInChain = nullptr;
    BufferUsage usage;
    uint64_t size;
};

// Can be chained in SharedFenceDescriptor
struct SharedFenceDXGISharedHandleDescriptor : ChainedStruct {
    inline SharedFenceDXGISharedHandleDescriptor();

    struct Init;
    inline SharedFenceDXGISharedHandleDescriptor(Init&& init);
    inline operator const WGPUSharedFenceDXGISharedHandleDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void * ));
    alignas(kFirstMemberAlignment) void * handle;
};

// Can be chained in SharedFenceExportInfo
struct SharedFenceDXGISharedHandleExportInfo : ChainedStructOut {
    inline SharedFenceDXGISharedHandleExportInfo();

    struct Init;
    inline SharedFenceDXGISharedHandleExportInfo(Init&& init);
    inline operator const WGPUSharedFenceDXGISharedHandleExportInfo&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void * ));
    alignas(kFirstMemberAlignment) void * handle;
};

// Can be chained in SharedFenceDescriptor
struct SharedFenceMTLSharedEventDescriptor : ChainedStruct {
    inline SharedFenceMTLSharedEventDescriptor();

    struct Init;
    inline SharedFenceMTLSharedEventDescriptor(Init&& init);
    inline operator const WGPUSharedFenceMTLSharedEventDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void * ));
    alignas(kFirstMemberAlignment) void * sharedEvent;
};

// Can be chained in SharedFenceExportInfo
struct SharedFenceMTLSharedEventExportInfo : ChainedStructOut {
    inline SharedFenceMTLSharedEventExportInfo();

    struct Init;
    inline SharedFenceMTLSharedEventExportInfo(Init&& init);
    inline operator const WGPUSharedFenceMTLSharedEventExportInfo&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void * ));
    alignas(kFirstMemberAlignment) void * sharedEvent;
};

struct SharedFenceDescriptor {
    inline operator const WGPUSharedFenceDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
};

struct SharedFenceExportInfo {
    inline operator const WGPUSharedFenceExportInfo&() const noexcept;

    ChainedStructOut  * nextInChain = nullptr;
    SharedFenceType type;
};

// Can be chained in SharedFenceDescriptor
struct SharedFenceVkSemaphoreOpaqueFDDescriptor : ChainedStruct {
    inline SharedFenceVkSemaphoreOpaqueFDDescriptor();

    struct Init;
    inline SharedFenceVkSemaphoreOpaqueFDDescriptor(Init&& init);
    inline operator const WGPUSharedFenceVkSemaphoreOpaqueFDDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(int ));
    alignas(kFirstMemberAlignment) int handle;
};

// Can be chained in SharedFenceExportInfo
struct SharedFenceVkSemaphoreOpaqueFDExportInfo : ChainedStructOut {
    inline SharedFenceVkSemaphoreOpaqueFDExportInfo();

    struct Init;
    inline SharedFenceVkSemaphoreOpaqueFDExportInfo(Init&& init);
    inline operator const WGPUSharedFenceVkSemaphoreOpaqueFDExportInfo&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(int ));
    alignas(kFirstMemberAlignment) int handle;
};

// Can be chained in SharedFenceDescriptor
struct SharedFenceVkSemaphoreSyncFDDescriptor : ChainedStruct {
    inline SharedFenceVkSemaphoreSyncFDDescriptor();

    struct Init;
    inline SharedFenceVkSemaphoreSyncFDDescriptor(Init&& init);
    inline operator const WGPUSharedFenceVkSemaphoreSyncFDDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(int ));
    alignas(kFirstMemberAlignment) int handle;
};

// Can be chained in SharedFenceExportInfo
struct SharedFenceVkSemaphoreSyncFDExportInfo : ChainedStructOut {
    inline SharedFenceVkSemaphoreSyncFDExportInfo();

    struct Init;
    inline SharedFenceVkSemaphoreSyncFDExportInfo(Init&& init);
    inline operator const WGPUSharedFenceVkSemaphoreSyncFDExportInfo&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(int ));
    alignas(kFirstMemberAlignment) int handle;
};

// Can be chained in SharedFenceDescriptor
struct SharedFenceVkSemaphoreZirconHandleDescriptor : ChainedStruct {
    inline SharedFenceVkSemaphoreZirconHandleDescriptor();

    struct Init;
    inline SharedFenceVkSemaphoreZirconHandleDescriptor(Init&& init);
    inline operator const WGPUSharedFenceVkSemaphoreZirconHandleDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(uint32_t ));
    alignas(kFirstMemberAlignment) uint32_t handle;
};

// Can be chained in SharedFenceExportInfo
struct SharedFenceVkSemaphoreZirconHandleExportInfo : ChainedStructOut {
    inline SharedFenceVkSemaphoreZirconHandleExportInfo();

    struct Init;
    inline SharedFenceVkSemaphoreZirconHandleExportInfo(Init&& init);
    inline operator const WGPUSharedFenceVkSemaphoreZirconHandleExportInfo&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(uint32_t ));
    alignas(kFirstMemberAlignment) uint32_t handle;
};

// Can be chained in SharedTextureMemoryBeginAccessDescriptor
struct SharedTextureMemoryD3DSwapchainBeginState : ChainedStruct {
    inline SharedTextureMemoryD3DSwapchainBeginState();

    struct Init;
    inline SharedTextureMemoryD3DSwapchainBeginState(Init&& init);
    inline operator const WGPUSharedTextureMemoryD3DSwapchainBeginState&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(Bool ));
    alignas(kFirstMemberAlignment) Bool isSwapchain = false;
};

// Can be chained in SharedTextureMemoryDescriptor
struct SharedTextureMemoryDXGISharedHandleDescriptor : ChainedStruct {
    inline SharedTextureMemoryDXGISharedHandleDescriptor();

    struct Init;
    inline SharedTextureMemoryDXGISharedHandleDescriptor(Init&& init);
    inline operator const WGPUSharedTextureMemoryDXGISharedHandleDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void * ));
    alignas(kFirstMemberAlignment) void * handle;
    Bool useKeyedMutex;
};

// Can be chained in SharedTextureMemoryDescriptor
struct SharedTextureMemoryEGLImageDescriptor : ChainedStruct {
    inline SharedTextureMemoryEGLImageDescriptor();

    struct Init;
    inline SharedTextureMemoryEGLImageDescriptor(Init&& init);
    inline operator const WGPUSharedTextureMemoryEGLImageDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void * ));
    alignas(kFirstMemberAlignment) void * image;
};

// Can be chained in SharedTextureMemoryDescriptor
struct SharedTextureMemoryIOSurfaceDescriptor : ChainedStruct {
    inline SharedTextureMemoryIOSurfaceDescriptor();

    struct Init;
    inline SharedTextureMemoryIOSurfaceDescriptor(Init&& init);
    inline operator const WGPUSharedTextureMemoryIOSurfaceDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void * ));
    alignas(kFirstMemberAlignment) void * ioSurface;
};

// Can be chained in SharedTextureMemoryDescriptor
struct SharedTextureMemoryAHardwareBufferDescriptor : ChainedStruct {
    inline SharedTextureMemoryAHardwareBufferDescriptor();

    struct Init;
    inline SharedTextureMemoryAHardwareBufferDescriptor(Init&& init);
    inline operator const WGPUSharedTextureMemoryAHardwareBufferDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void * ));
    alignas(kFirstMemberAlignment) void * handle;
};

struct SharedTextureMemoryBeginAccessDescriptor {
    inline operator const WGPUSharedTextureMemoryBeginAccessDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    Bool concurrentRead;
    Bool initialized;
    size_t fenceCount;
    SharedFence const * fences;
    uint64_t const * signaledValues;
};

struct SharedTextureMemoryDescriptor {
    inline operator const WGPUSharedTextureMemoryDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
};

struct SharedTextureMemoryDmaBufPlane {
    inline operator const WGPUSharedTextureMemoryDmaBufPlane&() const noexcept;

    int fd;
    uint64_t offset;
    uint32_t stride;
};

struct SharedTextureMemoryEndAccessState {
    inline SharedTextureMemoryEndAccessState();
    inline ~SharedTextureMemoryEndAccessState();
    SharedTextureMemoryEndAccessState(const SharedTextureMemoryEndAccessState&) = delete;
    SharedTextureMemoryEndAccessState& operator=(const SharedTextureMemoryEndAccessState&) = delete;
    inline SharedTextureMemoryEndAccessState(SharedTextureMemoryEndAccessState&&);
    inline SharedTextureMemoryEndAccessState& operator=(SharedTextureMemoryEndAccessState&&);
    inline operator const WGPUSharedTextureMemoryEndAccessState&() const noexcept;

    ChainedStructOut  * nextInChain = nullptr;
    Bool const initialized = {};
    size_t const fenceCount = {};
    SharedFence const * const fences = {};
    uint64_t const * const signaledValues = {};

  private:
    static inline void Reset(SharedTextureMemoryEndAccessState& value);
};

// Can be chained in SharedTextureMemoryDescriptor
struct SharedTextureMemoryOpaqueFDDescriptor : ChainedStruct {
    inline SharedTextureMemoryOpaqueFDDescriptor();

    struct Init;
    inline SharedTextureMemoryOpaqueFDDescriptor(Init&& init);
    inline operator const WGPUSharedTextureMemoryOpaqueFDDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void const * ));
    alignas(kFirstMemberAlignment) void const * vkImageCreateInfo;
    int memoryFD;
    uint32_t memoryTypeIndex;
    uint64_t allocationSize;
    Bool dedicatedAllocation;
};

// Can be chained in SharedTextureMemoryDescriptor
struct SharedTextureMemoryVkDedicatedAllocationDescriptor : ChainedStruct {
    inline SharedTextureMemoryVkDedicatedAllocationDescriptor();

    struct Init;
    inline SharedTextureMemoryVkDedicatedAllocationDescriptor(Init&& init);
    inline operator const WGPUSharedTextureMemoryVkDedicatedAllocationDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(Bool ));
    alignas(kFirstMemberAlignment) Bool dedicatedAllocation;
};

// Can be chained in SharedTextureMemoryBeginAccessDescriptor
struct SharedTextureMemoryVkImageLayoutBeginState : ChainedStruct {
    inline SharedTextureMemoryVkImageLayoutBeginState();

    struct Init;
    inline SharedTextureMemoryVkImageLayoutBeginState(Init&& init);
    inline operator const WGPUSharedTextureMemoryVkImageLayoutBeginState&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(int32_t ));
    alignas(kFirstMemberAlignment) int32_t oldLayout;
    int32_t newLayout;
};

// Can be chained in SharedTextureMemoryEndAccessState
struct SharedTextureMemoryVkImageLayoutEndState : ChainedStructOut {
    inline SharedTextureMemoryVkImageLayoutEndState();

    struct Init;
    inline SharedTextureMemoryVkImageLayoutEndState(Init&& init);
    inline operator const WGPUSharedTextureMemoryVkImageLayoutEndState&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(int32_t ));
    alignas(kFirstMemberAlignment) int32_t oldLayout;
    int32_t newLayout;
};

// Can be chained in SharedTextureMemoryDescriptor
struct SharedTextureMemoryZirconHandleDescriptor : ChainedStruct {
    inline SharedTextureMemoryZirconHandleDescriptor();

    struct Init;
    inline SharedTextureMemoryZirconHandleDescriptor(Init&& init);
    inline operator const WGPUSharedTextureMemoryZirconHandleDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(uint32_t ));
    alignas(kFirstMemberAlignment) uint32_t memoryFD;
    uint64_t allocationSize;
};

// Can be chained in BindGroupLayoutEntry
struct StaticSamplerBindingLayout : ChainedStruct {
    inline StaticSamplerBindingLayout();

    struct Init;
    inline StaticSamplerBindingLayout(Init&& init);
    inline operator const WGPUStaticSamplerBindingLayout&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(Sampler ));
    alignas(kFirstMemberAlignment) Sampler sampler;
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
struct SurfaceDescriptorFromAndroidNativeWindow : ChainedStruct {
    inline SurfaceDescriptorFromAndroidNativeWindow();

    struct Init;
    inline SurfaceDescriptorFromAndroidNativeWindow(Init&& init);
    inline operator const WGPUSurfaceDescriptorFromAndroidNativeWindow&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void * ));
    alignas(kFirstMemberAlignment) void * window;
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

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromMetalLayer : ChainedStruct {
    inline SurfaceDescriptorFromMetalLayer();

    struct Init;
    inline SurfaceDescriptorFromMetalLayer(Init&& init);
    inline operator const WGPUSurfaceDescriptorFromMetalLayer&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void * ));
    alignas(kFirstMemberAlignment) void * layer;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromWaylandSurface : ChainedStruct {
    inline SurfaceDescriptorFromWaylandSurface();

    struct Init;
    inline SurfaceDescriptorFromWaylandSurface(Init&& init);
    inline operator const WGPUSurfaceDescriptorFromWaylandSurface&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void * ));
    alignas(kFirstMemberAlignment) void * display;
    void * surface;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromWindowsHWND : ChainedStruct {
    inline SurfaceDescriptorFromWindowsHWND();

    struct Init;
    inline SurfaceDescriptorFromWindowsHWND(Init&& init);
    inline operator const WGPUSurfaceDescriptorFromWindowsHWND&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void * ));
    alignas(kFirstMemberAlignment) void * hinstance;
    void * hwnd;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromWindowsCoreWindow : ChainedStruct {
    inline SurfaceDescriptorFromWindowsCoreWindow();

    struct Init;
    inline SurfaceDescriptorFromWindowsCoreWindow(Init&& init);
    inline operator const WGPUSurfaceDescriptorFromWindowsCoreWindow&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void * ));
    alignas(kFirstMemberAlignment) void * coreWindow;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromWindowsSwapChainPanel : ChainedStruct {
    inline SurfaceDescriptorFromWindowsSwapChainPanel();

    struct Init;
    inline SurfaceDescriptorFromWindowsSwapChainPanel(Init&& init);
    inline operator const WGPUSurfaceDescriptorFromWindowsSwapChainPanel&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void * ));
    alignas(kFirstMemberAlignment) void * swapChainPanel;
};

// Can be chained in SurfaceDescriptor
struct SurfaceDescriptorFromXlibWindow : ChainedStruct {
    inline SurfaceDescriptorFromXlibWindow();

    struct Init;
    inline SurfaceDescriptorFromXlibWindow(Init&& init);
    inline operator const WGPUSurfaceDescriptorFromXlibWindow&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(void * ));
    alignas(kFirstMemberAlignment) void * display;
    uint64_t window;
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

// Can be chained in SamplerDescriptor
// Can be chained in TextureViewDescriptor
struct YCbCrVkDescriptor : ChainedStruct {
    inline YCbCrVkDescriptor();

    struct Init;
    inline YCbCrVkDescriptor(Init&& init);
    inline operator const WGPUYCbCrVkDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(uint32_t ));
    alignas(kFirstMemberAlignment) uint32_t vkFormat = 0;
    uint32_t vkYCbCrModel = 0;
    uint32_t vkYCbCrRange = 0;
    uint32_t vkComponentSwizzleRed = 0;
    uint32_t vkComponentSwizzleGreen = 0;
    uint32_t vkComponentSwizzleBlue = 0;
    uint32_t vkComponentSwizzleAlpha = 0;
    uint32_t vkXChromaOffset = 0;
    uint32_t vkYChromaOffset = 0;
    FilterMode vkChromaFilter = FilterMode::Nearest;
    Bool forceExplicitReconstruction = false;
    uint64_t externalFormat = 0;
};

struct AHardwareBufferProperties {
    inline operator const WGPUAHardwareBufferProperties&() const noexcept;

    YCbCrVkDescriptor yCbCrInfo;
};

// Can be chained in AdapterProperties
struct AdapterPropertiesMemoryHeaps : ChainedStructOut {
    inline AdapterPropertiesMemoryHeaps();

    struct Init;
    inline AdapterPropertiesMemoryHeaps(Init&& init);
    inline ~AdapterPropertiesMemoryHeaps();
    AdapterPropertiesMemoryHeaps(const AdapterPropertiesMemoryHeaps&) = delete;
    AdapterPropertiesMemoryHeaps& operator=(const AdapterPropertiesMemoryHeaps&) = delete;
    inline AdapterPropertiesMemoryHeaps(AdapterPropertiesMemoryHeaps&&);
    inline AdapterPropertiesMemoryHeaps& operator=(AdapterPropertiesMemoryHeaps&&);
    inline operator const WGPUAdapterPropertiesMemoryHeaps&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(size_t ));
    alignas(kFirstMemberAlignment) size_t const heapCount = {};
    MemoryHeapInfo const * const heapInfo = {};

  private:
    static inline void Reset(AdapterPropertiesMemoryHeaps& value);
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

// Can be chained in FormatCapabilities
struct DrmFormatCapabilities : ChainedStructOut {
    inline DrmFormatCapabilities();

    struct Init;
    inline DrmFormatCapabilities(Init&& init);
    inline ~DrmFormatCapabilities();
    DrmFormatCapabilities(const DrmFormatCapabilities&) = delete;
    DrmFormatCapabilities& operator=(const DrmFormatCapabilities&) = delete;
    inline DrmFormatCapabilities(DrmFormatCapabilities&&);
    inline DrmFormatCapabilities& operator=(DrmFormatCapabilities&&);
    inline operator const WGPUDrmFormatCapabilities&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(size_t ));
    alignas(kFirstMemberAlignment) size_t const propertiesCount = {};
    DrmFormatProperties const * const properties = {};

  private:
    static inline void Reset(DrmFormatCapabilities& value);
};

struct ExternalTextureDescriptor {
    inline operator const WGPUExternalTextureDescriptor&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    char const * label = nullptr;
    TextureView plane0;
    TextureView plane1 = nullptr;
    Origin2D visibleOrigin;
    Extent2D visibleSize;
    Bool doYuvToRgbConversionOnly = false;
    float const * yuvToRgbConversionMatrix = nullptr;
    float const * srcTransferFunctionParameters;
    float const * dstTransferFunctionParameters;
    float const * gamutConversionMatrix;
    Bool mirrored = false;
    ExternalTextureRotation rotation = ExternalTextureRotation::Rotate0Degrees;
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

struct ImageCopyExternalTexture {
    inline operator const WGPUImageCopyExternalTexture&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    ExternalTexture externalTexture;
    Origin3D origin;
    Extent2D naturalSize;
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

// Can be chained in PipelineLayoutDescriptor
struct PipelineLayoutPixelLocalStorage : ChainedStruct {
    inline PipelineLayoutPixelLocalStorage();

    struct Init;
    inline PipelineLayoutPixelLocalStorage(Init&& init);
    inline operator const WGPUPipelineLayoutPixelLocalStorage&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(uint64_t ));
    alignas(kFirstMemberAlignment) uint64_t totalPixelLocalStorageSize;
    size_t storageAttachmentCount = 0;
    PipelineLayoutStorageAttachment const * storageAttachments;
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

struct RenderPassStorageAttachment {
    inline operator const WGPURenderPassStorageAttachment&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    uint64_t offset = 0;
    TextureView storage;
    LoadOp loadOp;
    StoreOp storeOp;
    Color clearValue;
};

struct RequiredLimits {
    inline operator const WGPURequiredLimits&() const noexcept;

    ChainedStruct const * nextInChain = nullptr;
    Limits limits;
};

// Can be chained in SharedTextureMemoryProperties
struct SharedTextureMemoryAHardwareBufferProperties : ChainedStructOut {
    inline SharedTextureMemoryAHardwareBufferProperties();

    struct Init;
    inline SharedTextureMemoryAHardwareBufferProperties(Init&& init);
    inline operator const WGPUSharedTextureMemoryAHardwareBufferProperties&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(YCbCrVkDescriptor ));
    alignas(kFirstMemberAlignment) YCbCrVkDescriptor yCbCrInfo;
};

// Can be chained in SharedTextureMemoryDescriptor
struct SharedTextureMemoryDmaBufDescriptor : ChainedStruct {
    inline SharedTextureMemoryDmaBufDescriptor();

    struct Init;
    inline SharedTextureMemoryDmaBufDescriptor(Init&& init);
    inline operator const WGPUSharedTextureMemoryDmaBufDescriptor&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(Extent3D ));
    alignas(kFirstMemberAlignment) Extent3D size;
    uint32_t drmFormat;
    uint64_t drmModifier;
    size_t planeCount;
    SharedTextureMemoryDmaBufPlane const * planes;
};

struct SharedTextureMemoryProperties {
    inline operator const WGPUSharedTextureMemoryProperties&() const noexcept;

    ChainedStructOut  * nextInChain = nullptr;
    TextureUsage usage;
    Extent3D size;
    TextureFormat format;
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
    DeviceLostCallback deviceLostCallback = nullptr;
    void * deviceLostUserdata = nullptr;
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

// Can be chained in RenderPassDescriptor
struct RenderPassPixelLocalStorage : ChainedStruct {
    inline RenderPassPixelLocalStorage();

    struct Init;
    inline RenderPassPixelLocalStorage(Init&& init);
    inline operator const WGPURenderPassPixelLocalStorage&() const noexcept;

    static constexpr size_t kFirstMemberAlignment = detail::ConstexprMax(alignof(ChainedStruct), alignof(uint64_t ));
    alignas(kFirstMemberAlignment) uint64_t totalPixelLocalStorageSize;
    size_t storageAttachmentCount = 0;
    RenderPassStorageAttachment const * storageAttachments;
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
        wgpuDawnWireClientAdapterInfoFreeMembers(
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
        wgpuDawnWireClientAdapterPropertiesFreeMembers(
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

// AdapterPropertiesD3D implementation
AdapterPropertiesD3D::AdapterPropertiesD3D()
  : ChainedStructOut { nullptr, SType::AdapterPropertiesD3D } {}
struct AdapterPropertiesD3D::Init {
    ChainedStructOut *  nextInChain;
    uint32_t shaderModel;
};
AdapterPropertiesD3D::AdapterPropertiesD3D(AdapterPropertiesD3D::Init&& init)
  : ChainedStructOut { init.nextInChain, SType::AdapterPropertiesD3D }, 
    shaderModel(std::move(init.shaderModel)){}

AdapterPropertiesD3D::operator const WGPUAdapterPropertiesD3D&() const noexcept {
    return *reinterpret_cast<const WGPUAdapterPropertiesD3D*>(this);
}

static_assert(sizeof(AdapterPropertiesD3D) == sizeof(WGPUAdapterPropertiesD3D), "sizeof mismatch for AdapterPropertiesD3D");
static_assert(alignof(AdapterPropertiesD3D) == alignof(WGPUAdapterPropertiesD3D), "alignof mismatch for AdapterPropertiesD3D");
static_assert(offsetof(AdapterPropertiesD3D, shaderModel) == offsetof(WGPUAdapterPropertiesD3D, shaderModel),
        "offsetof mismatch for AdapterPropertiesD3D::shaderModel");

// AdapterPropertiesVk implementation
AdapterPropertiesVk::AdapterPropertiesVk()
  : ChainedStructOut { nullptr, SType::AdapterPropertiesVk } {}
struct AdapterPropertiesVk::Init {
    ChainedStructOut *  nextInChain;
    uint32_t driverVersion;
};
AdapterPropertiesVk::AdapterPropertiesVk(AdapterPropertiesVk::Init&& init)
  : ChainedStructOut { init.nextInChain, SType::AdapterPropertiesVk }, 
    driverVersion(std::move(init.driverVersion)){}

AdapterPropertiesVk::operator const WGPUAdapterPropertiesVk&() const noexcept {
    return *reinterpret_cast<const WGPUAdapterPropertiesVk*>(this);
}

static_assert(sizeof(AdapterPropertiesVk) == sizeof(WGPUAdapterPropertiesVk), "sizeof mismatch for AdapterPropertiesVk");
static_assert(alignof(AdapterPropertiesVk) == alignof(WGPUAdapterPropertiesVk), "alignof mismatch for AdapterPropertiesVk");
static_assert(offsetof(AdapterPropertiesVk, driverVersion) == offsetof(WGPUAdapterPropertiesVk, driverVersion),
        "offsetof mismatch for AdapterPropertiesVk::driverVersion");

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

// BufferHostMappedPointer implementation
BufferHostMappedPointer::BufferHostMappedPointer()
  : ChainedStruct { nullptr, SType::BufferHostMappedPointer } {}
struct BufferHostMappedPointer::Init {
    ChainedStruct * const nextInChain;
    void * pointer;
    Callback disposeCallback;
    void * userdata;
};
BufferHostMappedPointer::BufferHostMappedPointer(BufferHostMappedPointer::Init&& init)
  : ChainedStruct { init.nextInChain, SType::BufferHostMappedPointer }, 
    pointer(std::move(init.pointer)), 
    disposeCallback(std::move(init.disposeCallback)), 
    userdata(std::move(init.userdata)){}

BufferHostMappedPointer::operator const WGPUBufferHostMappedPointer&() const noexcept {
    return *reinterpret_cast<const WGPUBufferHostMappedPointer*>(this);
}

static_assert(sizeof(BufferHostMappedPointer) == sizeof(WGPUBufferHostMappedPointer), "sizeof mismatch for BufferHostMappedPointer");
static_assert(alignof(BufferHostMappedPointer) == alignof(WGPUBufferHostMappedPointer), "alignof mismatch for BufferHostMappedPointer");
static_assert(offsetof(BufferHostMappedPointer, pointer) == offsetof(WGPUBufferHostMappedPointer, pointer),
        "offsetof mismatch for BufferHostMappedPointer::pointer");
static_assert(offsetof(BufferHostMappedPointer, disposeCallback) == offsetof(WGPUBufferHostMappedPointer, disposeCallback),
        "offsetof mismatch for BufferHostMappedPointer::disposeCallback");
static_assert(offsetof(BufferHostMappedPointer, userdata) == offsetof(WGPUBufferHostMappedPointer, userdata),
        "offsetof mismatch for BufferHostMappedPointer::userdata");

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

// ColorTargetStateExpandResolveTextureDawn implementation
ColorTargetStateExpandResolveTextureDawn::ColorTargetStateExpandResolveTextureDawn()
  : ChainedStruct { nullptr, SType::ColorTargetStateExpandResolveTextureDawn } {}
struct ColorTargetStateExpandResolveTextureDawn::Init {
    ChainedStruct * const nextInChain;
    Bool enabled = false;
};
ColorTargetStateExpandResolveTextureDawn::ColorTargetStateExpandResolveTextureDawn(ColorTargetStateExpandResolveTextureDawn::Init&& init)
  : ChainedStruct { init.nextInChain, SType::ColorTargetStateExpandResolveTextureDawn }, 
    enabled(std::move(init.enabled)){}

ColorTargetStateExpandResolveTextureDawn::operator const WGPUColorTargetStateExpandResolveTextureDawn&() const noexcept {
    return *reinterpret_cast<const WGPUColorTargetStateExpandResolveTextureDawn*>(this);
}

static_assert(sizeof(ColorTargetStateExpandResolveTextureDawn) == sizeof(WGPUColorTargetStateExpandResolveTextureDawn), "sizeof mismatch for ColorTargetStateExpandResolveTextureDawn");
static_assert(alignof(ColorTargetStateExpandResolveTextureDawn) == alignof(WGPUColorTargetStateExpandResolveTextureDawn), "alignof mismatch for ColorTargetStateExpandResolveTextureDawn");
static_assert(offsetof(ColorTargetStateExpandResolveTextureDawn, enabled) == offsetof(WGPUColorTargetStateExpandResolveTextureDawn, enabled),
        "offsetof mismatch for ColorTargetStateExpandResolveTextureDawn::enabled");

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

// CopyTextureForBrowserOptions implementation

CopyTextureForBrowserOptions::operator const WGPUCopyTextureForBrowserOptions&() const noexcept {
    return *reinterpret_cast<const WGPUCopyTextureForBrowserOptions*>(this);
}

static_assert(sizeof(CopyTextureForBrowserOptions) == sizeof(WGPUCopyTextureForBrowserOptions), "sizeof mismatch for CopyTextureForBrowserOptions");
static_assert(alignof(CopyTextureForBrowserOptions) == alignof(WGPUCopyTextureForBrowserOptions), "alignof mismatch for CopyTextureForBrowserOptions");
static_assert(offsetof(CopyTextureForBrowserOptions, nextInChain) == offsetof(WGPUCopyTextureForBrowserOptions, nextInChain),
        "offsetof mismatch for CopyTextureForBrowserOptions::nextInChain");
static_assert(offsetof(CopyTextureForBrowserOptions, flipY) == offsetof(WGPUCopyTextureForBrowserOptions, flipY),
        "offsetof mismatch for CopyTextureForBrowserOptions::flipY");
static_assert(offsetof(CopyTextureForBrowserOptions, needsColorSpaceConversion) == offsetof(WGPUCopyTextureForBrowserOptions, needsColorSpaceConversion),
        "offsetof mismatch for CopyTextureForBrowserOptions::needsColorSpaceConversion");
static_assert(offsetof(CopyTextureForBrowserOptions, srcAlphaMode) == offsetof(WGPUCopyTextureForBrowserOptions, srcAlphaMode),
        "offsetof mismatch for CopyTextureForBrowserOptions::srcAlphaMode");
static_assert(offsetof(CopyTextureForBrowserOptions, srcTransferFunctionParameters) == offsetof(WGPUCopyTextureForBrowserOptions, srcTransferFunctionParameters),
        "offsetof mismatch for CopyTextureForBrowserOptions::srcTransferFunctionParameters");
static_assert(offsetof(CopyTextureForBrowserOptions, conversionMatrix) == offsetof(WGPUCopyTextureForBrowserOptions, conversionMatrix),
        "offsetof mismatch for CopyTextureForBrowserOptions::conversionMatrix");
static_assert(offsetof(CopyTextureForBrowserOptions, dstTransferFunctionParameters) == offsetof(WGPUCopyTextureForBrowserOptions, dstTransferFunctionParameters),
        "offsetof mismatch for CopyTextureForBrowserOptions::dstTransferFunctionParameters");
static_assert(offsetof(CopyTextureForBrowserOptions, dstAlphaMode) == offsetof(WGPUCopyTextureForBrowserOptions, dstAlphaMode),
        "offsetof mismatch for CopyTextureForBrowserOptions::dstAlphaMode");
static_assert(offsetof(CopyTextureForBrowserOptions, internalUsage) == offsetof(WGPUCopyTextureForBrowserOptions, internalUsage),
        "offsetof mismatch for CopyTextureForBrowserOptions::internalUsage");

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

// DawnWGSLBlocklist implementation
DawnWGSLBlocklist::DawnWGSLBlocklist()
  : ChainedStruct { nullptr, SType::DawnWGSLBlocklist } {}
struct DawnWGSLBlocklist::Init {
    ChainedStruct * const nextInChain;
    size_t blocklistedFeatureCount = 0;
    const char* const * blocklistedFeatures;
};
DawnWGSLBlocklist::DawnWGSLBlocklist(DawnWGSLBlocklist::Init&& init)
  : ChainedStruct { init.nextInChain, SType::DawnWGSLBlocklist }, 
    blocklistedFeatureCount(std::move(init.blocklistedFeatureCount)), 
    blocklistedFeatures(std::move(init.blocklistedFeatures)){}

DawnWGSLBlocklist::operator const WGPUDawnWGSLBlocklist&() const noexcept {
    return *reinterpret_cast<const WGPUDawnWGSLBlocklist*>(this);
}

static_assert(sizeof(DawnWGSLBlocklist) == sizeof(WGPUDawnWGSLBlocklist), "sizeof mismatch for DawnWGSLBlocklist");
static_assert(alignof(DawnWGSLBlocklist) == alignof(WGPUDawnWGSLBlocklist), "alignof mismatch for DawnWGSLBlocklist");
static_assert(offsetof(DawnWGSLBlocklist, blocklistedFeatureCount) == offsetof(WGPUDawnWGSLBlocklist, blocklistedFeatureCount),
        "offsetof mismatch for DawnWGSLBlocklist::blocklistedFeatureCount");
static_assert(offsetof(DawnWGSLBlocklist, blocklistedFeatures) == offsetof(WGPUDawnWGSLBlocklist, blocklistedFeatures),
        "offsetof mismatch for DawnWGSLBlocklist::blocklistedFeatures");

// DawnAdapterPropertiesPowerPreference implementation
DawnAdapterPropertiesPowerPreference::DawnAdapterPropertiesPowerPreference()
  : ChainedStructOut { nullptr, SType::DawnAdapterPropertiesPowerPreference } {}
struct DawnAdapterPropertiesPowerPreference::Init {
    ChainedStructOut *  nextInChain;
    PowerPreference powerPreference = PowerPreference::Undefined;
};
DawnAdapterPropertiesPowerPreference::DawnAdapterPropertiesPowerPreference(DawnAdapterPropertiesPowerPreference::Init&& init)
  : ChainedStructOut { init.nextInChain, SType::DawnAdapterPropertiesPowerPreference }, 
    powerPreference(std::move(init.powerPreference)){}

DawnAdapterPropertiesPowerPreference::operator const WGPUDawnAdapterPropertiesPowerPreference&() const noexcept {
    return *reinterpret_cast<const WGPUDawnAdapterPropertiesPowerPreference*>(this);
}

static_assert(sizeof(DawnAdapterPropertiesPowerPreference) == sizeof(WGPUDawnAdapterPropertiesPowerPreference), "sizeof mismatch for DawnAdapterPropertiesPowerPreference");
static_assert(alignof(DawnAdapterPropertiesPowerPreference) == alignof(WGPUDawnAdapterPropertiesPowerPreference), "alignof mismatch for DawnAdapterPropertiesPowerPreference");
static_assert(offsetof(DawnAdapterPropertiesPowerPreference, powerPreference) == offsetof(WGPUDawnAdapterPropertiesPowerPreference, powerPreference),
        "offsetof mismatch for DawnAdapterPropertiesPowerPreference::powerPreference");

// DawnBufferDescriptorErrorInfoFromWireClient implementation
DawnBufferDescriptorErrorInfoFromWireClient::DawnBufferDescriptorErrorInfoFromWireClient()
  : ChainedStruct { nullptr, SType::DawnBufferDescriptorErrorInfoFromWireClient } {}
struct DawnBufferDescriptorErrorInfoFromWireClient::Init {
    ChainedStruct * const nextInChain;
    Bool outOfMemory = false;
};
DawnBufferDescriptorErrorInfoFromWireClient::DawnBufferDescriptorErrorInfoFromWireClient(DawnBufferDescriptorErrorInfoFromWireClient::Init&& init)
  : ChainedStruct { init.nextInChain, SType::DawnBufferDescriptorErrorInfoFromWireClient }, 
    outOfMemory(std::move(init.outOfMemory)){}

DawnBufferDescriptorErrorInfoFromWireClient::operator const WGPUDawnBufferDescriptorErrorInfoFromWireClient&() const noexcept {
    return *reinterpret_cast<const WGPUDawnBufferDescriptorErrorInfoFromWireClient*>(this);
}

static_assert(sizeof(DawnBufferDescriptorErrorInfoFromWireClient) == sizeof(WGPUDawnBufferDescriptorErrorInfoFromWireClient), "sizeof mismatch for DawnBufferDescriptorErrorInfoFromWireClient");
static_assert(alignof(DawnBufferDescriptorErrorInfoFromWireClient) == alignof(WGPUDawnBufferDescriptorErrorInfoFromWireClient), "alignof mismatch for DawnBufferDescriptorErrorInfoFromWireClient");
static_assert(offsetof(DawnBufferDescriptorErrorInfoFromWireClient, outOfMemory) == offsetof(WGPUDawnBufferDescriptorErrorInfoFromWireClient, outOfMemory),
        "offsetof mismatch for DawnBufferDescriptorErrorInfoFromWireClient::outOfMemory");

// DawnCacheDeviceDescriptor implementation
DawnCacheDeviceDescriptor::DawnCacheDeviceDescriptor()
  : ChainedStruct { nullptr, SType::DawnCacheDeviceDescriptor } {}
struct DawnCacheDeviceDescriptor::Init {
    ChainedStruct * const nextInChain;
    char const * isolationKey = "";
    DawnLoadCacheDataFunction loadDataFunction = nullptr;
    DawnStoreCacheDataFunction storeDataFunction = nullptr;
    void * functionUserdata = nullptr;
};
DawnCacheDeviceDescriptor::DawnCacheDeviceDescriptor(DawnCacheDeviceDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::DawnCacheDeviceDescriptor }, 
    isolationKey(std::move(init.isolationKey)), 
    loadDataFunction(std::move(init.loadDataFunction)), 
    storeDataFunction(std::move(init.storeDataFunction)), 
    functionUserdata(std::move(init.functionUserdata)){}

DawnCacheDeviceDescriptor::operator const WGPUDawnCacheDeviceDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUDawnCacheDeviceDescriptor*>(this);
}

static_assert(sizeof(DawnCacheDeviceDescriptor) == sizeof(WGPUDawnCacheDeviceDescriptor), "sizeof mismatch for DawnCacheDeviceDescriptor");
static_assert(alignof(DawnCacheDeviceDescriptor) == alignof(WGPUDawnCacheDeviceDescriptor), "alignof mismatch for DawnCacheDeviceDescriptor");
static_assert(offsetof(DawnCacheDeviceDescriptor, isolationKey) == offsetof(WGPUDawnCacheDeviceDescriptor, isolationKey),
        "offsetof mismatch for DawnCacheDeviceDescriptor::isolationKey");
static_assert(offsetof(DawnCacheDeviceDescriptor, loadDataFunction) == offsetof(WGPUDawnCacheDeviceDescriptor, loadDataFunction),
        "offsetof mismatch for DawnCacheDeviceDescriptor::loadDataFunction");
static_assert(offsetof(DawnCacheDeviceDescriptor, storeDataFunction) == offsetof(WGPUDawnCacheDeviceDescriptor, storeDataFunction),
        "offsetof mismatch for DawnCacheDeviceDescriptor::storeDataFunction");
static_assert(offsetof(DawnCacheDeviceDescriptor, functionUserdata) == offsetof(WGPUDawnCacheDeviceDescriptor, functionUserdata),
        "offsetof mismatch for DawnCacheDeviceDescriptor::functionUserdata");

// DawnComputePipelineFullSubgroups implementation
DawnComputePipelineFullSubgroups::DawnComputePipelineFullSubgroups()
  : ChainedStruct { nullptr, SType::DawnComputePipelineFullSubgroups } {}
struct DawnComputePipelineFullSubgroups::Init {
    ChainedStruct * const nextInChain;
    Bool requiresFullSubgroups = false;
};
DawnComputePipelineFullSubgroups::DawnComputePipelineFullSubgroups(DawnComputePipelineFullSubgroups::Init&& init)
  : ChainedStruct { init.nextInChain, SType::DawnComputePipelineFullSubgroups }, 
    requiresFullSubgroups(std::move(init.requiresFullSubgroups)){}

DawnComputePipelineFullSubgroups::operator const WGPUDawnComputePipelineFullSubgroups&() const noexcept {
    return *reinterpret_cast<const WGPUDawnComputePipelineFullSubgroups*>(this);
}

static_assert(sizeof(DawnComputePipelineFullSubgroups) == sizeof(WGPUDawnComputePipelineFullSubgroups), "sizeof mismatch for DawnComputePipelineFullSubgroups");
static_assert(alignof(DawnComputePipelineFullSubgroups) == alignof(WGPUDawnComputePipelineFullSubgroups), "alignof mismatch for DawnComputePipelineFullSubgroups");
static_assert(offsetof(DawnComputePipelineFullSubgroups, requiresFullSubgroups) == offsetof(WGPUDawnComputePipelineFullSubgroups, requiresFullSubgroups),
        "offsetof mismatch for DawnComputePipelineFullSubgroups::requiresFullSubgroups");

// DawnEncoderInternalUsageDescriptor implementation
DawnEncoderInternalUsageDescriptor::DawnEncoderInternalUsageDescriptor()
  : ChainedStruct { nullptr, SType::DawnEncoderInternalUsageDescriptor } {}
struct DawnEncoderInternalUsageDescriptor::Init {
    ChainedStruct * const nextInChain;
    Bool useInternalUsages = false;
};
DawnEncoderInternalUsageDescriptor::DawnEncoderInternalUsageDescriptor(DawnEncoderInternalUsageDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::DawnEncoderInternalUsageDescriptor }, 
    useInternalUsages(std::move(init.useInternalUsages)){}

DawnEncoderInternalUsageDescriptor::operator const WGPUDawnEncoderInternalUsageDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUDawnEncoderInternalUsageDescriptor*>(this);
}

static_assert(sizeof(DawnEncoderInternalUsageDescriptor) == sizeof(WGPUDawnEncoderInternalUsageDescriptor), "sizeof mismatch for DawnEncoderInternalUsageDescriptor");
static_assert(alignof(DawnEncoderInternalUsageDescriptor) == alignof(WGPUDawnEncoderInternalUsageDescriptor), "alignof mismatch for DawnEncoderInternalUsageDescriptor");
static_assert(offsetof(DawnEncoderInternalUsageDescriptor, useInternalUsages) == offsetof(WGPUDawnEncoderInternalUsageDescriptor, useInternalUsages),
        "offsetof mismatch for DawnEncoderInternalUsageDescriptor::useInternalUsages");

// DawnExperimentalSubgroupLimits implementation
DawnExperimentalSubgroupLimits::DawnExperimentalSubgroupLimits()
  : ChainedStructOut { nullptr, SType::DawnExperimentalSubgroupLimits } {}
struct DawnExperimentalSubgroupLimits::Init {
    ChainedStructOut *  nextInChain;
    uint32_t minSubgroupSize = WGPU_LIMIT_U32_UNDEFINED;
    uint32_t maxSubgroupSize = WGPU_LIMIT_U32_UNDEFINED;
};
DawnExperimentalSubgroupLimits::DawnExperimentalSubgroupLimits(DawnExperimentalSubgroupLimits::Init&& init)
  : ChainedStructOut { init.nextInChain, SType::DawnExperimentalSubgroupLimits }, 
    minSubgroupSize(std::move(init.minSubgroupSize)), 
    maxSubgroupSize(std::move(init.maxSubgroupSize)){}

DawnExperimentalSubgroupLimits::operator const WGPUDawnExperimentalSubgroupLimits&() const noexcept {
    return *reinterpret_cast<const WGPUDawnExperimentalSubgroupLimits*>(this);
}

static_assert(sizeof(DawnExperimentalSubgroupLimits) == sizeof(WGPUDawnExperimentalSubgroupLimits), "sizeof mismatch for DawnExperimentalSubgroupLimits");
static_assert(alignof(DawnExperimentalSubgroupLimits) == alignof(WGPUDawnExperimentalSubgroupLimits), "alignof mismatch for DawnExperimentalSubgroupLimits");
static_assert(offsetof(DawnExperimentalSubgroupLimits, minSubgroupSize) == offsetof(WGPUDawnExperimentalSubgroupLimits, minSubgroupSize),
        "offsetof mismatch for DawnExperimentalSubgroupLimits::minSubgroupSize");
static_assert(offsetof(DawnExperimentalSubgroupLimits, maxSubgroupSize) == offsetof(WGPUDawnExperimentalSubgroupLimits, maxSubgroupSize),
        "offsetof mismatch for DawnExperimentalSubgroupLimits::maxSubgroupSize");

// DawnMultisampleStateRenderToSingleSampled implementation
DawnMultisampleStateRenderToSingleSampled::DawnMultisampleStateRenderToSingleSampled()
  : ChainedStruct { nullptr, SType::DawnMultisampleStateRenderToSingleSampled } {}
struct DawnMultisampleStateRenderToSingleSampled::Init {
    ChainedStruct * const nextInChain;
    Bool enabled = false;
};
DawnMultisampleStateRenderToSingleSampled::DawnMultisampleStateRenderToSingleSampled(DawnMultisampleStateRenderToSingleSampled::Init&& init)
  : ChainedStruct { init.nextInChain, SType::DawnMultisampleStateRenderToSingleSampled }, 
    enabled(std::move(init.enabled)){}

DawnMultisampleStateRenderToSingleSampled::operator const WGPUDawnMultisampleStateRenderToSingleSampled&() const noexcept {
    return *reinterpret_cast<const WGPUDawnMultisampleStateRenderToSingleSampled*>(this);
}

static_assert(sizeof(DawnMultisampleStateRenderToSingleSampled) == sizeof(WGPUDawnMultisampleStateRenderToSingleSampled), "sizeof mismatch for DawnMultisampleStateRenderToSingleSampled");
static_assert(alignof(DawnMultisampleStateRenderToSingleSampled) == alignof(WGPUDawnMultisampleStateRenderToSingleSampled), "alignof mismatch for DawnMultisampleStateRenderToSingleSampled");
static_assert(offsetof(DawnMultisampleStateRenderToSingleSampled, enabled) == offsetof(WGPUDawnMultisampleStateRenderToSingleSampled, enabled),
        "offsetof mismatch for DawnMultisampleStateRenderToSingleSampled::enabled");

// DawnRenderPassColorAttachmentRenderToSingleSampled implementation
DawnRenderPassColorAttachmentRenderToSingleSampled::DawnRenderPassColorAttachmentRenderToSingleSampled()
  : ChainedStruct { nullptr, SType::DawnRenderPassColorAttachmentRenderToSingleSampled } {}
struct DawnRenderPassColorAttachmentRenderToSingleSampled::Init {
    ChainedStruct * const nextInChain;
    uint32_t implicitSampleCount = 1;
};
DawnRenderPassColorAttachmentRenderToSingleSampled::DawnRenderPassColorAttachmentRenderToSingleSampled(DawnRenderPassColorAttachmentRenderToSingleSampled::Init&& init)
  : ChainedStruct { init.nextInChain, SType::DawnRenderPassColorAttachmentRenderToSingleSampled }, 
    implicitSampleCount(std::move(init.implicitSampleCount)){}

DawnRenderPassColorAttachmentRenderToSingleSampled::operator const WGPUDawnRenderPassColorAttachmentRenderToSingleSampled&() const noexcept {
    return *reinterpret_cast<const WGPUDawnRenderPassColorAttachmentRenderToSingleSampled*>(this);
}

static_assert(sizeof(DawnRenderPassColorAttachmentRenderToSingleSampled) == sizeof(WGPUDawnRenderPassColorAttachmentRenderToSingleSampled), "sizeof mismatch for DawnRenderPassColorAttachmentRenderToSingleSampled");
static_assert(alignof(DawnRenderPassColorAttachmentRenderToSingleSampled) == alignof(WGPUDawnRenderPassColorAttachmentRenderToSingleSampled), "alignof mismatch for DawnRenderPassColorAttachmentRenderToSingleSampled");
static_assert(offsetof(DawnRenderPassColorAttachmentRenderToSingleSampled, implicitSampleCount) == offsetof(WGPUDawnRenderPassColorAttachmentRenderToSingleSampled, implicitSampleCount),
        "offsetof mismatch for DawnRenderPassColorAttachmentRenderToSingleSampled::implicitSampleCount");

// DawnShaderModuleSPIRVOptionsDescriptor implementation
DawnShaderModuleSPIRVOptionsDescriptor::DawnShaderModuleSPIRVOptionsDescriptor()
  : ChainedStruct { nullptr, SType::DawnShaderModuleSPIRVOptionsDescriptor } {}
struct DawnShaderModuleSPIRVOptionsDescriptor::Init {
    ChainedStruct * const nextInChain;
    Bool allowNonUniformDerivatives = false;
};
DawnShaderModuleSPIRVOptionsDescriptor::DawnShaderModuleSPIRVOptionsDescriptor(DawnShaderModuleSPIRVOptionsDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::DawnShaderModuleSPIRVOptionsDescriptor }, 
    allowNonUniformDerivatives(std::move(init.allowNonUniformDerivatives)){}

DawnShaderModuleSPIRVOptionsDescriptor::operator const WGPUDawnShaderModuleSPIRVOptionsDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUDawnShaderModuleSPIRVOptionsDescriptor*>(this);
}

static_assert(sizeof(DawnShaderModuleSPIRVOptionsDescriptor) == sizeof(WGPUDawnShaderModuleSPIRVOptionsDescriptor), "sizeof mismatch for DawnShaderModuleSPIRVOptionsDescriptor");
static_assert(alignof(DawnShaderModuleSPIRVOptionsDescriptor) == alignof(WGPUDawnShaderModuleSPIRVOptionsDescriptor), "alignof mismatch for DawnShaderModuleSPIRVOptionsDescriptor");
static_assert(offsetof(DawnShaderModuleSPIRVOptionsDescriptor, allowNonUniformDerivatives) == offsetof(WGPUDawnShaderModuleSPIRVOptionsDescriptor, allowNonUniformDerivatives),
        "offsetof mismatch for DawnShaderModuleSPIRVOptionsDescriptor::allowNonUniformDerivatives");

// DawnTextureInternalUsageDescriptor implementation
DawnTextureInternalUsageDescriptor::DawnTextureInternalUsageDescriptor()
  : ChainedStruct { nullptr, SType::DawnTextureInternalUsageDescriptor } {}
struct DawnTextureInternalUsageDescriptor::Init {
    ChainedStruct * const nextInChain;
    TextureUsage internalUsage = TextureUsage::None;
};
DawnTextureInternalUsageDescriptor::DawnTextureInternalUsageDescriptor(DawnTextureInternalUsageDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::DawnTextureInternalUsageDescriptor }, 
    internalUsage(std::move(init.internalUsage)){}

DawnTextureInternalUsageDescriptor::operator const WGPUDawnTextureInternalUsageDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUDawnTextureInternalUsageDescriptor*>(this);
}

static_assert(sizeof(DawnTextureInternalUsageDescriptor) == sizeof(WGPUDawnTextureInternalUsageDescriptor), "sizeof mismatch for DawnTextureInternalUsageDescriptor");
static_assert(alignof(DawnTextureInternalUsageDescriptor) == alignof(WGPUDawnTextureInternalUsageDescriptor), "alignof mismatch for DawnTextureInternalUsageDescriptor");
static_assert(offsetof(DawnTextureInternalUsageDescriptor, internalUsage) == offsetof(WGPUDawnTextureInternalUsageDescriptor, internalUsage),
        "offsetof mismatch for DawnTextureInternalUsageDescriptor::internalUsage");

// DawnTogglesDescriptor implementation
DawnTogglesDescriptor::DawnTogglesDescriptor()
  : ChainedStruct { nullptr, SType::DawnTogglesDescriptor } {}
struct DawnTogglesDescriptor::Init {
    ChainedStruct * const nextInChain;
    size_t enabledToggleCount = 0;
    const char* const * enabledToggles;
    size_t disabledToggleCount = 0;
    const char* const * disabledToggles;
};
DawnTogglesDescriptor::DawnTogglesDescriptor(DawnTogglesDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::DawnTogglesDescriptor }, 
    enabledToggleCount(std::move(init.enabledToggleCount)), 
    enabledToggles(std::move(init.enabledToggles)), 
    disabledToggleCount(std::move(init.disabledToggleCount)), 
    disabledToggles(std::move(init.disabledToggles)){}

DawnTogglesDescriptor::operator const WGPUDawnTogglesDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUDawnTogglesDescriptor*>(this);
}

static_assert(sizeof(DawnTogglesDescriptor) == sizeof(WGPUDawnTogglesDescriptor), "sizeof mismatch for DawnTogglesDescriptor");
static_assert(alignof(DawnTogglesDescriptor) == alignof(WGPUDawnTogglesDescriptor), "alignof mismatch for DawnTogglesDescriptor");
static_assert(offsetof(DawnTogglesDescriptor, enabledToggleCount) == offsetof(WGPUDawnTogglesDescriptor, enabledToggleCount),
        "offsetof mismatch for DawnTogglesDescriptor::enabledToggleCount");
static_assert(offsetof(DawnTogglesDescriptor, enabledToggles) == offsetof(WGPUDawnTogglesDescriptor, enabledToggles),
        "offsetof mismatch for DawnTogglesDescriptor::enabledToggles");
static_assert(offsetof(DawnTogglesDescriptor, disabledToggleCount) == offsetof(WGPUDawnTogglesDescriptor, disabledToggleCount),
        "offsetof mismatch for DawnTogglesDescriptor::disabledToggleCount");
static_assert(offsetof(DawnTogglesDescriptor, disabledToggles) == offsetof(WGPUDawnTogglesDescriptor, disabledToggles),
        "offsetof mismatch for DawnTogglesDescriptor::disabledToggles");

// DawnWireWGSLControl implementation
DawnWireWGSLControl::DawnWireWGSLControl()
  : ChainedStruct { nullptr, SType::DawnWireWGSLControl } {}
struct DawnWireWGSLControl::Init {
    ChainedStruct * const nextInChain;
    Bool enableExperimental = false;
    Bool enableUnsafe = false;
    Bool enableTesting = false;
};
DawnWireWGSLControl::DawnWireWGSLControl(DawnWireWGSLControl::Init&& init)
  : ChainedStruct { init.nextInChain, SType::DawnWireWGSLControl }, 
    enableExperimental(std::move(init.enableExperimental)), 
    enableUnsafe(std::move(init.enableUnsafe)), 
    enableTesting(std::move(init.enableTesting)){}

DawnWireWGSLControl::operator const WGPUDawnWireWGSLControl&() const noexcept {
    return *reinterpret_cast<const WGPUDawnWireWGSLControl*>(this);
}

static_assert(sizeof(DawnWireWGSLControl) == sizeof(WGPUDawnWireWGSLControl), "sizeof mismatch for DawnWireWGSLControl");
static_assert(alignof(DawnWireWGSLControl) == alignof(WGPUDawnWireWGSLControl), "alignof mismatch for DawnWireWGSLControl");
static_assert(offsetof(DawnWireWGSLControl, enableExperimental) == offsetof(WGPUDawnWireWGSLControl, enableExperimental),
        "offsetof mismatch for DawnWireWGSLControl::enableExperimental");
static_assert(offsetof(DawnWireWGSLControl, enableUnsafe) == offsetof(WGPUDawnWireWGSLControl, enableUnsafe),
        "offsetof mismatch for DawnWireWGSLControl::enableUnsafe");
static_assert(offsetof(DawnWireWGSLControl, enableTesting) == offsetof(WGPUDawnWireWGSLControl, enableTesting),
        "offsetof mismatch for DawnWireWGSLControl::enableTesting");

// DepthStencilStateDepthWriteDefinedDawn implementation
DepthStencilStateDepthWriteDefinedDawn::DepthStencilStateDepthWriteDefinedDawn()
  : ChainedStruct { nullptr, SType::DepthStencilStateDepthWriteDefinedDawn } {}
struct DepthStencilStateDepthWriteDefinedDawn::Init {
    ChainedStruct * const nextInChain;
    Bool depthWriteDefined;
};
DepthStencilStateDepthWriteDefinedDawn::DepthStencilStateDepthWriteDefinedDawn(DepthStencilStateDepthWriteDefinedDawn::Init&& init)
  : ChainedStruct { init.nextInChain, SType::DepthStencilStateDepthWriteDefinedDawn }, 
    depthWriteDefined(std::move(init.depthWriteDefined)){}

DepthStencilStateDepthWriteDefinedDawn::operator const WGPUDepthStencilStateDepthWriteDefinedDawn&() const noexcept {
    return *reinterpret_cast<const WGPUDepthStencilStateDepthWriteDefinedDawn*>(this);
}

static_assert(sizeof(DepthStencilStateDepthWriteDefinedDawn) == sizeof(WGPUDepthStencilStateDepthWriteDefinedDawn), "sizeof mismatch for DepthStencilStateDepthWriteDefinedDawn");
static_assert(alignof(DepthStencilStateDepthWriteDefinedDawn) == alignof(WGPUDepthStencilStateDepthWriteDefinedDawn), "alignof mismatch for DepthStencilStateDepthWriteDefinedDawn");
static_assert(offsetof(DepthStencilStateDepthWriteDefinedDawn, depthWriteDefined) == offsetof(WGPUDepthStencilStateDepthWriteDefinedDawn, depthWriteDefined),
        "offsetof mismatch for DepthStencilStateDepthWriteDefinedDawn::depthWriteDefined");

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

// DrmFormatProperties implementation

DrmFormatProperties::operator const WGPUDrmFormatProperties&() const noexcept {
    return *reinterpret_cast<const WGPUDrmFormatProperties*>(this);
}

static_assert(sizeof(DrmFormatProperties) == sizeof(WGPUDrmFormatProperties), "sizeof mismatch for DrmFormatProperties");
static_assert(alignof(DrmFormatProperties) == alignof(WGPUDrmFormatProperties), "alignof mismatch for DrmFormatProperties");
static_assert(offsetof(DrmFormatProperties, modifier) == offsetof(WGPUDrmFormatProperties, modifier),
        "offsetof mismatch for DrmFormatProperties::modifier");
static_assert(offsetof(DrmFormatProperties, modifierPlaneCount) == offsetof(WGPUDrmFormatProperties, modifierPlaneCount),
        "offsetof mismatch for DrmFormatProperties::modifierPlaneCount");

// Extent2D implementation

Extent2D::operator const WGPUExtent2D&() const noexcept {
    return *reinterpret_cast<const WGPUExtent2D*>(this);
}

static_assert(sizeof(Extent2D) == sizeof(WGPUExtent2D), "sizeof mismatch for Extent2D");
static_assert(alignof(Extent2D) == alignof(WGPUExtent2D), "alignof mismatch for Extent2D");
static_assert(offsetof(Extent2D, width) == offsetof(WGPUExtent2D, width),
        "offsetof mismatch for Extent2D::width");
static_assert(offsetof(Extent2D, height) == offsetof(WGPUExtent2D, height),
        "offsetof mismatch for Extent2D::height");

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

// ExternalTextureBindingEntry implementation
ExternalTextureBindingEntry::ExternalTextureBindingEntry()
  : ChainedStruct { nullptr, SType::ExternalTextureBindingEntry } {}
struct ExternalTextureBindingEntry::Init {
    ChainedStruct * const nextInChain;
    ExternalTexture externalTexture;
};
ExternalTextureBindingEntry::ExternalTextureBindingEntry(ExternalTextureBindingEntry::Init&& init)
  : ChainedStruct { init.nextInChain, SType::ExternalTextureBindingEntry }, 
    externalTexture(std::move(init.externalTexture)){}

ExternalTextureBindingEntry::operator const WGPUExternalTextureBindingEntry&() const noexcept {
    return *reinterpret_cast<const WGPUExternalTextureBindingEntry*>(this);
}

static_assert(sizeof(ExternalTextureBindingEntry) == sizeof(WGPUExternalTextureBindingEntry), "sizeof mismatch for ExternalTextureBindingEntry");
static_assert(alignof(ExternalTextureBindingEntry) == alignof(WGPUExternalTextureBindingEntry), "alignof mismatch for ExternalTextureBindingEntry");
static_assert(offsetof(ExternalTextureBindingEntry, externalTexture) == offsetof(WGPUExternalTextureBindingEntry, externalTexture),
        "offsetof mismatch for ExternalTextureBindingEntry::externalTexture");

// ExternalTextureBindingLayout implementation
ExternalTextureBindingLayout::ExternalTextureBindingLayout()
  : ChainedStruct { nullptr, SType::ExternalTextureBindingLayout } {}
struct ExternalTextureBindingLayout::Init {
    ChainedStruct * const nextInChain;
};
ExternalTextureBindingLayout::ExternalTextureBindingLayout(ExternalTextureBindingLayout::Init&& init)
  : ChainedStruct { init.nextInChain, SType::ExternalTextureBindingLayout }{}

ExternalTextureBindingLayout::operator const WGPUExternalTextureBindingLayout&() const noexcept {
    return *reinterpret_cast<const WGPUExternalTextureBindingLayout*>(this);
}

static_assert(sizeof(ExternalTextureBindingLayout) == sizeof(WGPUExternalTextureBindingLayout), "sizeof mismatch for ExternalTextureBindingLayout");
static_assert(alignof(ExternalTextureBindingLayout) == alignof(WGPUExternalTextureBindingLayout), "alignof mismatch for ExternalTextureBindingLayout");

// FormatCapabilities implementation

FormatCapabilities::operator const WGPUFormatCapabilities&() const noexcept {
    return *reinterpret_cast<const WGPUFormatCapabilities*>(this);
}

static_assert(sizeof(FormatCapabilities) == sizeof(WGPUFormatCapabilities), "sizeof mismatch for FormatCapabilities");
static_assert(alignof(FormatCapabilities) == alignof(WGPUFormatCapabilities), "alignof mismatch for FormatCapabilities");
static_assert(offsetof(FormatCapabilities, nextInChain) == offsetof(WGPUFormatCapabilities, nextInChain),
        "offsetof mismatch for FormatCapabilities::nextInChain");

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

// MemoryHeapInfo implementation

MemoryHeapInfo::operator const WGPUMemoryHeapInfo&() const noexcept {
    return *reinterpret_cast<const WGPUMemoryHeapInfo*>(this);
}

static_assert(sizeof(MemoryHeapInfo) == sizeof(WGPUMemoryHeapInfo), "sizeof mismatch for MemoryHeapInfo");
static_assert(alignof(MemoryHeapInfo) == alignof(WGPUMemoryHeapInfo), "alignof mismatch for MemoryHeapInfo");
static_assert(offsetof(MemoryHeapInfo, properties) == offsetof(WGPUMemoryHeapInfo, properties),
        "offsetof mismatch for MemoryHeapInfo::properties");
static_assert(offsetof(MemoryHeapInfo, size) == offsetof(WGPUMemoryHeapInfo, size),
        "offsetof mismatch for MemoryHeapInfo::size");

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

// Origin2D implementation

Origin2D::operator const WGPUOrigin2D&() const noexcept {
    return *reinterpret_cast<const WGPUOrigin2D*>(this);
}

static_assert(sizeof(Origin2D) == sizeof(WGPUOrigin2D), "sizeof mismatch for Origin2D");
static_assert(alignof(Origin2D) == alignof(WGPUOrigin2D), "alignof mismatch for Origin2D");
static_assert(offsetof(Origin2D, x) == offsetof(WGPUOrigin2D, x),
        "offsetof mismatch for Origin2D::x");
static_assert(offsetof(Origin2D, y) == offsetof(WGPUOrigin2D, y),
        "offsetof mismatch for Origin2D::y");

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

// PipelineLayoutStorageAttachment implementation

PipelineLayoutStorageAttachment::operator const WGPUPipelineLayoutStorageAttachment&() const noexcept {
    return *reinterpret_cast<const WGPUPipelineLayoutStorageAttachment*>(this);
}

static_assert(sizeof(PipelineLayoutStorageAttachment) == sizeof(WGPUPipelineLayoutStorageAttachment), "sizeof mismatch for PipelineLayoutStorageAttachment");
static_assert(alignof(PipelineLayoutStorageAttachment) == alignof(WGPUPipelineLayoutStorageAttachment), "alignof mismatch for PipelineLayoutStorageAttachment");
static_assert(offsetof(PipelineLayoutStorageAttachment, nextInChain) == offsetof(WGPUPipelineLayoutStorageAttachment, nextInChain),
        "offsetof mismatch for PipelineLayoutStorageAttachment::nextInChain");
static_assert(offsetof(PipelineLayoutStorageAttachment, offset) == offsetof(WGPUPipelineLayoutStorageAttachment, offset),
        "offsetof mismatch for PipelineLayoutStorageAttachment::offset");
static_assert(offsetof(PipelineLayoutStorageAttachment, format) == offsetof(WGPUPipelineLayoutStorageAttachment, format),
        "offsetof mismatch for PipelineLayoutStorageAttachment::format");

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

// ShaderModuleCompilationOptions implementation
ShaderModuleCompilationOptions::ShaderModuleCompilationOptions()
  : ChainedStruct { nullptr, SType::ShaderModuleCompilationOptions } {}
struct ShaderModuleCompilationOptions::Init {
    ChainedStruct * const nextInChain;
    Bool strictMath;
};
ShaderModuleCompilationOptions::ShaderModuleCompilationOptions(ShaderModuleCompilationOptions::Init&& init)
  : ChainedStruct { init.nextInChain, SType::ShaderModuleCompilationOptions }, 
    strictMath(std::move(init.strictMath)){}

ShaderModuleCompilationOptions::operator const WGPUShaderModuleCompilationOptions&() const noexcept {
    return *reinterpret_cast<const WGPUShaderModuleCompilationOptions*>(this);
}

static_assert(sizeof(ShaderModuleCompilationOptions) == sizeof(WGPUShaderModuleCompilationOptions), "sizeof mismatch for ShaderModuleCompilationOptions");
static_assert(alignof(ShaderModuleCompilationOptions) == alignof(WGPUShaderModuleCompilationOptions), "alignof mismatch for ShaderModuleCompilationOptions");
static_assert(offsetof(ShaderModuleCompilationOptions, strictMath) == offsetof(WGPUShaderModuleCompilationOptions, strictMath),
        "offsetof mismatch for ShaderModuleCompilationOptions::strictMath");

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

// SharedBufferMemoryBeginAccessDescriptor implementation

SharedBufferMemoryBeginAccessDescriptor::operator const WGPUSharedBufferMemoryBeginAccessDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedBufferMemoryBeginAccessDescriptor*>(this);
}

static_assert(sizeof(SharedBufferMemoryBeginAccessDescriptor) == sizeof(WGPUSharedBufferMemoryBeginAccessDescriptor), "sizeof mismatch for SharedBufferMemoryBeginAccessDescriptor");
static_assert(alignof(SharedBufferMemoryBeginAccessDescriptor) == alignof(WGPUSharedBufferMemoryBeginAccessDescriptor), "alignof mismatch for SharedBufferMemoryBeginAccessDescriptor");
static_assert(offsetof(SharedBufferMemoryBeginAccessDescriptor, nextInChain) == offsetof(WGPUSharedBufferMemoryBeginAccessDescriptor, nextInChain),
        "offsetof mismatch for SharedBufferMemoryBeginAccessDescriptor::nextInChain");
static_assert(offsetof(SharedBufferMemoryBeginAccessDescriptor, initialized) == offsetof(WGPUSharedBufferMemoryBeginAccessDescriptor, initialized),
        "offsetof mismatch for SharedBufferMemoryBeginAccessDescriptor::initialized");
static_assert(offsetof(SharedBufferMemoryBeginAccessDescriptor, fenceCount) == offsetof(WGPUSharedBufferMemoryBeginAccessDescriptor, fenceCount),
        "offsetof mismatch for SharedBufferMemoryBeginAccessDescriptor::fenceCount");
static_assert(offsetof(SharedBufferMemoryBeginAccessDescriptor, fences) == offsetof(WGPUSharedBufferMemoryBeginAccessDescriptor, fences),
        "offsetof mismatch for SharedBufferMemoryBeginAccessDescriptor::fences");
static_assert(offsetof(SharedBufferMemoryBeginAccessDescriptor, signaledValues) == offsetof(WGPUSharedBufferMemoryBeginAccessDescriptor, signaledValues),
        "offsetof mismatch for SharedBufferMemoryBeginAccessDescriptor::signaledValues");

// SharedBufferMemoryDescriptor implementation

SharedBufferMemoryDescriptor::operator const WGPUSharedBufferMemoryDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedBufferMemoryDescriptor*>(this);
}

static_assert(sizeof(SharedBufferMemoryDescriptor) == sizeof(WGPUSharedBufferMemoryDescriptor), "sizeof mismatch for SharedBufferMemoryDescriptor");
static_assert(alignof(SharedBufferMemoryDescriptor) == alignof(WGPUSharedBufferMemoryDescriptor), "alignof mismatch for SharedBufferMemoryDescriptor");
static_assert(offsetof(SharedBufferMemoryDescriptor, nextInChain) == offsetof(WGPUSharedBufferMemoryDescriptor, nextInChain),
        "offsetof mismatch for SharedBufferMemoryDescriptor::nextInChain");
static_assert(offsetof(SharedBufferMemoryDescriptor, label) == offsetof(WGPUSharedBufferMemoryDescriptor, label),
        "offsetof mismatch for SharedBufferMemoryDescriptor::label");

// SharedBufferMemoryEndAccessState implementation
SharedBufferMemoryEndAccessState::SharedBufferMemoryEndAccessState() = default;
SharedBufferMemoryEndAccessState::~SharedBufferMemoryEndAccessState() {
    if (this->fences != nullptr || this->signaledValues != nullptr) {
        wgpuDawnWireClientSharedBufferMemoryEndAccessStateFreeMembers(
            *reinterpret_cast<WGPUSharedBufferMemoryEndAccessState*>(this));
    }
}

SharedBufferMemoryEndAccessState::SharedBufferMemoryEndAccessState(SharedBufferMemoryEndAccessState&& rhs)
    : initialized(rhs.initialized),
            fenceCount(rhs.fenceCount),
            fences(rhs.fences),
            signaledValues(rhs.signaledValues){
    Reset(rhs);
}

SharedBufferMemoryEndAccessState& SharedBufferMemoryEndAccessState::operator=(SharedBufferMemoryEndAccessState&& rhs) {
    if (&rhs == this) {
        return *this;
    }
    this->~SharedBufferMemoryEndAccessState();
    detail::AsNonConstReference(this->initialized) = std::move(rhs.initialized);
    detail::AsNonConstReference(this->fenceCount) = std::move(rhs.fenceCount);
    detail::AsNonConstReference(this->fences) = std::move(rhs.fences);
    detail::AsNonConstReference(this->signaledValues) = std::move(rhs.signaledValues);
    Reset(rhs);
    return *this;
}

    // static
void SharedBufferMemoryEndAccessState::Reset(SharedBufferMemoryEndAccessState& value) {
    SharedBufferMemoryEndAccessState defaultValue{};
    detail::AsNonConstReference(value.initialized) = defaultValue.initialized;
    detail::AsNonConstReference(value.fenceCount) = defaultValue.fenceCount;
    detail::AsNonConstReference(value.fences) = defaultValue.fences;
    detail::AsNonConstReference(value.signaledValues) = defaultValue.signaledValues;
}

SharedBufferMemoryEndAccessState::operator const WGPUSharedBufferMemoryEndAccessState&() const noexcept {
    return *reinterpret_cast<const WGPUSharedBufferMemoryEndAccessState*>(this);
}

static_assert(sizeof(SharedBufferMemoryEndAccessState) == sizeof(WGPUSharedBufferMemoryEndAccessState), "sizeof mismatch for SharedBufferMemoryEndAccessState");
static_assert(alignof(SharedBufferMemoryEndAccessState) == alignof(WGPUSharedBufferMemoryEndAccessState), "alignof mismatch for SharedBufferMemoryEndAccessState");
static_assert(offsetof(SharedBufferMemoryEndAccessState, nextInChain) == offsetof(WGPUSharedBufferMemoryEndAccessState, nextInChain),
        "offsetof mismatch for SharedBufferMemoryEndAccessState::nextInChain");
static_assert(offsetof(SharedBufferMemoryEndAccessState, initialized) == offsetof(WGPUSharedBufferMemoryEndAccessState, initialized),
        "offsetof mismatch for SharedBufferMemoryEndAccessState::initialized");
static_assert(offsetof(SharedBufferMemoryEndAccessState, fenceCount) == offsetof(WGPUSharedBufferMemoryEndAccessState, fenceCount),
        "offsetof mismatch for SharedBufferMemoryEndAccessState::fenceCount");
static_assert(offsetof(SharedBufferMemoryEndAccessState, fences) == offsetof(WGPUSharedBufferMemoryEndAccessState, fences),
        "offsetof mismatch for SharedBufferMemoryEndAccessState::fences");
static_assert(offsetof(SharedBufferMemoryEndAccessState, signaledValues) == offsetof(WGPUSharedBufferMemoryEndAccessState, signaledValues),
        "offsetof mismatch for SharedBufferMemoryEndAccessState::signaledValues");

// SharedBufferMemoryProperties implementation

SharedBufferMemoryProperties::operator const WGPUSharedBufferMemoryProperties&() const noexcept {
    return *reinterpret_cast<const WGPUSharedBufferMemoryProperties*>(this);
}

static_assert(sizeof(SharedBufferMemoryProperties) == sizeof(WGPUSharedBufferMemoryProperties), "sizeof mismatch for SharedBufferMemoryProperties");
static_assert(alignof(SharedBufferMemoryProperties) == alignof(WGPUSharedBufferMemoryProperties), "alignof mismatch for SharedBufferMemoryProperties");
static_assert(offsetof(SharedBufferMemoryProperties, nextInChain) == offsetof(WGPUSharedBufferMemoryProperties, nextInChain),
        "offsetof mismatch for SharedBufferMemoryProperties::nextInChain");
static_assert(offsetof(SharedBufferMemoryProperties, usage) == offsetof(WGPUSharedBufferMemoryProperties, usage),
        "offsetof mismatch for SharedBufferMemoryProperties::usage");
static_assert(offsetof(SharedBufferMemoryProperties, size) == offsetof(WGPUSharedBufferMemoryProperties, size),
        "offsetof mismatch for SharedBufferMemoryProperties::size");

// SharedFenceDXGISharedHandleDescriptor implementation
SharedFenceDXGISharedHandleDescriptor::SharedFenceDXGISharedHandleDescriptor()
  : ChainedStruct { nullptr, SType::SharedFenceDXGISharedHandleDescriptor } {}
struct SharedFenceDXGISharedHandleDescriptor::Init {
    ChainedStruct * const nextInChain;
    void * handle;
};
SharedFenceDXGISharedHandleDescriptor::SharedFenceDXGISharedHandleDescriptor(SharedFenceDXGISharedHandleDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SharedFenceDXGISharedHandleDescriptor }, 
    handle(std::move(init.handle)){}

SharedFenceDXGISharedHandleDescriptor::operator const WGPUSharedFenceDXGISharedHandleDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedFenceDXGISharedHandleDescriptor*>(this);
}

static_assert(sizeof(SharedFenceDXGISharedHandleDescriptor) == sizeof(WGPUSharedFenceDXGISharedHandleDescriptor), "sizeof mismatch for SharedFenceDXGISharedHandleDescriptor");
static_assert(alignof(SharedFenceDXGISharedHandleDescriptor) == alignof(WGPUSharedFenceDXGISharedHandleDescriptor), "alignof mismatch for SharedFenceDXGISharedHandleDescriptor");
static_assert(offsetof(SharedFenceDXGISharedHandleDescriptor, handle) == offsetof(WGPUSharedFenceDXGISharedHandleDescriptor, handle),
        "offsetof mismatch for SharedFenceDXGISharedHandleDescriptor::handle");

// SharedFenceDXGISharedHandleExportInfo implementation
SharedFenceDXGISharedHandleExportInfo::SharedFenceDXGISharedHandleExportInfo()
  : ChainedStructOut { nullptr, SType::SharedFenceDXGISharedHandleExportInfo } {}
struct SharedFenceDXGISharedHandleExportInfo::Init {
    ChainedStructOut *  nextInChain;
    void * handle;
};
SharedFenceDXGISharedHandleExportInfo::SharedFenceDXGISharedHandleExportInfo(SharedFenceDXGISharedHandleExportInfo::Init&& init)
  : ChainedStructOut { init.nextInChain, SType::SharedFenceDXGISharedHandleExportInfo }, 
    handle(std::move(init.handle)){}

SharedFenceDXGISharedHandleExportInfo::operator const WGPUSharedFenceDXGISharedHandleExportInfo&() const noexcept {
    return *reinterpret_cast<const WGPUSharedFenceDXGISharedHandleExportInfo*>(this);
}

static_assert(sizeof(SharedFenceDXGISharedHandleExportInfo) == sizeof(WGPUSharedFenceDXGISharedHandleExportInfo), "sizeof mismatch for SharedFenceDXGISharedHandleExportInfo");
static_assert(alignof(SharedFenceDXGISharedHandleExportInfo) == alignof(WGPUSharedFenceDXGISharedHandleExportInfo), "alignof mismatch for SharedFenceDXGISharedHandleExportInfo");
static_assert(offsetof(SharedFenceDXGISharedHandleExportInfo, handle) == offsetof(WGPUSharedFenceDXGISharedHandleExportInfo, handle),
        "offsetof mismatch for SharedFenceDXGISharedHandleExportInfo::handle");

// SharedFenceMTLSharedEventDescriptor implementation
SharedFenceMTLSharedEventDescriptor::SharedFenceMTLSharedEventDescriptor()
  : ChainedStruct { nullptr, SType::SharedFenceMTLSharedEventDescriptor } {}
struct SharedFenceMTLSharedEventDescriptor::Init {
    ChainedStruct * const nextInChain;
    void * sharedEvent;
};
SharedFenceMTLSharedEventDescriptor::SharedFenceMTLSharedEventDescriptor(SharedFenceMTLSharedEventDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SharedFenceMTLSharedEventDescriptor }, 
    sharedEvent(std::move(init.sharedEvent)){}

SharedFenceMTLSharedEventDescriptor::operator const WGPUSharedFenceMTLSharedEventDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedFenceMTLSharedEventDescriptor*>(this);
}

static_assert(sizeof(SharedFenceMTLSharedEventDescriptor) == sizeof(WGPUSharedFenceMTLSharedEventDescriptor), "sizeof mismatch for SharedFenceMTLSharedEventDescriptor");
static_assert(alignof(SharedFenceMTLSharedEventDescriptor) == alignof(WGPUSharedFenceMTLSharedEventDescriptor), "alignof mismatch for SharedFenceMTLSharedEventDescriptor");
static_assert(offsetof(SharedFenceMTLSharedEventDescriptor, sharedEvent) == offsetof(WGPUSharedFenceMTLSharedEventDescriptor, sharedEvent),
        "offsetof mismatch for SharedFenceMTLSharedEventDescriptor::sharedEvent");

// SharedFenceMTLSharedEventExportInfo implementation
SharedFenceMTLSharedEventExportInfo::SharedFenceMTLSharedEventExportInfo()
  : ChainedStructOut { nullptr, SType::SharedFenceMTLSharedEventExportInfo } {}
struct SharedFenceMTLSharedEventExportInfo::Init {
    ChainedStructOut *  nextInChain;
    void * sharedEvent;
};
SharedFenceMTLSharedEventExportInfo::SharedFenceMTLSharedEventExportInfo(SharedFenceMTLSharedEventExportInfo::Init&& init)
  : ChainedStructOut { init.nextInChain, SType::SharedFenceMTLSharedEventExportInfo }, 
    sharedEvent(std::move(init.sharedEvent)){}

SharedFenceMTLSharedEventExportInfo::operator const WGPUSharedFenceMTLSharedEventExportInfo&() const noexcept {
    return *reinterpret_cast<const WGPUSharedFenceMTLSharedEventExportInfo*>(this);
}

static_assert(sizeof(SharedFenceMTLSharedEventExportInfo) == sizeof(WGPUSharedFenceMTLSharedEventExportInfo), "sizeof mismatch for SharedFenceMTLSharedEventExportInfo");
static_assert(alignof(SharedFenceMTLSharedEventExportInfo) == alignof(WGPUSharedFenceMTLSharedEventExportInfo), "alignof mismatch for SharedFenceMTLSharedEventExportInfo");
static_assert(offsetof(SharedFenceMTLSharedEventExportInfo, sharedEvent) == offsetof(WGPUSharedFenceMTLSharedEventExportInfo, sharedEvent),
        "offsetof mismatch for SharedFenceMTLSharedEventExportInfo::sharedEvent");

// SharedFenceDescriptor implementation

SharedFenceDescriptor::operator const WGPUSharedFenceDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedFenceDescriptor*>(this);
}

static_assert(sizeof(SharedFenceDescriptor) == sizeof(WGPUSharedFenceDescriptor), "sizeof mismatch for SharedFenceDescriptor");
static_assert(alignof(SharedFenceDescriptor) == alignof(WGPUSharedFenceDescriptor), "alignof mismatch for SharedFenceDescriptor");
static_assert(offsetof(SharedFenceDescriptor, nextInChain) == offsetof(WGPUSharedFenceDescriptor, nextInChain),
        "offsetof mismatch for SharedFenceDescriptor::nextInChain");
static_assert(offsetof(SharedFenceDescriptor, label) == offsetof(WGPUSharedFenceDescriptor, label),
        "offsetof mismatch for SharedFenceDescriptor::label");

// SharedFenceExportInfo implementation

SharedFenceExportInfo::operator const WGPUSharedFenceExportInfo&() const noexcept {
    return *reinterpret_cast<const WGPUSharedFenceExportInfo*>(this);
}

static_assert(sizeof(SharedFenceExportInfo) == sizeof(WGPUSharedFenceExportInfo), "sizeof mismatch for SharedFenceExportInfo");
static_assert(alignof(SharedFenceExportInfo) == alignof(WGPUSharedFenceExportInfo), "alignof mismatch for SharedFenceExportInfo");
static_assert(offsetof(SharedFenceExportInfo, nextInChain) == offsetof(WGPUSharedFenceExportInfo, nextInChain),
        "offsetof mismatch for SharedFenceExportInfo::nextInChain");
static_assert(offsetof(SharedFenceExportInfo, type) == offsetof(WGPUSharedFenceExportInfo, type),
        "offsetof mismatch for SharedFenceExportInfo::type");

// SharedFenceVkSemaphoreOpaqueFDDescriptor implementation
SharedFenceVkSemaphoreOpaqueFDDescriptor::SharedFenceVkSemaphoreOpaqueFDDescriptor()
  : ChainedStruct { nullptr, SType::SharedFenceVkSemaphoreOpaqueFDDescriptor } {}
struct SharedFenceVkSemaphoreOpaqueFDDescriptor::Init {
    ChainedStruct * const nextInChain;
    int handle;
};
SharedFenceVkSemaphoreOpaqueFDDescriptor::SharedFenceVkSemaphoreOpaqueFDDescriptor(SharedFenceVkSemaphoreOpaqueFDDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SharedFenceVkSemaphoreOpaqueFDDescriptor }, 
    handle(std::move(init.handle)){}

SharedFenceVkSemaphoreOpaqueFDDescriptor::operator const WGPUSharedFenceVkSemaphoreOpaqueFDDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedFenceVkSemaphoreOpaqueFDDescriptor*>(this);
}

static_assert(sizeof(SharedFenceVkSemaphoreOpaqueFDDescriptor) == sizeof(WGPUSharedFenceVkSemaphoreOpaqueFDDescriptor), "sizeof mismatch for SharedFenceVkSemaphoreOpaqueFDDescriptor");
static_assert(alignof(SharedFenceVkSemaphoreOpaqueFDDescriptor) == alignof(WGPUSharedFenceVkSemaphoreOpaqueFDDescriptor), "alignof mismatch for SharedFenceVkSemaphoreOpaqueFDDescriptor");
static_assert(offsetof(SharedFenceVkSemaphoreOpaqueFDDescriptor, handle) == offsetof(WGPUSharedFenceVkSemaphoreOpaqueFDDescriptor, handle),
        "offsetof mismatch for SharedFenceVkSemaphoreOpaqueFDDescriptor::handle");

// SharedFenceVkSemaphoreOpaqueFDExportInfo implementation
SharedFenceVkSemaphoreOpaqueFDExportInfo::SharedFenceVkSemaphoreOpaqueFDExportInfo()
  : ChainedStructOut { nullptr, SType::SharedFenceVkSemaphoreOpaqueFDExportInfo } {}
struct SharedFenceVkSemaphoreOpaqueFDExportInfo::Init {
    ChainedStructOut *  nextInChain;
    int handle;
};
SharedFenceVkSemaphoreOpaqueFDExportInfo::SharedFenceVkSemaphoreOpaqueFDExportInfo(SharedFenceVkSemaphoreOpaqueFDExportInfo::Init&& init)
  : ChainedStructOut { init.nextInChain, SType::SharedFenceVkSemaphoreOpaqueFDExportInfo }, 
    handle(std::move(init.handle)){}

SharedFenceVkSemaphoreOpaqueFDExportInfo::operator const WGPUSharedFenceVkSemaphoreOpaqueFDExportInfo&() const noexcept {
    return *reinterpret_cast<const WGPUSharedFenceVkSemaphoreOpaqueFDExportInfo*>(this);
}

static_assert(sizeof(SharedFenceVkSemaphoreOpaqueFDExportInfo) == sizeof(WGPUSharedFenceVkSemaphoreOpaqueFDExportInfo), "sizeof mismatch for SharedFenceVkSemaphoreOpaqueFDExportInfo");
static_assert(alignof(SharedFenceVkSemaphoreOpaqueFDExportInfo) == alignof(WGPUSharedFenceVkSemaphoreOpaqueFDExportInfo), "alignof mismatch for SharedFenceVkSemaphoreOpaqueFDExportInfo");
static_assert(offsetof(SharedFenceVkSemaphoreOpaqueFDExportInfo, handle) == offsetof(WGPUSharedFenceVkSemaphoreOpaqueFDExportInfo, handle),
        "offsetof mismatch for SharedFenceVkSemaphoreOpaqueFDExportInfo::handle");

// SharedFenceVkSemaphoreSyncFDDescriptor implementation
SharedFenceVkSemaphoreSyncFDDescriptor::SharedFenceVkSemaphoreSyncFDDescriptor()
  : ChainedStruct { nullptr, SType::SharedFenceVkSemaphoreSyncFDDescriptor } {}
struct SharedFenceVkSemaphoreSyncFDDescriptor::Init {
    ChainedStruct * const nextInChain;
    int handle;
};
SharedFenceVkSemaphoreSyncFDDescriptor::SharedFenceVkSemaphoreSyncFDDescriptor(SharedFenceVkSemaphoreSyncFDDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SharedFenceVkSemaphoreSyncFDDescriptor }, 
    handle(std::move(init.handle)){}

SharedFenceVkSemaphoreSyncFDDescriptor::operator const WGPUSharedFenceVkSemaphoreSyncFDDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedFenceVkSemaphoreSyncFDDescriptor*>(this);
}

static_assert(sizeof(SharedFenceVkSemaphoreSyncFDDescriptor) == sizeof(WGPUSharedFenceVkSemaphoreSyncFDDescriptor), "sizeof mismatch for SharedFenceVkSemaphoreSyncFDDescriptor");
static_assert(alignof(SharedFenceVkSemaphoreSyncFDDescriptor) == alignof(WGPUSharedFenceVkSemaphoreSyncFDDescriptor), "alignof mismatch for SharedFenceVkSemaphoreSyncFDDescriptor");
static_assert(offsetof(SharedFenceVkSemaphoreSyncFDDescriptor, handle) == offsetof(WGPUSharedFenceVkSemaphoreSyncFDDescriptor, handle),
        "offsetof mismatch for SharedFenceVkSemaphoreSyncFDDescriptor::handle");

// SharedFenceVkSemaphoreSyncFDExportInfo implementation
SharedFenceVkSemaphoreSyncFDExportInfo::SharedFenceVkSemaphoreSyncFDExportInfo()
  : ChainedStructOut { nullptr, SType::SharedFenceVkSemaphoreSyncFDExportInfo } {}
struct SharedFenceVkSemaphoreSyncFDExportInfo::Init {
    ChainedStructOut *  nextInChain;
    int handle;
};
SharedFenceVkSemaphoreSyncFDExportInfo::SharedFenceVkSemaphoreSyncFDExportInfo(SharedFenceVkSemaphoreSyncFDExportInfo::Init&& init)
  : ChainedStructOut { init.nextInChain, SType::SharedFenceVkSemaphoreSyncFDExportInfo }, 
    handle(std::move(init.handle)){}

SharedFenceVkSemaphoreSyncFDExportInfo::operator const WGPUSharedFenceVkSemaphoreSyncFDExportInfo&() const noexcept {
    return *reinterpret_cast<const WGPUSharedFenceVkSemaphoreSyncFDExportInfo*>(this);
}

static_assert(sizeof(SharedFenceVkSemaphoreSyncFDExportInfo) == sizeof(WGPUSharedFenceVkSemaphoreSyncFDExportInfo), "sizeof mismatch for SharedFenceVkSemaphoreSyncFDExportInfo");
static_assert(alignof(SharedFenceVkSemaphoreSyncFDExportInfo) == alignof(WGPUSharedFenceVkSemaphoreSyncFDExportInfo), "alignof mismatch for SharedFenceVkSemaphoreSyncFDExportInfo");
static_assert(offsetof(SharedFenceVkSemaphoreSyncFDExportInfo, handle) == offsetof(WGPUSharedFenceVkSemaphoreSyncFDExportInfo, handle),
        "offsetof mismatch for SharedFenceVkSemaphoreSyncFDExportInfo::handle");

// SharedFenceVkSemaphoreZirconHandleDescriptor implementation
SharedFenceVkSemaphoreZirconHandleDescriptor::SharedFenceVkSemaphoreZirconHandleDescriptor()
  : ChainedStruct { nullptr, SType::SharedFenceVkSemaphoreZirconHandleDescriptor } {}
struct SharedFenceVkSemaphoreZirconHandleDescriptor::Init {
    ChainedStruct * const nextInChain;
    uint32_t handle;
};
SharedFenceVkSemaphoreZirconHandleDescriptor::SharedFenceVkSemaphoreZirconHandleDescriptor(SharedFenceVkSemaphoreZirconHandleDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SharedFenceVkSemaphoreZirconHandleDescriptor }, 
    handle(std::move(init.handle)){}

SharedFenceVkSemaphoreZirconHandleDescriptor::operator const WGPUSharedFenceVkSemaphoreZirconHandleDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedFenceVkSemaphoreZirconHandleDescriptor*>(this);
}

static_assert(sizeof(SharedFenceVkSemaphoreZirconHandleDescriptor) == sizeof(WGPUSharedFenceVkSemaphoreZirconHandleDescriptor), "sizeof mismatch for SharedFenceVkSemaphoreZirconHandleDescriptor");
static_assert(alignof(SharedFenceVkSemaphoreZirconHandleDescriptor) == alignof(WGPUSharedFenceVkSemaphoreZirconHandleDescriptor), "alignof mismatch for SharedFenceVkSemaphoreZirconHandleDescriptor");
static_assert(offsetof(SharedFenceVkSemaphoreZirconHandleDescriptor, handle) == offsetof(WGPUSharedFenceVkSemaphoreZirconHandleDescriptor, handle),
        "offsetof mismatch for SharedFenceVkSemaphoreZirconHandleDescriptor::handle");

// SharedFenceVkSemaphoreZirconHandleExportInfo implementation
SharedFenceVkSemaphoreZirconHandleExportInfo::SharedFenceVkSemaphoreZirconHandleExportInfo()
  : ChainedStructOut { nullptr, SType::SharedFenceVkSemaphoreZirconHandleExportInfo } {}
struct SharedFenceVkSemaphoreZirconHandleExportInfo::Init {
    ChainedStructOut *  nextInChain;
    uint32_t handle;
};
SharedFenceVkSemaphoreZirconHandleExportInfo::SharedFenceVkSemaphoreZirconHandleExportInfo(SharedFenceVkSemaphoreZirconHandleExportInfo::Init&& init)
  : ChainedStructOut { init.nextInChain, SType::SharedFenceVkSemaphoreZirconHandleExportInfo }, 
    handle(std::move(init.handle)){}

SharedFenceVkSemaphoreZirconHandleExportInfo::operator const WGPUSharedFenceVkSemaphoreZirconHandleExportInfo&() const noexcept {
    return *reinterpret_cast<const WGPUSharedFenceVkSemaphoreZirconHandleExportInfo*>(this);
}

static_assert(sizeof(SharedFenceVkSemaphoreZirconHandleExportInfo) == sizeof(WGPUSharedFenceVkSemaphoreZirconHandleExportInfo), "sizeof mismatch for SharedFenceVkSemaphoreZirconHandleExportInfo");
static_assert(alignof(SharedFenceVkSemaphoreZirconHandleExportInfo) == alignof(WGPUSharedFenceVkSemaphoreZirconHandleExportInfo), "alignof mismatch for SharedFenceVkSemaphoreZirconHandleExportInfo");
static_assert(offsetof(SharedFenceVkSemaphoreZirconHandleExportInfo, handle) == offsetof(WGPUSharedFenceVkSemaphoreZirconHandleExportInfo, handle),
        "offsetof mismatch for SharedFenceVkSemaphoreZirconHandleExportInfo::handle");

// SharedTextureMemoryD3DSwapchainBeginState implementation
SharedTextureMemoryD3DSwapchainBeginState::SharedTextureMemoryD3DSwapchainBeginState()
  : ChainedStruct { nullptr, SType::SharedTextureMemoryD3DSwapchainBeginState } {}
struct SharedTextureMemoryD3DSwapchainBeginState::Init {
    ChainedStruct * const nextInChain;
    Bool isSwapchain = false;
};
SharedTextureMemoryD3DSwapchainBeginState::SharedTextureMemoryD3DSwapchainBeginState(SharedTextureMemoryD3DSwapchainBeginState::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SharedTextureMemoryD3DSwapchainBeginState }, 
    isSwapchain(std::move(init.isSwapchain)){}

SharedTextureMemoryD3DSwapchainBeginState::operator const WGPUSharedTextureMemoryD3DSwapchainBeginState&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryD3DSwapchainBeginState*>(this);
}

static_assert(sizeof(SharedTextureMemoryD3DSwapchainBeginState) == sizeof(WGPUSharedTextureMemoryD3DSwapchainBeginState), "sizeof mismatch for SharedTextureMemoryD3DSwapchainBeginState");
static_assert(alignof(SharedTextureMemoryD3DSwapchainBeginState) == alignof(WGPUSharedTextureMemoryD3DSwapchainBeginState), "alignof mismatch for SharedTextureMemoryD3DSwapchainBeginState");
static_assert(offsetof(SharedTextureMemoryD3DSwapchainBeginState, isSwapchain) == offsetof(WGPUSharedTextureMemoryD3DSwapchainBeginState, isSwapchain),
        "offsetof mismatch for SharedTextureMemoryD3DSwapchainBeginState::isSwapchain");

// SharedTextureMemoryDXGISharedHandleDescriptor implementation
SharedTextureMemoryDXGISharedHandleDescriptor::SharedTextureMemoryDXGISharedHandleDescriptor()
  : ChainedStruct { nullptr, SType::SharedTextureMemoryDXGISharedHandleDescriptor } {}
struct SharedTextureMemoryDXGISharedHandleDescriptor::Init {
    ChainedStruct * const nextInChain;
    void * handle;
    Bool useKeyedMutex;
};
SharedTextureMemoryDXGISharedHandleDescriptor::SharedTextureMemoryDXGISharedHandleDescriptor(SharedTextureMemoryDXGISharedHandleDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SharedTextureMemoryDXGISharedHandleDescriptor }, 
    handle(std::move(init.handle)), 
    useKeyedMutex(std::move(init.useKeyedMutex)){}

SharedTextureMemoryDXGISharedHandleDescriptor::operator const WGPUSharedTextureMemoryDXGISharedHandleDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryDXGISharedHandleDescriptor*>(this);
}

static_assert(sizeof(SharedTextureMemoryDXGISharedHandleDescriptor) == sizeof(WGPUSharedTextureMemoryDXGISharedHandleDescriptor), "sizeof mismatch for SharedTextureMemoryDXGISharedHandleDescriptor");
static_assert(alignof(SharedTextureMemoryDXGISharedHandleDescriptor) == alignof(WGPUSharedTextureMemoryDXGISharedHandleDescriptor), "alignof mismatch for SharedTextureMemoryDXGISharedHandleDescriptor");
static_assert(offsetof(SharedTextureMemoryDXGISharedHandleDescriptor, handle) == offsetof(WGPUSharedTextureMemoryDXGISharedHandleDescriptor, handle),
        "offsetof mismatch for SharedTextureMemoryDXGISharedHandleDescriptor::handle");
static_assert(offsetof(SharedTextureMemoryDXGISharedHandleDescriptor, useKeyedMutex) == offsetof(WGPUSharedTextureMemoryDXGISharedHandleDescriptor, useKeyedMutex),
        "offsetof mismatch for SharedTextureMemoryDXGISharedHandleDescriptor::useKeyedMutex");

// SharedTextureMemoryEGLImageDescriptor implementation
SharedTextureMemoryEGLImageDescriptor::SharedTextureMemoryEGLImageDescriptor()
  : ChainedStruct { nullptr, SType::SharedTextureMemoryEGLImageDescriptor } {}
struct SharedTextureMemoryEGLImageDescriptor::Init {
    ChainedStruct * const nextInChain;
    void * image;
};
SharedTextureMemoryEGLImageDescriptor::SharedTextureMemoryEGLImageDescriptor(SharedTextureMemoryEGLImageDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SharedTextureMemoryEGLImageDescriptor }, 
    image(std::move(init.image)){}

SharedTextureMemoryEGLImageDescriptor::operator const WGPUSharedTextureMemoryEGLImageDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryEGLImageDescriptor*>(this);
}

static_assert(sizeof(SharedTextureMemoryEGLImageDescriptor) == sizeof(WGPUSharedTextureMemoryEGLImageDescriptor), "sizeof mismatch for SharedTextureMemoryEGLImageDescriptor");
static_assert(alignof(SharedTextureMemoryEGLImageDescriptor) == alignof(WGPUSharedTextureMemoryEGLImageDescriptor), "alignof mismatch for SharedTextureMemoryEGLImageDescriptor");
static_assert(offsetof(SharedTextureMemoryEGLImageDescriptor, image) == offsetof(WGPUSharedTextureMemoryEGLImageDescriptor, image),
        "offsetof mismatch for SharedTextureMemoryEGLImageDescriptor::image");

// SharedTextureMemoryIOSurfaceDescriptor implementation
SharedTextureMemoryIOSurfaceDescriptor::SharedTextureMemoryIOSurfaceDescriptor()
  : ChainedStruct { nullptr, SType::SharedTextureMemoryIOSurfaceDescriptor } {}
struct SharedTextureMemoryIOSurfaceDescriptor::Init {
    ChainedStruct * const nextInChain;
    void * ioSurface;
};
SharedTextureMemoryIOSurfaceDescriptor::SharedTextureMemoryIOSurfaceDescriptor(SharedTextureMemoryIOSurfaceDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SharedTextureMemoryIOSurfaceDescriptor }, 
    ioSurface(std::move(init.ioSurface)){}

SharedTextureMemoryIOSurfaceDescriptor::operator const WGPUSharedTextureMemoryIOSurfaceDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryIOSurfaceDescriptor*>(this);
}

static_assert(sizeof(SharedTextureMemoryIOSurfaceDescriptor) == sizeof(WGPUSharedTextureMemoryIOSurfaceDescriptor), "sizeof mismatch for SharedTextureMemoryIOSurfaceDescriptor");
static_assert(alignof(SharedTextureMemoryIOSurfaceDescriptor) == alignof(WGPUSharedTextureMemoryIOSurfaceDescriptor), "alignof mismatch for SharedTextureMemoryIOSurfaceDescriptor");
static_assert(offsetof(SharedTextureMemoryIOSurfaceDescriptor, ioSurface) == offsetof(WGPUSharedTextureMemoryIOSurfaceDescriptor, ioSurface),
        "offsetof mismatch for SharedTextureMemoryIOSurfaceDescriptor::ioSurface");

// SharedTextureMemoryAHardwareBufferDescriptor implementation
SharedTextureMemoryAHardwareBufferDescriptor::SharedTextureMemoryAHardwareBufferDescriptor()
  : ChainedStruct { nullptr, SType::SharedTextureMemoryAHardwareBufferDescriptor } {}
struct SharedTextureMemoryAHardwareBufferDescriptor::Init {
    ChainedStruct * const nextInChain;
    void * handle;
};
SharedTextureMemoryAHardwareBufferDescriptor::SharedTextureMemoryAHardwareBufferDescriptor(SharedTextureMemoryAHardwareBufferDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SharedTextureMemoryAHardwareBufferDescriptor }, 
    handle(std::move(init.handle)){}

SharedTextureMemoryAHardwareBufferDescriptor::operator const WGPUSharedTextureMemoryAHardwareBufferDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryAHardwareBufferDescriptor*>(this);
}

static_assert(sizeof(SharedTextureMemoryAHardwareBufferDescriptor) == sizeof(WGPUSharedTextureMemoryAHardwareBufferDescriptor), "sizeof mismatch for SharedTextureMemoryAHardwareBufferDescriptor");
static_assert(alignof(SharedTextureMemoryAHardwareBufferDescriptor) == alignof(WGPUSharedTextureMemoryAHardwareBufferDescriptor), "alignof mismatch for SharedTextureMemoryAHardwareBufferDescriptor");
static_assert(offsetof(SharedTextureMemoryAHardwareBufferDescriptor, handle) == offsetof(WGPUSharedTextureMemoryAHardwareBufferDescriptor, handle),
        "offsetof mismatch for SharedTextureMemoryAHardwareBufferDescriptor::handle");

// SharedTextureMemoryBeginAccessDescriptor implementation

SharedTextureMemoryBeginAccessDescriptor::operator const WGPUSharedTextureMemoryBeginAccessDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryBeginAccessDescriptor*>(this);
}

static_assert(sizeof(SharedTextureMemoryBeginAccessDescriptor) == sizeof(WGPUSharedTextureMemoryBeginAccessDescriptor), "sizeof mismatch for SharedTextureMemoryBeginAccessDescriptor");
static_assert(alignof(SharedTextureMemoryBeginAccessDescriptor) == alignof(WGPUSharedTextureMemoryBeginAccessDescriptor), "alignof mismatch for SharedTextureMemoryBeginAccessDescriptor");
static_assert(offsetof(SharedTextureMemoryBeginAccessDescriptor, nextInChain) == offsetof(WGPUSharedTextureMemoryBeginAccessDescriptor, nextInChain),
        "offsetof mismatch for SharedTextureMemoryBeginAccessDescriptor::nextInChain");
static_assert(offsetof(SharedTextureMemoryBeginAccessDescriptor, concurrentRead) == offsetof(WGPUSharedTextureMemoryBeginAccessDescriptor, concurrentRead),
        "offsetof mismatch for SharedTextureMemoryBeginAccessDescriptor::concurrentRead");
static_assert(offsetof(SharedTextureMemoryBeginAccessDescriptor, initialized) == offsetof(WGPUSharedTextureMemoryBeginAccessDescriptor, initialized),
        "offsetof mismatch for SharedTextureMemoryBeginAccessDescriptor::initialized");
static_assert(offsetof(SharedTextureMemoryBeginAccessDescriptor, fenceCount) == offsetof(WGPUSharedTextureMemoryBeginAccessDescriptor, fenceCount),
        "offsetof mismatch for SharedTextureMemoryBeginAccessDescriptor::fenceCount");
static_assert(offsetof(SharedTextureMemoryBeginAccessDescriptor, fences) == offsetof(WGPUSharedTextureMemoryBeginAccessDescriptor, fences),
        "offsetof mismatch for SharedTextureMemoryBeginAccessDescriptor::fences");
static_assert(offsetof(SharedTextureMemoryBeginAccessDescriptor, signaledValues) == offsetof(WGPUSharedTextureMemoryBeginAccessDescriptor, signaledValues),
        "offsetof mismatch for SharedTextureMemoryBeginAccessDescriptor::signaledValues");

// SharedTextureMemoryDescriptor implementation

SharedTextureMemoryDescriptor::operator const WGPUSharedTextureMemoryDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryDescriptor*>(this);
}

static_assert(sizeof(SharedTextureMemoryDescriptor) == sizeof(WGPUSharedTextureMemoryDescriptor), "sizeof mismatch for SharedTextureMemoryDescriptor");
static_assert(alignof(SharedTextureMemoryDescriptor) == alignof(WGPUSharedTextureMemoryDescriptor), "alignof mismatch for SharedTextureMemoryDescriptor");
static_assert(offsetof(SharedTextureMemoryDescriptor, nextInChain) == offsetof(WGPUSharedTextureMemoryDescriptor, nextInChain),
        "offsetof mismatch for SharedTextureMemoryDescriptor::nextInChain");
static_assert(offsetof(SharedTextureMemoryDescriptor, label) == offsetof(WGPUSharedTextureMemoryDescriptor, label),
        "offsetof mismatch for SharedTextureMemoryDescriptor::label");

// SharedTextureMemoryDmaBufPlane implementation

SharedTextureMemoryDmaBufPlane::operator const WGPUSharedTextureMemoryDmaBufPlane&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryDmaBufPlane*>(this);
}

static_assert(sizeof(SharedTextureMemoryDmaBufPlane) == sizeof(WGPUSharedTextureMemoryDmaBufPlane), "sizeof mismatch for SharedTextureMemoryDmaBufPlane");
static_assert(alignof(SharedTextureMemoryDmaBufPlane) == alignof(WGPUSharedTextureMemoryDmaBufPlane), "alignof mismatch for SharedTextureMemoryDmaBufPlane");
static_assert(offsetof(SharedTextureMemoryDmaBufPlane, fd) == offsetof(WGPUSharedTextureMemoryDmaBufPlane, fd),
        "offsetof mismatch for SharedTextureMemoryDmaBufPlane::fd");
static_assert(offsetof(SharedTextureMemoryDmaBufPlane, offset) == offsetof(WGPUSharedTextureMemoryDmaBufPlane, offset),
        "offsetof mismatch for SharedTextureMemoryDmaBufPlane::offset");
static_assert(offsetof(SharedTextureMemoryDmaBufPlane, stride) == offsetof(WGPUSharedTextureMemoryDmaBufPlane, stride),
        "offsetof mismatch for SharedTextureMemoryDmaBufPlane::stride");

// SharedTextureMemoryEndAccessState implementation
SharedTextureMemoryEndAccessState::SharedTextureMemoryEndAccessState() = default;
SharedTextureMemoryEndAccessState::~SharedTextureMemoryEndAccessState() {
    if (this->fences != nullptr || this->signaledValues != nullptr) {
        wgpuDawnWireClientSharedTextureMemoryEndAccessStateFreeMembers(
            *reinterpret_cast<WGPUSharedTextureMemoryEndAccessState*>(this));
    }
}

SharedTextureMemoryEndAccessState::SharedTextureMemoryEndAccessState(SharedTextureMemoryEndAccessState&& rhs)
    : initialized(rhs.initialized),
            fenceCount(rhs.fenceCount),
            fences(rhs.fences),
            signaledValues(rhs.signaledValues){
    Reset(rhs);
}

SharedTextureMemoryEndAccessState& SharedTextureMemoryEndAccessState::operator=(SharedTextureMemoryEndAccessState&& rhs) {
    if (&rhs == this) {
        return *this;
    }
    this->~SharedTextureMemoryEndAccessState();
    detail::AsNonConstReference(this->initialized) = std::move(rhs.initialized);
    detail::AsNonConstReference(this->fenceCount) = std::move(rhs.fenceCount);
    detail::AsNonConstReference(this->fences) = std::move(rhs.fences);
    detail::AsNonConstReference(this->signaledValues) = std::move(rhs.signaledValues);
    Reset(rhs);
    return *this;
}

    // static
void SharedTextureMemoryEndAccessState::Reset(SharedTextureMemoryEndAccessState& value) {
    SharedTextureMemoryEndAccessState defaultValue{};
    detail::AsNonConstReference(value.initialized) = defaultValue.initialized;
    detail::AsNonConstReference(value.fenceCount) = defaultValue.fenceCount;
    detail::AsNonConstReference(value.fences) = defaultValue.fences;
    detail::AsNonConstReference(value.signaledValues) = defaultValue.signaledValues;
}

SharedTextureMemoryEndAccessState::operator const WGPUSharedTextureMemoryEndAccessState&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryEndAccessState*>(this);
}

static_assert(sizeof(SharedTextureMemoryEndAccessState) == sizeof(WGPUSharedTextureMemoryEndAccessState), "sizeof mismatch for SharedTextureMemoryEndAccessState");
static_assert(alignof(SharedTextureMemoryEndAccessState) == alignof(WGPUSharedTextureMemoryEndAccessState), "alignof mismatch for SharedTextureMemoryEndAccessState");
static_assert(offsetof(SharedTextureMemoryEndAccessState, nextInChain) == offsetof(WGPUSharedTextureMemoryEndAccessState, nextInChain),
        "offsetof mismatch for SharedTextureMemoryEndAccessState::nextInChain");
static_assert(offsetof(SharedTextureMemoryEndAccessState, initialized) == offsetof(WGPUSharedTextureMemoryEndAccessState, initialized),
        "offsetof mismatch for SharedTextureMemoryEndAccessState::initialized");
static_assert(offsetof(SharedTextureMemoryEndAccessState, fenceCount) == offsetof(WGPUSharedTextureMemoryEndAccessState, fenceCount),
        "offsetof mismatch for SharedTextureMemoryEndAccessState::fenceCount");
static_assert(offsetof(SharedTextureMemoryEndAccessState, fences) == offsetof(WGPUSharedTextureMemoryEndAccessState, fences),
        "offsetof mismatch for SharedTextureMemoryEndAccessState::fences");
static_assert(offsetof(SharedTextureMemoryEndAccessState, signaledValues) == offsetof(WGPUSharedTextureMemoryEndAccessState, signaledValues),
        "offsetof mismatch for SharedTextureMemoryEndAccessState::signaledValues");

// SharedTextureMemoryOpaqueFDDescriptor implementation
SharedTextureMemoryOpaqueFDDescriptor::SharedTextureMemoryOpaqueFDDescriptor()
  : ChainedStruct { nullptr, SType::SharedTextureMemoryOpaqueFDDescriptor } {}
struct SharedTextureMemoryOpaqueFDDescriptor::Init {
    ChainedStruct * const nextInChain;
    void const * vkImageCreateInfo;
    int memoryFD;
    uint32_t memoryTypeIndex;
    uint64_t allocationSize;
    Bool dedicatedAllocation;
};
SharedTextureMemoryOpaqueFDDescriptor::SharedTextureMemoryOpaqueFDDescriptor(SharedTextureMemoryOpaqueFDDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SharedTextureMemoryOpaqueFDDescriptor }, 
    vkImageCreateInfo(std::move(init.vkImageCreateInfo)), 
    memoryFD(std::move(init.memoryFD)), 
    memoryTypeIndex(std::move(init.memoryTypeIndex)), 
    allocationSize(std::move(init.allocationSize)), 
    dedicatedAllocation(std::move(init.dedicatedAllocation)){}

SharedTextureMemoryOpaqueFDDescriptor::operator const WGPUSharedTextureMemoryOpaqueFDDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryOpaqueFDDescriptor*>(this);
}

static_assert(sizeof(SharedTextureMemoryOpaqueFDDescriptor) == sizeof(WGPUSharedTextureMemoryOpaqueFDDescriptor), "sizeof mismatch for SharedTextureMemoryOpaqueFDDescriptor");
static_assert(alignof(SharedTextureMemoryOpaqueFDDescriptor) == alignof(WGPUSharedTextureMemoryOpaqueFDDescriptor), "alignof mismatch for SharedTextureMemoryOpaqueFDDescriptor");
static_assert(offsetof(SharedTextureMemoryOpaqueFDDescriptor, vkImageCreateInfo) == offsetof(WGPUSharedTextureMemoryOpaqueFDDescriptor, vkImageCreateInfo),
        "offsetof mismatch for SharedTextureMemoryOpaqueFDDescriptor::vkImageCreateInfo");
static_assert(offsetof(SharedTextureMemoryOpaqueFDDescriptor, memoryFD) == offsetof(WGPUSharedTextureMemoryOpaqueFDDescriptor, memoryFD),
        "offsetof mismatch for SharedTextureMemoryOpaqueFDDescriptor::memoryFD");
static_assert(offsetof(SharedTextureMemoryOpaqueFDDescriptor, memoryTypeIndex) == offsetof(WGPUSharedTextureMemoryOpaqueFDDescriptor, memoryTypeIndex),
        "offsetof mismatch for SharedTextureMemoryOpaqueFDDescriptor::memoryTypeIndex");
static_assert(offsetof(SharedTextureMemoryOpaqueFDDescriptor, allocationSize) == offsetof(WGPUSharedTextureMemoryOpaqueFDDescriptor, allocationSize),
        "offsetof mismatch for SharedTextureMemoryOpaqueFDDescriptor::allocationSize");
static_assert(offsetof(SharedTextureMemoryOpaqueFDDescriptor, dedicatedAllocation) == offsetof(WGPUSharedTextureMemoryOpaqueFDDescriptor, dedicatedAllocation),
        "offsetof mismatch for SharedTextureMemoryOpaqueFDDescriptor::dedicatedAllocation");

// SharedTextureMemoryVkDedicatedAllocationDescriptor implementation
SharedTextureMemoryVkDedicatedAllocationDescriptor::SharedTextureMemoryVkDedicatedAllocationDescriptor()
  : ChainedStruct { nullptr, SType::SharedTextureMemoryVkDedicatedAllocationDescriptor } {}
struct SharedTextureMemoryVkDedicatedAllocationDescriptor::Init {
    ChainedStruct * const nextInChain;
    Bool dedicatedAllocation;
};
SharedTextureMemoryVkDedicatedAllocationDescriptor::SharedTextureMemoryVkDedicatedAllocationDescriptor(SharedTextureMemoryVkDedicatedAllocationDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SharedTextureMemoryVkDedicatedAllocationDescriptor }, 
    dedicatedAllocation(std::move(init.dedicatedAllocation)){}

SharedTextureMemoryVkDedicatedAllocationDescriptor::operator const WGPUSharedTextureMemoryVkDedicatedAllocationDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryVkDedicatedAllocationDescriptor*>(this);
}

static_assert(sizeof(SharedTextureMemoryVkDedicatedAllocationDescriptor) == sizeof(WGPUSharedTextureMemoryVkDedicatedAllocationDescriptor), "sizeof mismatch for SharedTextureMemoryVkDedicatedAllocationDescriptor");
static_assert(alignof(SharedTextureMemoryVkDedicatedAllocationDescriptor) == alignof(WGPUSharedTextureMemoryVkDedicatedAllocationDescriptor), "alignof mismatch for SharedTextureMemoryVkDedicatedAllocationDescriptor");
static_assert(offsetof(SharedTextureMemoryVkDedicatedAllocationDescriptor, dedicatedAllocation) == offsetof(WGPUSharedTextureMemoryVkDedicatedAllocationDescriptor, dedicatedAllocation),
        "offsetof mismatch for SharedTextureMemoryVkDedicatedAllocationDescriptor::dedicatedAllocation");

// SharedTextureMemoryVkImageLayoutBeginState implementation
SharedTextureMemoryVkImageLayoutBeginState::SharedTextureMemoryVkImageLayoutBeginState()
  : ChainedStruct { nullptr, SType::SharedTextureMemoryVkImageLayoutBeginState } {}
struct SharedTextureMemoryVkImageLayoutBeginState::Init {
    ChainedStruct * const nextInChain;
    int32_t oldLayout;
    int32_t newLayout;
};
SharedTextureMemoryVkImageLayoutBeginState::SharedTextureMemoryVkImageLayoutBeginState(SharedTextureMemoryVkImageLayoutBeginState::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SharedTextureMemoryVkImageLayoutBeginState }, 
    oldLayout(std::move(init.oldLayout)), 
    newLayout(std::move(init.newLayout)){}

SharedTextureMemoryVkImageLayoutBeginState::operator const WGPUSharedTextureMemoryVkImageLayoutBeginState&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryVkImageLayoutBeginState*>(this);
}

static_assert(sizeof(SharedTextureMemoryVkImageLayoutBeginState) == sizeof(WGPUSharedTextureMemoryVkImageLayoutBeginState), "sizeof mismatch for SharedTextureMemoryVkImageLayoutBeginState");
static_assert(alignof(SharedTextureMemoryVkImageLayoutBeginState) == alignof(WGPUSharedTextureMemoryVkImageLayoutBeginState), "alignof mismatch for SharedTextureMemoryVkImageLayoutBeginState");
static_assert(offsetof(SharedTextureMemoryVkImageLayoutBeginState, oldLayout) == offsetof(WGPUSharedTextureMemoryVkImageLayoutBeginState, oldLayout),
        "offsetof mismatch for SharedTextureMemoryVkImageLayoutBeginState::oldLayout");
static_assert(offsetof(SharedTextureMemoryVkImageLayoutBeginState, newLayout) == offsetof(WGPUSharedTextureMemoryVkImageLayoutBeginState, newLayout),
        "offsetof mismatch for SharedTextureMemoryVkImageLayoutBeginState::newLayout");

// SharedTextureMemoryVkImageLayoutEndState implementation
SharedTextureMemoryVkImageLayoutEndState::SharedTextureMemoryVkImageLayoutEndState()
  : ChainedStructOut { nullptr, SType::SharedTextureMemoryVkImageLayoutEndState } {}
struct SharedTextureMemoryVkImageLayoutEndState::Init {
    ChainedStructOut *  nextInChain;
    int32_t oldLayout;
    int32_t newLayout;
};
SharedTextureMemoryVkImageLayoutEndState::SharedTextureMemoryVkImageLayoutEndState(SharedTextureMemoryVkImageLayoutEndState::Init&& init)
  : ChainedStructOut { init.nextInChain, SType::SharedTextureMemoryVkImageLayoutEndState }, 
    oldLayout(std::move(init.oldLayout)), 
    newLayout(std::move(init.newLayout)){}

SharedTextureMemoryVkImageLayoutEndState::operator const WGPUSharedTextureMemoryVkImageLayoutEndState&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryVkImageLayoutEndState*>(this);
}

static_assert(sizeof(SharedTextureMemoryVkImageLayoutEndState) == sizeof(WGPUSharedTextureMemoryVkImageLayoutEndState), "sizeof mismatch for SharedTextureMemoryVkImageLayoutEndState");
static_assert(alignof(SharedTextureMemoryVkImageLayoutEndState) == alignof(WGPUSharedTextureMemoryVkImageLayoutEndState), "alignof mismatch for SharedTextureMemoryVkImageLayoutEndState");
static_assert(offsetof(SharedTextureMemoryVkImageLayoutEndState, oldLayout) == offsetof(WGPUSharedTextureMemoryVkImageLayoutEndState, oldLayout),
        "offsetof mismatch for SharedTextureMemoryVkImageLayoutEndState::oldLayout");
static_assert(offsetof(SharedTextureMemoryVkImageLayoutEndState, newLayout) == offsetof(WGPUSharedTextureMemoryVkImageLayoutEndState, newLayout),
        "offsetof mismatch for SharedTextureMemoryVkImageLayoutEndState::newLayout");

// SharedTextureMemoryZirconHandleDescriptor implementation
SharedTextureMemoryZirconHandleDescriptor::SharedTextureMemoryZirconHandleDescriptor()
  : ChainedStruct { nullptr, SType::SharedTextureMemoryZirconHandleDescriptor } {}
struct SharedTextureMemoryZirconHandleDescriptor::Init {
    ChainedStruct * const nextInChain;
    uint32_t memoryFD;
    uint64_t allocationSize;
};
SharedTextureMemoryZirconHandleDescriptor::SharedTextureMemoryZirconHandleDescriptor(SharedTextureMemoryZirconHandleDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SharedTextureMemoryZirconHandleDescriptor }, 
    memoryFD(std::move(init.memoryFD)), 
    allocationSize(std::move(init.allocationSize)){}

SharedTextureMemoryZirconHandleDescriptor::operator const WGPUSharedTextureMemoryZirconHandleDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryZirconHandleDescriptor*>(this);
}

static_assert(sizeof(SharedTextureMemoryZirconHandleDescriptor) == sizeof(WGPUSharedTextureMemoryZirconHandleDescriptor), "sizeof mismatch for SharedTextureMemoryZirconHandleDescriptor");
static_assert(alignof(SharedTextureMemoryZirconHandleDescriptor) == alignof(WGPUSharedTextureMemoryZirconHandleDescriptor), "alignof mismatch for SharedTextureMemoryZirconHandleDescriptor");
static_assert(offsetof(SharedTextureMemoryZirconHandleDescriptor, memoryFD) == offsetof(WGPUSharedTextureMemoryZirconHandleDescriptor, memoryFD),
        "offsetof mismatch for SharedTextureMemoryZirconHandleDescriptor::memoryFD");
static_assert(offsetof(SharedTextureMemoryZirconHandleDescriptor, allocationSize) == offsetof(WGPUSharedTextureMemoryZirconHandleDescriptor, allocationSize),
        "offsetof mismatch for SharedTextureMemoryZirconHandleDescriptor::allocationSize");

// StaticSamplerBindingLayout implementation
StaticSamplerBindingLayout::StaticSamplerBindingLayout()
  : ChainedStruct { nullptr, SType::StaticSamplerBindingLayout } {}
struct StaticSamplerBindingLayout::Init {
    ChainedStruct * const nextInChain;
    Sampler sampler;
};
StaticSamplerBindingLayout::StaticSamplerBindingLayout(StaticSamplerBindingLayout::Init&& init)
  : ChainedStruct { init.nextInChain, SType::StaticSamplerBindingLayout }, 
    sampler(std::move(init.sampler)){}

StaticSamplerBindingLayout::operator const WGPUStaticSamplerBindingLayout&() const noexcept {
    return *reinterpret_cast<const WGPUStaticSamplerBindingLayout*>(this);
}

static_assert(sizeof(StaticSamplerBindingLayout) == sizeof(WGPUStaticSamplerBindingLayout), "sizeof mismatch for StaticSamplerBindingLayout");
static_assert(alignof(StaticSamplerBindingLayout) == alignof(WGPUStaticSamplerBindingLayout), "alignof mismatch for StaticSamplerBindingLayout");
static_assert(offsetof(StaticSamplerBindingLayout, sampler) == offsetof(WGPUStaticSamplerBindingLayout, sampler),
        "offsetof mismatch for StaticSamplerBindingLayout::sampler");

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
        wgpuDawnWireClientSurfaceCapabilitiesFreeMembers(
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

// SurfaceDescriptorFromAndroidNativeWindow implementation
SurfaceDescriptorFromAndroidNativeWindow::SurfaceDescriptorFromAndroidNativeWindow()
  : ChainedStruct { nullptr, SType::SurfaceDescriptorFromAndroidNativeWindow } {}
struct SurfaceDescriptorFromAndroidNativeWindow::Init {
    ChainedStruct * const nextInChain;
    void * window;
};
SurfaceDescriptorFromAndroidNativeWindow::SurfaceDescriptorFromAndroidNativeWindow(SurfaceDescriptorFromAndroidNativeWindow::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SurfaceDescriptorFromAndroidNativeWindow }, 
    window(std::move(init.window)){}

SurfaceDescriptorFromAndroidNativeWindow::operator const WGPUSurfaceDescriptorFromAndroidNativeWindow&() const noexcept {
    return *reinterpret_cast<const WGPUSurfaceDescriptorFromAndroidNativeWindow*>(this);
}

static_assert(sizeof(SurfaceDescriptorFromAndroidNativeWindow) == sizeof(WGPUSurfaceDescriptorFromAndroidNativeWindow), "sizeof mismatch for SurfaceDescriptorFromAndroidNativeWindow");
static_assert(alignof(SurfaceDescriptorFromAndroidNativeWindow) == alignof(WGPUSurfaceDescriptorFromAndroidNativeWindow), "alignof mismatch for SurfaceDescriptorFromAndroidNativeWindow");
static_assert(offsetof(SurfaceDescriptorFromAndroidNativeWindow, window) == offsetof(WGPUSurfaceDescriptorFromAndroidNativeWindow, window),
        "offsetof mismatch for SurfaceDescriptorFromAndroidNativeWindow::window");

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

// SurfaceDescriptorFromMetalLayer implementation
SurfaceDescriptorFromMetalLayer::SurfaceDescriptorFromMetalLayer()
  : ChainedStruct { nullptr, SType::SurfaceDescriptorFromMetalLayer } {}
struct SurfaceDescriptorFromMetalLayer::Init {
    ChainedStruct * const nextInChain;
    void * layer;
};
SurfaceDescriptorFromMetalLayer::SurfaceDescriptorFromMetalLayer(SurfaceDescriptorFromMetalLayer::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SurfaceDescriptorFromMetalLayer }, 
    layer(std::move(init.layer)){}

SurfaceDescriptorFromMetalLayer::operator const WGPUSurfaceDescriptorFromMetalLayer&() const noexcept {
    return *reinterpret_cast<const WGPUSurfaceDescriptorFromMetalLayer*>(this);
}

static_assert(sizeof(SurfaceDescriptorFromMetalLayer) == sizeof(WGPUSurfaceDescriptorFromMetalLayer), "sizeof mismatch for SurfaceDescriptorFromMetalLayer");
static_assert(alignof(SurfaceDescriptorFromMetalLayer) == alignof(WGPUSurfaceDescriptorFromMetalLayer), "alignof mismatch for SurfaceDescriptorFromMetalLayer");
static_assert(offsetof(SurfaceDescriptorFromMetalLayer, layer) == offsetof(WGPUSurfaceDescriptorFromMetalLayer, layer),
        "offsetof mismatch for SurfaceDescriptorFromMetalLayer::layer");

// SurfaceDescriptorFromWaylandSurface implementation
SurfaceDescriptorFromWaylandSurface::SurfaceDescriptorFromWaylandSurface()
  : ChainedStruct { nullptr, SType::SurfaceDescriptorFromWaylandSurface } {}
struct SurfaceDescriptorFromWaylandSurface::Init {
    ChainedStruct * const nextInChain;
    void * display;
    void * surface;
};
SurfaceDescriptorFromWaylandSurface::SurfaceDescriptorFromWaylandSurface(SurfaceDescriptorFromWaylandSurface::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SurfaceDescriptorFromWaylandSurface }, 
    display(std::move(init.display)), 
    surface(std::move(init.surface)){}

SurfaceDescriptorFromWaylandSurface::operator const WGPUSurfaceDescriptorFromWaylandSurface&() const noexcept {
    return *reinterpret_cast<const WGPUSurfaceDescriptorFromWaylandSurface*>(this);
}

static_assert(sizeof(SurfaceDescriptorFromWaylandSurface) == sizeof(WGPUSurfaceDescriptorFromWaylandSurface), "sizeof mismatch for SurfaceDescriptorFromWaylandSurface");
static_assert(alignof(SurfaceDescriptorFromWaylandSurface) == alignof(WGPUSurfaceDescriptorFromWaylandSurface), "alignof mismatch for SurfaceDescriptorFromWaylandSurface");
static_assert(offsetof(SurfaceDescriptorFromWaylandSurface, display) == offsetof(WGPUSurfaceDescriptorFromWaylandSurface, display),
        "offsetof mismatch for SurfaceDescriptorFromWaylandSurface::display");
static_assert(offsetof(SurfaceDescriptorFromWaylandSurface, surface) == offsetof(WGPUSurfaceDescriptorFromWaylandSurface, surface),
        "offsetof mismatch for SurfaceDescriptorFromWaylandSurface::surface");

// SurfaceDescriptorFromWindowsHWND implementation
SurfaceDescriptorFromWindowsHWND::SurfaceDescriptorFromWindowsHWND()
  : ChainedStruct { nullptr, SType::SurfaceDescriptorFromWindowsHWND } {}
struct SurfaceDescriptorFromWindowsHWND::Init {
    ChainedStruct * const nextInChain;
    void * hinstance;
    void * hwnd;
};
SurfaceDescriptorFromWindowsHWND::SurfaceDescriptorFromWindowsHWND(SurfaceDescriptorFromWindowsHWND::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SurfaceDescriptorFromWindowsHWND }, 
    hinstance(std::move(init.hinstance)), 
    hwnd(std::move(init.hwnd)){}

SurfaceDescriptorFromWindowsHWND::operator const WGPUSurfaceDescriptorFromWindowsHWND&() const noexcept {
    return *reinterpret_cast<const WGPUSurfaceDescriptorFromWindowsHWND*>(this);
}

static_assert(sizeof(SurfaceDescriptorFromWindowsHWND) == sizeof(WGPUSurfaceDescriptorFromWindowsHWND), "sizeof mismatch for SurfaceDescriptorFromWindowsHWND");
static_assert(alignof(SurfaceDescriptorFromWindowsHWND) == alignof(WGPUSurfaceDescriptorFromWindowsHWND), "alignof mismatch for SurfaceDescriptorFromWindowsHWND");
static_assert(offsetof(SurfaceDescriptorFromWindowsHWND, hinstance) == offsetof(WGPUSurfaceDescriptorFromWindowsHWND, hinstance),
        "offsetof mismatch for SurfaceDescriptorFromWindowsHWND::hinstance");
static_assert(offsetof(SurfaceDescriptorFromWindowsHWND, hwnd) == offsetof(WGPUSurfaceDescriptorFromWindowsHWND, hwnd),
        "offsetof mismatch for SurfaceDescriptorFromWindowsHWND::hwnd");

// SurfaceDescriptorFromWindowsCoreWindow implementation
SurfaceDescriptorFromWindowsCoreWindow::SurfaceDescriptorFromWindowsCoreWindow()
  : ChainedStruct { nullptr, SType::SurfaceDescriptorFromWindowsCoreWindow } {}
struct SurfaceDescriptorFromWindowsCoreWindow::Init {
    ChainedStruct * const nextInChain;
    void * coreWindow;
};
SurfaceDescriptorFromWindowsCoreWindow::SurfaceDescriptorFromWindowsCoreWindow(SurfaceDescriptorFromWindowsCoreWindow::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SurfaceDescriptorFromWindowsCoreWindow }, 
    coreWindow(std::move(init.coreWindow)){}

SurfaceDescriptorFromWindowsCoreWindow::operator const WGPUSurfaceDescriptorFromWindowsCoreWindow&() const noexcept {
    return *reinterpret_cast<const WGPUSurfaceDescriptorFromWindowsCoreWindow*>(this);
}

static_assert(sizeof(SurfaceDescriptorFromWindowsCoreWindow) == sizeof(WGPUSurfaceDescriptorFromWindowsCoreWindow), "sizeof mismatch for SurfaceDescriptorFromWindowsCoreWindow");
static_assert(alignof(SurfaceDescriptorFromWindowsCoreWindow) == alignof(WGPUSurfaceDescriptorFromWindowsCoreWindow), "alignof mismatch for SurfaceDescriptorFromWindowsCoreWindow");
static_assert(offsetof(SurfaceDescriptorFromWindowsCoreWindow, coreWindow) == offsetof(WGPUSurfaceDescriptorFromWindowsCoreWindow, coreWindow),
        "offsetof mismatch for SurfaceDescriptorFromWindowsCoreWindow::coreWindow");

// SurfaceDescriptorFromWindowsSwapChainPanel implementation
SurfaceDescriptorFromWindowsSwapChainPanel::SurfaceDescriptorFromWindowsSwapChainPanel()
  : ChainedStruct { nullptr, SType::SurfaceDescriptorFromWindowsSwapChainPanel } {}
struct SurfaceDescriptorFromWindowsSwapChainPanel::Init {
    ChainedStruct * const nextInChain;
    void * swapChainPanel;
};
SurfaceDescriptorFromWindowsSwapChainPanel::SurfaceDescriptorFromWindowsSwapChainPanel(SurfaceDescriptorFromWindowsSwapChainPanel::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SurfaceDescriptorFromWindowsSwapChainPanel }, 
    swapChainPanel(std::move(init.swapChainPanel)){}

SurfaceDescriptorFromWindowsSwapChainPanel::operator const WGPUSurfaceDescriptorFromWindowsSwapChainPanel&() const noexcept {
    return *reinterpret_cast<const WGPUSurfaceDescriptorFromWindowsSwapChainPanel*>(this);
}

static_assert(sizeof(SurfaceDescriptorFromWindowsSwapChainPanel) == sizeof(WGPUSurfaceDescriptorFromWindowsSwapChainPanel), "sizeof mismatch for SurfaceDescriptorFromWindowsSwapChainPanel");
static_assert(alignof(SurfaceDescriptorFromWindowsSwapChainPanel) == alignof(WGPUSurfaceDescriptorFromWindowsSwapChainPanel), "alignof mismatch for SurfaceDescriptorFromWindowsSwapChainPanel");
static_assert(offsetof(SurfaceDescriptorFromWindowsSwapChainPanel, swapChainPanel) == offsetof(WGPUSurfaceDescriptorFromWindowsSwapChainPanel, swapChainPanel),
        "offsetof mismatch for SurfaceDescriptorFromWindowsSwapChainPanel::swapChainPanel");

// SurfaceDescriptorFromXlibWindow implementation
SurfaceDescriptorFromXlibWindow::SurfaceDescriptorFromXlibWindow()
  : ChainedStruct { nullptr, SType::SurfaceDescriptorFromXlibWindow } {}
struct SurfaceDescriptorFromXlibWindow::Init {
    ChainedStruct * const nextInChain;
    void * display;
    uint64_t window;
};
SurfaceDescriptorFromXlibWindow::SurfaceDescriptorFromXlibWindow(SurfaceDescriptorFromXlibWindow::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SurfaceDescriptorFromXlibWindow }, 
    display(std::move(init.display)), 
    window(std::move(init.window)){}

SurfaceDescriptorFromXlibWindow::operator const WGPUSurfaceDescriptorFromXlibWindow&() const noexcept {
    return *reinterpret_cast<const WGPUSurfaceDescriptorFromXlibWindow*>(this);
}

static_assert(sizeof(SurfaceDescriptorFromXlibWindow) == sizeof(WGPUSurfaceDescriptorFromXlibWindow), "sizeof mismatch for SurfaceDescriptorFromXlibWindow");
static_assert(alignof(SurfaceDescriptorFromXlibWindow) == alignof(WGPUSurfaceDescriptorFromXlibWindow), "alignof mismatch for SurfaceDescriptorFromXlibWindow");
static_assert(offsetof(SurfaceDescriptorFromXlibWindow, display) == offsetof(WGPUSurfaceDescriptorFromXlibWindow, display),
        "offsetof mismatch for SurfaceDescriptorFromXlibWindow::display");
static_assert(offsetof(SurfaceDescriptorFromXlibWindow, window) == offsetof(WGPUSurfaceDescriptorFromXlibWindow, window),
        "offsetof mismatch for SurfaceDescriptorFromXlibWindow::window");

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

// YCbCrVkDescriptor implementation
YCbCrVkDescriptor::YCbCrVkDescriptor()
  : ChainedStruct { nullptr, SType::YCbCrVkDescriptor } {}
struct YCbCrVkDescriptor::Init {
    ChainedStruct * const nextInChain;
    uint32_t vkFormat = 0;
    uint32_t vkYCbCrModel = 0;
    uint32_t vkYCbCrRange = 0;
    uint32_t vkComponentSwizzleRed = 0;
    uint32_t vkComponentSwizzleGreen = 0;
    uint32_t vkComponentSwizzleBlue = 0;
    uint32_t vkComponentSwizzleAlpha = 0;
    uint32_t vkXChromaOffset = 0;
    uint32_t vkYChromaOffset = 0;
    FilterMode vkChromaFilter = FilterMode::Nearest;
    Bool forceExplicitReconstruction = false;
    uint64_t externalFormat = 0;
};
YCbCrVkDescriptor::YCbCrVkDescriptor(YCbCrVkDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::YCbCrVkDescriptor }, 
    vkFormat(std::move(init.vkFormat)), 
    vkYCbCrModel(std::move(init.vkYCbCrModel)), 
    vkYCbCrRange(std::move(init.vkYCbCrRange)), 
    vkComponentSwizzleRed(std::move(init.vkComponentSwizzleRed)), 
    vkComponentSwizzleGreen(std::move(init.vkComponentSwizzleGreen)), 
    vkComponentSwizzleBlue(std::move(init.vkComponentSwizzleBlue)), 
    vkComponentSwizzleAlpha(std::move(init.vkComponentSwizzleAlpha)), 
    vkXChromaOffset(std::move(init.vkXChromaOffset)), 
    vkYChromaOffset(std::move(init.vkYChromaOffset)), 
    vkChromaFilter(std::move(init.vkChromaFilter)), 
    forceExplicitReconstruction(std::move(init.forceExplicitReconstruction)), 
    externalFormat(std::move(init.externalFormat)){}

YCbCrVkDescriptor::operator const WGPUYCbCrVkDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUYCbCrVkDescriptor*>(this);
}

static_assert(sizeof(YCbCrVkDescriptor) == sizeof(WGPUYCbCrVkDescriptor), "sizeof mismatch for YCbCrVkDescriptor");
static_assert(alignof(YCbCrVkDescriptor) == alignof(WGPUYCbCrVkDescriptor), "alignof mismatch for YCbCrVkDescriptor");
static_assert(offsetof(YCbCrVkDescriptor, vkFormat) == offsetof(WGPUYCbCrVkDescriptor, vkFormat),
        "offsetof mismatch for YCbCrVkDescriptor::vkFormat");
static_assert(offsetof(YCbCrVkDescriptor, vkYCbCrModel) == offsetof(WGPUYCbCrVkDescriptor, vkYCbCrModel),
        "offsetof mismatch for YCbCrVkDescriptor::vkYCbCrModel");
static_assert(offsetof(YCbCrVkDescriptor, vkYCbCrRange) == offsetof(WGPUYCbCrVkDescriptor, vkYCbCrRange),
        "offsetof mismatch for YCbCrVkDescriptor::vkYCbCrRange");
static_assert(offsetof(YCbCrVkDescriptor, vkComponentSwizzleRed) == offsetof(WGPUYCbCrVkDescriptor, vkComponentSwizzleRed),
        "offsetof mismatch for YCbCrVkDescriptor::vkComponentSwizzleRed");
static_assert(offsetof(YCbCrVkDescriptor, vkComponentSwizzleGreen) == offsetof(WGPUYCbCrVkDescriptor, vkComponentSwizzleGreen),
        "offsetof mismatch for YCbCrVkDescriptor::vkComponentSwizzleGreen");
static_assert(offsetof(YCbCrVkDescriptor, vkComponentSwizzleBlue) == offsetof(WGPUYCbCrVkDescriptor, vkComponentSwizzleBlue),
        "offsetof mismatch for YCbCrVkDescriptor::vkComponentSwizzleBlue");
static_assert(offsetof(YCbCrVkDescriptor, vkComponentSwizzleAlpha) == offsetof(WGPUYCbCrVkDescriptor, vkComponentSwizzleAlpha),
        "offsetof mismatch for YCbCrVkDescriptor::vkComponentSwizzleAlpha");
static_assert(offsetof(YCbCrVkDescriptor, vkXChromaOffset) == offsetof(WGPUYCbCrVkDescriptor, vkXChromaOffset),
        "offsetof mismatch for YCbCrVkDescriptor::vkXChromaOffset");
static_assert(offsetof(YCbCrVkDescriptor, vkYChromaOffset) == offsetof(WGPUYCbCrVkDescriptor, vkYChromaOffset),
        "offsetof mismatch for YCbCrVkDescriptor::vkYChromaOffset");
static_assert(offsetof(YCbCrVkDescriptor, vkChromaFilter) == offsetof(WGPUYCbCrVkDescriptor, vkChromaFilter),
        "offsetof mismatch for YCbCrVkDescriptor::vkChromaFilter");
static_assert(offsetof(YCbCrVkDescriptor, forceExplicitReconstruction) == offsetof(WGPUYCbCrVkDescriptor, forceExplicitReconstruction),
        "offsetof mismatch for YCbCrVkDescriptor::forceExplicitReconstruction");
static_assert(offsetof(YCbCrVkDescriptor, externalFormat) == offsetof(WGPUYCbCrVkDescriptor, externalFormat),
        "offsetof mismatch for YCbCrVkDescriptor::externalFormat");

// AHardwareBufferProperties implementation

AHardwareBufferProperties::operator const WGPUAHardwareBufferProperties&() const noexcept {
    return *reinterpret_cast<const WGPUAHardwareBufferProperties*>(this);
}

static_assert(sizeof(AHardwareBufferProperties) == sizeof(WGPUAHardwareBufferProperties), "sizeof mismatch for AHardwareBufferProperties");
static_assert(alignof(AHardwareBufferProperties) == alignof(WGPUAHardwareBufferProperties), "alignof mismatch for AHardwareBufferProperties");
static_assert(offsetof(AHardwareBufferProperties, yCbCrInfo) == offsetof(WGPUAHardwareBufferProperties, yCbCrInfo),
        "offsetof mismatch for AHardwareBufferProperties::yCbCrInfo");

// AdapterPropertiesMemoryHeaps implementation
AdapterPropertiesMemoryHeaps::AdapterPropertiesMemoryHeaps()
  : ChainedStructOut { nullptr, SType::AdapterPropertiesMemoryHeaps } {}
struct AdapterPropertiesMemoryHeaps::Init {
    ChainedStructOut *  nextInChain;
    size_t const heapCount = {};
    MemoryHeapInfo const * const heapInfo = {};
};
AdapterPropertiesMemoryHeaps::AdapterPropertiesMemoryHeaps(AdapterPropertiesMemoryHeaps::Init&& init)
  : ChainedStructOut { init.nextInChain, SType::AdapterPropertiesMemoryHeaps }, 
    heapCount(std::move(init.heapCount)), 
    heapInfo(std::move(init.heapInfo)){}
AdapterPropertiesMemoryHeaps::~AdapterPropertiesMemoryHeaps() {
    if (this->heapInfo != nullptr) {
        wgpuDawnWireClientAdapterPropertiesMemoryHeapsFreeMembers(
            *reinterpret_cast<WGPUAdapterPropertiesMemoryHeaps*>(this));
    }
}

AdapterPropertiesMemoryHeaps::AdapterPropertiesMemoryHeaps(AdapterPropertiesMemoryHeaps&& rhs)
    : heapCount(rhs.heapCount),
            heapInfo(rhs.heapInfo){
    Reset(rhs);
}

AdapterPropertiesMemoryHeaps& AdapterPropertiesMemoryHeaps::operator=(AdapterPropertiesMemoryHeaps&& rhs) {
    if (&rhs == this) {
        return *this;
    }
    this->~AdapterPropertiesMemoryHeaps();
    detail::AsNonConstReference(this->heapCount) = std::move(rhs.heapCount);
    detail::AsNonConstReference(this->heapInfo) = std::move(rhs.heapInfo);
    Reset(rhs);
    return *this;
}

    // static
void AdapterPropertiesMemoryHeaps::Reset(AdapterPropertiesMemoryHeaps& value) {
    AdapterPropertiesMemoryHeaps defaultValue{};
    detail::AsNonConstReference(value.heapCount) = defaultValue.heapCount;
    detail::AsNonConstReference(value.heapInfo) = defaultValue.heapInfo;
}

AdapterPropertiesMemoryHeaps::operator const WGPUAdapterPropertiesMemoryHeaps&() const noexcept {
    return *reinterpret_cast<const WGPUAdapterPropertiesMemoryHeaps*>(this);
}

static_assert(sizeof(AdapterPropertiesMemoryHeaps) == sizeof(WGPUAdapterPropertiesMemoryHeaps), "sizeof mismatch for AdapterPropertiesMemoryHeaps");
static_assert(alignof(AdapterPropertiesMemoryHeaps) == alignof(WGPUAdapterPropertiesMemoryHeaps), "alignof mismatch for AdapterPropertiesMemoryHeaps");
static_assert(offsetof(AdapterPropertiesMemoryHeaps, heapCount) == offsetof(WGPUAdapterPropertiesMemoryHeaps, heapCount),
        "offsetof mismatch for AdapterPropertiesMemoryHeaps::heapCount");
static_assert(offsetof(AdapterPropertiesMemoryHeaps, heapInfo) == offsetof(WGPUAdapterPropertiesMemoryHeaps, heapInfo),
        "offsetof mismatch for AdapterPropertiesMemoryHeaps::heapInfo");

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

// DrmFormatCapabilities implementation
DrmFormatCapabilities::DrmFormatCapabilities()
  : ChainedStructOut { nullptr, SType::DrmFormatCapabilities } {}
struct DrmFormatCapabilities::Init {
    ChainedStructOut *  nextInChain;
    size_t const propertiesCount = {};
    DrmFormatProperties const * const properties = {};
};
DrmFormatCapabilities::DrmFormatCapabilities(DrmFormatCapabilities::Init&& init)
  : ChainedStructOut { init.nextInChain, SType::DrmFormatCapabilities }, 
    propertiesCount(std::move(init.propertiesCount)), 
    properties(std::move(init.properties)){}
DrmFormatCapabilities::~DrmFormatCapabilities() {
    if (this->properties != nullptr) {
        wgpuDawnWireClientDrmFormatCapabilitiesFreeMembers(
            *reinterpret_cast<WGPUDrmFormatCapabilities*>(this));
    }
}

DrmFormatCapabilities::DrmFormatCapabilities(DrmFormatCapabilities&& rhs)
    : propertiesCount(rhs.propertiesCount),
            properties(rhs.properties){
    Reset(rhs);
}

DrmFormatCapabilities& DrmFormatCapabilities::operator=(DrmFormatCapabilities&& rhs) {
    if (&rhs == this) {
        return *this;
    }
    this->~DrmFormatCapabilities();
    detail::AsNonConstReference(this->propertiesCount) = std::move(rhs.propertiesCount);
    detail::AsNonConstReference(this->properties) = std::move(rhs.properties);
    Reset(rhs);
    return *this;
}

    // static
void DrmFormatCapabilities::Reset(DrmFormatCapabilities& value) {
    DrmFormatCapabilities defaultValue{};
    detail::AsNonConstReference(value.propertiesCount) = defaultValue.propertiesCount;
    detail::AsNonConstReference(value.properties) = defaultValue.properties;
}

DrmFormatCapabilities::operator const WGPUDrmFormatCapabilities&() const noexcept {
    return *reinterpret_cast<const WGPUDrmFormatCapabilities*>(this);
}

static_assert(sizeof(DrmFormatCapabilities) == sizeof(WGPUDrmFormatCapabilities), "sizeof mismatch for DrmFormatCapabilities");
static_assert(alignof(DrmFormatCapabilities) == alignof(WGPUDrmFormatCapabilities), "alignof mismatch for DrmFormatCapabilities");
static_assert(offsetof(DrmFormatCapabilities, propertiesCount) == offsetof(WGPUDrmFormatCapabilities, propertiesCount),
        "offsetof mismatch for DrmFormatCapabilities::propertiesCount");
static_assert(offsetof(DrmFormatCapabilities, properties) == offsetof(WGPUDrmFormatCapabilities, properties),
        "offsetof mismatch for DrmFormatCapabilities::properties");

// ExternalTextureDescriptor implementation

ExternalTextureDescriptor::operator const WGPUExternalTextureDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUExternalTextureDescriptor*>(this);
}

static_assert(sizeof(ExternalTextureDescriptor) == sizeof(WGPUExternalTextureDescriptor), "sizeof mismatch for ExternalTextureDescriptor");
static_assert(alignof(ExternalTextureDescriptor) == alignof(WGPUExternalTextureDescriptor), "alignof mismatch for ExternalTextureDescriptor");
static_assert(offsetof(ExternalTextureDescriptor, nextInChain) == offsetof(WGPUExternalTextureDescriptor, nextInChain),
        "offsetof mismatch for ExternalTextureDescriptor::nextInChain");
static_assert(offsetof(ExternalTextureDescriptor, label) == offsetof(WGPUExternalTextureDescriptor, label),
        "offsetof mismatch for ExternalTextureDescriptor::label");
static_assert(offsetof(ExternalTextureDescriptor, plane0) == offsetof(WGPUExternalTextureDescriptor, plane0),
        "offsetof mismatch for ExternalTextureDescriptor::plane0");
static_assert(offsetof(ExternalTextureDescriptor, plane1) == offsetof(WGPUExternalTextureDescriptor, plane1),
        "offsetof mismatch for ExternalTextureDescriptor::plane1");
static_assert(offsetof(ExternalTextureDescriptor, visibleOrigin) == offsetof(WGPUExternalTextureDescriptor, visibleOrigin),
        "offsetof mismatch for ExternalTextureDescriptor::visibleOrigin");
static_assert(offsetof(ExternalTextureDescriptor, visibleSize) == offsetof(WGPUExternalTextureDescriptor, visibleSize),
        "offsetof mismatch for ExternalTextureDescriptor::visibleSize");
static_assert(offsetof(ExternalTextureDescriptor, doYuvToRgbConversionOnly) == offsetof(WGPUExternalTextureDescriptor, doYuvToRgbConversionOnly),
        "offsetof mismatch for ExternalTextureDescriptor::doYuvToRgbConversionOnly");
static_assert(offsetof(ExternalTextureDescriptor, yuvToRgbConversionMatrix) == offsetof(WGPUExternalTextureDescriptor, yuvToRgbConversionMatrix),
        "offsetof mismatch for ExternalTextureDescriptor::yuvToRgbConversionMatrix");
static_assert(offsetof(ExternalTextureDescriptor, srcTransferFunctionParameters) == offsetof(WGPUExternalTextureDescriptor, srcTransferFunctionParameters),
        "offsetof mismatch for ExternalTextureDescriptor::srcTransferFunctionParameters");
static_assert(offsetof(ExternalTextureDescriptor, dstTransferFunctionParameters) == offsetof(WGPUExternalTextureDescriptor, dstTransferFunctionParameters),
        "offsetof mismatch for ExternalTextureDescriptor::dstTransferFunctionParameters");
static_assert(offsetof(ExternalTextureDescriptor, gamutConversionMatrix) == offsetof(WGPUExternalTextureDescriptor, gamutConversionMatrix),
        "offsetof mismatch for ExternalTextureDescriptor::gamutConversionMatrix");
static_assert(offsetof(ExternalTextureDescriptor, mirrored) == offsetof(WGPUExternalTextureDescriptor, mirrored),
        "offsetof mismatch for ExternalTextureDescriptor::mirrored");
static_assert(offsetof(ExternalTextureDescriptor, rotation) == offsetof(WGPUExternalTextureDescriptor, rotation),
        "offsetof mismatch for ExternalTextureDescriptor::rotation");

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

// ImageCopyExternalTexture implementation

ImageCopyExternalTexture::operator const WGPUImageCopyExternalTexture&() const noexcept {
    return *reinterpret_cast<const WGPUImageCopyExternalTexture*>(this);
}

static_assert(sizeof(ImageCopyExternalTexture) == sizeof(WGPUImageCopyExternalTexture), "sizeof mismatch for ImageCopyExternalTexture");
static_assert(alignof(ImageCopyExternalTexture) == alignof(WGPUImageCopyExternalTexture), "alignof mismatch for ImageCopyExternalTexture");
static_assert(offsetof(ImageCopyExternalTexture, nextInChain) == offsetof(WGPUImageCopyExternalTexture, nextInChain),
        "offsetof mismatch for ImageCopyExternalTexture::nextInChain");
static_assert(offsetof(ImageCopyExternalTexture, externalTexture) == offsetof(WGPUImageCopyExternalTexture, externalTexture),
        "offsetof mismatch for ImageCopyExternalTexture::externalTexture");
static_assert(offsetof(ImageCopyExternalTexture, origin) == offsetof(WGPUImageCopyExternalTexture, origin),
        "offsetof mismatch for ImageCopyExternalTexture::origin");
static_assert(offsetof(ImageCopyExternalTexture, naturalSize) == offsetof(WGPUImageCopyExternalTexture, naturalSize),
        "offsetof mismatch for ImageCopyExternalTexture::naturalSize");

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

// PipelineLayoutPixelLocalStorage implementation
PipelineLayoutPixelLocalStorage::PipelineLayoutPixelLocalStorage()
  : ChainedStruct { nullptr, SType::PipelineLayoutPixelLocalStorage } {}
struct PipelineLayoutPixelLocalStorage::Init {
    ChainedStruct * const nextInChain;
    uint64_t totalPixelLocalStorageSize;
    size_t storageAttachmentCount = 0;
    PipelineLayoutStorageAttachment const * storageAttachments;
};
PipelineLayoutPixelLocalStorage::PipelineLayoutPixelLocalStorage(PipelineLayoutPixelLocalStorage::Init&& init)
  : ChainedStruct { init.nextInChain, SType::PipelineLayoutPixelLocalStorage }, 
    totalPixelLocalStorageSize(std::move(init.totalPixelLocalStorageSize)), 
    storageAttachmentCount(std::move(init.storageAttachmentCount)), 
    storageAttachments(std::move(init.storageAttachments)){}

PipelineLayoutPixelLocalStorage::operator const WGPUPipelineLayoutPixelLocalStorage&() const noexcept {
    return *reinterpret_cast<const WGPUPipelineLayoutPixelLocalStorage*>(this);
}

static_assert(sizeof(PipelineLayoutPixelLocalStorage) == sizeof(WGPUPipelineLayoutPixelLocalStorage), "sizeof mismatch for PipelineLayoutPixelLocalStorage");
static_assert(alignof(PipelineLayoutPixelLocalStorage) == alignof(WGPUPipelineLayoutPixelLocalStorage), "alignof mismatch for PipelineLayoutPixelLocalStorage");
static_assert(offsetof(PipelineLayoutPixelLocalStorage, totalPixelLocalStorageSize) == offsetof(WGPUPipelineLayoutPixelLocalStorage, totalPixelLocalStorageSize),
        "offsetof mismatch for PipelineLayoutPixelLocalStorage::totalPixelLocalStorageSize");
static_assert(offsetof(PipelineLayoutPixelLocalStorage, storageAttachmentCount) == offsetof(WGPUPipelineLayoutPixelLocalStorage, storageAttachmentCount),
        "offsetof mismatch for PipelineLayoutPixelLocalStorage::storageAttachmentCount");
static_assert(offsetof(PipelineLayoutPixelLocalStorage, storageAttachments) == offsetof(WGPUPipelineLayoutPixelLocalStorage, storageAttachments),
        "offsetof mismatch for PipelineLayoutPixelLocalStorage::storageAttachments");

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

// RenderPassStorageAttachment implementation

RenderPassStorageAttachment::operator const WGPURenderPassStorageAttachment&() const noexcept {
    return *reinterpret_cast<const WGPURenderPassStorageAttachment*>(this);
}

static_assert(sizeof(RenderPassStorageAttachment) == sizeof(WGPURenderPassStorageAttachment), "sizeof mismatch for RenderPassStorageAttachment");
static_assert(alignof(RenderPassStorageAttachment) == alignof(WGPURenderPassStorageAttachment), "alignof mismatch for RenderPassStorageAttachment");
static_assert(offsetof(RenderPassStorageAttachment, nextInChain) == offsetof(WGPURenderPassStorageAttachment, nextInChain),
        "offsetof mismatch for RenderPassStorageAttachment::nextInChain");
static_assert(offsetof(RenderPassStorageAttachment, offset) == offsetof(WGPURenderPassStorageAttachment, offset),
        "offsetof mismatch for RenderPassStorageAttachment::offset");
static_assert(offsetof(RenderPassStorageAttachment, storage) == offsetof(WGPURenderPassStorageAttachment, storage),
        "offsetof mismatch for RenderPassStorageAttachment::storage");
static_assert(offsetof(RenderPassStorageAttachment, loadOp) == offsetof(WGPURenderPassStorageAttachment, loadOp),
        "offsetof mismatch for RenderPassStorageAttachment::loadOp");
static_assert(offsetof(RenderPassStorageAttachment, storeOp) == offsetof(WGPURenderPassStorageAttachment, storeOp),
        "offsetof mismatch for RenderPassStorageAttachment::storeOp");
static_assert(offsetof(RenderPassStorageAttachment, clearValue) == offsetof(WGPURenderPassStorageAttachment, clearValue),
        "offsetof mismatch for RenderPassStorageAttachment::clearValue");

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

// SharedTextureMemoryAHardwareBufferProperties implementation
SharedTextureMemoryAHardwareBufferProperties::SharedTextureMemoryAHardwareBufferProperties()
  : ChainedStructOut { nullptr, SType::SharedTextureMemoryAHardwareBufferProperties } {}
struct SharedTextureMemoryAHardwareBufferProperties::Init {
    ChainedStructOut *  nextInChain;
    YCbCrVkDescriptor yCbCrInfo;
};
SharedTextureMemoryAHardwareBufferProperties::SharedTextureMemoryAHardwareBufferProperties(SharedTextureMemoryAHardwareBufferProperties::Init&& init)
  : ChainedStructOut { init.nextInChain, SType::SharedTextureMemoryAHardwareBufferProperties }, 
    yCbCrInfo(std::move(init.yCbCrInfo)){}

SharedTextureMemoryAHardwareBufferProperties::operator const WGPUSharedTextureMemoryAHardwareBufferProperties&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryAHardwareBufferProperties*>(this);
}

static_assert(sizeof(SharedTextureMemoryAHardwareBufferProperties) == sizeof(WGPUSharedTextureMemoryAHardwareBufferProperties), "sizeof mismatch for SharedTextureMemoryAHardwareBufferProperties");
static_assert(alignof(SharedTextureMemoryAHardwareBufferProperties) == alignof(WGPUSharedTextureMemoryAHardwareBufferProperties), "alignof mismatch for SharedTextureMemoryAHardwareBufferProperties");
static_assert(offsetof(SharedTextureMemoryAHardwareBufferProperties, yCbCrInfo) == offsetof(WGPUSharedTextureMemoryAHardwareBufferProperties, yCbCrInfo),
        "offsetof mismatch for SharedTextureMemoryAHardwareBufferProperties::yCbCrInfo");

// SharedTextureMemoryDmaBufDescriptor implementation
SharedTextureMemoryDmaBufDescriptor::SharedTextureMemoryDmaBufDescriptor()
  : ChainedStruct { nullptr, SType::SharedTextureMemoryDmaBufDescriptor } {}
struct SharedTextureMemoryDmaBufDescriptor::Init {
    ChainedStruct * const nextInChain;
    Extent3D size;
    uint32_t drmFormat;
    uint64_t drmModifier;
    size_t planeCount;
    SharedTextureMemoryDmaBufPlane const * planes;
};
SharedTextureMemoryDmaBufDescriptor::SharedTextureMemoryDmaBufDescriptor(SharedTextureMemoryDmaBufDescriptor::Init&& init)
  : ChainedStruct { init.nextInChain, SType::SharedTextureMemoryDmaBufDescriptor }, 
    size(std::move(init.size)), 
    drmFormat(std::move(init.drmFormat)), 
    drmModifier(std::move(init.drmModifier)), 
    planeCount(std::move(init.planeCount)), 
    planes(std::move(init.planes)){}

SharedTextureMemoryDmaBufDescriptor::operator const WGPUSharedTextureMemoryDmaBufDescriptor&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryDmaBufDescriptor*>(this);
}

static_assert(sizeof(SharedTextureMemoryDmaBufDescriptor) == sizeof(WGPUSharedTextureMemoryDmaBufDescriptor), "sizeof mismatch for SharedTextureMemoryDmaBufDescriptor");
static_assert(alignof(SharedTextureMemoryDmaBufDescriptor) == alignof(WGPUSharedTextureMemoryDmaBufDescriptor), "alignof mismatch for SharedTextureMemoryDmaBufDescriptor");
static_assert(offsetof(SharedTextureMemoryDmaBufDescriptor, size) == offsetof(WGPUSharedTextureMemoryDmaBufDescriptor, size),
        "offsetof mismatch for SharedTextureMemoryDmaBufDescriptor::size");
static_assert(offsetof(SharedTextureMemoryDmaBufDescriptor, drmFormat) == offsetof(WGPUSharedTextureMemoryDmaBufDescriptor, drmFormat),
        "offsetof mismatch for SharedTextureMemoryDmaBufDescriptor::drmFormat");
static_assert(offsetof(SharedTextureMemoryDmaBufDescriptor, drmModifier) == offsetof(WGPUSharedTextureMemoryDmaBufDescriptor, drmModifier),
        "offsetof mismatch for SharedTextureMemoryDmaBufDescriptor::drmModifier");
static_assert(offsetof(SharedTextureMemoryDmaBufDescriptor, planeCount) == offsetof(WGPUSharedTextureMemoryDmaBufDescriptor, planeCount),
        "offsetof mismatch for SharedTextureMemoryDmaBufDescriptor::planeCount");
static_assert(offsetof(SharedTextureMemoryDmaBufDescriptor, planes) == offsetof(WGPUSharedTextureMemoryDmaBufDescriptor, planes),
        "offsetof mismatch for SharedTextureMemoryDmaBufDescriptor::planes");

// SharedTextureMemoryProperties implementation

SharedTextureMemoryProperties::operator const WGPUSharedTextureMemoryProperties&() const noexcept {
    return *reinterpret_cast<const WGPUSharedTextureMemoryProperties*>(this);
}

static_assert(sizeof(SharedTextureMemoryProperties) == sizeof(WGPUSharedTextureMemoryProperties), "sizeof mismatch for SharedTextureMemoryProperties");
static_assert(alignof(SharedTextureMemoryProperties) == alignof(WGPUSharedTextureMemoryProperties), "alignof mismatch for SharedTextureMemoryProperties");
static_assert(offsetof(SharedTextureMemoryProperties, nextInChain) == offsetof(WGPUSharedTextureMemoryProperties, nextInChain),
        "offsetof mismatch for SharedTextureMemoryProperties::nextInChain");
static_assert(offsetof(SharedTextureMemoryProperties, usage) == offsetof(WGPUSharedTextureMemoryProperties, usage),
        "offsetof mismatch for SharedTextureMemoryProperties::usage");
static_assert(offsetof(SharedTextureMemoryProperties, size) == offsetof(WGPUSharedTextureMemoryProperties, size),
        "offsetof mismatch for SharedTextureMemoryProperties::size");
static_assert(offsetof(SharedTextureMemoryProperties, format) == offsetof(WGPUSharedTextureMemoryProperties, format),
        "offsetof mismatch for SharedTextureMemoryProperties::format");

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
static_assert(offsetof(DeviceDescriptor, deviceLostCallback) == offsetof(WGPUDeviceDescriptor, deviceLostCallback),
        "offsetof mismatch for DeviceDescriptor::deviceLostCallback");
static_assert(offsetof(DeviceDescriptor, deviceLostUserdata) == offsetof(WGPUDeviceDescriptor, deviceLostUserdata),
        "offsetof mismatch for DeviceDescriptor::deviceLostUserdata");
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

// RenderPassPixelLocalStorage implementation
RenderPassPixelLocalStorage::RenderPassPixelLocalStorage()
  : ChainedStruct { nullptr, SType::RenderPassPixelLocalStorage } {}
struct RenderPassPixelLocalStorage::Init {
    ChainedStruct * const nextInChain;
    uint64_t totalPixelLocalStorageSize;
    size_t storageAttachmentCount = 0;
    RenderPassStorageAttachment const * storageAttachments;
};
RenderPassPixelLocalStorage::RenderPassPixelLocalStorage(RenderPassPixelLocalStorage::Init&& init)
  : ChainedStruct { init.nextInChain, SType::RenderPassPixelLocalStorage }, 
    totalPixelLocalStorageSize(std::move(init.totalPixelLocalStorageSize)), 
    storageAttachmentCount(std::move(init.storageAttachmentCount)), 
    storageAttachments(std::move(init.storageAttachments)){}

RenderPassPixelLocalStorage::operator const WGPURenderPassPixelLocalStorage&() const noexcept {
    return *reinterpret_cast<const WGPURenderPassPixelLocalStorage*>(this);
}

static_assert(sizeof(RenderPassPixelLocalStorage) == sizeof(WGPURenderPassPixelLocalStorage), "sizeof mismatch for RenderPassPixelLocalStorage");
static_assert(alignof(RenderPassPixelLocalStorage) == alignof(WGPURenderPassPixelLocalStorage), "alignof mismatch for RenderPassPixelLocalStorage");
static_assert(offsetof(RenderPassPixelLocalStorage, totalPixelLocalStorageSize) == offsetof(WGPURenderPassPixelLocalStorage, totalPixelLocalStorageSize),
        "offsetof mismatch for RenderPassPixelLocalStorage::totalPixelLocalStorageSize");
static_assert(offsetof(RenderPassPixelLocalStorage, storageAttachmentCount) == offsetof(WGPURenderPassPixelLocalStorage, storageAttachmentCount),
        "offsetof mismatch for RenderPassPixelLocalStorage::storageAttachmentCount");
static_assert(offsetof(RenderPassPixelLocalStorage, storageAttachments) == offsetof(WGPURenderPassPixelLocalStorage, storageAttachments),
        "offsetof mismatch for RenderPassPixelLocalStorage::storageAttachments");

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

Device Adapter::CreateDevice(DeviceDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientAdapterCreateDevice(Get(), reinterpret_cast<WGPUDeviceDescriptor const * >(descriptor));
    return Device::Acquire(result);
}
size_t Adapter::EnumerateFeatures(FeatureName * features) const {
    auto result = wgpuDawnWireClientAdapterEnumerateFeatures(Get(), reinterpret_cast<WGPUFeatureName * >(features));
    return result;
}
ConvertibleStatus Adapter::GetFormatCapabilities(TextureFormat format, FormatCapabilities * capabilities) const {
    auto result = wgpuDawnWireClientAdapterGetFormatCapabilities(Get(), static_cast<WGPUTextureFormat>(format), reinterpret_cast<WGPUFormatCapabilities * >(capabilities));
    return static_cast<Status>(result);
}
ConvertibleStatus Adapter::GetInfo(AdapterInfo * info) const {
    *info = AdapterInfo();
    auto result = wgpuDawnWireClientAdapterGetInfo(Get(), reinterpret_cast<WGPUAdapterInfo * >(info));
    return static_cast<Status>(result);
}
Instance Adapter::GetInstance() const {
    auto result = wgpuDawnWireClientAdapterGetInstance(Get());
    return Instance::Acquire(result);
}
ConvertibleStatus Adapter::GetLimits(SupportedLimits * limits) const {
    auto result = wgpuDawnWireClientAdapterGetLimits(Get(), reinterpret_cast<WGPUSupportedLimits * >(limits));
    return static_cast<Status>(result);
}
ConvertibleStatus Adapter::GetProperties(AdapterProperties * properties) const {
    *properties = AdapterProperties();
    auto result = wgpuDawnWireClientAdapterGetProperties(Get(), reinterpret_cast<WGPUAdapterProperties * >(properties));
    return static_cast<Status>(result);
}
Bool Adapter::HasFeature(FeatureName feature) const {
    auto result = wgpuDawnWireClientAdapterHasFeature(Get(), static_cast<WGPUFeatureName>(feature));
    return result;
}
void Adapter::RequestDevice(DeviceDescriptor const * descriptor, RequestDeviceCallback callback, void * userdata) const {
    wgpuDawnWireClientAdapterRequestDevice(Get(), reinterpret_cast<WGPUDeviceDescriptor const * >(descriptor), callback, userdata);
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
    auto result = wgpuDawnWireClientAdapterRequestDevice2(Get(), reinterpret_cast<WGPUDeviceDescriptor const * >(options), callbackInfo);
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
        auto result = wgpuDawnWireClientAdapterRequestDevice2(Get(), reinterpret_cast<WGPUDeviceDescriptor const * >(options), callbackInfo);
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
        auto result = wgpuDawnWireClientAdapterRequestDevice2(Get(), reinterpret_cast<WGPUDeviceDescriptor const * >(options), callbackInfo);
        return Future {
            result.id
        };
    }
}
Future Adapter::RequestDevice(DeviceDescriptor const * options, RequestDeviceCallbackInfo callbackInfo) const {
    auto result = wgpuDawnWireClientAdapterRequestDeviceF(Get(), reinterpret_cast<WGPUDeviceDescriptor const * >(options), *reinterpret_cast<WGPURequestDeviceCallbackInfo const*>(&callbackInfo));
    return Future {
            result.id
        };
}
void Adapter::WGPUAddRef(WGPUAdapter handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientAdapterAddRef(handle);
    }
}
void Adapter::WGPURelease(WGPUAdapter handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientAdapterRelease(handle);
    }
}
static_assert(sizeof(Adapter) == sizeof(WGPUAdapter), "sizeof mismatch for Adapter");
static_assert(alignof(Adapter) == alignof(WGPUAdapter), "alignof mismatch for Adapter");

// BindGroup implementation

void BindGroup::SetLabel(char const * label) const {
    wgpuDawnWireClientBindGroupSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void BindGroup::WGPUAddRef(WGPUBindGroup handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientBindGroupAddRef(handle);
    }
}
void BindGroup::WGPURelease(WGPUBindGroup handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientBindGroupRelease(handle);
    }
}
static_assert(sizeof(BindGroup) == sizeof(WGPUBindGroup), "sizeof mismatch for BindGroup");
static_assert(alignof(BindGroup) == alignof(WGPUBindGroup), "alignof mismatch for BindGroup");

// BindGroupLayout implementation

void BindGroupLayout::SetLabel(char const * label) const {
    wgpuDawnWireClientBindGroupLayoutSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void BindGroupLayout::WGPUAddRef(WGPUBindGroupLayout handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientBindGroupLayoutAddRef(handle);
    }
}
void BindGroupLayout::WGPURelease(WGPUBindGroupLayout handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientBindGroupLayoutRelease(handle);
    }
}
static_assert(sizeof(BindGroupLayout) == sizeof(WGPUBindGroupLayout), "sizeof mismatch for BindGroupLayout");
static_assert(alignof(BindGroupLayout) == alignof(WGPUBindGroupLayout), "alignof mismatch for BindGroupLayout");

// Buffer implementation

void Buffer::Destroy() const {
    wgpuDawnWireClientBufferDestroy(Get());
}
void const * Buffer::GetConstMappedRange(size_t offset, size_t size) const {
    auto result = wgpuDawnWireClientBufferGetConstMappedRange(Get(), offset, size);
    return result;
}
BufferMapState Buffer::GetMapState() const {
    auto result = wgpuDawnWireClientBufferGetMapState(Get());
    return static_cast<BufferMapState>(result);
}
void * Buffer::GetMappedRange(size_t offset, size_t size) const {
    auto result = wgpuDawnWireClientBufferGetMappedRange(Get(), offset, size);
    return result;
}
uint64_t Buffer::GetSize() const {
    auto result = wgpuDawnWireClientBufferGetSize(Get());
    return result;
}
BufferUsage Buffer::GetUsage() const {
    auto result = wgpuDawnWireClientBufferGetUsage(Get());
    return static_cast<BufferUsage>(result);
}
void Buffer::MapAsync(MapMode mode, size_t offset, size_t size, BufferMapCallback callback, void * userdata) const {
    wgpuDawnWireClientBufferMapAsync(Get(), static_cast<WGPUMapMode>(mode), offset, size, callback, userdata);
}
Future Buffer::MapAsync(MapMode mode, size_t offset, size_t size, BufferMapCallbackInfo callbackInfo) const {
    auto result = wgpuDawnWireClientBufferMapAsyncF(Get(), static_cast<WGPUMapMode>(mode), offset, size, *reinterpret_cast<WGPUBufferMapCallbackInfo const*>(&callbackInfo));
    return Future {
            result.id
        };
}
void Buffer::SetLabel(char const * label) const {
    wgpuDawnWireClientBufferSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void Buffer::Unmap() const {
    wgpuDawnWireClientBufferUnmap(Get());
}
void Buffer::WGPUAddRef(WGPUBuffer handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientBufferAddRef(handle);
    }
}
void Buffer::WGPURelease(WGPUBuffer handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientBufferRelease(handle);
    }
}
static_assert(sizeof(Buffer) == sizeof(WGPUBuffer), "sizeof mismatch for Buffer");
static_assert(alignof(Buffer) == alignof(WGPUBuffer), "alignof mismatch for Buffer");

// CommandBuffer implementation

void CommandBuffer::SetLabel(char const * label) const {
    wgpuDawnWireClientCommandBufferSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void CommandBuffer::WGPUAddRef(WGPUCommandBuffer handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientCommandBufferAddRef(handle);
    }
}
void CommandBuffer::WGPURelease(WGPUCommandBuffer handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientCommandBufferRelease(handle);
    }
}
static_assert(sizeof(CommandBuffer) == sizeof(WGPUCommandBuffer), "sizeof mismatch for CommandBuffer");
static_assert(alignof(CommandBuffer) == alignof(WGPUCommandBuffer), "alignof mismatch for CommandBuffer");

// CommandEncoder implementation

ComputePassEncoder CommandEncoder::BeginComputePass(ComputePassDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientCommandEncoderBeginComputePass(Get(), reinterpret_cast<WGPUComputePassDescriptor const * >(descriptor));
    return ComputePassEncoder::Acquire(result);
}
RenderPassEncoder CommandEncoder::BeginRenderPass(RenderPassDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientCommandEncoderBeginRenderPass(Get(), reinterpret_cast<WGPURenderPassDescriptor const * >(descriptor));
    return RenderPassEncoder::Acquire(result);
}
void CommandEncoder::ClearBuffer(Buffer const& buffer, uint64_t offset, uint64_t size) const {
    wgpuDawnWireClientCommandEncoderClearBuffer(Get(), buffer.Get(), offset, size);
}
void CommandEncoder::CopyBufferToBuffer(Buffer const& source, uint64_t sourceOffset, Buffer const& destination, uint64_t destinationOffset, uint64_t size) const {
    wgpuDawnWireClientCommandEncoderCopyBufferToBuffer(Get(), source.Get(), sourceOffset, destination.Get(), destinationOffset, size);
}
void CommandEncoder::CopyBufferToTexture(ImageCopyBuffer const * source, ImageCopyTexture const * destination, Extent3D const * copySize) const {
    wgpuDawnWireClientCommandEncoderCopyBufferToTexture(Get(), reinterpret_cast<WGPUImageCopyBuffer const * >(source), reinterpret_cast<WGPUImageCopyTexture const * >(destination), reinterpret_cast<WGPUExtent3D const * >(copySize));
}
void CommandEncoder::CopyTextureToBuffer(ImageCopyTexture const * source, ImageCopyBuffer const * destination, Extent3D const * copySize) const {
    wgpuDawnWireClientCommandEncoderCopyTextureToBuffer(Get(), reinterpret_cast<WGPUImageCopyTexture const * >(source), reinterpret_cast<WGPUImageCopyBuffer const * >(destination), reinterpret_cast<WGPUExtent3D const * >(copySize));
}
void CommandEncoder::CopyTextureToTexture(ImageCopyTexture const * source, ImageCopyTexture const * destination, Extent3D const * copySize) const {
    wgpuDawnWireClientCommandEncoderCopyTextureToTexture(Get(), reinterpret_cast<WGPUImageCopyTexture const * >(source), reinterpret_cast<WGPUImageCopyTexture const * >(destination), reinterpret_cast<WGPUExtent3D const * >(copySize));
}
CommandBuffer CommandEncoder::Finish(CommandBufferDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientCommandEncoderFinish(Get(), reinterpret_cast<WGPUCommandBufferDescriptor const * >(descriptor));
    return CommandBuffer::Acquire(result);
}
void CommandEncoder::InjectValidationError(char const * message) const {
    wgpuDawnWireClientCommandEncoderInjectValidationError(Get(), reinterpret_cast<char const * >(message));
}
void CommandEncoder::InsertDebugMarker(char const * markerLabel) const {
    wgpuDawnWireClientCommandEncoderInsertDebugMarker(Get(), reinterpret_cast<char const * >(markerLabel));
}
void CommandEncoder::PopDebugGroup() const {
    wgpuDawnWireClientCommandEncoderPopDebugGroup(Get());
}
void CommandEncoder::PushDebugGroup(char const * groupLabel) const {
    wgpuDawnWireClientCommandEncoderPushDebugGroup(Get(), reinterpret_cast<char const * >(groupLabel));
}
void CommandEncoder::ResolveQuerySet(QuerySet const& querySet, uint32_t firstQuery, uint32_t queryCount, Buffer const& destination, uint64_t destinationOffset) const {
    wgpuDawnWireClientCommandEncoderResolveQuerySet(Get(), querySet.Get(), firstQuery, queryCount, destination.Get(), destinationOffset);
}
void CommandEncoder::SetLabel(char const * label) const {
    wgpuDawnWireClientCommandEncoderSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void CommandEncoder::WriteBuffer(Buffer const& buffer, uint64_t bufferOffset, uint8_t const * data, uint64_t size) const {
    wgpuDawnWireClientCommandEncoderWriteBuffer(Get(), buffer.Get(), bufferOffset, reinterpret_cast<uint8_t const * >(data), size);
}
void CommandEncoder::WriteTimestamp(QuerySet const& querySet, uint32_t queryIndex) const {
    wgpuDawnWireClientCommandEncoderWriteTimestamp(Get(), querySet.Get(), queryIndex);
}
void CommandEncoder::WGPUAddRef(WGPUCommandEncoder handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientCommandEncoderAddRef(handle);
    }
}
void CommandEncoder::WGPURelease(WGPUCommandEncoder handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientCommandEncoderRelease(handle);
    }
}
static_assert(sizeof(CommandEncoder) == sizeof(WGPUCommandEncoder), "sizeof mismatch for CommandEncoder");
static_assert(alignof(CommandEncoder) == alignof(WGPUCommandEncoder), "alignof mismatch for CommandEncoder");

// ComputePassEncoder implementation

void ComputePassEncoder::DispatchWorkgroups(uint32_t workgroupCountX, uint32_t workgroupCountY, uint32_t workgroupCountZ) const {
    wgpuDawnWireClientComputePassEncoderDispatchWorkgroups(Get(), workgroupCountX, workgroupCountY, workgroupCountZ);
}
void ComputePassEncoder::DispatchWorkgroupsIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const {
    wgpuDawnWireClientComputePassEncoderDispatchWorkgroupsIndirect(Get(), indirectBuffer.Get(), indirectOffset);
}
void ComputePassEncoder::End() const {
    wgpuDawnWireClientComputePassEncoderEnd(Get());
}
void ComputePassEncoder::InsertDebugMarker(char const * markerLabel) const {
    wgpuDawnWireClientComputePassEncoderInsertDebugMarker(Get(), reinterpret_cast<char const * >(markerLabel));
}
void ComputePassEncoder::PopDebugGroup() const {
    wgpuDawnWireClientComputePassEncoderPopDebugGroup(Get());
}
void ComputePassEncoder::PushDebugGroup(char const * groupLabel) const {
    wgpuDawnWireClientComputePassEncoderPushDebugGroup(Get(), reinterpret_cast<char const * >(groupLabel));
}
void ComputePassEncoder::SetBindGroup(uint32_t groupIndex, BindGroup const& group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) const {
    wgpuDawnWireClientComputePassEncoderSetBindGroup(Get(), groupIndex, group.Get(), dynamicOffsetCount, reinterpret_cast<uint32_t const * >(dynamicOffsets));
}
void ComputePassEncoder::SetLabel(char const * label) const {
    wgpuDawnWireClientComputePassEncoderSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void ComputePassEncoder::SetPipeline(ComputePipeline const& pipeline) const {
    wgpuDawnWireClientComputePassEncoderSetPipeline(Get(), pipeline.Get());
}
void ComputePassEncoder::WriteTimestamp(QuerySet const& querySet, uint32_t queryIndex) const {
    wgpuDawnWireClientComputePassEncoderWriteTimestamp(Get(), querySet.Get(), queryIndex);
}
void ComputePassEncoder::WGPUAddRef(WGPUComputePassEncoder handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientComputePassEncoderAddRef(handle);
    }
}
void ComputePassEncoder::WGPURelease(WGPUComputePassEncoder handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientComputePassEncoderRelease(handle);
    }
}
static_assert(sizeof(ComputePassEncoder) == sizeof(WGPUComputePassEncoder), "sizeof mismatch for ComputePassEncoder");
static_assert(alignof(ComputePassEncoder) == alignof(WGPUComputePassEncoder), "alignof mismatch for ComputePassEncoder");

// ComputePipeline implementation

BindGroupLayout ComputePipeline::GetBindGroupLayout(uint32_t groupIndex) const {
    auto result = wgpuDawnWireClientComputePipelineGetBindGroupLayout(Get(), groupIndex);
    return BindGroupLayout::Acquire(result);
}
void ComputePipeline::SetLabel(char const * label) const {
    wgpuDawnWireClientComputePipelineSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void ComputePipeline::WGPUAddRef(WGPUComputePipeline handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientComputePipelineAddRef(handle);
    }
}
void ComputePipeline::WGPURelease(WGPUComputePipeline handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientComputePipelineRelease(handle);
    }
}
static_assert(sizeof(ComputePipeline) == sizeof(WGPUComputePipeline), "sizeof mismatch for ComputePipeline");
static_assert(alignof(ComputePipeline) == alignof(WGPUComputePipeline), "alignof mismatch for ComputePipeline");

// Device implementation

BindGroup Device::CreateBindGroup(BindGroupDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceCreateBindGroup(Get(), reinterpret_cast<WGPUBindGroupDescriptor const * >(descriptor));
    return BindGroup::Acquire(result);
}
BindGroupLayout Device::CreateBindGroupLayout(BindGroupLayoutDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceCreateBindGroupLayout(Get(), reinterpret_cast<WGPUBindGroupLayoutDescriptor const * >(descriptor));
    return BindGroupLayout::Acquire(result);
}
Buffer Device::CreateBuffer(BufferDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceCreateBuffer(Get(), reinterpret_cast<WGPUBufferDescriptor const * >(descriptor));
    return Buffer::Acquire(result);
}
CommandEncoder Device::CreateCommandEncoder(CommandEncoderDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceCreateCommandEncoder(Get(), reinterpret_cast<WGPUCommandEncoderDescriptor const * >(descriptor));
    return CommandEncoder::Acquire(result);
}
ComputePipeline Device::CreateComputePipeline(ComputePipelineDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceCreateComputePipeline(Get(), reinterpret_cast<WGPUComputePipelineDescriptor const * >(descriptor));
    return ComputePipeline::Acquire(result);
}
void Device::CreateComputePipelineAsync(ComputePipelineDescriptor const * descriptor, CreateComputePipelineAsyncCallback callback, void * userdata) const {
    wgpuDawnWireClientDeviceCreateComputePipelineAsync(Get(), reinterpret_cast<WGPUComputePipelineDescriptor const * >(descriptor), callback, userdata);
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
    auto result = wgpuDawnWireClientDeviceCreateComputePipelineAsync2(Get(), reinterpret_cast<WGPUComputePipelineDescriptor const * >(descriptor), callbackInfo);
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
        auto result = wgpuDawnWireClientDeviceCreateComputePipelineAsync2(Get(), reinterpret_cast<WGPUComputePipelineDescriptor const * >(descriptor), callbackInfo);
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
        auto result = wgpuDawnWireClientDeviceCreateComputePipelineAsync2(Get(), reinterpret_cast<WGPUComputePipelineDescriptor const * >(descriptor), callbackInfo);
        return Future {
            result.id
        };
    }
}
Future Device::CreateComputePipelineAsync(ComputePipelineDescriptor const * descriptor, CreateComputePipelineAsyncCallbackInfo callbackInfo) const {
    auto result = wgpuDawnWireClientDeviceCreateComputePipelineAsyncF(Get(), reinterpret_cast<WGPUComputePipelineDescriptor const * >(descriptor), *reinterpret_cast<WGPUCreateComputePipelineAsyncCallbackInfo const*>(&callbackInfo));
    return Future {
            result.id
        };
}
Buffer Device::CreateErrorBuffer(BufferDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceCreateErrorBuffer(Get(), reinterpret_cast<WGPUBufferDescriptor const * >(descriptor));
    return Buffer::Acquire(result);
}
ExternalTexture Device::CreateErrorExternalTexture() const {
    auto result = wgpuDawnWireClientDeviceCreateErrorExternalTexture(Get());
    return ExternalTexture::Acquire(result);
}
ShaderModule Device::CreateErrorShaderModule(ShaderModuleDescriptor const * descriptor, char const * errorMessage) const {
    auto result = wgpuDawnWireClientDeviceCreateErrorShaderModule(Get(), reinterpret_cast<WGPUShaderModuleDescriptor const * >(descriptor), reinterpret_cast<char const * >(errorMessage));
    return ShaderModule::Acquire(result);
}
Texture Device::CreateErrorTexture(TextureDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceCreateErrorTexture(Get(), reinterpret_cast<WGPUTextureDescriptor const * >(descriptor));
    return Texture::Acquire(result);
}
ExternalTexture Device::CreateExternalTexture(ExternalTextureDescriptor const * externalTextureDescriptor) const {
    auto result = wgpuDawnWireClientDeviceCreateExternalTexture(Get(), reinterpret_cast<WGPUExternalTextureDescriptor const * >(externalTextureDescriptor));
    return ExternalTexture::Acquire(result);
}
PipelineLayout Device::CreatePipelineLayout(PipelineLayoutDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceCreatePipelineLayout(Get(), reinterpret_cast<WGPUPipelineLayoutDescriptor const * >(descriptor));
    return PipelineLayout::Acquire(result);
}
QuerySet Device::CreateQuerySet(QuerySetDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceCreateQuerySet(Get(), reinterpret_cast<WGPUQuerySetDescriptor const * >(descriptor));
    return QuerySet::Acquire(result);
}
RenderBundleEncoder Device::CreateRenderBundleEncoder(RenderBundleEncoderDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceCreateRenderBundleEncoder(Get(), reinterpret_cast<WGPURenderBundleEncoderDescriptor const * >(descriptor));
    return RenderBundleEncoder::Acquire(result);
}
RenderPipeline Device::CreateRenderPipeline(RenderPipelineDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceCreateRenderPipeline(Get(), reinterpret_cast<WGPURenderPipelineDescriptor const * >(descriptor));
    return RenderPipeline::Acquire(result);
}
void Device::CreateRenderPipelineAsync(RenderPipelineDescriptor const * descriptor, CreateRenderPipelineAsyncCallback callback, void * userdata) const {
    wgpuDawnWireClientDeviceCreateRenderPipelineAsync(Get(), reinterpret_cast<WGPURenderPipelineDescriptor const * >(descriptor), callback, userdata);
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
    auto result = wgpuDawnWireClientDeviceCreateRenderPipelineAsync2(Get(), reinterpret_cast<WGPURenderPipelineDescriptor const * >(descriptor), callbackInfo);
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
        auto result = wgpuDawnWireClientDeviceCreateRenderPipelineAsync2(Get(), reinterpret_cast<WGPURenderPipelineDescriptor const * >(descriptor), callbackInfo);
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
        auto result = wgpuDawnWireClientDeviceCreateRenderPipelineAsync2(Get(), reinterpret_cast<WGPURenderPipelineDescriptor const * >(descriptor), callbackInfo);
        return Future {
            result.id
        };
    }
}
Future Device::CreateRenderPipelineAsync(RenderPipelineDescriptor const * descriptor, CreateRenderPipelineAsyncCallbackInfo callbackInfo) const {
    auto result = wgpuDawnWireClientDeviceCreateRenderPipelineAsyncF(Get(), reinterpret_cast<WGPURenderPipelineDescriptor const * >(descriptor), *reinterpret_cast<WGPUCreateRenderPipelineAsyncCallbackInfo const*>(&callbackInfo));
    return Future {
            result.id
        };
}
Sampler Device::CreateSampler(SamplerDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceCreateSampler(Get(), reinterpret_cast<WGPUSamplerDescriptor const * >(descriptor));
    return Sampler::Acquire(result);
}
ShaderModule Device::CreateShaderModule(ShaderModuleDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceCreateShaderModule(Get(), reinterpret_cast<WGPUShaderModuleDescriptor const * >(descriptor));
    return ShaderModule::Acquire(result);
}
SwapChain Device::CreateSwapChain(Surface const& surface, SwapChainDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceCreateSwapChain(Get(), surface.Get(), reinterpret_cast<WGPUSwapChainDescriptor const * >(descriptor));
    return SwapChain::Acquire(result);
}
Texture Device::CreateTexture(TextureDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceCreateTexture(Get(), reinterpret_cast<WGPUTextureDescriptor const * >(descriptor));
    return Texture::Acquire(result);
}
void Device::Destroy() const {
    wgpuDawnWireClientDeviceDestroy(Get());
}
size_t Device::EnumerateFeatures(FeatureName * features) const {
    auto result = wgpuDawnWireClientDeviceEnumerateFeatures(Get(), reinterpret_cast<WGPUFeatureName * >(features));
    return result;
}
void Device::ForceLoss(DeviceLostReason type, char const * message) const {
    wgpuDawnWireClientDeviceForceLoss(Get(), static_cast<WGPUDeviceLostReason>(type), reinterpret_cast<char const * >(message));
}
ConvertibleStatus Device::GetAHardwareBufferProperties(void * handle, AHardwareBufferProperties * properties) const {
    auto result = wgpuDawnWireClientDeviceGetAHardwareBufferProperties(Get(), handle, reinterpret_cast<WGPUAHardwareBufferProperties * >(properties));
    return static_cast<Status>(result);
}
Adapter Device::GetAdapter() const {
    auto result = wgpuDawnWireClientDeviceGetAdapter(Get());
    return Adapter::Acquire(result);
}
ConvertibleStatus Device::GetLimits(SupportedLimits * limits) const {
    auto result = wgpuDawnWireClientDeviceGetLimits(Get(), reinterpret_cast<WGPUSupportedLimits * >(limits));
    return static_cast<Status>(result);
}
Queue Device::GetQueue() const {
    auto result = wgpuDawnWireClientDeviceGetQueue(Get());
    return Queue::Acquire(result);
}
TextureUsage Device::GetSupportedSurfaceUsage(Surface const& surface) const {
    auto result = wgpuDawnWireClientDeviceGetSupportedSurfaceUsage(Get(), surface.Get());
    return static_cast<TextureUsage>(result);
}
Bool Device::HasFeature(FeatureName feature) const {
    auto result = wgpuDawnWireClientDeviceHasFeature(Get(), static_cast<WGPUFeatureName>(feature));
    return result;
}
SharedBufferMemory Device::ImportSharedBufferMemory(SharedBufferMemoryDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceImportSharedBufferMemory(Get(), reinterpret_cast<WGPUSharedBufferMemoryDescriptor const * >(descriptor));
    return SharedBufferMemory::Acquire(result);
}
SharedFence Device::ImportSharedFence(SharedFenceDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceImportSharedFence(Get(), reinterpret_cast<WGPUSharedFenceDescriptor const * >(descriptor));
    return SharedFence::Acquire(result);
}
SharedTextureMemory Device::ImportSharedTextureMemory(SharedTextureMemoryDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientDeviceImportSharedTextureMemory(Get(), reinterpret_cast<WGPUSharedTextureMemoryDescriptor const * >(descriptor));
    return SharedTextureMemory::Acquire(result);
}
void Device::InjectError(ErrorType type, char const * message) const {
    wgpuDawnWireClientDeviceInjectError(Get(), static_cast<WGPUErrorType>(type), reinterpret_cast<char const * >(message));
}
void Device::PopErrorScope(ErrorCallback oldCallback, void * userdata) const {
    wgpuDawnWireClientDevicePopErrorScope(Get(), oldCallback, userdata);
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
    auto result = wgpuDawnWireClientDevicePopErrorScope2(Get(), callbackInfo);
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
        auto result = wgpuDawnWireClientDevicePopErrorScope2(Get(), callbackInfo);
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
        auto result = wgpuDawnWireClientDevicePopErrorScope2(Get(), callbackInfo);
        return Future {
            result.id
        };
    }
}
Future Device::PopErrorScope(PopErrorScopeCallbackInfo callbackInfo) const {
    auto result = wgpuDawnWireClientDevicePopErrorScopeF(Get(), *reinterpret_cast<WGPUPopErrorScopeCallbackInfo const*>(&callbackInfo));
    return Future {
            result.id
        };
}
void Device::PushErrorScope(ErrorFilter filter) const {
    wgpuDawnWireClientDevicePushErrorScope(Get(), static_cast<WGPUErrorFilter>(filter));
}
void Device::SetDeviceLostCallback(DeviceLostCallback callback, void * userdata) const {
    wgpuDawnWireClientDeviceSetDeviceLostCallback(Get(), callback, userdata);
}
void Device::SetLabel(char const * label) const {
    wgpuDawnWireClientDeviceSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void Device::SetLoggingCallback(LoggingCallback callback, void * userdata) const {
    wgpuDawnWireClientDeviceSetLoggingCallback(Get(), callback, userdata);
}
void Device::SetUncapturedErrorCallback(ErrorCallback callback, void * userdata) const {
    wgpuDawnWireClientDeviceSetUncapturedErrorCallback(Get(), callback, userdata);
}
void Device::Tick() const {
    wgpuDawnWireClientDeviceTick(Get());
}
void Device::ValidateTextureDescriptor(TextureDescriptor const * descriptor) const {
    wgpuDawnWireClientDeviceValidateTextureDescriptor(Get(), reinterpret_cast<WGPUTextureDescriptor const * >(descriptor));
}
void Device::WGPUAddRef(WGPUDevice handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientDeviceAddRef(handle);
    }
}
void Device::WGPURelease(WGPUDevice handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientDeviceRelease(handle);
    }
}
static_assert(sizeof(Device) == sizeof(WGPUDevice), "sizeof mismatch for Device");
static_assert(alignof(Device) == alignof(WGPUDevice), "alignof mismatch for Device");

// ExternalTexture implementation

void ExternalTexture::Destroy() const {
    wgpuDawnWireClientExternalTextureDestroy(Get());
}
void ExternalTexture::Expire() const {
    wgpuDawnWireClientExternalTextureExpire(Get());
}
void ExternalTexture::Refresh() const {
    wgpuDawnWireClientExternalTextureRefresh(Get());
}
void ExternalTexture::SetLabel(char const * label) const {
    wgpuDawnWireClientExternalTextureSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void ExternalTexture::WGPUAddRef(WGPUExternalTexture handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientExternalTextureAddRef(handle);
    }
}
void ExternalTexture::WGPURelease(WGPUExternalTexture handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientExternalTextureRelease(handle);
    }
}
static_assert(sizeof(ExternalTexture) == sizeof(WGPUExternalTexture), "sizeof mismatch for ExternalTexture");
static_assert(alignof(ExternalTexture) == alignof(WGPUExternalTexture), "alignof mismatch for ExternalTexture");

// Instance implementation

Surface Instance::CreateSurface(SurfaceDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientInstanceCreateSurface(Get(), reinterpret_cast<WGPUSurfaceDescriptor const * >(descriptor));
    return Surface::Acquire(result);
}
size_t Instance::EnumerateWGSLLanguageFeatures(WGSLFeatureName * features) const {
    auto result = wgpuDawnWireClientInstanceEnumerateWGSLLanguageFeatures(Get(), reinterpret_cast<WGPUWGSLFeatureName * >(features));
    return result;
}
Bool Instance::HasWGSLLanguageFeature(WGSLFeatureName feature) const {
    auto result = wgpuDawnWireClientInstanceHasWGSLLanguageFeature(Get(), static_cast<WGPUWGSLFeatureName>(feature));
    return result;
}
void Instance::ProcessEvents() const {
    wgpuDawnWireClientInstanceProcessEvents(Get());
}
void Instance::RequestAdapter(RequestAdapterOptions const * options, RequestAdapterCallback callback, void * userdata) const {
    wgpuDawnWireClientInstanceRequestAdapter(Get(), reinterpret_cast<WGPURequestAdapterOptions const * >(options), callback, userdata);
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
    auto result = wgpuDawnWireClientInstanceRequestAdapter2(Get(), reinterpret_cast<WGPURequestAdapterOptions const * >(options), callbackInfo);
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
        auto result = wgpuDawnWireClientInstanceRequestAdapter2(Get(), reinterpret_cast<WGPURequestAdapterOptions const * >(options), callbackInfo);
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
        auto result = wgpuDawnWireClientInstanceRequestAdapter2(Get(), reinterpret_cast<WGPURequestAdapterOptions const * >(options), callbackInfo);
        return Future {
            result.id
        };
    }
}
Future Instance::RequestAdapter(RequestAdapterOptions const * options, RequestAdapterCallbackInfo callbackInfo) const {
    auto result = wgpuDawnWireClientInstanceRequestAdapterF(Get(), reinterpret_cast<WGPURequestAdapterOptions const * >(options), *reinterpret_cast<WGPURequestAdapterCallbackInfo const*>(&callbackInfo));
    return Future {
            result.id
        };
}
WaitStatus Instance::WaitAny(size_t futureCount, FutureWaitInfo * futures, uint64_t timeoutNS) const {
    auto result = wgpuDawnWireClientInstanceWaitAny(Get(), futureCount, reinterpret_cast<WGPUFutureWaitInfo * >(futures), timeoutNS);
    return static_cast<WaitStatus>(result);
}
void Instance::WGPUAddRef(WGPUInstance handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientInstanceAddRef(handle);
    }
}
void Instance::WGPURelease(WGPUInstance handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientInstanceRelease(handle);
    }
}
static_assert(sizeof(Instance) == sizeof(WGPUInstance), "sizeof mismatch for Instance");
static_assert(alignof(Instance) == alignof(WGPUInstance), "alignof mismatch for Instance");

// PipelineLayout implementation

void PipelineLayout::SetLabel(char const * label) const {
    wgpuDawnWireClientPipelineLayoutSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void PipelineLayout::WGPUAddRef(WGPUPipelineLayout handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientPipelineLayoutAddRef(handle);
    }
}
void PipelineLayout::WGPURelease(WGPUPipelineLayout handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientPipelineLayoutRelease(handle);
    }
}
static_assert(sizeof(PipelineLayout) == sizeof(WGPUPipelineLayout), "sizeof mismatch for PipelineLayout");
static_assert(alignof(PipelineLayout) == alignof(WGPUPipelineLayout), "alignof mismatch for PipelineLayout");

// QuerySet implementation

void QuerySet::Destroy() const {
    wgpuDawnWireClientQuerySetDestroy(Get());
}
uint32_t QuerySet::GetCount() const {
    auto result = wgpuDawnWireClientQuerySetGetCount(Get());
    return result;
}
QueryType QuerySet::GetType() const {
    auto result = wgpuDawnWireClientQuerySetGetType(Get());
    return static_cast<QueryType>(result);
}
void QuerySet::SetLabel(char const * label) const {
    wgpuDawnWireClientQuerySetSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void QuerySet::WGPUAddRef(WGPUQuerySet handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientQuerySetAddRef(handle);
    }
}
void QuerySet::WGPURelease(WGPUQuerySet handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientQuerySetRelease(handle);
    }
}
static_assert(sizeof(QuerySet) == sizeof(WGPUQuerySet), "sizeof mismatch for QuerySet");
static_assert(alignof(QuerySet) == alignof(WGPUQuerySet), "alignof mismatch for QuerySet");

// Queue implementation

void Queue::CopyExternalTextureForBrowser(ImageCopyExternalTexture const * source, ImageCopyTexture const * destination, Extent3D const * copySize, CopyTextureForBrowserOptions const * options) const {
    wgpuDawnWireClientQueueCopyExternalTextureForBrowser(Get(), reinterpret_cast<WGPUImageCopyExternalTexture const * >(source), reinterpret_cast<WGPUImageCopyTexture const * >(destination), reinterpret_cast<WGPUExtent3D const * >(copySize), reinterpret_cast<WGPUCopyTextureForBrowserOptions const * >(options));
}
void Queue::CopyTextureForBrowser(ImageCopyTexture const * source, ImageCopyTexture const * destination, Extent3D const * copySize, CopyTextureForBrowserOptions const * options) const {
    wgpuDawnWireClientQueueCopyTextureForBrowser(Get(), reinterpret_cast<WGPUImageCopyTexture const * >(source), reinterpret_cast<WGPUImageCopyTexture const * >(destination), reinterpret_cast<WGPUExtent3D const * >(copySize), reinterpret_cast<WGPUCopyTextureForBrowserOptions const * >(options));
}
void Queue::OnSubmittedWorkDone(QueueWorkDoneCallback callback, void * userdata) const {
    wgpuDawnWireClientQueueOnSubmittedWorkDone(Get(), callback, userdata);
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
    auto result = wgpuDawnWireClientQueueOnSubmittedWorkDone2(Get(), callbackInfo);
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
        auto result = wgpuDawnWireClientQueueOnSubmittedWorkDone2(Get(), callbackInfo);
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
        auto result = wgpuDawnWireClientQueueOnSubmittedWorkDone2(Get(), callbackInfo);
        return Future {
            result.id
        };
    }
}
Future Queue::OnSubmittedWorkDone(QueueWorkDoneCallbackInfo callbackInfo) const {
    auto result = wgpuDawnWireClientQueueOnSubmittedWorkDoneF(Get(), *reinterpret_cast<WGPUQueueWorkDoneCallbackInfo const*>(&callbackInfo));
    return Future {
            result.id
        };
}
void Queue::SetLabel(char const * label) const {
    wgpuDawnWireClientQueueSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void Queue::Submit(size_t commandCount, CommandBuffer const * commands) const {
    wgpuDawnWireClientQueueSubmit(Get(), commandCount, reinterpret_cast<WGPUCommandBuffer const * >(commands));
}
void Queue::WriteBuffer(Buffer const& buffer, uint64_t bufferOffset, void const * data, size_t size) const {
    wgpuDawnWireClientQueueWriteBuffer(Get(), buffer.Get(), bufferOffset, reinterpret_cast<void const * >(data), size);
}
void Queue::WriteTexture(ImageCopyTexture const * destination, void const * data, size_t dataSize, TextureDataLayout const * dataLayout, Extent3D const * writeSize) const {
    wgpuDawnWireClientQueueWriteTexture(Get(), reinterpret_cast<WGPUImageCopyTexture const * >(destination), reinterpret_cast<void const * >(data), dataSize, reinterpret_cast<WGPUTextureDataLayout const * >(dataLayout), reinterpret_cast<WGPUExtent3D const * >(writeSize));
}
void Queue::WGPUAddRef(WGPUQueue handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientQueueAddRef(handle);
    }
}
void Queue::WGPURelease(WGPUQueue handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientQueueRelease(handle);
    }
}
static_assert(sizeof(Queue) == sizeof(WGPUQueue), "sizeof mismatch for Queue");
static_assert(alignof(Queue) == alignof(WGPUQueue), "alignof mismatch for Queue");

// RenderBundle implementation

void RenderBundle::SetLabel(char const * label) const {
    wgpuDawnWireClientRenderBundleSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void RenderBundle::WGPUAddRef(WGPURenderBundle handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientRenderBundleAddRef(handle);
    }
}
void RenderBundle::WGPURelease(WGPURenderBundle handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientRenderBundleRelease(handle);
    }
}
static_assert(sizeof(RenderBundle) == sizeof(WGPURenderBundle), "sizeof mismatch for RenderBundle");
static_assert(alignof(RenderBundle) == alignof(WGPURenderBundle), "alignof mismatch for RenderBundle");

// RenderBundleEncoder implementation

void RenderBundleEncoder::Draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) const {
    wgpuDawnWireClientRenderBundleEncoderDraw(Get(), vertexCount, instanceCount, firstVertex, firstInstance);
}
void RenderBundleEncoder::DrawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance) const {
    wgpuDawnWireClientRenderBundleEncoderDrawIndexed(Get(), indexCount, instanceCount, firstIndex, baseVertex, firstInstance);
}
void RenderBundleEncoder::DrawIndexedIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const {
    wgpuDawnWireClientRenderBundleEncoderDrawIndexedIndirect(Get(), indirectBuffer.Get(), indirectOffset);
}
void RenderBundleEncoder::DrawIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const {
    wgpuDawnWireClientRenderBundleEncoderDrawIndirect(Get(), indirectBuffer.Get(), indirectOffset);
}
RenderBundle RenderBundleEncoder::Finish(RenderBundleDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientRenderBundleEncoderFinish(Get(), reinterpret_cast<WGPURenderBundleDescriptor const * >(descriptor));
    return RenderBundle::Acquire(result);
}
void RenderBundleEncoder::InsertDebugMarker(char const * markerLabel) const {
    wgpuDawnWireClientRenderBundleEncoderInsertDebugMarker(Get(), reinterpret_cast<char const * >(markerLabel));
}
void RenderBundleEncoder::PopDebugGroup() const {
    wgpuDawnWireClientRenderBundleEncoderPopDebugGroup(Get());
}
void RenderBundleEncoder::PushDebugGroup(char const * groupLabel) const {
    wgpuDawnWireClientRenderBundleEncoderPushDebugGroup(Get(), reinterpret_cast<char const * >(groupLabel));
}
void RenderBundleEncoder::SetBindGroup(uint32_t groupIndex, BindGroup const& group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) const {
    wgpuDawnWireClientRenderBundleEncoderSetBindGroup(Get(), groupIndex, group.Get(), dynamicOffsetCount, reinterpret_cast<uint32_t const * >(dynamicOffsets));
}
void RenderBundleEncoder::SetIndexBuffer(Buffer const& buffer, IndexFormat format, uint64_t offset, uint64_t size) const {
    wgpuDawnWireClientRenderBundleEncoderSetIndexBuffer(Get(), buffer.Get(), static_cast<WGPUIndexFormat>(format), offset, size);
}
void RenderBundleEncoder::SetLabel(char const * label) const {
    wgpuDawnWireClientRenderBundleEncoderSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void RenderBundleEncoder::SetPipeline(RenderPipeline const& pipeline) const {
    wgpuDawnWireClientRenderBundleEncoderSetPipeline(Get(), pipeline.Get());
}
void RenderBundleEncoder::SetVertexBuffer(uint32_t slot, Buffer const& buffer, uint64_t offset, uint64_t size) const {
    wgpuDawnWireClientRenderBundleEncoderSetVertexBuffer(Get(), slot, buffer.Get(), offset, size);
}
void RenderBundleEncoder::WGPUAddRef(WGPURenderBundleEncoder handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientRenderBundleEncoderAddRef(handle);
    }
}
void RenderBundleEncoder::WGPURelease(WGPURenderBundleEncoder handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientRenderBundleEncoderRelease(handle);
    }
}
static_assert(sizeof(RenderBundleEncoder) == sizeof(WGPURenderBundleEncoder), "sizeof mismatch for RenderBundleEncoder");
static_assert(alignof(RenderBundleEncoder) == alignof(WGPURenderBundleEncoder), "alignof mismatch for RenderBundleEncoder");

// RenderPassEncoder implementation

void RenderPassEncoder::BeginOcclusionQuery(uint32_t queryIndex) const {
    wgpuDawnWireClientRenderPassEncoderBeginOcclusionQuery(Get(), queryIndex);
}
void RenderPassEncoder::Draw(uint32_t vertexCount, uint32_t instanceCount, uint32_t firstVertex, uint32_t firstInstance) const {
    wgpuDawnWireClientRenderPassEncoderDraw(Get(), vertexCount, instanceCount, firstVertex, firstInstance);
}
void RenderPassEncoder::DrawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t baseVertex, uint32_t firstInstance) const {
    wgpuDawnWireClientRenderPassEncoderDrawIndexed(Get(), indexCount, instanceCount, firstIndex, baseVertex, firstInstance);
}
void RenderPassEncoder::DrawIndexedIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const {
    wgpuDawnWireClientRenderPassEncoderDrawIndexedIndirect(Get(), indirectBuffer.Get(), indirectOffset);
}
void RenderPassEncoder::DrawIndirect(Buffer const& indirectBuffer, uint64_t indirectOffset) const {
    wgpuDawnWireClientRenderPassEncoderDrawIndirect(Get(), indirectBuffer.Get(), indirectOffset);
}
void RenderPassEncoder::End() const {
    wgpuDawnWireClientRenderPassEncoderEnd(Get());
}
void RenderPassEncoder::EndOcclusionQuery() const {
    wgpuDawnWireClientRenderPassEncoderEndOcclusionQuery(Get());
}
void RenderPassEncoder::ExecuteBundles(size_t bundleCount, RenderBundle const * bundles) const {
    wgpuDawnWireClientRenderPassEncoderExecuteBundles(Get(), bundleCount, reinterpret_cast<WGPURenderBundle const * >(bundles));
}
void RenderPassEncoder::InsertDebugMarker(char const * markerLabel) const {
    wgpuDawnWireClientRenderPassEncoderInsertDebugMarker(Get(), reinterpret_cast<char const * >(markerLabel));
}
void RenderPassEncoder::PixelLocalStorageBarrier() const {
    wgpuDawnWireClientRenderPassEncoderPixelLocalStorageBarrier(Get());
}
void RenderPassEncoder::PopDebugGroup() const {
    wgpuDawnWireClientRenderPassEncoderPopDebugGroup(Get());
}
void RenderPassEncoder::PushDebugGroup(char const * groupLabel) const {
    wgpuDawnWireClientRenderPassEncoderPushDebugGroup(Get(), reinterpret_cast<char const * >(groupLabel));
}
void RenderPassEncoder::SetBindGroup(uint32_t groupIndex, BindGroup const& group, size_t dynamicOffsetCount, uint32_t const * dynamicOffsets) const {
    wgpuDawnWireClientRenderPassEncoderSetBindGroup(Get(), groupIndex, group.Get(), dynamicOffsetCount, reinterpret_cast<uint32_t const * >(dynamicOffsets));
}
void RenderPassEncoder::SetBlendConstant(Color const * color) const {
    wgpuDawnWireClientRenderPassEncoderSetBlendConstant(Get(), reinterpret_cast<WGPUColor const * >(color));
}
void RenderPassEncoder::SetIndexBuffer(Buffer const& buffer, IndexFormat format, uint64_t offset, uint64_t size) const {
    wgpuDawnWireClientRenderPassEncoderSetIndexBuffer(Get(), buffer.Get(), static_cast<WGPUIndexFormat>(format), offset, size);
}
void RenderPassEncoder::SetLabel(char const * label) const {
    wgpuDawnWireClientRenderPassEncoderSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void RenderPassEncoder::SetPipeline(RenderPipeline const& pipeline) const {
    wgpuDawnWireClientRenderPassEncoderSetPipeline(Get(), pipeline.Get());
}
void RenderPassEncoder::SetScissorRect(uint32_t x, uint32_t y, uint32_t width, uint32_t height) const {
    wgpuDawnWireClientRenderPassEncoderSetScissorRect(Get(), x, y, width, height);
}
void RenderPassEncoder::SetStencilReference(uint32_t reference) const {
    wgpuDawnWireClientRenderPassEncoderSetStencilReference(Get(), reference);
}
void RenderPassEncoder::SetVertexBuffer(uint32_t slot, Buffer const& buffer, uint64_t offset, uint64_t size) const {
    wgpuDawnWireClientRenderPassEncoderSetVertexBuffer(Get(), slot, buffer.Get(), offset, size);
}
void RenderPassEncoder::SetViewport(float x, float y, float width, float height, float minDepth, float maxDepth) const {
    wgpuDawnWireClientRenderPassEncoderSetViewport(Get(), x, y, width, height, minDepth, maxDepth);
}
void RenderPassEncoder::WriteTimestamp(QuerySet const& querySet, uint32_t queryIndex) const {
    wgpuDawnWireClientRenderPassEncoderWriteTimestamp(Get(), querySet.Get(), queryIndex);
}
void RenderPassEncoder::WGPUAddRef(WGPURenderPassEncoder handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientRenderPassEncoderAddRef(handle);
    }
}
void RenderPassEncoder::WGPURelease(WGPURenderPassEncoder handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientRenderPassEncoderRelease(handle);
    }
}
static_assert(sizeof(RenderPassEncoder) == sizeof(WGPURenderPassEncoder), "sizeof mismatch for RenderPassEncoder");
static_assert(alignof(RenderPassEncoder) == alignof(WGPURenderPassEncoder), "alignof mismatch for RenderPassEncoder");

// RenderPipeline implementation

BindGroupLayout RenderPipeline::GetBindGroupLayout(uint32_t groupIndex) const {
    auto result = wgpuDawnWireClientRenderPipelineGetBindGroupLayout(Get(), groupIndex);
    return BindGroupLayout::Acquire(result);
}
void RenderPipeline::SetLabel(char const * label) const {
    wgpuDawnWireClientRenderPipelineSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void RenderPipeline::WGPUAddRef(WGPURenderPipeline handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientRenderPipelineAddRef(handle);
    }
}
void RenderPipeline::WGPURelease(WGPURenderPipeline handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientRenderPipelineRelease(handle);
    }
}
static_assert(sizeof(RenderPipeline) == sizeof(WGPURenderPipeline), "sizeof mismatch for RenderPipeline");
static_assert(alignof(RenderPipeline) == alignof(WGPURenderPipeline), "alignof mismatch for RenderPipeline");

// Sampler implementation

void Sampler::SetLabel(char const * label) const {
    wgpuDawnWireClientSamplerSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void Sampler::WGPUAddRef(WGPUSampler handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientSamplerAddRef(handle);
    }
}
void Sampler::WGPURelease(WGPUSampler handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientSamplerRelease(handle);
    }
}
static_assert(sizeof(Sampler) == sizeof(WGPUSampler), "sizeof mismatch for Sampler");
static_assert(alignof(Sampler) == alignof(WGPUSampler), "alignof mismatch for Sampler");

// ShaderModule implementation

void ShaderModule::GetCompilationInfo(CompilationInfoCallback callback, void * userdata) const {
    wgpuDawnWireClientShaderModuleGetCompilationInfo(Get(), callback, userdata);
}
Future ShaderModule::GetCompilationInfo(CompilationInfoCallbackInfo callbackInfo) const {
    auto result = wgpuDawnWireClientShaderModuleGetCompilationInfoF(Get(), *reinterpret_cast<WGPUCompilationInfoCallbackInfo const*>(&callbackInfo));
    return Future {
            result.id
        };
}
void ShaderModule::SetLabel(char const * label) const {
    wgpuDawnWireClientShaderModuleSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void ShaderModule::WGPUAddRef(WGPUShaderModule handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientShaderModuleAddRef(handle);
    }
}
void ShaderModule::WGPURelease(WGPUShaderModule handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientShaderModuleRelease(handle);
    }
}
static_assert(sizeof(ShaderModule) == sizeof(WGPUShaderModule), "sizeof mismatch for ShaderModule");
static_assert(alignof(ShaderModule) == alignof(WGPUShaderModule), "alignof mismatch for ShaderModule");

// SharedBufferMemory implementation

Bool SharedBufferMemory::BeginAccess(Buffer const& buffer, SharedBufferMemoryBeginAccessDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientSharedBufferMemoryBeginAccess(Get(), buffer.Get(), reinterpret_cast<WGPUSharedBufferMemoryBeginAccessDescriptor const * >(descriptor));
    return result;
}
Buffer SharedBufferMemory::CreateBuffer(BufferDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientSharedBufferMemoryCreateBuffer(Get(), reinterpret_cast<WGPUBufferDescriptor const * >(descriptor));
    return Buffer::Acquire(result);
}
Bool SharedBufferMemory::EndAccess(Buffer const& buffer, SharedBufferMemoryEndAccessState * descriptor) const {
    *descriptor = SharedBufferMemoryEndAccessState();
    auto result = wgpuDawnWireClientSharedBufferMemoryEndAccess(Get(), buffer.Get(), reinterpret_cast<WGPUSharedBufferMemoryEndAccessState * >(descriptor));
    return result;
}
ConvertibleStatus SharedBufferMemory::GetProperties(SharedBufferMemoryProperties * properties) const {
    auto result = wgpuDawnWireClientSharedBufferMemoryGetProperties(Get(), reinterpret_cast<WGPUSharedBufferMemoryProperties * >(properties));
    return static_cast<Status>(result);
}
Bool SharedBufferMemory::IsDeviceLost() const {
    auto result = wgpuDawnWireClientSharedBufferMemoryIsDeviceLost(Get());
    return result;
}
void SharedBufferMemory::SetLabel(char const * label) const {
    wgpuDawnWireClientSharedBufferMemorySetLabel(Get(), reinterpret_cast<char const * >(label));
}
void SharedBufferMemory::WGPUAddRef(WGPUSharedBufferMemory handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientSharedBufferMemoryAddRef(handle);
    }
}
void SharedBufferMemory::WGPURelease(WGPUSharedBufferMemory handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientSharedBufferMemoryRelease(handle);
    }
}
static_assert(sizeof(SharedBufferMemory) == sizeof(WGPUSharedBufferMemory), "sizeof mismatch for SharedBufferMemory");
static_assert(alignof(SharedBufferMemory) == alignof(WGPUSharedBufferMemory), "alignof mismatch for SharedBufferMemory");

// SharedFence implementation

void SharedFence::ExportInfo(SharedFenceExportInfo * info) const {
    wgpuDawnWireClientSharedFenceExportInfo(Get(), reinterpret_cast<WGPUSharedFenceExportInfo * >(info));
}
void SharedFence::WGPUAddRef(WGPUSharedFence handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientSharedFenceAddRef(handle);
    }
}
void SharedFence::WGPURelease(WGPUSharedFence handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientSharedFenceRelease(handle);
    }
}
static_assert(sizeof(SharedFence) == sizeof(WGPUSharedFence), "sizeof mismatch for SharedFence");
static_assert(alignof(SharedFence) == alignof(WGPUSharedFence), "alignof mismatch for SharedFence");

// SharedTextureMemory implementation

Bool SharedTextureMemory::BeginAccess(Texture const& texture, SharedTextureMemoryBeginAccessDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientSharedTextureMemoryBeginAccess(Get(), texture.Get(), reinterpret_cast<WGPUSharedTextureMemoryBeginAccessDescriptor const * >(descriptor));
    return result;
}
Texture SharedTextureMemory::CreateTexture(TextureDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientSharedTextureMemoryCreateTexture(Get(), reinterpret_cast<WGPUTextureDescriptor const * >(descriptor));
    return Texture::Acquire(result);
}
Bool SharedTextureMemory::EndAccess(Texture const& texture, SharedTextureMemoryEndAccessState * descriptor) const {
    *descriptor = SharedTextureMemoryEndAccessState();
    auto result = wgpuDawnWireClientSharedTextureMemoryEndAccess(Get(), texture.Get(), reinterpret_cast<WGPUSharedTextureMemoryEndAccessState * >(descriptor));
    return result;
}
ConvertibleStatus SharedTextureMemory::GetProperties(SharedTextureMemoryProperties * properties) const {
    auto result = wgpuDawnWireClientSharedTextureMemoryGetProperties(Get(), reinterpret_cast<WGPUSharedTextureMemoryProperties * >(properties));
    return static_cast<Status>(result);
}
Bool SharedTextureMemory::IsDeviceLost() const {
    auto result = wgpuDawnWireClientSharedTextureMemoryIsDeviceLost(Get());
    return result;
}
void SharedTextureMemory::SetLabel(char const * label) const {
    wgpuDawnWireClientSharedTextureMemorySetLabel(Get(), reinterpret_cast<char const * >(label));
}
void SharedTextureMemory::WGPUAddRef(WGPUSharedTextureMemory handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientSharedTextureMemoryAddRef(handle);
    }
}
void SharedTextureMemory::WGPURelease(WGPUSharedTextureMemory handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientSharedTextureMemoryRelease(handle);
    }
}
static_assert(sizeof(SharedTextureMemory) == sizeof(WGPUSharedTextureMemory), "sizeof mismatch for SharedTextureMemory");
static_assert(alignof(SharedTextureMemory) == alignof(WGPUSharedTextureMemory), "alignof mismatch for SharedTextureMemory");

// Surface implementation

void Surface::Configure(SurfaceConfiguration const * config) const {
    wgpuDawnWireClientSurfaceConfigure(Get(), reinterpret_cast<WGPUSurfaceConfiguration const * >(config));
}
ConvertibleStatus Surface::GetCapabilities(Adapter const& adapter, SurfaceCapabilities * capabilities) const {
    *capabilities = SurfaceCapabilities();
    auto result = wgpuDawnWireClientSurfaceGetCapabilities(Get(), adapter.Get(), reinterpret_cast<WGPUSurfaceCapabilities * >(capabilities));
    return static_cast<Status>(result);
}
void Surface::GetCurrentTexture(SurfaceTexture * surfaceTexture) const {
    wgpuDawnWireClientSurfaceGetCurrentTexture(Get(), reinterpret_cast<WGPUSurfaceTexture * >(surfaceTexture));
}
TextureFormat Surface::GetPreferredFormat(Adapter const& adapter) const {
    auto result = wgpuDawnWireClientSurfaceGetPreferredFormat(Get(), adapter.Get());
    return static_cast<TextureFormat>(result);
}
void Surface::Present() const {
    wgpuDawnWireClientSurfacePresent(Get());
}
void Surface::Unconfigure() const {
    wgpuDawnWireClientSurfaceUnconfigure(Get());
}
void Surface::WGPUAddRef(WGPUSurface handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientSurfaceAddRef(handle);
    }
}
void Surface::WGPURelease(WGPUSurface handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientSurfaceRelease(handle);
    }
}
static_assert(sizeof(Surface) == sizeof(WGPUSurface), "sizeof mismatch for Surface");
static_assert(alignof(Surface) == alignof(WGPUSurface), "alignof mismatch for Surface");

// SwapChain implementation

Texture SwapChain::GetCurrentTexture() const {
    auto result = wgpuDawnWireClientSwapChainGetCurrentTexture(Get());
    return Texture::Acquire(result);
}
TextureView SwapChain::GetCurrentTextureView() const {
    auto result = wgpuDawnWireClientSwapChainGetCurrentTextureView(Get());
    return TextureView::Acquire(result);
}
void SwapChain::Present() const {
    wgpuDawnWireClientSwapChainPresent(Get());
}
void SwapChain::WGPUAddRef(WGPUSwapChain handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientSwapChainAddRef(handle);
    }
}
void SwapChain::WGPURelease(WGPUSwapChain handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientSwapChainRelease(handle);
    }
}
static_assert(sizeof(SwapChain) == sizeof(WGPUSwapChain), "sizeof mismatch for SwapChain");
static_assert(alignof(SwapChain) == alignof(WGPUSwapChain), "alignof mismatch for SwapChain");

// Texture implementation

TextureView Texture::CreateErrorView(TextureViewDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientTextureCreateErrorView(Get(), reinterpret_cast<WGPUTextureViewDescriptor const * >(descriptor));
    return TextureView::Acquire(result);
}
TextureView Texture::CreateView(TextureViewDescriptor const * descriptor) const {
    auto result = wgpuDawnWireClientTextureCreateView(Get(), reinterpret_cast<WGPUTextureViewDescriptor const * >(descriptor));
    return TextureView::Acquire(result);
}
void Texture::Destroy() const {
    wgpuDawnWireClientTextureDestroy(Get());
}
uint32_t Texture::GetDepthOrArrayLayers() const {
    auto result = wgpuDawnWireClientTextureGetDepthOrArrayLayers(Get());
    return result;
}
TextureDimension Texture::GetDimension() const {
    auto result = wgpuDawnWireClientTextureGetDimension(Get());
    return static_cast<TextureDimension>(result);
}
TextureFormat Texture::GetFormat() const {
    auto result = wgpuDawnWireClientTextureGetFormat(Get());
    return static_cast<TextureFormat>(result);
}
uint32_t Texture::GetHeight() const {
    auto result = wgpuDawnWireClientTextureGetHeight(Get());
    return result;
}
uint32_t Texture::GetMipLevelCount() const {
    auto result = wgpuDawnWireClientTextureGetMipLevelCount(Get());
    return result;
}
uint32_t Texture::GetSampleCount() const {
    auto result = wgpuDawnWireClientTextureGetSampleCount(Get());
    return result;
}
TextureUsage Texture::GetUsage() const {
    auto result = wgpuDawnWireClientTextureGetUsage(Get());
    return static_cast<TextureUsage>(result);
}
uint32_t Texture::GetWidth() const {
    auto result = wgpuDawnWireClientTextureGetWidth(Get());
    return result;
}
void Texture::SetLabel(char const * label) const {
    wgpuDawnWireClientTextureSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void Texture::WGPUAddRef(WGPUTexture handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientTextureAddRef(handle);
    }
}
void Texture::WGPURelease(WGPUTexture handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientTextureRelease(handle);
    }
}
static_assert(sizeof(Texture) == sizeof(WGPUTexture), "sizeof mismatch for Texture");
static_assert(alignof(Texture) == alignof(WGPUTexture), "alignof mismatch for Texture");

// TextureView implementation

void TextureView::SetLabel(char const * label) const {
    wgpuDawnWireClientTextureViewSetLabel(Get(), reinterpret_cast<char const * >(label));
}
void TextureView::WGPUAddRef(WGPUTextureView handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientTextureViewAddRef(handle);
    }
}
void TextureView::WGPURelease(WGPUTextureView handle) {
    if (handle != nullptr) {
        wgpuDawnWireClientTextureViewRelease(handle);
    }
}
static_assert(sizeof(TextureView) == sizeof(WGPUTextureView), "sizeof mismatch for TextureView");
static_assert(alignof(TextureView) == alignof(WGPUTextureView), "alignof mismatch for TextureView");


}  // namespace dawn::wire::client

using Adapter = dawn::wire::client::Adapter;
using BindGroup = dawn::wire::client::BindGroup;
using BindGroupLayout = dawn::wire::client::BindGroupLayout;
using Buffer = dawn::wire::client::Buffer;
using CommandBuffer = dawn::wire::client::CommandBuffer;
using CommandEncoder = dawn::wire::client::CommandEncoder;
using ComputePassEncoder = dawn::wire::client::ComputePassEncoder;
using ComputePipeline = dawn::wire::client::ComputePipeline;
using Device = dawn::wire::client::Device;
using ExternalTexture = dawn::wire::client::ExternalTexture;
using Instance = dawn::wire::client::Instance;
using PipelineLayout = dawn::wire::client::PipelineLayout;
using QuerySet = dawn::wire::client::QuerySet;
using Queue = dawn::wire::client::Queue;
using RenderBundle = dawn::wire::client::RenderBundle;
using RenderBundleEncoder = dawn::wire::client::RenderBundleEncoder;
using RenderPassEncoder = dawn::wire::client::RenderPassEncoder;
using RenderPipeline = dawn::wire::client::RenderPipeline;
using Sampler = dawn::wire::client::Sampler;
using ShaderModule = dawn::wire::client::ShaderModule;
using SharedBufferMemory = dawn::wire::client::SharedBufferMemory;
using SharedFence = dawn::wire::client::SharedFence;
using SharedTextureMemory = dawn::wire::client::SharedTextureMemory;
using Surface = dawn::wire::client::Surface;
using SwapChain = dawn::wire::client::SwapChain;
using Texture = dawn::wire::client::Texture;
using TextureView = dawn::wire::client::TextureView;

using AdapterInfo = dawn::wire::client::AdapterInfo;
using AdapterProperties = dawn::wire::client::AdapterProperties;
using AdapterPropertiesD3D = dawn::wire::client::AdapterPropertiesD3D;
using AdapterPropertiesVk = dawn::wire::client::AdapterPropertiesVk;
using BindGroupEntry = dawn::wire::client::BindGroupEntry;
using BlendComponent = dawn::wire::client::BlendComponent;
using BufferBindingLayout = dawn::wire::client::BufferBindingLayout;
using BufferDescriptor = dawn::wire::client::BufferDescriptor;
using BufferHostMappedPointer = dawn::wire::client::BufferHostMappedPointer;
using BufferMapCallbackInfo = dawn::wire::client::BufferMapCallbackInfo;
using Color = dawn::wire::client::Color;
using ColorTargetStateExpandResolveTextureDawn = dawn::wire::client::ColorTargetStateExpandResolveTextureDawn;
using CommandBufferDescriptor = dawn::wire::client::CommandBufferDescriptor;
using CommandEncoderDescriptor = dawn::wire::client::CommandEncoderDescriptor;
using CompilationInfoCallbackInfo = dawn::wire::client::CompilationInfoCallbackInfo;
using CompilationMessage = dawn::wire::client::CompilationMessage;
using ComputePassTimestampWrites = dawn::wire::client::ComputePassTimestampWrites;
using ConstantEntry = dawn::wire::client::ConstantEntry;
using CopyTextureForBrowserOptions = dawn::wire::client::CopyTextureForBrowserOptions;
using CreateComputePipelineAsyncCallbackInfo = dawn::wire::client::CreateComputePipelineAsyncCallbackInfo;
using CreateRenderPipelineAsyncCallbackInfo = dawn::wire::client::CreateRenderPipelineAsyncCallbackInfo;
using DawnWGSLBlocklist = dawn::wire::client::DawnWGSLBlocklist;
using DawnAdapterPropertiesPowerPreference = dawn::wire::client::DawnAdapterPropertiesPowerPreference;
using DawnBufferDescriptorErrorInfoFromWireClient = dawn::wire::client::DawnBufferDescriptorErrorInfoFromWireClient;
using DawnCacheDeviceDescriptor = dawn::wire::client::DawnCacheDeviceDescriptor;
using DawnComputePipelineFullSubgroups = dawn::wire::client::DawnComputePipelineFullSubgroups;
using DawnEncoderInternalUsageDescriptor = dawn::wire::client::DawnEncoderInternalUsageDescriptor;
using DawnExperimentalSubgroupLimits = dawn::wire::client::DawnExperimentalSubgroupLimits;
using DawnMultisampleStateRenderToSingleSampled = dawn::wire::client::DawnMultisampleStateRenderToSingleSampled;
using DawnRenderPassColorAttachmentRenderToSingleSampled = dawn::wire::client::DawnRenderPassColorAttachmentRenderToSingleSampled;
using DawnShaderModuleSPIRVOptionsDescriptor = dawn::wire::client::DawnShaderModuleSPIRVOptionsDescriptor;
using DawnTextureInternalUsageDescriptor = dawn::wire::client::DawnTextureInternalUsageDescriptor;
using DawnTogglesDescriptor = dawn::wire::client::DawnTogglesDescriptor;
using DawnWireWGSLControl = dawn::wire::client::DawnWireWGSLControl;
using DepthStencilStateDepthWriteDefinedDawn = dawn::wire::client::DepthStencilStateDepthWriteDefinedDawn;
using DeviceLostCallbackInfo = dawn::wire::client::DeviceLostCallbackInfo;
using DrmFormatProperties = dawn::wire::client::DrmFormatProperties;
using Extent2D = dawn::wire::client::Extent2D;
using Extent3D = dawn::wire::client::Extent3D;
using ExternalTextureBindingEntry = dawn::wire::client::ExternalTextureBindingEntry;
using ExternalTextureBindingLayout = dawn::wire::client::ExternalTextureBindingLayout;
using FormatCapabilities = dawn::wire::client::FormatCapabilities;
using Future = dawn::wire::client::Future;
using InstanceFeatures = dawn::wire::client::InstanceFeatures;
using Limits = dawn::wire::client::Limits;
using MemoryHeapInfo = dawn::wire::client::MemoryHeapInfo;
using MultisampleState = dawn::wire::client::MultisampleState;
using Origin2D = dawn::wire::client::Origin2D;
using Origin3D = dawn::wire::client::Origin3D;
using PipelineLayoutDescriptor = dawn::wire::client::PipelineLayoutDescriptor;
using PipelineLayoutStorageAttachment = dawn::wire::client::PipelineLayoutStorageAttachment;
using PopErrorScopeCallbackInfo = dawn::wire::client::PopErrorScopeCallbackInfo;
using PrimitiveDepthClipControl = dawn::wire::client::PrimitiveDepthClipControl;
using PrimitiveState = dawn::wire::client::PrimitiveState;
using QuerySetDescriptor = dawn::wire::client::QuerySetDescriptor;
using QueueDescriptor = dawn::wire::client::QueueDescriptor;
using QueueWorkDoneCallbackInfo = dawn::wire::client::QueueWorkDoneCallbackInfo;
using RenderBundleDescriptor = dawn::wire::client::RenderBundleDescriptor;
using RenderBundleEncoderDescriptor = dawn::wire::client::RenderBundleEncoderDescriptor;
using RenderPassDepthStencilAttachment = dawn::wire::client::RenderPassDepthStencilAttachment;
using RenderPassDescriptorMaxDrawCount = dawn::wire::client::RenderPassDescriptorMaxDrawCount;
using RenderPassTimestampWrites = dawn::wire::client::RenderPassTimestampWrites;
using RequestAdapterCallbackInfo = dawn::wire::client::RequestAdapterCallbackInfo;
using RequestAdapterOptions = dawn::wire::client::RequestAdapterOptions;
using RequestDeviceCallbackInfo = dawn::wire::client::RequestDeviceCallbackInfo;
using SamplerBindingLayout = dawn::wire::client::SamplerBindingLayout;
using SamplerDescriptor = dawn::wire::client::SamplerDescriptor;
using ShaderModuleSPIRVDescriptor = dawn::wire::client::ShaderModuleSPIRVDescriptor;
using ShaderModuleWGSLDescriptor = dawn::wire::client::ShaderModuleWGSLDescriptor;
using ShaderModuleCompilationOptions = dawn::wire::client::ShaderModuleCompilationOptions;
using ShaderModuleDescriptor = dawn::wire::client::ShaderModuleDescriptor;
using SharedBufferMemoryBeginAccessDescriptor = dawn::wire::client::SharedBufferMemoryBeginAccessDescriptor;
using SharedBufferMemoryDescriptor = dawn::wire::client::SharedBufferMemoryDescriptor;
using SharedBufferMemoryEndAccessState = dawn::wire::client::SharedBufferMemoryEndAccessState;
using SharedBufferMemoryProperties = dawn::wire::client::SharedBufferMemoryProperties;
using SharedFenceDXGISharedHandleDescriptor = dawn::wire::client::SharedFenceDXGISharedHandleDescriptor;
using SharedFenceDXGISharedHandleExportInfo = dawn::wire::client::SharedFenceDXGISharedHandleExportInfo;
using SharedFenceMTLSharedEventDescriptor = dawn::wire::client::SharedFenceMTLSharedEventDescriptor;
using SharedFenceMTLSharedEventExportInfo = dawn::wire::client::SharedFenceMTLSharedEventExportInfo;
using SharedFenceDescriptor = dawn::wire::client::SharedFenceDescriptor;
using SharedFenceExportInfo = dawn::wire::client::SharedFenceExportInfo;
using SharedFenceVkSemaphoreOpaqueFDDescriptor = dawn::wire::client::SharedFenceVkSemaphoreOpaqueFDDescriptor;
using SharedFenceVkSemaphoreOpaqueFDExportInfo = dawn::wire::client::SharedFenceVkSemaphoreOpaqueFDExportInfo;
using SharedFenceVkSemaphoreSyncFDDescriptor = dawn::wire::client::SharedFenceVkSemaphoreSyncFDDescriptor;
using SharedFenceVkSemaphoreSyncFDExportInfo = dawn::wire::client::SharedFenceVkSemaphoreSyncFDExportInfo;
using SharedFenceVkSemaphoreZirconHandleDescriptor = dawn::wire::client::SharedFenceVkSemaphoreZirconHandleDescriptor;
using SharedFenceVkSemaphoreZirconHandleExportInfo = dawn::wire::client::SharedFenceVkSemaphoreZirconHandleExportInfo;
using SharedTextureMemoryD3DSwapchainBeginState = dawn::wire::client::SharedTextureMemoryD3DSwapchainBeginState;
using SharedTextureMemoryDXGISharedHandleDescriptor = dawn::wire::client::SharedTextureMemoryDXGISharedHandleDescriptor;
using SharedTextureMemoryEGLImageDescriptor = dawn::wire::client::SharedTextureMemoryEGLImageDescriptor;
using SharedTextureMemoryIOSurfaceDescriptor = dawn::wire::client::SharedTextureMemoryIOSurfaceDescriptor;
using SharedTextureMemoryAHardwareBufferDescriptor = dawn::wire::client::SharedTextureMemoryAHardwareBufferDescriptor;
using SharedTextureMemoryBeginAccessDescriptor = dawn::wire::client::SharedTextureMemoryBeginAccessDescriptor;
using SharedTextureMemoryDescriptor = dawn::wire::client::SharedTextureMemoryDescriptor;
using SharedTextureMemoryDmaBufPlane = dawn::wire::client::SharedTextureMemoryDmaBufPlane;
using SharedTextureMemoryEndAccessState = dawn::wire::client::SharedTextureMemoryEndAccessState;
using SharedTextureMemoryOpaqueFDDescriptor = dawn::wire::client::SharedTextureMemoryOpaqueFDDescriptor;
using SharedTextureMemoryVkDedicatedAllocationDescriptor = dawn::wire::client::SharedTextureMemoryVkDedicatedAllocationDescriptor;
using SharedTextureMemoryVkImageLayoutBeginState = dawn::wire::client::SharedTextureMemoryVkImageLayoutBeginState;
using SharedTextureMemoryVkImageLayoutEndState = dawn::wire::client::SharedTextureMemoryVkImageLayoutEndState;
using SharedTextureMemoryZirconHandleDescriptor = dawn::wire::client::SharedTextureMemoryZirconHandleDescriptor;
using StaticSamplerBindingLayout = dawn::wire::client::StaticSamplerBindingLayout;
using StencilFaceState = dawn::wire::client::StencilFaceState;
using StorageTextureBindingLayout = dawn::wire::client::StorageTextureBindingLayout;
using SurfaceCapabilities = dawn::wire::client::SurfaceCapabilities;
using SurfaceConfiguration = dawn::wire::client::SurfaceConfiguration;
using SurfaceDescriptor = dawn::wire::client::SurfaceDescriptor;
using SurfaceDescriptorFromAndroidNativeWindow = dawn::wire::client::SurfaceDescriptorFromAndroidNativeWindow;
using SurfaceDescriptorFromCanvasHTMLSelector = dawn::wire::client::SurfaceDescriptorFromCanvasHTMLSelector;
using SurfaceDescriptorFromMetalLayer = dawn::wire::client::SurfaceDescriptorFromMetalLayer;
using SurfaceDescriptorFromWaylandSurface = dawn::wire::client::SurfaceDescriptorFromWaylandSurface;
using SurfaceDescriptorFromWindowsHWND = dawn::wire::client::SurfaceDescriptorFromWindowsHWND;
using SurfaceDescriptorFromWindowsCoreWindow = dawn::wire::client::SurfaceDescriptorFromWindowsCoreWindow;
using SurfaceDescriptorFromWindowsSwapChainPanel = dawn::wire::client::SurfaceDescriptorFromWindowsSwapChainPanel;
using SurfaceDescriptorFromXlibWindow = dawn::wire::client::SurfaceDescriptorFromXlibWindow;
using SurfaceTexture = dawn::wire::client::SurfaceTexture;
using SwapChainDescriptor = dawn::wire::client::SwapChainDescriptor;
using TextureBindingLayout = dawn::wire::client::TextureBindingLayout;
using TextureBindingViewDimensionDescriptor = dawn::wire::client::TextureBindingViewDimensionDescriptor;
using TextureDataLayout = dawn::wire::client::TextureDataLayout;
using TextureViewDescriptor = dawn::wire::client::TextureViewDescriptor;
using UncapturedErrorCallbackInfo = dawn::wire::client::UncapturedErrorCallbackInfo;
using VertexAttribute = dawn::wire::client::VertexAttribute;
using YCbCrVkDescriptor = dawn::wire::client::YCbCrVkDescriptor;
using AHardwareBufferProperties = dawn::wire::client::AHardwareBufferProperties;
using AdapterPropertiesMemoryHeaps = dawn::wire::client::AdapterPropertiesMemoryHeaps;
using BindGroupDescriptor = dawn::wire::client::BindGroupDescriptor;
using BindGroupLayoutEntry = dawn::wire::client::BindGroupLayoutEntry;
using BlendState = dawn::wire::client::BlendState;
using CompilationInfo = dawn::wire::client::CompilationInfo;
using ComputePassDescriptor = dawn::wire::client::ComputePassDescriptor;
using DepthStencilState = dawn::wire::client::DepthStencilState;
using DrmFormatCapabilities = dawn::wire::client::DrmFormatCapabilities;
using ExternalTextureDescriptor = dawn::wire::client::ExternalTextureDescriptor;
using FutureWaitInfo = dawn::wire::client::FutureWaitInfo;
using ImageCopyBuffer = dawn::wire::client::ImageCopyBuffer;
using ImageCopyExternalTexture = dawn::wire::client::ImageCopyExternalTexture;
using ImageCopyTexture = dawn::wire::client::ImageCopyTexture;
using InstanceDescriptor = dawn::wire::client::InstanceDescriptor;
using PipelineLayoutPixelLocalStorage = dawn::wire::client::PipelineLayoutPixelLocalStorage;
using ProgrammableStageDescriptor = dawn::wire::client::ProgrammableStageDescriptor;
using RenderPassColorAttachment = dawn::wire::client::RenderPassColorAttachment;
using RenderPassStorageAttachment = dawn::wire::client::RenderPassStorageAttachment;
using RequiredLimits = dawn::wire::client::RequiredLimits;
using SharedTextureMemoryAHardwareBufferProperties = dawn::wire::client::SharedTextureMemoryAHardwareBufferProperties;
using SharedTextureMemoryDmaBufDescriptor = dawn::wire::client::SharedTextureMemoryDmaBufDescriptor;
using SharedTextureMemoryProperties = dawn::wire::client::SharedTextureMemoryProperties;
using SupportedLimits = dawn::wire::client::SupportedLimits;
using TextureDescriptor = dawn::wire::client::TextureDescriptor;
using VertexBufferLayout = dawn::wire::client::VertexBufferLayout;
using BindGroupLayoutDescriptor = dawn::wire::client::BindGroupLayoutDescriptor;
using ColorTargetState = dawn::wire::client::ColorTargetState;
using ComputePipelineDescriptor = dawn::wire::client::ComputePipelineDescriptor;
using DeviceDescriptor = dawn::wire::client::DeviceDescriptor;
using RenderPassDescriptor = dawn::wire::client::RenderPassDescriptor;
using RenderPassPixelLocalStorage = dawn::wire::client::RenderPassPixelLocalStorage;
using VertexState = dawn::wire::client::VertexState;
using FragmentState = dawn::wire::client::FragmentState;
using RenderPipelineDescriptor = dawn::wire::client::RenderPipelineDescriptor;


// Free Functions
static inline Instance CreateInstance(InstanceDescriptor const * descriptor = nullptr) {
    auto result = wgpuDawnWireClientCreateInstance(reinterpret_cast<WGPUInstanceDescriptor const * >(descriptor));
    return Instance::Acquire(result);
}
static inline Status GetInstanceFeatures(InstanceFeatures * features) {
    auto result = wgpuDawnWireClientGetInstanceFeatures(reinterpret_cast<WGPUInstanceFeatures * >(features));
    return static_cast<Status>(result);
}
static inline Proc GetProcAddress(Device device, char const * procName) {
    auto result = wgpuDawnWireClientGetProcAddress(device.Get(), reinterpret_cast<char const * >(procName));
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
struct IsWGPUBitmask<wgpu::HeapProperty> {
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

#endif // DAWN_WIRE_CLIENT_WEBGPU_CPP_H_
