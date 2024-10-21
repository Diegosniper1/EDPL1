#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"

class Pila
{
    public:
        Pila();
        virtual ~Pila();
        bool esVacia();
        void apilar(int v);
        void desapilar();
        int mostrar();
        void mostrar_entera();

    private:
        pnodo cima;



};

#endif // PILA_H
