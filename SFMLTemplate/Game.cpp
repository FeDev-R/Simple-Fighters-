#include "Game.h"

class Characters;

void Game::checkCollision(Characters& player1, Characters& player2, float deltaTime) {

	takeDmgCD -= deltaTime;
	std::cout << "CD DEL ATAQUE" << takeDmgCD << std::endl;
	bool canTakeDmg = false;

		if (takeDmgCD <= 0) {
			canTakeDmg = true;
		}
		if (player1.getHitboxAttack().getGlobalBounds().intersects(player2.getHitbox().getGlobalBounds()) && canTakeDmg) {
			checkTakeDmg(player2, player1.getDmg());  // player2 recibe daño de player1
			takeDmgCD = 0.75;
		}
		else if (player2.getHitboxAttack().getGlobalBounds().intersects(player1.getHitbox().getGlobalBounds()) && canTakeDmg) {
			checkTakeDmg(player1, player2.getDmg());  // player1 recibe daño de player2
			takeDmgCD = 0.75;
		}
}

void Game::checkTakeDmg(Characters& player, int takenDmg)
{
	player.takeDmg(takenDmg);
}
