#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Box.h"

class NodoLista
{
    public:
        NodoLista();
        virtual ~NodoLista();

    protected:

    private:
        NodoLista *siguiente;
        NodoLista *anterior;
        Box box;
};

#endif // NODOLISTA_H
