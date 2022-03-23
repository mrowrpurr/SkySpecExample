#pragma once

#include <websocketpp/server.hpp>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/common/connection_hdl.hpp>

using namespace websocketpp;

namespace SkySpec::Server {
    typedef websocketpp::server<config::asio> WebSocketServer;
    typedef WebSocketServer::message_ptr WebSocketServerMessagePointer;

    class SpecServer {
        WebSocketServer& _webSocketServer;

    public:
        void Start() {

        }

        void DispatchTextMessage(const std::string text, connection_hdl connectionId) {
            _webSocketServer.send(connectionId, text, frame::opcode::text);
        }
    };
}

