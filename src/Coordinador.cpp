#include "Coordinador.h"
void Coordinador::dibuja()
{
	if (estado == INICIO)
	{//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/galaxia_victoria.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);		glVertex3f(-20, 0, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(20, 0, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(20, 15, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-20, 15, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 45);
		ETSIDI::printxy("SPACE Y", -5, 12);

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
		ETSIDI::printxy("PULSE -E- PARA EMPEZAR", -5, 9);
		ETSIDI::printxy("PULSE -S- PARA SALIR", -5, 8);

		ETSIDI::setTextColor(0, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
		ETSIDI::printxy("CONTROLES:", -5, 6);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 10);
		ETSIDI::printxy("DISPARO: ESPACIO", -5, 5);
		ETSIDI::printxy("MOVIMIENTO ASCENDENTE: CURSOR ARRIBA", -5, 4);
		ETSIDI::printxy("MOVIMIENTO DESCENDENTE: CURSOR ABAJO", -5, 3);
		ETSIDI::setTextColor(0, 1, 0);
		ETSIDI::printxy("JUEGO CREADO POR", -3, 2);
		ETSIDI::printxy("Christian Stantchev, Daniel Escalada, Daniel Parrilla, Juan Jusdado, Pedro Menchero", -10, 1);

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
		
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
			
		glEnable(GL_TEXTURE_2D);
		ETSIDI::stopMusica();
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo_1.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);		glVertex3f(-20, 0, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(20, 0, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(20, 15, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-20, 15, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 35);
		ETSIDI::printxy("GAMEOVER", -5, 15);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
		ETSIDI::printxy("TU NAVE HA SIDO DERROTADA", -8, 13);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 3);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		sprintf(buffer, "Puntuacion: %d", mundo.getPuntuacion());
		ETSIDI::printxy(buffer, -3, 8);
	
	}
	else if (estado == FIN)
	{
		
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
			
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo_victoria.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);		glVertex3f(-20, 0, -0.1);
		glTexCoord2d(1, 1);		glVertex3f(20, 0, -0.1);
		glTexCoord2d(1, 0);		glVertex3f(20, 15, -0.1);
		glTexCoord2d(0, 0);		glVertex3f(-20, 15, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 30);
		ETSIDI::printxy("ENHORABUENA", -7, 10);
		ETSIDI::printxy("?Has logrado sobrevivir!", -9, 8);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 17);
		ETSIDI::printxy("Pulsa -C- para continuar", -5, 6);
	}


}
Coordinador::Coordinador()
{
	estado = INICIO;
	ETSIDI::playMusica("sonidos/AMBIENTE.mp3", true);
}
void Coordinador::tecla(unsigned char key)
{

	if (estado == INICIO)
	{

		if (key == 'e')
		{
			ETSIDI::play("sonidos/morse.wav");
			ETSIDI::stopMusica();
			mundo.~Mundo();
			mundo.inicializa();
			estado = JUEGO;
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

		if (key == 'c') {
			ETSIDI::playMusica("sonidos/AMBIENTE.mp3", true);
			estado = INICIO;
		}
	}
	else if (estado == FIN)
	{

		if (key == 'c') {
			ETSIDI::playMusica("sonidos/AMBIENTE.mp3", true);
			estado = INICIO;
		}
	}
	else if (estado == PAUSA)
	{
		if (key == 'c') {
			
			estado = JUEGO;
		}

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
			{

				estado = FIN;
				ETSIDI::stopMusica();
				ETSIDI::play("sonidos/WIN.wav");
			}
		}
		if (mundo.getVidas() < 1) 
		{
			ETSIDI::stopMusica();
			ETSIDI::play("sonidos/GAME_OVER.wav");
			estado = GAMEOVER;
		}

	}

}