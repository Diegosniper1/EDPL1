#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"
#include"Pasajero.h"

class Pila
{
    public:
        Pila();
        virtual ~Pila();
        bool esVacia();
        void apilar(Pasajero pas);
        void apilar_por_orden(Pasajero pas);
        void desapilar();
        Pasajero mostrar();
        void mostrar_entera();
        void ordenar_pila();
    private:
        pnodo cima;
        friend class Aeropuerto;



};

#endif // PILA_H
