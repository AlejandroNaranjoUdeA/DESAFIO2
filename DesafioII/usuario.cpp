#include "usuario.h"
#include <cstring>

Usuario::Usuario() {
    documento = nullptr;
    antiguedad = 0;
    puntuacion = 0.0f;
}

Usuario::~Usuario() {
    if (documento) delete[] documento;
}
