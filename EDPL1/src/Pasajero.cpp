#include "Pasajero.h"
#include <iostream>
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
    return hora_inicio;
}

int Pasajero::getId(){
    return id;
}

int Pasajero::getDuracion(){
    return duracion;
}

int Pasajero::getPrioridad(){
    return prioridad;
}

int Pasajero::disminuirDuracion(){
    return duracion;
}

std::ostream& operator<<(std::ostream& os, const Pasajero& p) {
    os << "Id: " << p.id << ", Prioridad: " << p.prioridad << ", Destino: " << p.destino;  // Ejemplo de salida
    return os;
}

