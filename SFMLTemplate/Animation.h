#pragma once
#include"Game.h"
class Animation 
{
protected:
	
	sf::Texture* getTexture();
	//sf::IntRect frameRect;
	int frameCount;
	int currentFrame = 0;
	float frameDuration;
	
	
	sf::Sprite sprite;
	

public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	//Animation(int frameWidth, int frameHeight, int frameCount, float frameDuration);

	void update(int row, float deltaTime, int column);
	sf::IntRect getCurrentFrameRect() const;
	void reset();
	sf::IntRect TextureRect;
private:
	unsigned int SizeTexture;
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;
	float totalTime;
	float switchTime;


	
	
};

