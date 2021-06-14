
#include "Bonus.h"
#include <stdlib.h>
#include "glut.h"


Bonus::Bonus()
{
	//movimiento gravitatorio
	//velocidad vertical inicial
	
	velocidad.x=-5.0f;
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

