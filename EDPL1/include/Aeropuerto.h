#ifndef AEROPUERTO_H
#define AEROPUERTO_H
#include "Box.h"
#include "Pila.h"
#include "Cola.h"

#include <vector>

using namespace std;

class Aeropuerto
{
    public:
        Aeropuerto();
        virtual ~Aeropuerto();
        Pila crear_pila();
        void borrar_pila(Pila& p);
        void mostrar_pila_entera(Pila p);
        void mostrar_boxes();
        void mostrar_cola(Cola& c);
        vector<Box>& getBoxes();
        Box getBox(int);
        void setBoxes(Box a, Box b, Box c);
        Pila getPila();
        Cola getCola();

    protected:

    private:
        Pila pila;
        Cola cola;
        std::vector<Box> boxes;
};

#endif // AEROPUERTO_H
