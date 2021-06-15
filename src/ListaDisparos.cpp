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

/*bool ListaDisparos::agregar(DisparoEspecial* de)
{
	for (int i = 0; i < numero; i++)//para evitar que se añada una esfera ya existente
		if (lista[i] == de)
			return false;

	if (numero < MAX_DISPAROS)
		lista[numero++] = de;
	else
		return false;
	return true;
}*/

void ListaDisparos::colision(Pared p)
{
	for(int i=0;i<numero;i++)
	{
		if(Interaccion::colision(*(lista[i]),p))
		{
			lista[i]->setVel(0,0);
			eliminar(i);
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
			eliminar(i);
		}
	}
}

Disparo* ListaDisparos::operator [](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;

	return lista[i];
}


void ListaDisparos::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete lista[i];
	
	numero = 0;
}

void ListaDisparos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))
		return;

	delete lista[index];

	numero = numero - 1;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
	
}

void ListaDisparos::eliminar(Disparo* e)
{
	for (int i = 0; i < numero; i++)
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
}
/*void ListaDisparos::eliminar(DisparoEspecial* de)
{


}*/