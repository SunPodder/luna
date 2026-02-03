#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "core/Core.hpp"
#include "ui/MainWindow.hpp"
#include "editor/Editor.hpp"
#include "lsp/LspClient.hpp"
#include "ai/AiAssist.hpp"
#include "plugin/PluginManager.hpp"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    
    Luna::Core::Logger::log("Luna Editor Starting...");

    // Initialize Modules
    Luna::Plugin::PluginManager pluginManager;
    pluginManager.loadPlugins();

    Luna::Lsp::LspClient lspClient;
    Luna::Editor::Editor editor;
    Luna::AI::AiAssist aiAssist;
    Luna::UI::MainWindow window;

    window.show();

    return app.exec();
}
