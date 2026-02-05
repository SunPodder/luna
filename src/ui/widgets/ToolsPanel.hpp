#pragma once
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

namespace Luna::Plugin { class PluginManager; }

namespace Luna::UI {

struct Tool {
    std::string name;
    std::string iconPath;
};

class ToolsPanel : public QWidget {
    Q_OBJECT
public:
    explicit ToolsPanel(Luna::Plugin::PluginManager& pluginManager, QWidget *parent = nullptr);
    void refreshTools();

private:
    void setupUi();
    void addToolButton(const QString& name, const QString& iconPath);
    
    Luna::Plugin::PluginManager& m_pluginManager;
    QVBoxLayout* m_layout;
};

}
