#include "Pasajero.h"
#include <iostream>
#include <string>

using namespace std;

Pasajero::Pasajero()
{
    this->id = -1;
    this->duracion = 0;
    this->hora_inicio = 0;
    this->prioridad = 0;
}

Pasajero::Pasajero(int id, int prioridad, string destino, int hora_inicio, int duracion)
{
    this->id = id;
    this->prioridad = prioridad;
    this->destino = destino;
    this->hora_inicio = hora_inicio;
    this->duracion = duracion;
    this->tiempoEstancia = 0;
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

string Pasajero::getDestino(){
    return destino;
}

int Pasajero::disminuirDuracion(){
    if (duracion > 0) {
        duracion--;
    }
    return duracion;
}

int Pasajero::getTiempoEstancia(){
    return tiempoEstancia;
}

std::ostream& operator<<(std::ostream& os, const Pasajero& p) {
    os << "Id: " << p.id << ", Prioridad: " << p.prioridad << ", Destino: " << p.destino;
    return os;
}

