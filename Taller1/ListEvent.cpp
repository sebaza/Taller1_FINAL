#include "stdafx.h"
#include "ListEvent.h"
#include "ListAdmin.h"
#include "Event.h"
ListEvent::ListEvent()
{
}

ListEvent::ListEvent(int total)
{
	this->total = total;
	this->CantidadActual = 0;
	this->ListE = new Event*[100];
}

void ListEvent::AgregarEvento(string nombre, string ciudad, string clienteID, string tipo, int CantEsperando,string AdminId)
{
	//Falta creador de ID
	string eventoId = "";
	Event*eventoNuevo = new Event(nombre, ciudad, clienteID, AdminId, eventoId, tipo, "por realizar", CantEsperando, 0);
	//Llamar funcion para expandir lista.
	this->ListE[this->CantidadActual] = eventoNuevo;
	this->CantidadActual++;

}



void ListEvent::EventoRealizado(string ID, int CantAsistes)
{
	BuscarEventos(ID);
}

void ListEvent::EventoCancelado(string ID)
{
}

void ListEvent::BuscarPorEventos(string tipo)
{
	cout << "LISTADO DE EVENTOS" << endl;
	cout << "***********************" << endl;
	for (int i = 0; i < CantidadActual;i++) {
		
		if (tipo == "TODOS") {
			cout << i + 1 << "Nombre: " << this->ListE[i]->Getnombre() << "||" << "Id: "<< this->ListE[i]->GetnEventoID() << "|| "<< "Estado: "<< this->ListE[i]->GetEstado()<< endl;

			//nombre,id,estado
		
		}
		else if (this->ListE[i]->GetTipo() == tipo) {
			cout << i + 1 << "Nombre: " << this->ListE[i]->Getnombre() << "||" << "Id: " << this->ListE[i]->GetnEventoID() << "|| " << "Estado: " << this->ListE[i]->GetEstado() << endl;
		}



	}
}

string ListEvent::BuscarEventos(string ciudad)
{
	return string();
}


ListEvent::~ListEvent()
{

}


