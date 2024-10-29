#ifndef BOX_H
#define BOX_H
#include"Pasajero.h"


class Box
{
    public:
        Box();
        Box(int id_box);
        virtual ~Box();
        Pasajero getPasajero();
        int getIdBox();
        bool esVacio();

      protected:

    private:
        int id_box;
        Pasajero pasajero;
        friend class Aeropuerto;

};

#endif // BOX_H
