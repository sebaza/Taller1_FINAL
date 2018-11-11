#pragma once
#include "Client.h"
class ListClient
{
public:
	ListClient();
	ListClient(int total);
	~ListClient();
	void AgregarCliente(Client*nuevoCliente);
	void BuscarCliente(string ciudad);
	int GetCantidad();
	bool VerificarCliente(string id);
	Client** GetLista();
private:
	int total;
	int CantidadActual;
	Client* C;
	Client** ListC;
};

