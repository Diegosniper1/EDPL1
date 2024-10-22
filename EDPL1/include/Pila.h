#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"

class Pila
{
    public:
        Pila();
        virtual ~Pila();
        bool esVacia();
        void apilar(Pasajero pas);
        void desapilar();
        int mostrar();
        void mostrar_entera();
        void ordenar_pila();
    private:
        pnodo cima;



};

#endif // PILA_H
