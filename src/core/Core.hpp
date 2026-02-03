#pragma once
#include <QString>

namespace Luna::Core {

class Logger {
public:
    static void log(const QString& message);
};

}
