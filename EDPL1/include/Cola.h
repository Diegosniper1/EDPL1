#ifndef COLA_H
#define COLA_H


class Cola
{
    public:
        Cola();
        ~Cola();
        void encolar(char);
        Pasajero inicio();
        Pasajero fin();
        char desencolar();
        bool es_vacia();

    private:
        NodoCola * primero;
        NodoCola * ultimo;
        int longitud;
};

#endif // COLA_H
