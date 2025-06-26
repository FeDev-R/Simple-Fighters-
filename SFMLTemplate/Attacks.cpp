#include "Attacks.h"
#include <iostream>


Attacks::Attacks()
{
	HitBox.setOutlineColor(sf::Color::Magenta);
	HitBox.setOutlineThickness(2.0f);
	HitBox.setFillColor(sf::Color::Transparent); // solo contorno
	HitBox.setSize(sf::Vector2f(0.0f, 0.0f));  

	ataque.restart();        
	esperandoAparecer = false;       
	 
	
}

void Attacks::attackAction(sf::RectangleShape body, bool sideMove, int character, int attackNum)
{
	position = body.getPosition();

	sf::Vector2f size;
	sf::Vector2f offset;

	if (character == 1) {
		switch (attackNum) {
		case 1:
			if (sideMove) {
				size = sf::Vector2f(-(body.getSize().x * 3.f), body.getSize().y / 3.0f);
				offset = sf::Vector2f(-20.f, 10.f);
			}
			else {
				size = sf::Vector2f(body.getSize().x * 3.f, body.getSize().y / 3.0f);
				offset = sf::Vector2f(20.f, 10.f);
			}
			
			break;
		case 2:
			if (sideMove) {
				size = sf::Vector2f(-(body.getSize().x * 3.f), body.getSize().y / 3.0f);
				offset = sf::Vector2f(-20.f, 10.f);
			}
			else {
				size = sf::Vector2f(body.getSize().x * 3.f, body.getSize().y / 3.0f);
				offset = sf::Vector2f(20.f, 10.f);
			}

			
			break;
		}
	}

	if (character == 2) {

		switch (attackNum) {
		case 1:
			if (sideMove) {
				size = sf::Vector2f(-(body.getSize().x * 3.f), body.getSize().y / 2.0f);
				offset = sf::Vector2f(-20.f, -10.f);
			}
			else {
				size = sf::Vector2f(body.getSize().x * 3.f, body.getSize().y / 2.0f);
				offset = sf::Vector2f(20.f, -10.f);
			}
			break;
		case 2:
			if (sideMove) {
				size = sf::Vector2f(-(body.getSize().x * 2.5f), body.getSize().y / 2.0f);
				offset = sf::Vector2f(-20.f, -10.f);
			}
			else {
				size = sf::Vector2f(body.getSize().x * 2.5f, body.getSize().y / 2.0f);
				offset = sf::Vector2f(20.f, -10.f);
			}
			break;
		}
	}

	if (character == 3) {

		switch (attackNum) {

		case 1:
			if (sideMove) {
				size = sf::Vector2f(-(body.getSize().x * 4.0f), body.getSize().y / 1.0f);
				offset = sf::Vector2f(-20.f, -10.f);
			}
			else {
				size = sf::Vector2f(body.getSize().x * 4.0f, body.getSize().y / 1.0f);
				offset = sf::Vector2f(20.f, -10.f);
			}
			break;
		case 2:
			if (sideMove) {
				size = sf::Vector2f(-(body.getSize().x * 4.0f), body.getSize().y / 1.0f);
				offset = sf::Vector2f(-20.f, -10.f);
			}
			else {
				size = sf::Vector2f(body.getSize().x * 4.0f, body.getSize().y / 1.0f);
				offset = sf::Vector2f(20.f, -10.f);
			}
			break;
		}
	}	
	
	if (character == 4 && attackNum == 1) {
		ataque.restart(); 
		esperandoAparecer = true;

		if (sideMove) {
			size = sf::Vector2f(-(body.getSize().x * 6.0f), body.getSize().y / 6.0f);
			offset = sf::Vector2f(-20.f, -30.f);
		}
		else {
			size = sf::Vector2f(body.getSize().x * 6.0f, body.getSize().y / 6.0f);
			offset = sf::Vector2f(20.f, -30.f);
		}

		
		HitBox.setSize({ 0.f, 0.f }); 
		HitBox.setPosition(-1000.f, -1000.f); 

		attackOffSet = offset2;

		this->size2 = size;    
		this->offset2 = offset;

		return;
	}

	if (sideMove) {
		offset.x = -offset.x;
	}

	HitBox.setSize(size);
	
	HitBox.setPosition(position + offset - sf::Vector2f(0, size.y / 2));
}
sf::Vector2f Attacks::getHitbox()
{
	return sf::Vector2f(HitBox.getPosition());
}
	//HitBox.setPosition(-body.getOrigin());
	


sf::RectangleShape& Attacks::GetHitBox() {
	return HitBox;
}

void Attacks::updateAttack(sf::RectangleShape& body, bool sideMove)
{
	position = body.getPosition();

	if (esperandoAparecer) {
		if (ataque.getElapsedTime().asSeconds() >= delayAntesHitbox) {
		
			HitBox.setSize(size2);
			HitBox.setPosition(position + offset2 - sf::Vector2f(0, size2.y / 2.f));

			esperandoAparecer = false;
		}
		else {
			
			HitBox.setSize({ 0.f, 0.f });
			HitBox.setPosition(-1000.f, -1000.f);
		}
	}
	else {
		
		HitBox.setPosition(position + offset2 - sf::Vector2f(0, HitBox.getSize().y / 2.f));
	}
}
void Attacks::reset() {
	HitBox.setSize(sf::Vector2f(0.0f, 0.0f)); 
	HitBox.setPosition(-1000.f, -1000.f);   
	esperandoAparecer = false;
}
void Attacks::setPosition()
{

}
;