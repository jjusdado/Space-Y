#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class Obstaculo :public ObjetoMovil
{
friend class Interaccion;
public:
	Obstaculo();
	Obstaculo(float rad, float x, float y, float v, int n);
	virtual ~Obstaculo();
	void dibuja();
	void setRadio(float r);
		
protected:
	float radio;
	SpriteSequence sprite1, sprite2, sprite3;
	int nivel;
};