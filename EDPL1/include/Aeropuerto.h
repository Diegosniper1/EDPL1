#ifndef AEROPUERTO_H
#define AEROPUERTO_H


class Aeropuerto
{
    public:
        Aeropuerto();
        virtual ~Aeropuerto();
        mostrar_pila_entera();
        mostrar_boxes();
        mostrar_cola();

    protected:

    private:
        Pila pila;
        Cola cola;
        Box box;
};

#endif // AEROPUERTO_H
