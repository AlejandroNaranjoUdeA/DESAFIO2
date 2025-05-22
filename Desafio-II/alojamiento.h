#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include "anfitrion.h"
#include "reservacion.h"

class Alojamiento {
private:
    char* codigo;
    char* direccion;
    char* municipio;
    char tipo; // 'C' o 'A'
    float precioPorNoche;
    Anfitrion* anfitrion; // asociacion simple
    Reservacion** reservas;
    int cantidadReservas;

public:
    Alojamiento(const char* cod, const char* dir, const char* mun, char t, float precio, Anfitrion* a);
    ~Alojamiento();
    const char* getCodigo() const;
    const char* getMunicipio() const;
    float getPrecioPorNoche() const;
    Anfitrion* getAnfitrion() const;
    int getCantidadReservas() const;
    Reservacion** getReservas() const;
    const char* getDireccion() const;

    void agregarReservacion(Reservacion* r);

};

#endif // ALOJAMIENTO_H
