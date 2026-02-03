#include "MainWindow.hpp"
#include "../core/Core.hpp"
#include <QDir>
#include <QUrl>
#include <QCoreApplication>
#include <QFileInfo>
#include <QStringList>

namespace Luna::UI {

MainWindow::MainWindow(QObject *parent) : QObject(parent) {
    Core::Logger::log("MainWindow initialized");
}

void MainWindow::show() {
    Core::Logger::log("Showing Main Window (QML)");
    
    const QStringList potentialPaths = {
        "src/ui/qml/Main.qml",
        "../src/ui/qml/Main.qml",
        "../../src/ui/qml/Main.qml", 
        QCoreApplication::applicationDirPath() + "/../../src/ui/qml/Main.qml", // Common build layout
        "/home/sun/Workspace/luna/src/ui/qml/Main.qml" // Absolute fallback for this workspace
    };

    QString qmlPath;
    for (const auto& path : potentialPaths) {
        if (QFileInfo::exists(path)) {
            qmlPath = path;
            break;
        }
    }

    if (qmlPath.isEmpty()) {
        Core::Logger::log("Error: Could not find Main.qml");
        // Try simple filename in case it's in the same dir
        qmlPath = "Main.qml"; 
    }

    Core::Logger::log("Loading QML from: " + qmlPath);
    m_engine.load(QUrl::fromLocalFile(QFileInfo(qmlPath).absoluteFilePath()));

    if (m_engine.rootObjects().isEmpty()) {
        Core::Logger::log("Error: Failed to load QML component");
    }
}

}
