#pragma once
#include <QStatusBar>
#include <QLabel>

namespace Luna::UI {

class StatusBar : public QStatusBar {
    Q_OBJECT
public:
    explicit StatusBar(QWidget *parent = nullptr);
    void setStatus(const QString &message);

private:
    void setupUi();
    QLabel *m_statusLabel{nullptr};
};

}
