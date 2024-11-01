#ifndef BOX_H
#define BOX_H
#include"Pasajero.h"


class Box
{
    public:
        Box();
        Box(int id_box, bool ocupado);
        virtual ~Box();
        Pasajero getPasajero();
        void setPasajero(Pasajero p);
        int getIdBox();
        bool esVacio();

      protected:

    private:
        int id_box;
        Pasajero pasajero;
        friend class Aeropuerto;
        bool ocupado;

};

#endif // BOX_H
