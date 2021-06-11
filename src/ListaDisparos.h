
#pragma once

#define MAX_DISPAROS 10
#include "Disparo.h"
#include "Caja.h"

class ListaDisparos  
{
public:
	ListaDisparos();
	virtual ~ListaDisparos();
	
	bool agregar(Disparo* d);
	void destruirContenido();
	void mueve(float t);
	void dibuja();

	void colision(Pared p);
	void colision(Caja c);

private:
	Disparo * lista[MAX_DISPAROS];
	int numero;
};
