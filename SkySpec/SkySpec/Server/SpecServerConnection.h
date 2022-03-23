#pragma once

#include "SpecServer.h"

namespace SkySpec::Server {
    class SpecServerConnection {
        SpecServer& _specServer;
        connection_hdl _connectionId;

    public:
        SpecServerConnection(SpecServer& specServer, connection_hdl connectionId)
            : _specServer(specServer), _connectionId(connectionId) {}

        void DispatchTextMessage(const std::string text) {
            _specServer.DispatchTextMessage(text, _connectionId);
        }
    };
}

