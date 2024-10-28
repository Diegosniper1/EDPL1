#include "Aeropuerto.h"
#include"Pila.h"
#include"Cola.h"
#include"Box.h"
#include <vector>

using namespace std;

Aeropuerto::Aeropuerto()
{
    boxes = std::vector<Box>(3);
    this->pila = Pila();
    this->cola = Cola();
    //ctor
}

Aeropuerto::~Aeropuerto()
{
    //dtor
}

void Aeropuerto::crear_pila(){
     // Creamos la lista de pasajeros - apartado 1

    Pasajero p1 = Pasajero(1,6,"Indonesia",0,20);
    Pasajero p2 = Pasajero(2,1,"Portugal",0,15);
    Pasajero p3 = Pasajero(3,7,"Australia",5,39);
    Pasajero p4 = Pasajero(4,5,"Sudáfrica",7,39);
    Pasajero p5 = Pasajero(5,6,"Indonesia",9,16);
    Pasajero p6 = Pasajero(6,4,"Noruega",11,23);
    Pasajero p7 = Pasajero(7,7,"Australia",14,31);
    Pasajero p8 = Pasajero(8,2,"Italia",18,14);
    Pasajero p9 = Pasajero(9,3,"Alemania",21,20);

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


void Aeropuerto::mostrar_pila_entera(){

    pnodo aux;

    if (this.pila.esVacia()){

        cout << "Pila vacia"<<endl;
    }
    else{

        aux = this.pila.cima;

        while (aux != nullptr) {

             cout << "Pasajero:" << aux ->p asajero << endl;

             aux = aux ->siguiente;

        }

    }
}

void Aeropuerto::borrar_pila(){

    while(this->pila.cima != nullptr){
        pila.desapilar;
    }
}

void Aeropuerto::mostrar_cola()
{

    if (this.cola.es_vacia()) {
        cout << "La cola está vacía." << endl;
        return;
    }


    NodoCola* aux = this.cola.primero;
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


void Aeropuerto::mostrar_boxes(){   // Revisar luego

    for(int i = 0; i < this.boxes.size(); i++) {
        cout << "Box" << i << ":" << this.boxes[i].pasajero <<endl;
            cout << "Id:" << this.boxes[i].pasajero.id << "Duración:" << this.boxes[i].pasajero.duracion << endl;
    }
}

vector<Box> & Aeropuerto::getBoxes(){
    this->boxes = boxes;
    return boxes;
}

Pila Aeropuerto::getPila(){
    this->pila = pila;
    return pila;
}

Cola Aeropuerto::getCola(){
    this->cola = cola;
    return cola;
}







