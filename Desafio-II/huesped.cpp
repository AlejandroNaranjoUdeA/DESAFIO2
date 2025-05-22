#include "sistema.h"
#include "huesped.h"
#include <cstring>
#include <iostream>

Huesped::Huesped(const char* doc, int antig, float punt) {
    documento = new char[strlen(doc) + 1];
    strcpy(documento, doc);
    antiguedad = antig;
    puntuacion = punt;

    reservas= nullptr;
    cantidadReservas=0;
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
