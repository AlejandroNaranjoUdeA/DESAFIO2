#include "sistema.h"
#include "huesped.h"
#include <cstring>
#include <iostream>

Huesped::Huesped(const char* doc, const char* nom, int antig, float punt) {
    documento = new char[strlen(doc) + 1];
    strcpy(documento, doc);

    nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);

    antiguedad = antig;
    puntuacion = punt;

    reservas = nullptr;
    cantidadReservas = 0;
}

Huesped::~Huesped(){
    if (documento) delete[] documento;

    for (int i = 0; i < cantidadReservas; i++) {
        delete[] reservas[i];
    }
    delete[] reservas;
}

const char* Huesped::getDocumento() const {
    return documento;
}

void Huesped::setSistema(Sistema* s) {
    sistema = s;
}

void Huesped::mostrarMenu() {
    std::cout << "\n===== MENU DE HUESPED =====\n";
    std::cout << "1. Ver alojamientos disponibles\n";
    std::cout << "2. Reservar alojamiento\n";
    std::cout << "3. Anular reservacion\n";
    std::cout << "4. Cerrar sesion\n";
    std::cout << "============================\n";

    int opcion;
    std::cout << "Opcion: ";
    std::cin >> opcion;
    std::cin.ignore();

    switch (opcion){
        case 1:{
            int fecha, dias;
            char municipio[50];
            float precioMax, puntMin;

            std::cout << "Fecha inicio (AAAAMMDD): ";
            std::cin >> fecha;
            std::cout << "Cantidad de noches: ";
            std::cin >> dias;
            std::cin.ignore();
            std::cout << "Municipio: ";
            std::cin.getline(municipio, 50);

            std::cout << "Precio maximo por noche (-1 si no aplica): ";
            std::cin >> precioMax;
            std::cout << "Puntuacion minima del anfitrion (-1 si no aplica): ";
            std::cin >> puntMin;

            sistema->buscarAlojamientosDisponibles(fecha, dias, municipio, precioMax, puntMin);
            break;
        }
        case 2:{
            sistema->reservarAlojamiento(this);
            break;
        }
        case 3:{
            char codigo[20];
            std::cout << "Ingrese el codigo de la reservacion a anular: ";
            std::cin.ignore(); // limpiar si hace falta
            std::cin.getline(codigo, 20);

            if (eliminarReservacionPorCodigo(codigo)) {
                std::cout << "Reservacion anulada correctamente.\n";
            } else {
                std::cout << "No se pudo anular la reservacion.\n";
            }
            break;
        }
        case 4:{
            std::cout<<"\nSaliendo del menu de huesped "<<std::endl;
        }
        default:
            std::cout<<"\nOpcion invlida"<<std::endl;
    }
}

void Huesped::agregarReservacion(Reservacion *r){
    //reservamos memoria dinamica:
    Reservacion** nuevo = new Reservacion*[cantidadReservas + 1];
    for (int i = 0; i < cantidadReservas; i++) {
        nuevo[i] = reservas[i];
    }
    nuevo[cantidadReservas] = r;
    delete[] reservas;
    reservas = nuevo;
    cantidadReservas++;
}

int Huesped::getCantidadReservas() {
    return cantidadReservas;
}

Reservacion** Huesped::getReservas() {
    return reservas;
}

bool Huesped::eliminarReservacionPorCodigo(const char* codigo) {
    int pos = -1;
    for (int i = 0; i < cantidadReservas; i++) {
        if (strcmp(reservas[i]->getCodigo(), codigo) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        std::cout << "Reservación no encontrada.\n";
        return false;
    }

    // Eliminar también del alojamiento asociado
    Alojamiento* a = reservas[pos]->getAlojamiento();
    a->eliminarReservacionPorCodigo(codigo);

    delete reservas[pos];

    for (int i = pos; i < cantidadReservas - 1; i++) {
        reservas[i] = reservas[i + 1];
    }

    cantidadReservas--;

    return true;
}

