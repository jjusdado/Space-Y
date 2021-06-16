
#pragma once

#include "Pared.h"

class Caja  
{
	friend class Interaccion;
public:
	void dibuja(int i);
	Caja();
	virtual ~Caja();
private:
	Pared suelo;
	Pared techo;
	Pared pared_izq;
	Pared pared_dcha;

};

