#include "Vida.h"
#include "glut.h"

Vida::Vida():sprite("imagenes/Ship5.png", 1)
{
	sprite.setCenter(0, 0);
	sprite.setSize(2, 2);
}

Vida::~Vida()
{

}

void Vida::dibuja()
{
	glPushMatrix();
	glTranslatef(-12, 13, 0);
	glColor3f(1.0f, 1.0f, 1.0f);

	sprite.draw();

	glPopMatrix();
}

void Vida::restarVida()
{
	vidas--;
}