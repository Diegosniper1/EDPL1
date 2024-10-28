#ifndef COLA_H
#define COLA_H
#include"Pasajero.h"
#include "NodoCola.h"

class Cola
{
    public:
        Cola();
        ~Cola();
        void encolar(Pasajero pasajero);
        Pasajero desencolar();
        void mostrar();
        Pasajero inicio();
        Pasajero fin();

        bool es_vacia();
        int get_longitud();

    private:
        NodoCola * primero;
        NodoCola * ultimo;
        int longitud;
        friend class Aeropuerto;
};

#endif // COLA_H
