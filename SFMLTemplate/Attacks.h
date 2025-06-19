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

public:

	Attacks();
	Attacks(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position);

	virtual void setPosition();

	void attackAction(sf::RectangleShape body/*, sf::Window& window*/);

	sf::RectangleShape& GetHitBox();


	

};

