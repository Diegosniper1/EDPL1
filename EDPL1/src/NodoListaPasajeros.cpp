#include "NodoListaPasajeros.h"

NodoListaPasajeros::NodoListaPasajeros() {
    tiempoEstancia = 0;
    siguiente = nullptr;
    anterior = nullptr;
}

NodoListaPasajeros::NodoListaPasajeros(Pasajero p, int tiempo) {
    pasajero = p;
    tiempoEstancia = tiempo;
    siguiente = nullptr;
    anterior = nullptr;
}

NodoListaPasajeros::~NodoListaPasajeros()
{
    //dtor
}
