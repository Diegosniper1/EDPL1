#include "Lista.h"
#include "NodoLista.h"

Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
    //ctor
}

Lista::~Lista()
{
    //dtor
}

void Lista::añadirBox(){
    NodoLista* l;
    if (longitud = 0){
        primero = l;
        primero->siguiente = nullptr;
        primero->anterior = nullptr;
        ultimo = l;
        ultimo->siguiente = nullptr;
        ultimo->anterior = nullptr;
        longitud = 1;
        primero.box.setIdBox(1);
    }
    else if (longitud = 1){
            if (primero.box.cola.get_longitud() > 2){
                primero->siguiente = l;
                primero->anterior = nullptr;
                ultimo = l;
                l->anterior = primero;
                l->siguiente = nullptr;
                longitud++;
                ultimo.box.setIdBox(2);
            }
        }
        else{
             NodoLista* aux = primero;
             int lleno = 0;
            while(aux != nullptr && aux.box.cola.get_longitud() > 2){
                aux = aux->siguiente;
                lleno++;
            }
            if (longitud == lleno){
                ultimo.siguiente = l;
                ultimo = l;
                ultimo.box.setIdBox(longitud+1);
                longitud++;
            }
    }
}

void Lista::borrarBoxes(){
    if (longitud <= 1){
        return;
    }
    int boxesVacios = 0;
    NodoLista* aux = primero;
    while(aux != nullptr){
        if(aux->box.cola.get_longitud() == 0 && aux->box.esVacio()){
            boxesVacios++;
        }
        aux = aux->siguiente;
    }

    if (boxesVacios >= 2) {
        aux = primero;
        while (aux != nullptr && longitud > 1) {
            NodoLista* siguiente = aux->siguiente;

            if (aux->box.cola.get_longitud() == 0 && aux->box.esVacio()) {
                if (aux == primero) {
                    primero = siguiente;
                    if (primero){
                        primero->anterior = nullptr;
                    }
                } else if (aux == ultimo) {
                    ultimo = aux->anterior;
                    ultimo->siguiente = nullptr;
                } else {
                    aux->anterior->siguiente = aux->siguiente;
                    aux->siguiente->anterior = aux->anterior;
                }
                delete aux;
                longitud--;
            }
            aux = siguiente;
        }
    }

int Lista::boxMenosOcupado() {
    if (longitud == 0) {
        return 0;
    }
    NodoLista* aux = primero;
    int minPasajeros = aux->box.cola.get_longitud();
    int boxMenor = aux->box.id_box;

    while (aux != nullptr) {
        int pasajerosActuales = aux->box.cola.get_longitud();
        if (pasajerosActuales < minPasajeros) {
            minPasajeros = pasajerosActuales;
            boxMenor = aux->box.id_box;
        }
        aux = aux->siguiente;
    }
    return boxMenor;
}

int Lista::boxMasOcupado() {
    if (longitud == 0) {
        return 0;
    }

    NodoLista* aux = primero;
    int maxPasajeros = aux->box.cola.get_longitud();
    int boxMayor = aux->box.id;

    while (aux != nullptr) {
        int pasajerosActuales = aux->box.cola.get_longitud();
        if (pasajerosActuales > maxPasajeros) {
            maxPasajeros = pasajerosActuales;
            boxMayor = aux->box.id;
        }
        aux = aux->siguiente;
    }

    return boxMayor;
}

int Lista::getBoxesOperativos() {
    int boxesOperativos = 0;
    NodoLista* aux = primero;

    while (aux != nullptr || aux->box.cola.get_longitud() > 0 ) {
        if (!aux->box.esVacio()) {
            boxesOperativos++;
        }
        aux = aux->siguiente;
    }

    return boxesOperativos;
}




}




