#include "Pasajero.h"

Pasajero::Pasajero()
{
    //ctor
}

Pasajero::Pasajero(int id, int prioridad, string destino, int hora_inicio, int duracion)
{
    id = id;
    prioridad = prioridad;
    destino = destino;
    hora_inicio = hora_inicio;
    duracion = duracion;
}

Pasajero::~Pasajero()
{
    //dtor
}
