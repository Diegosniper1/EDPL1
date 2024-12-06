#include "Aeropuerto.h"
#include "Pila.h"
#include "NodoPila.h"
#include "NodoCola.h"
#include "Cola.h"
#include "Box.h"
#include "Lista.h"
#include <vector>

using namespace std;

Aeropuerto::Aeropuerto() {
    boxes = std::vector<Box>(3);
    this->pila = Pila();
    this->cola = Cola();
    lista = Lista();  // Lista menu 2
    abb = ABBPasajeros();
}

Aeropuerto::~Aeropuerto() {
}

Pila Aeropuerto::crear_pila() {
    Pila p;
    Pasajero p1 = Pasajero(1,6,"Indonesia",0,10);
    Pasajero p2 = Pasajero(2,1,"Portugal",0,15);
    Pasajero p3 = Pasajero(3,7,"Australia",5,29);
    Pasajero p4 = Pasajero(4,5,"Sudáfrica",7,8);
    Pasajero p5 = Pasajero(5,7,"Australia",9,16);
    Pasajero p6 = Pasajero(6,6,"Indonesia",9,13);
    Pasajero p7 = Pasajero(7,6,"Indonesia",10,10);
    Pasajero p8 = Pasajero(8,1,"Portugal",10,15);
    Pasajero p9 = Pasajero(9,7,"Australia",15,29);
    Pasajero p10 = Pasajero(10,5,"Sudáfrica",17,8);
    Pasajero p11 = Pasajero(11,7,"Australia",19,16);
    Pasajero p12 = Pasajero(12,6,"Indonesia",19,13);


    p.apilar_por_orden(p12);
    p.apilar_por_orden(p11);
    p.apilar_por_orden(p10);
    p.apilar_por_orden(p9);
    p.apilar_por_orden(p8);
    p.apilar_por_orden(p7);
    p.apilar_por_orden(p6);
    p.apilar_por_orden(p5);
    p.apilar_por_orden(p4);
    p.apilar_por_orden(p3);
    p.apilar_por_orden(p2);
    p.apilar_por_orden(p1);
    return p;
}

void Aeropuerto::mostrar_pila_entera(Pila p) {
    pnodo aux;
    if (p.esVacia()) {
        cout << "Pila vacia" << endl;
    } else {
        aux = p.cima;
        while (aux != nullptr) {
            cout << "Pasajero:" << aux->getPasajero() << endl;
            aux = aux->getSiguiente();
        }
    }
}

void Aeropuerto::borrar_pila(Pila& p) {
    while(p.cima != nullptr) {
        p.desapilar();
    }
}

void Aeropuerto::mostrar_cola(Cola& c) {
    if (c.es_vacia()) {
        cout << "La cola esta vacia." << endl;
        return;
    }

    NodoCola* aux = c.primero;
    int contador = 1;
    while (aux != nullptr) {
        cout << "Pasajero: " << contador << endl;
        cout << "ID: " << aux->getPasajero().getId() << endl;
        cout << "Prioridad: " << aux->getPasajero().getPrioridad() << endl;
        aux = aux->getSiguiente();
        contador++;
    }
}

void Aeropuerto::mostrar_boxes() {
    for (int i = 0; i < boxes.size(); i++) {
        cout << "Box ID: " << boxes[i].getIdBox() << endl;
        if (!boxes[i].esVacio()) {
            cout << "  Pasajero ID: " << boxes[i].getPasajero().getId() << endl;
            cout << "  Duración: " << boxes[i].getPasajero().getDuracion() << endl;
        } else {
            cout << "  Esta vacío." << endl;
        }
    }
}

vector<Box>& Aeropuerto::getBoxes() {
    return boxes;
}

Pila Aeropuerto::getPila() {
    return pila;
}

Cola Aeropuerto::getCola() {
    return cola;
}

void Aeropuerto::setBoxes(Box b1, Box b2, Box b3) {
    this->boxes = {b1, b2, b3};
}

Box Aeropuerto::getBox(int i) {
    return this->getBoxes()[i];
}

// Metodos parte 2
Lista& Aeropuerto::getLista() {
    return lista;
}

ABBPasajeros& Aeropuerto::getABBPasajeros() {
    return abb;
}

void Aeropuerto::mostrar_boxes_lista() {
    lista.mostrarBoxes();
}

void Aeropuerto::procesarLlegada(Pasajero& p) {
    NodoLista* boxMenorCola = lista.getPrimero();
    NodoLista* aux = lista.getPrimero();

    while (aux != nullptr) {
        if (aux->getBox().getTotalPasajeros() < boxMenorCola->getBox().getTotalPasajeros()) {
            boxMenorCola = aux;
        }
        aux = aux->getSiguiente();
    }

    if (boxMenorCola->getBox().esVacio()) {
        boxMenorCola->getBox().setPasajero(p);
    } else {
        boxMenorCola->getBox().encolarPasajero(p);
    }
}





