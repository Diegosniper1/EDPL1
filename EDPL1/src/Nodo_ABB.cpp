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
        this->izquierdo = nullptr;
        this->derecho = nullptr;



Nodo_ABB::~Nodo_ABB()
{
    //dtor
}


// Metodos get
