#include "reservacion.h"
#include <cstring>

Reservacion::Reservacion(const char* cod, int fecha, int dur, const char* metodo,int fPago, float m, const char* nota, Huesped* h, Alojamiento* a){
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);

    fechaInicio = fecha;
    duracion = dur;

    metodoPago = new char[strlen(metodo) + 1];
    strcpy(metodoPago, metodo);

    fechaPago = fPago;
    monto = m;

    anotacion = new char[strlen(nota) + 1];
    strcpy(anotacion, nota);

    huesped = h;
    alojamiento = a;
}

Reservacion::~Reservacion() {
    delete[] codigo;
    delete[] metodoPago;
    delete[] anotacion;
}

// Getters
const char* Reservacion::getCodigo() const { return codigo; }
int Reservacion::getFechaInicio() const { return fechaInicio; }
int Reservacion::getDuracion() const { return duracion; }
const char* Reservacion::getMetodoPago() const { return metodoPago; }
int Reservacion::getFechaPago() const { return fechaPago; }
float Reservacion::getMonto() const { return monto; }
const char* Reservacion::getAnotacion() const { return anotacion; }
Huesped* Reservacion::getHuesped() const { return huesped; }
Alojamiento* Reservacion::getAlojamiento() const { return alojamiento; }
