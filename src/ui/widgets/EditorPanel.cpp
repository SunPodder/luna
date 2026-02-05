#include "EditorPanel.hpp"

namespace Luna::UI {

EditorPanel::EditorPanel(QWidget *parent) : QWidget(parent) {
    setupUi();
}

void EditorPanel::setupUi() {
    setStyleSheet("background-color: #1e1e1e; color: #808080;");
    auto *layout = new QVBoxLayout(this);
    
    auto *label = new QLabel("Main Editor Area", this);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 20px;");
    layout->addWidget(label);
}

}
