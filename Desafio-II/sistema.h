#ifndef SISTEMA_H
#define SISTEMA_H

#include "huesped.h"
#include "anfitrion.h"
#include "alojamiento.h"
#include "reservacion.h"

class Sistema {
private:
    Huesped** huespedes;
    int cantidadHuespedes;

    Anfitrion** anfitriones;
    int cantidadAnfitriones;

    Alojamiento** alojamientos;
    int cantidadAlojamientos;

    Reservacion** historico;
    int cantidadHistorico;

public:
    Sistema();
    ~Sistema();

    void cargarDatos();
    void cargarHuespedes(const char* nombreArchivo);
    // futuras: cargarAnfitriones, cargarAlojamientos, etc.
};

#endif // SISTEMA_H
