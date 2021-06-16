
#include "Bonus.h"
#include <stdlib.h>
#include "glut.h"


Bonus::Bonus() :sprite("imagenes/klipartz.com.png", 1)
{
	sprite.setCenter(0, 0);
	sprite.setSize(1, 1);
	radio = 0.8f;
	velocidad.x = -3.0f;
	posicion.x = posicion.y = -100;
}
Bonus::~Bonus()
{

}

void Bonus::dibuja()
{
	glTranslatef(posicion.x, posicion.y, 0);
	sprite.draw();
	glTranslatef(-posicion.x, -posicion.y, 0);
}