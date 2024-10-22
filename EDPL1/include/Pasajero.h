#ifndef PASAJERO_H
#define PASAJERO_H


class Pasajero
{
    public:
        Pasajero();
        Pasajero(int id, int prioridad, string destino, int hora_inicio, int duracion);
        virtual ~Pasajero();

    protected:

    private:
        int id, id_box, duracion, hora_inicio, prioridad;
        string destino;

};

#endif // PASAJERO_H
