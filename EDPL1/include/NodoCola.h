#ifndef NODOCOLA_H
#define NODOCOLA_H


class NodoCola
{

    friend class Cola;
    public:
        NodoCola();
        virtual ~NodoCola();
        NodoCola(Pasajero pasajero, NodoCola*sig = NULL);

    protected:

    private:
        NodoCola *siguiente;
        Pasajero pasajero;
        int prioridad




};

#endif // NODOCOLA_H








