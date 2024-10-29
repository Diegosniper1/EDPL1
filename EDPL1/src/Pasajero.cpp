#include "Pasajero.h"

#include <string>

using namespace std;

Pasajero::Pasajero()
{
    this->id = -1;
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

int Pasajero::getHoraInicio(){
    this->hora_inicio = hora_inicio;
    return hora_inicio;
}

int Pasajero::getId(){
    this->id = id;
    return id;
}

int Pasajero::getDuracion(){
    this->duracion = duracion;
    return duracion;
}

int Pasajero::disminuirDuracion(){
    this->duracion = duracion--;
    return duracion;
}

