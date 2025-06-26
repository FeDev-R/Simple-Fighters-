#pragma once

#include "SFML/Graphics.hpp"
#include "clsStats.h"
#include <string>

class ArchStats
{
public:
	ArchStats(Stats statistics, sf::Texture* exitTexture);
	void setArchStats(Stats statistics);
	void Update(sf::Vector2f mousePos);
	void Draw(sf::RenderWindow& window);


private:

	Stats globalStats;


	sf::Texture			backgroundImage;
	sf::Sprite			backgroundSprite;
	sf::Font			textFont;


	sf::Text timesWinPj1Text;
	sf::Text timesWinPj2Text;
	sf::Text timesDrawText;
	sf::Text timesPlayedText;
	sf::Text timesPlayedElfText;
	sf::Text timesPlayedMafaldaText;
	sf::Text timesPlayedNecromancerText;
	sf::Text timesPlayedKnightText;





};
