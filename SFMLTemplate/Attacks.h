#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Animation.h"

class Attacks
{
private:
	float DmgBase = 100;
	sf::RectangleShape HitBox;
	float Duration = 5.0f;
	float cooldown = 2.0f;
	//Animation Animation;
	sf::Vector2f position;
	float offset = 5.0f;
public:

	Attacks();
	Attacks(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position);

	void updateAttack(sf::RectangleShape& body, bool sideMove);
	virtual void setPosition();

	void attackAction(sf::RectangleShape body, bool sideMove, int character/*, sf::Window& window*/);
	sf::Vector2f getHitbox();
	sf::RectangleShape& GetHitBox();


	

};

