#include "NodoCola.h"

NodoCola::NodoCola(){

    pasajero=NULL;
    siguiente=NULL;
}


NodoCola::NodoCola(Pasajero p, NodoCola *sig){
    pasajero = p;
    siguiente = NULL;
    prioridad = p.prioridad;


}



NodoCola::~NodoCola()
{
    //dtor
}




