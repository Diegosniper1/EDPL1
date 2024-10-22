#include "Aeropuerto.h"

Aeropuerto::Aeropuerto()
{
    //ctor
}

Aeropuerto::~Aeropuerto()
{
    //dtor
}

void mostrar_entera_pila(Pila p){

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

Pasajero Pila::mostrar(){
     if(esVacia()) {
        cout << "Pila vacia"<<endl;
     }
     else{
        cout << "Cima pila: "<< cima->pasajero<<endl;
     }
     return 0;

}


