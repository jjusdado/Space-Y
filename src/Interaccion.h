#pragma once

#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include "Disparo.h"
#include "Obstaculo.h"
#include "ListaObstaculo.h"
#include "ListaDisparos.h"
#include "Bonus.h"
#include "ETSIDI.h"

class Interaccion  
{
public:

	Bonus bonus;
	
	Interaccion();
	virtual ~Interaccion();	

	//funciones que modifican (paso por referencia) los objetos que se les pasa como parametro	
	static bool rebote(Esfera& e, Pared p);
	static void rebote(Esfera& e, Caja c);
	static void rebote(Hombre& h, Caja c);
	static bool rebote(Esfera& e1, Esfera& e2);
	static bool colision(ListaObstaculo& o, ListaDisparos& d, Bonus& b);

	//funciones de informacion, no cambian los objetos, solo devuelven true si hay colision
	static bool colision(Esfera e, Hombre h);
	static bool colision(Disparo d, Pared p);
	static bool colision(Disparo d, Caja c);
	static bool colision(Obstaculo o, Disparo d);
	static bool colision(Obstaculo o, DisparoEspecial de);

	static bool colision(Hombre h, Bonus b);

};

