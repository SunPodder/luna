#include "TopBar.hpp"
#include <QMouseEvent>
#include <QWindow>

namespace Luna::UI {

TopBar::TopBar(QWidget *parent) : QWidget(parent) {
    setFixedHeight(35);
    setStyleSheet("background-color: #3c3c3c; color: #cccccc;");
    setupUi();
}

void TopBar::setupUi() {
    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(10, 0, 0, 0);
    layout->setSpacing(0);
    
    // Title
    m_titleLabel = new QLabel("Luna Editor - Topbar", this);
    m_titleLabel->setFont(QFont("Segoe UI", 10)); 
    layout->addStretch();
    layout->addWidget(m_titleLabel);
    layout->addStretch();

    // Controls
    m_minimizeBtn = createBtn("─", "minBtn");
    connect(m_minimizeBtn, &QPushButton::clicked, this, &TopBar::minimizeClicked);
    
    m_maximizeBtn = createBtn("☐", "maxBtn");
    connect(m_maximizeBtn, &QPushButton::clicked, [this]() {
        // Toggle icon logic should arguably be here or controlled by state.
        // For now, simpler to toggle icon locally or let parent update it.
        // Let's toggle locally for immediate feedback but really parent makes the call.
        // We will just emit.
        emit maximizeClicked();
    });

    m_closeBtn = createBtn("✕", "closeBtn", "#e81123", "#c10e1c");
    connect(m_closeBtn, &QPushButton::clicked, this, &TopBar::closeClicked);

    layout->addWidget(m_minimizeBtn);
    layout->addWidget(m_maximizeBtn);
    layout->addWidget(m_closeBtn);
}

QPushButton* TopBar::createBtn(const QString &text, const QString &id, const QString &hoverColor, const QString &pressColor) {
    auto *btn = new QPushButton(text, this);
    btn->setObjectName(id);
    btn->setFixedSize(45, 35);
    btn->setFlat(true);
    btn->setStyleSheet(QString(
        "QPushButton { border: none; background: transparent; color: white; font-size: 12px; }"
        "QPushButton:hover { background: %1; }"
        "QPushButton:pressed { background: %2; }"
    ).arg(hoverColor, pressColor));
    return btn;
}

void TopBar::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        // Check signal validity or just rely on parent handling
        if (window()->windowHandle()) {
            window()->windowHandle()->startSystemMove();
        } else {
             m_dragPosition = event->globalPosition().toPoint() - window()->frameGeometry().topLeft();
        }
    }
    QWidget::mousePressEvent(event);
}

void TopBar::mouseMoveEvent(QMouseEvent *event) {
    if (!window()->windowHandle()) {
        if (event->buttons() & Qt::LeftButton) {
            window()->move(event->globalPosition().toPoint() - m_dragPosition);
        }
    }
    QWidget::mouseMoveEvent(event);
}

void TopBar::mouseDoubleClickEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        emit maximizeClicked();
    }
    QWidget::mouseDoubleClickEvent(event);
}

}
