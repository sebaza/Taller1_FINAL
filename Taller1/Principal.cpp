#include "stdafx.h"
#include "Principal.h"
#include "ListClient.h"
#include "ListEvent.h"
#include "ListAdmin.h"
#include "String.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;

ListEvent le;
ListAdmin la;
ListClient lc;


Principal::Principal()
{


	Menu();


}


Principal::~Principal()
{
}

void Principal::LecturaDeArchivos()
{
#pragma region Clientes
	//Variables aux

	std::ifstream archivoClientes;
	archivoClientes.open("Clientes.txt", ifstream::in);

	string linea;
	string aux_1;

	if (archivoClientes.is_open()) {

		cout << "***************************************************" << endl;
		while (getline(archivoClientes, linea)) {
			//crear cliente
			Client* clienteNuevo;

			clienteNuevo = new Client("", "", "", "", 0);



			cout << linea << endl; //Imprimir linea

			stringstream ss(linea);
			getline(ss, aux_1, ';');
			cout << aux_1 << endl; //Imprimir nombre
			clienteNuevo->SetNombre(aux_1);

			getline(ss, aux_1, ';');
			cout << aux_1 << endl; //Imprimir apellido
			clienteNuevo->SetApellido(aux_1);

			getline(ss, aux_1, ';');
			cout << aux_1 << endl; //Imprimir id
			clienteNuevo->SetClienteID(aux_1);


			getline(ss, aux_1, ';');
			cout << aux_1 << endl; //Imprimir ciudad
			clienteNuevo->SetCiudad(aux_1);


			getline(ss, aux_1, ';');
			cout << aux_1 << endl; //Imprimir numero
			clienteNuevo->SetTelefono(std::stoi(aux_1));

			cout << "***************************************************" << endl;
			cout << "LISTA DE EVENTOS" << endl;

			//ciclo de eventos
			string* ls;

			while (!ss.eof()) {
				string evento;
				getline(ss, evento, ';');

				cout << evento << endl; //Imprimir linea
			}

			cout << "***************************************************" << endl;

		}


		aux_1.clear(); //Liberacion de memoria para la variable auxiliar.
	}

#pragma endregion Clientes

#pragma region Administradores

	//Variables aux

	string monto;


	std::ifstream archivoAdmin;
	archivoAdmin.open("Administradores.txt", ifstream::in);
	string aux_2;

	if (archivoAdmin.is_open()) {

		cout << "***************************************************" << endl;
		while (getline(archivoAdmin, linea)) {
			cout << linea << endl; //Imprimir linea

			stringstream ss(linea);
			getline(ss, aux_2, ';');
			cout << aux_2 << endl; //Imprimir nombre

			getline(ss, aux_2, ';');
			cout << aux_2 << endl; //Imprimir apellido

			getline(ss, aux_2, ';');
			cout << aux_2 << endl; //Imprimir id

			getline(ss, aux_2, ';');
			cout << aux_2 << endl; //Imprimir ciudad

			getline(ss, aux_2, ';');
			cout << aux_2 << endl; //Imprimir numero

			cout << "***************************************************" << endl;
			//ciclo de eventos
			cout << "LISTA DE EVENTOS" << endl;
			while (!ss.eof()) {
				string evento;
				getline(ss, evento, ';');
				cout << evento << endl; //Imprimir linea
			}

			cout << "***************************************************" << endl;

		}


		aux_2.clear(); //Liberacion de memoria para la variable auxiliar.
	}
#pragma endregion Administradores

#pragma region Eventos

	std::ifstream archivoEventos;
	archivoEventos.open("Eventos.txt", ifstream::in);
	string aux_3;
	

	if (archivoEventos.is_open()) {
		cout << "***************************************************" << endl;
		while (getline(archivoEventos, linea)) {

			string nombreAux;
			string ciudadAux;
			string idAux;
			string idAdminAux;
			string idEventoAux;
			string tipoAux;
			string estadoAux;

			cout << linea << endl; //Imprimir linea

			stringstream ss(linea);
			getline(ss, nombreAux, ',');
			cout << nombreAux << endl; //Imprimir nombre evento

			getline(ss, ciudadAux, ',');
			cout << ciudadAux << endl; //Imprimir ciudad evento

			getline(ss, idAux, ',');
			cout << aux_3 << endl; //Imprimir id del cliente

			getline(ss, idAdminAux, ',');
			cout << aux_3 << endl; //Imprimir id del administrador

			getline(ss, idEventoAux, ',');
			cout << aux_3 << endl; //Imprimir id del evento.

			getline(ss, tipoAux, ',');
			cout << aux_3 << endl; //Imprimir tipo de evento.

			getline(ss, estadoAux, ',');
			cout << aux_3 << endl; //Imprimir estado del evento.

			if (aux_3.compare("Realizado") == 0) {
				string cantEsp;
				string cantAsis;

				getline(ss, cantEsp, ',');
				cout << aux_3 << endl; //Imprimir cantidad de personas esperadas del evento.


				getline(ss, cantAsis, ',');
				cout << aux_3 << endl; //Imprimir cantidad de personas asistentes del evento.


				Event *eventoNuevo = new Event(nombreAux, ciudadAux, idAux, idAdminAux, idEventoAux, tipoAux, estadoAux, std::stoi(cantEsp),std::stoi(cantAsis));
			}
			else {
				string cantEsp;
				getline(ss, cantEsp , ',');
				cout << aux_3 << endl; //Imprimir cantidad de personas esperadas del evento.
				Event *eventoNuevo = new Event(nombreAux, ciudadAux, idAux, idAdminAux, idEventoAux, tipoAux, estadoAux, std::stoi(cantEsp),0);
			}

			//Falta agregar eventoNuevo a lista le.
			
			//Creamos el evento y se añade a la lista

			
			cout << "***************************************************" << endl;
			cout << "***************************************************" << endl;

		}
	}

#pragma endregion Eventos
}

