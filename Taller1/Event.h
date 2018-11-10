#pragma once
#include <string>
#include <iostream>

using namespace std;
class Event
{
public:
	Event();
	Event(string nombre,string ciudad,string clienteID,string adminID, string eventoID, string tipo, string Estado, int CantEsperando, int CantAsistente);
	string Getnombre();
	string Getciudad();
	string GetClienteID();
	string GetAdminID();
	string GetnEventoID();
	string GetTipo();
	string GetEstado();
	int GetCantEsperado();
	int GetCantAsistente();

	~Event();
private:
	string nombre;
	string ciudad;
	string clienteID;
	string adminID;
	string eventoID;
	string tipo;
	string Estado;
	int CantEsperando;
	int CantAsistente;

};

