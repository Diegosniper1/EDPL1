#include "NodoPila.h"
#include "Pasajero.h"

NodoPila::NodoPila(){

    siguiente=nullptr;
    //Usar nullptr es mas recomendable que NULL
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

Pasajero NodoPila::getPasajero(){
    return pasajero;
}

NodoPila* NodoPila::getSiguiente(){
    return siguiente;
}
