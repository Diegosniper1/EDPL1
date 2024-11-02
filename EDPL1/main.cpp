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
                if (pila.esVacia()) {
                    cout << "No hay pasajeros para mostrar. Cree la pila primero." << endl;
                } else {
                    cout << "Lista de pasajeros en el aeropuerto:" << endl;
                    aeropuerto.mostrar_pila_entera(pila);
                }
                break;
            }

            case 3: {
                if (pila.esVacia()) {
                    cout << "La pila ya está vacia." << endl;
                } else {
                    aeropuerto.borrar_pila(pila);
                    cout << "Pila borrada con exito." << endl;
                }
                break;
            }



            case 4: {
                    if (cola.es_vacia()) {
                        cout << "La cola está vacía." << endl;
                    } else {
                        cout << "Cola de espera actual:" << endl;
                        aeropuerto.mostrar_cola(cola);
                    }
                    break;
                }



            case 5: {
                cout << "Estado actual de los boxes:" << endl;
                aeropuerto.mostrar_boxes();
                break;
                }





case 6: {
    cout << "Introduce los minutos a simular: " << endl;
    cin >> m;

    for (int t = 0; t <= m; t++) {
        // Procesar llegadas de pasajeros
        if (!pila.esVacia() && t == pila.getCima()->getPasajero().getHoraInicio()) {
            Pasajero pasajero = pila.getCima()->getPasajero();
            cout << "Minuto " << t << ": Llegada del pasajero ID=" << pasajero.getId() << endl;
            cola.encolar(pasajero);
            pila.desapilar();
        }

        // Procesar boxes
        for (int i = 0; i < 3; i++) {
            Box& box = aeropuerto.getBoxes()[i];
            if (!box.esVacio()) {
                // Procesar pasajero actual
                if (box.getPasajero().disminuirDuracion() == 0) {
                    cout << "Minuto " << t << ": Sale pasajero ID=" << box.getPasajero().getId()
                         << " del box " << box.getIdBox() << endl;
                    box.limpiarPasajero();

                    // Intentar asignar nuevo pasajero
                    if (!cola.es_vacia()) {
                        Pasajero nuevo = cola.desencolar();
                        box.setPasajero(nuevo);
                        cout << "Minuto " << t << ": Entra pasajero ID=" << nuevo.getId()
                             << " al box " << box.getIdBox() << endl;
                    }
                }
            } else if (!cola.es_vacia()) {
                // Box vacío y hay pasajeros en cola
                Pasajero nuevo = cola.desencolar();
                box.setPasajero(nuevo);
                cout << "Minuto " << t << ": Entra pasajero ID=" << nuevo.getId()
                     << " al box " << box.getIdBox() << endl;
            }
        }

        // Mostrar estado de los boxes
        cout << "\nEstado de los boxes en minuto " << t << ":" << endl;
        aeropuerto.mostrar_boxes();
        cout << endl;
    }
    break;
         }

     case 7: {
    int tiempo_total = 0;
    int pasajeros_atendidos = 0;
    int tiempo_actual = 0;
    int max_tiempo = 1000; // Límite de seguridad

    // Primero, asegurarse de que hay pasajeros para procesar
    if (pila.esVacia() && cola.es_vacia() &&
        aeropuerto.getBoxes()[0].esVacio() &&
        aeropuerto.getBoxes()[1].esVacio() &&
        aeropuerto.getBoxes()[2].esVacio()) {
        cout << "No hay pasajeros para procesar." << endl;
        break;
    }

    while ((!pila.esVacia() || !cola.es_vacia() ||
            !aeropuerto.getBoxes()[0].esVacio() ||
            !aeropuerto.getBoxes()[1].esVacio() ||
            !aeropuerto.getBoxes()[2].esVacio()) &&
           tiempo_actual < max_tiempo) {

        bool hubo_cambios = false;

        // Procesar llegadas
        if (!pila.esVacia() && tiempo_actual >= pila.getCima()->getPasajero().getHoraInicio()) {
            hubo_cambios = true;
            Pasajero pasajero = pila.getCima()->getPasajero();
            cout << "Minuto " << tiempo_actual << ": Llegada del pasajero ID=" << pasajero.getId() << endl;
            cola.encolar(pasajero);
            pila.desapilar();
        }

        // Procesar boxes
        for (int i = 0; i < 3; i++) {
            Box& box = aeropuerto.getBoxes()[i];
            if (!box.esVacio()) {
                hubo_cambios = true;
                if (box.getPasajero().getDuracion() == 0) {
                    pasajeros_atendidos++;
                    cout << "Minuto " << tiempo_actual << ": Sale pasajero ID="
                         << box.getPasajero().getId() << " del box " << box.getIdBox() << endl;
                    box.limpiarPasajero();

                    if (!cola.es_vacia()) {
                        Pasajero nuevo = cola.desencolar();
                        box.setPasajero(nuevo);
                        cout << "Minuto " << tiempo_actual << ": Entra pasajero ID="
                             << nuevo.getId() << " al box " << box.getIdBox() << endl;
                    }
                } else {
                    box.getPasajero().disminuirDuracion();
                }
            } else if (!cola.es_vacia()) {
                hubo_cambios = true;
                Pasajero nuevo = cola.desencolar();
                box.setPasajero(nuevo);
                cout << "Minuto " << tiempo_actual << ": Entra pasajero ID="
                     << nuevo.getId() << " al box " << box.getIdBox() << endl;
            }
        }

        if (!hubo_cambios) {
            cout << "No hay mas cambios que procesar." << endl;
            break;
        }

        tiempo_actual++;
    }

    if (tiempo_actual >= max_tiempo) {
        cout << "La simulacion se detuvo por exceder el tiempo maximo." << endl;
    }

    if (pasajeros_atendidos > 0) {
        double tiempo_medio = (double)tiempo_total / pasajeros_atendidos;
        cout << "Simulacion completada" << endl;
        cout << "Tiempo total: " << tiempo_actual << " minutos" << endl;
        cout << "Pasajeros atendidos: " << pasajeros_atendidos << endl;
        cout << "Tiempo medio de estancia: " << tiempo_medio << " minutos" << endl;
    }
    break;
}


            case 8: {
                cout << "Fin" << endl;
                break;
            }
            default: {
                cout << "No ha seleccionado una opcion, intentelo de nuevo: " << endl;
            }
        }
    } while (a != 8);

    return 0;
}




