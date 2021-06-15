#pragma once
#include "ETSIDI.h"

#define MAX_VIDAS 3

using ETSIDI::SpriteSequence;
class Vida
{
public:
	int vidas = 1;
	Vida();
	virtual ~Vida();
	void restarVida();
	void dibuja();
private:
	SpriteSequence sprite;
};

