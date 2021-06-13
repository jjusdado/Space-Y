
#include "Obstaculo.h"
#include "glut.h"


Obstaculo::Obstaculo()
{

	radio = 0.5f;
	//color.b = color.g = color.r = 255;
	velocidad.x = -5.0f;
}

Obstaculo::~Obstaculo()
{

}
Obstaculo::Obstaculo(float rad, float x, float y)

{
	
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = -5.0f;
}
void Obstaculo::dibuja()
{
	
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}


void Obstaculo::setRadio(float r)
{
	if (r < 0.1F)
		r = 0.1F;
	radio = r;
}

void Obstaculo::setColor(Byte r, Byte v, Byte a)
{
	color.set(r, v, a);
}

