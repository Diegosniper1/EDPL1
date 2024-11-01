#include "Box.h"
#include "Pasajero.h"

Box::Box()
{
    //ctor
}

Box::Box(int id_box, bool ocupado)
{
    this->id_box = id_box;
    this ->ocupado = false;

    //ctor
}

Box::~Box()
{
    //dtor
}

Pasajero Box::getPasajero(){
    this->pasajero = pasajero;
    return pasajero;
}

void Box::setPasajero(Pasajero p) {
    pasajero = p;
    ocupado = true;
}

int Box::getIdBox(){
    return id_box;
}

bool Box::esVacio(){

    return !ocupado;
}
