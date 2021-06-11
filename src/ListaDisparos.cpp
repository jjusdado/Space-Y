// ListaDisparos.cpp: implementation of the ListaDisparos class.
//
//////////////////////////////////////////////////////////////////////

#include "ListaDisparos.h"
#include "Interaccion.h"

ListaDisparos::ListaDisparos()
{

}

ListaDisparos::~ListaDisparos()
{

}

void ListaDisparos::dibuja()
{
	for(int i=0;i<numero;i++)
		lista[i]->dibuja();
}

void ListaDisparos::mueve(float t)
{
	for(int i=0;i<numero;i++)
		lista[i]->mueve(t);
}

void ListaDisparos::destruirContenido()
{
	for(int i=0;i<numero;i++)
		delete lista[i];

	numero=0;
}

bool ListaDisparos::agregar(Disparo *d)
{
	for(int i=0;i<numero;i++)//para evitar que se añada una esfera ya existente
		if(lista[i]==d)
			return false;

	if(numero<MAX_DISPAROS)
	   lista[numero++]=d;
	else 
		return false;
	return true;
}
void ListaDisparos::colision(Pared p)
{
	for(int i=0;i<numero;i++)
	{
		if(Interaccion::colision(*(lista[i]),p))
		{
			lista[i]->setVel(0,0);
		}
	}
}
void ListaDisparos::colision(Caja c)
{
	for(int i=0;i<numero;i++)
	{
		if(Interaccion::colision(*(lista[i]),c))
		{
			lista[i]->setVel(0,0);
			
		}
	}
}
