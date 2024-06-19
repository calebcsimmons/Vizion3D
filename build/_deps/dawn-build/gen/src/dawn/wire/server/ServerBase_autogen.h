
#ifndef DAWNWIRE_SERVER_SERVERBASE_AUTOGEN_H_
#define DAWNWIRE_SERVER_SERVERBASE_AUTOGEN_H_

#include <tuple>

#include "dawn/dawn_proc_table.h"
#include "dawn/wire/ChunkedCommandHandler.h"
#include "dawn/wire/Wire.h"
#include "dawn/wire/WireCmd_autogen.h"
#include "dawn/wire/WireDeserializeAllocator.h"
#include "dawn/wire/server/ObjectStorage.h"
#include "dawn/wire/server/WGPUTraits_autogen.h"

namespace dawn::wire::server {

    class ServerBase : public ChunkedCommandHandler, public ObjectIdResolver {
      public:
        ServerBase() = default;
        ~ServerBase() override = default;

      protected:
        template <typename T>
        const KnownObjects<T>& Objects() const {
            return std::get<KnownObjects<T>>(mKnown);
        }
        template <typename T>
        KnownObjects<T>& Objects() {
            return std::get<KnownObjects<T>>(mKnown);
        }

        template <typename T>
        void Release(const DawnProcTable& procs, T handle) {
            (procs.*WGPUTraits<T>::Release)(handle);
        }

