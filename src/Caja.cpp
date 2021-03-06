

#include "Caja.h"
#include "ETSIDI.h"


Caja::Caja()
{
	suelo.setColor(000,000,000);
	suelo.setPos(-15.0f,0,100.0f,0.0f);

	techo.setColor(000,000,000);
	techo.setPos(-15.0f,15.0f,100.0f,15.0f);

	pared_dcha.setColor(0, 150, 0);
	pared_dcha.setPos(-15.0f, 0, -15.0f, 15.0f);

	pared_izq.setColor(0, 150, 0);
	pared_izq.setPos(15.0f, 0, 15.0f, 15.0f);
}

Caja::~Caja()
{

}

void Caja::dibuja(int n)
{
	suelo.dibuja();
	techo.dibuja();
	pared_izq.dibuja();
	pared_dcha.dibuja();
	//dibujo del fondo
	if (n == 1) {
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo_2.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);		glVertex3f(-20, 0, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(20, 0, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(20, 15, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-20, 15, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	if (n == 2) {
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondonv2.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);		glVertex3f(-20, 0, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(20, 0, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(20, 15, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-20, 15, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	if (n == 3) {
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondonv3.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);		glVertex3f(-20, 0, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(20, 0, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(20, 15, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-20, 15, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
}
