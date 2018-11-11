#pragma once
class Principal
{
public:
	Principal();
	~Principal();
	//void EventoRealisado(EventoID,cantAsistente);
	//void CancelarEvento(EventoID);
	//BuscarEventoTipo(tipo);
	//BuscarEventoCiudad(Ciudad);
	//BuscarAdmin();
	void LecturaDeArchivos();
	void Menu();
	void MenuAgregar();
	void MenuAdministrar();
	void MenuBuscar();
	void Despedidos();
	void ExpandirLista();
	void ReducirLista();

	//Funciones Requerimientos funcionales
	void AgregarEvento();
	void AgregarCliente();
	void AgregarAdmin();
	
	void BuscarPorEventos();
	void BuscarClientes();
	void DesplegarAdmins();

	void RealizarEvento();
	void CancelarEvento();

	void ArchivoSalida();
	
};

