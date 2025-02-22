// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "platform/impl/windows/utils.h"

#include "absl/strings/ascii.h"
#include "absl/strings/str_format.h"

namespace location {
namespace nearby {
namespace windows {

std::string uint64_to_mac_address_string(uint64_t bluetoothAddress) {
  std::string buffer = absl::StrFormat(
      "%2llx:%2llx:%2llx:%2llx:%2llx:%2llx", bluetoothAddress >> 40,
      (bluetoothAddress >> 32) & 0xff, (bluetoothAddress >> 24) & 0xff,
      (bluetoothAddress >> 16) & 0xff, (bluetoothAddress >> 8) & 0xff,
      bluetoothAddress & 0xff);

  return absl::AsciiStrToUpper(buffer);
}

}  // namespace windows
}  // namespace nearby
}  // namespace location
