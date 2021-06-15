/*#pragma once

#define MAX_ESFERAS 100

#include "Esfera.h"
#include "Caja.h"
#include "Hombre.h"


class ListaEsferas
{
public:
	ListaEsferas(void);
	~ListaEsferas(void);

	void mueve(float t);
	void dibuja();

	bool agregar(Esfera* e);
	void eliminar(Esfera* e);
	void eliminar(int index);
	void destruirContenido();

	Esfera* colision(Hombre h);
	void rebote(Pared p);
	void rebote();
	void rebote(Caja caja);

	int getNumero(){return numero;}
	Esfera* operator[] (int index);

private:
	Esfera * lista[MAX_ESFERAS];
	int numero;
};
*/
