#pragma once
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

namespace Luna::UI {

class ToolsPanel : public QWidget {
    Q_OBJECT
public:
    explicit ToolsPanel(QWidget *parent = nullptr);

private:
    void setupUi();
};

}
