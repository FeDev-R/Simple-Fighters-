#pragma once
#include "Characters.h"
#include <SFML/Graphics.hpp>
class MafaldaNinja : public Characters
{
public:
    MafaldaNinja(sf::RenderWindow& window, bool esJugador1);

    void Update(float deltaTime, const std::vector<sf::RectangleShape>& plataformas);
    void draw(sf::RenderWindow& window);

    void setAnimations() override;


    float getJumpForce() const override;


    void setHP(float value) override;
    void setJumpForce(float value) override;





private:
    sf::RectangleShape body;
    sf::Texture texture;
    sf::RenderWindow window;
    int row;

};

