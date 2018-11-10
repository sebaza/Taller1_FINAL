#pragma once
#include <string>
#include <iostream>

using namespace std;
class Admin
{
public:
	Admin();
	Admin(string nombre, string apellido, string AdminID, string ciudad, int monto);
	string Getnombre();
	string GetApellido();
	string GetAdminID();
	string GetCiudad();
	int GetMonto();
	string* GetEvento();
	~Admin();
private:
	string nombre;
	string apellido;
	string AdminID;
	string ciudad;
	int monto;
	string* eventos;
};


