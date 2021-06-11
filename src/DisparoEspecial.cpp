#include "DisparoEspecial.h"
#include "glut.h"

DisparoEspecial::DisparoEspecial(void)
{
	radio=0.4f;
	velocidad.y=15;
}


DisparoEspecial::~DisparoEspecial(void)
{
}
void DisparoEspecial::dibuja()
{
	glColor3f(1.0f,1.0f,0.0f);

	glDisable(GL_LIGHTING);
	glLineWidth(2.0f);

	glBegin(GL_LINES);
		glVertex3f(origen.x-0.1,origen.y,0);
		glVertex3f(posicion.x-0.1,posicion.y,0);
		glVertex3f(origen.x+0.1,origen.y,0);
		glVertex3f(posicion.x+0.1,posicion.y,0);
	glEnd();
	glEnable(GL_LIGHTING);
	glLineWidth(1.0f);

	glPushMatrix();
	glTranslatef(posicion.x,posicion.y,0);

   	glutSolidSphere(radio, 20, 20);
	glPopMatrix();
}