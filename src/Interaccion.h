#pragma once

#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include "Disparo.h"

class Interaccion  
{
public:
	
	Interaccion();
	virtual ~Interaccion();	

	//funciones que modifican (paso por referencia) los objetos que se les pasa como parametro	
	static bool rebote(Esfera& e, Pared p);
	static void rebote(Esfera& e, Caja c);
	static void rebote(Hombre& h, Caja c);
	static bool rebote(Esfera& e1, Esfera& e2);

	//funciones de informacion, no cambian los objetos, solo devuelven true si hay colision
	static bool colision(Esfera e, Hombre h);
	static bool colision(Disparo d, Pared p);
	static bool colision(Disparo d, Caja c);


};

