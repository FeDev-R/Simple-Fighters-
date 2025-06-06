#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Animation.h"

class Characters
{

protected:
	Animation Animation;
	float hp;
	float moveSpeed;
	float jumpForce;
	float baseDmg;
	////
	sf::RectangleShape body;
	sf::Texture texture;
	sf::RenderWindow window;
	int row;
	float speed;
	////

	sf::Sprite sprite;
	sf::Vector2f POS{1.0f, 1.0f};
	
public:
	virtual float getHP() const = 0;
	virtual float getJumpForce() const = 0;
	virtual float getDMG() const = 0;

	virtual void setHP(float value) = 0;
	virtual void setJumpForce(float value) = 0;
	virtual void setDMG(float value) = 0;

	Characters(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);

	void Update(float deltaTime);
	virtual bool loadFromFile(const std::string& path);
	virtual void draw(sf::RenderWindow& window) const;
	virtual void setPosition(sf::Vector2f pos);
	virtual sf::Vector2f getPosition() const;
	virtual sf::FloatRect getBounds() const;
	virtual bool collidesWith(const sf::FloatRect& other) const;

};

