#include "Coordinador.h"
void Coordinador::dibuja()
{
	if (estado == INICIO)
	{//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("SPACE Y", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
	}
	else if (estado == JUEGO)
	{
		mundo.dibuja();
	}
	else if (estado == PAUSA)
	{
		mundo.dibuja();
		ETSIDI::setTextColor(1, 10, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 30);
		ETSIDI::printxy("PAUSA", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (estado == GAMEOVER)
	{
		mundo.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
	}
	else if (estado == FIN)
	{
		mundo.dibuja();
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
	}


}
Coordinador::Coordinador()
{
	estado = INICIO;
}
void Coordinador::tecla(unsigned char key)
{

	if (estado == INICIO)
	{
		if (key == 'e')
		{
			ETSIDI::play("sonidos/morse.wav");
			mundo.~Mundo();
			mundo.inicializa();
			estado = JUEGO;
			ETSIDI::playMusica("sonidos/resumen_2.mp3", true);
		}

		if (key == 's')
			exit(0);
	}
	else if (estado == JUEGO)
	{
		mundo.tecla(key);
		if (key == 'p')
			estado = PAUSA;
		ETSIDI::stopMusica();
	}
	else if (estado == GAMEOVER)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == FIN)
	{
		if (key == 'c')
			estado = INICIO;
	}
	else if (estado == PAUSA)
	{
		if (key == 'c')
			estado = JUEGO;
		ETSIDI::playMusica("sonidos/resumen_2.mp3", true);
	}
}
void Coordinador::teclaEspecial(unsigned char key)
{
	if (estado == JUEGO)
		mundo.teclaEspecial(key);
}
void Coordinador::mueve()
{
	if (estado == JUEGO)
	{
		mundo.mueve();
		if (mundo.getNumObstaculos() == 0)
		{
			if (!mundo.cargarNivel())
				estado = FIN;

		}
		if (mundo.getVidas() < 1)
			estado = GAMEOVER;
	}
}