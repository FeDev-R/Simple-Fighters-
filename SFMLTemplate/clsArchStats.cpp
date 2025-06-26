#include "clsArchStats.h"
#include <iostream>

ArchStats::ArchStats(Stats statistics, sf::Texture* exitTexture) :
	globalStats(statistics)
{

	backgroundImage.loadFromFile("./Assets/gothic.png");
	backgroundSprite.setTexture(backgroundImage);
	backgroundSprite.setOrigin(sf::Vector2f(backgroundImage.getSize()) / 2.0f);
	backgroundSprite.setScale(4 / 4.5f, 3 / 6.0f);


	float scale = 0.4f;

	textFont.loadFromFile("./Assets/Fonts/Minecraft.ttf");
	timesWinPj1Text.setFont(textFont);
	timesWinPj1Text.setFillColor(sf::Color::White);
	timesWinPj1Text.setOutlineThickness(-1.0f);
	timesWinPj1Text.setOutlineColor(sf::Color::Black);
	timesWinPj1Text.setCharacterSize(32);
	timesWinPj1Text.setScale(sf::Vector2f(scale, scale));

	timesWinPj2Text.setFont(textFont);
	timesWinPj2Text.setFillColor(sf::Color::White);
	timesWinPj2Text.setOutlineThickness(-1.0f);
	timesWinPj2Text.setOutlineColor(sf::Color::Black);
	timesWinPj2Text.setCharacterSize(32);
	timesWinPj2Text.setScale(sf::Vector2f(scale, scale));

	timesPlayedText.setFont(textFont);
	timesPlayedText.setFillColor(sf::Color::White);
	timesPlayedText.setOutlineThickness(-1.0f);
	timesPlayedText.setOutlineColor(sf::Color::Black);
	timesPlayedText.setCharacterSize(32);
	timesPlayedText.setScale(sf::Vector2f(scale, scale));

	timesPlayedElfText.setFont(textFont);
	timesPlayedElfText.setFillColor(sf::Color::White);
	timesPlayedElfText.setOutlineThickness(-1.0f);
	timesPlayedElfText.setOutlineColor(sf::Color::Black);
	timesPlayedElfText.setCharacterSize(32);
	timesPlayedElfText.setScale(sf::Vector2f(scale, scale));

	timesPlayedMafaldaText.setFont(textFont);
	timesPlayedMafaldaText.setFillColor(sf::Color::White);
	timesPlayedMafaldaText.setOutlineThickness(-1.0f);
	timesPlayedMafaldaText.setOutlineColor(sf::Color::Black);
	timesPlayedMafaldaText.setCharacterSize(32);
	timesPlayedMafaldaText.setScale(sf::Vector2f(scale, scale));

	timesPlayedNecromancerText.setFont(textFont);
	timesPlayedNecromancerText.setFillColor(sf::Color::White);
	timesPlayedNecromancerText.setOutlineThickness(-1.0f);
	timesPlayedNecromancerText.setOutlineColor(sf::Color::Black);
	timesPlayedNecromancerText.setCharacterSize(32);
	timesPlayedNecromancerText.setScale(sf::Vector2f(scale, scale));

	timesPlayedKnightText.setFont(textFont);
	timesPlayedKnightText.setFillColor(sf::Color::White);
	timesPlayedKnightText.setOutlineThickness(-1.0f);
	timesPlayedKnightText.setOutlineColor(sf::Color::Black);
	timesPlayedKnightText.setCharacterSize(32);
	timesPlayedKnightText.setScale(sf::Vector2f(scale, scale));


	sf::Vector2f statisticsOrigin(0.0f, -70.0f);

	timesWinPj1Text.setPosition(statisticsOrigin + sf::Vector2f(-190.0f, 0.0f));
	timesWinPj2Text.setPosition(statisticsOrigin + sf::Vector2f(-190.0f, 20.0f));
	timesPlayedText.setPosition(statisticsOrigin + sf::Vector2f(-190.0f, 40.0f));
	timesPlayedElfText.setPosition(statisticsOrigin + sf::Vector2f(-190.0f, 60.0f));
	timesPlayedMafaldaText.setPosition(statisticsOrigin + sf::Vector2f(-190.0f, 80.0f));
	timesPlayedNecromancerText.setPosition(statisticsOrigin + sf::Vector2f(0.0f, 0.0f));
	timesPlayedKnightText.setPosition(statisticsOrigin + sf::Vector2f(0.0f, 20.0f));
	


}

void ArchStats::setArchStats(Stats statistics)
{
	this->globalStats = statistics;
}

void ArchStats::Update(sf::Vector2f mousePos)
{
	sf::Vector2f mousePosition = mousePos;

	


	timesWinPj1Text.setString("Time Survived: " + std::to_string(int(globalStats.getTimesWinPj1())));
	timesWinPj2Text.setString("Total dmg Taken: " + std::to_string(globalStats.getTimesWinPj2()));
	timesPlayedText.setString("Total dmg Dealt " + std::to_string(globalStats.getTimesPlayed()));
	timesPlayedElfText.setString("Total Slimes Defeated: " + std::to_string(globalStats.getTimesPlayedElf()));
	timesPlayedMafaldaText.setString("Total Elem. Slime Defeated: " + std::to_string(globalStats.getTimesPlayedKnight()));
	timesPlayedNecromancerText.setString("Total Spartan Defeated: " + std::to_string(globalStats.getTimesPlayedMafalda()));
	timesPlayedKnightText.setString("Total Reaper Defeated: " + std::to_string(globalStats.getTimesPlayedNecromancer()));
	

	

}

void ArchStats::Draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
	window.draw(timesWinPj1Text);
	window.draw(timesWinPj2Text);
	window.draw(timesPlayedText);
	window.draw(timesPlayedElfText);
	window.draw(timesPlayedMafaldaText);
	window.draw(timesPlayedNecromancerText);
	window.draw(timesPlayedKnightText);

}

