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
    setStyleSheet(
        "QWidget { background-color: #333333; }"
        "QPushButton { border: none; border-radius: 0px; background-color: transparent; text-align: center; }"
        "QPushButton:hover { background-color: #444444; }"
        "QPushButton:checked { background-color: #383838; border-left: 2px solid #007fd4; }"
    );
    setFixedWidth(50);
    
    m_layout = new QVBoxLayout(this);
    m_layout->setSpacing(0);
    m_layout->setContentsMargins(0, 10, 0, 10);
    m_layout->addStretch();
}

void ToolsPanel::refreshTools() {
    // Clear existing buttons if any (though currently only called once)
    // TODO: Clear m_buttons and layout if refresh needs to support re-calling
    
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
    btn->setFixedSize(50, 50);
    btn->setToolTip(name);
    btn->setCheckable(true);
    
    if (!iconPath.isEmpty()) {
        btn->setIcon(QIcon(iconPath));
    } else {
        btn->setText(name.left(2)); // Fallback text
    }
    
    connect(btn, &QPushButton::clicked, this, [this, name]() {
        handleToolClick(name);
    });
    
    m_layout->insertWidget(index, btn);
    m_buttons[name] = btn;
}

void ToolsPanel::handleToolClick(const QString& toolName) {
    if (m_activeTool == toolName) {
        // Deselect
        if (m_buttons[m_activeTool]) {
            m_buttons[m_activeTool]->setChecked(false);
        }
        m_activeTool.clear();
        emit toolSelected("");
    } else {
        // Switch
        if (!m_activeTool.isEmpty() && m_buttons[m_activeTool]) {
            m_buttons[m_activeTool]->setChecked(false);
        }
        
        m_activeTool = toolName;
        if (m_buttons[m_activeTool]) {
            m_buttons[m_activeTool]->setChecked(true);
        }
        emit toolSelected(m_activeTool);
    }
}

}
