#pragma once

#include<SFML/Graphics.hpp>
#include "mapa.h"
#include "Characters.h"



class Game
{
public:


	void run();
	void update();
	void draw();
	void handleSelection();    // Lógica de selección de personajes/mapa
	void handleFight(float dt); // Lógica de pelea
	void checkCollision(Characters& player1, Characters& player2);

	void checkTakeDmg(Characters& player, int takenDmg );
	void loadAssets();         // Carga texturas, fuentes, sonidos
	void resetGame();          // Reinicia para una nueva partida

private:

};

