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
    return this->raiz == nullptr;
}

int ABBPasajeros::getAltura(Nodo_ABB* raiz) {
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
        if (this->raiz == nullptr) {
           cout << "Árbol vacío" << endl;
        }
        return;
    }

    // Primero se recorre el subarbol izquierdo
    mostrarArbol(nodo->getIzq());
    // Se muestran los datos de cada nodo
    cout << "País: " << nodo->getPaisDestino() << endl;
    cout << "Pasajeros:" << endl;
    NodoListaPasajeros* actual = nodo->getListaPasajeros().getPrimero();
    nodo->getListaPasajeros().mostrarPasajeros();
    cout << "------------------------" << endl;
    // Se recorre el subarbol derecho
    mostrarArbol(nodo->getDer());
}

Nodo_ABB* ABBPasajeros::buscarPais(Nodo_ABB* nodo, string pais) {
    if (nodo == nullptr || nodo->getPaisDestino() == pais) {
        return nodo;
    }

    if (pais < nodo->getPaisDestino()) {
        return buscarPais(nodo->getIzq(), pais);
    }
    return buscarPais(nodo->getDer(), pais);
}

void ABBPasajeros::mostrarPasajerosPorPais(string pais) {
    Nodo_ABB* nodo = buscarPais(this->raiz, pais);

    if (nodo == nullptr) {
        cout << "No se encontraron pasajeros con destino a " << pais << endl;
        return;
    }

    cout << "\nPasajeros con destino a " << pais << ":" << endl;
    NodoListaPasajeros* actual = nodo->getListaPasajeros().getPrimero();
    nodo->getListaPasajeros().mostrarPasajeros();
    cout << "------------------------" << endl;
}

void ABBPasajeros::mostrarPaises(Nodo_ABB* nodo) {
    if (nodo == nullptr) {
        if (this->raiz == nullptr) {
           cout << "Árbol vacío" << endl;
        }
        return;
    }
    else {
        mostrarPaises(nodo->getIzq());
        if (!nodo->getListaPasajeros().esVacia()) {
            cout << "- " << nodo->getPaisDestino() << endl;
        }
        mostrarPaises(nodo->getDer());
    }
}

void ABBPasajeros::buscarMayor(Nodo_ABB* nodo, string& mayorPais, int& mayorPasajeros) {
    if (nodo == nullptr) {
        if (this->raiz == nullptr) {
           cout << "Árbol vacío" << endl;
        }
        return;
    }

    int numPasajeros = nodo->getListaPasajeros().getLongitud();

    if (numPasajeros > mayorPasajeros) {
        mayorPasajeros = numPasajeros;
        mayorPais = nodo->getPaisDestino();
    }
    buscarMayor(nodo->getIzq(), mayorPais, mayorPasajeros);
    buscarMayor(nodo->getDer(), mayorPais, mayorPasajeros);
}


void ABBPasajeros::buscarMenor(Nodo_ABB* nodo, string& menorPais, int& menorPasajeros) {
    if (nodo == nullptr) {
        if (this->raiz == nullptr) {
           cout << "Árbol vacío" << endl;
        }
        return;
    }

    int numPasajeros = nodo->getListaPasajeros().getLongitud();

    if (numPasajeros < menorPasajeros && numPasajeros > 0) {
        menorPasajeros = numPasajeros;
        menorPais = nodo->getPaisDestino();
    }
    buscarMenor(nodo->getIzq(), menorPais, menorPasajeros);
    buscarMenor(nodo->getDer(), menorPais, menorPasajeros);
}


void ABBPasajeros::mostrarMayor() {
    if (esVacio()) {
        cout << "Árbol vacío" << endl;
        return;
    }
    string mayorPais = "";
    int mayorPasajeros = 0;
    buscarMayor(raiz, mayorPais, mayorPasajeros);
    cout << "Pais con mas pasajeros: " << mayorPais << " (" << mayorPasajeros << " pasajeros)" << endl;
}

void ABBPasajeros::mostrarMenor() {
    if (esVacio()) {
        cout << "Árbol vacío" << endl;
        return;
    }
    string menorPais = "";
    int menorPasajeros = 999;
    buscarMenor(raiz, menorPais, menorPasajeros);
    cout << "Pais con menos pasajeros: " << menorPais << " (" << menorPasajeros << " pasajeros)" << endl;
}



void ABBPasajeros::tiempoMedioPais(string pais) {
    Nodo_ABB* nodo = buscarPais(this->raiz, pais);
    if (nodo != nullptr) {
        int total = 0;
        int count = 0;
        NodoListaPasajeros* actual = nodo->getListaPasajeros().getPrimero();  // Usar NodoListaPasajeros
        while (actual != nullptr) {
            total += actual->getPasajero().getTiempoEstancia();
            count++;
            actual = actual->getSiguiente();
        }
        double tiempo = count > 0 ? (double)total/count : 0;
        cout << "Tiempo medio de estancia para " << pais << ": "
             << tiempo << " minutos" << endl;
    } else {
        cout << "País no encontrado" << endl;
    }
}

void ABBPasajeros::tiempoMedioTodos(Nodo_ABB* nodo) {
    if (nodo == nullptr) {
        if (this->raiz == nullptr) {
           cout << "Árbol vacío" << endl;
        }
        return;
    }

    tiempoMedioTodos(nodo->getIzq());

    int total = 0;
    int count = 0;
    NodoListaPasajeros* actual = nodo->getListaPasajeros().getPrimero();
    while (actual != nullptr) {
        total += actual->getPasajero().getTiempoEstancia();
        count++;
        actual = actual->getSiguiente();
    }
    double tiempo = count > 0 ? (double)total/count : 0;

    cout << nodo->getPaisDestino() << ": " << tiempo << " minutos" << endl;

    tiempoMedioTodos(nodo->getDer());
}