void Principal::Menu()
{
	LecturaDeArchivos();

	bool menu = true;
	cout << "Bienvenido a GenEvent" << endl;
	string opcion;
	string pause;
	while (menu) {
		cout << "A continuacion se mostrara un menu para que interactue" << endl;
		cout << "Menu principal:" << endl;
		cout << "1)Agregar" << endl;
		cout << "2)Administrar Evento" << endl;
		cout << "3)Buscar" << endl;
		cout << "4)Cerrar el programa" << endl;
		getline(cin, opcion);
		try {
			std::stoi(opcion);
		}
		catch (const std::exception) {
			cout << "Porfavor escriba un numero" << endl;
			continue;
		}
		int opcionVerificada = std::stoi(opcion);

		switch (opcionVerificada) {
		case 1:
			MenuAgregar();
			break;
		case 2:
			MenuAdministrar();
			break;
		case 3:
			MenuBuscar();
			break;
		case 4:
			cout << "Gracias por usar el programa" << endl;
			Despedidos();
			getline(cin, pause);
			menu = false;
			break;
		}
	}
}

void Principal::MenuAgregar()
{
	bool menu = true;
	cout << "Selecciono Agregar datos" << endl;
	string opcion;
	while (menu) {
		cout << "A continuacion se mostraron diferentes opciones que podran elegir" << endl;
		cout << "Menu Agregar:" << endl;
		cout << "1)Agregar Evento" << endl;
		cout << "2)Agregar Administrador" << endl;
		cout << "3)Agregar Cliente" << endl;
		cout << "4)volver" << endl;
		getline(cin, opcion);
		try {
			std::stoi(opcion);
		}
		catch (const std::exception) {
			cout << "Porfavor escriba un numero" << endl;
			continue;
		}
		int opcionVerificada = std::stoi(opcion);
		//recordar delete() despues

		string nombreAux;
		string variable2;
		string variable3;
		string variable4;
		string variable5;
		string variable6;
		string variable7;
		string variable8;
		string variable9;
		string* variableEventos = new string[10];


		switch (opcionVerificada) {
		case 1:
			//HalloweenNight, Antofagasta, C5, A20, E7, Cultural, Realizado, 3000, 2800

			cout << "Ingrese nombre" << endl;
			getline(cin, nombreAux);
			cout << "Ingrese ciudad" << endl;
			getline(cin, variable2);
			cout << "Ingrese la id del cliente" << endl;
			getline(cin, variable3);
			cout << "Ingrese el tipo de evento" << endl;
			getline(cin, variable6);

			cout << "Ingrese la cantidad de personas esperadas" << endl;
			getline(cin, variable8);

			if (la.BuscarAdmin(variable2) != "") {
				le.AgregarEvento(nombreAux, variable2, variable3, variable5, std::stoi(variable8), la.BuscarAdmin(variable2));
			}
			else {

			}
			cout << "Se regresara al menu agregar" << endl;
			continue;

		case 2:
			cout << "Ingresar Nombre" << endl;
			getline(cin, nombreAux);
			cout << "Ingrese Apellido" << endl;
			getline(cin, variable2);
			cout << "Ingresar ciudad" << endl;
			getline(cin, variable3);
			//cout << "¿cuantos eventos tiene realizado?(maximo 5)" << endl;
			//getline(cin, variable5);
			//while (std::stoi(variable5) > 5) {
				//cout << "ingreso una cantidad no esperada , intentelo de nuevo" << endl;
				//getline(cin, variable5);
			//}
			//string* list = new string[std::stoi(variable5)];
			//for (int i = 0; i < std::stoi(variable5); i++) {
				//cout << "Ingrese id evento " << i << endl;
				//getline(cin, variable6);
				//list[i] = variable6;
			//}
			la.AgregarAdmin(nombreAux, variable2, variable3, 7000);
			cout << "Se regresara al menu agregar" << endl;
			continue;

		case 3:
			cout << "Ingresar Nombre" << endl;
			getline(cin, nombreAux);
			cout << "Ingrese Apellido" << endl;
			getline(cin, variable2);
			cout << "Ingresar Ciudad" << endl;
			getline(cin, variable3);
			cout << "Ingresar el numero telefonico" << endl;
			getline(cin, variable4);
			lc.AgregarCliente(nombreAux, variable2, variable3, std::stoi(variable4));
			cout << "Se regresara al menu agregar" << endl;
			continue;


		case 4:
			cout << "Se regresara al menu principal" << endl;
			menu = false;
			Menu();
			break;
		}
	}
}

