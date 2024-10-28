#include "Pila.h"
#include "NodoPila.h"


Pila::Pila()
{
    cima = nullptr;
    //this.cima = Null es lo que estaba antes
    //ctor
}

Pila::~Pila()
{

    //dtor
}

bool Pila::esVacia(){

    return cima == NULL;

}


void Pila::apilar(Pasajero p){
    pnodo nuevo = new NodoPila(p, cima);

    cima = nuevo;

}


void Pila::apilar_por_orden(Pasajero pas){
    Pila paux;
    if (!esVacia()){
        while(pas.hora_inicio > cima.pasajero.hora_inicio){
            paux.apilar(cima.pasajero);
            desapilar();
            //if (esVacia())break;
        }
        apilar(pas);
        while(!paux.esVacia()){
            apilar(paux.cima.pasajero);
            //paux.desapilar();
        }
    }
    else{
        apilar(pas);
    }

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

void Pila::mostrar_entera(){

    pnodo aux;

    if (esVacia()){

        cout << "Pila vacia"<<endl;
    }
    else{

        aux = cima;

        while (aux != NULL) {

             cout << aux -> pasajero << "";

             aux = aux ->siguiente;

        }

    }


}





