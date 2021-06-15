

#include "Hombre.h"
#include "glut.h"


Hombre::Hombre():sprite("imagenes/Ship5.png",1)
{
	sprite.setCenter(0,0);
	sprite.setSize(2,2);
	altura=1.8f;
	posicion.y = 7.5f;
	posicion.x = -10.0f;
	aceleracion.y = 0; //sin gravedad la nave
}

Hombre::~Hombre()
{

}

void Hombre::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x,posicion.y,0.5);
   	glColor3f(1.0f,1.0f,1.0f);

	if((velocidad.y<0.01)&&(velocidad.y>-0.01))
		sprite.setState(0);
	else if (sprite.getState()==0)
		sprite.setState(1,false);
	sprite.draw();

	glPopMatrix();

}

void Hombre::mueve(float t)
{
	ObjetoMovil::mueve(t);
	sprite.loop();
}

void Hombre::restarvida()
{
	vidas--;
}
