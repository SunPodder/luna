#include "SidePanel.hpp"

namespace Luna::UI {

SidePanel::SidePanel(QWidget *parent) : QWidget(parent) {
    setupUi();
}

void SidePanel::setupUi() {
    setStyleSheet("background-color: #252526; color: #cccccc;");
    auto *layout = new QVBoxLayout(this);
    
    auto *label = new QLabel("Sidepanel", this);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);
}

}
