#pragma once
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

namespace Luna::UI {

class EditorPanel : public QWidget {
    Q_OBJECT
public:
    explicit EditorPanel(QWidget *parent = nullptr);

private:
    void setupUi();
};

}
