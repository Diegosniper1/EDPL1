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

    pila.mostrar_entera();


Aeropuerto aeropuerto = new Aeropuerto();

int a;

cout << "           *** MENÚ ***"        << endl;
cout << "1: Crear pila de pasajeros." << endl;
cout << "2: Mostrar los pasajeros." << endl;
cout << "3: Borrar la pila de pasajeros" << endl;
cout << "4: Mostrar la cola de espera" << endl;
cout << "5: Mostrar los pasajeros atendidos en cada box" << endl;
cout << "6: Simulacro en N minutos" << endl;
cout << "7: Simulacro total" << endl;

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

		break;
         }

	 case 6: {

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
