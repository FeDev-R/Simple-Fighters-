#include "Necromancer.h"

Necromancer::Necromancer(sf::RenderWindow& window, bool esJugador1) : Characters(esJugador1)
{
    //body.setTexture(&texture);
    hp = 300.0f;
    hpMax = 300.0f;
    jumpForce = 500.0f;
    baseDmg = 11;
    
    setAnimations();
    this->estadoActual = estadoPj::Idle;
    spriteBaseScale = { 4.5,4.5 };


    spriteOffsetsY[estadoPj::Idle] = -220;
    spriteOffsetsY[estadoPj::Move] = -220;
    spriteOffsetsY[estadoPj::Jump] = -220;
    spriteOffsetsY[estadoPj::Attack] = -290;

    spriteOffsetsX[estadoPj::Idle] = 0;
    spriteOffsetsX[estadoPj::Move] = 0;
    spriteOffsetsX[estadoPj::Jump] = 0;
    spriteOffsetsX[estadoPj::Attack] = 0;


     //body.setTextureRect({ 100,20,50,20 });
    //body.setSize(sf::Vector2f(100.0f, 200.0f));
}

void Necromancer::Update(float deltaTime, const std::vector<sf::RectangleShape>& plataformas)
{


    Characters::Update(deltaTime, column, row, plataformas);


}

void Necromancer::draw(sf::RenderWindow& window)
{
    //std::cout << "SCALE X: " << body.getScale().x << " SCALE Y: " << body.getScale().y;

    Characters::draw(window);
}

void Necromancer::setAnimations()
{
    // IDLE
    textures[estadoPj::Idle].loadFromFile("./assets/Necromancer/idle/idle.png");
    animations[estadoPj::Idle] = Animation(&textures[estadoPj::Idle], 50, 0.1f);

    // MOVE
    textures[estadoPj::Move].loadFromFile("./assets/Necromancer/walk/walk.png");
    animations[estadoPj::Move] = Animation(&textures[estadoPj::Move], 10, 0.1f);

    // JUMP
    textures[estadoPj::Jump].loadFromFile("./assets/Necromancer/jump/jump.png");
    animations[estadoPj::Jump] = Animation(&textures[estadoPj::Jump], 12, 0.16f);

    // ATTACK
    textures[estadoPj::Attack].loadFromFile("./assets/Necromancer/attack/attack.png");
    animations[estadoPj::Attack] = Animation(&textures[estadoPj::Attack], 47, 0.2f);
}

float Necromancer::getHP() const
{
    return hp;
}

float Necromancer::getJumpForce() const
{
    return 0.0f;
}

float Necromancer::getDMG() const
{
    return 0.0f;
}

void Necromancer::setHP(float value)
{
}

void Necromancer::setJumpForce(float value)
{
}

void Necromancer::setDMG(float value)
{
}
