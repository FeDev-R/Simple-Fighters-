#pragma once
#include"Game.h";
class HUD
{
private:
    // Vida
    float maxHP;
    float currentHP;
    sf::RectangleShape hpBackground;
    sf::RectangleShape hpFill;

    // Cooldown de 2 poderes
    float power1CooldownTime;
    float power1Current;
    sf::RectangleShape power1Bar;

    float power2CooldownTime;
    float power2Current;
    sf::RectangleShape power2Bar;

    // Texto
    sf::Font font;
    sf::Text nameText;

    // Ícono del personaje
    sf::Texture portraitTexture;
    sf::Sprite portraitSprite;

    sf::Vector2f position;

public:
    void init(const std::string& playerName, float maxHP, sf::Vector2f position);

    void setHealth(float hp);
    void startPowerCooldown(int powerIndex);
    bool isPowerReady(int powerIndex) const;

    void update(float deltaTime);
    void render(sf::RenderWindow& window);
};

