#include <iostream>
#include "Pila.h"
#include "Aeropuerto.h"
#include "Box.h"
#include <vector>

using namespace std;

int main()
{
    //Pila pila;
    Box b1(1,false);
    Box b2(2,false);
    Box b3(3,false);

    Aeropuerto aeropuerto;
    Pila pila = aeropuerto.getPila();
    Cola cola = aeropuerto.getCola();
    aeropuerto.setBoxes(b1,b2,b3);

    int a;
    int m = 0;
    ///int tiempoTotal = 0;
    ///int numPasajerosAtendidos = 0;

    cout << "           *** MENU ***" << endl;
    cout << "1: Crear pila de pasajeros." << endl;
    cout << "2: Mostrar los pasajeros." << endl;
    cout << "3: Borrar la pila de pasajeros" << endl;
    cout << "4: Mostrar la cola de espera" << endl;
    cout << "5: Mostrar los pasajeros atendidos en cada box" << endl;
    cout << "6: Simulacro en N minutos" << endl;
    cout << "7: Simulacro total" << endl;
    cout << "8: Salir" << endl;

    do {
        cout << "Elija una opcion: " << endl;
        cin >> a;
        switch (a) {
            case 1: {
                pila  = aeropuerto.crear_pila();
                cout << "Pila de pasajeros creada con exito." << endl;
                break;
            }
            case 2: {
                aeropuerto.mostrar_pila_entera(pila);
                break;
            }
            case 3: {
                aeropuerto.borrar_pila(pila);
                cout << "Pila borrada con exito." << endl;
                break;
            }
            case 4: {

                while (!pila.esVacia()) {
                    Pasajero pasajero = pila.getCima()->getPasajero(); // Solo de prueba
                    cola.encolar(pasajero);
                    pila.desapilar();
                    }

                aeropuerto.mostrar_cola(cola);
                break;
            }
            case 5: {
                aeropuerto.mostrar_boxes();
                break;
            }


            case 6: {
                cout << "Introduce los minutos" << endl;
                cin >> m;
                for(int t = 0; t <= m; t++){
                    if (t == pila.getCima()->getPasajero().getHoraInicio()){
                        cout << "Minuto" << m << ":" << endl;

                        cout << "Ha llegado un pasajero al aeropuerto:" << endl;
                        cout << "Id:" << pila.getCima()->getPasajero().getId() << endl;
                        Pasajero primero = pila.getCima()->getPasajero();
                        cola.encolar(primero); // encolamos en la cola de espera
                        pila.desapilar();
                    }


                    if (!aeropuerto.getBox(0).esVacio())
                    {
                        aeropuerto.getBoxes()[0].getPasajero().disminuirDuracion();
                    }
                    else{
                        if (!cola.es_vacia()){
                            aeropuerto.getBoxes()[0].getPasajero() = cola.desencolar();
                            }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[0].getIdBox() << ", no esta  en funcionamiento" << endl;
                        }
                    }
                    if (!aeropuerto.getBox(1).esVacio())
                    {
                        aeropuerto.getBoxes()[1].getPasajero().disminuirDuracion();
                    }
                    else{
                        if (!cola.es_vacia()){
                            aeropuerto.getBoxes()[1].getPasajero() = cola.desencolar();
                            }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[1].getIdBox() << ", no esta  en funcionamiento" << endl;
                        }
                    }
                    if (!aeropuerto.getBox(1).esVacio())
                    {
                    aeropuerto.getBoxes()[2].getPasajero().disminuirDuracion();
                    }
                    else{
                        if (!cola.es_vacia()){
                            aeropuerto.getBoxes()[2].getPasajero() = cola.desencolar();
                            }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[2].getIdBox() << ", no esta  en funcionamiento" << endl;
                        }
                    }


                    if (aeropuerto.getBoxes()[0].getPasajero().getDuracion() == 0)
                    {
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.getBoxes()[0].getPasajero().getId() <<  ", del box con identificador:" << aeropuerto.getBoxes()[0].getIdBox() << endl;
                        if (!cola.es_vacia()){
                            aeropuerto.getBoxes()[0].getPasajero() = cola.desencolar();
                            cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.getBoxes()[0].getPasajero().getId() <<  ", al box con identificador:" << aeropuerto.getBoxes()[0].getIdBox() << endl;
                            cout << "El box con Id:" << aeropuerto.getBoxes()[0].getIdBox() << ", está  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[0].getIdBox() << ", no esta  en funcionamiento" << endl;
                        }
                    }

                    if (aeropuerto.getBoxes()[1].getPasajero().getDuracion() == 0)
                    {
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.getBoxes()[1].getPasajero().getId() <<  ", del box con identificador:" << aeropuerto.getBoxes()[1].getIdBox() << endl;
                        if (!cola.es_vacia()){
                            aeropuerto.getBoxes()[1].getPasajero() = cola.desencolar();
                            cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.getBoxes()[1].getPasajero().getId() <<  ", al box con identificador:" << aeropuerto.getBoxes()[1].getIdBox() << endl;
                            cout << "El box con Id:" << aeropuerto.getBoxes()[1].getIdBox() << ", está  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[0].getIdBox() << ", no esta  en funcionamiento" << endl;
                        }
                    }

                    if (aeropuerto.getBoxes()[2].getPasajero().getDuracion() == 0)
                    {
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.getBoxes()[2].getPasajero().getId() <<  ", del box con identificador:" << aeropuerto.getBoxes()[2].getIdBox() << endl;
                        if (!cola.es_vacia()){
                            aeropuerto.getBoxes()[2].getPasajero() = cola.desencolar();
                            cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.getBoxes()[2].getPasajero().getId() <<  ", al box con identificador:" << aeropuerto.getBoxes()[2].getIdBox() << endl;
                            cout << "El box con Id:" << aeropuerto.getBoxes()[2].getIdBox() << ", esta  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[2].getIdBox() << ", no esta  en funcionamiento" << endl;
                        }
                    }
                }
		break;
         }


            case 7: {
                int tiempo_box1 = 0;
                int tiempo_box2 = 0;
                int tiempo_box3 = 0;
                double tiempo_medio = 0;
                while (!pila.esVacia() && !cola.es_vacia() && aeropuerto.getBox(0).esVacio() && aeropuerto.getBox(1).esVacio() && aeropuerto.getBox(2).esVacio()) {


                    if (m == pila.getCima()->getPasajero().getHoraInicio()){

                        cout << "Minuto" << m << ":" << endl;
                        cout << "Ha llegado un pasajero al aeropuerto:" << endl;
                        cout << "Id:" << pila.getCima()->getPasajero().getId() << endl;
                        Pasajero pasajero = pila.getCima()->getPasajero();

                        cola.encolar(pasajero);
                        pila.desapilar();
                    }


                    if (!aeropuerto.getBox(0).esVacio()){
                        aeropuerto.getBoxes()[0].getPasajero().disminuirDuracion();
                        tiempo_box1++;
                    }
                    else{
                        if (!cola.es_vacia()){
                            aeropuerto.getBoxes()[0].getPasajero() = cola.desencolar();
                            }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[0].getIdBox() << ", no esta  en funcionamiento" << endl;
                        }
                    }


                    if (!aeropuerto.getBox(1).esVacio()){
                        aeropuerto.getBoxes()[1].getPasajero().disminuirDuracion();
                        tiempo_box2++;
                    }
                    else{
                        if (!cola.es_vacia()){
                            aeropuerto.getBoxes()[1].getPasajero() = cola.desencolar();
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[1].getIdBox() << ", no esta  en funcionamiento" << endl;
                        }
                    }

                     if (!aeropuerto.getBox(2).esVacio()){
                        aeropuerto.getBoxes()[2].getPasajero().disminuirDuracion();
                        tiempo_box3++;
                    }
                    else{
                        if (!cola.es_vacia()){
                            aeropuerto.getBoxes()[2].getPasajero() = cola.desencolar();
                            }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[2].getIdBox() << ", no esta  en funcionamiento" << endl;
                        }
                    }





                    if (aeropuerto.getBoxes()[0].getPasajero().getDuracion() == 0){
                        tiempo_medio = tiempo_medio + tiempo_box1;
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.getBoxes()[0].getPasajero().getId() <<  ", del box con identificador:" << aeropuerto.getBoxes()[0].getIdBox() << endl;
                        if (!cola.es_vacia()){
                            aeropuerto.getBoxes()[0].getPasajero() = cola.desencolar();
                            cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.getBoxes()[0].getPasajero().getId() <<  ", al box con identificador:" << aeropuerto.getBoxes()[0].getIdBox() << endl;
                            cout << "El box con Id:" << aeropuerto.getBoxes()[0].getIdBox() << ", esta  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[0].getIdBox() << ", no esta  en funcionamiento" << endl;
                        }
                    }


                    if (aeropuerto.getBoxes()[1].getPasajero().getDuracion() == 0){
                        tiempo_medio = tiempo_medio + tiempo_box2;
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.getBoxes()[1].getPasajero().getId() <<  ", del box con identificador:" << aeropuerto.getBoxes()[1].getIdBox() << endl;
                        if (!cola.es_vacia()){
                            aeropuerto.getBoxes()[1].getPasajero() = cola.desencolar();
                            cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.getBoxes()[0].getPasajero().getId() <<  ", al box con identificador:" << aeropuerto.getBoxes()[0].getIdBox() << endl;
                            cout << "El box con Id:" << aeropuerto.getBoxes()[1].getIdBox() << ", esta  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[1].getIdBox() << ", no esta  en funcionamiento" << endl;
                        }
                    }


                    if (aeropuerto.getBoxes()[2].getPasajero().getDuracion() == 0){
                        tiempo_medio = tiempo_medio + tiempo_box3;
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.getBoxes()[2].getPasajero().getId() <<  ", del box con identificador:" << aeropuerto.getBoxes()[2].getIdBox() << endl;
                        if (!cola.es_vacia()){
                            aeropuerto.getBoxes()[2].getPasajero() = cola.desencolar();
                            cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.getBoxes()[0].getPasajero().getId() <<  ", al box con identificador:" << aeropuerto.getBoxes()[0].getIdBox() << endl;
                            cout << "El box con Id:" << aeropuerto.getBoxes()[2].getIdBox() << ", está  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[2].getIdBox() << ", no está  en funcionamiento" << endl;
                        }
                    }
                    cout << "El tiempo medio que están los pasajeros en los boxes es:" << tiempo_medio << "minutos" << endl;
                    m++;
                }
		break;
        }


            case 8: {
                cout << "Fin" << endl;
                break;
            }
            default: {
                cout << "No ha seleccionado una opción, inténtelo de nuevo: " << endl;
            }
        }
    } while (a != 8);

    return 0;
}

