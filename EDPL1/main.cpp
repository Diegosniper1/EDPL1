#include <iostream>
#include "Pila.h"
#include "Aeropuerto.h"
#include "Box.h"
#include <vector>
#include <map>
#include <ejecutarMenu1>
#include <ejecutarMenu2>

using namespace std;

int main()
{
    Aeropuerto aeropuerto;
    Pila pila = aeropuerto.getPila();
    Cola cola = aeropuerto.getCola();
    Lista lista = aeropuerto.getLista();
    //Pila pila;
    Box b1(1,false);
    Box b2(2,false);
    Box b3(3,false);

    aeropuerto.setBoxes(b1,b2,b3);
    int opcion;
    do {
        cout << "\n=== SISTEMA DE CONTROL DE ADUANAS ===" << endl;
        cout << "1. Simulación básica" << endl;
        cout << "2. Simulación con boxes dinámicos" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                ejecutarMenu1();
                break;
            case 2:
                ejecutarMenu2());
                break;
            case 3:
                cout << "Programa finalizado." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    } while(opcion != 3);




    void ejecutarMenu1(){

        cout << "           *** MENU ***" << endl;
        cout << "1: Crear pila de pasajeros." << endl;
        cout << "2: Mostrar los pasajeros." << endl;
        cout << "3: Borrar la pila de pasajeros" << endl;
        cout << "4: Mostrar la cola de espera" << endl;
        cout << "5: Mostrar los pasajeros atendidos en cada box" << endl;
        cout << "6: Simulacro en N minutos" << endl;
        cout << "7: Simulacro total" << endl;
        cout << "8: Salir" << endl;

        int a;
        int m = 0;

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
                        while (!pila.esVacia() && t == pila.getCima()->getPasajero().getHoraInicio()) {
                            Pasajero pasajero = pila.getCima()->getPasajero();
                            cout << "Minuto " << t << ": Llegada del pasajero ID=" << pasajero.getId()
                                 << " desde " << pasajero.getDestino() << endl;
                            cola.encolar(pasajero);
                            pila.desapilar();
                        }

                        // Procesar boxes
                        for (int i = 0; i < 3; i++) {
                            Box& box = aeropuerto.getBoxes()[i];

                            // Si el box está ocupado, procesar el pasajero actual
                            if (!box.esVacio()) {
                                if (box.getPasajero().getDuracion() == 0) {
                                    cout << "Minuto " << t << ": Sale pasajero ID=" << box.getPasajero().getId()
                                         << " del box " << box.getIdBox() << endl;
                                    box.limpiarPasajero();

                                    // Intentar asignar nuevo pasajero del queue
                                    if (!cola.es_vacia()) {
                                        Pasajero nuevo = cola.desencolar();
                                        box.setPasajero(nuevo);
                                        cout << "Minuto " << t << ": Entra pasajero ID=" << nuevo.getId()
                                             << " al box " << box.getIdBox() << endl;
                                    }
                                } else {
                                    box.getPasajero().disminuirDuracion();
                                }
                            }
                            // Si el box está vacío y hay pasajeros en cola
                            else if (!cola.es_vacia()) {
                                Pasajero nuevo = cola.desencolar();
                                box.setPasajero(nuevo);
                                cout << "Minuto " << t << ": Entra pasajero ID=" << nuevo.getId()
                                     << " al box " << box.getIdBox() << endl;
                            }
                        }

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
                    map<int, int> tiempos_llegada; // Para registrar cuando llega cada pasajero

                    while (!pila.esVacia() || !cola.es_vacia() ||
                           !aeropuerto.getBoxes()[0].esVacio() ||
                           !aeropuerto.getBoxes()[1].esVacio() ||
                           !aeropuerto.getBoxes()[2].esVacio()) {

                        // Registrar llegadas
                        while (!pila.esVacia() && tiempo_actual >= pila.getCima()->getPasajero().getHoraInicio()) {
                            Pasajero pasajero = pila.getCima()->getPasajero();
                            tiempos_llegada[pasajero.getId()] = tiempo_actual;
                            cout << "Minuto " << tiempo_actual << ": Llegada del pasajero ID=" << pasajero.getId() << endl;
                            cola.encolar(pasajero);
                            pila.desapilar();
                        }

                        // Procesar boxes
                        for (int i = 0; i < 3; i++) {
                            Box& box = aeropuerto.getBoxes()[i];
                            if (!box.esVacio()) {
                                if (box.getPasajero().getDuracion() == 0) {
                                    int id_pasajero = box.getPasajero().getId();
                                    int tiempo_estancia = tiempo_actual - tiempos_llegada[id_pasajero];
                                    tiempo_total += tiempo_estancia;
                                    pasajeros_atendidos++;

                                    cout << "Minuto " << tiempo_actual << ": Sale pasajero ID=" << id_pasajero
                                         << " del box " << box.getIdBox()
                                         << " (Tiempo de estancia: " << tiempo_estancia << " minutos)" << endl;

                                    box.limpiarPasajero();

                                    if (!cola.es_vacia()) {
                                        Pasajero nuevo = cola.desencolar();
                                        box.setPasajero(nuevo);
                                    }
                                } else {
                                    box.getPasajero().disminuirDuracion();
                                }
                            } else if (!cola.es_vacia()) {
                                Pasajero nuevo = cola.desencolar();
                                box.setPasajero(nuevo);
                            }
                        }

                        tiempo_actual++;
                    }

                    if (pasajeros_atendidos > 0) {
                        double tiempo_medio = (double)tiempo_total / pasajeros_atendidos;
                        cout << "\nSimulación completada:" << endl;
                        cout << "Tiempo total acumulado: " << tiempo_total << " minutos" << endl;
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
        }



void ejecutarMenu2(){


    ///Parte 2

    cout << "           *** MENU ***" << endl;
    cout << "1: Crear pila de pasajeros." << endl;
    cout << "2: Mostrar los pasajeros." << endl;
    cout << "3: Borrar la pila de pasajeros" << endl;
    cout << "4: Simulacro en N minutos" << endl;
    cout << "5: Mostrar los datos de la lista de boxes" << endl;
    cout << "6: Consultar box mas ocupado y box menos ocupado" << endl;
    cout << "7: Consultar el número de boxes operativos" << endl;
    cout << "8: Simulacro" << endl;
    cout << "9: Salir" << endl;

    do {
        cout << "Elija una opcion: " << endl;
        cin >> b;


        switch (b) {
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
                int minutos;
                cout << "Introduzca los minutos: ";
                cin >> minutos;

                for (int actual = 0; actual <= minutos; actual++) {
                    cout << "Minuto " << actual << ":" << endl;

                // Procesar nuevas llegadas desde la pila
                while (!pila.esVacia() && pila.getCima().getHoraLlegada() == actual) {
                    Pasajero nuevo = pila.desapilar();
                    lista.nuevoBox();
                // Buscar box con menor cola
                NodoLista* boxMenorCola = primero;
                NodoLista* aux = primero;

                    while (aux != nullptr) {
                        if (aux->box.getTotalPasajeros() < boxMenorCola->box.getTotalPasajeros()) {
                            boxMenorCola = aux;
                        }
                aux = aux->siguiente;
            }

            // Asignar pasajero al box
            if (boxMenorCola->getBox().esVacio() && boxMenorCola->getBox().cola.es_vacia()) {
                boxMenorCola->getBox().setPasajero(nuevo);
                cout << "LLEGADA - Pasajero " << nuevo.getId() << " entra al Box " << boxMenorCola->getBox().getIdBox() << endl;
            } else {
                boxMenorCola.getBox().getCola().encolar(nuevo);
                cout << "LLEGADA - Pasajero " << nuevo.getId() << " entra a la cola del Box " << boxMenorCola->getBox().getIdBox() << endl;
            }

            lista.mostrarBoxes();
        }

        // Procesar atenciones en curso
        NodoLista* aux = lista.getPrimero();
        while (aux != nullptr) {
            if (!aux->getBox().esVacio()) {
                aux->getBox().getPasajero().disminuirDuracion();

                if (aux->getBox().getPasajero().getDuracion() == 0) {
                    Pasajero sale = aux->getBox().getPasajero();
                    cout << "\nSALIDA - Pasajero " << sale.getId() << " sale del Box " << aux->box.getIdBox() << endl;

                    if (aux->getBox().getCola().get_longitud() > 0) {
                        Pasajero siguiente = aux->getBox().getCola().desencolar();
                        aux->getBox().setPasajero(siguiente);
                        cout << "ENTRADA - Pasajero " << siguiente.getId() << " entra al Box " << aux->getBox().getIdBox() << endl;
                    }

                    lista.mostrarBoxes();
                }
            }
            aux = aux->siguiente;
        }

        lista.borrarBoxes();
        }

        break;
        }

             case 5: {
                lista.mostrarBoxes();
                break;
            }

             case 6: {
                cout << "El box con menos pasajero es el box con Id:" << lista.boxMenosOcupado() << endl;
                cout << "El box con mas pasajero es el box con Id:" << lista.boxMasOcupado() << endl;
                break;
            }

             case 7: {
                cout << "El numero de boxes operativos es:" << lista.getBoxesOperativos() << endl;
                break;
            }

             case 8: {
                int tiempoTotal = 0;
                int pasajerosProcesados = 0;
                bool hayPasajeros = true;

                while (hayPasajeros) {
                    cout << "\n=== Minuto " << tiempoTotal << ":" << endl;
                    // Procesar nuevas llegadas desde la pila
                    while (!pila.esVacia() && pila.getCima().getHoraLlegada() == actual) {
                        Pasajero nuevo = pila.desapilar();
                        lista.nuevoBox();
                        // Buscar box con menor cola
                        NodoLista* boxMenorCola = primero;
                        NodoLista* aux = primero;

                        while (aux != nullptr) {
                            if (aux->getBox().getTotalPasajeros() < boxMenorCola->getBox().getTotalPasajeros()) {
                                boxMenorCola = aux;
                            }
                            aux = aux->siguiente;
                        }

                        // Asignar pasajero al box
                        if (boxMenorCola->getBox().esVacio() && boxMenorCola->getBox().getCola().es_vacia()) {
                            boxMenorCola->getBox().setPasajero(nuevo);
                            cout << "LLEGADA - Pasajero " << nuevo.getId() << " entra al Box " << boxMenorCola->getBox().getIdBox() << endl;
                        } else {
                            boxMenorCola.getBox().getCola().encolar(nuevo);
                            cout << "LLEGADA - Pasajero " << nuevo.getId() << " entra a la cola del Box " << boxMenorCola->getBox().getIdBox() << endl;
                        }

                        lista.mostrarBoxes();
                    }

                    // Procesar boxes actuales
                    NodoLista* aux = primero;
                    if (aeropuerto.getPila().esVacia()){
                    hayPasajeros = false; // Asumimos que no hay pasajeros hasta que encontremos uno
                    }
                    while (aux != nullptr) {
                        // Verificar si hay pasajeros en el sistema
                        if (!aux->getBox().esVacio() || aux->getBox().getCola().get_longitud() > 0) {
                        hayPasajeros = true;
                        }

                        if (!aux->getBox().esVacio()) {
                            aux->getBox().getPasajero().disminuirDuracion();

                            if (aux->getBox().getPasajero().getDuracion() == 0) {
                                Pasajero sale = aux->getBox().getPasajero();
                                pasajerosProcesados++;

                                // Calcular tiempo total de estancia
                                int tiempoEstancia = tiempoTotal - sale.getHoraLlegada();

                                cout << "\nSALIDA - Pasajero " << sale.getId() << " sale del Box " << aux->getBox().getIdBox() << " (Tiempo total en sistema: " << tiempoEstancia << " minutos)" << endl;

                                // Atender siguiente de la cola si existe
                                if (aux->getBox().getCola().get_longitud() > 0) {
                                    Pasajero siguiente = aux->getBox().getCola().desencolar();
                                    aux->getBox().setPasajero(siguientePasajero);
                                    cout << "ENTRADA - Pasajero " << siguiente.getId() << " entra al Box " << aux->getBox().getId() << endl;
                                }

                                lista.mostrarBoxes();
                            }
                        }
                        aux = aux->getSiguiente();
                 }


                    lista.borrarBoxes(); // Eliminar boxes vacíos si hay más de dos vacios
                }

                // Mostrar estadísticas finales
                double tiempoMedioEstancia = pasajerosProcesados > 0 ? static_cast<double>(tiempoTotal) / pasajerosProcesados : 0;

                cout << "\n=== Estadísticas Finales ===" << endl;
                cout << "Tiempo total de simulación: " << tiempoTotal << " minutos" << endl;
                cout << "Pasajeros procesados: " << pasajerosProcesados << endl;
                cout << "Tiempo medio de estancia: " << tiempoMedioEstancia << " minutos" << endl;

                tiempoTotal++;
            }

                break;
            }

             case 9: {
                cout << "Fin" << endl;
                break;
            }

            default: {
                 cout << "No ha seleccionado una opcion, intentelo de nuevo: " << endl;
            }
    }

}

    return 0;
}








