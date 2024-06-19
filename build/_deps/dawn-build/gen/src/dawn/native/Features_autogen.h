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

#ifndef DAWNNATIVE_FEATURES_AUTOGEN_H_
#define DAWNNATIVE_FEATURES_AUTOGEN_H_

#include "dawn/common/ityp_array.h"
#include "dawn/native/dawn_platform.h"

namespace dawn::native {

enum class Feature {
DepthClipControl,
Depth32FloatStencil8,
TimestampQuery,
TextureCompressionBC,
TextureCompressionETC2,
TextureCompressionASTC,
IndirectFirstInstance,
ShaderF16,
RG11B10UfloatRenderable,
BGRA8UnormStorage,
Float32Filterable,
DawnInternalUsages,
DawnMultiPlanarFormats,
DawnNative,
ChromiumExperimentalTimestampQueryInsidePasses,
ImplicitDeviceSynchronization,
SurfaceCapabilities,
TransientAttachments,
MSAARenderToSingleSampled,
DualSourceBlending,
D3D11MultithreadProtected,
ANGLETextureSharing,
ChromiumExperimentalSubgroups,
ChromiumExperimentalSubgroupUniformControlFlow,
PixelLocalStorageCoherent,
PixelLocalStorageNonCoherent,
Unorm16TextureFormats,
Snorm16TextureFormats,
MultiPlanarFormatExtendedUsages,
MultiPlanarFormatP010,
HostMappedPointer,
MultiPlanarRenderTargets,
MultiPlanarFormatNv12a,
FramebufferFetch,
BufferMapExtendedUsages,
AdapterPropertiesMemoryHeaps,
AdapterPropertiesD3D,
AdapterPropertiesVk,
R8UnormStorage,
FormatCapabilities,
DrmFormatCapabilities,
Norm16TextureFormats,
MultiPlanarFormatNv16,
MultiPlanarFormatNv24,
MultiPlanarFormatP210,
MultiPlanarFormatP410,
SharedTextureMemoryVkDedicatedAllocation,
SharedTextureMemoryAHardwareBuffer,
SharedTextureMemoryDmaBuf,
SharedTextureMemoryOpaqueFD,
SharedTextureMemoryZirconHandle,
SharedTextureMemoryDXGISharedHandle,
SharedTextureMemoryD3D11Texture2D,
SharedTextureMemoryIOSurface,
SharedTextureMemoryEGLImage,
SharedFenceVkSemaphoreOpaqueFD,
SharedFenceVkSemaphoreSyncFD,
SharedFenceVkSemaphoreZirconHandle,
SharedFenceDXGISharedHandle,
SharedFenceMTLSharedEvent,
SharedBufferMemoryD3D12Resource,
StaticSamplers,
YCbCrVulkanSamplers,
ShaderModuleCompilationOptions,
DawnLoadResolveTexture,
  InvalidEnum,
};

template<>
struct EnumCount<Feature> {
    static constexpr uint32_t value = 65;
};

}  // namespace dawn::native

#endif  // DAWNNATIVE_FEATURES_AUTOGEN_H_
