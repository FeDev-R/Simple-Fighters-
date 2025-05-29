#pragma once
#include"Game.h"
class mapa
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	std::string name;
	sf::FloatRect collisionBox;

public:
	bool loadFromFile(const std::string path) {
		if (!texture.loadFromFile(path))
			return false;
		sprite.setTexture(texture);
		
		return true;
	}

	void setHitbox(bool YesOrNo) {
		if (YesOrNo) {
			collisionBox = sprite.getGlobalBounds();
		}
		else {

		}
	}

	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	
	std::string getName() const { return name; }
	void setName(const std::string& n){ name = n; };

	void setScale(float scaleX, float scaleY) {
		sprite.setScale(scaleX, scaleY);
	}
	void setPosXY(float X, float Y) {
		sprite.setPosition(X, Y);
	}

	void fitToWindow(const sf::RenderWindow& window) {
		sf::Vector2u textureSize = sprite.getTexture()->getSize();
		sf::Vector2u windowSize = window.getSize();

		float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
		float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

		sprite.setScale(scaleX, scaleY);
		sprite.setPosition(0.f, 0.f);  
	}

	void setOrigin(float OriginX, float OriginY, bool ponerOriginEnMedio) {

		if (ponerOriginEnMedio) {
			sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
		}
		else {
			sprite.scale(OriginX, OriginY);
		}
	}


	const sf::FloatRect& getCollisionBox() const {
		return collisionBox;
	}
};