#include "anfitrion.h"
#include "reservacion.h"
#include "alojamiento.h"
#include "huesped.h"
#include <cstring>
#include <iostream>

Anfitrion::Anfitrion(const char* doc, const char* nom, int antig, float punt) {
    documento = new char[strlen(doc) + 1];
    strcpy(documento, doc);

    nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);

    antiguedad = antig;
    puntuacion = punt;

    alojamientos = nullptr;
    cantidadAlojamientos = 0;
}

const char* Anfitrion::getDocumento() const {
    return documento;
}

void Anfitrion::mostrarMenu() {
    int opcion;
    do {
        std::cout << "\n===== MENU DE ANFITRION =====\n";
        std::cout << "1. Ver mis alojamientos \n";
        std::cout << "2. Ver reservaciones \n";
        std::cout << "3. Anular reservacion\n";  // ✅ opción funcional
        std::cout << "4. Cerrar sesion\n";
        std::cout << "==============================\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;
        std::cin.ignore(); // limpiar salto de línea

        switch (opcion) {
        case 1:
            std::cout << "[Ver alojamientos - aun no implementado]\n";
            break;

        case 2:
            std::cout << "[Ver reservaciones - aun no implementado]\n";
            break;

        case 3: {
            char codigo[20];
            std::cout << "Ingrese el codigo de la reservacion a anular: ";
            std::cin.getline(codigo, 20);
            if (!anularReservacionComoAnfitrion(codigo)) {
                std::cout << "No se pudo anular la reservacion.\n";
            }
            break;
        }

        case 4:
            std::cout << "Cerrando sesion de anfitrion...\n";
            break;

        default:
            std::cout << "Opcion no valida. Intente nuevamente.\n";
        }

    } while (opcion != 4);
}

int Anfitrion::getCantidadAlojamientos() const {
    return cantidadAlojamientos;
}

Alojamiento* Anfitrion::getAlojamiento(int index) const {
    if (index < 0 || index >= cantidadAlojamientos) return nullptr;
    return alojamientos[index];
}

void Anfitrion::agregarAlojamiento(Alojamiento* a) {
    Alojamiento** nuevo = new Alojamiento*[cantidadAlojamientos + 1];
    for (int i = 0; i < cantidadAlojamientos; i++) {
        nuevo[i] = alojamientos[i];
    }
    nuevo[cantidadAlojamientos] = a;
    delete[] alojamientos;
    alojamientos = nuevo;
    cantidadAlojamientos++;
}



bool Anfitrion::anularReservacionComoAnfitrion(const char* codigo) {
    // Recorremos los alojamientos del anfitrión
    for (int i = 0; i < getCantidadAlojamientos(); i++) {
        Alojamiento* a = getAlojamiento(i);
        if (!a) continue;

        // Buscar la reserva dentro del alojamiento
        Reservacion** reservas = a->getReservas();
        int n = a->getCantidadReservas();
        for (int j = 0; j < n; j++) {
            if (strcmp(reservas[j]->getCodigo(), codigo) == 0) {
                Huesped* h = reservas[j]->getHuesped();

                // Primero eliminar del huésped
                h->eliminarReservacionPorCodigo(codigo);

                // Luego eliminar del alojamiento
                a->eliminarReservacionPorCodigo(codigo);

                // Eliminar objeto
                delete reservas[j];

                std::cout << "Reservacion anulada correctamente por el anfitrion.\n";
                return true;
            }
        }
    }

    std::cout << "No se encontro una reservacion con ese codigo entre sus alojamientos.\n";
    return false;
}
