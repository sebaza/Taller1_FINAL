#pragma once
#include "Admin.h"
class ListAdmin
{
public:
	ListAdmin();
	ListAdmin(int total);
	~ListAdmin();
	void AgregarAdmin(Admin*nuevoAdmin);
	string BuscarAdmin(string ciudad);
	void DesplegarAdmins();
	void AdminDespedido(bool);
	void Administradores();
	void AumentarCant();
	void DisminuirCant();

	int GetCantidad();
	int Utilidades(string AdminID, int utilidad);
	Admin** GetLista();
	
private:
	int total;
	int CantidadActual;
	Admin* A;
	Admin** ListaA;
	





};

