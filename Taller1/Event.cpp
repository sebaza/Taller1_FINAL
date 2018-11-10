#include "stdafx.h"
#include "Event.h"


Event::Event()
{
}

Event::Event(string nombre, string ciudad, string clienteID, string adminID, string eventoID, string tipo, string Estado, int CantEsperando, int CantAsistente)
{
	this->nombre = nombre;
	this->ciudad = ciudad;
	this->clienteID = clienteID;
	this->adminID = adminID;
	this->eventoID = eventoID;
	this->tipo = tipo;
	this->Estado = Estado;
	this->CantEsperando = CantEsperando;
	this->CantAsistente = CantAsistente;
}

string Event::Getnombre()
{
	return nombre;
}

string Event::Getciudad()
{
	return ciudad;
}

string Event::GetClienteID()
{
	return clienteID;
}

string Event::GetAdminID()
{
	return adminID;
}

string Event::GetnEventoID()
{
	return eventoID;
}

string Event::GetTipo()
{
	return tipo;
}

string Event::GetEstado()
{
	return Estado;
}

int Event::GetCantEsperado()
{
	return CantEsperando;
}

int Event::GetCantAsistente()
{
	return CantAsistente;
}


Event::~Event()
{
}
