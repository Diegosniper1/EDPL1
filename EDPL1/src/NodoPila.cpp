#include "NodoPila.h"
#include "Pasajero.h"

NodoPila::NodoPila(){

    siguiente=NULL;
    //Pasajero = NULL; ES LO QUE ESTABA PREVIAMENTE

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
