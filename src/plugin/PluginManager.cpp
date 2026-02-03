#include "PluginManager.hpp"
#include "../core/Core.hpp"

namespace Luna::Plugin {

PluginManager::PluginManager() {
    Core::Logger::log("PluginManager initialized");
}

void PluginManager::loadPlugins() {
    Core::Logger::log("Loading plugins...");
    // TODO: Implement Lua loading
}

}
