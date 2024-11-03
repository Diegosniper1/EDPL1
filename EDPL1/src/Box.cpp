#include "Box.h"
#include "Pasajero.h"
#include "Cola.h"

Box::Box() {
    id_box = 0;
    ocupado = false;
    cola = NULL;
}

Box::Box(int id_box, bool ocupado) {
    this->id_box = id_box;
    this->ocupado = ocupado;
    this->cola = NULL;
}



Box::~Box() {
}

Pasajero& Box::getPasajero() {
    return pasajero;
}

void Box::setPasajero(Pasajero& pasajero) {
    this->pasajero = pasajero;
    ocupado = true;
}

int Box::getIdBox() {
    return id_box;
}

bool Box::esVacio() {
    return !ocupado;
}

void Box::limpiarPasajero() {
    ocupado = false;
    pasajero = Pasajero();
}

int Box::setIdBox(int idBox) {
    this->id_box = idBox;
    return id_box;
}

int Box::getTotalPasajeros(){
    int total = 0;
    if (!this->esVacio()) {
        total++;
    }

    total += this->getCola().get_longitud();

    return total;
}

Cola Box::getCola() {
    return cola;
}
