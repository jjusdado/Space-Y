

#include "Esfera.h"
#include "glut.h"


Esfera::Esfera()
{
	radio=1.0f;
	aceleracion.y=-9.8f;
	velocidad.x=0;
	velocidad.y=0;
}

Esfera::~Esfera()
{

}
Esfera::Esfera(float rad, float x, float y, float vx, float vy)
{
	radio=rad;
	posicion.x=x;
	posicion.y=y;
	velocidad.x=vx;
	velocidad.y=vy;
	setColor(255,255,100);
	aceleracion.y=-9.8;
}
void Esfera::dibuja()
{
	color.ponColor();
	glTranslatef(posicion.x,posicion.y,0);
	glutSolidSphere(radio,20,20);
	glTranslatef(-posicion.x,-posicion.y,0);
}

void Esfera::setColor( Byte r,Byte v, Byte a)
{
	color.set(r,v,a);
}
void Esfera::setRadio(float r)
{
	if(r<0.1F)
		r=0.1F;
	radio=r;
}	

