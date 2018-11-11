#pragma once
#include "client.h"
class ListClient
{
public:
	ListClient();
	ListClient(int total);
	~ListClient();
	void AgregarCliente(Client*nuevoCliente);
	void BuscarCliente(string ciudad);
	int GetCantidad();
private:
	int total;
	int CantidadActual;
	Client* C;
	Client** ListC;
};

