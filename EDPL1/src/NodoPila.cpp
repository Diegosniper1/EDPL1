#include "NodoPila.h"
#include "Pasajero.h"

NodoPila::NodoPila(){

    pasajero=NULL; // Cambiar
    siguiente=NULL

    //ctor
}

NodoPila::NodoPila(Pasajero p, NodoPila *sig){

    pasajero=p; // Cambiar
    siguiente=sig;

    //ctor
}

NodoPila::~NodoPila()
{
    //dtor
}
