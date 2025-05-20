#include "huesped.h"
#include <cstring>
#include <iostream>

Huesped::Huesped(const char* doc, int antig, float punt) {
    documento = new char[strlen(doc) + 1];
    strcpy(documento, doc);
    antiguedad = antig;
    puntuacion = punt;
}

const char* Huesped::getDocumento() const {
    return documento;
}

void Huesped::mostrarMenu() {
    std::cout << "[Menu de Huesped] (por implementar)\n";
}
