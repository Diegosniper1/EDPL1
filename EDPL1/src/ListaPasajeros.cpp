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
    NodoListaPasajeros* nuevoNodo = new NodoListaPasajeros(p);

    if (primero == nullptr) {
        // Lista vacía
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    } else {
        // Insertar al final
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;
        ultimo = nuevoNodo;
    }
    longitud++;
}

