

#include "Disparo.h"
#include "glut.h"
//////////////////////////////////////////////////////////////////////
//////////////////// Construction/Destruction ////////////////////////
//////////////////////////////////////////////////////////////////////

Disparo::Disparo()
{
	radio=0.25f;
	velocidad.x=5.0f;
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

	glPushMatrix();
	glTranslatef(posicion.x,posicion.y,0);

   	glutSolidSphere(radio, 20, 20);
	glPopMatrix();

}
/*void Disparo::setPos(float ix,float iy)
{
	ObjetoMovil::setPos(ix,iy);
	origen=posicion;
}	*/

