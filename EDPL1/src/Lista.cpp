#include "Lista.h"
#include "NodoLista.h"

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

void Lista::añadirBox(){
    NodoLista* l = new NodoLista(); /// Creamos el nodo con new ya que es un puntero -> new para punteros (mem dinamica)
   // 2. Caso lista vacía
    if (longitud == 0) {
        primero = l;
        ultimo = l;
        primero->box.setIdBox(1);
        longitud = 1;
    }
    // 3. Lista con elementos
    else {
        // 4. Verificar si necesitamos nuevo box
        bool necesitaNuevoBox = true;
        NodoLista* aux = primero;
        while (aux != nullptr) {
            if (aux->box.cola.get_longitud() <= 2) {
                necesitaNuevoBox = false;
                break;
            }
            aux = aux->siguiente;
        }

        // 5. Si necesitamos nuevo box, lo añadimos
        if (necesitaNuevoBox) {
            ultimo->siguiente = l;
            l->anterior = ultimo;
            ultimo = l;
            ultimo->box.setIdBox(longitud + 1);
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
    if (longitud == 0) return 0;

    NodoLista* aux = primero;
    int minPasajeros = aux->box.cola.get_longitud() + (!aux->box.esVacio() ? 1 : 0);
    int boxMenor = aux->box.getIdBox();

    while (aux != nullptr) {
        int pasajerosActuales = aux->box.cola.get_longitud() + (!aux->box.esVacio() ? 1 : 0);
        if (pasajerosActuales < minPasajeros) {
            minPasajeros = pasajerosActuales;
            boxMenor = aux->box.getIdBox();
        }
        aux = aux->siguiente;
    }
    return boxMenor;
}

int Lista::boxMasOcupado(){
    if (longitud == 0) return 0;

    NodoLista* aux = primero;
    int maxPasajeros = aux->box.cola.get_longitud() + (!aux->box.esVacio() ? 1 : 0);
    int boxMayor = aux->box.getIdBox();

    while (aux != nullptr) {
        int pasajerosActuales = aux->box.cola.get_longitud() + (!aux->box.esVacio() ? 1 : 0);
        if (pasajerosActuales > maxPasajeros) {
            maxPasajeros = pasajerosActuales;
            boxMayor = aux->box.getIdBox();
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

NodoLista* getPrimero(){
    return primero;

}




}




