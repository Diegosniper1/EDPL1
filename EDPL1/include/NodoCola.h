#ifndef NODOCOLA_H
#define NODOCOLA_H
#include"Pasajero.h"

class NodoCola
{


    public:
        NodoCola();
        virtual ~NodoCola();
        NodoCola(Pasajero pasajero, NodoCola*sig = NULL);
        Pasajero getPasajero();
        NodoCola* getSiguiente();

    protected:

    private:
        NodoCola *siguiente;
        Pasajero pasajero;
        friend class Cola;




};

#endif // NODOCOLA_H








