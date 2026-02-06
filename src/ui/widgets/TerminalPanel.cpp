#include "TerminalPanel.hpp"
#include <QVBoxLayout>
#include <QApplication>
#include <QClipboard>
#include <qtermwidget.h>

namespace Luna::UI {

TerminalPanel::TerminalPanel(QWidget *parent) : QWidget(parent) {
    setupUi();
}

void TerminalPanel::setupUi() {
    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);

    m_termWidget = new QTermWidget();
    
    // Configure terminal
    auto font = QFont("Cascadia Code", 10);
    font.setStyleHint(QFont::Monospace);
    m_termWidget->setTerminalFont(font);
    
    m_termWidget->setColorScheme("DarkPastels");
    m_termWidget->setScrollBarPosition(QTermWidget::ScrollBarRight);

    // Custom Scrollbar Style
    m_termWidget->setStyleSheet(
        "QScrollBar:vertical {"
        "    border: none;"
        "    background: #1e1e1e;"
        "    width: 14px;"
        "    margin: 0px 0px 0px 0px;"
        "}"
        "QScrollBar::handle:vertical {"
        "    background: #424242;"
        "    min-height: 20px;"
        "}"
        "QScrollBar::handle:vertical:hover {"
        "    background: #4f4f4f;"
        "}"
        "QScrollBar::handle:vertical:pressed {"
        "    background: #007fd4;"
        "}"
        "QScrollBar::add-line:vertical {"
        "    height: 0px;"
        "    subcontrol-position: bottom;"
        "    subcontrol-origin: margin;"
        "}"
        "QScrollBar::sub-line:vertical {"
        "    height: 0px;"
        "    subcontrol-position: top;"
        "    subcontrol-origin: margin;"
        "}"
        "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {"
        "    background: none;"
        "}"
        "QScrollBar:horizontal {"
        "    border: none;"
        "    background: #1e1e1e;"
        "    height: 14px;"
        "    margin: 0px 0px 0px 0px;"
        "}"
        "QScrollBar::handle:horizontal {"
        "    background: #424242;"
        "    min-width: 20px;"
        "}"
        "QScrollBar::handle:horizontal:hover {"
        "    background: #4f4f4f;"
        "}"
        "QScrollBar::handle:horizontal:pressed {"
        "    background: #007fd4;"
        "}"
        "QScrollBar::add-line:horizontal {"
        "    width: 0px;"
        "    subcontrol-position: right;"
        "    subcontrol-origin: margin;"
        "}"
        "QScrollBar::sub-line:horizontal {"
        "    width: 0px;"
        "    subcontrol-position: left;"
        "    subcontrol-origin: margin;"
        "}"
        "QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {"
        "    background: none;"
        "}"
    );
    
    layout->addWidget(m_termWidget);
    
    m_termWidget->startShellProgram();
}

void TerminalPanel::sendText(const QString &text) {
    m_termWidget->sendText(text);
}

void TerminalPanel::copyClipboard() {
    m_termWidget->copyClipboard();
}

void TerminalPanel::pasteClipboard() {
    m_termWidget->pasteClipboard();
}

}
