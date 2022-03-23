#pragma once

#include <SkySpec/Server/TestSuiteRunner.h>

using namespace SkySpec::Server;

namespace SkySpec::SKSE::Bandit {
    class BanditTestSuiteRunner : public TestSuiteRunner {
    public:
        BanditTestSuiteRunner(MessageDispatcher messageDispatcher) : TestSuiteRunner(messageDispatcher) {}

        void RunAll(std::function<void(bool)> testSuiteCallback) override {
            // ...
            testSuiteCallback(true);
        }
    };
}
