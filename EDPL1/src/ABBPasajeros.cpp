#include "ABBPasajeros.h"
#include<iostream>

ABBPasajeros::ABBPasajeros() {
    raiz = new Nodo_ABB("MM");
}


ABBPasajeros::~ABBPasajeros()
{
    //dtor
}


void ABBPasajeros::insertar(Nodo_ABB* raiz, string pais, Pasajero p) {
    if (esVacio()) {
        raiz = new Nodo_ABB(pais, p);
    }
    else {
        if (pais < raiz->paisDestino) {
            if (raiz->izquierdo == nullptr) {
                raiz->izquierdo = new Nodo_ABB(pais, p);
            }
            else {
                insertar(raiz->izquierdo, pais, p);
            }
        }
        if (pais > raiz->paisDestino){
            if (raiz->derecho == nullptr) {
                raiz->derecho = new Nodo_ABB(pais, p);
            }
            else {
                insertar(raiz->derecho, pais, p);
            }
        }

        if (pais == raiz->paisDestino){
            raiz->getListaPasajeros().insertarPasajero(p);
        }
    }
}



bool ABBPasajeros::buscar(Nodo_ABB* raiz, string pais) {
    if (esVacio()) {
        return false;
    }
    else {
        if (pais == raiz->paisDestino) {
            return true;
        }
        else {
            if (pais < raiz->paisDestino) {
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

int ABBPasajeros::getAltura(Nodo_ABB* nodo) {
    if (esVacio()) {
        return 0;
    }

    int alturaIzq = (raiz->izquierdo) ? getAltura(raiz->izquierdo) : 0;
    int alturaDer = (raiz->derecho) ? getAltura(raiz->derecho) : 0;

    return 1 + std::max(alturaIzq, alturaDer);
}


// Para comprobar

void ABBPasajeros::mostrarArbol(Nodo_ABB* nodo) {
    if (nodo == nullptr) {
        return;
    }

    mostrarArbol(nodo->getIzq());
    cout << "Pa�s: " << nodo->getPaisDestino() << endl;
    cout << "Pasajeros:" << endl;
    nodo->getListaPasajeros().mostrarPasajeros();
    cout << "------------------------" << endl;
    mostrarArbol(nodo->getDer());
}

