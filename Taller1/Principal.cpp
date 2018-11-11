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
	

	string C_nombre;
	string C_apellido;
	string C_id;
	string C_ciudad;
	string C_numero;

	if (archivoClientes.is_open()) {

		cout << "***************************************************" << endl;
		while (getline(archivoClientes, linea)) {
			//crear cliente
			

			



			cout << linea << endl; //Imprimir linea

			stringstream ss(linea);
			getline(ss, C_nombre, ';');
			cout << C_nombre << endl; //Imprimir nombre
			

			getline(ss, C_apellido, ';');
			cout << C_apellido << endl; //Imprimir apellido
			

			getline(ss, C_id, ';');
			cout << C_id << endl; //Imprimir id
			


			getline(ss, C_ciudad, ';');
			cout << C_ciudad << endl; //Imprimir ciudad
			

			getline(ss, C_numero, ';');
			cout << C_numero << endl; //Imprimir numero
			

			cout << "***************************************************" << endl;
			cout << "LISTA DE EVENTOS" << endl;

			//ciclo de eventos
			string* ls;

			while (!ss.eof()) {
				string evento;
				getline(ss, evento, ';');

				cout << evento << endl; //Imprimir linea
			}
			Client*clienteNuevo = new Client(C_nombre, C_apellido, C_id, C_ciudad,std::stoi( C_numero));
			//falta agregar a lista
			cout << "***************************************************" << endl;

		}


		
	}

#pragma endregion Clientes

#pragma region Administradores

	//Variables aux

	
	string A_nombre;
	string A_apellido;
	string A_id;
	string A_ciudad;
	string A_monto;


	std::ifstream archivoAdmin;
	archivoAdmin.open("Administradores.txt", ifstream::in);
	

	if (archivoAdmin.is_open()) {

		cout << "***************************************************" << endl;
		while (getline(archivoAdmin, linea)) {
			cout << linea << endl; //Imprimir linea

			stringstream ss(linea);
			getline(ss, A_nombre, ';');
			cout << A_nombre << endl; //Imprimir nombre

			getline(ss, A_apellido, ';');
			cout << A_apellido << endl; //Imprimir apellido

			getline(ss, A_id, ';');
			cout << A_id << endl; //Imprimir id

			getline(ss, A_ciudad, ';');
			cout << A_ciudad << endl; //Imprimir ciudad

			getline(ss, A_monto, ';');
			cout << A_monto << endl; //Imprimir monto
			
			cout << "***************************************************" << endl;
			//ciclo de eventos
			cout << "LISTA DE EVENTOS" << endl;
			while (!ss.eof()) {
				string evento;
				getline(ss, evento, ';');
				cout << evento << endl; //Imprimir linea
			}

			Admin*nuevoAdmin = new Admin(A_nombre, A_apellido, A_id, A_ciudad,std::stoi(A_monto));

			
			cout << "***************************************************" << endl;

		}


		
	}
#pragma endregion Administradores

