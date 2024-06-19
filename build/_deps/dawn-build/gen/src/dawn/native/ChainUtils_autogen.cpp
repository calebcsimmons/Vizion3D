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

#include "dawn/native/ChainUtils.h"

#include <tuple>
#include <utility>

namespace dawn::native {

// Returns true iff the chain's SType matches the extension, false otherwise. If the SType was
// not already matched, sets the unpacked result accordingly. Otherwise, stores the duplicated
// SType in 'duplicate'.
template <typename Root, typename UnpackedPtrT, typename Ext>
bool UnpackExtension(typename UnpackedPtrT::TupleType& unpacked,
                     typename UnpackedPtrT::BitsetType& bitset,
                     typename UnpackedPtrT::ChainType chain, bool* duplicate) {
    DAWN_ASSERT(chain != nullptr);
    if (chain->sType == STypeFor<Ext>) {
        auto& member = std::get<Ext>(unpacked);
        if (member != nullptr && duplicate) {
            *duplicate = true;
        } else {
            member = reinterpret_cast<Ext>(chain);
            bitset.set(detail::UnpackedPtrIndexOf<UnpackedPtrT, Ext>);
        }
        return true;
    }
    return false;
}

// Tries to match all possible extensions, returning true iff one of the allowed extensions were
// matched, false otherwise. If the SType was not already matched, sets the unpacked result
// accordingly. Otherwise, stores the duplicated SType in 'duplicate'.
template <typename Root, typename UnpackedPtrT, typename AdditionalExts>
struct AdditionalExtensionUnpacker;
template <typename Root, typename UnpackedPtrT, typename... Exts>
struct AdditionalExtensionUnpacker<Root, UnpackedPtrT, detail::AdditionalExtensionsList<Exts...>> {
    static bool Unpack(typename UnpackedPtrT::TupleType& unpacked,
                       typename UnpackedPtrT::BitsetType& bitset,
                       typename UnpackedPtrT::ChainType chain,
                       bool* duplicate) {
        return ((UnpackExtension<Root, UnpackedPtrT, Exts>(unpacked, bitset, chain, duplicate)) ||
                ...);
    }
};

//
// UnpackedPtr chain helpers.
//
template <>
UnpackedPtr<AdapterInfo> Unpack<AdapterInfo>(typename UnpackedPtr<AdapterInfo>::PtrType chain) {
    UnpackedPtr<AdapterInfo> result(chain);
    for (typename UnpackedPtr<AdapterInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        AdapterInfo,
                        UnpackedPtr<AdapterInfo>,
                        detail::AdditionalExtensions<AdapterInfo>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<AdapterInfo>> ValidateAndUnpack<AdapterInfo>(
    typename UnpackedPtr<AdapterInfo>::PtrType chain) {
    UnpackedPtr<AdapterInfo> result(chain);
    for (typename UnpackedPtr<AdapterInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        AdapterInfo,
                        UnpackedPtr<AdapterInfo>,
                        detail::AdditionalExtensions<AdapterInfo>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "AdapterInfo"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "AdapterInfo"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<AdapterProperties> Unpack<AdapterProperties>(typename UnpackedPtr<AdapterProperties>::PtrType chain) {
    UnpackedPtr<AdapterProperties> result(chain);
    for (typename UnpackedPtr<AdapterProperties>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DawnAdapterPropertiesPowerPreference>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<AdapterProperties>, DawnAdapterPropertiesPowerPreference>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterProperties>, ExtPtrType>
                );
                break;
            }
            case STypeFor<AdapterPropertiesMemoryHeaps>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<AdapterProperties>, AdapterPropertiesMemoryHeaps>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterProperties>, ExtPtrType>
                );
                break;
            }
            case STypeFor<AdapterPropertiesD3D>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<AdapterProperties>, AdapterPropertiesD3D>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterProperties>, ExtPtrType>
                );
                break;
            }
            case STypeFor<AdapterPropertiesVk>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<AdapterProperties>, AdapterPropertiesVk>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterProperties>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        AdapterProperties,
                        UnpackedPtr<AdapterProperties>,
                        detail::AdditionalExtensions<AdapterProperties>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<AdapterProperties>> ValidateAndUnpack<AdapterProperties>(
    typename UnpackedPtr<AdapterProperties>::PtrType chain) {
    UnpackedPtr<AdapterProperties> result(chain);
    for (typename UnpackedPtr<AdapterProperties>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DawnAdapterPropertiesPowerPreference>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<AdapterProperties>, DawnAdapterPropertiesPowerPreference>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterProperties>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<AdapterPropertiesMemoryHeaps>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<AdapterProperties>, AdapterPropertiesMemoryHeaps>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterProperties>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<AdapterPropertiesD3D>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<AdapterProperties>, AdapterPropertiesD3D>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterProperties>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<AdapterPropertiesVk>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<AdapterProperties>, AdapterPropertiesVk>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<AdapterProperties>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        AdapterProperties,
                        UnpackedPtr<AdapterProperties>,
                        detail::AdditionalExtensions<AdapterProperties>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "AdapterProperties"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "AdapterProperties"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<BindGroupEntry> Unpack<BindGroupEntry>(typename UnpackedPtr<BindGroupEntry>::PtrType chain) {
    UnpackedPtr<BindGroupEntry> result(chain);
    for (typename UnpackedPtr<BindGroupEntry>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<ExternalTextureBindingEntry>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<BindGroupEntry>, ExternalTextureBindingEntry>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<BindGroupEntry>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindGroupEntry,
                        UnpackedPtr<BindGroupEntry>,
                        detail::AdditionalExtensions<BindGroupEntry>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<BindGroupEntry>> ValidateAndUnpack<BindGroupEntry>(
    typename UnpackedPtr<BindGroupEntry>::PtrType chain) {
    UnpackedPtr<BindGroupEntry> result(chain);
    for (typename UnpackedPtr<BindGroupEntry>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<ExternalTextureBindingEntry>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<BindGroupEntry>, ExternalTextureBindingEntry>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<BindGroupEntry>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindGroupEntry,
                        UnpackedPtr<BindGroupEntry>,
                        detail::AdditionalExtensions<BindGroupEntry>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "BindGroupEntry"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "BindGroupEntry"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<BufferBindingLayout> Unpack<BufferBindingLayout>(typename UnpackedPtr<BufferBindingLayout>::PtrType chain) {
    UnpackedPtr<BufferBindingLayout> result(chain);
    for (typename UnpackedPtr<BufferBindingLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BufferBindingLayout,
                        UnpackedPtr<BufferBindingLayout>,
                        detail::AdditionalExtensions<BufferBindingLayout>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<BufferBindingLayout>> ValidateAndUnpack<BufferBindingLayout>(
    typename UnpackedPtr<BufferBindingLayout>::PtrType chain) {
    UnpackedPtr<BufferBindingLayout> result(chain);
    for (typename UnpackedPtr<BufferBindingLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BufferBindingLayout,
                        UnpackedPtr<BufferBindingLayout>,
                        detail::AdditionalExtensions<BufferBindingLayout>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "BufferBindingLayout"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "BufferBindingLayout"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<BufferDescriptor> Unpack<BufferDescriptor>(typename UnpackedPtr<BufferDescriptor>::PtrType chain) {
    UnpackedPtr<BufferDescriptor> result(chain);
    for (typename UnpackedPtr<BufferDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<BufferHostMappedPointer>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<BufferDescriptor>, BufferHostMappedPointer>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<BufferDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnBufferDescriptorErrorInfoFromWireClient>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<BufferDescriptor>, DawnBufferDescriptorErrorInfoFromWireClient>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<BufferDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BufferDescriptor,
                        UnpackedPtr<BufferDescriptor>,
                        detail::AdditionalExtensions<BufferDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<BufferDescriptor>> ValidateAndUnpack<BufferDescriptor>(
    typename UnpackedPtr<BufferDescriptor>::PtrType chain) {
    UnpackedPtr<BufferDescriptor> result(chain);
    for (typename UnpackedPtr<BufferDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<BufferHostMappedPointer>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<BufferDescriptor>, BufferHostMappedPointer>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<BufferDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnBufferDescriptorErrorInfoFromWireClient>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<BufferDescriptor>, DawnBufferDescriptorErrorInfoFromWireClient>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<BufferDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BufferDescriptor,
                        UnpackedPtr<BufferDescriptor>,
                        detail::AdditionalExtensions<BufferDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "BufferDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "BufferDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<BufferMapCallbackInfo> Unpack<BufferMapCallbackInfo>(typename UnpackedPtr<BufferMapCallbackInfo>::PtrType chain) {
    UnpackedPtr<BufferMapCallbackInfo> result(chain);
    for (typename UnpackedPtr<BufferMapCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BufferMapCallbackInfo,
                        UnpackedPtr<BufferMapCallbackInfo>,
                        detail::AdditionalExtensions<BufferMapCallbackInfo>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<BufferMapCallbackInfo>> ValidateAndUnpack<BufferMapCallbackInfo>(
    typename UnpackedPtr<BufferMapCallbackInfo>::PtrType chain) {
    UnpackedPtr<BufferMapCallbackInfo> result(chain);
    for (typename UnpackedPtr<BufferMapCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BufferMapCallbackInfo,
                        UnpackedPtr<BufferMapCallbackInfo>,
                        detail::AdditionalExtensions<BufferMapCallbackInfo>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "BufferMapCallbackInfo"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "BufferMapCallbackInfo"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<CommandBufferDescriptor> Unpack<CommandBufferDescriptor>(typename UnpackedPtr<CommandBufferDescriptor>::PtrType chain) {
    UnpackedPtr<CommandBufferDescriptor> result(chain);
    for (typename UnpackedPtr<CommandBufferDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CommandBufferDescriptor,
                        UnpackedPtr<CommandBufferDescriptor>,
                        detail::AdditionalExtensions<CommandBufferDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<CommandBufferDescriptor>> ValidateAndUnpack<CommandBufferDescriptor>(
    typename UnpackedPtr<CommandBufferDescriptor>::PtrType chain) {
    UnpackedPtr<CommandBufferDescriptor> result(chain);
    for (typename UnpackedPtr<CommandBufferDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CommandBufferDescriptor,
                        UnpackedPtr<CommandBufferDescriptor>,
                        detail::AdditionalExtensions<CommandBufferDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "CommandBufferDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "CommandBufferDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<CommandEncoderDescriptor> Unpack<CommandEncoderDescriptor>(typename UnpackedPtr<CommandEncoderDescriptor>::PtrType chain) {
    UnpackedPtr<CommandEncoderDescriptor> result(chain);
    for (typename UnpackedPtr<CommandEncoderDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DawnEncoderInternalUsageDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<CommandEncoderDescriptor>, DawnEncoderInternalUsageDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<CommandEncoderDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CommandEncoderDescriptor,
                        UnpackedPtr<CommandEncoderDescriptor>,
                        detail::AdditionalExtensions<CommandEncoderDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<CommandEncoderDescriptor>> ValidateAndUnpack<CommandEncoderDescriptor>(
    typename UnpackedPtr<CommandEncoderDescriptor>::PtrType chain) {
    UnpackedPtr<CommandEncoderDescriptor> result(chain);
    for (typename UnpackedPtr<CommandEncoderDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DawnEncoderInternalUsageDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<CommandEncoderDescriptor>, DawnEncoderInternalUsageDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<CommandEncoderDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CommandEncoderDescriptor,
                        UnpackedPtr<CommandEncoderDescriptor>,
                        detail::AdditionalExtensions<CommandEncoderDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "CommandEncoderDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "CommandEncoderDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<CompilationInfoCallbackInfo> Unpack<CompilationInfoCallbackInfo>(typename UnpackedPtr<CompilationInfoCallbackInfo>::PtrType chain) {
    UnpackedPtr<CompilationInfoCallbackInfo> result(chain);
    for (typename UnpackedPtr<CompilationInfoCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CompilationInfoCallbackInfo,
                        UnpackedPtr<CompilationInfoCallbackInfo>,
                        detail::AdditionalExtensions<CompilationInfoCallbackInfo>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<CompilationInfoCallbackInfo>> ValidateAndUnpack<CompilationInfoCallbackInfo>(
    typename UnpackedPtr<CompilationInfoCallbackInfo>::PtrType chain) {
    UnpackedPtr<CompilationInfoCallbackInfo> result(chain);
    for (typename UnpackedPtr<CompilationInfoCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CompilationInfoCallbackInfo,
                        UnpackedPtr<CompilationInfoCallbackInfo>,
                        detail::AdditionalExtensions<CompilationInfoCallbackInfo>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "CompilationInfoCallbackInfo"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "CompilationInfoCallbackInfo"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<CompilationMessage> Unpack<CompilationMessage>(typename UnpackedPtr<CompilationMessage>::PtrType chain) {
    UnpackedPtr<CompilationMessage> result(chain);
    for (typename UnpackedPtr<CompilationMessage>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CompilationMessage,
                        UnpackedPtr<CompilationMessage>,
                        detail::AdditionalExtensions<CompilationMessage>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<CompilationMessage>> ValidateAndUnpack<CompilationMessage>(
    typename UnpackedPtr<CompilationMessage>::PtrType chain) {
    UnpackedPtr<CompilationMessage> result(chain);
    for (typename UnpackedPtr<CompilationMessage>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CompilationMessage,
                        UnpackedPtr<CompilationMessage>,
                        detail::AdditionalExtensions<CompilationMessage>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "CompilationMessage"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "CompilationMessage"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ConstantEntry> Unpack<ConstantEntry>(typename UnpackedPtr<ConstantEntry>::PtrType chain) {
    UnpackedPtr<ConstantEntry> result(chain);
    for (typename UnpackedPtr<ConstantEntry>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ConstantEntry,
                        UnpackedPtr<ConstantEntry>,
                        detail::AdditionalExtensions<ConstantEntry>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ConstantEntry>> ValidateAndUnpack<ConstantEntry>(
    typename UnpackedPtr<ConstantEntry>::PtrType chain) {
    UnpackedPtr<ConstantEntry> result(chain);
    for (typename UnpackedPtr<ConstantEntry>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ConstantEntry,
                        UnpackedPtr<ConstantEntry>,
                        detail::AdditionalExtensions<ConstantEntry>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "ConstantEntry"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ConstantEntry"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<CopyTextureForBrowserOptions> Unpack<CopyTextureForBrowserOptions>(typename UnpackedPtr<CopyTextureForBrowserOptions>::PtrType chain) {
    UnpackedPtr<CopyTextureForBrowserOptions> result(chain);
    for (typename UnpackedPtr<CopyTextureForBrowserOptions>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CopyTextureForBrowserOptions,
                        UnpackedPtr<CopyTextureForBrowserOptions>,
                        detail::AdditionalExtensions<CopyTextureForBrowserOptions>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<CopyTextureForBrowserOptions>> ValidateAndUnpack<CopyTextureForBrowserOptions>(
    typename UnpackedPtr<CopyTextureForBrowserOptions>::PtrType chain) {
    UnpackedPtr<CopyTextureForBrowserOptions> result(chain);
    for (typename UnpackedPtr<CopyTextureForBrowserOptions>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CopyTextureForBrowserOptions,
                        UnpackedPtr<CopyTextureForBrowserOptions>,
                        detail::AdditionalExtensions<CopyTextureForBrowserOptions>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "CopyTextureForBrowserOptions"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "CopyTextureForBrowserOptions"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<CreateComputePipelineAsyncCallbackInfo> Unpack<CreateComputePipelineAsyncCallbackInfo>(typename UnpackedPtr<CreateComputePipelineAsyncCallbackInfo>::PtrType chain) {
    UnpackedPtr<CreateComputePipelineAsyncCallbackInfo> result(chain);
    for (typename UnpackedPtr<CreateComputePipelineAsyncCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CreateComputePipelineAsyncCallbackInfo,
                        UnpackedPtr<CreateComputePipelineAsyncCallbackInfo>,
                        detail::AdditionalExtensions<CreateComputePipelineAsyncCallbackInfo>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<CreateComputePipelineAsyncCallbackInfo>> ValidateAndUnpack<CreateComputePipelineAsyncCallbackInfo>(
    typename UnpackedPtr<CreateComputePipelineAsyncCallbackInfo>::PtrType chain) {
    UnpackedPtr<CreateComputePipelineAsyncCallbackInfo> result(chain);
    for (typename UnpackedPtr<CreateComputePipelineAsyncCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CreateComputePipelineAsyncCallbackInfo,
                        UnpackedPtr<CreateComputePipelineAsyncCallbackInfo>,
                        detail::AdditionalExtensions<CreateComputePipelineAsyncCallbackInfo>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "CreateComputePipelineAsyncCallbackInfo"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "CreateComputePipelineAsyncCallbackInfo"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<CreateRenderPipelineAsyncCallbackInfo> Unpack<CreateRenderPipelineAsyncCallbackInfo>(typename UnpackedPtr<CreateRenderPipelineAsyncCallbackInfo>::PtrType chain) {
    UnpackedPtr<CreateRenderPipelineAsyncCallbackInfo> result(chain);
    for (typename UnpackedPtr<CreateRenderPipelineAsyncCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CreateRenderPipelineAsyncCallbackInfo,
                        UnpackedPtr<CreateRenderPipelineAsyncCallbackInfo>,
                        detail::AdditionalExtensions<CreateRenderPipelineAsyncCallbackInfo>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<CreateRenderPipelineAsyncCallbackInfo>> ValidateAndUnpack<CreateRenderPipelineAsyncCallbackInfo>(
    typename UnpackedPtr<CreateRenderPipelineAsyncCallbackInfo>::PtrType chain) {
    UnpackedPtr<CreateRenderPipelineAsyncCallbackInfo> result(chain);
    for (typename UnpackedPtr<CreateRenderPipelineAsyncCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CreateRenderPipelineAsyncCallbackInfo,
                        UnpackedPtr<CreateRenderPipelineAsyncCallbackInfo>,
                        detail::AdditionalExtensions<CreateRenderPipelineAsyncCallbackInfo>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "CreateRenderPipelineAsyncCallbackInfo"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "CreateRenderPipelineAsyncCallbackInfo"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<DeviceLostCallbackInfo> Unpack<DeviceLostCallbackInfo>(typename UnpackedPtr<DeviceLostCallbackInfo>::PtrType chain) {
    UnpackedPtr<DeviceLostCallbackInfo> result(chain);
    for (typename UnpackedPtr<DeviceLostCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        DeviceLostCallbackInfo,
                        UnpackedPtr<DeviceLostCallbackInfo>,
                        detail::AdditionalExtensions<DeviceLostCallbackInfo>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<DeviceLostCallbackInfo>> ValidateAndUnpack<DeviceLostCallbackInfo>(
    typename UnpackedPtr<DeviceLostCallbackInfo>::PtrType chain) {
    UnpackedPtr<DeviceLostCallbackInfo> result(chain);
    for (typename UnpackedPtr<DeviceLostCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        DeviceLostCallbackInfo,
                        UnpackedPtr<DeviceLostCallbackInfo>,
                        detail::AdditionalExtensions<DeviceLostCallbackInfo>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "DeviceLostCallbackInfo"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "DeviceLostCallbackInfo"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<FormatCapabilities> Unpack<FormatCapabilities>(typename UnpackedPtr<FormatCapabilities>::PtrType chain) {
    UnpackedPtr<FormatCapabilities> result(chain);
    for (typename UnpackedPtr<FormatCapabilities>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DrmFormatCapabilities>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<FormatCapabilities>, DrmFormatCapabilities>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<FormatCapabilities>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        FormatCapabilities,
                        UnpackedPtr<FormatCapabilities>,
                        detail::AdditionalExtensions<FormatCapabilities>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<FormatCapabilities>> ValidateAndUnpack<FormatCapabilities>(
    typename UnpackedPtr<FormatCapabilities>::PtrType chain) {
    UnpackedPtr<FormatCapabilities> result(chain);
    for (typename UnpackedPtr<FormatCapabilities>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DrmFormatCapabilities>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<FormatCapabilities>, DrmFormatCapabilities>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<FormatCapabilities>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        FormatCapabilities,
                        UnpackedPtr<FormatCapabilities>,
                        detail::AdditionalExtensions<FormatCapabilities>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "FormatCapabilities"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "FormatCapabilities"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<InstanceFeatures> Unpack<InstanceFeatures>(typename UnpackedPtr<InstanceFeatures>::PtrType chain) {
    UnpackedPtr<InstanceFeatures> result(chain);
    for (typename UnpackedPtr<InstanceFeatures>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        InstanceFeatures,
                        UnpackedPtr<InstanceFeatures>,
                        detail::AdditionalExtensions<InstanceFeatures>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<InstanceFeatures>> ValidateAndUnpack<InstanceFeatures>(
    typename UnpackedPtr<InstanceFeatures>::PtrType chain) {
    UnpackedPtr<InstanceFeatures> result(chain);
    for (typename UnpackedPtr<InstanceFeatures>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        InstanceFeatures,
                        UnpackedPtr<InstanceFeatures>,
                        detail::AdditionalExtensions<InstanceFeatures>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "InstanceFeatures"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "InstanceFeatures"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<MultisampleState> Unpack<MultisampleState>(typename UnpackedPtr<MultisampleState>::PtrType chain) {
    UnpackedPtr<MultisampleState> result(chain);
    for (typename UnpackedPtr<MultisampleState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DawnMultisampleStateRenderToSingleSampled>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<MultisampleState>, DawnMultisampleStateRenderToSingleSampled>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<MultisampleState>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        MultisampleState,
                        UnpackedPtr<MultisampleState>,
                        detail::AdditionalExtensions<MultisampleState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<MultisampleState>> ValidateAndUnpack<MultisampleState>(
    typename UnpackedPtr<MultisampleState>::PtrType chain) {
    UnpackedPtr<MultisampleState> result(chain);
    for (typename UnpackedPtr<MultisampleState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DawnMultisampleStateRenderToSingleSampled>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<MultisampleState>, DawnMultisampleStateRenderToSingleSampled>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<MultisampleState>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        MultisampleState,
                        UnpackedPtr<MultisampleState>,
                        detail::AdditionalExtensions<MultisampleState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "MultisampleState"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "MultisampleState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<PipelineLayoutDescriptor> Unpack<PipelineLayoutDescriptor>(typename UnpackedPtr<PipelineLayoutDescriptor>::PtrType chain) {
    UnpackedPtr<PipelineLayoutDescriptor> result(chain);
    for (typename UnpackedPtr<PipelineLayoutDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<PipelineLayoutPixelLocalStorage>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<PipelineLayoutDescriptor>, PipelineLayoutPixelLocalStorage>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<PipelineLayoutDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        PipelineLayoutDescriptor,
                        UnpackedPtr<PipelineLayoutDescriptor>,
                        detail::AdditionalExtensions<PipelineLayoutDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<PipelineLayoutDescriptor>> ValidateAndUnpack<PipelineLayoutDescriptor>(
    typename UnpackedPtr<PipelineLayoutDescriptor>::PtrType chain) {
    UnpackedPtr<PipelineLayoutDescriptor> result(chain);
    for (typename UnpackedPtr<PipelineLayoutDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<PipelineLayoutPixelLocalStorage>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<PipelineLayoutDescriptor>, PipelineLayoutPixelLocalStorage>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<PipelineLayoutDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        PipelineLayoutDescriptor,
                        UnpackedPtr<PipelineLayoutDescriptor>,
                        detail::AdditionalExtensions<PipelineLayoutDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "PipelineLayoutDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "PipelineLayoutDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<PipelineLayoutStorageAttachment> Unpack<PipelineLayoutStorageAttachment>(typename UnpackedPtr<PipelineLayoutStorageAttachment>::PtrType chain) {
    UnpackedPtr<PipelineLayoutStorageAttachment> result(chain);
    for (typename UnpackedPtr<PipelineLayoutStorageAttachment>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        PipelineLayoutStorageAttachment,
                        UnpackedPtr<PipelineLayoutStorageAttachment>,
                        detail::AdditionalExtensions<PipelineLayoutStorageAttachment>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<PipelineLayoutStorageAttachment>> ValidateAndUnpack<PipelineLayoutStorageAttachment>(
    typename UnpackedPtr<PipelineLayoutStorageAttachment>::PtrType chain) {
    UnpackedPtr<PipelineLayoutStorageAttachment> result(chain);
    for (typename UnpackedPtr<PipelineLayoutStorageAttachment>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        PipelineLayoutStorageAttachment,
                        UnpackedPtr<PipelineLayoutStorageAttachment>,
                        detail::AdditionalExtensions<PipelineLayoutStorageAttachment>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "PipelineLayoutStorageAttachment"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "PipelineLayoutStorageAttachment"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<PopErrorScopeCallbackInfo> Unpack<PopErrorScopeCallbackInfo>(typename UnpackedPtr<PopErrorScopeCallbackInfo>::PtrType chain) {
    UnpackedPtr<PopErrorScopeCallbackInfo> result(chain);
    for (typename UnpackedPtr<PopErrorScopeCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        PopErrorScopeCallbackInfo,
                        UnpackedPtr<PopErrorScopeCallbackInfo>,
                        detail::AdditionalExtensions<PopErrorScopeCallbackInfo>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<PopErrorScopeCallbackInfo>> ValidateAndUnpack<PopErrorScopeCallbackInfo>(
    typename UnpackedPtr<PopErrorScopeCallbackInfo>::PtrType chain) {
    UnpackedPtr<PopErrorScopeCallbackInfo> result(chain);
    for (typename UnpackedPtr<PopErrorScopeCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        PopErrorScopeCallbackInfo,
                        UnpackedPtr<PopErrorScopeCallbackInfo>,
                        detail::AdditionalExtensions<PopErrorScopeCallbackInfo>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "PopErrorScopeCallbackInfo"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "PopErrorScopeCallbackInfo"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<PrimitiveState> Unpack<PrimitiveState>(typename UnpackedPtr<PrimitiveState>::PtrType chain) {
    UnpackedPtr<PrimitiveState> result(chain);
    for (typename UnpackedPtr<PrimitiveState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<PrimitiveDepthClipControl>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<PrimitiveState>, PrimitiveDepthClipControl>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<PrimitiveState>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        PrimitiveState,
                        UnpackedPtr<PrimitiveState>,
                        detail::AdditionalExtensions<PrimitiveState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<PrimitiveState>> ValidateAndUnpack<PrimitiveState>(
    typename UnpackedPtr<PrimitiveState>::PtrType chain) {
    UnpackedPtr<PrimitiveState> result(chain);
    for (typename UnpackedPtr<PrimitiveState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<PrimitiveDepthClipControl>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<PrimitiveState>, PrimitiveDepthClipControl>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<PrimitiveState>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        PrimitiveState,
                        UnpackedPtr<PrimitiveState>,
                        detail::AdditionalExtensions<PrimitiveState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "PrimitiveState"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "PrimitiveState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<QuerySetDescriptor> Unpack<QuerySetDescriptor>(typename UnpackedPtr<QuerySetDescriptor>::PtrType chain) {
    UnpackedPtr<QuerySetDescriptor> result(chain);
    for (typename UnpackedPtr<QuerySetDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        QuerySetDescriptor,
                        UnpackedPtr<QuerySetDescriptor>,
                        detail::AdditionalExtensions<QuerySetDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<QuerySetDescriptor>> ValidateAndUnpack<QuerySetDescriptor>(
    typename UnpackedPtr<QuerySetDescriptor>::PtrType chain) {
    UnpackedPtr<QuerySetDescriptor> result(chain);
    for (typename UnpackedPtr<QuerySetDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        QuerySetDescriptor,
                        UnpackedPtr<QuerySetDescriptor>,
                        detail::AdditionalExtensions<QuerySetDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "QuerySetDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "QuerySetDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<QueueDescriptor> Unpack<QueueDescriptor>(typename UnpackedPtr<QueueDescriptor>::PtrType chain) {
    UnpackedPtr<QueueDescriptor> result(chain);
    for (typename UnpackedPtr<QueueDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        QueueDescriptor,
                        UnpackedPtr<QueueDescriptor>,
                        detail::AdditionalExtensions<QueueDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<QueueDescriptor>> ValidateAndUnpack<QueueDescriptor>(
    typename UnpackedPtr<QueueDescriptor>::PtrType chain) {
    UnpackedPtr<QueueDescriptor> result(chain);
    for (typename UnpackedPtr<QueueDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        QueueDescriptor,
                        UnpackedPtr<QueueDescriptor>,
                        detail::AdditionalExtensions<QueueDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "QueueDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "QueueDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<QueueWorkDoneCallbackInfo> Unpack<QueueWorkDoneCallbackInfo>(typename UnpackedPtr<QueueWorkDoneCallbackInfo>::PtrType chain) {
    UnpackedPtr<QueueWorkDoneCallbackInfo> result(chain);
    for (typename UnpackedPtr<QueueWorkDoneCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        QueueWorkDoneCallbackInfo,
                        UnpackedPtr<QueueWorkDoneCallbackInfo>,
                        detail::AdditionalExtensions<QueueWorkDoneCallbackInfo>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<QueueWorkDoneCallbackInfo>> ValidateAndUnpack<QueueWorkDoneCallbackInfo>(
    typename UnpackedPtr<QueueWorkDoneCallbackInfo>::PtrType chain) {
    UnpackedPtr<QueueWorkDoneCallbackInfo> result(chain);
    for (typename UnpackedPtr<QueueWorkDoneCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        QueueWorkDoneCallbackInfo,
                        UnpackedPtr<QueueWorkDoneCallbackInfo>,
                        detail::AdditionalExtensions<QueueWorkDoneCallbackInfo>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "QueueWorkDoneCallbackInfo"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "QueueWorkDoneCallbackInfo"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RenderBundleDescriptor> Unpack<RenderBundleDescriptor>(typename UnpackedPtr<RenderBundleDescriptor>::PtrType chain) {
    UnpackedPtr<RenderBundleDescriptor> result(chain);
    for (typename UnpackedPtr<RenderBundleDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderBundleDescriptor,
                        UnpackedPtr<RenderBundleDescriptor>,
                        detail::AdditionalExtensions<RenderBundleDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RenderBundleDescriptor>> ValidateAndUnpack<RenderBundleDescriptor>(
    typename UnpackedPtr<RenderBundleDescriptor>::PtrType chain) {
    UnpackedPtr<RenderBundleDescriptor> result(chain);
    for (typename UnpackedPtr<RenderBundleDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderBundleDescriptor,
                        UnpackedPtr<RenderBundleDescriptor>,
                        detail::AdditionalExtensions<RenderBundleDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "RenderBundleDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RenderBundleDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RenderBundleEncoderDescriptor> Unpack<RenderBundleEncoderDescriptor>(typename UnpackedPtr<RenderBundleEncoderDescriptor>::PtrType chain) {
    UnpackedPtr<RenderBundleEncoderDescriptor> result(chain);
    for (typename UnpackedPtr<RenderBundleEncoderDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderBundleEncoderDescriptor,
                        UnpackedPtr<RenderBundleEncoderDescriptor>,
                        detail::AdditionalExtensions<RenderBundleEncoderDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RenderBundleEncoderDescriptor>> ValidateAndUnpack<RenderBundleEncoderDescriptor>(
    typename UnpackedPtr<RenderBundleEncoderDescriptor>::PtrType chain) {
    UnpackedPtr<RenderBundleEncoderDescriptor> result(chain);
    for (typename UnpackedPtr<RenderBundleEncoderDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderBundleEncoderDescriptor,
                        UnpackedPtr<RenderBundleEncoderDescriptor>,
                        detail::AdditionalExtensions<RenderBundleEncoderDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "RenderBundleEncoderDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RenderBundleEncoderDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RequestAdapterCallbackInfo> Unpack<RequestAdapterCallbackInfo>(typename UnpackedPtr<RequestAdapterCallbackInfo>::PtrType chain) {
    UnpackedPtr<RequestAdapterCallbackInfo> result(chain);
    for (typename UnpackedPtr<RequestAdapterCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RequestAdapterCallbackInfo,
                        UnpackedPtr<RequestAdapterCallbackInfo>,
                        detail::AdditionalExtensions<RequestAdapterCallbackInfo>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RequestAdapterCallbackInfo>> ValidateAndUnpack<RequestAdapterCallbackInfo>(
    typename UnpackedPtr<RequestAdapterCallbackInfo>::PtrType chain) {
    UnpackedPtr<RequestAdapterCallbackInfo> result(chain);
    for (typename UnpackedPtr<RequestAdapterCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RequestAdapterCallbackInfo,
                        UnpackedPtr<RequestAdapterCallbackInfo>,
                        detail::AdditionalExtensions<RequestAdapterCallbackInfo>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "RequestAdapterCallbackInfo"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RequestAdapterCallbackInfo"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RequestAdapterOptions> Unpack<RequestAdapterOptions>(typename UnpackedPtr<RequestAdapterOptions>::PtrType chain) {
    UnpackedPtr<RequestAdapterOptions> result(chain);
    for (typename UnpackedPtr<RequestAdapterOptions>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DawnTogglesDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<RequestAdapterOptions>, DawnTogglesDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<RequestAdapterOptions>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RequestAdapterOptions,
                        UnpackedPtr<RequestAdapterOptions>,
                        detail::AdditionalExtensions<RequestAdapterOptions>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RequestAdapterOptions>> ValidateAndUnpack<RequestAdapterOptions>(
    typename UnpackedPtr<RequestAdapterOptions>::PtrType chain) {
    UnpackedPtr<RequestAdapterOptions> result(chain);
    for (typename UnpackedPtr<RequestAdapterOptions>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DawnTogglesDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<RequestAdapterOptions>, DawnTogglesDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<RequestAdapterOptions>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RequestAdapterOptions,
                        UnpackedPtr<RequestAdapterOptions>,
                        detail::AdditionalExtensions<RequestAdapterOptions>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "RequestAdapterOptions"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RequestAdapterOptions"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RequestDeviceCallbackInfo> Unpack<RequestDeviceCallbackInfo>(typename UnpackedPtr<RequestDeviceCallbackInfo>::PtrType chain) {
    UnpackedPtr<RequestDeviceCallbackInfo> result(chain);
    for (typename UnpackedPtr<RequestDeviceCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RequestDeviceCallbackInfo,
                        UnpackedPtr<RequestDeviceCallbackInfo>,
                        detail::AdditionalExtensions<RequestDeviceCallbackInfo>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RequestDeviceCallbackInfo>> ValidateAndUnpack<RequestDeviceCallbackInfo>(
    typename UnpackedPtr<RequestDeviceCallbackInfo>::PtrType chain) {
    UnpackedPtr<RequestDeviceCallbackInfo> result(chain);
    for (typename UnpackedPtr<RequestDeviceCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RequestDeviceCallbackInfo,
                        UnpackedPtr<RequestDeviceCallbackInfo>,
                        detail::AdditionalExtensions<RequestDeviceCallbackInfo>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "RequestDeviceCallbackInfo"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RequestDeviceCallbackInfo"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SamplerBindingLayout> Unpack<SamplerBindingLayout>(typename UnpackedPtr<SamplerBindingLayout>::PtrType chain) {
    UnpackedPtr<SamplerBindingLayout> result(chain);
    for (typename UnpackedPtr<SamplerBindingLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SamplerBindingLayout,
                        UnpackedPtr<SamplerBindingLayout>,
                        detail::AdditionalExtensions<SamplerBindingLayout>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SamplerBindingLayout>> ValidateAndUnpack<SamplerBindingLayout>(
    typename UnpackedPtr<SamplerBindingLayout>::PtrType chain) {
    UnpackedPtr<SamplerBindingLayout> result(chain);
    for (typename UnpackedPtr<SamplerBindingLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SamplerBindingLayout,
                        UnpackedPtr<SamplerBindingLayout>,
                        detail::AdditionalExtensions<SamplerBindingLayout>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SamplerBindingLayout"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SamplerBindingLayout"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SamplerDescriptor> Unpack<SamplerDescriptor>(typename UnpackedPtr<SamplerDescriptor>::PtrType chain) {
    UnpackedPtr<SamplerDescriptor> result(chain);
    for (typename UnpackedPtr<SamplerDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<YCbCrVkDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SamplerDescriptor>, YCbCrVkDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SamplerDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SamplerDescriptor,
                        UnpackedPtr<SamplerDescriptor>,
                        detail::AdditionalExtensions<SamplerDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SamplerDescriptor>> ValidateAndUnpack<SamplerDescriptor>(
    typename UnpackedPtr<SamplerDescriptor>::PtrType chain) {
    UnpackedPtr<SamplerDescriptor> result(chain);
    for (typename UnpackedPtr<SamplerDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<YCbCrVkDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SamplerDescriptor>, YCbCrVkDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SamplerDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SamplerDescriptor,
                        UnpackedPtr<SamplerDescriptor>,
                        detail::AdditionalExtensions<SamplerDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SamplerDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SamplerDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ShaderModuleDescriptor> Unpack<ShaderModuleDescriptor>(typename UnpackedPtr<ShaderModuleDescriptor>::PtrType chain) {
    UnpackedPtr<ShaderModuleDescriptor> result(chain);
    for (typename UnpackedPtr<ShaderModuleDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<ShaderModuleSPIRVDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<ShaderModuleDescriptor>, ShaderModuleSPIRVDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<ShaderModuleDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<ShaderModuleWGSLDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<ShaderModuleDescriptor>, ShaderModuleWGSLDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<ShaderModuleDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnShaderModuleSPIRVOptionsDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<ShaderModuleDescriptor>, DawnShaderModuleSPIRVOptionsDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<ShaderModuleDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<ShaderModuleCompilationOptions>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<ShaderModuleDescriptor>, ShaderModuleCompilationOptions>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<ShaderModuleDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ShaderModuleDescriptor,
                        UnpackedPtr<ShaderModuleDescriptor>,
                        detail::AdditionalExtensions<ShaderModuleDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ShaderModuleDescriptor>> ValidateAndUnpack<ShaderModuleDescriptor>(
    typename UnpackedPtr<ShaderModuleDescriptor>::PtrType chain) {
    UnpackedPtr<ShaderModuleDescriptor> result(chain);
    for (typename UnpackedPtr<ShaderModuleDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<ShaderModuleSPIRVDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<ShaderModuleDescriptor>, ShaderModuleSPIRVDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<ShaderModuleDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<ShaderModuleWGSLDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<ShaderModuleDescriptor>, ShaderModuleWGSLDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<ShaderModuleDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnShaderModuleSPIRVOptionsDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<ShaderModuleDescriptor>, DawnShaderModuleSPIRVOptionsDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<ShaderModuleDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<ShaderModuleCompilationOptions>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<ShaderModuleDescriptor>, ShaderModuleCompilationOptions>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<ShaderModuleDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ShaderModuleDescriptor,
                        UnpackedPtr<ShaderModuleDescriptor>,
                        detail::AdditionalExtensions<ShaderModuleDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "ShaderModuleDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ShaderModuleDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor> Unpack<SharedBufferMemoryBeginAccessDescriptor>(typename UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor>::PtrType chain) {
    UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor> result(chain);
    for (typename UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedBufferMemoryBeginAccessDescriptor,
                        UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor>,
                        detail::AdditionalExtensions<SharedBufferMemoryBeginAccessDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor>> ValidateAndUnpack<SharedBufferMemoryBeginAccessDescriptor>(
    typename UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor>::PtrType chain) {
    UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor> result(chain);
    for (typename UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedBufferMemoryBeginAccessDescriptor,
                        UnpackedPtr<SharedBufferMemoryBeginAccessDescriptor>,
                        detail::AdditionalExtensions<SharedBufferMemoryBeginAccessDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SharedBufferMemoryBeginAccessDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedBufferMemoryBeginAccessDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedBufferMemoryDescriptor> Unpack<SharedBufferMemoryDescriptor>(typename UnpackedPtr<SharedBufferMemoryDescriptor>::PtrType chain) {
    UnpackedPtr<SharedBufferMemoryDescriptor> result(chain);
    for (typename UnpackedPtr<SharedBufferMemoryDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedBufferMemoryDescriptor,
                        UnpackedPtr<SharedBufferMemoryDescriptor>,
                        detail::AdditionalExtensions<SharedBufferMemoryDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedBufferMemoryDescriptor>> ValidateAndUnpack<SharedBufferMemoryDescriptor>(
    typename UnpackedPtr<SharedBufferMemoryDescriptor>::PtrType chain) {
    UnpackedPtr<SharedBufferMemoryDescriptor> result(chain);
    for (typename UnpackedPtr<SharedBufferMemoryDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedBufferMemoryDescriptor,
                        UnpackedPtr<SharedBufferMemoryDescriptor>,
                        detail::AdditionalExtensions<SharedBufferMemoryDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SharedBufferMemoryDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedBufferMemoryDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedBufferMemoryEndAccessState> Unpack<SharedBufferMemoryEndAccessState>(typename UnpackedPtr<SharedBufferMemoryEndAccessState>::PtrType chain) {
    UnpackedPtr<SharedBufferMemoryEndAccessState> result(chain);
    for (typename UnpackedPtr<SharedBufferMemoryEndAccessState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedBufferMemoryEndAccessState,
                        UnpackedPtr<SharedBufferMemoryEndAccessState>,
                        detail::AdditionalExtensions<SharedBufferMemoryEndAccessState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedBufferMemoryEndAccessState>> ValidateAndUnpack<SharedBufferMemoryEndAccessState>(
    typename UnpackedPtr<SharedBufferMemoryEndAccessState>::PtrType chain) {
    UnpackedPtr<SharedBufferMemoryEndAccessState> result(chain);
    for (typename UnpackedPtr<SharedBufferMemoryEndAccessState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedBufferMemoryEndAccessState,
                        UnpackedPtr<SharedBufferMemoryEndAccessState>,
                        detail::AdditionalExtensions<SharedBufferMemoryEndAccessState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SharedBufferMemoryEndAccessState"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedBufferMemoryEndAccessState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedBufferMemoryProperties> Unpack<SharedBufferMemoryProperties>(typename UnpackedPtr<SharedBufferMemoryProperties>::PtrType chain) {
    UnpackedPtr<SharedBufferMemoryProperties> result(chain);
    for (typename UnpackedPtr<SharedBufferMemoryProperties>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedBufferMemoryProperties,
                        UnpackedPtr<SharedBufferMemoryProperties>,
                        detail::AdditionalExtensions<SharedBufferMemoryProperties>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedBufferMemoryProperties>> ValidateAndUnpack<SharedBufferMemoryProperties>(
    typename UnpackedPtr<SharedBufferMemoryProperties>::PtrType chain) {
    UnpackedPtr<SharedBufferMemoryProperties> result(chain);
    for (typename UnpackedPtr<SharedBufferMemoryProperties>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedBufferMemoryProperties,
                        UnpackedPtr<SharedBufferMemoryProperties>,
                        detail::AdditionalExtensions<SharedBufferMemoryProperties>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SharedBufferMemoryProperties"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedBufferMemoryProperties"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedFenceDescriptor> Unpack<SharedFenceDescriptor>(typename UnpackedPtr<SharedFenceDescriptor>::PtrType chain) {
    UnpackedPtr<SharedFenceDescriptor> result(chain);
    for (typename UnpackedPtr<SharedFenceDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<SharedFenceVkSemaphoreOpaqueFDDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceVkSemaphoreOpaqueFDDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceVkSemaphoreSyncFDDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceVkSemaphoreSyncFDDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceVkSemaphoreZirconHandleDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceVkSemaphoreZirconHandleDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceDXGISharedHandleDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceDXGISharedHandleDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceMTLSharedEventDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceMTLSharedEventDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedFenceDescriptor,
                        UnpackedPtr<SharedFenceDescriptor>,
                        detail::AdditionalExtensions<SharedFenceDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedFenceDescriptor>> ValidateAndUnpack<SharedFenceDescriptor>(
    typename UnpackedPtr<SharedFenceDescriptor>::PtrType chain) {
    UnpackedPtr<SharedFenceDescriptor> result(chain);
    for (typename UnpackedPtr<SharedFenceDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<SharedFenceVkSemaphoreOpaqueFDDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceVkSemaphoreOpaqueFDDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceVkSemaphoreSyncFDDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceVkSemaphoreSyncFDDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceVkSemaphoreZirconHandleDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceVkSemaphoreZirconHandleDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceDXGISharedHandleDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceDXGISharedHandleDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceMTLSharedEventDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceDescriptor>, SharedFenceMTLSharedEventDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedFenceDescriptor,
                        UnpackedPtr<SharedFenceDescriptor>,
                        detail::AdditionalExtensions<SharedFenceDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SharedFenceDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedFenceDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedFenceExportInfo> Unpack<SharedFenceExportInfo>(typename UnpackedPtr<SharedFenceExportInfo>::PtrType chain) {
    UnpackedPtr<SharedFenceExportInfo> result(chain);
    for (typename UnpackedPtr<SharedFenceExportInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<SharedFenceVkSemaphoreOpaqueFDExportInfo>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceVkSemaphoreOpaqueFDExportInfo>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceVkSemaphoreSyncFDExportInfo>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceVkSemaphoreSyncFDExportInfo>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceVkSemaphoreZirconHandleExportInfo>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceVkSemaphoreZirconHandleExportInfo>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceDXGISharedHandleExportInfo>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceDXGISharedHandleExportInfo>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedFenceMTLSharedEventExportInfo>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceMTLSharedEventExportInfo>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedFenceExportInfo,
                        UnpackedPtr<SharedFenceExportInfo>,
                        detail::AdditionalExtensions<SharedFenceExportInfo>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedFenceExportInfo>> ValidateAndUnpack<SharedFenceExportInfo>(
    typename UnpackedPtr<SharedFenceExportInfo>::PtrType chain) {
    UnpackedPtr<SharedFenceExportInfo> result(chain);
    for (typename UnpackedPtr<SharedFenceExportInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<SharedFenceVkSemaphoreOpaqueFDExportInfo>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceVkSemaphoreOpaqueFDExportInfo>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceVkSemaphoreSyncFDExportInfo>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceVkSemaphoreSyncFDExportInfo>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceVkSemaphoreZirconHandleExportInfo>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceVkSemaphoreZirconHandleExportInfo>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceDXGISharedHandleExportInfo>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceDXGISharedHandleExportInfo>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedFenceMTLSharedEventExportInfo>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedFenceExportInfo>, SharedFenceMTLSharedEventExportInfo>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedFenceExportInfo>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedFenceExportInfo,
                        UnpackedPtr<SharedFenceExportInfo>,
                        detail::AdditionalExtensions<SharedFenceExportInfo>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SharedFenceExportInfo"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedFenceExportInfo"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor> Unpack<SharedTextureMemoryBeginAccessDescriptor>(typename UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>::PtrType chain) {
    UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor> result(chain);
    for (typename UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<SharedTextureMemoryVkImageLayoutBeginState>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, SharedTextureMemoryVkImageLayoutBeginState>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryD3DSwapchainBeginState>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, SharedTextureMemoryD3DSwapchainBeginState>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedTextureMemoryBeginAccessDescriptor,
                        UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>,
                        detail::AdditionalExtensions<SharedTextureMemoryBeginAccessDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>> ValidateAndUnpack<SharedTextureMemoryBeginAccessDescriptor>(
    typename UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>::PtrType chain) {
    UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor> result(chain);
    for (typename UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<SharedTextureMemoryVkImageLayoutBeginState>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, SharedTextureMemoryVkImageLayoutBeginState>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryD3DSwapchainBeginState>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, SharedTextureMemoryD3DSwapchainBeginState>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedTextureMemoryBeginAccessDescriptor,
                        UnpackedPtr<SharedTextureMemoryBeginAccessDescriptor>,
                        detail::AdditionalExtensions<SharedTextureMemoryBeginAccessDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SharedTextureMemoryBeginAccessDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedTextureMemoryBeginAccessDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedTextureMemoryDescriptor> Unpack<SharedTextureMemoryDescriptor>(typename UnpackedPtr<SharedTextureMemoryDescriptor>::PtrType chain) {
    UnpackedPtr<SharedTextureMemoryDescriptor> result(chain);
    for (typename UnpackedPtr<SharedTextureMemoryDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<SharedTextureMemoryVkDedicatedAllocationDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryVkDedicatedAllocationDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryAHardwareBufferDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryAHardwareBufferDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryDmaBufDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryDmaBufDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryOpaqueFDDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryOpaqueFDDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryZirconHandleDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryZirconHandleDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryDXGISharedHandleDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryDXGISharedHandleDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryIOSurfaceDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryIOSurfaceDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SharedTextureMemoryEGLImageDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryEGLImageDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedTextureMemoryDescriptor,
                        UnpackedPtr<SharedTextureMemoryDescriptor>,
                        detail::AdditionalExtensions<SharedTextureMemoryDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedTextureMemoryDescriptor>> ValidateAndUnpack<SharedTextureMemoryDescriptor>(
    typename UnpackedPtr<SharedTextureMemoryDescriptor>::PtrType chain) {
    UnpackedPtr<SharedTextureMemoryDescriptor> result(chain);
    for (typename UnpackedPtr<SharedTextureMemoryDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<SharedTextureMemoryVkDedicatedAllocationDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryVkDedicatedAllocationDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryAHardwareBufferDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryAHardwareBufferDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryDmaBufDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryDmaBufDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryOpaqueFDDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryOpaqueFDDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryZirconHandleDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryZirconHandleDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryDXGISharedHandleDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryDXGISharedHandleDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryIOSurfaceDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryIOSurfaceDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SharedTextureMemoryEGLImageDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryDescriptor>, SharedTextureMemoryEGLImageDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedTextureMemoryDescriptor,
                        UnpackedPtr<SharedTextureMemoryDescriptor>,
                        detail::AdditionalExtensions<SharedTextureMemoryDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SharedTextureMemoryDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedTextureMemoryDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedTextureMemoryEndAccessState> Unpack<SharedTextureMemoryEndAccessState>(typename UnpackedPtr<SharedTextureMemoryEndAccessState>::PtrType chain) {
    UnpackedPtr<SharedTextureMemoryEndAccessState> result(chain);
    for (typename UnpackedPtr<SharedTextureMemoryEndAccessState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<SharedTextureMemoryVkImageLayoutEndState>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryEndAccessState>, SharedTextureMemoryVkImageLayoutEndState>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryEndAccessState>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedTextureMemoryEndAccessState,
                        UnpackedPtr<SharedTextureMemoryEndAccessState>,
                        detail::AdditionalExtensions<SharedTextureMemoryEndAccessState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedTextureMemoryEndAccessState>> ValidateAndUnpack<SharedTextureMemoryEndAccessState>(
    typename UnpackedPtr<SharedTextureMemoryEndAccessState>::PtrType chain) {
    UnpackedPtr<SharedTextureMemoryEndAccessState> result(chain);
    for (typename UnpackedPtr<SharedTextureMemoryEndAccessState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<SharedTextureMemoryVkImageLayoutEndState>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryEndAccessState>, SharedTextureMemoryVkImageLayoutEndState>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryEndAccessState>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedTextureMemoryEndAccessState,
                        UnpackedPtr<SharedTextureMemoryEndAccessState>,
                        detail::AdditionalExtensions<SharedTextureMemoryEndAccessState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SharedTextureMemoryEndAccessState"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedTextureMemoryEndAccessState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<StorageTextureBindingLayout> Unpack<StorageTextureBindingLayout>(typename UnpackedPtr<StorageTextureBindingLayout>::PtrType chain) {
    UnpackedPtr<StorageTextureBindingLayout> result(chain);
    for (typename UnpackedPtr<StorageTextureBindingLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        StorageTextureBindingLayout,
                        UnpackedPtr<StorageTextureBindingLayout>,
                        detail::AdditionalExtensions<StorageTextureBindingLayout>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<StorageTextureBindingLayout>> ValidateAndUnpack<StorageTextureBindingLayout>(
    typename UnpackedPtr<StorageTextureBindingLayout>::PtrType chain) {
    UnpackedPtr<StorageTextureBindingLayout> result(chain);
    for (typename UnpackedPtr<StorageTextureBindingLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        StorageTextureBindingLayout,
                        UnpackedPtr<StorageTextureBindingLayout>,
                        detail::AdditionalExtensions<StorageTextureBindingLayout>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "StorageTextureBindingLayout"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "StorageTextureBindingLayout"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SurfaceCapabilities> Unpack<SurfaceCapabilities>(typename UnpackedPtr<SurfaceCapabilities>::PtrType chain) {
    UnpackedPtr<SurfaceCapabilities> result(chain);
    for (typename UnpackedPtr<SurfaceCapabilities>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SurfaceCapabilities,
                        UnpackedPtr<SurfaceCapabilities>,
                        detail::AdditionalExtensions<SurfaceCapabilities>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SurfaceCapabilities>> ValidateAndUnpack<SurfaceCapabilities>(
    typename UnpackedPtr<SurfaceCapabilities>::PtrType chain) {
    UnpackedPtr<SurfaceCapabilities> result(chain);
    for (typename UnpackedPtr<SurfaceCapabilities>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SurfaceCapabilities,
                        UnpackedPtr<SurfaceCapabilities>,
                        detail::AdditionalExtensions<SurfaceCapabilities>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SurfaceCapabilities"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SurfaceCapabilities"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SurfaceConfiguration> Unpack<SurfaceConfiguration>(typename UnpackedPtr<SurfaceConfiguration>::PtrType chain) {
    UnpackedPtr<SurfaceConfiguration> result(chain);
    for (typename UnpackedPtr<SurfaceConfiguration>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SurfaceConfiguration,
                        UnpackedPtr<SurfaceConfiguration>,
                        detail::AdditionalExtensions<SurfaceConfiguration>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SurfaceConfiguration>> ValidateAndUnpack<SurfaceConfiguration>(
    typename UnpackedPtr<SurfaceConfiguration>::PtrType chain) {
    UnpackedPtr<SurfaceConfiguration> result(chain);
    for (typename UnpackedPtr<SurfaceConfiguration>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SurfaceConfiguration,
                        UnpackedPtr<SurfaceConfiguration>,
                        detail::AdditionalExtensions<SurfaceConfiguration>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SurfaceConfiguration"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SurfaceConfiguration"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SurfaceDescriptor> Unpack<SurfaceDescriptor>(typename UnpackedPtr<SurfaceDescriptor>::PtrType chain) {
    UnpackedPtr<SurfaceDescriptor> result(chain);
    for (typename UnpackedPtr<SurfaceDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<SurfaceDescriptorFromAndroidNativeWindow>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromAndroidNativeWindow>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SurfaceDescriptorFromCanvasHTMLSelector>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromCanvasHTMLSelector>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SurfaceDescriptorFromMetalLayer>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromMetalLayer>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SurfaceDescriptorFromWindowsHWND>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromWindowsHWND>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SurfaceDescriptorFromXlibWindow>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromXlibWindow>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SurfaceDescriptorFromWaylandSurface>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromWaylandSurface>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SurfaceDescriptorFromWindowsCoreWindow>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromWindowsCoreWindow>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<SurfaceDescriptorFromWindowsSwapChainPanel>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromWindowsSwapChainPanel>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SurfaceDescriptor,
                        UnpackedPtr<SurfaceDescriptor>,
                        detail::AdditionalExtensions<SurfaceDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SurfaceDescriptor>> ValidateAndUnpack<SurfaceDescriptor>(
    typename UnpackedPtr<SurfaceDescriptor>::PtrType chain) {
    UnpackedPtr<SurfaceDescriptor> result(chain);
    for (typename UnpackedPtr<SurfaceDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<SurfaceDescriptorFromAndroidNativeWindow>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromAndroidNativeWindow>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SurfaceDescriptorFromCanvasHTMLSelector>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromCanvasHTMLSelector>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SurfaceDescriptorFromMetalLayer>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromMetalLayer>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SurfaceDescriptorFromWindowsHWND>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromWindowsHWND>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SurfaceDescriptorFromXlibWindow>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromXlibWindow>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SurfaceDescriptorFromWaylandSurface>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromWaylandSurface>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SurfaceDescriptorFromWindowsCoreWindow>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromWindowsCoreWindow>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<SurfaceDescriptorFromWindowsSwapChainPanel>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SurfaceDescriptor>, SurfaceDescriptorFromWindowsSwapChainPanel>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SurfaceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SurfaceDescriptor,
                        UnpackedPtr<SurfaceDescriptor>,
                        detail::AdditionalExtensions<SurfaceDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SurfaceDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SurfaceDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SwapChainDescriptor> Unpack<SwapChainDescriptor>(typename UnpackedPtr<SwapChainDescriptor>::PtrType chain) {
    UnpackedPtr<SwapChainDescriptor> result(chain);
    for (typename UnpackedPtr<SwapChainDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SwapChainDescriptor,
                        UnpackedPtr<SwapChainDescriptor>,
                        detail::AdditionalExtensions<SwapChainDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SwapChainDescriptor>> ValidateAndUnpack<SwapChainDescriptor>(
    typename UnpackedPtr<SwapChainDescriptor>::PtrType chain) {
    UnpackedPtr<SwapChainDescriptor> result(chain);
    for (typename UnpackedPtr<SwapChainDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SwapChainDescriptor,
                        UnpackedPtr<SwapChainDescriptor>,
                        detail::AdditionalExtensions<SwapChainDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SwapChainDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SwapChainDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<TextureBindingLayout> Unpack<TextureBindingLayout>(typename UnpackedPtr<TextureBindingLayout>::PtrType chain) {
    UnpackedPtr<TextureBindingLayout> result(chain);
    for (typename UnpackedPtr<TextureBindingLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        TextureBindingLayout,
                        UnpackedPtr<TextureBindingLayout>,
                        detail::AdditionalExtensions<TextureBindingLayout>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<TextureBindingLayout>> ValidateAndUnpack<TextureBindingLayout>(
    typename UnpackedPtr<TextureBindingLayout>::PtrType chain) {
    UnpackedPtr<TextureBindingLayout> result(chain);
    for (typename UnpackedPtr<TextureBindingLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        TextureBindingLayout,
                        UnpackedPtr<TextureBindingLayout>,
                        detail::AdditionalExtensions<TextureBindingLayout>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "TextureBindingLayout"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "TextureBindingLayout"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<TextureDataLayout> Unpack<TextureDataLayout>(typename UnpackedPtr<TextureDataLayout>::PtrType chain) {
    UnpackedPtr<TextureDataLayout> result(chain);
    for (typename UnpackedPtr<TextureDataLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        TextureDataLayout,
                        UnpackedPtr<TextureDataLayout>,
                        detail::AdditionalExtensions<TextureDataLayout>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<TextureDataLayout>> ValidateAndUnpack<TextureDataLayout>(
    typename UnpackedPtr<TextureDataLayout>::PtrType chain) {
    UnpackedPtr<TextureDataLayout> result(chain);
    for (typename UnpackedPtr<TextureDataLayout>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        TextureDataLayout,
                        UnpackedPtr<TextureDataLayout>,
                        detail::AdditionalExtensions<TextureDataLayout>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "TextureDataLayout"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "TextureDataLayout"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<TextureViewDescriptor> Unpack<TextureViewDescriptor>(typename UnpackedPtr<TextureViewDescriptor>::PtrType chain) {
    UnpackedPtr<TextureViewDescriptor> result(chain);
    for (typename UnpackedPtr<TextureViewDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<YCbCrVkDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<TextureViewDescriptor>, YCbCrVkDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<TextureViewDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        TextureViewDescriptor,
                        UnpackedPtr<TextureViewDescriptor>,
                        detail::AdditionalExtensions<TextureViewDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<TextureViewDescriptor>> ValidateAndUnpack<TextureViewDescriptor>(
    typename UnpackedPtr<TextureViewDescriptor>::PtrType chain) {
    UnpackedPtr<TextureViewDescriptor> result(chain);
    for (typename UnpackedPtr<TextureViewDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<YCbCrVkDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<TextureViewDescriptor>, YCbCrVkDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<TextureViewDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        TextureViewDescriptor,
                        UnpackedPtr<TextureViewDescriptor>,
                        detail::AdditionalExtensions<TextureViewDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "TextureViewDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "TextureViewDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<UncapturedErrorCallbackInfo> Unpack<UncapturedErrorCallbackInfo>(typename UnpackedPtr<UncapturedErrorCallbackInfo>::PtrType chain) {
    UnpackedPtr<UncapturedErrorCallbackInfo> result(chain);
    for (typename UnpackedPtr<UncapturedErrorCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        UncapturedErrorCallbackInfo,
                        UnpackedPtr<UncapturedErrorCallbackInfo>,
                        detail::AdditionalExtensions<UncapturedErrorCallbackInfo>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<UncapturedErrorCallbackInfo>> ValidateAndUnpack<UncapturedErrorCallbackInfo>(
    typename UnpackedPtr<UncapturedErrorCallbackInfo>::PtrType chain) {
    UnpackedPtr<UncapturedErrorCallbackInfo> result(chain);
    for (typename UnpackedPtr<UncapturedErrorCallbackInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        UncapturedErrorCallbackInfo,
                        UnpackedPtr<UncapturedErrorCallbackInfo>,
                        detail::AdditionalExtensions<UncapturedErrorCallbackInfo>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "UncapturedErrorCallbackInfo"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "UncapturedErrorCallbackInfo"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<BindGroupDescriptor> Unpack<BindGroupDescriptor>(typename UnpackedPtr<BindGroupDescriptor>::PtrType chain) {
    UnpackedPtr<BindGroupDescriptor> result(chain);
    for (typename UnpackedPtr<BindGroupDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindGroupDescriptor,
                        UnpackedPtr<BindGroupDescriptor>,
                        detail::AdditionalExtensions<BindGroupDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<BindGroupDescriptor>> ValidateAndUnpack<BindGroupDescriptor>(
    typename UnpackedPtr<BindGroupDescriptor>::PtrType chain) {
    UnpackedPtr<BindGroupDescriptor> result(chain);
    for (typename UnpackedPtr<BindGroupDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindGroupDescriptor,
                        UnpackedPtr<BindGroupDescriptor>,
                        detail::AdditionalExtensions<BindGroupDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "BindGroupDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "BindGroupDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<BindGroupLayoutEntry> Unpack<BindGroupLayoutEntry>(typename UnpackedPtr<BindGroupLayoutEntry>::PtrType chain) {
    UnpackedPtr<BindGroupLayoutEntry> result(chain);
    for (typename UnpackedPtr<BindGroupLayoutEntry>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<StaticSamplerBindingLayout>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<BindGroupLayoutEntry>, StaticSamplerBindingLayout>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<BindGroupLayoutEntry>, ExtPtrType>
                );
                break;
            }
            case STypeFor<ExternalTextureBindingLayout>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<BindGroupLayoutEntry>, ExternalTextureBindingLayout>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<BindGroupLayoutEntry>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindGroupLayoutEntry,
                        UnpackedPtr<BindGroupLayoutEntry>,
                        detail::AdditionalExtensions<BindGroupLayoutEntry>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<BindGroupLayoutEntry>> ValidateAndUnpack<BindGroupLayoutEntry>(
    typename UnpackedPtr<BindGroupLayoutEntry>::PtrType chain) {
    UnpackedPtr<BindGroupLayoutEntry> result(chain);
    for (typename UnpackedPtr<BindGroupLayoutEntry>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<StaticSamplerBindingLayout>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<BindGroupLayoutEntry>, StaticSamplerBindingLayout>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<BindGroupLayoutEntry>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<ExternalTextureBindingLayout>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<BindGroupLayoutEntry>, ExternalTextureBindingLayout>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<BindGroupLayoutEntry>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindGroupLayoutEntry,
                        UnpackedPtr<BindGroupLayoutEntry>,
                        detail::AdditionalExtensions<BindGroupLayoutEntry>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "BindGroupLayoutEntry"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "BindGroupLayoutEntry"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<CompilationInfo> Unpack<CompilationInfo>(typename UnpackedPtr<CompilationInfo>::PtrType chain) {
    UnpackedPtr<CompilationInfo> result(chain);
    for (typename UnpackedPtr<CompilationInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CompilationInfo,
                        UnpackedPtr<CompilationInfo>,
                        detail::AdditionalExtensions<CompilationInfo>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<CompilationInfo>> ValidateAndUnpack<CompilationInfo>(
    typename UnpackedPtr<CompilationInfo>::PtrType chain) {
    UnpackedPtr<CompilationInfo> result(chain);
    for (typename UnpackedPtr<CompilationInfo>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        CompilationInfo,
                        UnpackedPtr<CompilationInfo>,
                        detail::AdditionalExtensions<CompilationInfo>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "CompilationInfo"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "CompilationInfo"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ComputePassDescriptor> Unpack<ComputePassDescriptor>(typename UnpackedPtr<ComputePassDescriptor>::PtrType chain) {
    UnpackedPtr<ComputePassDescriptor> result(chain);
    for (typename UnpackedPtr<ComputePassDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ComputePassDescriptor,
                        UnpackedPtr<ComputePassDescriptor>,
                        detail::AdditionalExtensions<ComputePassDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ComputePassDescriptor>> ValidateAndUnpack<ComputePassDescriptor>(
    typename UnpackedPtr<ComputePassDescriptor>::PtrType chain) {
    UnpackedPtr<ComputePassDescriptor> result(chain);
    for (typename UnpackedPtr<ComputePassDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ComputePassDescriptor,
                        UnpackedPtr<ComputePassDescriptor>,
                        detail::AdditionalExtensions<ComputePassDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "ComputePassDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ComputePassDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<DepthStencilState> Unpack<DepthStencilState>(typename UnpackedPtr<DepthStencilState>::PtrType chain) {
    UnpackedPtr<DepthStencilState> result(chain);
    for (typename UnpackedPtr<DepthStencilState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DepthStencilStateDepthWriteDefinedDawn>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<DepthStencilState>, DepthStencilStateDepthWriteDefinedDawn>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<DepthStencilState>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        DepthStencilState,
                        UnpackedPtr<DepthStencilState>,
                        detail::AdditionalExtensions<DepthStencilState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<DepthStencilState>> ValidateAndUnpack<DepthStencilState>(
    typename UnpackedPtr<DepthStencilState>::PtrType chain) {
    UnpackedPtr<DepthStencilState> result(chain);
    for (typename UnpackedPtr<DepthStencilState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DepthStencilStateDepthWriteDefinedDawn>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<DepthStencilState>, DepthStencilStateDepthWriteDefinedDawn>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<DepthStencilState>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        DepthStencilState,
                        UnpackedPtr<DepthStencilState>,
                        detail::AdditionalExtensions<DepthStencilState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "DepthStencilState"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "DepthStencilState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ExternalTextureDescriptor> Unpack<ExternalTextureDescriptor>(typename UnpackedPtr<ExternalTextureDescriptor>::PtrType chain) {
    UnpackedPtr<ExternalTextureDescriptor> result(chain);
    for (typename UnpackedPtr<ExternalTextureDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ExternalTextureDescriptor,
                        UnpackedPtr<ExternalTextureDescriptor>,
                        detail::AdditionalExtensions<ExternalTextureDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ExternalTextureDescriptor>> ValidateAndUnpack<ExternalTextureDescriptor>(
    typename UnpackedPtr<ExternalTextureDescriptor>::PtrType chain) {
    UnpackedPtr<ExternalTextureDescriptor> result(chain);
    for (typename UnpackedPtr<ExternalTextureDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ExternalTextureDescriptor,
                        UnpackedPtr<ExternalTextureDescriptor>,
                        detail::AdditionalExtensions<ExternalTextureDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "ExternalTextureDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ExternalTextureDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ImageCopyExternalTexture> Unpack<ImageCopyExternalTexture>(typename UnpackedPtr<ImageCopyExternalTexture>::PtrType chain) {
    UnpackedPtr<ImageCopyExternalTexture> result(chain);
    for (typename UnpackedPtr<ImageCopyExternalTexture>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ImageCopyExternalTexture,
                        UnpackedPtr<ImageCopyExternalTexture>,
                        detail::AdditionalExtensions<ImageCopyExternalTexture>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ImageCopyExternalTexture>> ValidateAndUnpack<ImageCopyExternalTexture>(
    typename UnpackedPtr<ImageCopyExternalTexture>::PtrType chain) {
    UnpackedPtr<ImageCopyExternalTexture> result(chain);
    for (typename UnpackedPtr<ImageCopyExternalTexture>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ImageCopyExternalTexture,
                        UnpackedPtr<ImageCopyExternalTexture>,
                        detail::AdditionalExtensions<ImageCopyExternalTexture>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "ImageCopyExternalTexture"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ImageCopyExternalTexture"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<InstanceDescriptor> Unpack<InstanceDescriptor>(typename UnpackedPtr<InstanceDescriptor>::PtrType chain) {
    UnpackedPtr<InstanceDescriptor> result(chain);
    for (typename UnpackedPtr<InstanceDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DawnTogglesDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<InstanceDescriptor>, DawnTogglesDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<InstanceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnWGSLBlocklist>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<InstanceDescriptor>, DawnWGSLBlocklist>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<InstanceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnWireWGSLControl>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<InstanceDescriptor>, DawnWireWGSLControl>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<InstanceDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        InstanceDescriptor,
                        UnpackedPtr<InstanceDescriptor>,
                        detail::AdditionalExtensions<InstanceDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<InstanceDescriptor>> ValidateAndUnpack<InstanceDescriptor>(
    typename UnpackedPtr<InstanceDescriptor>::PtrType chain) {
    UnpackedPtr<InstanceDescriptor> result(chain);
    for (typename UnpackedPtr<InstanceDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DawnTogglesDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<InstanceDescriptor>, DawnTogglesDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<InstanceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnWGSLBlocklist>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<InstanceDescriptor>, DawnWGSLBlocklist>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<InstanceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnWireWGSLControl>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<InstanceDescriptor>, DawnWireWGSLControl>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<InstanceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        InstanceDescriptor,
                        UnpackedPtr<InstanceDescriptor>,
                        detail::AdditionalExtensions<InstanceDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "InstanceDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "InstanceDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ProgrammableStageDescriptor> Unpack<ProgrammableStageDescriptor>(typename UnpackedPtr<ProgrammableStageDescriptor>::PtrType chain) {
    UnpackedPtr<ProgrammableStageDescriptor> result(chain);
    for (typename UnpackedPtr<ProgrammableStageDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ProgrammableStageDescriptor,
                        UnpackedPtr<ProgrammableStageDescriptor>,
                        detail::AdditionalExtensions<ProgrammableStageDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ProgrammableStageDescriptor>> ValidateAndUnpack<ProgrammableStageDescriptor>(
    typename UnpackedPtr<ProgrammableStageDescriptor>::PtrType chain) {
    UnpackedPtr<ProgrammableStageDescriptor> result(chain);
    for (typename UnpackedPtr<ProgrammableStageDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ProgrammableStageDescriptor,
                        UnpackedPtr<ProgrammableStageDescriptor>,
                        detail::AdditionalExtensions<ProgrammableStageDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "ProgrammableStageDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ProgrammableStageDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RenderPassColorAttachment> Unpack<RenderPassColorAttachment>(typename UnpackedPtr<RenderPassColorAttachment>::PtrType chain) {
    UnpackedPtr<RenderPassColorAttachment> result(chain);
    for (typename UnpackedPtr<RenderPassColorAttachment>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DawnRenderPassColorAttachmentRenderToSingleSampled>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<RenderPassColorAttachment>, DawnRenderPassColorAttachmentRenderToSingleSampled>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<RenderPassColorAttachment>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPassColorAttachment,
                        UnpackedPtr<RenderPassColorAttachment>,
                        detail::AdditionalExtensions<RenderPassColorAttachment>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RenderPassColorAttachment>> ValidateAndUnpack<RenderPassColorAttachment>(
    typename UnpackedPtr<RenderPassColorAttachment>::PtrType chain) {
    UnpackedPtr<RenderPassColorAttachment> result(chain);
    for (typename UnpackedPtr<RenderPassColorAttachment>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DawnRenderPassColorAttachmentRenderToSingleSampled>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<RenderPassColorAttachment>, DawnRenderPassColorAttachmentRenderToSingleSampled>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<RenderPassColorAttachment>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPassColorAttachment,
                        UnpackedPtr<RenderPassColorAttachment>,
                        detail::AdditionalExtensions<RenderPassColorAttachment>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "RenderPassColorAttachment"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RenderPassColorAttachment"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RenderPassStorageAttachment> Unpack<RenderPassStorageAttachment>(typename UnpackedPtr<RenderPassStorageAttachment>::PtrType chain) {
    UnpackedPtr<RenderPassStorageAttachment> result(chain);
    for (typename UnpackedPtr<RenderPassStorageAttachment>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPassStorageAttachment,
                        UnpackedPtr<RenderPassStorageAttachment>,
                        detail::AdditionalExtensions<RenderPassStorageAttachment>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RenderPassStorageAttachment>> ValidateAndUnpack<RenderPassStorageAttachment>(
    typename UnpackedPtr<RenderPassStorageAttachment>::PtrType chain) {
    UnpackedPtr<RenderPassStorageAttachment> result(chain);
    for (typename UnpackedPtr<RenderPassStorageAttachment>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPassStorageAttachment,
                        UnpackedPtr<RenderPassStorageAttachment>,
                        detail::AdditionalExtensions<RenderPassStorageAttachment>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "RenderPassStorageAttachment"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RenderPassStorageAttachment"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RequiredLimits> Unpack<RequiredLimits>(typename UnpackedPtr<RequiredLimits>::PtrType chain) {
    UnpackedPtr<RequiredLimits> result(chain);
    for (typename UnpackedPtr<RequiredLimits>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RequiredLimits,
                        UnpackedPtr<RequiredLimits>,
                        detail::AdditionalExtensions<RequiredLimits>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RequiredLimits>> ValidateAndUnpack<RequiredLimits>(
    typename UnpackedPtr<RequiredLimits>::PtrType chain) {
    UnpackedPtr<RequiredLimits> result(chain);
    for (typename UnpackedPtr<RequiredLimits>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RequiredLimits,
                        UnpackedPtr<RequiredLimits>,
                        detail::AdditionalExtensions<RequiredLimits>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "RequiredLimits"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RequiredLimits"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SharedTextureMemoryProperties> Unpack<SharedTextureMemoryProperties>(typename UnpackedPtr<SharedTextureMemoryProperties>::PtrType chain) {
    UnpackedPtr<SharedTextureMemoryProperties> result(chain);
    for (typename UnpackedPtr<SharedTextureMemoryProperties>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<SharedTextureMemoryAHardwareBufferProperties>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryProperties>, SharedTextureMemoryAHardwareBufferProperties>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryProperties>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedTextureMemoryProperties,
                        UnpackedPtr<SharedTextureMemoryProperties>,
                        detail::AdditionalExtensions<SharedTextureMemoryProperties>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SharedTextureMemoryProperties>> ValidateAndUnpack<SharedTextureMemoryProperties>(
    typename UnpackedPtr<SharedTextureMemoryProperties>::PtrType chain) {
    UnpackedPtr<SharedTextureMemoryProperties> result(chain);
    for (typename UnpackedPtr<SharedTextureMemoryProperties>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<SharedTextureMemoryAHardwareBufferProperties>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SharedTextureMemoryProperties>, SharedTextureMemoryAHardwareBufferProperties>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SharedTextureMemoryProperties>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SharedTextureMemoryProperties,
                        UnpackedPtr<SharedTextureMemoryProperties>,
                        detail::AdditionalExtensions<SharedTextureMemoryProperties>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SharedTextureMemoryProperties"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SharedTextureMemoryProperties"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<SupportedLimits> Unpack<SupportedLimits>(typename UnpackedPtr<SupportedLimits>::PtrType chain) {
    UnpackedPtr<SupportedLimits> result(chain);
    for (typename UnpackedPtr<SupportedLimits>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DawnExperimentalSubgroupLimits>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SupportedLimits>, DawnExperimentalSubgroupLimits>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<SupportedLimits>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SupportedLimits,
                        UnpackedPtr<SupportedLimits>,
                        detail::AdditionalExtensions<SupportedLimits>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<SupportedLimits>> ValidateAndUnpack<SupportedLimits>(
    typename UnpackedPtr<SupportedLimits>::PtrType chain) {
    UnpackedPtr<SupportedLimits> result(chain);
    for (typename UnpackedPtr<SupportedLimits>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DawnExperimentalSubgroupLimits>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<SupportedLimits>, DawnExperimentalSubgroupLimits>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<SupportedLimits>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        SupportedLimits,
                        UnpackedPtr<SupportedLimits>,
                        detail::AdditionalExtensions<SupportedLimits>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "SupportedLimits"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "SupportedLimits"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<TextureDescriptor> Unpack<TextureDescriptor>(typename UnpackedPtr<TextureDescriptor>::PtrType chain) {
    UnpackedPtr<TextureDescriptor> result(chain);
    for (typename UnpackedPtr<TextureDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<TextureBindingViewDimensionDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<TextureDescriptor>, TextureBindingViewDimensionDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<TextureDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnTextureInternalUsageDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<TextureDescriptor>, DawnTextureInternalUsageDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<TextureDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        TextureDescriptor,
                        UnpackedPtr<TextureDescriptor>,
                        detail::AdditionalExtensions<TextureDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<TextureDescriptor>> ValidateAndUnpack<TextureDescriptor>(
    typename UnpackedPtr<TextureDescriptor>::PtrType chain) {
    UnpackedPtr<TextureDescriptor> result(chain);
    for (typename UnpackedPtr<TextureDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<TextureBindingViewDimensionDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<TextureDescriptor>, TextureBindingViewDimensionDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<TextureDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnTextureInternalUsageDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<TextureDescriptor>, DawnTextureInternalUsageDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<TextureDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        TextureDescriptor,
                        UnpackedPtr<TextureDescriptor>,
                        detail::AdditionalExtensions<TextureDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "TextureDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "TextureDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<BindGroupLayoutDescriptor> Unpack<BindGroupLayoutDescriptor>(typename UnpackedPtr<BindGroupLayoutDescriptor>::PtrType chain) {
    UnpackedPtr<BindGroupLayoutDescriptor> result(chain);
    for (typename UnpackedPtr<BindGroupLayoutDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindGroupLayoutDescriptor,
                        UnpackedPtr<BindGroupLayoutDescriptor>,
                        detail::AdditionalExtensions<BindGroupLayoutDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<BindGroupLayoutDescriptor>> ValidateAndUnpack<BindGroupLayoutDescriptor>(
    typename UnpackedPtr<BindGroupLayoutDescriptor>::PtrType chain) {
    UnpackedPtr<BindGroupLayoutDescriptor> result(chain);
    for (typename UnpackedPtr<BindGroupLayoutDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        BindGroupLayoutDescriptor,
                        UnpackedPtr<BindGroupLayoutDescriptor>,
                        detail::AdditionalExtensions<BindGroupLayoutDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "BindGroupLayoutDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "BindGroupLayoutDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ColorTargetState> Unpack<ColorTargetState>(typename UnpackedPtr<ColorTargetState>::PtrType chain) {
    UnpackedPtr<ColorTargetState> result(chain);
    for (typename UnpackedPtr<ColorTargetState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<ColorTargetStateExpandResolveTextureDawn>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<ColorTargetState>, ColorTargetStateExpandResolveTextureDawn>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<ColorTargetState>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ColorTargetState,
                        UnpackedPtr<ColorTargetState>,
                        detail::AdditionalExtensions<ColorTargetState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ColorTargetState>> ValidateAndUnpack<ColorTargetState>(
    typename UnpackedPtr<ColorTargetState>::PtrType chain) {
    UnpackedPtr<ColorTargetState> result(chain);
    for (typename UnpackedPtr<ColorTargetState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<ColorTargetStateExpandResolveTextureDawn>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<ColorTargetState>, ColorTargetStateExpandResolveTextureDawn>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<ColorTargetState>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ColorTargetState,
                        UnpackedPtr<ColorTargetState>,
                        detail::AdditionalExtensions<ColorTargetState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "ColorTargetState"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ColorTargetState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<ComputePipelineDescriptor> Unpack<ComputePipelineDescriptor>(typename UnpackedPtr<ComputePipelineDescriptor>::PtrType chain) {
    UnpackedPtr<ComputePipelineDescriptor> result(chain);
    for (typename UnpackedPtr<ComputePipelineDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DawnComputePipelineFullSubgroups>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<ComputePipelineDescriptor>, DawnComputePipelineFullSubgroups>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<ComputePipelineDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ComputePipelineDescriptor,
                        UnpackedPtr<ComputePipelineDescriptor>,
                        detail::AdditionalExtensions<ComputePipelineDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<ComputePipelineDescriptor>> ValidateAndUnpack<ComputePipelineDescriptor>(
    typename UnpackedPtr<ComputePipelineDescriptor>::PtrType chain) {
    UnpackedPtr<ComputePipelineDescriptor> result(chain);
    for (typename UnpackedPtr<ComputePipelineDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DawnComputePipelineFullSubgroups>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<ComputePipelineDescriptor>, DawnComputePipelineFullSubgroups>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<ComputePipelineDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        ComputePipelineDescriptor,
                        UnpackedPtr<ComputePipelineDescriptor>,
                        detail::AdditionalExtensions<ComputePipelineDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "ComputePipelineDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "ComputePipelineDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<DeviceDescriptor> Unpack<DeviceDescriptor>(typename UnpackedPtr<DeviceDescriptor>::PtrType chain) {
    UnpackedPtr<DeviceDescriptor> result(chain);
    for (typename UnpackedPtr<DeviceDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<DawnTogglesDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<DeviceDescriptor>, DawnTogglesDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<DeviceDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<DawnCacheDeviceDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<DeviceDescriptor>, DawnCacheDeviceDescriptor>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<DeviceDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        DeviceDescriptor,
                        UnpackedPtr<DeviceDescriptor>,
                        detail::AdditionalExtensions<DeviceDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<DeviceDescriptor>> ValidateAndUnpack<DeviceDescriptor>(
    typename UnpackedPtr<DeviceDescriptor>::PtrType chain) {
    UnpackedPtr<DeviceDescriptor> result(chain);
    for (typename UnpackedPtr<DeviceDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<DawnTogglesDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<DeviceDescriptor>, DawnTogglesDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<DeviceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<DawnCacheDeviceDescriptor>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<DeviceDescriptor>, DawnCacheDeviceDescriptor>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<DeviceDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        DeviceDescriptor,
                        UnpackedPtr<DeviceDescriptor>,
                        detail::AdditionalExtensions<DeviceDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "DeviceDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "DeviceDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RenderPassDescriptor> Unpack<RenderPassDescriptor>(typename UnpackedPtr<RenderPassDescriptor>::PtrType chain) {
    UnpackedPtr<RenderPassDescriptor> result(chain);
    for (typename UnpackedPtr<RenderPassDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            case STypeFor<RenderPassDescriptorMaxDrawCount>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<RenderPassDescriptor>, RenderPassDescriptorMaxDrawCount>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<RenderPassDescriptor>, ExtPtrType>
                );
                break;
            }
            case STypeFor<RenderPassPixelLocalStorage>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<RenderPassDescriptor>, RenderPassPixelLocalStorage>::Type;
                std::get<ExtPtrType>(result.mUnpacked) =
                    static_cast<ExtPtrType>(next);
                result.mBitset.set(
                    detail::UnpackedPtrIndexOf<UnpackedPtr<RenderPassDescriptor>, ExtPtrType>
                );
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPassDescriptor,
                        UnpackedPtr<RenderPassDescriptor>,
                        detail::AdditionalExtensions<RenderPassDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RenderPassDescriptor>> ValidateAndUnpack<RenderPassDescriptor>(
    typename UnpackedPtr<RenderPassDescriptor>::PtrType chain) {
    UnpackedPtr<RenderPassDescriptor> result(chain);
    for (typename UnpackedPtr<RenderPassDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            case STypeFor<RenderPassDescriptorMaxDrawCount>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<RenderPassDescriptor>, RenderPassDescriptorMaxDrawCount>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<RenderPassDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            case STypeFor<RenderPassPixelLocalStorage>: {
                using ExtPtrType =
                    typename detail::PtrTypeFor<UnpackedPtr<RenderPassDescriptor>, RenderPassPixelLocalStorage>::Type;
                auto& member = std::get<ExtPtrType>(result.mUnpacked);
                if (member != nullptr) {
                    duplicate = true;
                } else {
                    member = static_cast<ExtPtrType>(next);
                    result.mBitset.set(
                        detail::UnpackedPtrIndexOf<UnpackedPtr<RenderPassDescriptor>, ExtPtrType>
                    );
                }
                break;
            }
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPassDescriptor,
                        UnpackedPtr<RenderPassDescriptor>,
                        detail::AdditionalExtensions<RenderPassDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "RenderPassDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RenderPassDescriptor"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<VertexState> Unpack<VertexState>(typename UnpackedPtr<VertexState>::PtrType chain) {
    UnpackedPtr<VertexState> result(chain);
    for (typename UnpackedPtr<VertexState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        VertexState,
                        UnpackedPtr<VertexState>,
                        detail::AdditionalExtensions<VertexState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<VertexState>> ValidateAndUnpack<VertexState>(
    typename UnpackedPtr<VertexState>::PtrType chain) {
    UnpackedPtr<VertexState> result(chain);
    for (typename UnpackedPtr<VertexState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        VertexState,
                        UnpackedPtr<VertexState>,
                        detail::AdditionalExtensions<VertexState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "VertexState"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "VertexState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<FragmentState> Unpack<FragmentState>(typename UnpackedPtr<FragmentState>::PtrType chain) {
    UnpackedPtr<FragmentState> result(chain);
    for (typename UnpackedPtr<FragmentState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        FragmentState,
                        UnpackedPtr<FragmentState>,
                        detail::AdditionalExtensions<FragmentState>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<FragmentState>> ValidateAndUnpack<FragmentState>(
    typename UnpackedPtr<FragmentState>::PtrType chain) {
    UnpackedPtr<FragmentState> result(chain);
    for (typename UnpackedPtr<FragmentState>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        FragmentState,
                        UnpackedPtr<FragmentState>,
                        detail::AdditionalExtensions<FragmentState>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "FragmentState"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "FragmentState"
            );
        }
    }
    return result;
}
template <>
UnpackedPtr<RenderPipelineDescriptor> Unpack<RenderPipelineDescriptor>(typename UnpackedPtr<RenderPipelineDescriptor>::PtrType chain) {
    UnpackedPtr<RenderPipelineDescriptor> result(chain);
    for (typename UnpackedPtr<RenderPipelineDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPipelineDescriptor,
                        UnpackedPtr<RenderPipelineDescriptor>,
                        detail::AdditionalExtensions<RenderPipelineDescriptor>::List>;
                Unpacker::Unpack(result.mUnpacked, result.mBitset, next, nullptr);
                break;
            }
        }
    }
    return result;
}
template <>
ResultOrError<UnpackedPtr<RenderPipelineDescriptor>> ValidateAndUnpack<RenderPipelineDescriptor>(
    typename UnpackedPtr<RenderPipelineDescriptor>::PtrType chain) {
    UnpackedPtr<RenderPipelineDescriptor> result(chain);
    for (typename UnpackedPtr<RenderPipelineDescriptor>::ChainType next = chain->nextInChain;
         next != nullptr;
         next = next->nextInChain) {
        bool duplicate = false;
        switch (next->sType) {
            default: {
                using Unpacker =
                    AdditionalExtensionUnpacker<
                        RenderPipelineDescriptor,
                        UnpackedPtr<RenderPipelineDescriptor>,
                        detail::AdditionalExtensions<RenderPipelineDescriptor>::List>;
                if (!Unpacker::Unpack(result.mUnpacked,
                                      result.mBitset,
                                      next,
                                      &duplicate)) {
                    return DAWN_VALIDATION_ERROR(
                        "Unexpected chained struct of type %s found on %s chain.",
                        next->sType, "RenderPipelineDescriptor"
                    );
                }
                break;
            }
        }
        if (duplicate) {
            return DAWN_VALIDATION_ERROR(
                "Duplicate chained struct of type %s found on %s chain.",
                next->sType, "RenderPipelineDescriptor"
            );
        }
    }
    return result;
}

}  // namespace dawn::native
