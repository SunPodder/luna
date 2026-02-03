#include "MainWindow.hpp"
#include "../core/Core.hpp"

namespace Luna::UI {

MainWindow::MainWindow(QObject *parent) : QObject(parent) {
    Core::Logger::log("MainWindow initialized");
}

void MainWindow::show() {
    Core::Logger::log("Showing Main Window (placeholder)");
}

}
