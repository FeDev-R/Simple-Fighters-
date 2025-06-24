#include "Game.h"

class Characters;

void Game::checkCollision(Characters& player1, Characters& player2) {
	if (player1.getHitboxAttack().getGlobalBounds().intersects(player2.getHitbox().getGlobalBounds())) {
		std::cout << "COLISION";
		checkTakeDmg(player1, player2.getDmg());
	}
	else if(player2.getHitboxAttack().getGlobalBounds().intersects(player1.getHitbox().getGlobalBounds())) {
		checkTakeDmg(player2, player1.getDmg());
	}
}

void Game::checkTakeDmg(Characters& player, int takenDmg)
{
	player.takeDmg(takenDmg);
}
