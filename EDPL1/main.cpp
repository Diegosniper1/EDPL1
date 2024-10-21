#include <iostream>

using namespace std;

int main()
{
    cout << "Creamos la pila Vacía" << endl;

    Pila pila;
    pila.mostrar();ç

    // Creamos la lista de pasajeros

    Pasajero p1 = Pasajero(1,6,"Indonesia",0,20);
    Pasajero p2 = Pasajero(2,1,"Portugal",0,15);
    Pasajero p3 = Pasajero(3,7,"Australia",5,39);
    Pasajero p4 = Pasajero(4,5,"Sudáfrica",7,39);
    Pasajero p5 = Pasajero(5,6,"Indonesia",9,16);
    Pasajero p6 = Pasajero(6,4,"Noruega",11,23);
    Pasajero p7 = Pasajero(7,7,"Australia",14,31);
    Pasajero p8 = Pasajero(8,2,"Italia",18,14);
    Pasajero p9 = Pasajero(9,3,"Alemania",21,20);


    //Apilamos los pasajeroa

    pila.apilar(p9);
    pila.apilar(p8);
    pila.apilar(p7);
    pila.apilar(p6);
    pila.apilar(p5);
    pila.apilar(p4);
    pila.apilar(p3);
    pila.apilar(p2);
    pila.apilar(p1);

    return 0;


    //Hola



    //Mostramos los elementos





}
