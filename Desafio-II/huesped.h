#ifndef HUESPED_H
#define HUESPED_H

#include "usuario.h"

class Huesped : public Usuario {
public:
    Huesped(const char* doc, int antig, float punt);
    const char* getDocumento() const override;
    void mostrarMenu() override; // pendiente de implementar
};

#endif // HUESPED_H
