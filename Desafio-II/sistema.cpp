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

    /*ejemplo de Huespedes.txt:
    documento, antiguedad, puntuacion
    1234,12,4.5
    */

    char linea[100];
    while (archivo.getline(linea, 100)) {
        // Obtener los tokens directamente
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
    1003,02,3.9
    */

    char linea[100]; // pueden haber 100 caracteres
    while(archivo.getline(linea, 100)){
        //obtenemos las diferentes lineas que necesitamos:
        char* token = strtok(linea, ","); //strtok me permite sacar una linea de codigo hasta llegar a un separador, en este caso, es la coma
        if (!token) continue; //continue me permite seguir y pasar de linea en caso de error
        char* documento = token;

        token = strtok(NULL, ",");
        if (!token) continue;
        int antiguedad = atoi(token);

        token = strtok(NULL, ",");
        if (!token) continue;
        float puntuacion = atof(token);

        // Se crea el Anfitrion
        Anfitrion* copia= new Anfitrion(documento, antiguedad, puntuacion);

        Anfitrion **nCopia= new Anfitrion *[cantidadAnfitriones +1];
        for(int i=0; i<cantidadAnfitriones; i++){
            nCopia[i]= anfitriones[i];
        }
        nCopia[cantidadAnfitriones]= copia;

        delete[] anfitriones;
        anfitriones= nCopia;
        cantidadAnfitriones++;
    }

    archivo.close();
}

void Sistema::cargarAlojamineto(const char* nombreArchivoAlojamiento){
    //verifica que se abra correctamente el archivo
    ifstream archivo(nombreArchivoAlojamiento);
    if (!archivo) {
        cout << "Error al abrir el archivo de los alojamientos: " << nombreArchivoAlojamiento << endl;
        return;
    }

    /*ejemplo de Alojamiento.txt:
    codigo, direccion, municipio, tipo, precioPorNoche, DocumentoAnfitrion
    A001,Calle 10 #23-45,Medellin,C,120000,1001
    */

    char linea[200];
    while (archivo.getline(linea, 200)) {
        char* token = strtok(linea, ",");
        if (!token) continue;
        char* codigo = token;

        token = strtok(NULL, ",");
        if (!token) continue;
        char* direccion = token;

        token = strtok(NULL, ",");
        if (!token) continue;
        char* municipio = token;

        token = strtok(NULL, ",");
        if (!token) continue;
        char tipo = token[0];

        token = strtok(NULL, ",");
        if (!token) continue;
        float precio = atof(token);

        token = strtok(NULL, ",");
        if (!token) continue;
        char* docAnfitrion = token;

        // Buscar el anfitrión por documento
        Anfitrion* anfitrion = nullptr;
        for (int i = 0; i < cantidadAnfitriones; i++) {
            if (strcmp(anfitriones[i]->getDocumento(), docAnfitrion) == 0) {
                anfitrion = anfitriones[i];
                break;
            }
        }

        if (!anfitrion) {
            cout << "Anfitrión con documento " << docAnfitrion << " no encontrado. Se omite el alojamiento " << codigo << endl;
            continue;
        }

        Alojamiento* nuevo = new Alojamiento(codigo, direccion, municipio, tipo, precio, anfitrion);

        // Redimensionar arreglo de alojamientos
        Alojamiento** nuevoArreglo = new Alojamiento*[cantidadAlojamientos + 1];
        for (int i = 0; i < cantidadAlojamientos; i++) {
            nuevoArreglo[i] = alojamientos[i];
        }
        nuevoArreglo[cantidadAlojamientos] = nuevo;

        delete[] alojamientos;
        alojamientos = nuevoArreglo;
        cantidadAlojamientos++;
    }

    archivo.close();
}

