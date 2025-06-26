#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
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
	sf::Vector2f offset;
	sf::Vector2f attackOffSet;
	bool esperandoAparecer = false;
	float delayAntesHitbox = 2.f; 
	sf::Clock ataque;
	sf::Vector2f size2;       
	sf::Vector2f offset2;     
public:

	Attacks();
	Attacks(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, sf::Vector2f position);

	void updateAttack(sf::RectangleShape& body, bool sideMove);
	virtual void setPosition();

	void attackAction(sf::RectangleShape body, bool sideMove, int character, int attackNum);
	sf::Vector2f getHitbox();
	sf::RectangleShape& GetHitBox();

	void reset();
	

};

