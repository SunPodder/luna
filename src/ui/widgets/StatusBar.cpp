#include "StatusBar.hpp"

namespace Luna::UI {

StatusBar::StatusBar(QWidget *parent) : QStatusBar(parent) {
    setupUi();
}

void StatusBar::setupUi() {
    setStyleSheet(
        "QStatusBar { background-color: #007fd4; color: white; }"
        "QStatusBar::item { border: none; }"
    );
    setSizeGripEnabled(true);

    m_statusLabel = new QLabel("Ready", this);
    m_statusLabel->setStyleSheet("font-size: 12px; margin-left: 10px; background: transparent;"); 
    
    // As per previous logic, add to layout normally for left alignment similar to VS Code / QML request
    addWidget(m_statusLabel);
}

void StatusBar::setStatus(const QString &message) {
    if (m_statusLabel) {
        m_statusLabel->setText(message);
    }
}

}
