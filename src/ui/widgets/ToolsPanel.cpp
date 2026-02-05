#include "ToolsPanel.hpp"

namespace Luna::UI {

ToolsPanel::ToolsPanel(QWidget *parent) : QWidget(parent) {
    setupUi();
}

void ToolsPanel::setupUi() {
    setStyleSheet("background-color: #333333; color: #cccccc;");
    setFixedWidth(50);
    
    auto *layout = new QVBoxLayout(this);
    auto *label = new QLabel("Tools", this); 
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label); 
}

}
