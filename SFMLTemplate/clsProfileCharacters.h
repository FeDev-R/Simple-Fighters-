#pragma once
#include<SFML/Graphics.hpp>

class ProfileCharacters
{
private:
    sf::Sprite sprite;
    sf::Texture texture;
    
    bool isSelected = false;
    std::string characterID;
    sf::RectangleShape squareFromProfile;
    

public:
    ProfileCharacters(const std::string& texturePath, const std::string& id, sf::Vector2f position);

    void draw(sf::RenderWindow& window);
    bool isHovered(const sf::Vector2f& mousePos);
    void setSelected(bool selected);
    std::string getCharacterID() const;
    sf::Vector2f getPosition() { return sprite.getPosition(); };
    sf::FloatRect getGlobalBounds() { return sprite.getGlobalBounds(); };
    const sf::Texture& getTexture() { return texture; };
};

// CharacterPortrait.cpp


