#ifndef RESERVACION_H
#define RESERVACION_H

#include "huesped.h"
#include "alojamiento.h"

class Reservacion {
private:
    char* codigo;
    int fechaInicio; // formato AAAAMMDD
    int duracion;
    float monto;
    char* anotacion;
    Huesped* huesped;
    Alojamiento* alojamiento;

public:
    Reservacion(const char* cod, int fecha, int dur, float m, const char* nota, Huesped* h, Alojamiento* a);
    ~Reservacion();
    const char* getCodigo() const;
};

#endif // RESERVACION_H
