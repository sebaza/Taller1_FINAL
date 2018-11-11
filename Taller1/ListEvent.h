#pragma once
#include "Event.h"
class ListEvent
{
public:
	ListEvent();
	ListEvent(int total);
	void AgregarEvento(Event*eventoNuevo);
	int EventoRealizado(string ID, int CantAsistes);
	int EventoCancelado(string ID);
	void BuscarPorEventos(string tipo);
	string BuscarEventos(string ciudad);
	int GetCantidad();

	void LecturaEvento(Event eventoNuevo);
	~ListEvent();
private:
	int total;
	int CantidadActual;
	Event* E;
	Event** ListE;
	
};

