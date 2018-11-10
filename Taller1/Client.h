#pragma once
#include <string>
#include <iostream>

using namespace std;
class Client
{
public:
	Client();
	Client(string nombre, string apellido, string ClienteID, string ciudad, int telefono);

	string GetNombre();
	string GetApellido();
	string GetClienteID();
	string GetCiudad();
	int GetnTelefono();
	string* GetEvento();

	void SetNombre(string nombre);
	void SetApellido(string apellido);
	void SetClienteID(string cliente);
	void SetCiudad(string ciudad);
	void SetTelefono(int telefono);


	~Client();
private:
	string nombre;
	string apellido;
	string ClienteID;
	string ciudad;
	int telefono;
	string* eventos;


};

