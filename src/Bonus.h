#pragma once

#include "ETSIDI.h"
#include "ObjetoMovil.h"
#include "Vector2D.h"

using ETSIDI::SpriteSequence;

class Bonus : public ObjetoMovil
{
	friend class Interaccion;
public:
	void dibuja();
	Bonus();
	virtual ~Bonus();
	float getRadio() { return radio; }
protected:
	float radio;
	SpriteSequence sprite;
};

