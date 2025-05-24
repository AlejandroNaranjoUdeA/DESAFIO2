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

    reservas = nullptr;
    cantidadReservas = 0;
}

Alojamiento::~Alojamiento() {
    delete[] codigo;
    delete[] direccion;
    delete[] municipio;

    // Liberar las reservaciones
    for (int i = 0; i < cantidadReservas; i++) {
        delete reservas[i];
    }
    delete[] reservas;

}

const char* Alojamiento::getCodigo() const {
    return codigo;
}

const char* Alojamiento::getDireccion() const {
    return direccion;
}

const char* Alojamiento::getMunicipio() const {
    return municipio;
}

float Alojamiento::getPrecioPorNoche() const {
    return precioPorNoche;
}

Anfitrion* Alojamiento::getAnfitrion() const {
    return anfitrion;
}

Reservacion** Alojamiento::getReservas() const {
    return reservas;
}

int Alojamiento::getCantidadReservas() const {
    return cantidadReservas;
}

// Agregar reservación
void Alojamiento::agregarReservacion(Reservacion* r) {
    Reservacion** nuevo = new Reservacion*[cantidadReservas + 1];
    for (int i = 0; i < cantidadReservas; i++) {
        nuevo[i] = reservas[i];
    }
    nuevo[cantidadReservas] = r;

    delete[] reservas;
    reservas = nuevo;
    cantidadReservas++;
}



bool Alojamiento::eliminarReservacionPorCodigo(const char* codigo) {
    int pos = -1;
    for (int i = 0; i < cantidadReservas; i++) {
        if (strcmp(reservas[i]->getCodigo(), codigo) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) return false;

    // Solo eliminamos el puntero, no el objeto (ya lo eliminó el huésped)
    for (int i = pos; i < cantidadReservas - 1; i++) {
        reservas[i] = reservas[i + 1];
    }

    cantidadReservas--;
    return true;
}

