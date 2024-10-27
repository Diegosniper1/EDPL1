#ifndef PASAJERO_H
#define PASAJERO_H

#include"Pasajero.h"

#include <string>


using namespace std;

class Pasajero
{
    public:
        Pasajero();
        Pasajero(int id, int prioridad, string destino, int hora_inicio, int duracion);
        virtual ~Pasajero();
        Pasajero getPrioridad();

    protected:

    private:
        int id, prioridad, hora_inicio, duracion, id_box;
        string destino;
        friend class Box;

};

#endif // PASAJERO_H
