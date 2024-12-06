#include "ListaPasajeros.h"
#include "Pasajero.h"

ListaPasajeros::ListaPasajeros()
{

    primero = nullptr;
    ultimo = nullptr;
    longitud = 0;
    //ctor

}

ListaPasajeros::~ListaPasajeros()
{
     NodoListaPasajeros* actual = primero;
        while (actual != nullptr) {
            NodoListaPasajeros* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
}

NodoListaPasajeros* ListaPasajeros::getPrimero()
{
    return primero;
}

NodoListaPasajeros* ListaPasajeros::getUltimo()
{
    return ultimo;
}

int ListaPasajeros::getLongitud()
{
    return longitud;
}

void ListaPasajeros::insertarPasajero(Pasajero p)
{
    NodoListaPasajeros* aux = primero;
    NodoListaPasajeros* nuevoNodo;
    nuevoNodo->pasajero = p;
    while ( aux != nullptr)
    {
        aux = aux->siguiente;
    }
    aux->siguiente = nuevoNodo;
}

