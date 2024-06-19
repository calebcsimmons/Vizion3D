// Copyright 2022 The Dawn & Tint Authors
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

#ifndef SRC_DAWN_COMMON_GPUINFO_AUTOGEN_H_
#define SRC_DAWN_COMMON_GPUINFO_AUTOGEN_H_

#include <cstdint>
#include <string>

using PCIVendorID = uint32_t;
using PCIDeviceID = uint32_t;

namespace dawn::gpu_info {

// Vendor IDs
static constexpr PCIVendorID kVendorID_AMD = 0x1002;
static constexpr PCIVendorID kVendorID_Apple = 0x106b;
static constexpr PCIVendorID kVendorID_ARM = 0x13B5;
static constexpr PCIVendorID kVendorID_Google = 0x1AE0;
static constexpr PCIVendorID kVendorID_ImgTec = 0x1010;
static constexpr PCIVendorID kVendorID_Intel = 0x8086;
static constexpr PCIVendorID kVendorID_Mesa = 0x10005;
static constexpr PCIVendorID kVendorID_Microsoft = 0x1414;
static constexpr PCIVendorID kVendorID_Nvidia = 0x10DE;
static constexpr PCIVendorID kVendorID_Qualcomm = 0x5143;
static constexpr PCIVendorID kVendorID_Samsung = 0x144d;

// Vendor checks
bool IsAMD(PCIVendorID vendorId);
bool IsApple(PCIVendorID vendorId);
bool IsARM(PCIVendorID vendorId);
bool IsGoogle(PCIVendorID vendorId);
bool IsImgTec(PCIVendorID vendorId);
bool IsIntel(PCIVendorID vendorId);
bool IsMesa(PCIVendorID vendorId);
bool IsMicrosoft(PCIVendorID vendorId);
bool IsNvidia(PCIVendorID vendorId);
bool IsQualcomm(PCIVendorID vendorId);
bool IsSamsung(PCIVendorID vendorId);

// Architecture checks

// AMD architectures
bool IsAMDGCN2(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsAMDGCN5(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsAMDRDNA2(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsAMDGCN1(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsAMDGCN3(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsAMDGCN4(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsAMDRDNA1(PCIVendorID vendorId, PCIDeviceID deviceId);

// ARM architectures
bool IsARMMidgard(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsARMBifrost(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsARMValhall(PCIVendorID vendorId, PCIDeviceID deviceId);

// Google architectures
bool IsGoogleSwiftshader(PCIVendorID vendorId, PCIDeviceID deviceId);

// Intel architectures
bool IsIntelGen7(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsIntelGen8(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsIntelGen9(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsIntelGen11(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsIntelGen12LP(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsIntelGen12HP(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsIntelGen13LP(PCIVendorID vendorId, PCIDeviceID deviceId);

// Mesa architectures
bool IsMesaSoftware(PCIVendorID vendorId, PCIDeviceID deviceId);

// Microsoft architectures
bool IsMicrosoftWARP(PCIVendorID vendorId, PCIDeviceID deviceId);

// Nvidia architectures
bool IsNvidiaFermi(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsNvidiaKepler(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsNvidiaMaxwell(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsNvidiaPascal(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsNvidiaTuring(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsNvidiaAmpere(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsNvidiaLovelace(PCIVendorID vendorId, PCIDeviceID deviceId);

// Qualcomm architectures
bool IsQualcommAdreno4xx(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsQualcommAdreno5xx(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsQualcommAdreno6xx(PCIVendorID vendorId, PCIDeviceID deviceId);
bool IsQualcommAdreno7xx(PCIVendorID vendorId, PCIDeviceID deviceId);

// Samsung architectures
bool IsSamsungRDNA2(PCIVendorID vendorId, PCIDeviceID deviceId);

// GPUAdapterInfo fields
std::string GetVendorName(PCIVendorID vendorId);
std::string GetArchitectureName(PCIVendorID vendorId, PCIDeviceID deviceId);

} // namespace dawn::gpu_info
#endif  // SRC_DAWN_COMMON_GPUINFO_AUTOGEN_H_
