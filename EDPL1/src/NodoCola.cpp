#include "NodoCola.h"

NodoCola::NodoCola(){


    siguiente=NULL;
    prioridad = 0;
}


NodoCola::NodoCola(Pasajero p, NodoCola *sig){
    pasajero = p;
    siguiente = sig;
    prioridad = p.getPrioridad;


}



NodoCola::~NodoCola()
{
    //dtor
}




