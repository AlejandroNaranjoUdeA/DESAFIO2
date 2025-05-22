#ifndef HUESPED_H
#define HUESPED_H

class Sistema;

#include "usuario.h"

class Huesped : public Usuario {

private:
    Sistema* sistema;

public:
    Huesped(const char* doc, int antig, float punt);
    const char* getDocumento() const override;
    void setSistema(Sistema* s);  // método para inyectar el sistema
    void mostrarMenu() override; // pendiente de implementar
};

#endif // HUESPED_H
