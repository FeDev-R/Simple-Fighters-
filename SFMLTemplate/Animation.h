#pragma once
#include <SFML/Graphics.hpp>
#include<map>

class Animation {
public:
    Animation();
    Animation(sf::Texture* texture, int frameCount, float switchTime);

    void update(float deltaTime);
    sf::IntRect getCurrentFrameRect() const;
    sf::Texture* getTexture() const;
    const sf::IntRect& getTextureRect() const;
   bool isLastFrame();
   void Reset();

private:
    sf::Texture* texture;
    int frameCount;
    float switchTime;
    float totalTime;
    int currentFrame;
    int frameWidth;
    int frameHeight;
};