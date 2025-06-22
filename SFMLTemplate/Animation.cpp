#include "Animation.h"
#include "Menu.h"
#include <iostream>

Animation::Animation()
    : texture(nullptr), frameCount(1), switchTime(0.1f),
    totalTime(0), currentFrame(0), frameWidth(0), frameHeight(0) {
}

Animation::Animation(sf::Texture* texture, int frameCount, float switchTime)
    : texture(texture), frameCount(frameCount), switchTime(switchTime),
    totalTime(0), currentFrame(0)
{
    frameWidth = texture->getSize().x / frameCount;
    frameHeight = texture->getSize().y;
}

void Animation::update(float deltaTime) {
    totalTime += deltaTime;
    if (totalTime >= switchTime) {
        totalTime -= switchTime;
        currentFrame = (currentFrame + 1) % frameCount;
    }
}

sf::IntRect Animation::getCurrentFrameRect() const {
    return sf::IntRect(currentFrame * frameWidth, 0, frameWidth, frameHeight);
}

sf::Texture* Animation::getTexture() const {
    return texture;
}


