#ifndef NODOPILA_H
#define NODOPILA_H
#include <iostream>
#include "Pasajero.h"


class NodoPila{

    public:
        NodoPila();
        NodoPila(Pasajero pasajero, NodoPila *sig = NULL);
        virtual ~NodoPila();
        Pasajero getPasajero();

    private:
        Pasajero pasajero;
        NodoPila *siguiente;
        friend class Pila;

};

// Puntero tipo NodoPila

typedef NodoPila *pnodo;

#endif // NODOPILA_H
