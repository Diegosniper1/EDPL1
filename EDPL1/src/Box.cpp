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
    return pasajero;
}

int Box::getIdBox(){
    return id_box;
}

bool Box::esVacio(){
    if (this->pasajero.getId() == NULL){
        return true;
    }
    return false;
}
