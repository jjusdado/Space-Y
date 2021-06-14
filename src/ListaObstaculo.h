#pragma once

#define MAX_OBSTACULOS 100

#include "Obstaculo.h"
#include "Caja.h"
#include "Hombre.h"
#include "Disparo.h"


class ListaObstaculo
{
	friend class Interaccion;
public:
	ListaObstaculo(void);
	~ListaObstaculo(void);

	void mueve(float t);
	void dibuja();

	bool agregar(Obstaculo* e);
	void eliminar(Obstaculo* e);
	void eliminar(int index);
	void destruirContenido();

	Obstaculo* colision(Disparo d);
	
	//Obstaculo* colision(DisparoEspecial de);
	
	//Obstaculo* colision(Hombre h);
	//void rebote(Pared p);
	//void rebote();
	//void rebote(Caja caja);

	int getNumero() { return numero; }
	Obstaculo* operator[] (int index);

private:
	Obstaculo* lista[MAX_OBSTACULOS];
	int numero;
};

