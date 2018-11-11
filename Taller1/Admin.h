#pragma once
#include <string>
#include <iostream>
#include "Event.h"
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
	int GetCantEventos();
	string getEvento(int index);
	int GetMonto();
	void SetMonto(int monto);
	void AgregarEvento(string evento);
	
	string* GetEvento();
	~Admin();
private:
	string nombre;
	string apellido;
	string AdminID;
	string ciudad;
	int monto;
	string* eventos;
	int cantEventos;
};


