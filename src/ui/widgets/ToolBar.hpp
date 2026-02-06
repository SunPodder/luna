#pragma once
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <map>

namespace Luna::Plugin { class PluginManager; }

namespace Luna::UI {

class ToolBar : public QWidget {
    Q_OBJECT
public:
    explicit ToolBar(Luna::Plugin::PluginManager& pluginManager, QWidget *parent = nullptr);
    void refreshTools();

    struct Item {
        std::string name;
        std::string iconPath;
    };

signals:
    void toolSelected(const QString& toolName);

private:
    void setupUi();
    void addToolButton(const QString& name, const QString& iconPath);
    void handleToolClick(const QString& toolName);
    
    Luna::Plugin::PluginManager& m_pluginManager;
    QVBoxLayout* m_layout;
    
    QString m_activeTool;
    std::map<QString, QPushButton*> m_buttons;
};

}
