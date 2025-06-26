#include "elfa.h"

elfa::elfa(sf::RenderWindow & window, bool esJugador1) :
    Characters(esJugador1)
{
    character = 1;
    hp = 700.0f;
    hpMax = 700.0f;
    jumpForce = 700.0f;
    baseDmg = 11;
    speed = 4;
    setAnimations();
    estadoActual = estadoPj::Idle;
    spriteBaseScale = { 4.5f, 4.5f };

    DmgAttack1 = 250;
    DmgAttack2 = 150;

    // offsets para centrar el sprite en cada estado
    spriteOffsetsY[estadoPj::Idle] = -80;
    spriteOffsetsY[estadoPj::Move] = -80;
    spriteOffsetsY[estadoPj::Jump] = -80;
    spriteOffsetsY[estadoPj::Attack] = -80;
    spriteOffsetsY[estadoPj::Attack2] = -80;

    spriteOffsetsX[estadoPj::Idle] = 0;
    spriteOffsetsX[estadoPj::Move] = 0;
    spriteOffsetsX[estadoPj::Jump] = 0;
    // spriteOffsetsX[estadoPj::Attack] se ajusta dinámicamente en update
}

// actualiza el personaje, moviendo hitbox según ataques y luego llama update padre
void elfa::Update(float deltaTime, const std::vector<sf::RectangleShape>& plataformas)
{
    if (estadoActual == estadoPj::Attack) {
        float avance = 70.0f * deltaTime;

        if (movingLeft) {
            hitbox.move(-avance, 0.f);
            spriteOffsetsX[estadoPj::Attack] = 50.0f;
        }
        else {
            hitbox.move(avance, 0.f);
            spriteOffsetsX[estadoPj::Attack] = -50.0f;
        }

        if (velocity.x > 0) {
            if (movingLeft) hitbox.move(-addedSpeed, 0.f);
            else hitbox.move(addedSpeed, 0.f);
        }
    }

    if (estadoActual == estadoPj::Attack2) {
        spriteOffsetsX[estadoPj::Attack2] = movingLeft ? 50.0f : -50.0f;
    }

    Characters::Update(deltaTime, plataformas);
}

void elfa::draw(sf::RenderWindow& window)
{
    Characters::draw(window);
}

// carga las animaciones de los diferentes estados con sus texturas y frames
void elfa::setAnimations()
{
    textures[estadoPj::Idle].loadFromFile("./assets/elf_png/elf_idle.png");
    animations[estadoPj::Idle] = Animation(&textures[estadoPj::Idle], 6, 0.2f);

    textures[estadoPj::Move].loadFromFile("./assets/elf_png/elf_run.png");
    animations[estadoPj::Move] = Animation(&textures[estadoPj::Move], 10, 0.1f);

    textures[estadoPj::Jump].loadFromFile("./assets/elf_png/elf_jump.png");
    animations[estadoPj::Jump] = Animation(&textures[estadoPj::Jump], 11, 0.15f);

    textures[estadoPj::Attack].loadFromFile("./assets/elf_png/elf_attack.png");
    animations[estadoPj::Attack] = Animation(&textures[estadoPj::Attack], 10, 0.1f);

    textures[estadoPj::Attack2].loadFromFile("./assets/elf_png/elf_attack2.png");
    animations[estadoPj::Attack2] = Animation(&textures[estadoPj::Attack2], 5, 0.15f);
}

// funciones vacías o que devuelven un valor fijo, podrían implementarse luego
float elfa::getJumpForce() const
{
    return 0.0f;
}

void elfa::setHP(float value)
{
    // implementar si se quiere modificar hp directamente
}

void elfa::setJumpForce(float value)
{
    // implementar si se quiere modificar fuerza de salto directamente
}

void elfa::setDmg(int value)
{
    currentDmg = value;
}