#pragma once
#include "Characters.h"
#include <SFML/Graphics.hpp>
class MafaldaNinja : public Characters
{
public:
	MafaldaNinja(sf::Texture* texture,sf::RenderWindow& window, sf::Vector2u imageCount, float switchTime) ;

    void Update(float deltaTime);
    void draw(sf::RenderWindow& window);


    float getHP() const override;
    float getJumpForce() const override;
    float getDMG() const override;

    void setHP(float value) override;
    void setJumpForce(float value) override;
    void setDMG(float value) override;

   


private:
    sf::RectangleShape body;
    sf::Texture texture;
    sf::RenderWindow window;
    int row;
    float speed;
};

