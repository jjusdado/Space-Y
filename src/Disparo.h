
#pragma once
#include "ObjetoMovil.h"
#include "Vector2D.h"

class Disparo :public ObjetoMovil 
{
	friend class Interaccion;
public:
	void dibuja();
	Disparo();
	virtual ~Disparo();
	float getRadio(){return radio;}
	void setPos(float ix,float iy);
protected:
	float radio;
	Vector2D origen;
};
