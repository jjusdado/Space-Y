#include "ListaObstaculo.h"
#include "Interaccion.h"

ListaObstaculo::ListaObstaculo(void)
{
	numero = 0;
	for (int i = 0; i < MAX_OBSTACULOS+200*nivel; i++)
		lista[i] = 0;
}


ListaObstaculo::~ListaObstaculo(void)
{

}

bool ListaObstaculo::agregar(Obstaculo* e)
{
	for (int i = 0; i < numero; i++)//para evitar que se añada una esfera ya existente
		if (lista[i] == e)
			return false;

	if (numero < MAX_OBSTACULOS)
		lista[numero++] = e;
	else
		return false;
	return true;
}

void ListaObstaculo::dibuja()
{
	for (int i = 0; i < numero; i++)
		lista[i]->dibuja();
}

void ListaObstaculo::mueve(float t)
{
	for (int i = 0; i < numero; i++)
		lista[i]->mueve(t);
}

/*
void ListaObstaculo::rebote(Caja caja)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), caja);

}

void ListaObstaculo::rebote()
{
	for (int i = 0; i < numero - 1; i++)
		for (int j = i + 1; j < numero; j++)
			Interaccion::rebote(*(lista[i]), *(lista[j]));
}

void ListaObstaculo::rebote(Pared p)
{
	for (int i = 0; i < numero; i++)
		Interaccion::rebote(*(lista[i]), p);
}



*/
Obstaculo* ListaObstaculo::colision(Hombre h)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), h))
			return lista[i];
	}
	return 0; //no hay colisión

}

Obstaculo* ListaObstaculo::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}

void ListaObstaculo::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];

	numero = 0;
}

void ListaObstaculo::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;

	delete lista[index];

	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];

}

void ListaObstaculo::eliminar(Obstaculo* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}

}

Obstaculo* ListaObstaculo::colision(Disparo d)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), d))
			return lista[i];
	}
	return 0; //no hay colisión

}

/*Obstaculo* ListaObstaculo::colision(DisparoEspecial de)
{
	for (int i = 0; i < numero; i++)
	{
		if (Interaccion::colision(*(lista[i]), de))
			return lista[i];
	}
	return 0; //no hay colisión

}*/