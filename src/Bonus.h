#pragma once

#include "ObjetoMovil.h"
#include "Vector2D.h"
#include "ColorRGB.h"

class Bonus : public ObjetoMovil 
{
	friend class Interaccion;
public:
	void dibuja();	
	Bonus();
	virtual ~Bonus();
	float getRadio() { return radio; }
	void setColor(Byte r, Byte v, Byte a);
protected:	
	float radio;
	ColorRGB color;
};

