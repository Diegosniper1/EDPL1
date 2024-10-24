#include "Aeropuerto.h"
#include"Pila.h"
#include"Cola.h"
#include"Box.h"
#include <vector>

Aeropuerto::Aeropuerto()
{
    vector<Box> boxes(3);
    this->pila = NULL;
    this->cola = Cola();

    //ctor
}

Aeropuerto::~Aeropuerto()
{
    //dtor
}

void Aeropuerto::crear_pila(){
    this->pila = Pila();
    this->pila.apilar_por_orden(p9);
    this->pila.apilar_por_orden(p8);
    this->pila.apilar_por_orden(p7);
    this->pila.apilar_por_orden(p6);
    this->pila.apilar_por_orden(p5);
    this->pila.apilar_por_orden(p4);
    this->pila.apilar_por_orden(p3);
    this->pila.apilar_por_orden(p2);
    this->pila.apilar_por_orden(p1);

}


void Aeropuerto::mostrar_pila_entera(this->pila){

    pnodo aux;

    if (esVacia()){

        cout << "Pila vacia"<<endl;
    }
    else{

        aux = cima;

        while (aux != NULL) {

             cout << "Pasajero:" aux -> pasajero << endl;

             aux = aux ->siguiente;

        }

    }
}

void Aeropuerto::borrar_pila(){

    while(this->pila.cima != NULL){
        pila.desapilar;
    }
}

void Aeropuerto::mostrar_cola(this.cola)
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
        cout << "ID: " << aux->pasajero.id << endl;
        cout << "Prioridad: " << aux->pasajero.prioridad << endl;
        aux = aux->siguiente;
        contador++;
    }
}

void Aeropuerto::mostrar_boxes(){

}


