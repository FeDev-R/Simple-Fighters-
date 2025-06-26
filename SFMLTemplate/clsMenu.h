#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Menu
{

private:
	sf::Texture backgroundImage;
	sf::Sprite background;
	sf::Texture buttonPlayImage;
	sf::Texture textureStat;
	sf::Sprite buttonPlay;
	sf::Sprite spriteStat;

	sf::Texture changeMusicImage;
	sf::Sprite changeMusicButton;
	sf::RectangleShape changeMusicRect;

	sf::RectangleShape playButton;
	sf::RectangleShape statsButton;
	sf::Vector2f sizeImage;
	sf::Font fuente;
	sf::Text titleGame;

	bool mouseOnPlay=false;
	bool mouseOnStats = false;
	bool mouseOnMusic = false;
public:

	Menu();
	void draw(sf::RenderWindow& window);
	void configurarText(sf::Text& text, const sf::Font& font, const std::string& str, sf::Color fillColor, unsigned int size, float outlineThickness, sf::Color outlineColor, sf::Vector2f scale);
	void update(sf::Vector2f mousePos);
	int getOptionPressed();

	int getOptionUnderMouse() const {
		if (mouseOnPlay) return 3;
		if (mouseOnStats) return 6;
		if (mouseOnMusic) return 10;
		return -1;
	}
};

