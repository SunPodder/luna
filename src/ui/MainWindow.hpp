#pragma once
#include <QObject>
#include <QQmlApplicationEngine>

namespace Luna::UI {

class MainWindow : public QObject {
    Q_OBJECT
public:
    explicit MainWindow(QObject *parent = nullptr);
    void show();

private:
   QQmlApplicationEngine m_engine;
};

}
