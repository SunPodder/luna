#include "ToolsPanel.hpp"
#include "../../plugin/PluginManager.hpp"
#include <QPushButton>

const std::vector<Luna::UI::Tool> tools = {
    {"Files", ":/icons/files.svg"},
    {"Search", ":/icons/search.svg"},
    {"Git", ":/icons/git.svg"},
    {"Plugins", ":/icons/plugins.svg"}
};

namespace Luna::UI {

ToolsPanel::ToolsPanel(Luna::Plugin::PluginManager& pluginManager, QWidget *parent)
    : QWidget(parent), m_pluginManager(pluginManager) {
    setupUi();
    refreshTools();
}

void ToolsPanel::setupUi() {
    setStyleSheet("background-color: #333333; color: #cccccc;");
    setFixedWidth(50);
    
    m_layout = new QVBoxLayout(this);
    m_layout->setSpacing(10);
    m_layout->setContentsMargins(5, 10, 5, 10);
    m_layout->addStretch();
}

void ToolsPanel::refreshTools() {
    auto pTools = m_pluginManager.getTools();
    for (const auto& tool : tools) {
        addToolButton(QString::fromStdString(tool.name), QString::fromStdString(tool.iconPath));
    }
    for (const auto& tool : pTools) {
        addToolButton(QString::fromStdString(tool.name), QString::fromStdString(tool.iconPath));
    }
}

void ToolsPanel::addToolButton(const QString& name, const QString& iconPath) {
    // Insert before the spacer (last item)
    int index = m_layout->count() - 1;
    
    QPushButton* btn = new QPushButton(this);
    btn->setFixedSize(40, 40);
    btn->setToolTip(name);
    
    if (!iconPath.isEmpty()) {
        btn->setIcon(QIcon(iconPath));
    } else {
        btn->setText(name.left(2)); // Fallback text
    }
    
    m_layout->insertWidget(index, btn);
}

}
