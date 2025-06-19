#include "Attacks.h"
#include <iostream>


Attacks::Attacks()
{
	HitBox.setOutlineColor(sf::Color::Magenta);
	HitBox.setOutlineThickness(2.0f);
	HitBox.setFillColor(sf::Color::Transparent); // solo contorno
	HitBox.setSize(sf::Vector2f(50.0f, 20.0f));  
}

Attacks::Attacks(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position)
	{
	HitBox.setOutlineColor(sf::Color::Magenta);
	HitBox.setOutlineThickness(15.0f);

	}

void Attacks::attackAction(sf::RectangleShape body/*, sf::Window& window*/)
{

	position = body.getPosition();
	float offset = 0.0f;
	HitBox.setPosition(position.x + offset * body.getScale().x, position.y - body.getSize().y / 2);
}
	//HitBox.setPosition(-body.getOrigin());
	


sf::RectangleShape& Attacks::GetHitBox() {
	return HitBox;
}

void Attacks::setPosition()
{

}
;