#include <iostream>
#include "Pila.h"
#include "Aeropuerto.h"
#include "Box.h"
#include "ABBPasajeros.h"
#include <vector>
#include <map>

using namespace std;

// Declaración de funciones
void ejecutarMenu1(Aeropuerto& aeropuerto, Pila& pila, Cola& cola);
void ejecutarMenu2(Aeropuerto& aeropuerto, Pila& pila, Lista& lista);

int main() {
    Aeropuerto aeropuerto;
    Pila pila = aeropuerto.getPila();
    Cola cola = aeropuerto.getCola();
    Lista lista = aeropuerto.getLista();
    ABBPasajeros abb = aeropuerto.getABBPasajeros();

    Box b1(1,false);
    Box b2(2,false);
    Box b3(3,false);
    aeropuerto.setBoxes(b1,b2,b3);

    int opcion;
    do {
        cout << "\n=== SISTEMA DE CONTROL DE ADUANAS ===" << endl;
        cout << "1. Simulacion basica" << endl;
        cout << "2. Simulacion con boxes dinamicos" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                ejecutarMenu1(aeropuerto, pila, cola);
                break;
            case 2:
                ejecutarMenu2(aeropuerto, pila, lista, abb);
                break;
            case 3:
                cout << "Programa finalizado." << endl;
                break;
            default:
                cout << "Opcion no válida." << endl;
        }
    } while(opcion != 3);

    return 0;
}




void ejecutarMenu1(Aeropuerto& aeropuerto, Pila& pila, Cola& cola){

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

                                    // Intentar asignar nuevo pasajero de la cola
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
                    const int MAX_PASAJEROS = 10;
                    int tiempos_llegada[MAX_PASAJEROS] = {0};
                    int tiempo_total = 0;
                    int pasajeros_atendidos = 0;
                    int tiempo_actual = 0;

                    while (!pila.esVacia() || !cola.es_vacia() ||
                           !aeropuerto.getBoxes()[0].esVacio() ||
                           !aeropuerto.getBoxes()[1].esVacio() ||
                           !aeropuerto.getBoxes()[2].esVacio()) {

                        // Registrar llegadas
                        while (!pila.esVacia() && tiempo_actual >= pila.getCima()->getPasajero().getHoraInicio()) {
                            Pasajero pasajero = pila.getCima()->getPasajero();
                            tiempos_llegada[pasajero.getId()] = pasajero.getHoraInicio(); // Usar hora_inicio en lugar de tiempo_actual
                            cout << "Minuto " << tiempo_actual << ": Llegada del pasajero ID="
                                 << pasajero.getId() << endl;
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

                                    cout << "Minuto " << tiempo_actual << ": Sale pasajero ID="
                                         << id_pasajero << " del box " << box.getIdBox()
                                         << " (Tiempo de estancia: " << tiempo_estancia << " minutos)" << endl;

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
                                Pasajero nuevo = cola.desencolar();
                                box.setPasajero(nuevo);
                                cout << "Minuto " << tiempo_actual << ": Entra pasajero ID="
                                     << nuevo.getId() << " al box " << box.getIdBox() << endl;
                            }
                        }

                        cout << "\nEstado de los boxes en minuto " << tiempo_actual << ":" << endl;
                        aeropuerto.mostrar_boxes();
                        cout << endl;

                        tiempo_actual++;
                    }

                    cout << "\nSimulacion completada:" << endl;
                    cout << "Tiempo total acumulado: " << tiempo_total << " minutos" << endl;
                    cout << "Pasajeros atendidos: " << pasajeros_atendidos << endl;
                    cout << "Tiempo medio de estancia: " << (double)tiempo_total / 9 << " minutos" << endl;
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



