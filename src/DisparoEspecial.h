#pragma once
#include "ObjetoMovil.h"
#include "disparo.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class DisparoEspecial :	public Disparo
{
public:
	DisparoEspecial(void);
	virtual ~DisparoEspecial(void);
	void dibuja();

private:
	SpriteSequence sprite;
};

