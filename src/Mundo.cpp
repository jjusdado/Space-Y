#include "Mundo.h"
#include "glut.h"
#include <cmath>
#include "Interaccion.h"
#include "ETSIDI.h"

Mundo::~Mundo()
{
	obstaculos.destruirContenido();
	disparos.destruirContenido();
}

void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}

void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo

		//funci�n obst�culos
	/*
	int j = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int k = 0; k < ETSIDI::lanzaDado(3, 1); k++) //de 1 a 3 obstaculos por columna  
		{
			obstaculos.agregar(new Obstaculo(0.5f, j, ETSIDI::lanzaDado(15, 1)));
		}
		j = j + 3;
	}

	*/
	caja.dibuja();
	hombre.dibuja();
	disparos.dibuja();	
	bonus.dibuja();
	//disparo_especial.dibuja();	
	obstaculos.dibuja();
	vidas.dibuja();

	ETSIDI::setTextColor(1,1,0);
	ETSIDI::setFont("fuentes/Bitwise.ttf",16);
	ETSIDI::printxy("SPACE Y", -10,17);
	
	ETSIDI::setTextColor(1,1,1);
	ETSIDI::setFont("fuentes/Bitwise.ttf",12);
	ETSIDI::printxy("Christian, Dani, Dani, Juan y Pedro",-10,16.4);

	if (nivel == 1){
		ETSIDI::setTextColor(0, 0, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
		ETSIDI::printxy("Nivel 1", 10, -2);
	}
	else if (nivel == 2){
	ETSIDI::setTextColor(0, 0, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
	ETSIDI::printxy("Nivel 2", 10, -2);
	}
	else if (nivel == 3){
	ETSIDI::setTextColor(0, 0, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
	ETSIDI::printxy("Nivel 3", 10, -2);
	}

	}

void Mundo::mueve()
{
	disparo_especial.mueve(0.025f);
	if(Interaccion::colision(disparo_especial,plataforma))
		disparo_especial.setVel(0,0);

	hombre.mueve(0.025f);
	bonus.mueve(0.025f);

	disparos.mueve(0.025f);
	disparos.colision(caja);
	disparos.colision(plataforma);

	obstaculos.mueve(0.025f);

	Obstaculo *aux=obstaculos.colision(hombre);
	if(aux!=0){
		vidas.restarVida();
		obstaculos.eliminar(aux);
		ETSIDI::play("sonidos/impacto.wav");
	}
	
	//eliminaci�n obstaculo

	if (Interaccion::colision(obstaculos, disparos, bonus))
	{
		bonus.dibuja();
	}

	if (Interaccion::colision(hombre, bonus)) 
	{
	//aqui se crea el disparo especial
	 cargadorEsp = 5;  //carga 5 disparos especiales
	 
	 bonus.setPos(100, 100);
	 bonus.dibuja();
	 ETSIDI::play("sonidos/Bonus.mp3");
	}

	obstaculos.rebote(pared_detras);
	Interaccion::rebote(hombre,caja);

	//if (obstaculos.getNumero() == 0) cargarNivel();
}

void Mundo::inicializa()
{
	x_ojo=0;
	y_ojo=7.5;
	z_ojo=30;

	pared_detras.setPos(-15.0f, 0, -15.0f, 15.0f);

	Vector2D pos = hombre.getPos();
	vidas.vidas = 3;
	nivel = 0;
	cargarNivel();
	/*
	int j = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int k = 0; k < ETSIDI::lanzaDado(3, 1); k++) //de 1 a 3 obstaculos por columna  
		{
			obstaculos.agregar(new Obstaculo(0.5f, j, ETSIDI::lanzaDado(15, 1)));
		}
		j = j + x;
	}
	nivel = 0;
	*/
}

void Mundo::tecla(unsigned char key)
{
		switch(key)
	{
		case ' ':
		{
			if (cargadorEsp > 0) {  //si el cargador de disparos especiales est� lleno

				DisparoEspecial* d1 = new DisparoEspecial;
				Vector2D pos = hombre.getPos();
				d1->setPos(pos.x, pos.y, pos.x, pos.y);

				disparos.agregar(d1);
				cargadorEsp--;            //gasta un disparo especial con cada pulsacion del espacio
				break;
			}
			else {
				if (disparos.getNumero() < 1) {
					Disparo* d = new Disparo();
					Vector2D pos = hombre.getPos();
					d->setPos(pos.x, pos.y, pos.x, pos.y);
					disparos.agregar(d);
					ETSIDI::play("sonidos/explosion fireworks1.wav");
					break;
				}
				break;
			}
		}
		case 's':
		{
			DisparoEspecial* d1 = new DisparoEspecial;
			Vector2D pos = hombre.getPos();
			d1->setPos(pos.x, pos.y, pos.x, pos.y);

			disparos.agregar(d1);
			ETSIDI::play("sonidos/explosion fireworks2.wav");
			break;
		}
	}
}

void Mundo::teclaEspecial(unsigned char key)
{
	switch(key)
	{
	case GLUT_KEY_UP:
		hombre.setVel(0.0f, 5.0f);
		break;
	case GLUT_KEY_DOWN:
		hombre.setVel(0.0f, -5.0f);
		break;
	}
}

int Mundo::getNumObstaculos()
{
	numeroObstaculos = obstaculos.getNumero();
	return numeroObstaculos;
}

bool Mundo::cargarNivel()
{
	nivel++;
	ETSIDI::play("sonidos/NEXTLEVEL.wav");
	hombre.setPos(-8, 0);
	obstaculos.destruirContenido();
	disparos.destruirContenido();
	if (nivel == 1)
	{
		obstaculos.nivel = 0;
		//x = 3;
		int j = 0;
		for (int i = 0; i < 100; i++)
		{
			for (int k = 0; k < ETSIDI::lanzaDado(3, 1); k++) //de 1 a 3 obstaculos por columna  
			{
				obstaculos.agregar(new Obstaculo(0.5f, j, ETSIDI::lanzaDado(15, 1), -5.0f));
			}
			j = j + 3;
		}
		
	}
	if (nivel == 2)
	{
		obstaculos.nivel = 1;
	
		int j = 0;
		for (int i = 0; i < 100; i++)
		{
			for (int k = 0; k < ETSIDI::lanzaDado(3, 1); k++) //de 1 a 3 obstaculos por columna  
			{
				obstaculos.agregar(new Obstaculo(0.5f, j, ETSIDI::lanzaDado(15, 1),-6.5f));
			}
			j = j + 2;
		}
		
	}
	if (nivel == 3)
	{
		
		int j = 0;
		for (int i = 0; i < 100; i++)
		{
			for (int k = 0; k < ETSIDI::lanzaDado(3, 1); k++) //de 1 a 3 obstaculos por columna  
			{
				obstaculos.agregar(new Obstaculo(0.5f, j, ETSIDI::lanzaDado(15, 1), -8.0f));
			}
			j = j + 1;
		}
		
	}
	if (nivel <= 3)
		return true;
	return false;
}
