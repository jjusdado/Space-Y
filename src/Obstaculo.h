#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "ObjetoMovil.h"
#include "ETSIDI.h"
using ETSIDI::SpriteSequence;

class Obstaculo :public ObjetoMovil
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
	
		//Vector2D posicion;
	
};

