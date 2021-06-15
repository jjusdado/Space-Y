#pragma once
#include "ETSIDI.h"

#define MAX_VIDAS 3

using ETSIDI::SpriteSequence;
class Vida
{
public:
	int vidas;
	Vida();
	virtual ~Vida();
	void restarVida();
	void sumarVida();
	void dibuja();
private:
	SpriteSequence sprite1;
	SpriteSequence sprite2;
	SpriteSequence sprite3;
};

