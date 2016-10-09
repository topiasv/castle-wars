#include "modelsuit.h"
#include <QString>

SuitType ModelSuit::stringToEnum(QString string) {
    string.toLower();
    if (string == "build") {
        return SuitType::Build;
    } else if (string == "attack") {
        return SuitType::Attack;
    } else if (string == "magic") {
        return SuitType::Magic;
    }
    return SuitType::Invalid;
}
