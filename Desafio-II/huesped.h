#ifndef HUESPED_H
#define HUESPED_H

class Reservacion;
class Sistema;

#include "usuario.h"

class Huesped : public Usuario {

private:
    Sistema* sistema;
    Reservacion **reservas;
    int cantidadReservas;

public:
    Huesped(const char* doc, const char* nom, int antig, float punt);
    ~Huesped();
    const char* getDocumento() const override;
    void setSistema(Sistema* s);  // método para inyectar el sistema
    void mostrarMenu() override; //
    void agregarReservacion(Reservacion *r);
    int getCantidadReservas();
    Reservacion ** getReservas();

    bool eliminarReservacionPorCodigo(const char* codigo);


};

#endif // HUESPED_H
