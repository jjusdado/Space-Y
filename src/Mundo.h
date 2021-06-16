#include "Caja.h"	
#include "Hombre.h"	
#include "Bonus.h"	
#include "Disparo.h"
#include "ListaDisparos.h"	
#include "DisparoEspecial.h"
#include "Obstaculo.h"
#include "ListaObstaculo.h"
#include "Vida.h"
#include "glut.h"
#include <cmath>
#include "Interaccion.h"
#include "ETSIDI.h"

class Mundo
{
	DisparoEspecial disparo_especial;
	ListaDisparos disparos;
	ListaObstaculo obstaculos;
	Hombre hombre;
	Caja caja;
	Bonus bonus;
	Pared plataforma;
	Pared pared_detras;
	Disparo disparounico;
	Vida vidas;
	int numeroObstaculos;
	int nivel;
	float x_ojo;
	float y_ojo;
	float z_ojo;
	int cargadorEsp = 0;
	int puntuacion = -20;//al cargar el nivel suma 20
	char buffer[10];
public: 
	~Mundo();
	void tecla(unsigned char key);
	void teclaEspecial(unsigned char key);
	void inicializa();
	void mueve();
	void dibuja();
	int getNumObstaculos();
	bool cargarNivel();
	int getVidas() { return vidas.vidas; }
	int getPuntuacion() { return puntuacion; }
	void setPuntuacion(int p) { puntuacion += p; }
};
