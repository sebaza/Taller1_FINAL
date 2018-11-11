#include "stdafx.h"
#include "ListAdmin.h"


ListAdmin::ListAdmin()
{
}

ListAdmin::ListAdmin(int total)
{
	this->total = total;
	this->CantidadActual = 0;
	this->ListaA = new Admin*[100];
}


ListAdmin::~ListAdmin()
{
}

void ListAdmin::AgregarAdmin(string nombre, string apellido, string ciudad, int monto)
{	
	//Falta generador de ID
	string id = "A" + std::to_string(CantidadActual);
	Admin*adminNuevo = new Admin(nombre, apellido, id, ciudad, monto);
	//Falta aumentar la lista en 1;
	this->ListaA[this->CantidadActual] = adminNuevo;
	this->CantidadActual++;
	
}

string ListAdmin::BuscarAdmin(string ciudad)
{
	return "";
}


void ListAdmin::DesplegarAdmins()
{
	cout << "LISTADO DE ADMINISTRADORES" << endl;
	cout << "***********************" << endl;
	for (int i = 0; i < CantidadActual; i++) {

		

			cout << i + 1 << "Nombre: " << this->ListaA[i]->Getnombre() << "||" << "Apellido: " << this->ListaA[i]->GetApellido() << "||" << "Id: " << this->ListaA[i]->GetAdminID() << "||" << "Monto: " << this->ListaA[i]->GetMonto() << endl;
			//Ciclo Eventos
			//nombre,id,estado
                   

	}
}

void ListAdmin::AdminDespedido(bool)
{
}

void ListAdmin::Administradores()
{
}

int ListAdmin::GetCantidad()
{
	return this->CantidadActual;
}

Admin** ListAdmin::GetLista()
{
	return ListaA;
}
