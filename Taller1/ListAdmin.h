#pragma once
#include "Admin.h"
class ListAdmin
{
public:
	ListAdmin();
	ListAdmin(int total);
	~ListAdmin();
	void AgregarAdmin(string nombre, string apellido, string ciudad, int monto);
	string BuscarAdmin(string ciudad);
	void DesplegarAdmins();
	void AdminDespedido(bool);
	void Administradores();
private:
	int total;
	int CantidadActual;
	Admin* A;
	Admin** ListaA;
	





};

