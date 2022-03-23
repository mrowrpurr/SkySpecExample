#pragma once

#include <SKSE/SKSE.h>

#include "SkySpec/SKSE"
#include "SkySpec/SpecServer.h"

namespace SkySpec::SKSE {
    void EnablePlugin(const PluginConfig& config = {}) {
        ::SKSE::GetMessagingInterface()->RegisterListener([](::SKSE::MessagingInterface::Message* event){
            if (event->type == ::SKSE::MessagingInterface::kDataLoaded) {
                //
            }
        });
    }
}
