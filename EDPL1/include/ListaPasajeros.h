#ifndef LISTAPASAJEROS_H
#define LISTAPASAJEROS_H
#include "NodoListaPasajeros.h"
#include "Pasajero.h"


class ListaPasajeros
{
    public:
        ListaPasajeros();
        virtual ~ListaPasajeros();
        NodoListaPasajeros* getPrimero();
        NodoListaPasajeros* getUltimo();
        int getLongitud();
        void insertarPasajero(Pasajero p);
        int getTiempoMedioEstancia();
        void mostrarPasajeros();
        bool  esVacia();

    protected:

    private:

        NodoListaPasajeros *primero;
        NodoListaPasajeros *ultimo;
        int longitud;
        friend class Nodo_ABB;
};

#endif // LISTAPASAJEROS_H
