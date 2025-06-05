#include "Characters.h"

Characters::Characters(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
    : Animation (texture, imageCount, switchTime)
{
    body.setTexture(texture);
    //body.setTextureRect({ 40,0,50,100 });
    body.setSize(sf::Vector2f(100.0f, 200.0f));
}


void Characters::Update(float deltaTime)
{
    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y -= 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        movement.y += 1;


    row = 5;

    Animation.update(row, deltaTime);
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