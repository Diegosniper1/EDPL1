#include "Box.h"
#include "Pasajero.h"


Box::Box()
{
    //ctor
}

Box::Box(int id_box)
{
    this->id_box = id_box;
    this->pasajero = NULL;
    //ctor
}

Box::~Box()
{
    //dtor
}
