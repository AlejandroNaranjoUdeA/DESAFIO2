#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include "anfitrion.h"

class Alojamiento {
private:
    char* codigo;
    char* direccion;
    char* municipio;
    char tipo; // 'C' o 'A'
    float precioPorNoche;
    Anfitrion* anfitrion; // asociacion simple

public:
    Alojamiento(const char* cod, const char* dir, const char* mun, char t, float precio, Anfitrion* a);
    ~Alojamiento();
    const char* getCodigo() const;
};

#endif // ALOJAMIENTO_H
