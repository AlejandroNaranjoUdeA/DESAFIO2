#include "reservacion.h"
#include <cstring>

Reservacion::Reservacion(const char* cod, int fecha, int dur, float m, const char* nota, Huesped* h, Alojamiento* a) {
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);

    fechaInicio = fecha;
    duracion = dur;
    monto = m;

    anotacion = new char[strlen(nota) + 1];
    strcpy(anotacion, nota);

    huesped = h;
    alojamiento = a;
}

Reservacion::~Reservacion() {
    delete[] codigo;
    delete[] anotacion;
}

const char* Reservacion::getCodigo() const {
    return codigo;
}
