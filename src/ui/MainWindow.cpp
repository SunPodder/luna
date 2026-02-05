#include "MainWindow.hpp"
#include "../core/Core.hpp"
#include <QMouseEvent>
#include <QApplication>
#include <QWindow>

namespace Luna::UI {

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    Core::Logger::log("MainWindow initialized");
    setupUi();
}

void MainWindow::setupUi() {
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    resize(1280, 800);
    setWindowTitle("Luna Editor");

    setupLayout();
}

void MainWindow::setupLayout() {
    m_centralWidget = new QWidget(this);
    m_centralWidget->setStyleSheet("background-color: #1e1e1e; font-family: 'Segoe UI', sans-serif;");
    setCentralWidget(m_centralWidget);
    
    m_mainLayout = new QVBoxLayout(m_centralWidget);
    m_mainLayout->setSpacing(0);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);

    // TopBar
    m_topBar = new TopBar(this);
    m_mainLayout->addWidget(m_topBar);
    
    connect(m_topBar, &TopBar::minimizeClicked, this, &QWidget::showMinimized);
    connect(m_topBar, &TopBar::maximizeClicked, [this]() {
        if (isMaximized()) showNormal();
        else showMaximized();
    });
    connect(m_topBar, &TopBar::closeClicked, this, &QWidget::close);

    // Main Splitter
    m_mainSplitter = new QSplitter(Qt::Horizontal, this);
    m_mainSplitter->setHandleWidth(2);
    m_mainSplitter->setStyleSheet(
        "QSplitter::handle { background-color: #1e1e1e; }"
        "QSplitter::handle:hover { background-color: #505050; }"
        "QSplitter::handle:pressed { background-color: #007fd4; }"
    );

    // AI Panel
    m_aiPanel = new AiPanel(this);
    m_mainSplitter->addWidget(m_aiPanel);

    // Center Splitter (Editor + Terminal)
    m_centerSplitter = new QSplitter(Qt::Vertical, this);
    m_centerSplitter->setHandleWidth(2);
    
    m_editorPanel = new EditorPanel(this);
    m_centerSplitter->addWidget(m_editorPanel);

    m_terminalPanel = new TerminalPanel(this);
    m_centerSplitter->addWidget(m_terminalPanel);

    m_centerSplitter->setStretchFactor(0, 3);
    m_centerSplitter->setStretchFactor(1, 1);
    m_mainSplitter->addWidget(m_centerSplitter);

    // Side Panel
    m_sidePanel = new SidePanel(this);
    m_mainSplitter->addWidget(m_sidePanel);

    // Tools Panel
    m_toolsPanel = new ToolsPanel(this);
    m_mainSplitter->addWidget(m_toolsPanel);

    m_mainLayout->addWidget(m_mainSplitter);

    // StatusBar
    m_statusBar = new StatusBar(this);
    setStatusBar(m_statusBar);
}

void MainWindow::show() {
    Core::Logger::log("Showing Main Window (Widgets)");
    QMainWindow::show();
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    // Basic drag support fallback if clicking on empty areas (though topbar handles its own)
    if (event->button() == Qt::LeftButton) {
        if (!childAt(event->pos())) {
             m_dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        }
    }
    QMainWindow::mousePressEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        if (!childAt(event->pos())) {
            move(event->globalPosition().toPoint() - m_dragPosition);
        }
    }
    QMainWindow::mouseMoveEvent(event);
}

}