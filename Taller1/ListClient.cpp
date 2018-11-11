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

void ListClient::AgregarCliente(Client*nuevoCliente)
{
	
	this->ListC[this->CantidadActual] = nuevoCliente;
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

int ListClient::GetCantidad()
{
	return this->CantidadActual;
}

bool ListClient::VerificarCliente(string id)
{
	
	for (int i = 0; i < CantidadActual; i++) {
		if (ListC[i]->GetClienteID() == id) {
			return true;
		}
	}
	return false;
}

Client ** ListClient::GetLista()
{
	return ListC;
}
