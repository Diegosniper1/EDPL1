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
        int getPrioridad();
        int getHoraInicio();
        int getDuracion();
        int disminuirDuracion();
        int getId();

    protected:

    private:
        int id, prioridad, hora_inicio, duracion, id_box;
        string destino;
        friend class Box;
        friend class Cola;
        friend class Pila;

    friend std::ostream& operator<<(std::ostream& os, const Pasajero& p);

};

#endif // PASAJERO_H
