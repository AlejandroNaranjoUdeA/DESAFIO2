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
    std::cout << "\n===== MENU DE HUESPED =====\n";
    std::cout << "1. Ver alojamientos disponibles\n";
    std::cout << "2. Reservar alojamiento\n";
    std::cout << "3. Anular reservacion\n";
    std::cout << "4. Cerrar sesion\n";
    std::cout << "============================\n";
}
