#ifndef AEROPUERTO_H
#define AEROPUERTO_H


class Aeropuerto
{
    public:
        Aeropuerto();
        virtual ~Aeropuerto();

    protected:

    private:
        Pila pila;
        Cola cola;
        Box box;
};

#endif // AEROPUERTO_H
