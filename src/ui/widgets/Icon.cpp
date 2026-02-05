#include "Icon.hpp"
#include "qicon.h"

namespace Luna::UI {

QIcon Icon(const QString &path) {
    return QIcon(path);
}

}
