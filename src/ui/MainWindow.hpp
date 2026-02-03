#pragma once
#include <QObject>

namespace Luna::UI {

class MainWindow : public QObject {
    Q_OBJECT
public:
    explicit MainWindow(QObject *parent = nullptr);
    void show();
};

}
