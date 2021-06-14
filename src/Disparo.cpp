

#include "Disparo.h"
#include "glut.h"
//////////////////////////////////////////////////////////////////////
//////////////////// Construction/Destruction ////////////////////////
//////////////////////////////////////////////////////////////////////

Disparo::Disparo() :sprite("imagenes/Missile_1_Flying_000.png", 1)
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
	glColor3f(1.0f,1.0f,1.0f);

	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
		glVertex3f(origen.x,origen.y,0);
		glVertex3f(posicion.x,posicion.y,0);
	glEnd();
	glEnable(GL_LIGHTING);

	if ((velocidad.y < 0.01) && (velocidad.y > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);
	sprite.draw();

	glPushMatrix();
	glTranslatef(posicion.x,posicion.y,0);

   	glutSolidSphere(radio, 20, 20);
	glPopMatrix();

}
void Disparo::setPos(float ix, float iy, float ox, float oy)
{
	ObjetoMovil::setPos(ix, iy);
	origen = posicion;
}