void Sistema::cargarReservaciones(const char* nombreArchivoReservaciones){
    //verifica que se abra correctamente el archivo
    ifstream archivo(nombreArchivoReservaciones);
    if (!archivo) {
        cout << "Error al abrir el archivo de las reservaciones: " << nombreArchivoReservaciones << endl;
        return;
    }

    /*ejemplo de Reservaciones.txt:
    codigo,FechaInicio,duracion,metodopPago,fechaPago,monto,anotacion,documentoHuesped,codigoAlojamiento
    R001,20250520,3,Efectivo,20250519,360000,Sin observaciones,1234,A001
    R002,20250401,2,Nequi,20250331,180000,Todo bien,5678,A002
    */

    const int FECHA_HOY = 20250520; // Formato AAAAMMDD (se puede modificar)

    char linea[500];
    while (archivo.getline(linea, 500)) {  //posible desborde de memoria
        char* token = strtok(linea, ",");
        if (!token) continue;
        char* codigo = token;

        token = strtok(NULL, ",");
        if (!token) continue;
        int fechaInicio = atoi(token);

        token = strtok(NULL, ",");
        if (!token) continue;
        int duracion = atoi(token);

        token = strtok(NULL, ",");
        if (!token) continue;
        char* metodoPago = token;

        token = strtok(NULL, ",");
        if (!token) continue;
        int fechaPago = atoi(token);

        token = strtok(NULL, ",");
        if (!token) continue;
        float monto = atof(token);

        token = strtok(NULL, ",");
        if (!token) continue;
        char* anotacion = token;

        token = strtok(NULL, ",");
        if (!token) continue;
        char* docHuesped = token;

        token = strtok(NULL, ",");
        if (!token) continue;
        char* codAlojamiento = token;

        // Buscar el huésped
        Huesped* h = nullptr;
        for (int i = 0; i < cantidadHuespedes; i++) {
            if (strcmp(huespedes[i]->getDocumento(), docHuesped) == 0) {
                h = huespedes[i];
                break;
            }
        }

        // Buscar el alojamiento
        Alojamiento* a = nullptr;
        for (int i = 0; i < cantidadAlojamientos; i++) {
            if (strcmp(alojamientos[i]->getCodigo(), codAlojamiento) == 0) {
                a = alojamientos[i];
                break;
            }
        }

        if (!h || !a) {
            cout << "No se encontro huesped o alojamiento para reserva " << codigo << ". Se omite.\n";
            continue;
        }

        // Crear la reservación
        Reservacion* nueva = new Reservacion(codigo, fechaInicio, duracion,metodoPago, fechaPago, monto, anotacion, h, a);

        // Determinar si es histórica o vigente
        int fechaFin = fechaInicio + duracion;
        if (fechaFin < FECHA_HOY) {
            // Agregar al histórico
            Reservacion** nuevoHist = new Reservacion*[cantidadHistorico + 1];
            for (int i = 0; i < cantidadHistorico; i++) {
                nuevoHist[i] = historico[i];
            }
            nuevoHist[cantidadHistorico] = nueva;
            delete[] historico;
            historico = nuevoHist;
            cantidadHistorico++;
        } else {
            // Aquí más adelante poder asociarla a huésped/alojamiento si decides guardar las vigentes
            // Por ahora se ignora, pero la reservación está viva en memoria si quieres usarla más adelante
        }
    }

    archivo.close();
}

void Sistema::guardarHistorico(const char* nombreArchivoHistorial){
    ofstream archivo(nombreArchivoHistorial);
    if (!archivo) {
        std::cout << "Error al abrir archivo del historial: " << nombreArchivoHistorial << std::endl;
        return;
    }

    /*ejemplo de Historial.txt:
    codigo,FechaInicio,duracion,metodoPago,fechaPago,monto,anotacion,documentoHuesped,codigoAlojamiento
    R002,20250401,2,Nequi,20250331,180000,Todo bien,5678,A002

    */

    for (int i = 0; i < cantidadHistorico; i++) {
        Reservacion* r = historico[i];
        archivo << r->getCodigo() << ","
                << r->getFechaInicio() << ","
                << r->getDuracion() << ","
                << r->getMetodoPago() << ","
                << r->getFechaPago() << ","
                << r->getMonto() << ","
                << r->getAnotacion() << ","
                << r->getHuesped()->getDocumento() << ","
                << r->getAlojamiento()->getCodigo() << "\n";
    }

    archivo.close();
    std::cout << "Historial guardado correctamente en " << nombreArchivoHistorial << std::endl;

}

Usuario* Sistema::login(const char* documentoBuscado) {
    for (int i = 0; i < cantidadHuespedes; i++) {
        if (strcmp(huespedes[i]->getDocumento(), documentoBuscado) == 0) {
            return huespedes[i];
        }
    }

    for (int i = 0; i < cantidadAnfitriones; i++) {
        if (strcmp(anfitriones[i]->getDocumento(), documentoBuscado) == 0) {
            return anfitriones[i];
        }
    }

    return nullptr;
}

//funcion para buscar los alojamientos:
void Sistema::buscarAlojamientosDisponibles(int fechaInicio, int duracion, const char* municipio, float precioMax, float puntuacionMin){
    std::cout<<"\nBuscando alojamientos disponibles en: "<<municipio<<std::endl;

    unsigned int encontrados=0;

    for(int i=0; i<cantidadAlojamientos; i++){
        Alojamiento *a= alojamientos[i];

        //filtro de municipio:
        if (strcmp(a->getMunicipio(), municipio) != 0) continue; //strcmp compara 2 cadenas de caracteres, en este caso, si no son iguales, continue

        // Filtro por precio (si aplica)
        if (precioMax != -1 && a->getPrecioPorNoche() > precioMax) continue;

        // Filtro por puntuación del anfitrión (si aplica)
        if (puntuacionMin != -1 && a->getAnfitrion()->getPuntuacion() < puntuacionMin) continue;

        // Verificar disponibilidad para la fecha y duracion
        bool disponible = true;
        for (int j = 0; j < a->getCantidadReservas(); j++) {
            Reservacion* r = a->getReservas()[j];
            int f1 = fechaInicio;
            int f2 = fechaInicio + duracion - 1;
            int r1 = r->getFechaInicio();
            int r2 = r1 + r->getDuracion() - 1;

            if (!(f2 < r1 || f1 > r2)) {
                disponible = false;
                break;
            }
        }

        if (!disponible) continue;

        // Mostrar alojamiento disponible
        std::cout << "\n[" << encontrados + 1 << "] "
                  << "Codigo: " << a->getCodigo()
                  << ", Direccion: " << a->getDireccion()
                  << ", Precio/noche: $" << a->getPrecioPorNoche()
                  << ", Puntuacion anfitrion: " << a->getAnfitrion()->getPuntuacion()
                  << std::endl;

        encontrados++;
    }

    if (encontrados == 0) {
        std::cout << "No se encontraron alojamientos disponibles con los criterios dados.\n";
    }
}


