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


void Sistema::cargarHuespedes(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cout << "Error al abrir el archivo de huespedes: " << nombreArchivo << endl;
        return;
    }

    char linea[100];
    while (archivo.getline(linea, 100)) {
        // Parsear la línea

        //sacamos el documento
        char* token = strtok(linea, ",");  //se usa strtok para separ en partes usando un separador, en este caso la coma
        if (!token) continue; //continue permite que si hay errores salte a la siguiente linea de codigo
        char* documento = new char[strlen(token) + 1];
        strcpy(documento, token);

        //sacamos la antiguedad
        token = strtok(NULL, ",");
        if (!token) continue;
        int antiguedad = atoi(token);

        //sacamos la puntuacion
        token = strtok(NULL, ",");
        if (!token) continue;
        float puntuacion = atof(token);

        // Crear el Huesped y agregar al arreglo
        Huesped* nuevo = new Huesped(documento, antiguedad, puntuacion);

        // Redimensionar arreglo huespedes
        Huesped** nuevoArreglo = new Huesped*[cantidadHuespedes + 1];
        for (int i = 0; i < cantidadHuespedes; i++) {
            nuevoArreglo[i] = huespedes[i];
        }
        nuevoArreglo[cantidadHuespedes] = nuevo;

        delete[] huespedes;
        huespedes = nuevoArreglo;
        cantidadHuespedes++;

        delete[] documento; // ya fue copiado internamente por Huesped
    }

    archivo.close();
}
