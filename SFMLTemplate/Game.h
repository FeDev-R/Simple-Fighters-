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
	void handleSelection();    
	void handleFight(float dt);
	void checkCollision(Characters& player1, Characters& player2, float deltaTime);

	void checkTakeDmg(Characters& player, int takenDmg );
	void loadAssets();        
	void resetGame();        

private:
	float takeDmgCD = 0;

};

