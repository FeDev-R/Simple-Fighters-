#pragma once
#include <vector>
#include<SFML/Graphics.hpp>
#include "clsProfileCharacters.h"

class selectCharacterMenu
{
private:
    std::vector<std::unique_ptr<ProfileCharacters>> Profiles;
    int selectedIndex = -1;
    sf::Sprite backgroundSelectCharacters;
    sf::Texture backgroundImage;
    int Personajes = 0;

    sf::Sprite pj1;
	sf::Sprite pj2;
    bool checkCharacter1 = false;
    bool checkCharacter2 = false;
    std::string Id1;
    std::string Id2;
	float cdClick = 0.0f;
public:
    selectCharacterMenu();

    void update(sf::Vector2f mousePos, float deltaTime);
    void addPortrait(const std::string& texturePath, const std::string& id, sf::Vector2f position);
    void handleClick(sf::Vector2f mousePos);
    void draw(sf::RenderWindow& window);
    void checkCharacters(ProfileCharacters& p, int Personajes);
    int checkPersonajes() { return Personajes; };
    std::string saveCharactersID(bool esJugador1);
};

