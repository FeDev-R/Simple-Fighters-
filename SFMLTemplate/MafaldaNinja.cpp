#include "MafaldaNinja.h"

MafaldaNinja::MafaldaNinja(sf::RenderWindow& window, bool esJugador1):
    Characters(esJugador1)
{
    //body.setTexture(&texture);
    hp = 300.0f;
    jumpForce = 500.0f;
    baseDmg = 11;
    setAnimations();
    this->estadoActual = estadoPj::Idle;
    body.setScale(3.0f, 3.0f);
    spriteOffsetY = -190;
    
    spriteOffsetsY[estadoPj::Idle] = -190;
    spriteOffsetsY[estadoPj::Move] = -190;
    spriteOffsetsY[estadoPj::Jump] = -190;
    spriteOffsetsY[estadoPj::Attack] = -300;
    //body.setTextureRect({ 100,20,50,20 });
    //body.setSize(sf::Vector2f(100.0f, 200.0f));
}

void MafaldaNinja::Update(float deltaTime, const std::vector<sf::RectangleShape>& plataformas)
{


    switch (estadoActual)
    {
    case Characters::estadoPj::Idle:
        column = 7;
        row = 2;
        break;
    case Characters::estadoPj::Move:
        column = 8;
        row = 4;
        break;
    case Characters::estadoPj::Jump:
        column = 2;
        row = 3;
        break;
    case Characters::estadoPj::Attack:
        column = 7;
        row = 1;
        break;
    default:
        column: 12;
        row : 0;
        break;
    }

    Characters::Update(deltaTime, column, row, plataformas );
   
}

void MafaldaNinja::draw(sf::RenderWindow& window) 
{
    //std::cout << "SCALE X: " << body.getScale().x << " SCALE Y: " << body.getScale().y;

    Characters::draw(window);
}

void MafaldaNinja::setAnimations()
{
    // IDLE
    textures[estadoPj::Idle].loadFromFile("./assets/mafalda/AnimeWarrior/Warrior/Idle.png");
    animations[estadoPj::Idle] = Animation(&textures[estadoPj::Idle], 12, 0.2f);

    // MOVE
    textures[estadoPj::Move].loadFromFile("./assets/mafalda/AnimeWarrior/Warrior/Run.png");
    animations[estadoPj::Move] = Animation(&textures[estadoPj::Move], 8, 0.1f);

    // JUMP
    textures[estadoPj::Jump].loadFromFile("./assets/mafalda/AnimeWarrior/Warrior/Jump.png");
    animations[estadoPj::Jump] = Animation(&textures[estadoPj::Jump], 2, 0.5f);

    // ATTACK
    textures[estadoPj::Attack].loadFromFile("./assets/mafalda/AnimeWarrior/Warrior/Sword-Combo.png");
    animations[estadoPj::Attack] = Animation(&textures[estadoPj::Attack], 14, 0.08f);
}

float MafaldaNinja::getHP() const
{
    return 0.0f;
}

float MafaldaNinja::getJumpForce() const
{
    return 0.0f;
}

float MafaldaNinja::getDMG() const
{
    return 0.0f;
}

void MafaldaNinja::setHP(float value)
{
}

void MafaldaNinja::setJumpForce(float value)
{
}

void MafaldaNinja::setDMG(float value)
{
}

