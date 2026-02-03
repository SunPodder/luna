#include "AiAssist.hpp"
#include "../core/Core.hpp"
#include <QString>

namespace Luna::AI {

AiAssist::AiAssist() {
    Core::Logger::log("AiAssist initialized");
}

void AiAssist::query(const char* prompt) {
    Core::Logger::log("AI Query: " + QString(prompt));
}

}
