#include <iostream>
#include"sistema.h"

using namespace std;

int main()
{
    Sistema sistema;

    //cargar archivos:
    sistema.cargarHuespedes("huespedes.txt");
    sistema.cargarAnfitriones("anfitriones.txt");
    sistema.cargarReservaciones("reservaciones.txt");
    sistema.guardarHistorico("historico.txt");
    sistema.cargarAlojamineto("alojamientos.txt");

    //iniciar sesion:
    char documento[20];
    cout << "Ingrese su documento para iniciar sesion: ";
    cin.getline(documento, 20);

    Usuario* usuario = sistema.login(documento);
    if (usuario) {
        cout << "Inicio de sesion exitoso.\n";
        usuario->mostrarMenu(); // función virtual, muestra menú según tipo
    } else {
        cout << "Documento no encontrado. Acceso denegado.\n";
    }



    return 0;
}
