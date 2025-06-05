#include "Animation.h"
#include "Menu.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	TextureRect.width = texture->getSize().x / float(imageCount.x);
	TextureRect.height = texture->getSize().y / float(imageCount.y);
}

/*Animation::Animation(int frameWidth, int frameHeight, int frameCount, float frameDuration)
	: frameRect(0, 0, frameWidth, frameHeight),
	frameCount(frameCount),
	frameDuration(frameDuration) {
}*/

void Animation::update(int row, float deltaTime)
{
	
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x) {
			currentImage.x = 0;
		}
	}

	TextureRect.left = currentImage.x * TextureRect.width;
	TextureRect.top = currentImage.y * TextureRect.height;
	
}

/*sf::IntRect Animation::getCurrentFrameRect() const
{
	//return frameRect;
}*/



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
