#include "Cola.h"
#include"NodoCola.h"
#include "Pasajero.h"
#include <iostream>

using namespace std;


Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}
Cola::~Cola() { }

void Cola::encolar(Pasajero pas)
{
    NodoCola *nuevo_nodo = new NodoCola(pas);  // Crear nuevo nodo con el pasajero

    if (es_vacia()) {  // Si la cola está vacía
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    else {
        NodoCola *aux = primero;
        NodoCola *anterior = NULL;;

        while (aux != nullptr && aux->pasajero.prioridad >= nuevo_nodo->pasajero.prioridad) {
            anterior = aux;
            aux = aux->siguiente;
        }

        if (anterior == nullptr) {
            nuevo_nodo->siguiente = primero;
            primero = nuevo_nodo;
        } else {
            nuevo_nodo->siguiente = anterior->siguiente;
            anterior->siguiente = nuevo_nodo;
        }

        if (nuevo_nodo->siguiente == nullptr) {
            ultimo = nuevo_nodo;
        }
    }

    longitud++;
}






/////////
Pasajero Cola::desencolar()
{
    if(!es_vacia())
    {
        Pasajero pasajero = primero->pasajero;
        NodoCola *aux = primero;
        if((primero == ultimo) && (primero->siguiente == NULL))
        {
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);
        }
        else
        {
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete(aux);
        }
    longitud--;
    return pasajero;
    }
}




void Cola::mostrar()
{

    if (es_vacia()) {
        cout << "La cola está vacía." << endl;
        return;
    }


    NodoCola* aux = primero;
    int contador = 1;

    // Recorrido de la cola
    while (aux != nullptr) {
        cout << "Pasajero: " << contador << endl;
        cout << "ID: " << aux->.getPasajero().getId() << endl;
        cout << "Prioridad: " << aux->.getPasajero().getPrioridad() << endl;
        aux = aux->.getSiguiente();
        contador++;
    }
}





Pasajero Cola::inicio(){
    if(!es_vacia())
    {
    return primero->pasajero;
}

}



Pasajero Cola::fin()
{
    if(!es_vacia())
    {
    return ultimo->pasajero;
    }
}

bool Cola::es_vacia()
{
    return ((primero == NULL) && (ultimo == NULL));
}


int Cola::get_longitud()
{
    return longitud;
}


























