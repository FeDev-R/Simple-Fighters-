#pragma once
#include"Game.h"
class Animation 
{
protected:
	
	sf::Texture* getTexture();
	sf::IntRect frameRect;
	int frameCount;
	int currentFrame = 0;
	float frameDuration;
	float totalTime;
	float switchTime;
	
	sf::Sprite sprite;
	sf::Vector2u imageCount;

public:
	Animation();
	Animation(int frameWidth, int frameHeight, int frameCount, float frameDuration);

	void update(float deltaTime);
	sf::IntRect getCurrentFrameRect() const;
	void reset();
	
};

