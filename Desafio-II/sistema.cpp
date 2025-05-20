#include "sistema.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

Sistema::Sistema() {
    huespedes = nullptr;
    cantidadHuespedes = 0;

    anfitriones = nullptr;
    cantidadAnfitriones = 0;

    alojamientos = nullptr;
    cantidadAlojamientos = 0;

    historico = nullptr;
    cantidadHistorico = 0;
}

Sistema::~Sistema() {
    // Liberar huéspedes
    for (int i = 0; i < cantidadHuespedes; i++) {
        delete huespedes[i];
    }
    delete[] huespedes;

    // Liberar anfitriones
    for (int i = 0; i < cantidadAnfitriones; i++) {
        delete anfitriones[i];
    }
    delete[] anfitriones;

    // Liberar alojamientos
    for (int i = 0; i < cantidadAlojamientos; i++) {
        delete alojamientos[i];
    }
    delete[] alojamientos;

    // Liberar histórico de reservaciones
    for (int i = 0; i < cantidadHistorico; i++) {
        delete historico[i];
    }
    delete[] historico;
}


void Sistema::cargarHuespedes(const char* nombreArchivo) { //falta cambiar por el nombre del archivo

    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error al abrir el archivo de huespedes: " << nombreArchivo << endl;
        return;
    }

    /*ejemplo de Huespedes.txt:
    documento, antiguedad, puntuacion
    1234, 12, 4.5
    */

    char linea[100];
    while (archivo.getline(linea, 100)) {
        // Obtener los tokens directamente sin new
        char* token = strtok(linea, ","); //strtok me permite sacar una linea de codigo hasta llegar a un separador, en este caso, es la coma
        if (!token) continue; //continue me permite seguir y pasar de linea en caso de error
        char* documento = token;

        token = strtok(NULL, ",");
        if (!token) continue;
        int antiguedad = atoi(token);

        token = strtok(NULL, ",");
        if (!token) continue;
        float puntuacion = atof(token);

        // Crear el Huesped (el constructor hace su propia copia del documento)
        Huesped* nuevo = new Huesped(documento, antiguedad, puntuacion);

        // Redimensionar el arreglo de huéspedes
        Huesped** nuevoArreglo = new Huesped*[cantidadHuespedes + 1];
        for (int i = 0; i < cantidadHuespedes; i++) {
            nuevoArreglo[i] = huespedes[i];
        }
        nuevoArreglo[cantidadHuespedes] = nuevo;

        delete[] huespedes; // eliminar el arreglo viejo (no los objetos)
        huespedes = nuevoArreglo;
        cantidadHuespedes++;
    }

    archivo.close();
}

void Sistema::cargarAnfitriones(const char* nombreArchivoAnfitriones){
    ifstream archivo(nombreArchivoAnfitriones);
    if (!archivo) {
        cout << "Error al abrir el archivo de anfitriones: " << nombreArchivoAnfitriones << endl;
        return;
    }

    /*ejemplo de Anfitriones.txt:
    documento, antiguedad, puntuacion
    1234, 12, 4.5
    */


}

