
#include "Bonus.h"
#include <stdlib.h>
#include "glut.h"


Bonus::Bonus()
{
	//movimiento gravitatorio
	//velocidad vertical inicial
	aceleracion.y=-9.8f;
	velocidad.y=5;
	lado=0.5f;
}

Bonus::~Bonus()
{

}

void Bonus::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x,posicion.y,0);
	glRotatef(30,1,1,1);
	glColor3f(	rand()/(float)RAND_MAX,
			rand()/(float)RAND_MAX,
			rand()/(float)RAND_MAX);//color aleatorio
    	glutSolidCube(lado);
	glPopMatrix();

}

