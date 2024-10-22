#ifndef COLA_H
#define COLA_H


class Cola
{
    public:
        Cola();
        ~Cola();
        void encolar(Pasajero);
        Pasajero desencolar();
        void mostrar();
        Pasajero inicio();
        Pasajero fin();

        bool es_vacia();
        int get_longitud();

    private:
        NodoCola * primero;
        NodoCola * ultimo;
        int longitud;
};

#endif // COLA_H
