#include "Pila.h"
#include "NodoPila.h"


Pila::Pila()
{
    cima = NULL;
    //ctor
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
Pasajero Pila::mostrar(){
     if(esVacia()) {
        cout << "Pila vacia"<<endl;
     }
     else{
        cout << "Cima pila: "<< cima->pasajero<<endl;
     }
     return 0;

}

void mostrar_entera(){

    pnodo aux;

    if (esVacia()){

        cout << "Pila vacia"<<endl;
    }
    else{

        aux = cima;

        while (aux != NULL) {

             cout << aux -> pasajero <<"";

             aux = aux ->siguiente;

        }

    }


}