void Principal::MenuAdministrar()
{
}

void Principal::MenuBuscar()
{
	bool menu = true;
	cout << "Selecciono Buscar" << endl;
	string opcion;
	while (menu) {
		cout << "A continuacion se le daran diferentes opciones de busqueda" << endl;
		cout << "se le pedira algunos datos para realizar la busqueda dependiendo del caso" << endl;
		cout << "Menu Buscar:" << endl;
		cout << "1)Eventos por tipo" << endl;
		cout << "2)Cliente por ciudad" << endl;
		cout << "3)Administradores" << endl;
		cout << "4)volver" << endl;
		getline(cin, opcion);
		try {
			std::stoi(opcion);
		}
		catch (const std::exception) {
			cout << "Porfavor escriba un numero" << endl;
			continue;
		}
		int opcionVerificada = std::stoi(opcion);
		string variable;

		switch (opcionVerificada) {
		case 1:
			cout << "Selecciono buscar Eventos por tipo" << endl;
			cout << "Ingrese el tipo de evento a buscar (o ingrese 'todos' para desplegar todos los eventos)" << endl;
			while (true) {
				getline(cin, variable);

				//algoritmo para pasar string a mayusculas
				for (int i = 0; i < variable.length(); i++) {
					variable[i] = toupper(variable[i]);
					cout << "borra esta linea despues" << endl;
				}
				cout << variable << endl;
				//********************************************
				if (variable =="SOCIAL" || variable=="DEPORTIVO"  || variable== "CULTURAL"  || variable=="TODOS") {
					cout << "success" << endl;
					le.BuscarPorEventos(variable);
					break;
					
				}
				else {
					cout << "ingreso una opcion no valida" << endl;
					cout << "se volvera a pedir el tipo asegurese de que es valido" << endl;
				}
			}
			continue;
			cout << "Se regresara al menu buscar" << endl;
		case 2:
			cout << "Selecciono buscar Cliente por ciudad" << endl;
			cout << "Ingrese la ciudad que desea buscar  (o ingrese 'todos' para desplegar todas las ciudades)" << endl;
			getline(cin, variable);
			//algoritmo para pasar string a mayusculas
			for (int i = 0; i < variable.length(); i++) {
				variable[i] = tolower(variable[i]);
			}
			variable[0] = toupper(variable[0]);
			//********************************************
			lc.BuscarCliente(variable);
			cout << "Se regresara al menu buscar" << endl;
			continue;

		case 3:
			cout << "Selecciono buscar administradores" << endl;
			la.DesplegarAdmins();
			cout << "Se regresara al menu buscar" << endl;
			continue;

		case 4:
			cout << "Se regresara al menu principal" << endl;
			menu = false;
			break;
		}
	}
}

void Principal::Despedidos()
{

}

void Principal::ReducirLista()
{
}

void Principal::ExpandirLista()
{
}