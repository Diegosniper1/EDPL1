#include <iostream>

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

    Box b1 = new Box(1);
    Box b2 = new Box(2);
    Box b3 = new Box(3);


Aeropuerto aeropuerto = new Aeropuerto();

aeropuerto.boxes = {b1, b2, b3};

int a;

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
    		cout << "Pila borrada con éxito." >> endl;
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
                    if (aeropuerto.boxes[1] != NULL)
                    {
                    aeropuerto.boxes[1].pasajero.duracion--;
                    }
                    if (aeropuerto.boxes[2].pasajero != NULL)
                    {
                    aeropuerto.boxes[2].pasajero.duracion--;
                    }
                    if (aeropuerto.boxes[0].pasajero.duracion == 0)
                    {
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.boxes[0].pasajero.id <<  ", del box con identificador:" << aeropuerto.boxes[0].id_box << end;
                        aeropuerto.boxes[0].pasajero = aeropuerto.cola.desencolar();
                        cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.boxes[0].pasajero.id <<  ", al box con identificador:" << aeropuerto.boxes[0].id_box << end;
                    }
                    if (aeropuerto.boxes[1].pasajero.duracion == 0)
                    {
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.boxes[1].pasajero.id <<  ", del box con identificador:" << aeropuerto.boxes[1].id_box << end;
                        aeropuerto.boxes[1].pasajero = aeropuerto.cola.desencolar();
                        cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.boxes[1].pasajero.id <<  ", al box con identificador:" << aeropuerto.boxes[1].id_box << end
                    }
                    if (aeropuerto.boxes[2].pasajero.duracion == 0)
                    {
                        cout << "Ha salido el pasajero: Id ==" << aeropuerto.boxes[2].pasajero.id <<  ", del box con identificador:" << aeropuerto.boxes[2].id_box << end;
                        aeropuerto.boxes[2].pasajero = aeropuerto.cola.desencolar();
                        cout << "En su lugar ha entrado el pasajero: Id ==" << aeropuerto.boxes[2].pasajero.id <<  ", al box con identificador:" << aeropuerto.boxes[2].id_box << end
                    }
                }
		break;
         }

	 case 7: {

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

int hora = 0;

c = new Cola();

while (!esVacia(p) && !esVacia(c) && b1 != [] && b2 != [] && b3 != [])
{

pas = cima(p);

cnodo = new NodoCola(primero(c),NodoCola *sig);

if (b1 != [])
{
	b1[0].duracion--;
}

if (b2 != [])
{
	b2[0].duracion--;
}

if (b1 != [])
{
	b3[0].duracion--;
}

if (b1[0].duracion == 0)
{
	b1 = [];
}

if (b2[0].duracion == 0)
{
	b2 = [];
}

if (b3[0].duracion == 0)
{
	b3 = [];
}

if(hora == cima(p).hora_llegada)
{
	//while (cnodo.sig != NULL) Ordenación por prioridad
	enc




	if (b1 == [])
	{
	b1 = [cima(p)];
	desapilar(p);
	}

	else
	{
		if (b2 == [])
		{
			b2 = [cima(p)];
			desapilar(P);
		}

     		else
		{
			if (b3 == [])
	     	{
		b3 = [cima(p)];
		desapilar(p);
          	}

		else
	     	{
		c.encolar(cima(p));
		desapilar(p);
	     	}
	}

}
}




hora++;

}



















     return 0;



}
