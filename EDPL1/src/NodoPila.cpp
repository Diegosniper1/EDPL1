#include "NodoPila.h"
#include "Pasajero.h"

NodoPila::NodoPila(){

    pasajero=NULL;
    siguiente=NULL;

    //ctor
;}

NodoPila::NodoPila(Pasajero p, NodoPila *sig){

    pasajero=p;
    siguiente=sig;

    //ctor
}

NodoPila::~NodoPila()
{
    //dtor
}
