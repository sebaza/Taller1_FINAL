#pragma once
#include "client.h"
class ListClient
{
public:
	ListClient();
	ListClient(int total);
	~ListClient();
	void AgregarCliente(string nombre, string apellido, string ciudad, int telefono);
	void BuscarCliente(string ciudad);
private:
	int total;
	int CantidadActual;
	Client* C;
	Client** ListC;
};

