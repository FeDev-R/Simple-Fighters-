#include "Knight.h"
Knight::Knight(sf::RenderWindow& window, bool esJugador1) : Characters(esJugador1)
{
    //body.setTexture(&texture);
    hp = 800.0f;
    hpMax = 800.0f;
    jumpForce = 500.0f;
    baseDmg = 11;
    speed = 3;
    character = 2;
    setAnimations();
    this->estadoActual = estadoPj::Idle;
    spriteBaseScale = { 2.5,2.5 };
    DmgAttack1 = 250;
    DmgAttack2 = 250;

    spriteOffsetsY[estadoPj::Idle] = -80;
    spriteOffsetsY[estadoPj::Move] = -80;
    spriteOffsetsY[estadoPj::Jump] = -80;
    spriteOffsetsY[estadoPj::Attack] = -80;
    spriteOffsetsY[estadoPj::Attack2] = -80;

    spriteOffsetsX[estadoPj::Idle] = 0;
    spriteOffsetsX[estadoPj::Move] = 0;
    spriteOffsetsX[estadoPj::Jump] = 0;
    spriteOffsetsX[estadoPj::Attack] = 0;


    //body.setTextureRect({ 100,20,50,20 });
   //body.setSize(sf::Vector2f(100.0f, 200.0f));
}

void Knight::Update(float deltaTime, const std::vector<sf::RectangleShape>& plataformas)
{


    Characters::Update(deltaTime, column, row, plataformas);


}

void Knight::draw(sf::RenderWindow& window)
{
    //std::cout << "SCALE X: " << body.getScale().x << " SCALE Y: " << body.getScale().y;

    Characters::draw(window);
}

void Knight::setAnimations()
{
    // IDLE
    textures[estadoPj::Idle].loadFromFile("./assets/knight/idle.png");
    animations[estadoPj::Idle] = Animation(&textures[estadoPj::Idle],4, 0.4f);

    // MOVE
    textures[estadoPj::Move].loadFromFile("./assets/knight/run.png");
    animations[estadoPj::Move] = Animation(&textures[estadoPj::Move], 7, 0.1f);

    // JUMP
    textures[estadoPj::Jump].loadFromFile("./assets/knight/jump.png");
    animations[estadoPj::Jump] = Animation(&textures[estadoPj::Jump], 6, 0.15f);

    // ATTACK
    textures[estadoPj::Attack].loadFromFile("./assets/knight/attack1.png");
    animations[estadoPj::Attack] = Animation(&textures[estadoPj::Attack], 6, 0.15f);

    textures[estadoPj::Attack2].loadFromFile("./assets/knight/attack2.png");
    animations[estadoPj::Attack2] = Animation(&textures[estadoPj::Attack2], 6, 0.15f);
}


float Knight::getJumpForce() const
{
    return 0.0f;
}



void Knight::setHP(float value)
{
}

void Knight::setJumpForce(float value)
{
}

