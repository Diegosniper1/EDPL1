#include "Nodo_ABB.h"
#include "Pasajero.h"


Nodo_ABB::Nodo_ABB() {
    this->paisDestino = "";
    this->listaP = ListaPasajeros();
    this->izquierdo = nullptr;
    this->derecho = nullptr;
}

Nodo_ABB::Nodo_ABB(string pais) {
    this->paisDestino = pais;
    this->listaP = ListaPasajeros();
    this->izquierdo = nullptr;
    this->derecho = nullptr;
}

Nodo_ABB::Nodo_ABB(string pais, Pasajero p)
{
        this->paisDestino = pais;
        this->listaP = ListaPasajeros();
        this->listaP.insertarPasajero(p);
        this->izquierdo = nullptr;
        this->derecho = nullptr;
}


Nodo_ABB::~Nodo_ABB()
{
     if (izquierdo != nullptr) {
        delete izquierdo;
    }
    if (derecho != nullptr) {
        delete derecho;
    }
    //dtor
}


// Metodos get

Nodo_ABB* Nodo_ABB::getIzq()
{
    return izquierdo;
}

Nodo_ABB* Nodo_ABB::getDer()
{
   return derecho;
}

ListaPasajeros& Nodo_ABB::getListaPasajeros()
{
    return listaP;
}

string Nodo_ABB::getPaisDestino()
{
    return paisDestino;
}

