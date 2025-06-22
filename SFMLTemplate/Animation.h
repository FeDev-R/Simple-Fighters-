#pragma once
#include"Game.h"
#include<map>

class Animation {
public:
    Animation();
    Animation(sf::Texture* texture, int frameCount, float switchTime);

    void update(float deltaTime);
    sf::IntRect getCurrentFrameRect() const;
    sf::Texture* getTexture() const;
    const sf::IntRect& getTextureRect() const;


private:
    sf::Texture* texture;
    int frameCount;
    float switchTime;
    float totalTime;
    int currentFrame;
    int frameWidth;
    int frameHeight;
};