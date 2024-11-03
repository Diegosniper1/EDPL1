#ifndef BOX_H
#define BOX_H
#include "Cola.h"
#include "Pasajero.h"

class Box {
private:
    int id_box;
    bool ocupado;
    Pasajero pasajero;
    Cola cola;

public:
    Box();
    Box(int id_box, bool ocupado);
    ~Box();

    Pasajero& getPasajero();
    void setPasajero(Pasajero& pasajero);
    int getIdBox();
    bool esVacio();
    void limpiarPasajero();
    int setIdBox(int idBox);
    int getTotalPasajeros();
    Cola& getCola();
    void encolarPasajero(Pasajero& p);
    bool tienePasajerosEnCola();
};

#endif


