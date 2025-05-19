// Huesped.h
#ifndef HUESPED_H
#define HUESPED_H

#include "usuario.h" //falta crear la clase usuario

class Huesped : public Usuario {
public:
    Huesped(const char* doc, int antig, float punt);
    const char* getDocumento() const override;
    void mostrarMenu() override; // pendiente de implementar
};

#endif
