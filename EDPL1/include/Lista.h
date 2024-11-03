#ifndef LISTA_H
#define LISTA_H
#include "NodoLista.h"



class Lista
{
    public:
        Lista();
        ~Lista();
        void nuevoBox();
        void borrarBoxes();
        int boxMenosOcupado();
        int boxMasOcupado();
        int getBoxesOperativos();
        NodoLista* getPrimero();
        NodoLista* getUltimo();
        void mostrarBoxes();
        bool hayPasajerosEnSistema();

    private:
        NodoLista *primero;
        NodoLista *ultimo;
        int longitud;
        friend class Aeropuerto;

};

#endif // LISTA_H
