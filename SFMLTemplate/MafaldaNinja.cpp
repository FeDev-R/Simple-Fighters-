#include "MafaldaNinja.h"

MafaldaNinja::MafaldaNinja(sf::Texture* texture, sf::RenderWindow& window, sf::Vector2u imageCount, float switchTime):
    Characters(texture, imageCount, switchTime)
{
    //body.setTexture(&texture);
    hp = 300.0f;
    jumpForce = 200.0f;
    baseDmg = 11;
    //body.setTextureRect({ 40,0,50,100 });
    //body.setSize(sf::Vector2f(100.0f, 200.0f));
}

void MafaldaNinja::Update(float deltaTime)
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

    Characters::Update(deltaTime, column, row);
   
}

void MafaldaNinja::draw(sf::RenderWindow& window) 
{
    Characters::draw(window);
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

