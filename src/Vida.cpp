#include "Vida.h"
#include "glut.h"

Vida::Vida():sprite1("imagenes/Ship5.png", 1), sprite2("imagenes/Ship5.png", 1), sprite3("imagenes/Ship5.png", 1)
{
	sprite1.setCenter(0, 0);
	sprite1.setSize(2, 2);
	sprite2.setCenter(0, 0);
	sprite2.setSize(2, 2);
	sprite3.setCenter(0, 0);
	sprite3.setSize(2, 2);
}

Vida::~Vida()
{

}

void Vida::dibuja()
{
		if (vidas >= 1) {
			glPushMatrix();
			glTranslatef(-12, 13, 0);
			glColor3f(1.0f, 1.0f, 1.0f);

			sprite1.draw();

			glPopMatrix();
		}
		if (vidas >= 2 )
		{
			glPushMatrix();
			glTranslatef(-10, 13, 0);
			glColor3f(1.0f, 1.0f, 1.0f);

			sprite2.draw();

			glPopMatrix();
		}
		if (vidas == 3) {
			glPushMatrix();
			glTranslatef(-8, 13, 0);
			glColor3f(1.0f, 1.0f, 1.0f);

			sprite3.draw();
			glPopMatrix();
		}
}

void Vida::restarVida()
{
	vidas--;
}

void Vida::sumarVida()
{
	if (vidas < MAX_VIDAS)
		vidas++;
}