#include "stdafx.h"
#include "ListClient.h"


ListClient::ListClient()
{
}

ListClient::ListClient(int total)
{
	this->total = total;
	this->CantidadActual = 0;
	this->ListC = new Client*[100];
}


ListClient::~ListClient()
{
}

void ListClient::AgregarCliente(string nombre, string apellido, string ciudad, int telefono)
{
	//Falta generador de ID para cliente
	string id = "";
	Client* NuevoCliente = new Client(nombre, apellido,id, ciudad,telefono);
	this->ListC[this->CantidadActual] = NuevoCliente;
	this->CantidadActual++;
}

void ListClient::BuscarCliente(string ciudad)
{
	cout << "LISTADO DE CLIENTES" << endl;
	cout << "***********************" << endl;
	for (int i = 0; i < CantidadActual; i++) {

		if (ciudad == "TODOS") {

			cout << i + 1 << "Nombre: " << this->ListC[i]->GetNombre() << "||" << "Apellido: " << this->ListC[i]->GetApellido() << "||" << "Id: " << this->ListC[i]->GetClienteID() << endl;
			//Ciclo Eventos
			//nombre,id,estado

		}

		else if (this->ListC[i]->GetCiudad() == ciudad) {
			cout << i + 1 << "Nombre: " << this->ListC[i]->GetNombre() << "||" << "Apellido: "<< this->ListC[i]->GetApellido() <<"||" << "Id: " << this->ListC[i]->GetClienteID() << endl;
			//Ciclo Eventos
		}



	}
}
