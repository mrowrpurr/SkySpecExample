#pragma once

#include <format>

#include "SpecServerConnection.h"

namespace SkySpec::Server {
    class MessageDispatcher {
        SpecServerConnection _specServerConnection;
    public:
        MessageDispatcher(SpecServerConnection& specServerConnection) : _specServerConnection(specServerConnection) {}
        void Print(const std::string& text) { _specServerConnection.DispatchTextMessage(std::format("Print:{}", text)); }
        void PrintTestPass(const std::string& text) { _specServerConnection.DispatchTextMessage(std::format("PrintTestPass:{}", text)); }
        void PrintTestFail(const std::string& text) { _specServerConnection.DispatchTextMessage(std::format("PrintTestFail:{}", text)); }
    };
}
