#pragma once

#include<SFML/Graphics.hpp>
#include"mapa.h"
class Game
{
public:

	void run();
	void update();
	void draw();
	void handleSelection();    // Lógica de selección de personajes/mapa
	void handleFight(float dt); // Lógica de pelea

	void loadAssets();         // Carga texturas, fuentes, sonidos
	void resetGame();          // Reinicia para una nueva partida

private:

};

