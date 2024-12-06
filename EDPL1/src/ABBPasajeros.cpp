#include "ABBPasajeros.h"

ABBPasajeros::ABBPasajeros()
{
    //ctor
    raiz = nullptr;
}

ABBPasajeros::~ABBPasajeros()
{
    //dtor
}


void ABBPasajeros::insertar(string pais, Pasajero p, int tiempoEstancia) {
    if (esVacio()) {
        raiz = new Nodo_ABB(pais, p, tiempoEstancia);
    }
    else {
        if (pais <= raiz->pais) {
            if (raiz->izquierdo == nullptr) {
                raiz->izquierdo = new Nodo_ABB(pais, p, tiempoEstancia);
            }
            else {
                insertar(raiz->izquierdo, pais, p, tiempoEstancia);
            }
        }
        else {
            if (raiz->derecho == nullptr) {
                raiz->derecho = new Nodo_ABB(pais, p, tiempoEstancia);
            }
            else {
                insertar(raiz->derecho, pais, p, tiempoEstancia);
            }
        }
    }
}



bool ABBPasajeros::buscar(string pais) {
    if (esVacio()) {
        return false;
    }
    else {
        if (pais == raiz->pais) {
            return true;
        }
        else {
            if (pais < raiz->pais) {
                return buscar(raiz->izquierdo, pais);
            }
            else {
                return buscar(raiz->derecho, pais);
            }
        }
    }
}


Nodo_ABB* ABBPasajeros::getRaiz() {
    return raiz;
}

ABBPasajeros* ABBPasajeros::getIzquierdo() {
    if (!esVacio()) {
        ABBPasajeros* izq = new ABBPasajeros();
        izq->raiz = raiz->izquierdo;
        return izq;
    }
    return nullptr;
}

ABBPasajeros* ABBPasajeros::getDerecho() {
    if (!esVacio()) {
        ABBPasajeros* der = new ABBPasajeros();
        der->raiz = raiz->derecho;
        return der;
    }
    return nullptr;
}

bool ABBPasajeros::esVacio() {
    return raiz == nullptr;
}

int ABBPasajeros::getAltura() {
    if (esVacio()) {
        return 0;
    }

    int alturaIzq = (raiz->izquierdo) ? getAltura(raiz->izquierdo) : 0;
    int alturaDer = (raiz->derecho) ? getAltura(raiz->derecho) : 0;

    return 1 + std::max(alturaIzq, alturaDer);
}
