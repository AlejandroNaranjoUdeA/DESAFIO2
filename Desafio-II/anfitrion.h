#ifndef ANFITRION_H
#define ANFITRION_H

class Sistema;

class Alojamiento;
#include "usuario.h"

class Anfitrion : public Usuario {

private:
    Alojamiento** alojamientos;
    int cantidadAlojamientos;

    Sistema* sistema;


public:
    Anfitrion(const char* doc, const char* nom, int antig, float punt);
    const char* getDocumento() const override; //se usa el override para verificar que sea una funcion virtual de la clase base, en este caso, usuario
    void mostrarMenu() override; // pendiente de implementar

    void setSistema(Sistema* s);

    bool anularReservacionComoAnfitrion(const char* codigo);

    int getCantidadAlojamientos() const;
    Alojamiento* getAlojamiento(int index) const;
    void agregarAlojamiento(Alojamiento* a); // para registrar uno nuevo

    void consultarReservacionesPorRango(int desde, int hasta) const;


};

#endif// ANFITRION_H
