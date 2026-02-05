#pragma once
#include <string>
#include <vector>
#include <sol/sol.hpp>
#include "../ui/widgets/ToolsPanel.hpp"

namespace Luna::Plugin {

class PluginManager {
public:
    PluginManager();
    void loadPlugins();
    
    // Tools API
    void registerTool(const std::string& name, const std::string& iconPath);
    const std::vector<Luna::UI::Tool>& getTools() const;

private:
    sol::state lua;
    std::vector<Luna::UI::Tool> tools;
};

}
