#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Box.h"

class NodoLista
{
    public:
        NodoLista();
        NodoLista(Box b, NodoLista *sig = NULL, NodoLista *ant = NULL);
        virtual ~NodoLista();
        Box& getBox();
        NodoLista* getSiguiente();
        NodoLista* getAnterior();



    protected:

    private:
        NodoLista *siguiente;
        NodoLista *anterior;
        Box box;
        friend class Lista;

};

#endif // NODOLISTA_H
