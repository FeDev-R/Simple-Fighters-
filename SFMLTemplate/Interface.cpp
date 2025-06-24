#include "Interface.h"
#include <iostream>

Interface::Interface(float hpMax, float hpMax2)
{
	this->hpMax = hpMax;
	this->hpMax2 = hpMax2;
	configurarRectangle(Hpbackground, sf::Vector2f(500.0f, 45.0f), sf::Color::Black, false);
	configurarRectangle(HpActualBar, sf::Vector2f(490.0f, 40.0f), sf::Color::Red, false);

	Hpbackground.setPosition(sf::Vector2f(30.0f, 0.0f));
	HpActualBar.setPosition(sf::Vector2f(35.0f, 1.0f));

	configurarRectangle(Hpbackground2, sf::Vector2f(500.0f, 45.0f), sf::Color::Black, false);
	configurarRectangle(HpActualBar2, sf::Vector2f(490.0f, 40.0f), sf::Color::Red, false);

	Hpbackground2.setPosition(sf::Vector2f(550.0f, 0.0f));
	HpActualBar2.setPosition(sf::Vector2f(555.0f, 1.0f));
}

/*Interface::Interface(float hpMax, float hpMax2)
	: isProyectUpgradeVisible(false), proyectUpgradeTimer(0.0f)
{
	this->hpMax = hpMax;

	configurarRectangle(Hpbackground, sf::Vector2f(50.0f, 3.50f), sf::Color::Black, false);
	configurarRectangle(HpActualBar, sf::Vector2f(48.5f, 2.5f), sf::Color::Red, false);


	if (!textFont.loadFromFile("./Assets/Fonts/Minecraft.ttf")) {
		std::cout << "NO FUNCAAAAA / INTERFACECPP";
	}
	//configurarText(ProyectUpgrade, textFont, "LEVEL UP", sf::Color::White, 16, -1.0f, sf::Color::Black, sf::Vector2f(0.4, 0.4));

	//configurarText( textFont, "", sf::Color::White, 32, -1.0f, sf::Color::Black, sf::Vector2f(0.4, 0.4));

}*/

void Interface::UpdateHpBar(float hpActual, float hpActual2)
{
	float hpPercent = hpActual / hpMax;
	HpActualBar.setSize(sf::Vector2f(48.5f * hpPercent, HpActualBar.getSize().y));
	HpActualBar.setScale(10.0f, 1.0f);
	hpPercent = std::max(0.0f, std::min(hpPercent, 1.0f));
	//std::cout << "hpPercent: " << hpPercent << std::endl;

	HpActualBar.setSize(sf::Vector2f(48.5f * hpPercent, HpActualBar.getSize().y));

	float hpPercent2 = hpActual2 / hpMax2;
	HpActualBar2.setSize(sf::Vector2f(48.5f * hpPercent2, HpActualBar2.getSize().y));
	HpActualBar2.setScale(10.0f, 1.0f);
	hpPercent2 = std::max(0.0f, std::min(hpPercent2, 1.0f));
	//std::cout << "hpPercent: " << hpPercent << std::endl;

	HpActualBar2.setSize(sf::Vector2f(48.5f * hpPercent2, HpActualBar2.getSize().y));

}


void Interface::update(sf::Vector2f posToPj, int level, float deltaTime)
{

	Hpbackground.setPosition(sf::Vector2f(posToPj.x - 25, posToPj.y + 25));
	HpActualBar.setPosition(Hpbackground.getPosition().x + 1, Hpbackground.getPosition().y + 0.5);

	

	// Actualizar temporizador de ProyectUpgrade
	if (isProyectUpgradeVisible) {
		proyectUpgradeTimer += deltaTime;
		if (proyectUpgradeTimer >= timeDurationProyect) {
			isProyectUpgradeVisible = false;
		}
		else {
			// Actualizar la posición de ProyectUpgrade para que siga al jugador
			ProyectUpgrade.setPosition(posToPj.x - 12.5, posToPj.y - 20);
		}



	}
}

void Interface::configurarRectangle(sf::RectangleShape& rect, sf::Vector2f size, sf::Color color, bool setOrigin)
{
	rect.setSize(size);
	rect.setFillColor(color);
	if (setOrigin) {
		rect.setOrigin(size / 2.0f);
	}
}

void Interface::configurarText(sf::Text& text, const sf::Font& font, const std::string& str, sf::Color fillColor, unsigned int size, float outlineThickness, sf::Color outlineColor, sf::Vector2f scale)
{
	text.setFont(font);
	text.setFillColor(fillColor);
	text.setOutlineThickness(outlineThickness);
	text.setOutlineColor(outlineColor);
	text.setCharacterSize(size);
	text.setString(str);
	text.setScale(scale);
}

void Interface::Draw(sf::RenderWindow& window)
{
	window.draw(Hpbackground);
	window.draw(HpActualBar);
	window.draw(Hpbackground2);
	window.draw(HpActualBar2);
	if (isProyectUpgradeVisible) {
		window.draw(ProyectUpgrade);
	}
}