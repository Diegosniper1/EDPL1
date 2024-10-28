#include "NodoCola.h"
#include "Pasajero.h"

NodoCola::NodoCola(){

    siguiente=NULL;
}


NodoCola::NodoCola(Pasajero p, NodoCola *sig){
    pasajero = p;
    siguiente = sig;
    int prioridad = p.getPrioridad;


}



NodoCola::~NodoCola()
{
    //dtor
}