        void DestroyAllObjects(const DawnProcTable& procs) {
            {
                std::vector<WGPUDevice> handles = Objects<WGPUDevice>().AcquireAllHandles();
                for (WGPUDevice handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUAdapter> handles = Objects<WGPUAdapter>().AcquireAllHandles();
                for (WGPUAdapter handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUBindGroup> handles = Objects<WGPUBindGroup>().AcquireAllHandles();
                for (WGPUBindGroup handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUBindGroupLayout> handles = Objects<WGPUBindGroupLayout>().AcquireAllHandles();
                for (WGPUBindGroupLayout handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUBuffer> handles = Objects<WGPUBuffer>().AcquireAllHandles();
                for (WGPUBuffer handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUCommandBuffer> handles = Objects<WGPUCommandBuffer>().AcquireAllHandles();
                for (WGPUCommandBuffer handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUCommandEncoder> handles = Objects<WGPUCommandEncoder>().AcquireAllHandles();
                for (WGPUCommandEncoder handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUComputePassEncoder> handles = Objects<WGPUComputePassEncoder>().AcquireAllHandles();
                for (WGPUComputePassEncoder handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUComputePipeline> handles = Objects<WGPUComputePipeline>().AcquireAllHandles();
                for (WGPUComputePipeline handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUExternalTexture> handles = Objects<WGPUExternalTexture>().AcquireAllHandles();
                for (WGPUExternalTexture handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUInstance> handles = Objects<WGPUInstance>().AcquireAllHandles();
                for (WGPUInstance handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUPipelineLayout> handles = Objects<WGPUPipelineLayout>().AcquireAllHandles();
                for (WGPUPipelineLayout handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUQuerySet> handles = Objects<WGPUQuerySet>().AcquireAllHandles();
                for (WGPUQuerySet handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUQueue> handles = Objects<WGPUQueue>().AcquireAllHandles();
                for (WGPUQueue handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPURenderBundle> handles = Objects<WGPURenderBundle>().AcquireAllHandles();
                for (WGPURenderBundle handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPURenderBundleEncoder> handles = Objects<WGPURenderBundleEncoder>().AcquireAllHandles();
                for (WGPURenderBundleEncoder handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPURenderPassEncoder> handles = Objects<WGPURenderPassEncoder>().AcquireAllHandles();
                for (WGPURenderPassEncoder handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPURenderPipeline> handles = Objects<WGPURenderPipeline>().AcquireAllHandles();
                for (WGPURenderPipeline handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUSampler> handles = Objects<WGPUSampler>().AcquireAllHandles();
                for (WGPUSampler handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUShaderModule> handles = Objects<WGPUShaderModule>().AcquireAllHandles();
                for (WGPUShaderModule handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUSurface> handles = Objects<WGPUSurface>().AcquireAllHandles();
                for (WGPUSurface handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUSwapChain> handles = Objects<WGPUSwapChain>().AcquireAllHandles();
                for (WGPUSwapChain handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUTexture> handles = Objects<WGPUTexture>().AcquireAllHandles();
                for (WGPUTexture handle : handles) {
                    Release(procs, handle);
                }
            }
            {
                std::vector<WGPUTextureView> handles = Objects<WGPUTextureView>().AcquireAllHandles();
                for (WGPUTextureView handle : handles) {
                    Release(procs, handle);
                }
            }
        }

      private:
        // Implementation of the ObjectIdResolver interface
        WireResult GetFromId(ObjectId id, WGPUAdapter* out) const final {
            return Objects<WGPUAdapter>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUAdapter* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUBindGroup* out) const final {
            return Objects<WGPUBindGroup>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUBindGroup* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUBindGroupLayout* out) const final {
            return Objects<WGPUBindGroupLayout>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUBindGroupLayout* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUBuffer* out) const final {
            return Objects<WGPUBuffer>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUBuffer* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUCommandBuffer* out) const final {
            return Objects<WGPUCommandBuffer>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUCommandBuffer* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUCommandEncoder* out) const final {
            return Objects<WGPUCommandEncoder>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUCommandEncoder* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUComputePassEncoder* out) const final {
            return Objects<WGPUComputePassEncoder>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUComputePassEncoder* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUComputePipeline* out) const final {
            return Objects<WGPUComputePipeline>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUComputePipeline* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUDevice* out) const final {
            return Objects<WGPUDevice>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUDevice* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUExternalTexture* out) const final {
            return Objects<WGPUExternalTexture>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUExternalTexture* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUInstance* out) const final {
            return Objects<WGPUInstance>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUInstance* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUPipelineLayout* out) const final {
            return Objects<WGPUPipelineLayout>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUPipelineLayout* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUQuerySet* out) const final {
            return Objects<WGPUQuerySet>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUQuerySet* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUQueue* out) const final {
            return Objects<WGPUQueue>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUQueue* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPURenderBundle* out) const final {
            return Objects<WGPURenderBundle>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPURenderBundle* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPURenderBundleEncoder* out) const final {
            return Objects<WGPURenderBundleEncoder>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPURenderBundleEncoder* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPURenderPassEncoder* out) const final {
            return Objects<WGPURenderPassEncoder>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPURenderPassEncoder* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPURenderPipeline* out) const final {
            return Objects<WGPURenderPipeline>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPURenderPipeline* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUSampler* out) const final {
            return Objects<WGPUSampler>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUSampler* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUShaderModule* out) const final {
            return Objects<WGPUShaderModule>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUShaderModule* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUSurface* out) const final {
            return Objects<WGPUSurface>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUSurface* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUSwapChain* out) const final {
            return Objects<WGPUSwapChain>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUSwapChain* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUTexture* out) const final {
            return Objects<WGPUTexture>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUTexture* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }
        WireResult GetFromId(ObjectId id, WGPUTextureView* out) const final {
            return Objects<WGPUTextureView>().GetNativeHandle(id, out);
        }

        WireResult GetOptionalFromId(ObjectId id, WGPUTextureView* out) const final {
            if (id == 0) {
                *out = nullptr;
                return WireResult::Success;
            }
            return GetFromId(id, out);
        }

        std::tuple<
            KnownObjects<WGPUAdapter>, 
            KnownObjects<WGPUBindGroup>, 
            KnownObjects<WGPUBindGroupLayout>, 
            KnownObjects<WGPUBuffer>, 
            KnownObjects<WGPUCommandBuffer>, 
            KnownObjects<WGPUCommandEncoder>, 
            KnownObjects<WGPUComputePassEncoder>, 
            KnownObjects<WGPUComputePipeline>, 
            KnownObjects<WGPUDevice>, 
            KnownObjects<WGPUExternalTexture>, 
            KnownObjects<WGPUInstance>, 
            KnownObjects<WGPUPipelineLayout>, 
            KnownObjects<WGPUQuerySet>, 
            KnownObjects<WGPUQueue>, 
            KnownObjects<WGPURenderBundle>, 
            KnownObjects<WGPURenderBundleEncoder>, 
            KnownObjects<WGPURenderPassEncoder>, 
            KnownObjects<WGPURenderPipeline>, 
            KnownObjects<WGPUSampler>, 
            KnownObjects<WGPUShaderModule>, 
            KnownObjects<WGPUSurface>, 
            KnownObjects<WGPUSwapChain>, 
            KnownObjects<WGPUTexture>, 
            KnownObjects<WGPUTextureView>
        > mKnown;
    };

}  // namespace dawn::wire::server

#endif  // DAWNWIRE_SERVER_SERVERBASE_AUTOGEN_H_
