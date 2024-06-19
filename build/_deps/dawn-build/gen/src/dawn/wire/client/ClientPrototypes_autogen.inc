
WireResult HandleAdapterRequestDeviceCallback(DeserializeBuffer* deserializeBuffer);
WireResult HandleBufferMapAsyncCallback(DeserializeBuffer* deserializeBuffer);
WireResult HandleDeviceCreateComputePipelineAsyncCallback(DeserializeBuffer* deserializeBuffer);
WireResult HandleDeviceCreateRenderPipelineAsyncCallback(DeserializeBuffer* deserializeBuffer);
WireResult HandleDeviceLoggingCallback(DeserializeBuffer* deserializeBuffer);
WireResult HandleDeviceLostCallback(DeserializeBuffer* deserializeBuffer);
WireResult HandleDevicePopErrorScopeCallback(DeserializeBuffer* deserializeBuffer);
WireResult HandleDeviceUncapturedErrorCallback(DeserializeBuffer* deserializeBuffer);
WireResult HandleInstanceRequestAdapterCallback(DeserializeBuffer* deserializeBuffer);
WireResult HandleQueueWorkDoneCallback(DeserializeBuffer* deserializeBuffer);
WireResult HandleShaderModuleGetCompilationInfoCallback(DeserializeBuffer* deserializeBuffer);

WireResult DoAdapterRequestDeviceCallback(ObjectHandle eventManager, WGPUFuture future, WGPURequestDeviceStatus status, char const * message, WGPUSupportedLimits const * limits, uint32_t featuresCount, WGPUFeatureName const * features);
WireResult DoBufferMapAsyncCallback(ObjectHandle eventManager, WGPUFuture future, WGPUBufferMapAsyncStatus status, uint64_t readDataUpdateInfoLength, uint8_t const * readDataUpdateInfo);
WireResult DoDeviceCreateComputePipelineAsyncCallback(ObjectHandle eventManager, WGPUFuture future, WGPUCreatePipelineAsyncStatus status, char const * message);
WireResult DoDeviceCreateRenderPipelineAsyncCallback(ObjectHandle eventManager, WGPUFuture future, WGPUCreatePipelineAsyncStatus status, char const * message);
WireResult DoDeviceLoggingCallback(Device* device, WGPULoggingType type, char const * message);
WireResult DoDeviceLostCallback(ObjectHandle eventManager, WGPUFuture future, WGPUDeviceLostReason reason, char const * message);
WireResult DoDevicePopErrorScopeCallback(ObjectHandle eventManager, WGPUFuture future, WGPUErrorType type, char const * message);
WireResult DoDeviceUncapturedErrorCallback(Device* device, WGPUErrorType type, char const * message);
WireResult DoInstanceRequestAdapterCallback(ObjectHandle eventManager, WGPUFuture future, WGPURequestAdapterStatus status, char const * message, WGPUAdapterInfo const * info, WGPUAdapterProperties const * properties, WGPUSupportedLimits const * limits, uint32_t featuresCount, WGPUFeatureName const * features);
WireResult DoQueueWorkDoneCallback(ObjectHandle eventManager, WGPUFuture future, WGPUQueueWorkDoneStatus status);
WireResult DoShaderModuleGetCompilationInfoCallback(ObjectHandle eventManager, WGPUFuture future, WGPUCompilationInfoRequestStatus status, WGPUCompilationInfo const * info);
