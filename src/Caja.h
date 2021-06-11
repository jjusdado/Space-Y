
#pragma once

#include "Pared.h"

class Caja  
{
	friend class Interaccion;
public:
	void dibuja();
	Caja();
	virtual ~Caja();
private:
	Pared suelo;
	Pared techo;
	Pared pared_izq;
	Pared pared_dcha;

};

