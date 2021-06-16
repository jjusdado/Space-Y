#pragma once
#include "ETSIDI.h"
#include "Vector2D.h"
#include "ObjetoMovil.h"

using ETSIDI::SpriteSequence;
class Hombre: public ObjetoMovil
{
	friend class Interaccion;
public:
	void mueve(float t);
	void dibuja();
	Hombre();
	virtual ~Hombre();
	

private:
	SpriteSequence sprite;



};

