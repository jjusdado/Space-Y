#pragma once
#include "ObjetoMovil.h"
#include "Vector2D.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Disparo :public ObjetoMovil 
{
	friend class Interaccion;
public:
	virtual void dibuja();
	Disparo();
	virtual ~Disparo();
	float getRadio(){return radio;}
	void setPos(float ix,float iy, float ox, float oy);
	void mueve(float t);

protected:
	SpriteSequence sprite;
	float radio;
};
