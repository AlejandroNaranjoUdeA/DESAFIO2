#ifndef USUARIO_H
#define USUARIO_H

class Usuario {
protected:
    char* documento;
    int antiguedad;
    float puntuacion;

public:
    Usuario(); // constructor por defecto
    virtual ~Usuario(); // destructor virtual
    virtual const char* getDocumento() const = 0; // método puro // se usa virtual para poder usar el polimorfismo dinamico, es decir, cuando se usan punteros y demas
    virtual void mostrarMenu() = 0;
};

#endif // USUARIO_H
