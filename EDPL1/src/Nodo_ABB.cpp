#include "Nodo_ABB.h"

Nodo_ABB::Nodo_ABB()
{
    //ctor
}

Nodo_ABB::Nodo_ABB(string p)
{
        this->pais = pais;
        this->listaPasajeros = new ListaPasajeros();
        this->listaPasajeros->insertarPasajero(p, tiempoEstancia);
        this->izq = nullptr;
        this->der = nullptr;



Nodo_ABB::~Nodo_ABB()
{
    //dtor
}


// Metodos get

Nodo_ABB* Nodo_ABB::getIzq()
{
    return izq;
}

Nodo_ABB* Nodo_ABB::getDer()
{
   return der;
}

ListaPasajeros& Nodo_ABB::getListaPasajeros()
{
    return listaP;
}

string Nodo_ABB::getPaisDestino()
{
    return paisDestino;
}

