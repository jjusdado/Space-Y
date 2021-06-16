#include "Interaccion.h"
#include <cmath>

Interaccion::Interaccion(void)
{
}


Interaccion::~Interaccion(void)
{
}

void Interaccion::rebote(Hombre &h, Caja c)
{
	float xmin=c.pared_dcha.limite1.y;
	float xmax=c.pared_dcha.limite2.y;
	if(h.posicion.y>xmax-1.8){   //el -1.8 es para que se vea el sprite entero (sino se queda justo por encima)
		h.posicion.y=xmax-1.8;
		h.velocidad.y=0;
	}
	if(h.posicion.y<xmin+0.4f){
		h.posicion.y=xmin+0.4f;
		h.velocidad.y=0;
	}
}


bool Interaccion::colision(Obstaculo o, Hombre h)
{

	float distancia=(o.posicion-h.posicion).modulo();
	if(distancia<0.5f+o.radio)
		return true;	
	return false;
}
bool Interaccion::colision(Disparo d, Pared p)
{
	Vector2D pos=d.getPos();
	float dist=p.distancia(pos);
	if(dist<d.getRadio())
		return true;
	return false;
}
bool Interaccion::colision(Disparo d, Caja c)
{
	//utilizo la funcion anterior
	return colision(d,c.pared_izq);
}

bool Interaccion::colision(Obstaculo o, Disparo d)
{
	float distancia = (d.posicion - o.posicion).modulo();
	if (distancia < (d.radio+o.radio))
		return true;
	return false;
}

bool Interaccion::colision(Obstaculo o, DisparoEspecial de)
{

	float distancia = (de.posicion - o.posicion).modulo();
	if (distancia < (de.radio + o.radio))
		return true;
	return false;
}

//listaobstaculo con listadisparos

bool Interaccion::colision(ListaObstaculo& o, ListaDisparos& d, Bonus& b) {

	

	int numo = o.getNumero();
	int numd = d.getNumero();
	for (int i = numo-1; i >=  0; i--)
		for (int j = numd-1; j >= 0; j--)
			if (Interaccion::colision(*o.lista[i], *d.lista[j])) {
				Vector2D posb = d.lista[j]->getPos();
				o.eliminar(i);
				d.eliminar(j);
				
				int r = ETSIDI::lanzaDado(6,1);
				if (r == 3 ) {
					b.setPos(posb.x, posb.y);
					return true;
				}
				ETSIDI::play("sonidos/explosion fireworks1.wav");
			}
	return false;
}

bool Interaccion::colision(Hombre h, Bonus b) {
	float distancia = (h.getPos() - b.getPos()).modulo();
	if (distancia < b.getRadio()+1)
		return true;
	return false;
}

bool Interaccion::rebote(Obstaculo& o, Pared p)
{
	Vector2D dir;
	float dif = p.distancia(o.posicion, &dir) - o.radio;
	if (dif <= 0.0f)
	{
		
		return true;
	}
	return false;
}