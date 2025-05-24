#ifndef RESERVACION_H
#define RESERVACION_H

class Alojamiento;
#include "huesped.h"

class Reservacion {
private:
    char* codigo;
    int fechaInicio;  // formato AAAAMMDD
    int duracion;
    char* metodoPago;
    int fechaPago;
    float monto;
    char* anotacion;
    Huesped* huesped;
    Alojamiento* alojamiento;

public:
    Reservacion(const char* cod, int fechaInicio, int duracion, const char* metodoPago, int fechaPago, float monto, const char* anotacion, Huesped* h, Alojamiento* a);
    ~Reservacion();
    //metodos necesarios para guardar
    const char* getCodigo() const;
    int getFechaInicio() const;
    int getDuracion() const;
    const char* getMetodoPago() const;
    int getFechaPago() const;
    float getMonto() const;
    const char* getAnotacion() const;
    Huesped* getHuesped() const;
    Alojamiento* getAlojamiento() const;
    bool esAnteriorA(int fechaCorte) const;

};

#endif // RESERVACION_H
