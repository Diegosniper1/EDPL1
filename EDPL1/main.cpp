#include <iostream>
#include"Pila.h"
#include"Aeropuerto.h"
#include"Box.h"
#include <vector>

using namespace std;

int main()
{
    cout << "Creamos la pila Vacía" << endl;

    Pila pila;
    pila.mostrar();

    // Creamos la lista de pasajeros - apartado 1

    Pasajero p1 = Pasajero(1,6,"Indonesia",0,20);
    Pasajero p2 = Pasajero(2,1,"Portugal",0,15);
    Pasajero p3 = Pasajero(3,7,"Australia",5,39);
    Pasajero p4 = Pasajero(4,5,"Sudáfrica",7,39);
    Pasajero p5 = Pasajero(5,6,"Indonesia",9,16);
    Pasajero p6 = Pasajero(6,4,"Noruega",11,23);
    Pasajero p7 = Pasajero(7,7,"Australia",14,31);
    Pasajero p8 = Pasajero(8,2,"Italia",18,14);
    Pasajero p9 = Pasajero(9,3,"Alemania",21,20);

    //Mostramos los elementos   - apartado 2

    Box b1(1);
    Box b2(2);
    Box b3(3);

Aeropuerto aeropuerto;

aeropuerto.setBoxes(b1, b2, b3);

int a;
int m = 0;

cout << "           *** MENÚ ***"        << endl;
cout << "1: Crear pila de pasajeros." << endl;
cout << "2: Mostrar los pasajeros." << endl;
cout << "3: Borrar la pila de pasajeros" << endl;
cout << "4: Mostrar la cola de espera" << endl;
cout << "5: Mostrar los pasajeros atendidos en cada box" << endl;
cout << "6: Simulacro en N minutos" << endl;
cout << "7: Simulacro total" << endl;
cout << "8: Salir" << endl;
//////////////

do {
      cout<<"Elija una opción: "<<endl;
      cin>>a;
      switch(a) {
         case 1: {
            aeropuerto.crear_pila();
	    cout<<"Pila de pasajeros creada con éxito: "<<endl;
            break;
         }
         case 2: {
	 	aeropuerto.mostrar_pila_entera();
	 	break;
         }
         case 3: {
            	aeropuerto.borrar_pila();
    		cout << "Pila borrada con éxito." << endl;
		break;
         }

	  case 4: {
            	aeropuerto.mostrar_cola();
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
                    if (t == aeropuerto.getPila().getCima()->getPasajero().getHoraInicio()){
                        cout << "Minuto" << m << ":" << endl;

                        cout << "Ha llegado un pasajero al aeropuerto:" << endl;
                        cout << "Id:" << aeropuerto.getPila().getCima()->getPasajero().getId() << endl;
                        aeropuerto.getCola().encolar(aeropuerto.getPila().getCima()->getPasajero());
                        aeropuerto.getPila().desapilar();
                    }
                    if (!aeropuerto.getBox(0).esVacio())
                    {
                        aeropuerto.getBoxes()[0].getPasajero().disminuirDuracion();
                    }
                    else{
                        if (!aeropuerto.getCola().es_vacia()){
                            aeropuerto.getBoxes()[0].getPasajero() = aeropuerto.getCola().desencolar();
                            }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[0].getIdBox() << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (!aeropuerto.getBox(1).esVacio())
                    {
                    aeropuerto.getBoxes()[1].getPasajero().disminuirDuracion();
                    }
                    else{
                        if (!aeropuerto.getCola().es_vacia()){
                            aeropuerto.getBoxes()[1].getPasajero() = aeropuerto.getCola().desencolar();
                            }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[1].getIdBox() << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (!aeropuerto.getBox(1).esVacio())
                    {
                    aeropuerto.getBoxes()[2].getPasajero().disminuirDuracion();
                    }
                    else{
                        if (!aeropuerto.getCola().es_vacia()){
                            aeropuerto.getBoxes()[2].getPasajero() = aeropuerto.getCola().desencolar();
                            }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[2].getIdBox() << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (aeropuerto.getBoxes()[0].getPasajero().getDuracion() == 0)
                    {
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.getBoxes()[0].getPasajero().getId() <<  ", del box con identificador:" << aeropuerto.getBoxes()[0].getIdBox() << endl;
                        if (!aeropuerto.getCola().es_vacia()){
                            aeropuerto.getBoxes()[0].getPasajero() = aeropuerto.getCola().desencolar();
                            cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.getBoxes()[0].getPasajero().getId() <<  ", al box con identificador:" << aeropuerto.getBoxes()[0].getIdBox() << endl;
                            cout << "El box con Id:" << aeropuerto.getBoxes()[0].getIdBox() << ", está  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[0].getIdBox() << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (aeropuerto.getBoxes()[1].getPasajero().getDuracion() == 0)
                    {
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.getBoxes()[1].getPasajero().getId() <<  ", del box con identificador:" << aeropuerto.getBoxes()[1].getIdBox() << endl;
                        if (!aeropuerto.getCola().es_vacia()){
                            aeropuerto.getBoxes()[1].getPasajero() = aeropuerto.getCola().desencolar();
                            cout << "En su lugar ha entrado el pasajero Id ==" << aeropuerto.getBoxes()[1].getPasajero().getId() <<  ", al box con identificador:" << aeropuerto.getBoxes()[1].getIdBox() << endl;
                            cout << "El box con Id:" << aeropuerto.getBoxes()[1].getIdBox() << ", está  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[1].getIdBox() << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (aeropuerto.getBoxes()[2].getPasajero().getDuracion() == 0)
                    {
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.getBoxes()[2].getPasajero().getId() <<  ", del box con identificador:" << aeropuerto.getBoxes()[2].getIdBox() << endl;
                        if (!aeropuerto.getCola().es_vacia()){
                            aeropuerto.getBoxes()[2].getPasajero() = aeropuerto.getCola().desencolar();
                            cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.getBoxes()[2].getPasajero().getId() <<  ", al box con identificador:" << aeropuerto.getBoxes()[2].getIdBox() << endl;
                            cout << "El box con Id:" << aeropuerto.getBoxes()[2].getIdBox() << ", está  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[2].getIdBox() << ", no está  en funcionamiento" << endl;
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
                while (!aeropuerto.getPila().esVacia() && !aeropuerto.getCola().es_vacia() && aeropuerto.getBox(0).esVacio() && aeropuerto.getBox(1).esVacio() && aeropuerto.getBox(1).esVacio()){
                    if (m == aeropuerto.getPila().getCima()->getPasajero().getHoraInicio()){
                        cout << "Minuto" << m << ":" << endl;

                        cout << "Ha llegado un pasajero al aeropuerto:" << endl;
                        cout << "Id:" << aeropuerto.getPila().getCima()->getPasajero().getId() << endl;
                        aeropuerto.getCola().encolar(aeropuerto.getPila().getCima()->getPasajero());
                        aeropuerto.getPila().desapilar();
                    }
                    if (!aeropuerto.getBox(0).esVacio()){
                        aeropuerto.getBoxes()[0].getPasajero().disminuirDuracion();
                        tiempo_box1++;
                    }
                    else{
                        if (!aeropuerto.getCola().es_vacia()){
                            aeropuerto.getBoxes()[0].getPasajero() = aeropuerto.getCola().desencolar();
                            }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[0].getIdBox() << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (!aeropuerto.getBox(1).esVacio()){
                        aeropuerto.getBoxes()[1].getPasajero().disminuirDuracion();
                        tiempo_box2++;
                    }
                    else{
                        if (!aeropuerto.getCola().es_vacia()){
                            aeropuerto.getBoxes()[1].getPasajero() = aeropuerto.getCola().desencolar();
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[1].getIdBox() << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (!aeropuerto.getBox(2).esVacio()){
                        aeropuerto.getBoxes()[2].getPasajero().disminuirDuracion();
                        tiempo_box3++;
                    }
                    else{
                        if (!aeropuerto.getCola().es_vacia()){
                            aeropuerto.getBoxes()[0].getPasajero() = aeropuerto.getCola().desencolar();
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[0].getIdBox() << ", no está  en funcionamiento" << endl;
                        }
                    }

                    if (aeropuerto.getBoxes()[0].getPasajero().getDuracion() == 0){
                        tiempo_medio = tiempo_medio + tiempo_box1;
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.getBoxes()[0].getPasajero().getId() <<  ", del box con identificador:" << aeropuerto.getBoxes()[0].getIdBox() << endl;
                        if (!aeropuerto.getCola().es_vacia()){
                            aeropuerto.getBoxes()[0].getPasajero() = aeropuerto.getCola().desencolar();
                            cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.getBoxes()[0].getPasajero().getId() <<  ", al box con identificador:" << aeropuerto.getBoxes()[0].getIdBox() << endl;
                            cout << "El box con Id:" << aeropuerto.getBoxes()[0].getIdBox() << ", está  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[0].getIdBox() << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (aeropuerto.getBoxes()[1].getPasajero().getDuracion() == 0){
                        tiempo_medio = tiempo_medio + tiempo_box2;
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.getBoxes()[1].getPasajero().getId() <<  ", del box con identificador:" << aeropuerto.getBoxes()[1].getIdBox() << endl;
                        if (!aeropuerto.getCola().es_vacia()){
                            aeropuerto.getBoxes()[1].getPasajero() = aeropuerto.getCola().desencolar();
                            cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.getBoxes()[0].getPasajero().getId() <<  ", al box con identificador:" << aeropuerto.getBoxes()[0].getIdBox() << endl;
                            cout << "El box con Id:" << aeropuerto.getBoxes()[1].getIdBox() << ", está  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.getBoxes()[1].getIdBox() << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (aeropuerto.getBoxes()[2].getPasajero().getDuracion() == 0){
                        tiempo_medio = tiempo_medio + tiempo_box3;
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.getBoxes()[2].getPasajero().getId() <<  ", del box con identificador:" << aeropuerto.getBoxes()[2].getIdBox() << endl;
                        if (!aeropuerto.getCola().es_vacia()){
                            aeropuerto.getBoxes()[2].getPasajero() = aeropuerto.getCola().desencolar();
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
            cout<<"Fin"<<endl;
            break;
         }
    default: {
            cout<<"No ha seleccionado una opción, inténtelo de nuevo: 	"<<endl;
         }
      }
   }while(a!=8);


     return 0;

}
