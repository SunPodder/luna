#include "SidePanel.hpp"
#include <QLabel>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QTreeView>
#include <QFileSystemModel>
#include <QHeaderView>

namespace Luna::UI {

SidePanel::SidePanel(QWidget *parent) : QWidget(parent) {
    setupUi();
    setupPages();
}

void SidePanel::setupUi() {
    setMinimumWidth(200);
    setStyleSheet("background-color: #252526; color: #cccccc; border: none;");
    
    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    
    m_stack = new QStackedWidget(this);
    layout->addWidget(m_stack);
}

void SidePanel::setupPages() {
    // Files
    QWidget* filesWidget = createFilesWidget();
    m_pages["Files"] = filesWidget;
    m_stack->addWidget(filesWidget);

    // Search
    QWidget* searchWidget = createPlaceholderWidget("Search");
    m_pages["Search"] = searchWidget;
    m_stack->addWidget(searchWidget);
    
    // Git
    QWidget* gitWidget = createPlaceholderWidget("Git");
    m_pages["Git"] = gitWidget;
    m_stack->addWidget(gitWidget);
    
    // Plugins
    QWidget* pluginsWidget = createPlaceholderWidget("Plugins");
    m_pages["Plugins"] = pluginsWidget;
    m_stack->addWidget(pluginsWidget);
}

void SidePanel::setContent(const QString& toolName) {
    if (m_pages.contains(toolName)) {
        m_stack->setCurrentWidget(m_pages[toolName]);
    } else {
        // If unknown tool, show a generic placeholder or add it on the fly
        if (!m_pages.contains(toolName)) {
            QWidget* w = createPlaceholderWidget(toolName);
            m_pages[toolName] = w;
            m_stack->addWidget(w);
        }
        m_stack->setCurrentWidget(m_pages[toolName]);
    }
}

QWidget* SidePanel::createFilesWidget() {
    QWidget* container = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(container);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    QLabel* header = new QLabel("EXPLORER", container);
    header->setStyleSheet("padding: 10px; font-weight: bold; background-color: #252526;");
    layout->addWidget(header);

    QTreeView* tree = new QTreeView(container);
    QFileSystemModel* model = new QFileSystemModel(tree);
    model->setRootPath(QDir::currentPath());
    
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));
    tree->setHeaderHidden(true);
    tree->setAnimated(false);
    tree->setIndentation(20);
    tree->setSortingEnabled(true);
    tree->setStyleSheet(
        "QTreeView { background-color: #252526; border: none; }"
        "QTreeView::item { padding: 2px; }"
        "QTreeView::item:hover { background-color: #2a2d2e; }"
        "QTreeView::item:selected { background-color: #37373d; }"
    );
    
    // Hide columns other than name
    for (int i = 1; i < model->columnCount(); ++i) {
        tree->hideColumn(i);
    }

    layout->addWidget(tree);
    return container;
}

QWidget* SidePanel::createPlaceholderWidget(const QString& name) {
    QWidget* container = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(container);
    layout->setAlignment(Qt::AlignTop);

    QLabel* header = new QLabel(name.toUpper(), container);
    header->setStyleSheet("padding: 10px; font-weight: bold;");
    layout->addWidget(header);

    QLabel* content = new QLabel(name + " View Not Implemented", container);
    content->setAlignment(Qt::AlignCenter);
    content->setStyleSheet("color: #666666; padding-top: 20px;");
    layout->addWidget(content);

    return container;
}

}