void ejecutarMenu2(Aeropuerto& aeropuerto, Pila& pila, Lista& lista, ABBPasajeros& abb){


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
    cout << "9: Añadir un pasajero directamente al Arbol Binario de Busqueda, leyendo sus datos de teclado" << endl;
    cout << "10: Mostrar los datos almacenados en el Arbol Binario de Busqueda, ordenados por nombre de pais" << endl;
    cout << "11: Mostrar los pasajeros con destino a un pais dado" << endl;
    cout << "12: Mostrar los nombres de todos los paises que han sido destino de al menos un pasajero, en orden alfabetico" << endl;
    cout << "13: Mostrar el pais destino de mayor numero de pasajeros y el de menor numero" << endl;
    cout << "14: Mostrar el tiempo medio de estancia en el aeropuerto de los pasajeros con destino a un pais dado" << endl;
    cout << "15: Mostrar el tiempo medio de estancia en el aeropuerto de los pasajeros con destino a cada uno de los paises (preorden)" << endl;
    cout << "16: Salir" << endl;

    int b;
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
                while (!pila.esVacia() && pila.getCima()->getPasajero().getHoraInicio() == actual) {
                    Pasajero nuevo = pila.getCima()->getPasajero();
                    pila.desapilar();
                    lista.nuevoBox();
                // Buscar box con menor cola
                NodoLista* boxMenorCola = lista.getPrimero();
                NodoLista* aux = lista.getPrimero();

                    while (aux != nullptr) {
                        if (aux->getBox().getTotalPasajeros() < boxMenorCola->getBox().getTotalPasajeros()) {
                            boxMenorCola = aux;
                        }
                        aux = aux->getSiguiente();
                    }

            // Asignar pasajero al box
            if (boxMenorCola->getBox().esVacio() && boxMenorCola->getBox().getCola().es_vacia()) {
                boxMenorCola->getBox().setPasajero(nuevo);
                cout << "LLEGADA - Pasajero " << nuevo.getId() << " entra al Box " << boxMenorCola->getBox().getIdBox() << endl;
            } else {
                boxMenorCola->getBox().getCola().encolar(nuevo);
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
                    cout << "\nSALIDA - Pasajero " << sale.getId() << " sale del Box " << aux->getBox().getIdBox() << endl;
                    int tiempoEst =  actual - sale.getHoraInicio();
                    sale.setTiempoEstancia(tiempoEst);
                    abb.insertar(abb.raiz, sale.destino, sale)



                    if (aux->getBox().getCola().get_longitud() > 0) {
                        Pasajero siguiente = aux->getBox().getCola().desencolar();
                        aux->getBox().setPasajero(siguiente);
                        cout << "ENTRADA - Pasajero " << siguiente.getId() << " entra al Box " << aux->getBox().getIdBox() << endl;
                    }

                    lista.mostrarBoxes();
                }
            }
            aux = aux->getSiguiente();
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
    lista.nuevoBox();
    lista.getPrimero()->getBox().setIdBox(1);

    int tiempoTotal = 0;
    int pasajerosProcesados = 0;
    int tiempoEstanciaTotal = 0;

    while (!pila.esVacia() || lista.hayPasajerosEnSistema()) {
        cout << "\n=== Minuto " << tiempoTotal << ":" << endl;

        // Prrocesar llegadas
        while (!pila.esVacia() && pila.getCima()->getPasajero().getHoraInicio() == tiempoTotal) {
            Pasajero nuevo = pila.getCima()->getPasajero();
            cout << "LLEGADA - Pasajero " << nuevo.getId() << " al sistema" << endl;


            if (lista.getPrimero()->getBox().getTotalPasajeros() > 2) {
                lista.nuevoBox();
            }

            // Encontrar box menos ocupado
            NodoLista* boxMenorCola = lista.getPrimero();
            NodoLista* aux = lista.getPrimero();
            while (aux != nullptr) {
                if (aux->getBox().getTotalPasajeros() < boxMenorCola->getBox().getTotalPasajeros()) {
                    boxMenorCola = aux;
                }
                aux = aux->getSiguiente();
            }

            // Meter pasajero en box
            if (boxMenorCola->getBox().esVacio()) {
                boxMenorCola->getBox().setPasajero(nuevo);
                cout << "Pasajero " << nuevo.getId() << " asignado al Box "
                     << boxMenorCola->getBox().getIdBox() << endl;
            } else {
                boxMenorCola->getBox().encolarPasajero(nuevo);
                cout << "Pasajero " << nuevo.getId() << " en cola del Box "
                     << boxMenorCola->getBox().getIdBox() << endl;
            }

            pila.desapilar();
        }

        // Procesar boxes
        NodoLista* aux = lista.getPrimero();
        while (aux != nullptr) {
            Box& boxActual = aux->getBox();

            if (!boxActual.esVacio()) {
                Pasajero& pasajeroActual = boxActual.getPasajero();
                pasajeroActual.disminuirDuracion();

                if (pasajeroActual.getDuracion() == 0) {
                    cout << "SALIDA - Pasajero " << pasajeroActual.getId()
                         << " del Box " << boxActual.getIdBox() << endl;

                    int tiempoEst =  tiempoTotal - pasajeroActual.getHoraInicio();
                    pasajeroActual.setTiempoEstancia(tiempoEst);
                    abb.insertar(abb.raiz, pasajeroActual.destino, pasajeroActual);
                    pasajerosProcesados++;
                    tiempoEstanciaTotal += tiempoEst;

                    if (boxActual.getCola().get_longitud() > 0) {
                        Pasajero siguiente = boxActual.getCola().desencolar();
                        boxActual.setPasajero(siguiente);
                        cout << "ENTRADA - Pasajero " << siguiente.getId()
                             << " al Box " << boxActual.getIdBox() << endl;
                    } else {
                        boxActual.limpiarPasajero();
                    }
                }
            }
            aux = aux->getSiguiente();
        }

        //Comprobamos cada 5 mins si podemos borrar boxes
        lista.mostrarBoxes();
        if (tiempoTotal % 5 == 0) {
            lista.borrarBoxes();
        }

        tiempoTotal++;
    }

    cout << "\n=== Estadisticas Finales ===" << endl;
    cout << "Tiempo total de simulacion: " << tiempoTotal << " minutos" << endl;
    cout << "Pasajeros procesados: " << pasajerosProcesados << endl;
    cout << "Tiempo medio de estancia: " <<
            (pasajerosProcesados > 0 ? tiempoEstanciaTotal/pasajerosProcesados : 0)
         << " minutos" << endl;
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



}while (b != 9);


}








