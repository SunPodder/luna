#pragma once
#include <string>
#include <vector>
#include <sol/sol.hpp>
#include "../ui/widgets/ToolBar.hpp"

namespace Luna::Plugin {

class PluginManager {
public:
    PluginManager();
    void loadPlugins();
    
    // Tools API
    void registerToolBarItem(const std::string& name, const std::string& iconPath);
    const std::vector<Luna::UI::ToolBar::Item>& getTools() const;

private:
    sol::state lua;
    std::vector<Luna::UI::ToolBar::Item> tools;
};

}
