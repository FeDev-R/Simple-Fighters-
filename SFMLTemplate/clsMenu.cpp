#include "clsMenu.h"


Menu::Menu()
{
	float scaleX = float(1080) / 816;
	float scaleY = float(720) / 480;
	std::cout << scaleX;
	backgroundImage.loadFromFile("./assets/theme.png");
	background.setTexture(backgroundImage);
	background.setScale(scaleX, scaleY);

	if (!fuente.loadFromFile("./assets/Fonts/GravityBold8.ttf")) {
		std::cout << "NO FUNCA";
	}
	configurarText(titleGame, fuente, "Simple Fighters", sf::Color::White,200, -1, sf::Color::Black, sf::Vector2f(0.4f,0.4f));
	titleGame.setFont(fuente);
	titleGame.setPosition((1080 / 2) - (titleGame.getGlobalBounds().width/2), 200);

	if (!buttonPlayImage.loadFromFile("./assets/play.png")) {
		std::cout << "NO FUNCA";
	}
	textureStat.loadFromFile("./assets/pregunta.png");

	sf::Vector2f playSize(128.0f, 64.0f);

	statsButton.setTexture(&textureStat);
	statsButton.setSize(sf::Vector2f(64,64));
	statsButton.setOrigin(playSize / 2.0f);
	statsButton.setPosition(1050, 690);

	playButton.setSize(playSize);
	playButton.setOrigin(playSize / 2.0f);
	playButton.setPosition((1080/2), (720/2));

	
	
}

void Menu::draw(sf::RenderWindow& window) {
	window.draw(background);
	window.draw(titleGame);
	window.draw(playButton);
	window.draw(statsButton);
}

void Menu::configurarText(sf::Text& text, const sf::Font& font, const std::string& str, sf::Color fillColor, unsigned int size, float outlineThickness, sf::Color outlineColor, sf::Vector2f scale)
{
	text.setFont(font);
	text.setFillColor(fillColor);
	text.setOutlineThickness(outlineThickness);
	text.setOutlineColor(outlineColor);
	text.setCharacterSize(size);
	text.setString(str);
	text.setScale(scale);
}

void Menu::update(sf::Vector2f mousePos)
{
	sf::Vector2f mousePosition = mousePos;

	bool mouseOverPlay = false;
	bool mouseOverStats = false;


	sf::Vector2f thisPosition = playButton.getPosition();
	sf::Vector2f thisHalfSize = playButton.getSize() / 2.0f;
	//std::cout << "X" << std::endl << playButton.getSize().x << std::endl;
	//std::cout << "Y" << std::endl << playButton.getSize().y << std::endl;
	float deltaX = mousePos.x - thisPosition.x;
	float deltaY = mousePos.y - thisPosition.y;

	float IntersectX = abs(deltaX) - (thisHalfSize.x);
	float IntersectY = abs(deltaY) - (thisHalfSize.y);

	if (IntersectX < 0 && IntersectY < 0)  /// que pasa si colisiona
	{

		mouseOverPlay = true;
	}

	thisPosition = statsButton.getPosition();
	thisHalfSize = statsButton.getSize() / 2.0f;

	deltaX = mousePos.x - thisPosition.x;
	deltaY = mousePos.y - thisPosition.y;

	IntersectX = abs(deltaX) - (thisHalfSize.x);
	IntersectY = abs(deltaY) - (thisHalfSize.y);

	//std::cout << "intersectX: " << IntersectX << std::endl << "IntersectY: " << IntersectY << std::endl;

	if (IntersectX < 0 && IntersectY < 0)  /// que pasa si se tocan
	{

		mouseOverStats = true;
	}

	this->mouseOnPlay = mouseOverPlay;
	//this->mouseOnStats = mouseOverStats;

	//playAnimation.Update(mouseOverPlay);
	//playButton.setTextureRect(playAnimation.uvRect);

}



int Menu::getOptionPressed()
{
	if (mouseOnPlay && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return 3;
	}
	/*if (mouseOnStats && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		return 2;
	}*/


	return -1;
}