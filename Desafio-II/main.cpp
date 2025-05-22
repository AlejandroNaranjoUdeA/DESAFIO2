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

    // Prueba directa: búsqueda de alojamientos disponibles
    sistema.buscarAlojamientosDisponibles(20250601, 3, "Medellin", 150000, 4.5); //prueba

    //iniciar sesion:
    char documento[20];
    cout << "Ingrese su documento para iniciar sesion: ";
    cin.getline(documento, 20);

    Usuario* usuario = sistema.login(documento);
    if (usuario) {
        Huesped* h = dynamic_cast<Huesped*>(usuario);
        if (h) h->setSistema(&sistema);  // 👈 importante
        cout << "Inicio de sesion exitoso.\n";
        usuario->mostrarMenu(); // función virtual, muestra menú según tipo
    } else {
        cout << "Documento no encontrado. Acceso denegado.\n";
    }



    return 0;
}
