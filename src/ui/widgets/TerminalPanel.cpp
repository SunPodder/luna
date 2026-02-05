#include "TerminalPanel.hpp"

namespace Luna::UI {

TerminalPanel::TerminalPanel(QWidget *parent) : QWidget(parent) {
    setupUi();
}

void TerminalPanel::setupUi() {
    setStyleSheet("background-color: #1e1e1e; color: #cccccc; border-top: 1px solid #333333;");
    auto *layout = new QVBoxLayout(this);
    
    auto *label = new QLabel("Terminal", this);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);
}

}
