
#include "Bonus.h"
#include <stdlib.h>
#include "glut.h"


Bonus::Bonus()
{
	radio = 0.5f;
	velocidad.x = -3.0f;
	setColor(0, 0, 255);
	posicion.x = posicion.y = -100;
}
Bonus::~Bonus()
{

}

void Bonus::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
	glPopMatrix();
}

void Bonus::setColor(Byte r, Byte v, Byte a)
{
	color.set(r, v, a);
}