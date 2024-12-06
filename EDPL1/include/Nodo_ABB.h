#ifndef NODO_ABB_H
#define NODO_ABB_H


class Nodo_ABB
{
    public:
        Nodo_ABB();
        Nodo_ABB();
        virtual ~Nodo_ABB();
        ListaPasajeros& getListaPasajeros();
        Nodo_ABB* getIzq();
        Nodo_ABB* getDer();
        string getPaisDestino();

    protected:

    private:

        string paisDestino;
        ListaPasajeros* listaP;
        Nodo_ABB* izq;
        Nodo_ABB* der;

        friend class ABBPasajeros;

};

#endif // NODO_ABB_H
