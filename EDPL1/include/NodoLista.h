#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Box.h"

class NodoLista
{
    public:
        NodoLista();
        NodoLista(Pasajero pasajero, NodoLista *sig = NULL, NodoLista *ant = NULL);
        virtual ~NodoLista();
        Box getBox();
        NodoLista* getSiguiente();
        NodoLista* getAnterior();



    protected:

    private:
        NodoLista *siguiente;
        NodoLista *anterior;
        Box box;
};

#endif // NODOLISTA_H
