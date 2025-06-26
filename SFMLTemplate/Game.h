#pragma once

#include<SFML/Graphics.hpp>
#include "mapa.h"
#include "Characters.h"
#include "clsArchivoStatistics.h"



class Game
{
public:

	Stats getStatistics();
	void update();
	void draw();
	void checkCollision(Characters& player1, Characters& player2, float deltaTime);
	void checkTakeDmg(Characters& player, int takenDmg );
	void incrementTimesPlayed();
	void incrementWinPj1();
	void incrementWinPj2();
	void incrementDraw();
	void incrementCharacterPlayed(const std::string& characterID);

private:
	float takeDmgCD = 0;
	int timesWinPj1 = 0;
	int timesWinPj2 = 0;
	int timesDraw = 0;
	int timesPlayed = 0;
	int timesPlayedElf = 0;
	int timesPlayedMafalda = 0;
	int timesPlayedNecromancer = 0;
	int timesPlayedKnight = 0;


	////////// ESTADISTICAS PARA TODO LAS STATS
	/*-VECES QUE GANO PJ1
	  - VECES QUE GANO PJ2
	  - VECES QUE EMPATARON
	  -VECES QUE JUGARON
	  - VECES QUE JUGARON CON ELFA
	  - VECES QUE JUGARON CON MAFALDA
	  - VECES QUE JUGARON CON NECROMANCER
	  - VECES QUE JUGARON CON KNIGHT
		*/

};

