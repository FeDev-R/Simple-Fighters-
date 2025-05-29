#pragma once

#include<SFML/Graphics.hpp>
#include"mapa.h"
class Game
{
public:

	void run();
	void update();
	void draw();
	void handleSelection();    // L�gica de selecci�n de personajes/mapa
	void handleFight(float dt); // L�gica de pelea

	void loadAssets();         // Carga texturas, fuentes, sonidos
	void resetGame();          // Reinicia para una nueva partida

private:

};

