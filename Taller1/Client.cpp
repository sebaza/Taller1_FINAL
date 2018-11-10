#include "stdafx.h"
#include "Client.h"


Client::Client()
{
}

Client::Client(string nombre, string apellido, string ClienteID, string ciudad, int telefono)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->ClienteID = ClienteID;
	this->ciudad = ciudad;
	this->telefono = telefono;
	this->eventos = new string[0];
}

string Client::GetNombre()
{
	return nombre;
}

string Client::GetApellido()
{
	return apellido;
}

string Client::GetClienteID()
{
	return ClienteID;
}

string Client::GetCiudad()
{
	return ciudad;
}

int Client::GetnTelefono()
{
	return telefono;
}

string * Client::GetEvento()
{
	return eventos;
}

void Client::SetNombre(string nombre)
{
	this->nombre = nombre;
}

void Client::SetApellido(string apellido)
{
	this->apellido = apellido;
}

void Client::SetClienteID(string cliente)
{
	this->ClienteID = cliente;
}


void Client::SetCiudad(string ciudad)
{
	this->ciudad = ciudad;
}

void Client::SetTelefono(int telefono)
{
	this->telefono = telefono;

}



Client::~Client()
{
}
