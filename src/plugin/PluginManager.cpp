#include "PluginManager.hpp"
#include "../core/Core.hpp"
#include "ui/widgets/ToolBar.hpp"
#include <filesystem>

namespace Luna::Plugin {

PluginManager::PluginManager() {
    Core::Logger::log("PluginManager initialized");
    
    // Initialize Lua state
    lua.open_libraries(sol::lib::base, sol::lib::package, sol::lib::io, sol::lib::string);

    // Expose API
    lua.set_function("register_toolbar_item", &PluginManager::registerToolBarItem, this);
}

void PluginManager::loadPlugins() {
    Core::Logger::log("Loading plugins...");
    
    // For now, look in a "plugins" directory in the current working directory
    // In a real app, this would be standardized paths
    std::string pluginDir = "plugins";
    
    if (!std::filesystem::exists(pluginDir)) {
        Core::Logger::log("Plugins directory not found: " + QString::fromStdString(pluginDir));
        return;
    }

    for (const auto& entry : std::filesystem::directory_iterator(pluginDir)) {
        if (entry.path().extension() == ".lua") {
            Core::Logger::log("Loading plugin: " + QString::fromStdString(entry.path().string()));
            try {
                lua.script_file(entry.path().string());
            } catch (const sol::error& e) {
                Core::Logger::log("Error loading plugin: " + QString::fromStdString(e.what()));
            }
        }
    }
}

void PluginManager::registerToolBarItem(const std::string& name, const std::string& iconPath) {
    tools.push_back({name, iconPath});
    Core::Logger::log("Tool registered: " + QString::fromStdString(name));
}

const std::vector<Luna::UI::ToolBar::Item>& PluginManager::getTools() const {
    return tools;
}

}
