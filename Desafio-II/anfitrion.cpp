#include "anfitrion.h"
#include <cstring>
#include <iostream>

Anfitrion::Anfitrion(const char* doc, int antig, float punt) {
    documento = new char[strlen(doc) + 1];
    strcpy(documento, doc);
    antiguedad = antig;
    puntuacion = punt;
}

const char* Anfitrion::getDocumento() const {
    return documento;
}

void Anfitrion::mostrarMenu() {
    std::cout << "[Menu de Anfitrion] (por implementar)\n";
}
