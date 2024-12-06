#ifndef ABBPASAJEROS_H
#define ABBPASAJEROS_H


class ABBPasajeros
{
    public:
        ABBPasajeros();
        virtual ~ABBPasajeros();
        void insertar(string pais, Pasajero p, int tiempoEstancia);
        bool buscar(string pais);
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
