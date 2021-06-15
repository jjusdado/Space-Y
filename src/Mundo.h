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

class Mundo
{
	EsferaPulsante esfera_pulsante;
	DisparoEspecial disparo_especial;

	ListaEsferas esferas;
	ListaDisparos disparos;
	ListaObstaculo obstaculos;
	Hombre hombre;
	Caja caja;
	Bonus bonus;
	Pared plataforma;
	Disparo disparounico;
	bool impacto;
	int numeroEsferas;
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
	bool getImpacto();
	int getNumEsferas();
	bool cargarNivel();
};
