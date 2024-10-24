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
        std::vector<Box> boxes; ;
};

#endif // AEROPUERTO_H
