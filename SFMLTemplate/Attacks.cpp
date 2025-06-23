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

void Attacks::attackAction(sf::RectangleShape body, bool sideMove/*, sf::Window& window*/)
{
	//sf::Vector2f size = body.getSize();
	position = body.getPosition();
	float offset = 5.0f;
	HitBox.setSize(sf::Vector2f(body.getSize().x * 4, body.getSize().y * 2));
	//HitBox.setPosition(position.x + offset  /*+ body.getSize().x * 4*/ /* body.getScale().x*/, position.y  - body.getSize().y / 2);
	HitBox.setPosition(position.x - offset , position.y -HitBox.getSize().y / 2);
	if (sideMove) {
		offset = 150;
		HitBox.setPosition( position.x - offset , position.y - HitBox.getSize().y / 2);
		
	}
	
}
	//HitBox.setPosition(-body.getOrigin());
	


sf::RectangleShape& Attacks::GetHitBox() {
	return HitBox;
}

void Attacks::setPosition()
{

}
;