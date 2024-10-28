#include "NodoCola.h"
#include "Pasajero.h"

NodoCola::NodoCola(){

    siguiente=NULL;
}


NodoCola::NodoCola(Pasajero p, NodoCola *sig){
    pasajero = p;
    siguiente = sig;



}



NodoCola::~NodoCola()
{
    //dtor
}




