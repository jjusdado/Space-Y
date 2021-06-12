#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

class Obstaculo
{

		friend class Interaccion;
	public:
		Obstaculo();
		Obstaculo(float rad, float x, float y);
		virtual ~Obstaculo();
		void dibuja();
		void setColor(Byte r, Byte v, Byte a);
		void setRadio(float r);
	protected:
		ColorRGB color;
		float radio;
		Vector2D posicion;
	
};

