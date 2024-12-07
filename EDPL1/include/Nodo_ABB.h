#ifndef NODO_ABB_H
#define NODO_ABB_H
#include "ListaPasajeros.h"

class Nodo_ABB
{
    public:
        Nodo_ABB();
        Nodo_ABB(string pais);  // New constructor for "MM" node
        Nodo_ABB(string pais, Pasajero p);
        ~Nodo_ABB();
        ListaPasajeros& getListaPasajeros();
        Nodo_ABB* getIzq();
        Nodo_ABB* getDer();
        string getPaisDestino();

    protected:

    private:

        string paisDestino;
        ListaPasajeros listaP;
        Nodo_ABB* izquierdo;
        Nodo_ABB* derecho;

        friend class ABBPasajeros;

};

#endif // NODO_ABB_H
