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
	Animation Animation;

public:

	
	Attacks(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);


	

};

