#include "Obstaculo.h"
#include "glut.h"


Obstaculo::Obstaculo() :sprite("imagenes/Meteor_02.png", 1)
{
	sprite.setCenter(0, 0);
	sprite.setSize(1, 1);
	radio = 0.5f;
	color.b = color.g = color.r = 255;
	velocidad.x = -5.0f;
}

Obstaculo::~Obstaculo()
{

}

Obstaculo::Obstaculo(float rad, float x, float y) :sprite("imagenes/Meteor_02.png", 1)
{
	sprite.setCenter(0, 0);
	sprite.setSize(1, 1);
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = -5.0f;
}

void Obstaculo::dibuja()
{	
	glTranslatef(posicion.x, posicion.y, 0);
	sprite.draw();
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

