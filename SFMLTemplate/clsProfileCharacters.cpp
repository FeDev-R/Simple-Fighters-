#include "clsProfileCharacters.h"
#include <iostream>

ProfileCharacters::ProfileCharacters(const std::string& texturePath, const std::string& CharacterID, sf::Vector2f position)
{
   

    this->characterID = CharacterID;
    if (!texture.loadFromFile(texturePath)) {
        std::cout << "Error al cargar " << texturePath << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale(2.0f, 2.0f); 
   

    squareFromProfile.setSize(sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));
    //std::cout << squareFromProfile.getSize().x<<std::endl;
    //std::cout << squareFromProfile.getSize().y<< std::endl;
    squareFromProfile.setPosition(sprite.getPosition());
    squareFromProfile.setFillColor(sf::Color::White);
}

void ProfileCharacters::draw(sf::RenderWindow& window) {
    
    window.draw(squareFromProfile);
    window.draw(sprite);
    //std::cout << "Dibujando personaje: " << characterID
      //  << " Tamaño de textura: " << texture.getSize().x << ", " << texture.getSize().y << std::endl;

}

bool ProfileCharacters::isHovered(const sf::Vector2f& mousePos) {
    return sprite.getGlobalBounds().contains(mousePos);
}

void ProfileCharacters::setSelected(bool selected) {
    isSelected = selected;
    squareFromProfile.setFillColor(selected ? sf::Color::Green : sf::Color::White);
}

std::string ProfileCharacters::getCharacterID() const {
    return characterID;
}
