#pragma once
#include "ObjetoMovil.h"
#include "Vector2D.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;
class Disparo :public ObjetoMovil 
{
	friend class Interaccion;
public:
	void dibuja();
	Disparo();
	virtual ~Disparo();
	float getRadio(){return radio;}
	void setPos(float ix,float iy, float ox, float oy);
protected:
	SpriteSequence sprite;
	float radio;

};
