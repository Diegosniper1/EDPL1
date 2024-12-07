#ifndef ABBPASAJEROS_H
#define ABBPASAJEROS_H
#include "Nodo_ABB.h"



class ABBPasajeros
{
    public:
        ABBPasajeros();
        virtual ~ABBPasajeros();
        void insertar(Nodo_ABB* nodo, string pais, Pasajero p);
        bool buscar(Nodo_ABB* nodo, string pais);
        Nodo_ABB* getRaiz();
        ABBPasajeros* getIzquierdo();
        ABBPasajeros* getDerecho();
        bool esVacio();
        int getAltura(Nodo_ABB* nodo);
        void mostrarArbol(Nodo_ABB* nodo);




    protected:

    private:
        Nodo_ABB* raiz;
        friend class Aeropuerto;
};

#endif // ABBPASAJEROS_H
