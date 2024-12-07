#include "ListaPasajeros.h"
#include "Pasajero.h"
#include <iostream>

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

bool ListaPasajeros::esVacia() {
    return primero == nullptr;
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

int ListaPasajeros::getTiempoMedioEstancia() {
    if (longitud == 0) return 0;

    int tiempoTotal = 0;
    NodoListaPasajeros* actual = primero;

    while (actual != nullptr) {
        tiempoTotal += actual->getPasajero().getTiempoEstancia();
        actual = actual->siguiente;
    }

    return tiempoTotal / longitud;
}

void ListaPasajeros::mostrarPasajeros() {
    NodoListaPasajeros* actual = this->getPrimero();
    while (actual != nullptr) {
        cout << "ID: " << actual->getPasajero().getId()
             << ", Tiempo estancia: " << actual->getPasajero().getTiempoEstancia()
             << " minutos" << endl;
        actual = actual->getSiguiente();
    }
}
