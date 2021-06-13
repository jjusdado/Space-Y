
#pragma once

#define MAX_DISPAROS 10
#include "Disparo.h"
#include "Caja.h"

class ListaDisparos  
{
	friend class Interaccion;
public:
	ListaDisparos();
	virtual ~ListaDisparos();
	
	bool agregar(Disparo* d);
	void mueve(float t);
	void dibuja();

	void eliminar(Disparo* e);
	void eliminar(int index);
	void destruirContenido();


	void colision(Pared p);
	void colision(Caja c);

	int getNumero() { return numero; }
	Disparo* operator[] (int index);

private:
	Disparo * lista[MAX_DISPAROS];
	int numero;
};
