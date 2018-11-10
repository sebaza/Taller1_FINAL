#include "stdafx.h"
#include "Admin.h"


Admin::Admin()
{
}

Admin::Admin(string nombre, string apellido, string AdminID, string ciudad, int monto)
{
	this->nombre = nombre;
	this->apellido = apellido;
	this->AdminID = AdminID;
	this->ciudad = ciudad;
	this->monto = monto;
}

string Admin::Getnombre()
{
	return nombre;
}

string Admin::GetApellido()
{
	return apellido;
}

string Admin::GetAdminID()
{
	return AdminID;
}

string Admin::GetCiudad()
{
	return ciudad;
}

int Admin::GetMonto()
{
	return monto;
}


string * Admin::GetEvento()
{
	return eventos;
}

Admin::~Admin()
{
}
