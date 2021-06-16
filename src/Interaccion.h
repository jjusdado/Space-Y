#pragma once
#include "Hombre.h"
#include "Caja.h"
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
	static void rebote(Hombre& h, Caja c);
	static bool colision(ListaObstaculo& o, ListaDisparos& d, Bonus& b);
	static bool rebote(Obstaculo& o, Pared p);

	//funciones de informacion, no cambian los objetos, solo devuelven true si hay colision
	static bool colision(Obstaculo o, Hombre h);
	static bool colision(Disparo d, Pared p);
	static bool colision(Disparo d, Caja c);
	static bool colision(Obstaculo o, Disparo d);
	static bool colision(Obstaculo o, DisparoEspecial de);
	static bool colision(Hombre h, Bonus b);
};

