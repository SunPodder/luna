#include "Core.hpp"
#include <QDebug>

namespace Luna::Core {

void Logger::log(const QString& message) {
    qDebug() << "[Core] " << message;
}

}
