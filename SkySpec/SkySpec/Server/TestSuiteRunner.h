#pragma once

#include <functional>

#include "MessageDispatcher.h"

namespace SkySpec::Server {
    class TestSuiteRunner {
        MessageDispatcher& _messageDispatcher;

    public:
        TestSuiteRunner(MessageDispatcher& messageDispatcher) : _messageDispatcher(messageDispatcher) {}

        virtual void RunAll(std::function<void(bool)> testSuiteCallback) = 0;

        void Print(const std::string& text) { _messageDispatcher.Print(text); }
        void PrintTestPass(const std::string& testName) { _messageDispatcher.PrintTestPass(testName); }
        void PrintTestFail(const std::string& testName) { _messageDispatcher.PrintTestFail(testName); }
    };
}
