#include "Box.h"
#include "Pasajero.h"

Box::Box()
{
    //ctor
}

Box::Box(int id_box)
{
    this->id_box = id_box;

    //ctor
}

Box::~Box()
{
    //dtor
}

Pasajero Box::getPasajero(){
    this->pasajero = pasajero;
}

int Box::getIdBox(){
    this->id_box = id_box;
}
