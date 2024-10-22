#include "Cola.h"
#include"NodoCola.h"


Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}
Cola::~Cola() { }


void Cola::encolar(Pasajero pas)
{
    NodoCola *nuevo_nodo = new NodoCola(pas);
    if(es_vacia())
    {
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    else
    {
        ultimo->siguiente = nuevo_nodo;
        ultimo = nuevo_nodo;
    }
    longitud++;
}


Pasajero Cola::desencolar()
{
    if(!es_vacia())
    {
        Pasajero pas = primero->pas;
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
    return pas;
    }
}




void Cola::mostrar()
{

    if (es_vacia()) {
        cout << "La cola est� vac�a." << endl;
        return;
    }


    NodoCola* aux = primero;
    int contador = 1;

    // Recorrido de la cola
    while (aux != nullptr) {
        cout << "Pasajero " << contador << ":" << endl;
        cout << "ID: " << aux->pasajero.id << endl;
        cout << "Prioridad: " << aux->pasajero.prioridad << endl;
        aux = aux->siguiente;
        contador++;
    }
}





Pasajero Cola::inicio(){
    if(!es_vacia())
    {
    return primero->elemento;
}

}



Pasajero Cola::fin()
{
    if(!es_vacia())
    {
    return ultimo->elemento;
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


























