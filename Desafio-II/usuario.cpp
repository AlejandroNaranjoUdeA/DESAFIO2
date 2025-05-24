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

float Usuario::getPuntuacion() const {
    return puntuacion;
}

const char* Usuario::getNombre() const {
    return nombre;
}

void Usuario::setNombre(const char* nom) {
    if (nombre) delete[] nombre;
    nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);
}
