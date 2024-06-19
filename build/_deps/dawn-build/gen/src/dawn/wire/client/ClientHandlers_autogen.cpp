
#include "dawn/common/Assert.h"
#include "dawn/wire/client/Client.h"

#include <string>

namespace dawn::wire::client {
    WireResult Client::HandleAdapterRequestDeviceCallback(DeserializeBuffer* deserializeBuffer) {
        ReturnAdapterRequestDeviceCallbackCmd cmd;
        WIRE_TRY(cmd.Deserialize(deserializeBuffer, &mWireCommandAllocator));


        return DoAdapterRequestDeviceCallback(cmd.eventManager, cmd.future, cmd.status, cmd.message, cmd.limits, cmd.featuresCount, cmd.features);
    }
    WireResult Client::HandleBufferMapAsyncCallback(DeserializeBuffer* deserializeBuffer) {
        ReturnBufferMapAsyncCallbackCmd cmd;
        WIRE_TRY(cmd.Deserialize(deserializeBuffer, &mWireCommandAllocator));


        return DoBufferMapAsyncCallback(cmd.eventManager, cmd.future, cmd.status, cmd.readDataUpdateInfoLength, cmd.readDataUpdateInfo);
    }
    WireResult Client::HandleDeviceCreateComputePipelineAsyncCallback(DeserializeBuffer* deserializeBuffer) {
        ReturnDeviceCreateComputePipelineAsyncCallbackCmd cmd;
        WIRE_TRY(cmd.Deserialize(deserializeBuffer, &mWireCommandAllocator));


        return DoDeviceCreateComputePipelineAsyncCallback(cmd.eventManager, cmd.future, cmd.status, cmd.message);
    }
    WireResult Client::HandleDeviceCreateRenderPipelineAsyncCallback(DeserializeBuffer* deserializeBuffer) {
        ReturnDeviceCreateRenderPipelineAsyncCallbackCmd cmd;
        WIRE_TRY(cmd.Deserialize(deserializeBuffer, &mWireCommandAllocator));


        return DoDeviceCreateRenderPipelineAsyncCallback(cmd.eventManager, cmd.future, cmd.status, cmd.message);
    }
    WireResult Client::HandleDeviceLoggingCallback(DeserializeBuffer* deserializeBuffer) {
        ReturnDeviceLoggingCallbackCmd cmd;
        WIRE_TRY(cmd.Deserialize(deserializeBuffer, &mWireCommandAllocator));


        Device* device = Get<Device>(cmd.device.id);
        if (device != nullptr && device->GetWireGeneration() != cmd.device.generation) {
            device = nullptr;
        }

        return DoDeviceLoggingCallback(device, cmd.type, cmd.message);
    }
    WireResult Client::HandleDeviceLostCallback(DeserializeBuffer* deserializeBuffer) {
        ReturnDeviceLostCallbackCmd cmd;
        WIRE_TRY(cmd.Deserialize(deserializeBuffer, &mWireCommandAllocator));


        return DoDeviceLostCallback(cmd.eventManager, cmd.future, cmd.reason, cmd.message);
    }
    WireResult Client::HandleDevicePopErrorScopeCallback(DeserializeBuffer* deserializeBuffer) {
        ReturnDevicePopErrorScopeCallbackCmd cmd;
        WIRE_TRY(cmd.Deserialize(deserializeBuffer, &mWireCommandAllocator));


        return DoDevicePopErrorScopeCallback(cmd.eventManager, cmd.future, cmd.type, cmd.message);
    }
    WireResult Client::HandleDeviceUncapturedErrorCallback(DeserializeBuffer* deserializeBuffer) {
        ReturnDeviceUncapturedErrorCallbackCmd cmd;
        WIRE_TRY(cmd.Deserialize(deserializeBuffer, &mWireCommandAllocator));


        Device* device = Get<Device>(cmd.device.id);
        if (device != nullptr && device->GetWireGeneration() != cmd.device.generation) {
            device = nullptr;
        }

        return DoDeviceUncapturedErrorCallback(device, cmd.type, cmd.message);
    }
    WireResult Client::HandleInstanceRequestAdapterCallback(DeserializeBuffer* deserializeBuffer) {
        ReturnInstanceRequestAdapterCallbackCmd cmd;
        WIRE_TRY(cmd.Deserialize(deserializeBuffer, &mWireCommandAllocator));


        return DoInstanceRequestAdapterCallback(cmd.eventManager, cmd.future, cmd.status, cmd.message, cmd.info, cmd.properties, cmd.limits, cmd.featuresCount, cmd.features);
    }
    WireResult Client::HandleQueueWorkDoneCallback(DeserializeBuffer* deserializeBuffer) {
        ReturnQueueWorkDoneCallbackCmd cmd;
        WIRE_TRY(cmd.Deserialize(deserializeBuffer, &mWireCommandAllocator));


        return DoQueueWorkDoneCallback(cmd.eventManager, cmd.future, cmd.status);
    }
    WireResult Client::HandleShaderModuleGetCompilationInfoCallback(DeserializeBuffer* deserializeBuffer) {
        ReturnShaderModuleGetCompilationInfoCallbackCmd cmd;
        WIRE_TRY(cmd.Deserialize(deserializeBuffer, &mWireCommandAllocator));


        return DoShaderModuleGetCompilationInfoCallback(cmd.eventManager, cmd.future, cmd.status, cmd.info);
    }

