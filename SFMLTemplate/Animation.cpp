#include "Animation.h"
#include "Menu.h"

Animation::Animation()
{
}

Animation::Animation(int frameWidth, int frameHeight, int frameCount, float frameDuration)
	: frameRect(0, 0, frameWidth, frameHeight),
	frameCount(frameCount),
	frameDuration(frameDuration) {
}

void Animation::update(float deltaTime)
{
}

sf::IntRect Animation::getCurrentFrameRect() const
{
	return frameRect;
}



sf::Texture* Animation::getTexture()
{
	return nullptr;
}

void Menu::draw()
{
}

void Menu::gameState()
{
}

void Menu::mousePos()
{
}
