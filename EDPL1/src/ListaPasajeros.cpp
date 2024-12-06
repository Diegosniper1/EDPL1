#include "ListaPasajeros.h"

ListaPasajeros::ListaPasajeros()
{

    primero = nullptr;
    ultimo = nullptr;
    longitud = 0;
    //ctor

}

ListaPasajeros::~ListaPasajeros()
{
     while(primero != nullptr) {
        NodoPasajero* aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
}
