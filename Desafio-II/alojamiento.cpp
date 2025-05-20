#include "alojamiento.h"
#include <cstring>

Alojamiento::Alojamiento(const char* cod, const char* dir, const char* mun, char t, float precio, Anfitrion* a) {
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);

    direccion = new char[strlen(dir) + 1];
    strcpy(direccion, dir);

    municipio = new char[strlen(mun) + 1];
    strcpy(municipio, mun);

    tipo = t;
    precioPorNoche = precio;
    anfitrion = a;
}

Alojamiento::~Alojamiento() {
    delete[] codigo;
    delete[] direccion;
    delete[] municipio;
}

const char* Alojamiento::getCodigo() const {
    return codigo;
}
