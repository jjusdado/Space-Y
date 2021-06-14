#pragma once
#include "ObjetoMovil.h"
#include "disparo.h"
class DisparoEspecial :
	public Disparo
{
public:
	DisparoEspecial(void);
	virtual ~DisparoEspecial(void);
	void dibuja();
};

