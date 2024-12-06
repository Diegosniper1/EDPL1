#ifndef LISTAPASAJEROS_H
#define LISTAPASAJEROS_H


class ListaPasajeros
{
    public:
        ListaPasajeros();
        virtual ~ListaPasajeros();

    protected:

    private:

        NodoListaPasajeros *primero;
        NodoListaPasajeros *ultimo;
        int longitud;
        friend class Nodo_ABB;
};

#endif // LISTAPASAJEROS_H
