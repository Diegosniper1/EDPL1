#ifndef NODOLISTAPASAJEROS_H
#define NODOLISTAPASAJEROS_H


class NodoListaPasajeros
{
    public:
        NodoListaPasajeros();
        virtual ~NodoListaPasajeros();

    protected:

    private:
        NodoListaPasajeros *siguiente;
        NodoListPasajeros *anterior;
        Pasajero pasajero;
        int tiempoEstancia;
        friend class ListaPasajeros;
};

#endif // NODOLISTAPASAJEROS_H
