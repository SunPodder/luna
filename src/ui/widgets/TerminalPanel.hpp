#pragma once
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

namespace Luna::UI {

class TerminalPanel : public QWidget {
    Q_OBJECT
public:
    explicit TerminalPanel(QWidget *parent = nullptr);

private:
    void setupUi();
};

}
