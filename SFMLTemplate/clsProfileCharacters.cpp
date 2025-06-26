#include "clsProfileCharacters.h"
#include <iostream>

// constructor, carga textura, posiciona y configura el sprite y el recuadro del perfil
ProfileCharacters::ProfileCharacters(const std::string& texturePath, const std::string& CharacterID, sf::Vector2f position)
{
    this->characterID = CharacterID;
    if (!texture.loadFromFile(texturePath)) {
        std::cout << "error al cargar " << texturePath << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
    sprite.setScale(2.0f, 2.0f);

    squareFromProfile.setSize(sf::Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height));
    squareFromProfile.setPosition(sprite.getPosition());
    squareFromProfile.setFillColor(sf::Color::White);
}

// dibuja el recuadro y el sprite del personaje
void ProfileCharacters::draw(sf::RenderWindow& window) {
    window.draw(squareFromProfile);
    window.draw(sprite);
}

// devuelve true si el mouse esta sobre el sprite
bool ProfileCharacters::isHovered(const sf::Vector2f& mousePos) {
    return sprite.getGlobalBounds().contains(mousePos);
}

// cambia el estado de seleccion y cambia el color del recuadro segun corresponda
void ProfileCharacters::setSelected(bool selected) {
    isSelected = selected;
    squareFromProfile.setFillColor(selected ? sf::Color::Green : sf::Color::White);
}

// devuelve el id del personaje
std::string ProfileCharacters::getCharacterID() const {
    return characterID;
}