#include "NodoLista.h"
#include "Box.h"


NodoLista::NodoLista()
{
    siguiente = nullptr;
    anterior = nullptr;
    box = NULL;
    //ctor
}

NodoLista::NodoLista(Box b, NodoLista *sig, NodoLista *ant)
{
    siguiente = sig;
    anterior = ant;
    box = b;
    //ctor
}

NodoLista::~NodoLista()
{
    //dtor
}

Box NodoLista::getBox(){
    return box;
}

NodoLista* NodoLista::getSiguiente(){
    return siguiente;
}

NodoLista* NodoLista::getAnterior(){
    return anterior;
}
