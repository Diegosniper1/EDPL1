#ifndef BOX_H
#define BOX_H

#include "Pasajero.h"

class Box {
private:
    int id_box;
    bool ocupado;
    Pasajero pasajero;

public:
    Box();
    Box(int id_box, bool ocupado);
    ~Box();

    Pasajero& getPasajero();
    void setPasajero(Pasajero& pasajero);
    int getIdBox();
    bool esVacio();
    void limpiarPasajero();
};

#endif

