#ifndef AEROPUERTO_H
#define AEROPUERTO_H

#include "Pila.h"
#include "Cola.h"
#include "Box.h"
#include "Lista.h"
#include <vector>

class Aeropuerto {
private:
    std::vector<Box> boxes;  // Para menú 1
    Lista lista;             // Para menú 2
    Pila pila;
    Cola cola;

public:
    Aeropuerto();
    ~Aeropuerto();

    // Métodos para menú 1
    Pila crear_pila();
    void mostrar_pila_entera(Pila p);
    void borrar_pila(Pila& p);
    void mostrar_cola(Cola& c);
    void mostrar_boxes();
    vector<Box>& getBoxes();
    Pila getPila();
    Cola getCola();
    void setBoxes(Box b1, Box b2, Box b3);
    Box getBox(int i);

    // Métodos para menú 2
    Lista& getLista();
    void mostrar_boxes_lista();
    void procesarLlegada(Pasajero& p);
};

#endif
