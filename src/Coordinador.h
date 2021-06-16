#pragma once
#include "Mundo.h"
#include <stdio.h>

class Coordinador
{
	int puntuacion = -20; //al cargar el nivel suma 20
	char buffer[10];
public:
	Coordinador();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void mueve();
	void dibuja();
protected:
	Mundo mundo;
	enum Estado { INICIO, JUEGO, GAMEOVER, FIN, PAUSA };
	Estado estado;
};