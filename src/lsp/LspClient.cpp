#include "LspClient.hpp"
#include "../core/Core.hpp"

namespace Luna::Lsp {

LspClient::LspClient() {
    Core::Logger::log("LspClient initialized");
}

void LspClient::connectToServer(const QString& serverPath) {
    Core::Logger::log("Connecting to LSP server at: " + serverPath);
}

}
