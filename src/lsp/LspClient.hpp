#pragma once
#include <QString>

namespace Luna::Lsp {

class LspClient {
public:
    LspClient();
    void connectToServer(const QString& serverPath);
};

}
