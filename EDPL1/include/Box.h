#ifndef BOX_H
#define BOX_H


class Box
{
    public:
        Box();
        virtual ~Box();

    protected:

    private:
        int id_box;
        Pasajero pasajero;
        friend class Aeropuerto;

};

#endif // BOX_H
