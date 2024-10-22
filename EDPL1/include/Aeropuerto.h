#ifndef AEROPUERTO_H
#define AEROPUERTO_H


class Aeropuerto
{
    public:
        Aeropuerto();
        virtual ~Aeropuerto();
        void mostrar_entera_Pila();
        int mostrar();c

    protected:

    private:
        Pila pila;
        Cola cola;
        Box box;
};

#endif // AEROPUERTO_H
