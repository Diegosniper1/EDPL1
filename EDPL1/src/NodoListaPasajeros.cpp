#include "NodoListaPasajeros.h"

NodoListaPasajeros::NodoListaPasajeros() {
    pasajero = NULL;
    siguiente = nullptr;
    anterior = nullptr;
}

NodoListaPasajeros::NodoListaPasajeros(Pasajero p) {
    pasajero = p;
    siguiente = nullptr;
    anterior = nullptr;
}

NodoListaPasajeros::~NodoListaPasajeros()
{
    //dtor
}

NodoListaPasajeros* NodoListaPasajeros::getSiguiente()
{
    return siguiente;
}

NodoListaPasajeros* NodoListaPasajeros::getSiguiente()
{
    return anterior;
}

Pasajero& NodoListaPasajeros::getPasajero()
{
    return pasajero;
}


