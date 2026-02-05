#pragma once
#include <QMainWindow>
#include <QSplitter>
#include <QVBoxLayout>

#include "widgets/TopBar.hpp"
#include "widgets/StatusBar.hpp"
#include "widgets/AiPanel.hpp"
#include "widgets/EditorPanel.hpp"
#include "widgets/TerminalPanel.hpp"
#include "widgets/SidePanel.hpp"
#include "widgets/ToolsPanel.hpp"

namespace Luna::Plugin { class PluginManager; }

namespace Luna::UI {

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(Luna::Plugin::PluginManager& pluginManager, QWidget *parent = nullptr);
    void show();

private:
    void setupUi();
    void setupLayout();

    Luna::Plugin::PluginManager& m_pluginManager;

    // UI Components
    QWidget *m_centralWidget{nullptr};
    QVBoxLayout *m_mainLayout{nullptr};
    
    // Custom Components
    TopBar *m_topBar{nullptr};
    StatusBar *m_statusBar{nullptr}; 

    // Content
    QSplitter *m_mainSplitter{nullptr}; 
    AiPanel *m_aiPanel{nullptr};
    QSplitter *m_centerSplitter{nullptr}; 
    EditorPanel *m_editorPanel{nullptr};
    TerminalPanel *m_terminalPanel{nullptr};
    SidePanel *m_sidePanel{nullptr};
    ToolsPanel *m_toolsPanel{nullptr};
    
    QPoint m_dragPosition;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};

}
