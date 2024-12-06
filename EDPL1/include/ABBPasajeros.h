#ifndef ABBPASAJEROS_H
#define ABBPASAJEROS_H


class ABBPasajeros
{
    public:
        ABBPasajeros();
        virtual ~ABBPasajeros();
        void insertar(Nodo_ABB* nodo, string pais, Pasajero p);
        bool buscar(Nodo_ABB* nodo, string pais);
        Nodo_ABB* getRaiz()
        ABBPasajeros* getIzquierdo();
        ABBPasajeros* getDerecho();
        bool esVacio();
        int getAltura();




    protected:

    private:
        Nodo_ABB* raiz;
};

#endif // ABBPASAJEROS_H
