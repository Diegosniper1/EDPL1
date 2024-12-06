#ifndef NODOLISTAPASAJEROS_H
#define NODOLISTAPASAJEROS_H
#include "Pasajero.h"

class NodoListaPasajeros
{
    public:
        NodoListaPasajeros();
        NodoListaPasajeros(Pasajero p);
        virtual ~NodoListaPasajeros();
        NodoListaPasajeros* getSiguiente();
        NodoListaPasajeros* getAnterior();
        Pasajero& getPasajero();


    protected:

    private:
        NodoListaPasajeros *siguiente;
        NodoListaPasajeros *anterior;
        Pasajero pasajero;
        friend class ListaPasajeros;
};

#endif // NODOLISTAPASAJEROS_H