    const volatile char* Client::HandleCommandsImpl(const volatile char* commands, size_t size) {
        DeserializeBuffer deserializeBuffer(commands, size);

        while (deserializeBuffer.AvailableSize() >= sizeof(CmdHeader) + sizeof(ReturnWireCmd)) {
            // Start by chunked command handling, if it is done, then it means the whole buffer
            // was consumed by it, so we return a pointer to the end of the commands.
            switch (HandleChunkedCommands(deserializeBuffer.Buffer(), deserializeBuffer.AvailableSize())) {
                case ChunkedCommandsResult::Consumed:
                    return commands + size;
                case ChunkedCommandsResult::Error:
                    return nullptr;
                case ChunkedCommandsResult::Passthrough:
                    break;
            }

            ReturnWireCmd cmdId = *static_cast<const volatile ReturnWireCmd*>(static_cast<const volatile void*>(
                deserializeBuffer.Buffer() + sizeof(CmdHeader)));
            WireResult result = WireResult::FatalError;
            switch (cmdId) {
                case ReturnWireCmd::AdapterRequestDeviceCallback:
                    result = HandleAdapterRequestDeviceCallback(&deserializeBuffer);
                    break;
                case ReturnWireCmd::BufferMapAsyncCallback:
                    result = HandleBufferMapAsyncCallback(&deserializeBuffer);
                    break;
                case ReturnWireCmd::DeviceCreateComputePipelineAsyncCallback:
                    result = HandleDeviceCreateComputePipelineAsyncCallback(&deserializeBuffer);
                    break;
                case ReturnWireCmd::DeviceCreateRenderPipelineAsyncCallback:
                    result = HandleDeviceCreateRenderPipelineAsyncCallback(&deserializeBuffer);
                    break;
                case ReturnWireCmd::DeviceLoggingCallback:
                    result = HandleDeviceLoggingCallback(&deserializeBuffer);
                    break;
                case ReturnWireCmd::DeviceLostCallback:
                    result = HandleDeviceLostCallback(&deserializeBuffer);
                    break;
                case ReturnWireCmd::DevicePopErrorScopeCallback:
                    result = HandleDevicePopErrorScopeCallback(&deserializeBuffer);
                    break;
                case ReturnWireCmd::DeviceUncapturedErrorCallback:
                    result = HandleDeviceUncapturedErrorCallback(&deserializeBuffer);
                    break;
                case ReturnWireCmd::InstanceRequestAdapterCallback:
                    result = HandleInstanceRequestAdapterCallback(&deserializeBuffer);
                    break;
                case ReturnWireCmd::QueueWorkDoneCallback:
                    result = HandleQueueWorkDoneCallback(&deserializeBuffer);
                    break;
                case ReturnWireCmd::ShaderModuleGetCompilationInfoCallback:
                    result = HandleShaderModuleGetCompilationInfoCallback(&deserializeBuffer);
                    break;
            }

            if (result != WireResult::Success) {
                return nullptr;
            }
            mWireCommandAllocator.Reset();
        }

        if (deserializeBuffer.AvailableSize() != 0) {
            return nullptr;
        }

        return commands;
    }
}  // namespace dawn::wire::client
