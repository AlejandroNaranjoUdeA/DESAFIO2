#ifndef ANFITRION_H
#define ANFITRION_H

#include "usuario.h"

class Anfitrion : public Usuario {
public:
    Anfitrion(const char* doc, int antig, float punt);
    const char* getDocumento() const override; //se usa el override para verificar que sea una funcion virtual de la clase base, en este caso, usuario
    void mostrarMenu() override; // pendiente de implementar
};

#endif// ANFITRION_H
