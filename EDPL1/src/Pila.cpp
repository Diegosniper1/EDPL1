#include "Pila.h"
#include "NodoPila.h"


Pila::Pila()
{
    cima = NULL;
    //ctor fdssd
}

Pila::~Pila()
{

    //dtor
}

bool Pila::esVacia(){

    return cima == NULL;

}


void Pila::apilar(int p){
    pnodo nuevo = new NodoPila(p, cima);

    cima = nuevo;

}


void Pila::desapilar(){
     pnodo nodo; //puntero aux para manipular el nodo
     if(cima)
     nodo = cima;
     cima = nodo->siguiente;
     delete nodo;
}
int Pila::mostrar(){
     if(esVacia()) {
        cout << "Pila vacia"<<endl;
     }
     else{
        cout << "Cima pila: "<< cima->valor<<endl;
     }
     return 0;
}