#pragma region Eventos

	std::ifstream archivoEventos;
	archivoEventos.open("Eventos.txt", ifstream::in);
	string aux_3;
	

	if (archivoEventos.is_open()) {
		cout << "***************************************************" << endl;
		while (getline(archivoEventos, linea)) {

			string E_nombre;
			string E_ciudad;
			string E_idCliente;
			string E_idAdmin;
			string E_id;
			string E_tipo;
			string E_estado;

			cout << linea << endl; //Imprimir linea

			stringstream ss(linea);
			getline(ss, E_nombre, ',');
			cout << E_nombre << endl; //Imprimir nombre evento

			getline(ss, E_ciudad, ',');
			cout << E_ciudad << endl; //Imprimir ciudad evento

			getline(ss, E_idCliente, ',');
			cout << aux_3 << endl; //Imprimir id del cliente

			getline(ss, E_idAdmin, ',');
			cout << aux_3 << endl; //Imprimir id del administrador

			getline(ss, E_id, ',');
			cout << aux_3 << endl; //Imprimir id del evento.

			getline(ss, E_tipo, ',');
			cout << aux_3 << endl; //Imprimir tipo de evento.

			getline(ss, E_estado, ',');
			cout << aux_3 << endl; //Imprimir estado del evento.

			if (aux_3.compare("Realizado") == 0) {
				string cantEsp;
				string cantAsis;

				getline(ss, cantEsp, ',');
				cout << aux_3 << endl; //Imprimir cantidad de personas esperadas del evento.


				getline(ss, cantAsis, ',');
				cout << aux_3 << endl; //Imprimir cantidad de personas asistentes del evento.


				Event *eventoNuevo = new Event(E_nombre, E_ciudad, E_idCliente, E_idAdmin, E_id, E_tipo, E_estado, std::stoi(cantEsp),std::stoi(cantAsis));
			}
			else {
				string cantEsp;
				getline(ss, cantEsp , ',');
				cout << aux_3 << endl; //Imprimir cantidad de personas esperadas del evento.
				Event *eventoNuevo = new Event(E_nombre, E_ciudad, E_idCliente, E_idAdmin, E_id, E_tipo, E_estado, std::stoi(cantEsp),0);
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
		
		
		string* variableEventos = new string[10];


		switch (opcionVerificada) {
		case 1:
			//HalloweenNight, Antofagasta, C5, A20, E7, Cultural, Realizado, 3000, 2800
			AgregarEvento();
			continue;

		case 2:
			AgregarAdmin();
			continue;

		case 3:
			
			AgregarCliente();
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
	cout << "Selecciono Menu Administras" << endl;
	string opcion;
	bool menu = true;
	while (menu) {
		cout << "A continuacion se mostraron diferentes opciones que podran elegir" << endl;
		cout << "Menu Administrar evento:" << endl;
		cout << "1)Evento Realizado" << endl;
		cout << "2)Cancelar Evento" << endl;
		cout << "3)Volver" << endl;

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

		
		switch (opcionVerificada) {
		case 1:
			RealizarEvento();
			continue;
		case 2:
			CancelarEvento();
			continue;
		case 3:
			cout << "Selecciono volver al menu principal" << endl;
			menu = false;
			Menu();
			break;
		}
	}
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
		
		
		switch (opcionVerificada) {
		case 1:
			BuscarPorEventos();
			continue;
			cout << "Se regresara al menu buscar" << endl;
		case 2:
			BuscarClientes();
			continue;

		case 3:
			DesplegarAdmins();
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
	std::ofstream outfile("Despedidos.txt");

	outfile << "my text here!" << std::endl;
	
	outfile.close();

	ofstream myfile("Despedidos.txt");
	if (myfile.is_open())
	{//Algoritmo que verifica si el admin es despedido dependiendo de su monto
		for (int i = 0; i < la.GetCantidad(); i++) {
			if (la.GetLista()[i]->GetMonto() < 0) {
				outfile << la.GetLista()[i]->Getnombre()<<";"<< la.GetLista()[i]->GetApellido()<<";"<< la.GetLista()[i]->GetAdminID()<<";"<< la.GetLista()[i]->GetCiudad()<<";"<< la.GetLista()[i]->GetMonto() << std::endl;
			}
		
		}

		//texto prueba, DEBE SER BORRADO
		myfile << "This outputting a line.\n";
		myfile << "this is another line.\n";
		myfile.close();
	}
}

void Principal::ReducirLista()
{
}

void Principal::ExpandirLista()
{
}

void Principal::AgregarEvento() {
	string nombre;
	string ciudad;
	string id;
	string tipoEvento;
	string cantidad;
	cout << "Ingrese nombre" << endl;
	getline(cin, nombre);
	cout << "Ingrese ciudad" << endl;
	getline(cin, ciudad);
	cout << "Ingrese la id del cliente" << endl;
	getline(cin, id);
	cout << "Ingrese el tipo de evento" << endl;
	getline(cin, tipoEvento);

	cout << "Ingrese la cantidad de personas esperadas" << endl;
	getline(cin, cantidad);

	if (la.BuscarAdmin(ciudad) != "") {
		le.AgregarEvento(nombre,ciudad, id, tipoEvento, std::stoi(cantidad), la.BuscarAdmin(ciudad));
	}
	else {
		cout << "Administrador no encontrado en aquella ciudad, no fue posible crear el evento" << endl;
		cout << "*****************************************************************************" << endl;
	}
	cout << "Se regresara al menu agregar" << endl;
}
void Principal::AgregarCliente() {

	string nombre;
	string apellido;
	string ciudad;
	string numero;
	
	cout << "Ingresar Nombre" << endl;
	getline(cin, nombre);
	cout << "Ingrese Apellido" << endl;
	getline(cin, apellido);
	cout << "Ingresar Ciudad" << endl;
	getline(cin, ciudad);
	cout << "Ingresar el numero telefonico" << endl;
	getline(cin, numero);
	lc.AgregarCliente(nombre, apellido,ciudad, std::stoi(numero));
	cout << "Se regresara al menu agregar" << endl;
}
void Principal::AgregarAdmin() {
	string nombre;
	string apellido;
	string ciudad;
	cout << "Ingresar Nombre" << endl;
	getline(cin, nombre);
	cout << "Ingrese Apellido" << endl;
	getline(cin, apellido);
	cout << "Ingresar ciudad" << endl;
	getline(cin, ciudad);
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
	la.AgregarAdmin(nombre, apellido, ciudad, 7000);
	cout << "Se regresara al menu agregar" << endl;

}

void Principal::BuscarPorEventos()
{
	string variable;
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
		if (variable == "SOCIAL" || variable == "DEPORTIVO" || variable == "CULTURAL" || variable == "TODOS") {
			cout << "success" << endl;
			le.BuscarPorEventos(variable);
			break;

		}
		else {
			cout << "ingreso una opcion no valida" << endl;
			cout << "se volvera a pedir el tipo asegurese de que es valido" << endl;
		}
	}
}
void Principal::BuscarClientes()
{
	string variable;
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
}
void Principal::DesplegarAdmins() {
	cout << "Selecciono buscar administradores" << endl;
	la.DesplegarAdmins();
	cout << "Se regresara al menu buscar" << endl;
}

void Principal::RealizarEvento()
{
	string variableID;
	string variable_cantidad;
	cout << "Porfavor ingrese la id del eveto" << endl;
	getline(cin, variableID);
	cout << "Porfavor ingrese la cantidad de personas que asistieron" << endl;
	getline(cin, variable_cantidad);
	int utilidad = le.EventoRealizado(variableID, std::stoi(variable_cantidad));
	utilidad = la.Utilidades(variableID, utilidad);
	if (utilidad < 0) {
		//despedir
	}
}
void Principal::CancelarEvento()
{
	string variableID;
	cout << "Porfavor ingrese la id del eveto que quiera cancelar" << endl;
	getline(cin, variableID);
	int utilidad = le.EventoCancelado(variableID);
	utilidad = la.Utilidades(variableID, utilidad);
	if (utilidad < 0) {
		//despedir
	}
}


void Principal::ArchivoSalida()
{
	
	

}

