#ifndef LISTA_H
#define LISTA_H
#include "NodoLista.h"



class Lista
{
    public:
        Lista();
        virtual ~Lista();
        void añadirBox();
        void borrarBoxes();
        int boxMenosOcupado();
        int boxMasOcupado();
        int getBoxesOperativos();
    protected:

    private:
        NodoLista *primero;
        NodoLista *ultimo;
        int longitud;
        friend class Aeropuerto;

};

#endif // LISTA_H
