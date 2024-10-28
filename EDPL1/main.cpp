#include <iostream>
#include"Pila.h"
#include"Aeropuerto.h"
#include"Box.h"

using namespace std; //espacio de nombres

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

aeropuerto.boxes = {b1, b2, b3};

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
                for(t = 0; i <= m; t++){
                    if (t == aeropuerto.pila.cima.pasajero.hora_inicio){
                        cout << "Minuto" << m << ":" << endl;

                        cout << "Ha llegado un pasajero al aeropuerto:" << endl;
                        cout << "Id:" << aeropuerto.pila.cima.pasajero.id << endl;
                        aeropuerto.cola.encolar(aeropuerto.pila.cima.pasajero);
                        aeropuerto.pila.desapilar();
                    }
                    if (aeropuerto.boxes[0].pasajero != NULL)
                    {
                        aeropuerto.boxes[0].pasajero.duracion--;
                    }
                    else{
                        if (!aeropuerto.cola.es_vacia()){
                            aeropuerto.boxes[0].pasajero = aeropuerto.cola.desencolar();
                            }
                        else{
                            cout << "El box con Id:" << aeropuerto.boxes[0].id_box << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (aeropuerto.boxes[1] != NULL)
                    {
                    aeropuerto.boxes[1].pasajero.duracion--;
                    }
                    else{
                        if (!aeropuerto.cola.es_vacia()){
                            aeropuerto.boxes[1].pasajero = aeropuerto.cola.desencolar();
                            }
                        else{
                            cout << "El box con Id:" << aeropuerto.boxes[1].id_box << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (aeropuerto.boxes[2].pasajero != NULL)
                    {
                    aeropuerto.boxes[2].pasajero.duracion--;
                    }
                    else{
                        if (!aeropuerto.cola.es_vacia()){
                            aeropuerto.boxes[2].pasajero = aeropuerto.cola.desencolar();
                            }
                        else{
                            cout << "El box con Id:" << aeropuerto.boxes[2].id_box << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (aeropuerto.boxes[0].pasajero.duracion == 0)
                    {
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.boxes[0].pasajero.id <<  ", del box con identificador:" << aeropuerto.boxes[0].id_box << end;
                        if (!aeropuerto.cola.es_vacia()){
                            aeropuerto.boxes[0].pasajero = aeropuerto.cola.desencolar();
                            cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.boxes[0].pasajero.id <<  ", al box con identificador:" << aeropuerto.boxes[0].id_box << end;
                            cout << "El box con Id:" << aeropuerto.boxes[0].id_box << ", está  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.boxes[0].id_box << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (aeropuerto.boxes[1].pasajero.duracion == 0)
                    {
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.boxes[1].pasajero.id <<  ", del box con identificador:" << aeropuerto.boxes[1].id_box << end;
                        if (!aeropuerto.cola.es_vacia()){
                            aeropuerto.boxes[1].pasajero = aeropuerto.cola.desencolar();
                            cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.boxes[1].pasajero.id <<  ", al box con identificador:" << aeropuerto.boxes[1].id_box << end;
                            cout << "El box con Id:" << aeropuerto.boxes[1].id_box << ", está  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.boxes[1].id_box << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (aeropuerto.boxes[2].pasajero.duracion == 0)
                    {
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.boxes[2].pasajero.id <<  ", del box con identificador:" << aeropuerto.boxes[2].id_box << end;
                        if (!aeropuerto.cola.es_vacia()){
                            aeropuerto.boxes[2].pasajero = aeropuerto.cola.desencolar();
                            cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.boxes[2].pasajero.id <<  ", al box con identificador:" << aeropuerto.boxes[2].id_box << end;
                            cout << "El box con Id:" << aeropuerto.boxes[2].id_box << ", está  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.boxes[2].id_box << ", no está  en funcionamiento" << endl;
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
                while (!aeropuerto.pila.esVacia() && !aeropuerto.cola.es_vacia() && aeropuerto.boxes[0].empty() && aeropuerto.boxes[1].empty() && aeropuerto.boxes[2].empty()){
                    if (m == aeropuerto.pila.cima.pasajero.hora_inicio){
                        cout << "Minuto" << m << ":" << endl;

                        cout << "Ha llegado un pasajero al aeropuerto:" << endl;
                        cout << "Id:" << aeropuerto.pila.cima.pasajero.id << endl;
                        aeropuerto.cola.encolar(aeropuerto.pila.cima.pasajero);
                        aeropuerto.pila.desapilar();
                    }
                    if (aeropuerto.boxes[0].pasajero != NULL){
                        aeropuerto.boxes[0].pasajero.duracion--;
                        tiempo_box1++;
                    }
                    else{
                        if (!aeropuerto.cola.es_vacia()){
                            aeropuerto.boxes[0].pasajero = aeropuerto.cola.desencolar();
                            }
                        else{
                            cout << "El box con Id:" << aeropuerto.boxes[0].id_box << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (aeropuerto.boxes[1] != NULL){
                        aeropuerto.boxes[1].pasajero.duracion--;
                        tiempo_box2++;
                    }
                    else{
                        if (!aeropuerto.cola.es_vacia()){
                            aeropuerto.boxes[1].pasajero = aeropuerto.cola.desencolar();
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.boxes[1].id_box << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (aeropuerto.boxes[2].pasajero != NULL){
                        aeropuerto.boxes[2].pasajero.duracion--;
                        tiempo_box3++;
                    }
                    else{
                        if (!aeropuerto.cola.es_vacia()){
                            aeropuerto.boxes[0].pasajero = aeropuerto.cola.desencolar();
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.boxes[0].id_box << ", no está  en funcionamiento" << endl;
                        }
                    }

                    if (aeropuerto.boxes[0].pasajero.duracion == 0){
                        tiempo_medio = tiempo_medio + tiempo_box1;
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.boxes[0].pasajero.id <<  ", del box con identificador:" << aeropuerto.boxes[0].id_box << end;
                        if (!aeropuerto.cola.es_vacia()){
                            aeropuerto.boxes[0].pasajero = aeropuerto.cola.desencolar();
                            cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.boxes[0].pasajero.id <<  ", al box con identificador:" << aeropuerto.boxes[0].id_box << end;
                            cout << "El box con Id:" << aeropuerto.boxes[0].id_box << ", está  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.boxes[0].id_box << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (aeropuerto.boxes[1].pasajero.duracion == 0){
                        tiempo_medio = tiempo_medio + tiempo_box2;
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.boxes[1].pasajero.id <<  ", del box con identificador:" << aeropuerto.boxes[1].id_box << end;
                        if (!aeropuerto.cola.es_vacia()){
                            aeropuerto.boxes[1].pasajero = aeropuerto.cola.desencolar();
                            cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.boxes[0].pasajero.id <<  ", al box con identificador:" << aeropuerto.boxes[0].id_box << end;
                            cout << "El box con Id:" << aeropuerto.boxes[1].id_box << ", está  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.boxes[1].id_box << ", no está  en funcionamiento" << endl;
                        }
                    }
                    if (aeropuerto.boxes[2].pasajero.duracion == 0){
                        tiempo_medio = tiempo_medio + tiempo_box3;
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.boxes[2].pasajero.id <<  ", del box con identificador:" << aeropuerto.boxes[2].id_box << end;
                        if (!aeropuerto.cola.es_vacia()){
                            aeropuerto.boxes[2].pasajero = aeropuerto.cola.desencolar();
                            cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.boxes[0].pasajero.id <<  ", al box con identificador:" << aeropuerto.boxes[0].id_box << end;
                            cout << "El box con Id:" << aeropuerto.boxes[2].id_box << ", está  en funcionamiento" << endl;
                        }
                        else{
                            cout << "El box con Id:" << aeropuerto.boxes[2].id_box << ", no está  en funcionamiento" << endl;
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






////////////




















     return 0;



}
