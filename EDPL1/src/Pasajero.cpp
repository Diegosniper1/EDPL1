#include "Pasajero.h"

Pasajero::Pasajero()
{
    //ctor
}

Pasajero::Pasajero(int id, int prioridad, string destino, int hora_inicio, int duracion)
{
    this->id = id;
    this->prioridad = prioridad;
    this->destino = destino;
    this->hora_inicio = hora_inicio;
    this->duracion = duracion;
}

Pasajero::~Pasajero()
{
    //dtor
}


Pasajero::getPrioridad(){

    return prioridad;
}
