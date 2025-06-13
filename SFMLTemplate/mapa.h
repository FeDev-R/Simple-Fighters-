#pragma once
#include"Game.h"
class mapa
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	std::string name;
	std::vector<sf::RectangleShape> plataformas;
	sf::FloatRect collisionBox;

	sf::Texture texturePlatform;
	sf::Sprite spritePlatform;

public:
	void addPlatform(const sf::Vector2f& size, const sf::Vector2f& position) {
		sf::RectangleShape plataforma;
		plataforma.setSize(size);
		plataforma.setPosition(position);
		plataforma.setTexture(&texturePlatform);
		plataforma.setOrigin(0.f, 0.f);
		plataforma.setOutlineColor(sf::Color::Cyan);
		plataforma.setOutlineThickness(1.0f);

		plataformas.push_back(plataforma);

	}

	const std::vector<sf::RectangleShape>& getPlataformas() const {
		return plataformas;
	}

	bool loadFromFile(const std::string path) {
		if (!texture.loadFromFile(path))
			return false;
		sprite.setTexture(texture);

		return true;
	}
	bool loadPlatformTexture(const std::string& path) {
		if (!texturePlatform.loadFromFile(path))
			return false;
		spritePlatform.setTexture(texturePlatform);
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

		for(auto& plataforma: plataformas) {
			window.draw(plataforma);
		}
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
			//sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
		}
		else {
			sprite.scale(OriginX, OriginY);
		}
	}


	const sf::FloatRect& getCollisionBox() const {
		return collisionBox;
	}
};