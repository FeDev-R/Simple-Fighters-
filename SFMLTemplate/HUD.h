#pragma once
#include"Game.h";
class HUD
{
private:
   
    float maxHP;
    float currentHP;
    sf::RectangleShape hpBackground;
    sf::RectangleShape hpFill;

  
    float power1CooldownTime;
    float power1Current;
    sf::RectangleShape power1Bar;

    float power2CooldownTime;
    float power2Current;
    sf::RectangleShape power2Bar;

   
    sf::Font font;
    sf::Text nameText;

  
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

