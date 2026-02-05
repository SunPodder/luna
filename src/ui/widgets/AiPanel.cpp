#include "AiPanel.hpp"

namespace Luna::UI {

AiPanel::AiPanel(QWidget *parent) : QWidget(parent) {
    setupUi();
}

void AiPanel::setupUi() {
    setStyleSheet("background-color: #252526; color: #cccccc;");
    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    
    auto *label = new QLabel("AI PANEL", this);
    label->setAlignment(Qt::AlignCenter);
    QFont font; font.setBold(true); label->setFont(font);
    layout->addWidget(label);
}

}
