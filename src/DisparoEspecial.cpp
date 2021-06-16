#include "DisparoEspecial.h"
#include "glut.h"

DisparoEspecial::DisparoEspecial(void) :sprite("imagenes/Missile_2.png", 10)
{
	sprite.setCenter(0, 0);
	sprite.setSize(1.5f, .75f);
	radio = 0.4f;
	velocidad.x = 15;
}

DisparoEspecial::~DisparoEspecial(void)
{
}

void DisparoEspecial::dibuja()
{
	glColor3f(1.0f, 1.0f, 0.0f);

	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	if (velocidad.x > 0.01)sprite.flip(false, false);
	if (velocidad.x < -0.01)sprite.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);
	sprite.draw();
	glPopMatrix();
}