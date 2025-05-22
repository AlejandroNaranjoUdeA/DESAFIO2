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
    void cargarAnfitriones(const char* nombreArchivoAnfitriones);
    void cargarAlojamineto(const char* nombreArchivoAlojamiento);
    void cargarReservaciones(const char* nombreArchivoReservaciones);
    void guardarHistorico(const char* nombreArchivoHistorial);

    Usuario* login(const char* documentoBuscado);

    void buscarAlojamientosDisponibles(int fechaInicio, int duracion, const char* municipio, float precioMax = -1, float puntuacionMin = -1);
    void reservarAlojamiento(Huesped *h);

};

#endif // SISTEMA_H
