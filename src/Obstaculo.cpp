#include "Obstaculo.h"
#include "glut.h"


Obstaculo::Obstaculo() :sprite1("imagenes/Meteor_02.png", 1), sprite2("imagenes/Meteor_05.png", 1), sprite3("imagenes/Meteor_03.png", 1)
{
	sprite1.setCenter(0, 0);
	sprite1.setSize(1, 1);
	sprite2.setCenter(0, 0);
	sprite2.setSize(1, 1);
	sprite3.setCenter(0, 0);
	sprite3.setSize(1, 1);
	radio = 1.0f;
	velocidad.x = -5.0f;
}

Obstaculo::~Obstaculo()
{

}

Obstaculo::Obstaculo(float rad, float x, float y, float v, int n) :sprite1("imagenes/Meteor_02.png", 1), sprite2("imagenes/Meteor_05.png", 1), sprite3("imagenes/Meteor_03.png", 1)
{
	sprite1.setCenter(0, 0);
	sprite1.setSize(1, 1);
	sprite2.setCenter(0, 0);
	sprite2.setSize(1, 1);
	sprite3.setCenter(0, 0);
	sprite3.setSize(1, 1);
	radio = rad;
	posicion.x = x;
	posicion.y = y;
	velocidad.x = v;
	nivel = n;
}

void Obstaculo::dibuja()
{	
	glTranslatef(posicion.x, posicion.y, 0);
	if (nivel == 1)
		sprite1.draw();
	if (nivel == 2)
		sprite2.draw();
	if (nivel == 3)
		sprite3.draw();
	glTranslatef(-posicion.x, -posicion.y, 0);
}


void Obstaculo::setRadio(float r)
{
	if (r < 0.1F)
		r = 0.1F;
	radio = r;
}
