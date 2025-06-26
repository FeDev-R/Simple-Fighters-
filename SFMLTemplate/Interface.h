#pragma once
#include <sfml/Graphics.hpp>

class Interface
{
private:

	float hpMax;
	float hpMax2;
	float HpActual;
	bool isProyectUpgradeVisible; //NUEVA
	float proyectUpgradeTimer; //NUEVA
	const float timeDurationProyect = 2.0f; //NUEVA
	sf::Vector2i size;
	sf::RectangleShape Hpbackground;
	sf::RectangleShape HpActualBar;
	sf::RectangleShape Hpbackground2;
	sf::RectangleShape HpActualBar2;

	sf::Font			textFont;

	sf::Text            ProyectUpgrade;
	sf::Font            textLetters;

public:
	//Interface();
	Interface(float hpMax, float hpMax2);
	void UpdateHpBar(float hpActual, float HpActual2);
	void Draw(sf::RenderWindow& window);
	void update(sf::Vector2f posToPj, int level, float deltaTime);
	void configurarRectangle(sf::RectangleShape& rect, sf::Vector2f size, sf::Color color, bool setOrigin);
	void setHpMax(float hpMax, float hpMax2) { this->hpMax = hpMax; this->hpMax2 = hpMax2; };
};

