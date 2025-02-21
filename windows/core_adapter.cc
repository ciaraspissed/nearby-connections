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

#include "third_party/nearby_connections/windows/core_adapter.h"

#include "absl/strings/str_format.h"

namespace location {
namespace nearby {
namespace connections {

Core* InitCore(ServiceControllerRouter* router) {
  return new Core(router);
}

void CloseCore(Core* pCore) {
  if (pCore) {
    pCore->StopAllEndpoints(
        {.result_cb =
             std::function<void(location::nearby::connections::Status)>{
                 [](location::nearby::connections::Status) {}}});
    delete pCore;
  }
}

void StartAdvertising(Core* pCore, absl::string_view service_id,
                      ConnectionOptions options, ConnectionRequestInfo info,
                      ResultCallback callback) {
  if (pCore) {
    pCore->StartAdvertising(service_id, options, info, callback);
  }
}

void StopAdvertising(Core* pCore, ResultCallback callback) {
  if (pCore) {
    pCore->StopAdvertising(callback);
  }
}

void StartDiscovery(Core* pCore, absl::string_view service_id,
                    ConnectionOptions options, DiscoveryListener listener,
                    ResultCallback callback) {
  if (pCore) {
    pCore->StartDiscovery(service_id, options, listener, callback);
  }
}

void StopDiscovery(Core* pCore, ResultCallback callback) {
  if (pCore) {
    pCore->StopDiscovery(callback);
  }
}

void InjectEndpoint(Core* pCore, absl::string_view service_id,
                    OutOfBandConnectionMetadata metadata,
                    ResultCallback callback) {
  if (pCore) {
    pCore->InjectEndpoint(service_id, metadata, callback);
  }
}

void RequestConnection(Core* pCore, absl::string_view endpoint_id,
                       ConnectionRequestInfo info, ConnectionOptions options,
                       ResultCallback callback) {
  if (pCore) {
    pCore->RequestConnection(endpoint_id, info, options, callback);
  }
}

void AcceptConnection(Core* pCore, absl::string_view endpoint_id,
                      PayloadListener listener, ResultCallback callback) {
  if (pCore) {
    pCore->AcceptConnection(endpoint_id, listener, callback);
  }
}

void RejectConnection(Core* pCore, absl::string_view endpoint_id,
                      ResultCallback callback) {
  if (pCore) {
    pCore->RejectConnection(endpoint_id, callback);
  }
}

void SendPayload(Core* pCore, absl::Span<const std::string> endpoint_ids,
                 Payload payload, ResultCallback callback) {
  if (pCore) {
    pCore->SendPayload(endpoint_ids, std::move(payload), callback);
  }
}

void CancelPayload(Core* pCore, std::int64_t payload_id,
                   ResultCallback callback) {
  if (pCore) {
    pCore->CancelPayload(payload_id, callback);
  }
}

void DisconnectFromEndpoint(Core* pCore, absl::string_view endpoint_id,
                            ResultCallback callback) {
  if (pCore) {
    pCore->DisconnectFromEndpoint(endpoint_id, callback);
  }
}

void StopAllEndpoints(Core* pCore, ResultCallback callback) {
  if (pCore) {
    pCore->StopAllEndpoints(callback);
  }
}

void InitiateBandwidthUpgrade(Core* pCore, absl::string_view endpoint_id,
                              ResultCallback callback) {
  if (pCore) {
    pCore->InitiateBandwidthUpgrade(endpoint_id, callback);
  }
}

const char* GetLocalEndpointId(Core* pCore) {
  if (pCore) {
    std::string endpoint_id = pCore->GetLocalEndpointId();
    char * result = new char[endpoint_id.length() + 1];
    absl::SNPrintF(result, endpoint_id.length() + 1, "%s", endpoint_id);
    return result;
  }
  return "Null-Core";
}

ServiceControllerRouter* InitServiceControllerRouter() {
  return new ServiceControllerRouter();
}

void CloseServiceControllerRouter(ServiceControllerRouter* pRouter) {
  if (pRouter) {
    delete pRouter;
  }
}

}  // namespace connections
}  // namespace nearby
}  // namespace location
