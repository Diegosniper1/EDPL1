#ifndef COLA_H
#define COLA_H


class Cola
{
    public:
        Cola();
        ~Cola();
        void encolar(Pasajero);
        Pasajero inicio();
        Pasajero fin();
        Pasajero desencolar();
        bool es_vacia();

    private:
        NodoCola * primero;
        NodoCola * ultimo;
        int longitud;
};

#endif // COLA_H
