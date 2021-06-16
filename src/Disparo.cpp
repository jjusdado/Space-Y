#include "Disparo.h"
#include "glut.h"
//////////////////////////////////////////////////////////////////////
//////////////////// Construction/Destruction ////////////////////////
//////////////////////////////////////////////////////////////////////

Disparo::Disparo() :sprite("imagenes/Missile_1.png", 10)
{
	sprite.setCenter(0, 0);
	sprite.setSize(1, .5f);
	radio = 0.25f;
	velocidad.x = 5.0f;
}

Disparo::~Disparo()
{

}

void Disparo::dibuja()
{
	glColor3f(1.0f, 1.0f, 1.0f);

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

void Disparo::setPos(float ix, float iy, float ox, float oy)
{
	ObjetoMovil::setPos(ix, iy);
	origen = posicion;
}

void Disparo::mueve(float t)
{
	ObjetoMovil::mueve(t);
	sprite.loop();
}

