#pragma once
#include "Event.h"
class ListEvent
{
public:
	ListEvent();
	ListEvent(int total);
	void AgregarEvento(string nombre, string ciudad, string clienteID,  string tipo, int CantEsperando,string AdminId);
	void EventoRealizado(string ID, int CantAsistes);
	void EventoCancelado(string ID);
	void BuscarPorEventos(string tipo);
	string BuscarEventos(string ciudad);
	~ListEvent();
private:
	int total;
	int CantidadActual;
	Event* E;
	Event** ListE;
	
};

