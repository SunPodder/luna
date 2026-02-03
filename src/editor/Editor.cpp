#include "Editor.hpp"
#include "../core/Core.hpp"
#include <QString>

namespace Luna::Editor {

Editor::Editor() {
    Core::Logger::log("Editor initialized");
}

void Editor::openFile(const char* path) {
    Core::Logger::log("Opening file: " + QString(path));
}

}
