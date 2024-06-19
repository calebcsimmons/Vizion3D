
#include "dawn/native/webgpu_absl_format_autogen.h"

#include "dawn/native/ChainUtils.h"
#include "dawn/native/ObjectType_autogen.h"

namespace dawn::native {

    //
    // Descriptors
    //

    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const BufferDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[BufferDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<BufferDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const CommandBufferDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[CommandBufferDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<CommandBufferDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const CommandEncoderDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[CommandEncoderDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<CommandEncoderDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const PipelineLayoutDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[PipelineLayoutDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<PipelineLayoutDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const QuerySetDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[QuerySetDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<QuerySetDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const QueueDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[QueueDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<QueueDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const RenderBundleDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[RenderBundleDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<RenderBundleDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const RenderBundleEncoderDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[RenderBundleEncoderDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<RenderBundleEncoderDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const SamplerDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[SamplerDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<SamplerDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const ShaderModuleDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[ShaderModuleDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<ShaderModuleDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const SharedBufferMemoryDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[SharedBufferMemoryDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<SharedBufferMemoryDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const SharedFenceDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[SharedFenceDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<SharedFenceDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const SharedTextureMemoryDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[SharedTextureMemoryDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<SharedTextureMemoryDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const SurfaceDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[SurfaceDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<SurfaceDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const SwapChainDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[SwapChainDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<SwapChainDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const TextureViewDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[TextureViewDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<TextureViewDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const BindGroupDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[BindGroupDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<BindGroupDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const ComputePassDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[ComputePassDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<ComputePassDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const ExternalTextureDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[ExternalTextureDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<ExternalTextureDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const TextureDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[TextureDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<TextureDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const BindGroupLayoutDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[BindGroupLayoutDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<BindGroupLayoutDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const ComputePipelineDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[ComputePipelineDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<ComputePipelineDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const DeviceDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[DeviceDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<DeviceDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const RenderPassDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[RenderPassDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<RenderPassDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const RenderPipelineDescriptor* value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        if (value == nullptr) {
            s->Append("[null]");
            return {true};
        }
        s->Append("[RenderPipelineDescriptor");
        if (value->label != nullptr) {
            s->Append(absl::StrFormat(" \"%s\"", value->label));
        }
        s->Append("]");
        return {true};
    }
    absl::FormatConvertResult<absl::FormatConversionCharSet::kString>
    AbslFormatConvert(const UnpackedPtr<RenderPipelineDescriptor>& value,
                      const absl::FormatConversionSpec& spec,
                      absl::FormatSink* s) {
        return AbslFormatConvert(*value, spec, s);
    }

}  // namespace dawn::native

namespace wgpu {

    //
    // Enums
    //

absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(WGSLFeatureName value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("WGSLFeatureName::");
        switch (value) {
        case WGSLFeatureName::Undefined:
            s->Append("Undefined");
            break;
        case WGSLFeatureName::ReadonlyAndReadwriteStorageTextures:
            s->Append("ReadonlyAndReadwriteStorageTextures");
            break;
        case WGSLFeatureName::Packed4x8IntegerDotProduct:
            s->Append("Packed4x8IntegerDotProduct");
            break;
        case WGSLFeatureName::UnrestrictedPointerParameters:
            s->Append("UnrestrictedPointerParameters");
            break;
        case WGSLFeatureName::PointerCompositeAccess:
            s->Append("PointerCompositeAccess");
            break;
        case WGSLFeatureName::ChromiumTestingUnimplemented:
            s->Append("ChromiumTestingUnimplemented");
            break;
        case WGSLFeatureName::ChromiumTestingUnsafeExperimental:
            s->Append("ChromiumTestingUnsafeExperimental");
            break;
        case WGSLFeatureName::ChromiumTestingExperimental:
            s->Append("ChromiumTestingExperimental");
            break;
        case WGSLFeatureName::ChromiumTestingShippedWithKillswitch:
            s->Append("ChromiumTestingShippedWithKillswitch");
            break;
        case WGSLFeatureName::ChromiumTestingShipped:
            s->Append("ChromiumTestingShipped");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<WGSLFeatureName>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(AdapterType value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("AdapterType::");
        switch (value) {
        case AdapterType::DiscreteGPU:
            s->Append("DiscreteGPU");
            break;
        case AdapterType::IntegratedGPU:
            s->Append("IntegratedGPU");
            break;
        case AdapterType::CPU:
            s->Append("CPU");
            break;
        case AdapterType::Unknown:
            s->Append("Unknown");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<AdapterType>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(AddressMode value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("AddressMode::");
        switch (value) {
        case AddressMode::Undefined:
            s->Append("Undefined");
            break;
        case AddressMode::ClampToEdge:
            s->Append("ClampToEdge");
            break;
        case AddressMode::Repeat:
            s->Append("Repeat");
            break;
        case AddressMode::MirrorRepeat:
            s->Append("MirrorRepeat");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<AddressMode>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(AlphaMode value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("AlphaMode::");
        switch (value) {
        case AlphaMode::Opaque:
            s->Append("Opaque");
            break;
        case AlphaMode::Premultiplied:
            s->Append("Premultiplied");
            break;
        case AlphaMode::Unpremultiplied:
            s->Append("Unpremultiplied");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<AlphaMode>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(BackendType value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("BackendType::");
        switch (value) {
        case BackendType::Undefined:
            s->Append("Undefined");
            break;
        case BackendType::Null:
            s->Append("Null");
            break;
        case BackendType::WebGPU:
            s->Append("WebGPU");
            break;
        case BackendType::D3D11:
            s->Append("D3D11");
            break;
        case BackendType::D3D12:
            s->Append("D3D12");
            break;
        case BackendType::Metal:
            s->Append("Metal");
            break;
        case BackendType::Vulkan:
            s->Append("Vulkan");
            break;
        case BackendType::OpenGL:
            s->Append("OpenGL");
            break;
        case BackendType::OpenGLES:
            s->Append("OpenGLES");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<BackendType>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(BlendFactor value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("BlendFactor::");
        switch (value) {
        case BlendFactor::Undefined:
            s->Append("Undefined");
            break;
        case BlendFactor::Zero:
            s->Append("Zero");
            break;
        case BlendFactor::One:
            s->Append("One");
            break;
        case BlendFactor::Src:
            s->Append("Src");
            break;
        case BlendFactor::OneMinusSrc:
            s->Append("OneMinusSrc");
            break;
        case BlendFactor::SrcAlpha:
            s->Append("SrcAlpha");
            break;
        case BlendFactor::OneMinusSrcAlpha:
            s->Append("OneMinusSrcAlpha");
            break;
        case BlendFactor::Dst:
            s->Append("Dst");
            break;
        case BlendFactor::OneMinusDst:
            s->Append("OneMinusDst");
            break;
        case BlendFactor::DstAlpha:
            s->Append("DstAlpha");
            break;
        case BlendFactor::OneMinusDstAlpha:
            s->Append("OneMinusDstAlpha");
            break;
        case BlendFactor::SrcAlphaSaturated:
            s->Append("SrcAlphaSaturated");
            break;
        case BlendFactor::Constant:
            s->Append("Constant");
            break;
        case BlendFactor::OneMinusConstant:
            s->Append("OneMinusConstant");
            break;
        case BlendFactor::Src1:
            s->Append("Src1");
            break;
        case BlendFactor::OneMinusSrc1:
            s->Append("OneMinusSrc1");
            break;
        case BlendFactor::Src1Alpha:
            s->Append("Src1Alpha");
            break;
        case BlendFactor::OneMinusSrc1Alpha:
            s->Append("OneMinusSrc1Alpha");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<BlendFactor>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(BlendOperation value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("BlendOperation::");
        switch (value) {
        case BlendOperation::Undefined:
            s->Append("Undefined");
            break;
        case BlendOperation::Add:
            s->Append("Add");
            break;
        case BlendOperation::Subtract:
            s->Append("Subtract");
            break;
        case BlendOperation::ReverseSubtract:
            s->Append("ReverseSubtract");
            break;
        case BlendOperation::Min:
            s->Append("Min");
            break;
        case BlendOperation::Max:
            s->Append("Max");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<BlendOperation>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(BufferBindingType value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("BufferBindingType::");
        switch (value) {
        case BufferBindingType::Undefined:
            s->Append("Undefined");
            break;
        case BufferBindingType::Uniform:
            s->Append("Uniform");
            break;
        case BufferBindingType::Storage:
            s->Append("Storage");
            break;
        case BufferBindingType::ReadOnlyStorage:
            s->Append("ReadOnlyStorage");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<BufferBindingType>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(BufferMapAsyncStatus value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("BufferMapAsyncStatus::");
        switch (value) {
        case BufferMapAsyncStatus::Success:
            s->Append("Success");
            break;
        case BufferMapAsyncStatus::InstanceDropped:
            s->Append("InstanceDropped");
            break;
        case BufferMapAsyncStatus::ValidationError:
            s->Append("ValidationError");
            break;
        case BufferMapAsyncStatus::Unknown:
            s->Append("Unknown");
            break;
        case BufferMapAsyncStatus::DeviceLost:
            s->Append("DeviceLost");
            break;
        case BufferMapAsyncStatus::DestroyedBeforeCallback:
            s->Append("DestroyedBeforeCallback");
            break;
        case BufferMapAsyncStatus::UnmappedBeforeCallback:
            s->Append("UnmappedBeforeCallback");
            break;
        case BufferMapAsyncStatus::MappingAlreadyPending:
            s->Append("MappingAlreadyPending");
            break;
        case BufferMapAsyncStatus::OffsetOutOfRange:
            s->Append("OffsetOutOfRange");
            break;
        case BufferMapAsyncStatus::SizeOutOfRange:
            s->Append("SizeOutOfRange");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<BufferMapAsyncStatus>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(BufferMapState value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("BufferMapState::");
        switch (value) {
        case BufferMapState::Unmapped:
            s->Append("Unmapped");
            break;
        case BufferMapState::Pending:
            s->Append("Pending");
            break;
        case BufferMapState::Mapped:
            s->Append("Mapped");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<BufferMapState>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(CallbackMode value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("CallbackMode::");
        switch (value) {
        case CallbackMode::WaitAnyOnly:
            s->Append("WaitAnyOnly");
            break;
        case CallbackMode::AllowProcessEvents:
            s->Append("AllowProcessEvents");
            break;
        case CallbackMode::AllowSpontaneous:
            s->Append("AllowSpontaneous");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<CallbackMode>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(CompareFunction value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("CompareFunction::");
        switch (value) {
        case CompareFunction::Undefined:
            s->Append("Undefined");
            break;
        case CompareFunction::Never:
            s->Append("Never");
            break;
        case CompareFunction::Less:
            s->Append("Less");
            break;
        case CompareFunction::Equal:
            s->Append("Equal");
            break;
        case CompareFunction::LessEqual:
            s->Append("LessEqual");
            break;
        case CompareFunction::Greater:
            s->Append("Greater");
            break;
        case CompareFunction::NotEqual:
            s->Append("NotEqual");
            break;
        case CompareFunction::GreaterEqual:
            s->Append("GreaterEqual");
            break;
        case CompareFunction::Always:
            s->Append("Always");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<CompareFunction>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(CompilationInfoRequestStatus value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("CompilationInfoRequestStatus::");
        switch (value) {
        case CompilationInfoRequestStatus::Success:
            s->Append("Success");
            break;
        case CompilationInfoRequestStatus::InstanceDropped:
            s->Append("InstanceDropped");
            break;
        case CompilationInfoRequestStatus::Error:
            s->Append("Error");
            break;
        case CompilationInfoRequestStatus::DeviceLost:
            s->Append("DeviceLost");
            break;
        case CompilationInfoRequestStatus::Unknown:
            s->Append("Unknown");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<CompilationInfoRequestStatus>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(CompilationMessageType value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("CompilationMessageType::");
        switch (value) {
        case CompilationMessageType::Error:
            s->Append("Error");
            break;
        case CompilationMessageType::Warning:
            s->Append("Warning");
            break;
        case CompilationMessageType::Info:
            s->Append("Info");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<CompilationMessageType>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(CompositeAlphaMode value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("CompositeAlphaMode::");
        switch (value) {
        case CompositeAlphaMode::Auto:
            s->Append("Auto");
            break;
        case CompositeAlphaMode::Opaque:
            s->Append("Opaque");
            break;
        case CompositeAlphaMode::Premultiplied:
            s->Append("Premultiplied");
            break;
        case CompositeAlphaMode::Unpremultiplied:
            s->Append("Unpremultiplied");
            break;
        case CompositeAlphaMode::Inherit:
            s->Append("Inherit");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<CompositeAlphaMode>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(CreatePipelineAsyncStatus value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("CreatePipelineAsyncStatus::");
        switch (value) {
        case CreatePipelineAsyncStatus::Success:
            s->Append("Success");
            break;
        case CreatePipelineAsyncStatus::InstanceDropped:
            s->Append("InstanceDropped");
            break;
        case CreatePipelineAsyncStatus::ValidationError:
            s->Append("ValidationError");
            break;
        case CreatePipelineAsyncStatus::InternalError:
            s->Append("InternalError");
            break;
        case CreatePipelineAsyncStatus::DeviceLost:
            s->Append("DeviceLost");
            break;
        case CreatePipelineAsyncStatus::DeviceDestroyed:
            s->Append("DeviceDestroyed");
            break;
        case CreatePipelineAsyncStatus::Unknown:
            s->Append("Unknown");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<CreatePipelineAsyncStatus>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(CullMode value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("CullMode::");
        switch (value) {
        case CullMode::Undefined:
            s->Append("Undefined");
            break;
        case CullMode::None:
            s->Append("None");
            break;
        case CullMode::Front:
            s->Append("Front");
            break;
        case CullMode::Back:
            s->Append("Back");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<CullMode>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(DeviceLostReason value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("DeviceLostReason::");
        switch (value) {
        case DeviceLostReason::Unknown:
            s->Append("Unknown");
            break;
        case DeviceLostReason::Destroyed:
            s->Append("Destroyed");
            break;
        case DeviceLostReason::InstanceDropped:
            s->Append("InstanceDropped");
            break;
        case DeviceLostReason::FailedCreation:
            s->Append("FailedCreation");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<DeviceLostReason>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(ErrorFilter value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("ErrorFilter::");
        switch (value) {
        case ErrorFilter::Validation:
            s->Append("Validation");
            break;
        case ErrorFilter::OutOfMemory:
            s->Append("OutOfMemory");
            break;
        case ErrorFilter::Internal:
            s->Append("Internal");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<ErrorFilter>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(ErrorType value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("ErrorType::");
        switch (value) {
        case ErrorType::NoError:
            s->Append("NoError");
            break;
        case ErrorType::Validation:
            s->Append("Validation");
            break;
        case ErrorType::OutOfMemory:
            s->Append("OutOfMemory");
            break;
        case ErrorType::Internal:
            s->Append("Internal");
            break;
        case ErrorType::Unknown:
            s->Append("Unknown");
            break;
        case ErrorType::DeviceLost:
            s->Append("DeviceLost");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<ErrorType>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(ExternalTextureRotation value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("ExternalTextureRotation::");
        switch (value) {
        case ExternalTextureRotation::Rotate0Degrees:
            s->Append("Rotate0Degrees");
            break;
        case ExternalTextureRotation::Rotate90Degrees:
            s->Append("Rotate90Degrees");
            break;
        case ExternalTextureRotation::Rotate180Degrees:
            s->Append("Rotate180Degrees");
            break;
        case ExternalTextureRotation::Rotate270Degrees:
            s->Append("Rotate270Degrees");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<ExternalTextureRotation>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(FeatureName value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("FeatureName::");
        switch (value) {
        case FeatureName::Undefined:
            s->Append("Undefined");
            break;
        case FeatureName::DepthClipControl:
            s->Append("DepthClipControl");
            break;
        case FeatureName::Depth32FloatStencil8:
            s->Append("Depth32FloatStencil8");
            break;
        case FeatureName::TimestampQuery:
            s->Append("TimestampQuery");
            break;
        case FeatureName::TextureCompressionBC:
            s->Append("TextureCompressionBC");
            break;
        case FeatureName::TextureCompressionETC2:
            s->Append("TextureCompressionETC2");
            break;
        case FeatureName::TextureCompressionASTC:
            s->Append("TextureCompressionASTC");
            break;
        case FeatureName::IndirectFirstInstance:
            s->Append("IndirectFirstInstance");
            break;
        case FeatureName::ShaderF16:
            s->Append("ShaderF16");
            break;
        case FeatureName::RG11B10UfloatRenderable:
            s->Append("RG11B10UfloatRenderable");
            break;
        case FeatureName::BGRA8UnormStorage:
            s->Append("BGRA8UnormStorage");
            break;
        case FeatureName::Float32Filterable:
            s->Append("Float32Filterable");
            break;
        case FeatureName::DawnInternalUsages:
            s->Append("DawnInternalUsages");
            break;
        case FeatureName::DawnMultiPlanarFormats:
            s->Append("DawnMultiPlanarFormats");
            break;
        case FeatureName::DawnNative:
            s->Append("DawnNative");
            break;
        case FeatureName::ChromiumExperimentalTimestampQueryInsidePasses:
            s->Append("ChromiumExperimentalTimestampQueryInsidePasses");
            break;
        case FeatureName::ImplicitDeviceSynchronization:
            s->Append("ImplicitDeviceSynchronization");
            break;
        case FeatureName::SurfaceCapabilities:
            s->Append("SurfaceCapabilities");
            break;
        case FeatureName::TransientAttachments:
            s->Append("TransientAttachments");
            break;
        case FeatureName::MSAARenderToSingleSampled:
            s->Append("MSAARenderToSingleSampled");
            break;
        case FeatureName::DualSourceBlending:
            s->Append("DualSourceBlending");
            break;
        case FeatureName::D3D11MultithreadProtected:
            s->Append("D3D11MultithreadProtected");
            break;
        case FeatureName::ANGLETextureSharing:
            s->Append("ANGLETextureSharing");
            break;
        case FeatureName::ChromiumExperimentalSubgroups:
            s->Append("ChromiumExperimentalSubgroups");
            break;
        case FeatureName::ChromiumExperimentalSubgroupUniformControlFlow:
            s->Append("ChromiumExperimentalSubgroupUniformControlFlow");
            break;
        case FeatureName::PixelLocalStorageCoherent:
            s->Append("PixelLocalStorageCoherent");
            break;
        case FeatureName::PixelLocalStorageNonCoherent:
            s->Append("PixelLocalStorageNonCoherent");
            break;
        case FeatureName::Unorm16TextureFormats:
            s->Append("Unorm16TextureFormats");
            break;
        case FeatureName::Snorm16TextureFormats:
            s->Append("Snorm16TextureFormats");
            break;
        case FeatureName::MultiPlanarFormatExtendedUsages:
            s->Append("MultiPlanarFormatExtendedUsages");
            break;
        case FeatureName::MultiPlanarFormatP010:
            s->Append("MultiPlanarFormatP010");
            break;
        case FeatureName::HostMappedPointer:
            s->Append("HostMappedPointer");
            break;
        case FeatureName::MultiPlanarRenderTargets:
            s->Append("MultiPlanarRenderTargets");
            break;
        case FeatureName::MultiPlanarFormatNv12a:
            s->Append("MultiPlanarFormatNv12a");
            break;
        case FeatureName::FramebufferFetch:
            s->Append("FramebufferFetch");
            break;
        case FeatureName::BufferMapExtendedUsages:
            s->Append("BufferMapExtendedUsages");
            break;
        case FeatureName::AdapterPropertiesMemoryHeaps:
            s->Append("AdapterPropertiesMemoryHeaps");
            break;
        case FeatureName::AdapterPropertiesD3D:
            s->Append("AdapterPropertiesD3D");
            break;
        case FeatureName::AdapterPropertiesVk:
            s->Append("AdapterPropertiesVk");
            break;
        case FeatureName::R8UnormStorage:
            s->Append("R8UnormStorage");
            break;
        case FeatureName::FormatCapabilities:
            s->Append("FormatCapabilities");
            break;
        case FeatureName::DrmFormatCapabilities:
            s->Append("DrmFormatCapabilities");
            break;
        case FeatureName::Norm16TextureFormats:
            s->Append("Norm16TextureFormats");
            break;
        case FeatureName::MultiPlanarFormatNv16:
            s->Append("MultiPlanarFormatNv16");
            break;
        case FeatureName::MultiPlanarFormatNv24:
            s->Append("MultiPlanarFormatNv24");
            break;
        case FeatureName::MultiPlanarFormatP210:
            s->Append("MultiPlanarFormatP210");
            break;
        case FeatureName::MultiPlanarFormatP410:
            s->Append("MultiPlanarFormatP410");
            break;
        case FeatureName::SharedTextureMemoryVkDedicatedAllocation:
            s->Append("SharedTextureMemoryVkDedicatedAllocation");
            break;
        case FeatureName::SharedTextureMemoryAHardwareBuffer:
            s->Append("SharedTextureMemoryAHardwareBuffer");
            break;
        case FeatureName::SharedTextureMemoryDmaBuf:
            s->Append("SharedTextureMemoryDmaBuf");
            break;
        case FeatureName::SharedTextureMemoryOpaqueFD:
            s->Append("SharedTextureMemoryOpaqueFD");
            break;
        case FeatureName::SharedTextureMemoryZirconHandle:
            s->Append("SharedTextureMemoryZirconHandle");
            break;
        case FeatureName::SharedTextureMemoryDXGISharedHandle:
            s->Append("SharedTextureMemoryDXGISharedHandle");
            break;
        case FeatureName::SharedTextureMemoryD3D11Texture2D:
            s->Append("SharedTextureMemoryD3D11Texture2D");
            break;
        case FeatureName::SharedTextureMemoryIOSurface:
            s->Append("SharedTextureMemoryIOSurface");
            break;
        case FeatureName::SharedTextureMemoryEGLImage:
            s->Append("SharedTextureMemoryEGLImage");
            break;
        case FeatureName::SharedFenceVkSemaphoreOpaqueFD:
            s->Append("SharedFenceVkSemaphoreOpaqueFD");
            break;
        case FeatureName::SharedFenceVkSemaphoreSyncFD:
            s->Append("SharedFenceVkSemaphoreSyncFD");
            break;
        case FeatureName::SharedFenceVkSemaphoreZirconHandle:
            s->Append("SharedFenceVkSemaphoreZirconHandle");
            break;
        case FeatureName::SharedFenceDXGISharedHandle:
            s->Append("SharedFenceDXGISharedHandle");
            break;
        case FeatureName::SharedFenceMTLSharedEvent:
            s->Append("SharedFenceMTLSharedEvent");
            break;
        case FeatureName::SharedBufferMemoryD3D12Resource:
            s->Append("SharedBufferMemoryD3D12Resource");
            break;
        case FeatureName::StaticSamplers:
            s->Append("StaticSamplers");
            break;
        case FeatureName::YCbCrVulkanSamplers:
            s->Append("YCbCrVulkanSamplers");
            break;
        case FeatureName::ShaderModuleCompilationOptions:
            s->Append("ShaderModuleCompilationOptions");
            break;
        case FeatureName::DawnLoadResolveTexture:
            s->Append("DawnLoadResolveTexture");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<FeatureName>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(FilterMode value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("FilterMode::");
        switch (value) {
        case FilterMode::Undefined:
            s->Append("Undefined");
            break;
        case FilterMode::Nearest:
            s->Append("Nearest");
            break;
        case FilterMode::Linear:
            s->Append("Linear");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<FilterMode>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(FrontFace value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("FrontFace::");
        switch (value) {
        case FrontFace::Undefined:
            s->Append("Undefined");
            break;
        case FrontFace::CCW:
            s->Append("CCW");
            break;
        case FrontFace::CW:
            s->Append("CW");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<FrontFace>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(IndexFormat value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("IndexFormat::");
        switch (value) {
        case IndexFormat::Undefined:
            s->Append("Undefined");
            break;
        case IndexFormat::Uint16:
            s->Append("Uint16");
            break;
        case IndexFormat::Uint32:
            s->Append("Uint32");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<IndexFormat>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(LoadOp value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("LoadOp::");
        switch (value) {
        case LoadOp::Undefined:
            s->Append("Undefined");
            break;
        case LoadOp::Clear:
            s->Append("Clear");
            break;
        case LoadOp::Load:
            s->Append("Load");
            break;
        case LoadOp::ExpandResolveTexture:
            s->Append("ExpandResolveTexture");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<LoadOp>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(LoggingType value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("LoggingType::");
        switch (value) {
        case LoggingType::Verbose:
            s->Append("Verbose");
            break;
        case LoggingType::Info:
            s->Append("Info");
            break;
        case LoggingType::Warning:
            s->Append("Warning");
            break;
        case LoggingType::Error:
            s->Append("Error");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<LoggingType>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(MipmapFilterMode value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("MipmapFilterMode::");
        switch (value) {
        case MipmapFilterMode::Undefined:
            s->Append("Undefined");
            break;
        case MipmapFilterMode::Nearest:
            s->Append("Nearest");
            break;
        case MipmapFilterMode::Linear:
            s->Append("Linear");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<MipmapFilterMode>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(PopErrorScopeStatus value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("PopErrorScopeStatus::");
        switch (value) {
        case PopErrorScopeStatus::Success:
            s->Append("Success");
            break;
        case PopErrorScopeStatus::InstanceDropped:
            s->Append("InstanceDropped");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<PopErrorScopeStatus>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(PowerPreference value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("PowerPreference::");
        switch (value) {
        case PowerPreference::Undefined:
            s->Append("Undefined");
            break;
        case PowerPreference::LowPower:
            s->Append("LowPower");
            break;
        case PowerPreference::HighPerformance:
            s->Append("HighPerformance");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<PowerPreference>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(PresentMode value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("PresentMode::");
        switch (value) {
        case PresentMode::Fifo:
            s->Append("Fifo");
            break;
        case PresentMode::FifoRelaxed:
            s->Append("FifoRelaxed");
            break;
        case PresentMode::Immediate:
            s->Append("Immediate");
            break;
        case PresentMode::Mailbox:
            s->Append("Mailbox");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<PresentMode>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(PrimitiveTopology value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("PrimitiveTopology::");
        switch (value) {
        case PrimitiveTopology::Undefined:
            s->Append("Undefined");
            break;
        case PrimitiveTopology::PointList:
            s->Append("PointList");
            break;
        case PrimitiveTopology::LineList:
            s->Append("LineList");
            break;
        case PrimitiveTopology::LineStrip:
            s->Append("LineStrip");
            break;
        case PrimitiveTopology::TriangleList:
            s->Append("TriangleList");
            break;
        case PrimitiveTopology::TriangleStrip:
            s->Append("TriangleStrip");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<PrimitiveTopology>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(QueryType value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("QueryType::");
        switch (value) {
        case QueryType::Occlusion:
            s->Append("Occlusion");
            break;
        case QueryType::Timestamp:
            s->Append("Timestamp");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<QueryType>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(QueueWorkDoneStatus value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("QueueWorkDoneStatus::");
        switch (value) {
        case QueueWorkDoneStatus::Success:
            s->Append("Success");
            break;
        case QueueWorkDoneStatus::InstanceDropped:
            s->Append("InstanceDropped");
            break;
        case QueueWorkDoneStatus::Error:
            s->Append("Error");
            break;
        case QueueWorkDoneStatus::Unknown:
            s->Append("Unknown");
            break;
        case QueueWorkDoneStatus::DeviceLost:
            s->Append("DeviceLost");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<QueueWorkDoneStatus>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(RequestAdapterStatus value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("RequestAdapterStatus::");
        switch (value) {
        case RequestAdapterStatus::Success:
            s->Append("Success");
            break;
        case RequestAdapterStatus::InstanceDropped:
            s->Append("InstanceDropped");
            break;
        case RequestAdapterStatus::Unavailable:
            s->Append("Unavailable");
            break;
        case RequestAdapterStatus::Error:
            s->Append("Error");
            break;
        case RequestAdapterStatus::Unknown:
            s->Append("Unknown");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<RequestAdapterStatus>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(RequestDeviceStatus value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("RequestDeviceStatus::");
        switch (value) {
        case RequestDeviceStatus::Success:
            s->Append("Success");
            break;
        case RequestDeviceStatus::InstanceDropped:
            s->Append("InstanceDropped");
            break;
        case RequestDeviceStatus::Error:
            s->Append("Error");
            break;
        case RequestDeviceStatus::Unknown:
            s->Append("Unknown");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<RequestDeviceStatus>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(SType value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("SType::");
        switch (value) {
        case SType::Invalid:
            s->Append("Invalid");
            break;
        case SType::SurfaceDescriptorFromMetalLayer:
            s->Append("SurfaceDescriptorFromMetalLayer");
            break;
        case SType::SurfaceDescriptorFromWindowsHWND:
            s->Append("SurfaceDescriptorFromWindowsHWND");
            break;
        case SType::SurfaceDescriptorFromXlibWindow:
            s->Append("SurfaceDescriptorFromXlibWindow");
            break;
        case SType::SurfaceDescriptorFromCanvasHTMLSelector:
            s->Append("SurfaceDescriptorFromCanvasHTMLSelector");
            break;
        case SType::ShaderModuleSPIRVDescriptor:
            s->Append("ShaderModuleSPIRVDescriptor");
            break;
        case SType::ShaderModuleWGSLDescriptor:
            s->Append("ShaderModuleWGSLDescriptor");
            break;
        case SType::PrimitiveDepthClipControl:
            s->Append("PrimitiveDepthClipControl");
            break;
        case SType::SurfaceDescriptorFromWaylandSurface:
            s->Append("SurfaceDescriptorFromWaylandSurface");
            break;
        case SType::SurfaceDescriptorFromAndroidNativeWindow:
            s->Append("SurfaceDescriptorFromAndroidNativeWindow");
            break;
        case SType::SurfaceDescriptorFromWindowsCoreWindow:
            s->Append("SurfaceDescriptorFromWindowsCoreWindow");
            break;
        case SType::ExternalTextureBindingEntry:
            s->Append("ExternalTextureBindingEntry");
            break;
        case SType::ExternalTextureBindingLayout:
            s->Append("ExternalTextureBindingLayout");
            break;
        case SType::SurfaceDescriptorFromWindowsSwapChainPanel:
            s->Append("SurfaceDescriptorFromWindowsSwapChainPanel");
            break;
        case SType::RenderPassDescriptorMaxDrawCount:
            s->Append("RenderPassDescriptorMaxDrawCount");
            break;
        case SType::DepthStencilStateDepthWriteDefinedDawn:
            s->Append("DepthStencilStateDepthWriteDefinedDawn");
            break;
        case SType::TextureBindingViewDimensionDescriptor:
            s->Append("TextureBindingViewDimensionDescriptor");
            break;
        case SType::DawnTextureInternalUsageDescriptor:
            s->Append("DawnTextureInternalUsageDescriptor");
            break;
        case SType::DawnEncoderInternalUsageDescriptor:
            s->Append("DawnEncoderInternalUsageDescriptor");
            break;
        case SType::DawnInstanceDescriptor:
            s->Append("DawnInstanceDescriptor");
            break;
        case SType::DawnCacheDeviceDescriptor:
            s->Append("DawnCacheDeviceDescriptor");
            break;
        case SType::DawnAdapterPropertiesPowerPreference:
            s->Append("DawnAdapterPropertiesPowerPreference");
            break;
        case SType::DawnBufferDescriptorErrorInfoFromWireClient:
            s->Append("DawnBufferDescriptorErrorInfoFromWireClient");
            break;
        case SType::DawnTogglesDescriptor:
            s->Append("DawnTogglesDescriptor");
            break;
        case SType::DawnShaderModuleSPIRVOptionsDescriptor:
            s->Append("DawnShaderModuleSPIRVOptionsDescriptor");
            break;
        case SType::RequestAdapterOptionsLUID:
            s->Append("RequestAdapterOptionsLUID");
            break;
        case SType::RequestAdapterOptionsGetGLProc:
            s->Append("RequestAdapterOptionsGetGLProc");
            break;
        case SType::RequestAdapterOptionsD3D11Device:
            s->Append("RequestAdapterOptionsD3D11Device");
            break;
        case SType::DawnMultisampleStateRenderToSingleSampled:
            s->Append("DawnMultisampleStateRenderToSingleSampled");
            break;
        case SType::DawnRenderPassColorAttachmentRenderToSingleSampled:
            s->Append("DawnRenderPassColorAttachmentRenderToSingleSampled");
            break;
        case SType::RenderPassPixelLocalStorage:
            s->Append("RenderPassPixelLocalStorage");
            break;
        case SType::PipelineLayoutPixelLocalStorage:
            s->Append("PipelineLayoutPixelLocalStorage");
            break;
        case SType::BufferHostMappedPointer:
            s->Append("BufferHostMappedPointer");
            break;
        case SType::DawnExperimentalSubgroupLimits:
            s->Append("DawnExperimentalSubgroupLimits");
            break;
        case SType::AdapterPropertiesMemoryHeaps:
            s->Append("AdapterPropertiesMemoryHeaps");
            break;
        case SType::AdapterPropertiesD3D:
            s->Append("AdapterPropertiesD3D");
            break;
        case SType::AdapterPropertiesVk:
            s->Append("AdapterPropertiesVk");
            break;
        case SType::DawnComputePipelineFullSubgroups:
            s->Append("DawnComputePipelineFullSubgroups");
            break;
        case SType::DawnWireWGSLControl:
            s->Append("DawnWireWGSLControl");
            break;
        case SType::DawnWGSLBlocklist:
            s->Append("DawnWGSLBlocklist");
            break;
        case SType::DrmFormatCapabilities:
            s->Append("DrmFormatCapabilities");
            break;
        case SType::ShaderModuleCompilationOptions:
            s->Append("ShaderModuleCompilationOptions");
            break;
        case SType::ColorTargetStateExpandResolveTextureDawn:
            s->Append("ColorTargetStateExpandResolveTextureDawn");
            break;
        case SType::SharedTextureMemoryVkDedicatedAllocationDescriptor:
            s->Append("SharedTextureMemoryVkDedicatedAllocationDescriptor");
            break;
        case SType::SharedTextureMemoryAHardwareBufferDescriptor:
            s->Append("SharedTextureMemoryAHardwareBufferDescriptor");
            break;
        case SType::SharedTextureMemoryDmaBufDescriptor:
            s->Append("SharedTextureMemoryDmaBufDescriptor");
            break;
        case SType::SharedTextureMemoryOpaqueFDDescriptor:
            s->Append("SharedTextureMemoryOpaqueFDDescriptor");
            break;
        case SType::SharedTextureMemoryZirconHandleDescriptor:
            s->Append("SharedTextureMemoryZirconHandleDescriptor");
            break;
        case SType::SharedTextureMemoryDXGISharedHandleDescriptor:
            s->Append("SharedTextureMemoryDXGISharedHandleDescriptor");
            break;
        case SType::SharedTextureMemoryD3D11Texture2DDescriptor:
            s->Append("SharedTextureMemoryD3D11Texture2DDescriptor");
            break;
        case SType::SharedTextureMemoryIOSurfaceDescriptor:
            s->Append("SharedTextureMemoryIOSurfaceDescriptor");
            break;
        case SType::SharedTextureMemoryEGLImageDescriptor:
            s->Append("SharedTextureMemoryEGLImageDescriptor");
            break;
        case SType::SharedTextureMemoryInitializedBeginState:
            s->Append("SharedTextureMemoryInitializedBeginState");
            break;
        case SType::SharedTextureMemoryInitializedEndState:
            s->Append("SharedTextureMemoryInitializedEndState");
            break;
        case SType::SharedTextureMemoryVkImageLayoutBeginState:
            s->Append("SharedTextureMemoryVkImageLayoutBeginState");
            break;
        case SType::SharedTextureMemoryVkImageLayoutEndState:
            s->Append("SharedTextureMemoryVkImageLayoutEndState");
            break;
        case SType::SharedTextureMemoryD3DSwapchainBeginState:
            s->Append("SharedTextureMemoryD3DSwapchainBeginState");
            break;
        case SType::SharedFenceVkSemaphoreOpaqueFDDescriptor:
            s->Append("SharedFenceVkSemaphoreOpaqueFDDescriptor");
            break;
        case SType::SharedFenceVkSemaphoreOpaqueFDExportInfo:
            s->Append("SharedFenceVkSemaphoreOpaqueFDExportInfo");
            break;
        case SType::SharedFenceVkSemaphoreSyncFDDescriptor:
            s->Append("SharedFenceVkSemaphoreSyncFDDescriptor");
            break;
        case SType::SharedFenceVkSemaphoreSyncFDExportInfo:
            s->Append("SharedFenceVkSemaphoreSyncFDExportInfo");
            break;
        case SType::SharedFenceVkSemaphoreZirconHandleDescriptor:
            s->Append("SharedFenceVkSemaphoreZirconHandleDescriptor");
            break;
        case SType::SharedFenceVkSemaphoreZirconHandleExportInfo:
            s->Append("SharedFenceVkSemaphoreZirconHandleExportInfo");
            break;
        case SType::SharedFenceDXGISharedHandleDescriptor:
            s->Append("SharedFenceDXGISharedHandleDescriptor");
            break;
        case SType::SharedFenceDXGISharedHandleExportInfo:
            s->Append("SharedFenceDXGISharedHandleExportInfo");
            break;
        case SType::SharedFenceMTLSharedEventDescriptor:
            s->Append("SharedFenceMTLSharedEventDescriptor");
            break;
        case SType::SharedFenceMTLSharedEventExportInfo:
            s->Append("SharedFenceMTLSharedEventExportInfo");
            break;
        case SType::SharedBufferMemoryD3D12ResourceDescriptor:
            s->Append("SharedBufferMemoryD3D12ResourceDescriptor");
            break;
        case SType::StaticSamplerBindingLayout:
            s->Append("StaticSamplerBindingLayout");
            break;
        case SType::YCbCrVkDescriptor:
            s->Append("YCbCrVkDescriptor");
            break;
        case SType::SharedTextureMemoryAHardwareBufferProperties:
            s->Append("SharedTextureMemoryAHardwareBufferProperties");
            break;
        case SType::AHardwareBufferProperties:
            s->Append("AHardwareBufferProperties");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<SType>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(SamplerBindingType value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("SamplerBindingType::");
        switch (value) {
        case SamplerBindingType::Undefined:
            s->Append("Undefined");
            break;
        case SamplerBindingType::Filtering:
            s->Append("Filtering");
            break;
        case SamplerBindingType::NonFiltering:
            s->Append("NonFiltering");
            break;
        case SamplerBindingType::Comparison:
            s->Append("Comparison");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<SamplerBindingType>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(SharedFenceType value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("SharedFenceType::");
        switch (value) {
        case SharedFenceType::Undefined:
            s->Append("Undefined");
            break;
        case SharedFenceType::VkSemaphoreOpaqueFD:
            s->Append("VkSemaphoreOpaqueFD");
            break;
        case SharedFenceType::VkSemaphoreSyncFD:
            s->Append("VkSemaphoreSyncFD");
            break;
        case SharedFenceType::VkSemaphoreZirconHandle:
            s->Append("VkSemaphoreZirconHandle");
            break;
        case SharedFenceType::DXGISharedHandle:
            s->Append("DXGISharedHandle");
            break;
        case SharedFenceType::MTLSharedEvent:
            s->Append("MTLSharedEvent");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<SharedFenceType>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(Status value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("Status::");
        switch (value) {
        case Status::Success:
            s->Append("Success");
            break;
        case Status::Error:
            s->Append("Error");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<Status>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(StencilOperation value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("StencilOperation::");
        switch (value) {
        case StencilOperation::Undefined:
            s->Append("Undefined");
            break;
        case StencilOperation::Keep:
            s->Append("Keep");
            break;
        case StencilOperation::Zero:
            s->Append("Zero");
            break;
        case StencilOperation::Replace:
            s->Append("Replace");
            break;
        case StencilOperation::Invert:
            s->Append("Invert");
            break;
        case StencilOperation::IncrementClamp:
            s->Append("IncrementClamp");
            break;
        case StencilOperation::DecrementClamp:
            s->Append("DecrementClamp");
            break;
        case StencilOperation::IncrementWrap:
            s->Append("IncrementWrap");
            break;
        case StencilOperation::DecrementWrap:
            s->Append("DecrementWrap");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<StencilOperation>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(StorageTextureAccess value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("StorageTextureAccess::");
        switch (value) {
        case StorageTextureAccess::Undefined:
            s->Append("Undefined");
            break;
        case StorageTextureAccess::WriteOnly:
            s->Append("WriteOnly");
            break;
        case StorageTextureAccess::ReadOnly:
            s->Append("ReadOnly");
            break;
        case StorageTextureAccess::ReadWrite:
            s->Append("ReadWrite");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<StorageTextureAccess>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(StoreOp value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("StoreOp::");
        switch (value) {
        case StoreOp::Undefined:
            s->Append("Undefined");
            break;
        case StoreOp::Store:
            s->Append("Store");
            break;
        case StoreOp::Discard:
            s->Append("Discard");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<StoreOp>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(SurfaceGetCurrentTextureStatus value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("SurfaceGetCurrentTextureStatus::");
        switch (value) {
        case SurfaceGetCurrentTextureStatus::Success:
            s->Append("Success");
            break;
        case SurfaceGetCurrentTextureStatus::Timeout:
            s->Append("Timeout");
            break;
        case SurfaceGetCurrentTextureStatus::Outdated:
            s->Append("Outdated");
            break;
        case SurfaceGetCurrentTextureStatus::Lost:
            s->Append("Lost");
            break;
        case SurfaceGetCurrentTextureStatus::OutOfMemory:
            s->Append("OutOfMemory");
            break;
        case SurfaceGetCurrentTextureStatus::DeviceLost:
            s->Append("DeviceLost");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<SurfaceGetCurrentTextureStatus>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(TextureAspect value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("TextureAspect::");
        switch (value) {
        case TextureAspect::Undefined:
            s->Append("Undefined");
            break;
        case TextureAspect::All:
            s->Append("All");
            break;
        case TextureAspect::StencilOnly:
            s->Append("StencilOnly");
            break;
        case TextureAspect::DepthOnly:
            s->Append("DepthOnly");
            break;
        case TextureAspect::Plane0Only:
            s->Append("Plane0Only");
            break;
        case TextureAspect::Plane1Only:
            s->Append("Plane1Only");
            break;
        case TextureAspect::Plane2Only:
            s->Append("Plane2Only");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<TextureAspect>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(TextureDimension value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("TextureDimension::");
        switch (value) {
        case TextureDimension::Undefined:
            s->Append("Undefined");
            break;
        case TextureDimension::e1D:
            s->Append("e1D");
            break;
        case TextureDimension::e2D:
            s->Append("e2D");
            break;
        case TextureDimension::e3D:
            s->Append("e3D");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<TextureDimension>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(TextureFormat value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("TextureFormat::");
        switch (value) {
        case TextureFormat::Undefined:
            s->Append("Undefined");
            break;
        case TextureFormat::R8Unorm:
            s->Append("R8Unorm");
            break;
        case TextureFormat::R8Snorm:
            s->Append("R8Snorm");
            break;
        case TextureFormat::R8Uint:
            s->Append("R8Uint");
            break;
        case TextureFormat::R8Sint:
            s->Append("R8Sint");
            break;
        case TextureFormat::R16Uint:
            s->Append("R16Uint");
            break;
        case TextureFormat::R16Sint:
            s->Append("R16Sint");
            break;
        case TextureFormat::R16Float:
            s->Append("R16Float");
            break;
        case TextureFormat::RG8Unorm:
            s->Append("RG8Unorm");
            break;
        case TextureFormat::RG8Snorm:
            s->Append("RG8Snorm");
            break;
        case TextureFormat::RG8Uint:
            s->Append("RG8Uint");
            break;
        case TextureFormat::RG8Sint:
            s->Append("RG8Sint");
            break;
        case TextureFormat::R32Float:
            s->Append("R32Float");
            break;
        case TextureFormat::R32Uint:
            s->Append("R32Uint");
            break;
        case TextureFormat::R32Sint:
            s->Append("R32Sint");
            break;
        case TextureFormat::RG16Uint:
            s->Append("RG16Uint");
            break;
        case TextureFormat::RG16Sint:
            s->Append("RG16Sint");
            break;
        case TextureFormat::RG16Float:
            s->Append("RG16Float");
            break;
        case TextureFormat::RGBA8Unorm:
            s->Append("RGBA8Unorm");
            break;
        case TextureFormat::RGBA8UnormSrgb:
            s->Append("RGBA8UnormSrgb");
            break;
        case TextureFormat::RGBA8Snorm:
            s->Append("RGBA8Snorm");
            break;
        case TextureFormat::RGBA8Uint:
            s->Append("RGBA8Uint");
            break;
        case TextureFormat::RGBA8Sint:
            s->Append("RGBA8Sint");
            break;
        case TextureFormat::BGRA8Unorm:
            s->Append("BGRA8Unorm");
            break;
        case TextureFormat::BGRA8UnormSrgb:
            s->Append("BGRA8UnormSrgb");
            break;
        case TextureFormat::RGB10A2Uint:
            s->Append("RGB10A2Uint");
            break;
        case TextureFormat::RGB10A2Unorm:
            s->Append("RGB10A2Unorm");
            break;
        case TextureFormat::RG11B10Ufloat:
            s->Append("RG11B10Ufloat");
            break;
        case TextureFormat::RGB9E5Ufloat:
            s->Append("RGB9E5Ufloat");
            break;
        case TextureFormat::RG32Float:
            s->Append("RG32Float");
            break;
        case TextureFormat::RG32Uint:
            s->Append("RG32Uint");
            break;
        case TextureFormat::RG32Sint:
            s->Append("RG32Sint");
            break;
        case TextureFormat::RGBA16Uint:
            s->Append("RGBA16Uint");
            break;
        case TextureFormat::RGBA16Sint:
            s->Append("RGBA16Sint");
            break;
        case TextureFormat::RGBA16Float:
            s->Append("RGBA16Float");
            break;
        case TextureFormat::RGBA32Float:
            s->Append("RGBA32Float");
            break;
        case TextureFormat::RGBA32Uint:
            s->Append("RGBA32Uint");
            break;
        case TextureFormat::RGBA32Sint:
            s->Append("RGBA32Sint");
            break;
        case TextureFormat::Stencil8:
            s->Append("Stencil8");
            break;
        case TextureFormat::Depth16Unorm:
            s->Append("Depth16Unorm");
            break;
        case TextureFormat::Depth24Plus:
            s->Append("Depth24Plus");
            break;
        case TextureFormat::Depth24PlusStencil8:
            s->Append("Depth24PlusStencil8");
            break;
        case TextureFormat::Depth32Float:
            s->Append("Depth32Float");
            break;
        case TextureFormat::Depth32FloatStencil8:
            s->Append("Depth32FloatStencil8");
            break;
        case TextureFormat::BC1RGBAUnorm:
            s->Append("BC1RGBAUnorm");
            break;
        case TextureFormat::BC1RGBAUnormSrgb:
            s->Append("BC1RGBAUnormSrgb");
            break;
        case TextureFormat::BC2RGBAUnorm:
            s->Append("BC2RGBAUnorm");
            break;
        case TextureFormat::BC2RGBAUnormSrgb:
            s->Append("BC2RGBAUnormSrgb");
            break;
        case TextureFormat::BC3RGBAUnorm:
            s->Append("BC3RGBAUnorm");
            break;
        case TextureFormat::BC3RGBAUnormSrgb:
            s->Append("BC3RGBAUnormSrgb");
            break;
        case TextureFormat::BC4RUnorm:
            s->Append("BC4RUnorm");
            break;
        case TextureFormat::BC4RSnorm:
            s->Append("BC4RSnorm");
            break;
        case TextureFormat::BC5RGUnorm:
            s->Append("BC5RGUnorm");
            break;
        case TextureFormat::BC5RGSnorm:
            s->Append("BC5RGSnorm");
            break;
        case TextureFormat::BC6HRGBUfloat:
            s->Append("BC6HRGBUfloat");
            break;
        case TextureFormat::BC6HRGBFloat:
            s->Append("BC6HRGBFloat");
            break;
        case TextureFormat::BC7RGBAUnorm:
            s->Append("BC7RGBAUnorm");
            break;
        case TextureFormat::BC7RGBAUnormSrgb:
            s->Append("BC7RGBAUnormSrgb");
            break;
        case TextureFormat::ETC2RGB8Unorm:
            s->Append("ETC2RGB8Unorm");
            break;
        case TextureFormat::ETC2RGB8UnormSrgb:
            s->Append("ETC2RGB8UnormSrgb");
            break;
        case TextureFormat::ETC2RGB8A1Unorm:
            s->Append("ETC2RGB8A1Unorm");
            break;
        case TextureFormat::ETC2RGB8A1UnormSrgb:
            s->Append("ETC2RGB8A1UnormSrgb");
            break;
        case TextureFormat::ETC2RGBA8Unorm:
            s->Append("ETC2RGBA8Unorm");
            break;
        case TextureFormat::ETC2RGBA8UnormSrgb:
            s->Append("ETC2RGBA8UnormSrgb");
            break;
        case TextureFormat::EACR11Unorm:
            s->Append("EACR11Unorm");
            break;
        case TextureFormat::EACR11Snorm:
            s->Append("EACR11Snorm");
            break;
        case TextureFormat::EACRG11Unorm:
            s->Append("EACRG11Unorm");
            break;
        case TextureFormat::EACRG11Snorm:
            s->Append("EACRG11Snorm");
            break;
        case TextureFormat::ASTC4x4Unorm:
            s->Append("ASTC4x4Unorm");
            break;
        case TextureFormat::ASTC4x4UnormSrgb:
            s->Append("ASTC4x4UnormSrgb");
            break;
        case TextureFormat::ASTC5x4Unorm:
            s->Append("ASTC5x4Unorm");
            break;
        case TextureFormat::ASTC5x4UnormSrgb:
            s->Append("ASTC5x4UnormSrgb");
            break;
        case TextureFormat::ASTC5x5Unorm:
            s->Append("ASTC5x5Unorm");
            break;
        case TextureFormat::ASTC5x5UnormSrgb:
            s->Append("ASTC5x5UnormSrgb");
            break;
        case TextureFormat::ASTC6x5Unorm:
            s->Append("ASTC6x5Unorm");
            break;
        case TextureFormat::ASTC6x5UnormSrgb:
            s->Append("ASTC6x5UnormSrgb");
            break;
        case TextureFormat::ASTC6x6Unorm:
            s->Append("ASTC6x6Unorm");
            break;
        case TextureFormat::ASTC6x6UnormSrgb:
            s->Append("ASTC6x6UnormSrgb");
            break;
        case TextureFormat::ASTC8x5Unorm:
            s->Append("ASTC8x5Unorm");
            break;
        case TextureFormat::ASTC8x5UnormSrgb:
            s->Append("ASTC8x5UnormSrgb");
            break;
        case TextureFormat::ASTC8x6Unorm:
            s->Append("ASTC8x6Unorm");
            break;
        case TextureFormat::ASTC8x6UnormSrgb:
            s->Append("ASTC8x6UnormSrgb");
            break;
        case TextureFormat::ASTC8x8Unorm:
            s->Append("ASTC8x8Unorm");
            break;
        case TextureFormat::ASTC8x8UnormSrgb:
            s->Append("ASTC8x8UnormSrgb");
            break;
        case TextureFormat::ASTC10x5Unorm:
            s->Append("ASTC10x5Unorm");
            break;
        case TextureFormat::ASTC10x5UnormSrgb:
            s->Append("ASTC10x5UnormSrgb");
            break;
        case TextureFormat::ASTC10x6Unorm:
            s->Append("ASTC10x6Unorm");
            break;
        case TextureFormat::ASTC10x6UnormSrgb:
            s->Append("ASTC10x6UnormSrgb");
            break;
        case TextureFormat::ASTC10x8Unorm:
            s->Append("ASTC10x8Unorm");
            break;
        case TextureFormat::ASTC10x8UnormSrgb:
            s->Append("ASTC10x8UnormSrgb");
            break;
        case TextureFormat::ASTC10x10Unorm:
            s->Append("ASTC10x10Unorm");
            break;
        case TextureFormat::ASTC10x10UnormSrgb:
            s->Append("ASTC10x10UnormSrgb");
            break;
        case TextureFormat::ASTC12x10Unorm:
            s->Append("ASTC12x10Unorm");
            break;
        case TextureFormat::ASTC12x10UnormSrgb:
            s->Append("ASTC12x10UnormSrgb");
            break;
        case TextureFormat::ASTC12x12Unorm:
            s->Append("ASTC12x12Unorm");
            break;
        case TextureFormat::ASTC12x12UnormSrgb:
            s->Append("ASTC12x12UnormSrgb");
            break;
        case TextureFormat::R16Unorm:
            s->Append("R16Unorm");
            break;
        case TextureFormat::RG16Unorm:
            s->Append("RG16Unorm");
            break;
        case TextureFormat::RGBA16Unorm:
            s->Append("RGBA16Unorm");
            break;
        case TextureFormat::R16Snorm:
            s->Append("R16Snorm");
            break;
        case TextureFormat::RG16Snorm:
            s->Append("RG16Snorm");
            break;
        case TextureFormat::RGBA16Snorm:
            s->Append("RGBA16Snorm");
            break;
        case TextureFormat::R8BG8Biplanar420Unorm:
            s->Append("R8BG8Biplanar420Unorm");
            break;
        case TextureFormat::R10X6BG10X6Biplanar420Unorm:
            s->Append("R10X6BG10X6Biplanar420Unorm");
            break;
        case TextureFormat::R8BG8A8Triplanar420Unorm:
            s->Append("R8BG8A8Triplanar420Unorm");
            break;
        case TextureFormat::R8BG8Biplanar422Unorm:
            s->Append("R8BG8Biplanar422Unorm");
            break;
        case TextureFormat::R8BG8Biplanar444Unorm:
            s->Append("R8BG8Biplanar444Unorm");
            break;
        case TextureFormat::R10X6BG10X6Biplanar422Unorm:
            s->Append("R10X6BG10X6Biplanar422Unorm");
            break;
        case TextureFormat::R10X6BG10X6Biplanar444Unorm:
            s->Append("R10X6BG10X6Biplanar444Unorm");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<TextureFormat>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(TextureSampleType value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("TextureSampleType::");
        switch (value) {
        case TextureSampleType::Undefined:
            s->Append("Undefined");
            break;
        case TextureSampleType::Float:
            s->Append("Float");
            break;
        case TextureSampleType::UnfilterableFloat:
            s->Append("UnfilterableFloat");
            break;
        case TextureSampleType::Depth:
            s->Append("Depth");
            break;
        case TextureSampleType::Sint:
            s->Append("Sint");
            break;
        case TextureSampleType::Uint:
            s->Append("Uint");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<TextureSampleType>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(TextureViewDimension value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("TextureViewDimension::");
        switch (value) {
        case TextureViewDimension::Undefined:
            s->Append("Undefined");
            break;
        case TextureViewDimension::e1D:
            s->Append("e1D");
            break;
        case TextureViewDimension::e2D:
            s->Append("e2D");
            break;
        case TextureViewDimension::e2DArray:
            s->Append("e2DArray");
            break;
        case TextureViewDimension::Cube:
            s->Append("Cube");
            break;
        case TextureViewDimension::CubeArray:
            s->Append("CubeArray");
            break;
        case TextureViewDimension::e3D:
            s->Append("e3D");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<TextureViewDimension>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(VertexFormat value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("VertexFormat::");
        switch (value) {
        case VertexFormat::Undefined:
            s->Append("Undefined");
            break;
        case VertexFormat::Uint8x2:
            s->Append("Uint8x2");
            break;
        case VertexFormat::Uint8x4:
            s->Append("Uint8x4");
            break;
        case VertexFormat::Sint8x2:
            s->Append("Sint8x2");
            break;
        case VertexFormat::Sint8x4:
            s->Append("Sint8x4");
            break;
        case VertexFormat::Unorm8x2:
            s->Append("Unorm8x2");
            break;
        case VertexFormat::Unorm8x4:
            s->Append("Unorm8x4");
            break;
        case VertexFormat::Snorm8x2:
            s->Append("Snorm8x2");
            break;
        case VertexFormat::Snorm8x4:
            s->Append("Snorm8x4");
            break;
        case VertexFormat::Uint16x2:
            s->Append("Uint16x2");
            break;
        case VertexFormat::Uint16x4:
            s->Append("Uint16x4");
            break;
        case VertexFormat::Sint16x2:
            s->Append("Sint16x2");
            break;
        case VertexFormat::Sint16x4:
            s->Append("Sint16x4");
            break;
        case VertexFormat::Unorm16x2:
            s->Append("Unorm16x2");
            break;
        case VertexFormat::Unorm16x4:
            s->Append("Unorm16x4");
            break;
        case VertexFormat::Snorm16x2:
            s->Append("Snorm16x2");
            break;
        case VertexFormat::Snorm16x4:
            s->Append("Snorm16x4");
            break;
        case VertexFormat::Float16x2:
            s->Append("Float16x2");
            break;
        case VertexFormat::Float16x4:
            s->Append("Float16x4");
            break;
        case VertexFormat::Float32:
            s->Append("Float32");
            break;
        case VertexFormat::Float32x2:
            s->Append("Float32x2");
            break;
        case VertexFormat::Float32x3:
            s->Append("Float32x3");
            break;
        case VertexFormat::Float32x4:
            s->Append("Float32x4");
            break;
        case VertexFormat::Uint32:
            s->Append("Uint32");
            break;
        case VertexFormat::Uint32x2:
            s->Append("Uint32x2");
            break;
        case VertexFormat::Uint32x3:
            s->Append("Uint32x3");
            break;
        case VertexFormat::Uint32x4:
            s->Append("Uint32x4");
            break;
        case VertexFormat::Sint32:
            s->Append("Sint32");
            break;
        case VertexFormat::Sint32x2:
            s->Append("Sint32x2");
            break;
        case VertexFormat::Sint32x3:
            s->Append("Sint32x3");
            break;
        case VertexFormat::Sint32x4:
            s->Append("Sint32x4");
            break;
        case VertexFormat::Unorm10_10_10_2:
            s->Append("Unorm10_10_10_2");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<VertexFormat>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(VertexStepMode value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("VertexStepMode::");
        switch (value) {
        case VertexStepMode::Undefined:
            s->Append("Undefined");
            break;
        case VertexStepMode::VertexBufferNotUsed:
            s->Append("VertexBufferNotUsed");
            break;
        case VertexStepMode::Vertex:
            s->Append("Vertex");
            break;
        case VertexStepMode::Instance:
            s->Append("Instance");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<VertexStepMode>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(WaitStatus value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("WaitStatus::");
        switch (value) {
        case WaitStatus::Success:
            s->Append("Success");
            break;
        case WaitStatus::TimedOut:
            s->Append("TimedOut");
            break;
        case WaitStatus::UnsupportedTimeout:
            s->Append("UnsupportedTimeout");
            break;
        case WaitStatus::UnsupportedCount:
            s->Append("UnsupportedCount");
            break;
        case WaitStatus::UnsupportedMixedSources:
            s->Append("UnsupportedMixedSources");
            break;
        case WaitStatus::Unknown:
            s->Append("Unknown");
            break;
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<WaitStatus>::type>(value)));
    }
    return {true};
}

    //
    // Bitmasks
    //

absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(BufferUsage value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("BufferUsage::");
        if (!static_cast<bool>(value)) {
            // 0 is often explicitly declared as None.
            s->Append("None");
            return {true};
        }

        bool moreThanOneBit = !HasZeroOrOneBits(value);
        if (moreThanOneBit) {
            s->Append("(");
        }

        bool first = true;
        if (value & BufferUsage::MapRead) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("MapRead");
            value &= ~BufferUsage::MapRead;
        }
        if (value & BufferUsage::MapWrite) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("MapWrite");
            value &= ~BufferUsage::MapWrite;
        }
        if (value & BufferUsage::CopySrc) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("CopySrc");
            value &= ~BufferUsage::CopySrc;
        }
        if (value & BufferUsage::CopyDst) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("CopyDst");
            value &= ~BufferUsage::CopyDst;
        }
        if (value & BufferUsage::Index) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("Index");
            value &= ~BufferUsage::Index;
        }
        if (value & BufferUsage::Vertex) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("Vertex");
            value &= ~BufferUsage::Vertex;
        }
        if (value & BufferUsage::Uniform) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("Uniform");
            value &= ~BufferUsage::Uniform;
        }
        if (value & BufferUsage::Storage) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("Storage");
            value &= ~BufferUsage::Storage;
        }
        if (value & BufferUsage::Indirect) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("Indirect");
            value &= ~BufferUsage::Indirect;
        }
        if (value & BufferUsage::QueryResolve) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("QueryResolve");
            value &= ~BufferUsage::QueryResolve;
        }

        if (static_cast<bool>(value)) {
            if (!first) {
                s->Append("|");
            }
            s->Append(absl::StrFormat("BufferUsage::%x", static_cast<typename std::underlying_type<BufferUsage>::type>(value)));
        }

        if (moreThanOneBit) {
            s->Append(")");
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<BufferUsage>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(ColorWriteMask value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("ColorWriteMask::");
        if (!static_cast<bool>(value)) {
            // 0 is often explicitly declared as None.
            s->Append("None");
            return {true};
        }

        bool moreThanOneBit = !HasZeroOrOneBits(value);
        if (moreThanOneBit) {
            s->Append("(");
        }

        bool first = true;
        if (value & ColorWriteMask::Red) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("Red");
            value &= ~ColorWriteMask::Red;
        }
        if (value & ColorWriteMask::Green) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("Green");
            value &= ~ColorWriteMask::Green;
        }
        if (value & ColorWriteMask::Blue) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("Blue");
            value &= ~ColorWriteMask::Blue;
        }
        if (value & ColorWriteMask::Alpha) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("Alpha");
            value &= ~ColorWriteMask::Alpha;
        }
        if (value & ColorWriteMask::All) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("All");
            value &= ~ColorWriteMask::All;
        }

        if (static_cast<bool>(value)) {
            if (!first) {
                s->Append("|");
            }
            s->Append(absl::StrFormat("ColorWriteMask::%x", static_cast<typename std::underlying_type<ColorWriteMask>::type>(value)));
        }

        if (moreThanOneBit) {
            s->Append(")");
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<ColorWriteMask>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(HeapProperty value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("HeapProperty::");
        if (!static_cast<bool>(value)) {
            // 0 is often explicitly declared as None.
            s->Append("Undefined");
            return {true};
        }

        bool moreThanOneBit = !HasZeroOrOneBits(value);
        if (moreThanOneBit) {
            s->Append("(");
        }

        bool first = true;
        if (value & HeapProperty::DeviceLocal) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("DeviceLocal");
            value &= ~HeapProperty::DeviceLocal;
        }
        if (value & HeapProperty::HostVisible) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("HostVisible");
            value &= ~HeapProperty::HostVisible;
        }
        if (value & HeapProperty::HostCoherent) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("HostCoherent");
            value &= ~HeapProperty::HostCoherent;
        }
        if (value & HeapProperty::HostUncached) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("HostUncached");
            value &= ~HeapProperty::HostUncached;
        }
        if (value & HeapProperty::HostCached) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("HostCached");
            value &= ~HeapProperty::HostCached;
        }

        if (static_cast<bool>(value)) {
            if (!first) {
                s->Append("|");
            }
            s->Append(absl::StrFormat("HeapProperty::%x", static_cast<typename std::underlying_type<HeapProperty>::type>(value)));
        }

        if (moreThanOneBit) {
            s->Append(")");
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<HeapProperty>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(MapMode value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("MapMode::");
        if (!static_cast<bool>(value)) {
            // 0 is often explicitly declared as None.
            s->Append("None");
            return {true};
        }

        bool moreThanOneBit = !HasZeroOrOneBits(value);
        if (moreThanOneBit) {
            s->Append("(");
        }

        bool first = true;
        if (value & MapMode::Read) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("Read");
            value &= ~MapMode::Read;
        }
        if (value & MapMode::Write) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("Write");
            value &= ~MapMode::Write;
        }

        if (static_cast<bool>(value)) {
            if (!first) {
                s->Append("|");
            }
            s->Append(absl::StrFormat("MapMode::%x", static_cast<typename std::underlying_type<MapMode>::type>(value)));
        }

        if (moreThanOneBit) {
            s->Append(")");
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<MapMode>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(ShaderStage value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("ShaderStage::");
        if (!static_cast<bool>(value)) {
            // 0 is often explicitly declared as None.
            s->Append("None");
            return {true};
        }

        bool moreThanOneBit = !HasZeroOrOneBits(value);
        if (moreThanOneBit) {
            s->Append("(");
        }

        bool first = true;
        if (value & ShaderStage::Vertex) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("Vertex");
            value &= ~ShaderStage::Vertex;
        }
        if (value & ShaderStage::Fragment) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("Fragment");
            value &= ~ShaderStage::Fragment;
        }
        if (value & ShaderStage::Compute) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("Compute");
            value &= ~ShaderStage::Compute;
        }

        if (static_cast<bool>(value)) {
            if (!first) {
                s->Append("|");
            }
            s->Append(absl::StrFormat("ShaderStage::%x", static_cast<typename std::underlying_type<ShaderStage>::type>(value)));
        }

        if (moreThanOneBit) {
            s->Append(")");
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<ShaderStage>::type>(value)));
    }
    return {true};
}
absl::FormatConvertResult<absl::FormatConversionCharSet::kString|absl::FormatConversionCharSet::kIntegral>
AbslFormatConvert(TextureUsage value,
                  const absl::FormatConversionSpec& spec,
                  absl::FormatSink* s) {
    if (spec.conversion_char() == absl::FormatConversionChar::s) {
        s->Append("TextureUsage::");
        if (!static_cast<bool>(value)) {
            // 0 is often explicitly declared as None.
            s->Append("None");
            return {true};
        }

        bool moreThanOneBit = !HasZeroOrOneBits(value);
        if (moreThanOneBit) {
            s->Append("(");
        }

        bool first = true;
        if (value & TextureUsage::CopySrc) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("CopySrc");
            value &= ~TextureUsage::CopySrc;
        }
        if (value & TextureUsage::CopyDst) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("CopyDst");
            value &= ~TextureUsage::CopyDst;
        }
        if (value & TextureUsage::TextureBinding) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("TextureBinding");
            value &= ~TextureUsage::TextureBinding;
        }
        if (value & TextureUsage::StorageBinding) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("StorageBinding");
            value &= ~TextureUsage::StorageBinding;
        }
        if (value & TextureUsage::RenderAttachment) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("RenderAttachment");
            value &= ~TextureUsage::RenderAttachment;
        }
        if (value & TextureUsage::TransientAttachment) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("TransientAttachment");
            value &= ~TextureUsage::TransientAttachment;
        }
        if (value & TextureUsage::StorageAttachment) {
            if (!first) {
                s->Append("|");
            }
            first = false;
            s->Append("StorageAttachment");
            value &= ~TextureUsage::StorageAttachment;
        }

        if (static_cast<bool>(value)) {
            if (!first) {
                s->Append("|");
            }
            s->Append(absl::StrFormat("TextureUsage::%x", static_cast<typename std::underlying_type<TextureUsage>::type>(value)));
        }

        if (moreThanOneBit) {
            s->Append(")");
        }
    } else {
        s->Append(absl::StrFormat("%u", static_cast<typename std::underlying_type<TextureUsage>::type>(value)));
    }
    return {true};
}

}  // namespace wgpu
