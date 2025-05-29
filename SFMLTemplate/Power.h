#pragma once
#include"Game.h"
class Power
{
protected:
	bool canActivate();
	void activate();
	void update();
	void draw(sf::RenderWindow& window);

	float cd;
	float dmg;
	float range;

};

