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
    std::cout << "\n===== MENU DE ANFITRION =====\n";
    std::cout << "1. Consultar mis alojamientos\n";
    std::cout << "2. Consultar reservaciones recibidas\n";
    std::cout << "3. Cerrar sesion\n";
    std::cout << "==============================\n";
}
