#include "Caja.h"	
#include "Hombre.h"	
#include "Esfera.h"	
#include "Bonus.h"	
#include "Disparo.h"
#include "ListaEsferas.h"	
#include "ListaDisparos.h"	
#include "EsferaPulsante.h"
#include "DisparoEspecial.h"
#include "Obstaculo.h"
#include "ListaObstaculo.h"
#include "Vida.h"

class Mundo
{
	DisparoEspecial disparo_especial;
	ListaDisparos disparos;
	ListaObstaculo obstaculos;
	Hombre hombre;
	Caja caja;
	Bonus bonus;
	Pared plataforma;
	Disparo disparounico;
	Vida vidas;
	int numeroObstaculos;
	int nivel;
	float x_ojo;
	float y_ojo;
	float z_ojo;
	int cargadorEsp = 0;
public: 
	~Mundo();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();
	int getNumObstaculos();
	bool cargarNivel();
	int getVidas() { return hombre.vidas; }
};
