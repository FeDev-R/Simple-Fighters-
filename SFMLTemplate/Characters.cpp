#include "Characters.h"
#include <iostream>

Characters::Characters(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
    : Animation (texture, imageCount, switchTime)
{
    
    body.setTexture(texture);
    //body.setTextureRect({ 40,0,50,100 });
    body.setSize(sf::Vector2f(100.0f, 200.0f));
}


void Characters::Update(float deltaTime, int column, int row)
{
    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y -= 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        movement.y += 2;

    std::cout << movement.y;
    std::cout << movement.x;

    ///QUIETO O EN MOVIMIENTO
    if (movement.x > 0.0f || movement.x < 0.0f && movement.y == 0) {
        Characters::estadoActual = estadoPj::Move;
    }
    else if(movement.x==0.0 && movement.y == 0) {
        Characters::estadoActual = estadoPj::Idle;
    }


    this->column = column;
    this->row = row;

    //std::cout << this->column;
    //std::cout << this->row;

    /*if (movement.x > 0.0f)
        faceRight = true;
    else if (movement.x == 0)
        ;
    else
        faceRight = false;
        */

    Animation.update(row, deltaTime, column);
    body.setTextureRect(Animation.TextureRect);
    body.move(movement);


}


bool Characters::loadFromFile(const std::string& path) {
    if (!texture.loadFromFile(path))
        return false;
    sprite.setTexture(texture);
    return true;
}

void Characters::draw(sf::RenderWindow& window) const {
    window.draw(body);
}



void Characters::setPosition(sf::Vector2f pos) {
    sprite.setPosition(pos);
}

sf::Vector2f Characters::getPosition() const {
    return sprite.getPosition();
}

sf::FloatRect Characters::getBounds() const {
    return sprite.getGlobalBounds();
}

bool Characters::collidesWith(const sf::FloatRect& other) const {
    return getBounds().intersects(other);
}