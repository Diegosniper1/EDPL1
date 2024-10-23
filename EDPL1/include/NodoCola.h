#ifndef NODOCOLA_H
#define NODOCOLA_H


class NodoCola
{


    public:
        NodoCola();
        virtual ~NodoCola();
        NodoCola(Pasajero pasajero, NodoCola*sig = NULL);

    protected:

    private:
        NodoCola *siguiente;
        Pasajero pasajero;
        int prioridad;
        friend class Cola;




};

#endif // NODOCOLA_H








