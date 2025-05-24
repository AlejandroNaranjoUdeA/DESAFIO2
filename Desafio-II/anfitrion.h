#ifndef ANFITRION_H
#define ANFITRION_H

class Alojamiento;
#include "usuario.h"

class Anfitrion : public Usuario {

private:
    Alojamiento** alojamientos;
    int cantidadAlojamientos;

public:
    Anfitrion(const char* doc, const char* nom, int antig, float punt);
    const char* getDocumento() const override; //se usa el override para verificar que sea una funcion virtual de la clase base, en este caso, usuario
    void mostrarMenu() override; // pendiente de implementar

    bool anularReservacionComoAnfitrion(const char* codigo);

    int getCantidadAlojamientos() const;
    Alojamiento* getAlojamiento(int index) const;
    void agregarAlojamiento(Alojamiento* a); // para registrar uno nuevo


};

#endif// ANFITRION_H
