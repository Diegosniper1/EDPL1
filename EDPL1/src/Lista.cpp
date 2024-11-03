#include "Lista.h"
#include "NodoLista.h"
#include "Box.h"
#include <iostream>




Lista::Lista()
{
    primero = nullptr;
    ultimo = nullptr;
    longitud = 0;
    //ctor
}

Lista::~Lista(){
     NodoLista* actual = primero;
        while (actual != nullptr) {
            NodoLista* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
}

void Lista::mostrarBoxes(){
    if (longitud == 0){
        cout << "Lista vacia" << endl;
    }
    else{
        NodoLista* aux = primero;
        while (aux != nullptr){
            cout << "\nBox ID: " << aux->getBox().getIdBox() << endl;
            if (!aux->getBox().esVacio()) {
                cout << "Pasajero Actual: " << aux->getBox().getPasajero().getId() << endl;
                cout << "Tiempo Restante: " << aux->getBox().getPasajero().getDuracion() << endl;
            }
            else {
                cout << "Pasajero Actual: Ninguno" << endl;
                cout << "Tiempo Restante: 0" << endl;
            }
            cout << "Pasajeros en Espera:" << endl;
            if (aux->getBox().getCola().get_longitud() > 0) {
                aux->getBox().getCola().mostrar();
            }
            else {
                cout << "- No hay pasajeros en espera" << endl;
            }
            aux = aux->getSiguiente();
        }
    }
}

void Lista::nuevoBox(){
    NodoLista* l = new NodoLista(); /// Creamos el nodo con new ya que es un puntero -> new para punteros (mem dinamica)
   // 2. Caso lista vacía
    if (longitud == 0) {
        primero = l;
        ultimo = l;
        primero->getBox().setIdBox(1);
        longitud = 1;
    }
    // 3. Lista con elementos
    else {
        // 4. Verificar si necesitamos nuevo box
        bool necesitaNuevoBox = true;
        NodoLista* aux = primero;
        while (aux != nullptr) {
            if (aux->getBox().getCola().get_longitud() <= 2) {
                necesitaNuevoBox = false;
                break;
            }
            aux = aux->getSiguiente();
        }

        // 5. Si necesitamos nuevo box, lo añadimos
        if (necesitaNuevoBox) {
            ultimo->siguiente = l;
            l->anterior = ultimo;
            ultimo = l;
            ultimo->getBox().setIdBox(longitud + 1);
            longitud++;
        }
        // 6. Si no lo necesitamos, liberamos memoria
        else {
            delete l;
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
        if(aux->getBox().getCola().get_longitud() == 0 && aux->getBox().esVacio()){
            boxesVacios++;
        }
        aux = aux->siguiente;
    }

    if (boxesVacios >= 2) {
        aux = primero;
        while (aux != nullptr && longitud > 1) {
            NodoLista* siguiente = aux->siguiente;

            if (aux->getBox().getCola().get_longitud() == 0 && aux->getBox().esVacio()) {
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
}

int Lista::boxMenosOcupado() {
    if (longitud == 0) return 0;

    NodoLista* aux = primero;
    int minPasajeros = aux->getBox().getCola().get_longitud() + (!aux->getBox().esVacio() ? 1 : 0);
    int boxMenor = aux->getBox().getIdBox();

    while (aux != nullptr) {
        int pasajerosActuales = aux->getBox().getCola().get_longitud() + (!aux->getBox().esVacio() ? 1 : 0);
        if (pasajerosActuales < minPasajeros) {
            minPasajeros = pasajerosActuales;
            boxMenor = aux->getBox().getIdBox();
        }
        aux = aux->getSiguiente();
    }
    return boxMenor;
}

int Lista::boxMasOcupado()
{
    int boxMayor;
    if (longitud == 0){
       boxMayor = 0;
    }

    NodoLista* aux = primero;
    int maxPasajeros = aux->getBox().getCola().get_longitud() + (!aux->getBox().esVacio() ? 1 : 0);
    boxMayor = aux->getBox().getIdBox();

    while (aux != nullptr) {
        int pasajerosActuales = aux->getBox().getCola().get_longitud() + (!aux->getBox().esVacio() ? 1 : 0);
        if (pasajerosActuales > maxPasajeros) {
            maxPasajeros = pasajerosActuales;
            boxMayor = aux->getBox().getIdBox();
        }
        aux = aux->getSiguiente();
    }
    return boxMayor;
}

int Lista::getBoxesOperativos()
{
    int boxesOperativos = 0;
    NodoLista* aux = primero;

    while (aux != nullptr || aux->getBox().getCola().get_longitud() > 0 ) {
        if (!aux->getBox().esVacio()) {
            boxesOperativos++;
        }
        aux = aux->getSiguiente();
    }

    return boxesOperativos;
}

NodoLista* Lista::getPrimero(){
    return primero;

}

NodoLista* Lista::getUltimo(){
    return ultimo;

}






