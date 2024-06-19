// Copyright 2023 The Dawn & Tint Authors
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

namespace dawn::native {

wgpu::FeatureName ToAPI(Feature feature) {
  switch (feature) {
  case Feature::DepthClipControl:
    return wgpu::FeatureName::DepthClipControl;
  case Feature::Depth32FloatStencil8:
    return wgpu::FeatureName::Depth32FloatStencil8;
  case Feature::TimestampQuery:
    return wgpu::FeatureName::TimestampQuery;
  case Feature::TextureCompressionBC:
    return wgpu::FeatureName::TextureCompressionBC;
  case Feature::TextureCompressionETC2:
    return wgpu::FeatureName::TextureCompressionETC2;
  case Feature::TextureCompressionASTC:
    return wgpu::FeatureName::TextureCompressionASTC;
  case Feature::IndirectFirstInstance:
    return wgpu::FeatureName::IndirectFirstInstance;
  case Feature::ShaderF16:
    return wgpu::FeatureName::ShaderF16;
  case Feature::RG11B10UfloatRenderable:
    return wgpu::FeatureName::RG11B10UfloatRenderable;
  case Feature::BGRA8UnormStorage:
    return wgpu::FeatureName::BGRA8UnormStorage;
  case Feature::Float32Filterable:
    return wgpu::FeatureName::Float32Filterable;
  case Feature::DawnInternalUsages:
    return wgpu::FeatureName::DawnInternalUsages;
  case Feature::DawnMultiPlanarFormats:
    return wgpu::FeatureName::DawnMultiPlanarFormats;
  case Feature::DawnNative:
    return wgpu::FeatureName::DawnNative;
  case Feature::ChromiumExperimentalTimestampQueryInsidePasses:
    return wgpu::FeatureName::ChromiumExperimentalTimestampQueryInsidePasses;
  case Feature::ImplicitDeviceSynchronization:
    return wgpu::FeatureName::ImplicitDeviceSynchronization;
  case Feature::SurfaceCapabilities:
    return wgpu::FeatureName::SurfaceCapabilities;
  case Feature::TransientAttachments:
    return wgpu::FeatureName::TransientAttachments;
  case Feature::MSAARenderToSingleSampled:
    return wgpu::FeatureName::MSAARenderToSingleSampled;
  case Feature::DualSourceBlending:
    return wgpu::FeatureName::DualSourceBlending;
  case Feature::D3D11MultithreadProtected:
    return wgpu::FeatureName::D3D11MultithreadProtected;
  case Feature::ANGLETextureSharing:
    return wgpu::FeatureName::ANGLETextureSharing;
  case Feature::ChromiumExperimentalSubgroups:
    return wgpu::FeatureName::ChromiumExperimentalSubgroups;
  case Feature::ChromiumExperimentalSubgroupUniformControlFlow:
    return wgpu::FeatureName::ChromiumExperimentalSubgroupUniformControlFlow;
  case Feature::PixelLocalStorageCoherent:
    return wgpu::FeatureName::PixelLocalStorageCoherent;
  case Feature::PixelLocalStorageNonCoherent:
    return wgpu::FeatureName::PixelLocalStorageNonCoherent;
  case Feature::Unorm16TextureFormats:
    return wgpu::FeatureName::Unorm16TextureFormats;
  case Feature::Snorm16TextureFormats:
    return wgpu::FeatureName::Snorm16TextureFormats;
  case Feature::MultiPlanarFormatExtendedUsages:
    return wgpu::FeatureName::MultiPlanarFormatExtendedUsages;
  case Feature::MultiPlanarFormatP010:
    return wgpu::FeatureName::MultiPlanarFormatP010;
  case Feature::HostMappedPointer:
    return wgpu::FeatureName::HostMappedPointer;
  case Feature::MultiPlanarRenderTargets:
    return wgpu::FeatureName::MultiPlanarRenderTargets;
  case Feature::MultiPlanarFormatNv12a:
    return wgpu::FeatureName::MultiPlanarFormatNv12a;
  case Feature::FramebufferFetch:
    return wgpu::FeatureName::FramebufferFetch;
  case Feature::BufferMapExtendedUsages:
    return wgpu::FeatureName::BufferMapExtendedUsages;
  case Feature::AdapterPropertiesMemoryHeaps:
    return wgpu::FeatureName::AdapterPropertiesMemoryHeaps;
  case Feature::AdapterPropertiesD3D:
    return wgpu::FeatureName::AdapterPropertiesD3D;
  case Feature::AdapterPropertiesVk:
    return wgpu::FeatureName::AdapterPropertiesVk;
  case Feature::R8UnormStorage:
    return wgpu::FeatureName::R8UnormStorage;
  case Feature::FormatCapabilities:
    return wgpu::FeatureName::FormatCapabilities;
  case Feature::DrmFormatCapabilities:
    return wgpu::FeatureName::DrmFormatCapabilities;
  case Feature::Norm16TextureFormats:
    return wgpu::FeatureName::Norm16TextureFormats;
  case Feature::MultiPlanarFormatNv16:
    return wgpu::FeatureName::MultiPlanarFormatNv16;
  case Feature::MultiPlanarFormatNv24:
    return wgpu::FeatureName::MultiPlanarFormatNv24;
  case Feature::MultiPlanarFormatP210:
    return wgpu::FeatureName::MultiPlanarFormatP210;
  case Feature::MultiPlanarFormatP410:
    return wgpu::FeatureName::MultiPlanarFormatP410;
  case Feature::SharedTextureMemoryVkDedicatedAllocation:
    return wgpu::FeatureName::SharedTextureMemoryVkDedicatedAllocation;
  case Feature::SharedTextureMemoryAHardwareBuffer:
    return wgpu::FeatureName::SharedTextureMemoryAHardwareBuffer;
  case Feature::SharedTextureMemoryDmaBuf:
    return wgpu::FeatureName::SharedTextureMemoryDmaBuf;
  case Feature::SharedTextureMemoryOpaqueFD:
    return wgpu::FeatureName::SharedTextureMemoryOpaqueFD;
  case Feature::SharedTextureMemoryZirconHandle:
    return wgpu::FeatureName::SharedTextureMemoryZirconHandle;
  case Feature::SharedTextureMemoryDXGISharedHandle:
    return wgpu::FeatureName::SharedTextureMemoryDXGISharedHandle;
  case Feature::SharedTextureMemoryD3D11Texture2D:
    return wgpu::FeatureName::SharedTextureMemoryD3D11Texture2D;
  case Feature::SharedTextureMemoryIOSurface:
    return wgpu::FeatureName::SharedTextureMemoryIOSurface;
  case Feature::SharedTextureMemoryEGLImage:
    return wgpu::FeatureName::SharedTextureMemoryEGLImage;
  case Feature::SharedFenceVkSemaphoreOpaqueFD:
    return wgpu::FeatureName::SharedFenceVkSemaphoreOpaqueFD;
  case Feature::SharedFenceVkSemaphoreSyncFD:
    return wgpu::FeatureName::SharedFenceVkSemaphoreSyncFD;
  case Feature::SharedFenceVkSemaphoreZirconHandle:
    return wgpu::FeatureName::SharedFenceVkSemaphoreZirconHandle;
  case Feature::SharedFenceDXGISharedHandle:
    return wgpu::FeatureName::SharedFenceDXGISharedHandle;
  case Feature::SharedFenceMTLSharedEvent:
    return wgpu::FeatureName::SharedFenceMTLSharedEvent;
  case Feature::SharedBufferMemoryD3D12Resource:
    return wgpu::FeatureName::SharedBufferMemoryD3D12Resource;
  case Feature::StaticSamplers:
    return wgpu::FeatureName::StaticSamplers;
  case Feature::YCbCrVulkanSamplers:
    return wgpu::FeatureName::YCbCrVulkanSamplers;
  case Feature::ShaderModuleCompilationOptions:
    return wgpu::FeatureName::ShaderModuleCompilationOptions;
  case Feature::DawnLoadResolveTexture:
    return wgpu::FeatureName::DawnLoadResolveTexture;
    case Feature::InvalidEnum:
      DAWN_UNREACHABLE();
  }
}

Feature FromAPI(wgpu::FeatureName feature) {
  switch (feature) {
  case wgpu::FeatureName::Undefined:
  return Feature::InvalidEnum;
  case wgpu::FeatureName::DepthClipControl:
  return Feature::DepthClipControl;
  case wgpu::FeatureName::Depth32FloatStencil8:
  return Feature::Depth32FloatStencil8;
  case wgpu::FeatureName::TimestampQuery:
  return Feature::TimestampQuery;
  case wgpu::FeatureName::TextureCompressionBC:
  return Feature::TextureCompressionBC;
  case wgpu::FeatureName::TextureCompressionETC2:
  return Feature::TextureCompressionETC2;
  case wgpu::FeatureName::TextureCompressionASTC:
  return Feature::TextureCompressionASTC;
  case wgpu::FeatureName::IndirectFirstInstance:
  return Feature::IndirectFirstInstance;
  case wgpu::FeatureName::ShaderF16:
  return Feature::ShaderF16;
  case wgpu::FeatureName::RG11B10UfloatRenderable:
  return Feature::RG11B10UfloatRenderable;
  case wgpu::FeatureName::BGRA8UnormStorage:
  return Feature::BGRA8UnormStorage;
  case wgpu::FeatureName::Float32Filterable:
  return Feature::Float32Filterable;
  case wgpu::FeatureName::DawnInternalUsages:
  return Feature::DawnInternalUsages;
  case wgpu::FeatureName::DawnMultiPlanarFormats:
  return Feature::DawnMultiPlanarFormats;
  case wgpu::FeatureName::DawnNative:
  return Feature::DawnNative;
  case wgpu::FeatureName::ChromiumExperimentalTimestampQueryInsidePasses:
  return Feature::ChromiumExperimentalTimestampQueryInsidePasses;
  case wgpu::FeatureName::ImplicitDeviceSynchronization:
  return Feature::ImplicitDeviceSynchronization;
  case wgpu::FeatureName::SurfaceCapabilities:
  return Feature::SurfaceCapabilities;
  case wgpu::FeatureName::TransientAttachments:
  return Feature::TransientAttachments;
  case wgpu::FeatureName::MSAARenderToSingleSampled:
  return Feature::MSAARenderToSingleSampled;
  case wgpu::FeatureName::DualSourceBlending:
  return Feature::DualSourceBlending;
  case wgpu::FeatureName::D3D11MultithreadProtected:
  return Feature::D3D11MultithreadProtected;
  case wgpu::FeatureName::ANGLETextureSharing:
  return Feature::ANGLETextureSharing;
  case wgpu::FeatureName::ChromiumExperimentalSubgroups:
  return Feature::ChromiumExperimentalSubgroups;
  case wgpu::FeatureName::ChromiumExperimentalSubgroupUniformControlFlow:
  return Feature::ChromiumExperimentalSubgroupUniformControlFlow;
  case wgpu::FeatureName::PixelLocalStorageCoherent:
  return Feature::PixelLocalStorageCoherent;
  case wgpu::FeatureName::PixelLocalStorageNonCoherent:
  return Feature::PixelLocalStorageNonCoherent;
  case wgpu::FeatureName::Unorm16TextureFormats:
  return Feature::Unorm16TextureFormats;
  case wgpu::FeatureName::Snorm16TextureFormats:
  return Feature::Snorm16TextureFormats;
  case wgpu::FeatureName::MultiPlanarFormatExtendedUsages:
  return Feature::MultiPlanarFormatExtendedUsages;
  case wgpu::FeatureName::MultiPlanarFormatP010:
  return Feature::MultiPlanarFormatP010;
  case wgpu::FeatureName::HostMappedPointer:
  return Feature::HostMappedPointer;
  case wgpu::FeatureName::MultiPlanarRenderTargets:
  return Feature::MultiPlanarRenderTargets;
  case wgpu::FeatureName::MultiPlanarFormatNv12a:
  return Feature::MultiPlanarFormatNv12a;
  case wgpu::FeatureName::FramebufferFetch:
  return Feature::FramebufferFetch;
  case wgpu::FeatureName::BufferMapExtendedUsages:
  return Feature::BufferMapExtendedUsages;
  case wgpu::FeatureName::AdapterPropertiesMemoryHeaps:
  return Feature::AdapterPropertiesMemoryHeaps;
  case wgpu::FeatureName::AdapterPropertiesD3D:
  return Feature::AdapterPropertiesD3D;
  case wgpu::FeatureName::AdapterPropertiesVk:
  return Feature::AdapterPropertiesVk;
  case wgpu::FeatureName::R8UnormStorage:
  return Feature::R8UnormStorage;
  case wgpu::FeatureName::FormatCapabilities:
  return Feature::FormatCapabilities;
  case wgpu::FeatureName::DrmFormatCapabilities:
  return Feature::DrmFormatCapabilities;
  case wgpu::FeatureName::Norm16TextureFormats:
  return Feature::Norm16TextureFormats;
  case wgpu::FeatureName::MultiPlanarFormatNv16:
  return Feature::MultiPlanarFormatNv16;
  case wgpu::FeatureName::MultiPlanarFormatNv24:
  return Feature::MultiPlanarFormatNv24;
  case wgpu::FeatureName::MultiPlanarFormatP210:
  return Feature::MultiPlanarFormatP210;
  case wgpu::FeatureName::MultiPlanarFormatP410:
  return Feature::MultiPlanarFormatP410;
  case wgpu::FeatureName::SharedTextureMemoryVkDedicatedAllocation:
  return Feature::SharedTextureMemoryVkDedicatedAllocation;
  case wgpu::FeatureName::SharedTextureMemoryAHardwareBuffer:
  return Feature::SharedTextureMemoryAHardwareBuffer;
  case wgpu::FeatureName::SharedTextureMemoryDmaBuf:
  return Feature::SharedTextureMemoryDmaBuf;
  case wgpu::FeatureName::SharedTextureMemoryOpaqueFD:
  return Feature::SharedTextureMemoryOpaqueFD;
  case wgpu::FeatureName::SharedTextureMemoryZirconHandle:
  return Feature::SharedTextureMemoryZirconHandle;
  case wgpu::FeatureName::SharedTextureMemoryDXGISharedHandle:
  return Feature::SharedTextureMemoryDXGISharedHandle;
  case wgpu::FeatureName::SharedTextureMemoryD3D11Texture2D:
  return Feature::SharedTextureMemoryD3D11Texture2D;
  case wgpu::FeatureName::SharedTextureMemoryIOSurface:
  return Feature::SharedTextureMemoryIOSurface;
  case wgpu::FeatureName::SharedTextureMemoryEGLImage:
  return Feature::SharedTextureMemoryEGLImage;
  case wgpu::FeatureName::SharedFenceVkSemaphoreOpaqueFD:
  return Feature::SharedFenceVkSemaphoreOpaqueFD;
  case wgpu::FeatureName::SharedFenceVkSemaphoreSyncFD:
  return Feature::SharedFenceVkSemaphoreSyncFD;
  case wgpu::FeatureName::SharedFenceVkSemaphoreZirconHandle:
  return Feature::SharedFenceVkSemaphoreZirconHandle;
  case wgpu::FeatureName::SharedFenceDXGISharedHandle:
  return Feature::SharedFenceDXGISharedHandle;
  case wgpu::FeatureName::SharedFenceMTLSharedEvent:
  return Feature::SharedFenceMTLSharedEvent;
  case wgpu::FeatureName::SharedBufferMemoryD3D12Resource:
  return Feature::SharedBufferMemoryD3D12Resource;
  case wgpu::FeatureName::StaticSamplers:
  return Feature::StaticSamplers;
  case wgpu::FeatureName::YCbCrVulkanSamplers:
  return Feature::YCbCrVulkanSamplers;
  case wgpu::FeatureName::ShaderModuleCompilationOptions:
  return Feature::ShaderModuleCompilationOptions;
  case wgpu::FeatureName::DawnLoadResolveTexture:
  return Feature::DawnLoadResolveTexture;
    default:
      return Feature::InvalidEnum;
  }
}

static constexpr bool FeatureInfoIsDefined(Feature feature) {
  for (const auto& info : kFeatureInfo) {
    if (info.feature == feature) {
      return true;
    }
  }
  return false;
}

static constexpr ityp::array<Feature, FeatureInfo, kEnumCount<Feature>> InitializeFeatureEnumAndInfoList() {
  constexpr size_t kInfoCount = sizeof(kFeatureInfo) / sizeof(kFeatureInfo[0]);
  ityp::array<Feature, FeatureInfo, kEnumCount<Feature>> list{};
{
  static_assert(FeatureInfoIsDefined(Feature::DepthClipControl),
                "Please define feature info for DepthClipControl in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::DepthClipControl) {
      list[Feature::DepthClipControl] = {
        "depth-clip-control",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::Depth32FloatStencil8),
                "Please define feature info for Depth32FloatStencil8 in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::Depth32FloatStencil8) {
      list[Feature::Depth32FloatStencil8] = {
        "depth32float-stencil8",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::TimestampQuery),
                "Please define feature info for TimestampQuery in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::TimestampQuery) {
      list[Feature::TimestampQuery] = {
        "timestamp-query",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::TextureCompressionBC),
                "Please define feature info for TextureCompressionBC in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::TextureCompressionBC) {
      list[Feature::TextureCompressionBC] = {
        "texture-compression-bc",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::TextureCompressionETC2),
                "Please define feature info for TextureCompressionETC2 in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::TextureCompressionETC2) {
      list[Feature::TextureCompressionETC2] = {
        "texture-compression-etc2",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::TextureCompressionASTC),
                "Please define feature info for TextureCompressionASTC in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::TextureCompressionASTC) {
      list[Feature::TextureCompressionASTC] = {
        "texture-compression-astc",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::IndirectFirstInstance),
                "Please define feature info for IndirectFirstInstance in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::IndirectFirstInstance) {
      list[Feature::IndirectFirstInstance] = {
        "indirect-first-instance",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::ShaderF16),
                "Please define feature info for ShaderF16 in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::ShaderF16) {
      list[Feature::ShaderF16] = {
        "shader-f16",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::RG11B10UfloatRenderable),
                "Please define feature info for RG11B10UfloatRenderable in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::RG11B10UfloatRenderable) {
      list[Feature::RG11B10UfloatRenderable] = {
        "rg11b10ufloat-renderable",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::BGRA8UnormStorage),
                "Please define feature info for BGRA8UnormStorage in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::BGRA8UnormStorage) {
      list[Feature::BGRA8UnormStorage] = {
        "bgra8unorm-storage",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::Float32Filterable),
                "Please define feature info for Float32Filterable in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::Float32Filterable) {
      list[Feature::Float32Filterable] = {
        "float32filterable",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::DawnInternalUsages),
                "Please define feature info for DawnInternalUsages in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::DawnInternalUsages) {
      list[Feature::DawnInternalUsages] = {
        "dawn-internal-usages",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::DawnMultiPlanarFormats),
                "Please define feature info for DawnMultiPlanarFormats in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::DawnMultiPlanarFormats) {
      list[Feature::DawnMultiPlanarFormats] = {
        "dawn-multi-planar-formats",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::DawnNative),
                "Please define feature info for DawnNative in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::DawnNative) {
      list[Feature::DawnNative] = {
        "dawn-native",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::ChromiumExperimentalTimestampQueryInsidePasses),
                "Please define feature info for ChromiumExperimentalTimestampQueryInsidePasses in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::ChromiumExperimentalTimestampQueryInsidePasses) {
      list[Feature::ChromiumExperimentalTimestampQueryInsidePasses] = {
        "chromium-experimental-timestamp-query-inside-passes",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::ImplicitDeviceSynchronization),
                "Please define feature info for ImplicitDeviceSynchronization in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::ImplicitDeviceSynchronization) {
      list[Feature::ImplicitDeviceSynchronization] = {
        "implicit-device-synchronization",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::SurfaceCapabilities),
                "Please define feature info for SurfaceCapabilities in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::SurfaceCapabilities) {
      list[Feature::SurfaceCapabilities] = {
        "surface-capabilities",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::TransientAttachments),
                "Please define feature info for TransientAttachments in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::TransientAttachments) {
      list[Feature::TransientAttachments] = {
        "transient-attachments",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::MSAARenderToSingleSampled),
                "Please define feature info for MSAARenderToSingleSampled in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::MSAARenderToSingleSampled) {
      list[Feature::MSAARenderToSingleSampled] = {
        "msaa-render-to-single-sampled",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::DualSourceBlending),
                "Please define feature info for DualSourceBlending in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::DualSourceBlending) {
      list[Feature::DualSourceBlending] = {
        "dual-source-blending",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::D3D11MultithreadProtected),
                "Please define feature info for D3D11MultithreadProtected in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::D3D11MultithreadProtected) {
      list[Feature::D3D11MultithreadProtected] = {
        "d3d11multithread-protected",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::ANGLETextureSharing),
                "Please define feature info for ANGLETextureSharing in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::ANGLETextureSharing) {
      list[Feature::ANGLETextureSharing] = {
        "angle-texture-sharing",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::ChromiumExperimentalSubgroups),
                "Please define feature info for ChromiumExperimentalSubgroups in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::ChromiumExperimentalSubgroups) {
      list[Feature::ChromiumExperimentalSubgroups] = {
        "chromium-experimental-subgroups",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::ChromiumExperimentalSubgroupUniformControlFlow),
                "Please define feature info for ChromiumExperimentalSubgroupUniformControlFlow in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::ChromiumExperimentalSubgroupUniformControlFlow) {
      list[Feature::ChromiumExperimentalSubgroupUniformControlFlow] = {
        "chromium-experimental-subgroup-uniform-control-flow",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::PixelLocalStorageCoherent),
                "Please define feature info for PixelLocalStorageCoherent in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::PixelLocalStorageCoherent) {
      list[Feature::PixelLocalStorageCoherent] = {
        "pixel-local-storage-coherent",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::PixelLocalStorageNonCoherent),
                "Please define feature info for PixelLocalStorageNonCoherent in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::PixelLocalStorageNonCoherent) {
      list[Feature::PixelLocalStorageNonCoherent] = {
        "pixel-local-storage-non-coherent",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::Unorm16TextureFormats),
                "Please define feature info for Unorm16TextureFormats in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::Unorm16TextureFormats) {
      list[Feature::Unorm16TextureFormats] = {
        "unorm16texture-formats",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::Snorm16TextureFormats),
                "Please define feature info for Snorm16TextureFormats in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::Snorm16TextureFormats) {
      list[Feature::Snorm16TextureFormats] = {
        "snorm16texture-formats",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::MultiPlanarFormatExtendedUsages),
                "Please define feature info for MultiPlanarFormatExtendedUsages in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::MultiPlanarFormatExtendedUsages) {
      list[Feature::MultiPlanarFormatExtendedUsages] = {
        "multi-planar-format-extended-usages",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::MultiPlanarFormatP010),
                "Please define feature info for MultiPlanarFormatP010 in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::MultiPlanarFormatP010) {
      list[Feature::MultiPlanarFormatP010] = {
        "multi-planar-format-p010",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::HostMappedPointer),
                "Please define feature info for HostMappedPointer in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::HostMappedPointer) {
      list[Feature::HostMappedPointer] = {
        "host-mapped-pointer",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::MultiPlanarRenderTargets),
                "Please define feature info for MultiPlanarRenderTargets in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::MultiPlanarRenderTargets) {
      list[Feature::MultiPlanarRenderTargets] = {
        "multi-planar-render-targets",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::MultiPlanarFormatNv12a),
                "Please define feature info for MultiPlanarFormatNv12a in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::MultiPlanarFormatNv12a) {
      list[Feature::MultiPlanarFormatNv12a] = {
        "multi-planar-format-nv12a",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::FramebufferFetch),
                "Please define feature info for FramebufferFetch in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::FramebufferFetch) {
      list[Feature::FramebufferFetch] = {
        "framebuffer-fetch",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::BufferMapExtendedUsages),
                "Please define feature info for BufferMapExtendedUsages in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::BufferMapExtendedUsages) {
      list[Feature::BufferMapExtendedUsages] = {
        "buffer-map-extended-usages",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::AdapterPropertiesMemoryHeaps),
                "Please define feature info for AdapterPropertiesMemoryHeaps in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::AdapterPropertiesMemoryHeaps) {
      list[Feature::AdapterPropertiesMemoryHeaps] = {
        "adapter-properties-memory-heaps",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::AdapterPropertiesD3D),
                "Please define feature info for AdapterPropertiesD3D in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::AdapterPropertiesD3D) {
      list[Feature::AdapterPropertiesD3D] = {
        "adapter-properties-d3d",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::AdapterPropertiesVk),
                "Please define feature info for AdapterPropertiesVk in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::AdapterPropertiesVk) {
      list[Feature::AdapterPropertiesVk] = {
        "adapter-properties-vk",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::R8UnormStorage),
                "Please define feature info for R8UnormStorage in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::R8UnormStorage) {
      list[Feature::R8UnormStorage] = {
        "r8unorm-storage",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::FormatCapabilities),
                "Please define feature info for FormatCapabilities in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::FormatCapabilities) {
      list[Feature::FormatCapabilities] = {
        "format-capabilities",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::DrmFormatCapabilities),
                "Please define feature info for DrmFormatCapabilities in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::DrmFormatCapabilities) {
      list[Feature::DrmFormatCapabilities] = {
        "drm-format-capabilities",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::Norm16TextureFormats),
                "Please define feature info for Norm16TextureFormats in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::Norm16TextureFormats) {
      list[Feature::Norm16TextureFormats] = {
        "norm16texture-formats",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::MultiPlanarFormatNv16),
                "Please define feature info for MultiPlanarFormatNv16 in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::MultiPlanarFormatNv16) {
      list[Feature::MultiPlanarFormatNv16] = {
        "multi-planar-format-nv16",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::MultiPlanarFormatNv24),
                "Please define feature info for MultiPlanarFormatNv24 in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::MultiPlanarFormatNv24) {
      list[Feature::MultiPlanarFormatNv24] = {
        "multi-planar-format-nv24",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::MultiPlanarFormatP210),
                "Please define feature info for MultiPlanarFormatP210 in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::MultiPlanarFormatP210) {
      list[Feature::MultiPlanarFormatP210] = {
        "multi-planar-format-p210",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::MultiPlanarFormatP410),
                "Please define feature info for MultiPlanarFormatP410 in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::MultiPlanarFormatP410) {
      list[Feature::MultiPlanarFormatP410] = {
        "multi-planar-format-p410",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::SharedTextureMemoryVkDedicatedAllocation),
                "Please define feature info for SharedTextureMemoryVkDedicatedAllocation in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::SharedTextureMemoryVkDedicatedAllocation) {
      list[Feature::SharedTextureMemoryVkDedicatedAllocation] = {
        "shared-texture-memory-vk-dedicated-allocation",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::SharedTextureMemoryAHardwareBuffer),
                "Please define feature info for SharedTextureMemoryAHardwareBuffer in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::SharedTextureMemoryAHardwareBuffer) {
      list[Feature::SharedTextureMemoryAHardwareBuffer] = {
        "shared-texture-memory-a-hardware-buffer",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::SharedTextureMemoryDmaBuf),
                "Please define feature info for SharedTextureMemoryDmaBuf in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::SharedTextureMemoryDmaBuf) {
      list[Feature::SharedTextureMemoryDmaBuf] = {
        "shared-texture-memory-dma-buf",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::SharedTextureMemoryOpaqueFD),
                "Please define feature info for SharedTextureMemoryOpaqueFD in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::SharedTextureMemoryOpaqueFD) {
      list[Feature::SharedTextureMemoryOpaqueFD] = {
        "shared-texture-memory-opaque-fd",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::SharedTextureMemoryZirconHandle),
                "Please define feature info for SharedTextureMemoryZirconHandle in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::SharedTextureMemoryZirconHandle) {
      list[Feature::SharedTextureMemoryZirconHandle] = {
        "shared-texture-memory-zircon-handle",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::SharedTextureMemoryDXGISharedHandle),
                "Please define feature info for SharedTextureMemoryDXGISharedHandle in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::SharedTextureMemoryDXGISharedHandle) {
      list[Feature::SharedTextureMemoryDXGISharedHandle] = {
        "shared-texture-memory-dxgi-shared-handle",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::SharedTextureMemoryD3D11Texture2D),
                "Please define feature info for SharedTextureMemoryD3D11Texture2D in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::SharedTextureMemoryD3D11Texture2D) {
      list[Feature::SharedTextureMemoryD3D11Texture2D] = {
        "shared-texture-memory-d3d11texture-2d",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::SharedTextureMemoryIOSurface),
                "Please define feature info for SharedTextureMemoryIOSurface in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::SharedTextureMemoryIOSurface) {
      list[Feature::SharedTextureMemoryIOSurface] = {
        "shared-texture-memory-io-surface",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::SharedTextureMemoryEGLImage),
                "Please define feature info for SharedTextureMemoryEGLImage in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::SharedTextureMemoryEGLImage) {
      list[Feature::SharedTextureMemoryEGLImage] = {
        "shared-texture-memory-egl-image",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::SharedFenceVkSemaphoreOpaqueFD),
                "Please define feature info for SharedFenceVkSemaphoreOpaqueFD in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::SharedFenceVkSemaphoreOpaqueFD) {
      list[Feature::SharedFenceVkSemaphoreOpaqueFD] = {
        "shared-fence-vk-semaphore-opaque-fd",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::SharedFenceVkSemaphoreSyncFD),
                "Please define feature info for SharedFenceVkSemaphoreSyncFD in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::SharedFenceVkSemaphoreSyncFD) {
      list[Feature::SharedFenceVkSemaphoreSyncFD] = {
        "shared-fence-vk-semaphore-sync-fd",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::SharedFenceVkSemaphoreZirconHandle),
                "Please define feature info for SharedFenceVkSemaphoreZirconHandle in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::SharedFenceVkSemaphoreZirconHandle) {
      list[Feature::SharedFenceVkSemaphoreZirconHandle] = {
        "shared-fence-vk-semaphore-zircon-handle",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::SharedFenceDXGISharedHandle),
                "Please define feature info for SharedFenceDXGISharedHandle in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::SharedFenceDXGISharedHandle) {
      list[Feature::SharedFenceDXGISharedHandle] = {
        "shared-fence-dxgi-shared-handle",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::SharedFenceMTLSharedEvent),
                "Please define feature info for SharedFenceMTLSharedEvent in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::SharedFenceMTLSharedEvent) {
      list[Feature::SharedFenceMTLSharedEvent] = {
        "shared-fence-mtl-shared-event",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::SharedBufferMemoryD3D12Resource),
                "Please define feature info for SharedBufferMemoryD3D12Resource in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::SharedBufferMemoryD3D12Resource) {
      list[Feature::SharedBufferMemoryD3D12Resource] = {
        "shared-buffer-memory-d3d12resource",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::StaticSamplers),
                "Please define feature info for StaticSamplers in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::StaticSamplers) {
      list[Feature::StaticSamplers] = {
        "static-samplers",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::YCbCrVulkanSamplers),
                "Please define feature info for YCbCrVulkanSamplers in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::YCbCrVulkanSamplers) {
      list[Feature::YCbCrVulkanSamplers] = {
        "y-cb-cr-vulkan-samplers",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::ShaderModuleCompilationOptions),
                "Please define feature info for ShaderModuleCompilationOptions in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::ShaderModuleCompilationOptions) {
      list[Feature::ShaderModuleCompilationOptions] = {
        "shader-module-compilation-options",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
{
  static_assert(FeatureInfoIsDefined(Feature::DawnLoadResolveTexture),
                "Please define feature info for DawnLoadResolveTexture in Features.cpp");
  for (size_t i = 0; i < kInfoCount; ++i) {
    if (kFeatureInfo[i].feature == Feature::DawnLoadResolveTexture) {
      list[Feature::DawnLoadResolveTexture] = {
        "dawn-load-resolve-texture",
        kFeatureInfo[i].info.description,
        kFeatureInfo[i].info.url,
        kFeatureInfo[i].info.featureState,
      };
    }
  }
}
  return list;
}

const ityp::array<Feature, FeatureInfo, kEnumCount<Feature>> kFeatureNameAndInfoList = InitializeFeatureEnumAndInfoList();

}
