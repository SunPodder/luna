#pragma once
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

namespace Luna::UI {

class AiPanel : public QWidget {
    Q_OBJECT
public:
    explicit AiPanel(QWidget *parent = nullptr);

private:
    void setupUi();
};

}
