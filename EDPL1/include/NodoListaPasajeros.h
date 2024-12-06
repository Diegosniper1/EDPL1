#ifndef NODOLISTAPASAJEROS_H
#define NODOLISTAPASAJEROS_H


class NodoListaPasajeros
{
    public:
        NodoListaPasajeros();
        NodoListaPasajeros(Pasajero p);
        virtual ~NodoListaPasajeros();
        NodoListaPasajeros* getSiguiente();
        NodoListaPasajeros* getAnterior();
        Pasajero& getPasajero();


    protected:

    private:
        NodoListaPasajeros *siguiente;
        NodoListPasajeros *anterior;
        Pasajero pasajero;
        friend class ListaPasajeros;
};

#endif // NODOLISTAPASAJEROS_H
