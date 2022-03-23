cmake_minimum_required(VERSION 3.21)

project(SkySpecExample VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

option(DEPLOY_TESTS "Bundles tests into SKSE plugin when enabled" ON)
if(DEPLOY_TESTS)
    set(SPEC_FILES spec/FirstSpec.cpp)
    add_definitions(-DINCLUDE_SPECS)
endif()

add_library(SkySpecExample SHARED src/plugin.cpp ${SPEC_FILES})
find_package(CommonLibSSE CONFIG REQUIRED)
target_link_libraries(SkySpecExample PRIVATE CommonLibSSE::CommonLibSSE)
target_include_directories(SkySpecExample PRIVATE SkySpec SkySpecBandit)

# hopefully will be encapsulated? if not that's ok.
find_path(BANDIT_INCLUDE_DIRS "bandit/adapters.h")
target_include_directories(SkySpecExample PRIVATE ${BANDIT_INCLUDE_DIRS})
find_package(websocketpp CONFIG REQUIRED)
target_link_libraries(SkySpecExample PRIVATE websocketpp::websocketpp)
