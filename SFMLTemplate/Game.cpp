#include "Game.h"

class Characters;

void Game::checkCollision(Characters& player1, Characters& player2, float deltaTime) {
    takeDmgCD -= deltaTime; // reduce cooldown del daño recibido
    std::cout << "CD DEL ATAQUE: " << takeDmgCD << std::endl;

    bool canTakeDmg = (takeDmgCD <= 0);

    // si el hitbox de ataque de player1 colisiona con hitbox de player2 y puede recibir daño
    if (player1.getHitboxAttack().getGlobalBounds().intersects(player2.getHitbox().getGlobalBounds()) && canTakeDmg) {
        checkTakeDmg(player2, player1.getDmg());  // player2 recibe daño
        takeDmgCD = 0.75f; // reinicia cooldown
    }
    // si el hitbox de ataque de player2 colisiona con hitbox de player1 y puede recibir daño
    else if (player2.getHitboxAttack().getGlobalBounds().intersects(player1.getHitbox().getGlobalBounds()) && canTakeDmg) {
        checkTakeDmg(player1, player2.getDmg());  // player1 recibe daño
        takeDmgCD = 0.75f; // reinicia cooldown
    }
}

// método para aplicar daño a un jugador
void Game::checkTakeDmg(Characters& player, int takenDmg) {
    player.takeDmg(takenDmg);
}