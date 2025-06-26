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
        std::cout << "no funciona la fuente";
    }
    configurarText(titleGame, fuente, "Simple Fighters", sf::Color::White, 200, -1, sf::Color::Black, sf::Vector2f(0.4f, 0.4f));
    titleGame.setFont(fuente);
    titleGame.setPosition((1080 / 2) - (titleGame.getGlobalBounds().width / 2), 200);

	buttonPlayImage.loadFromFile("./assets/play.png");
	textureStat.loadFromFile("./assets/pregunta.png");
	estadisticasTexture.loadFromFile("./assets/InfoSquare Button.png");

    sf::Vector2f playSize(128.0f, 64.0f);

    statsButton.setTexture(&textureStat);
    statsButton.setSize(sf::Vector2f(64, 64));
    statsButton.setOrigin(playSize / 2.0f);
    statsButton.setPosition(70, 690);

    playButton.setTexture(&buttonPlayImage);
    playButton.setSize(playSize);
    playButton.setOrigin(playSize / 2.0f);
    playButton.setPosition((1080 / 2), (720 / 2));

    changeMusicImage.loadFromFile("./assets/changeMusic.png");
    changeMusicRect.setTexture(&changeMusicImage);
    changeMusicRect.setSize(sf::Vector2f(64, 64));
    changeMusicRect.setOrigin(sf::Vector2f(32, 32));
    changeMusicRect.setPosition(1050, 690);


	/*estadisticasButton.setTexture(&estadisticasTexture);
	estadisticasButton.setSize(sf::Vector2f(64, 64));
	estadisticasButton.setOrigin(playSize / 2.0f);
	estadisticasButton.setPosition(250, 690);*/
	
	
}

void Menu::draw(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(titleGame);
    window.draw(playButton);
    window.draw(statsButton);
    window.draw(changeMusicRect);
	//window.draw(estadisticasButton);
}

// configura propiedades basicas del texto
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

// actualiza si el mouse esta sobre cada boton segun su posicion y tamaño
void Menu::update(sf::Vector2f mousePos)
{
    sf::Vector2f thisPosition;
    sf::Vector2f thisHalfSize;
    float deltaX, deltaY, IntersectX, IntersectY;

    // boton play
    thisPosition = playButton.getPosition();
    thisHalfSize = playButton.getSize() / 2.0f;

    deltaX = mousePos.x - thisPosition.x;
    deltaY = mousePos.y - thisPosition.y;
    IntersectX = abs(deltaX) - thisHalfSize.x;
    IntersectY = abs(deltaY) - thisHalfSize.y;

    mouseOnPlay = (IntersectX < 0 && IntersectY < 0);

    // boton estadisticas
    thisPosition = statsButton.getPosition();
    thisHalfSize = statsButton.getSize() / 2.0f;

    deltaX = mousePos.x - thisPosition.x;
    deltaY = mousePos.y - thisPosition.y;
    IntersectX = abs(deltaX) - thisHalfSize.x;
    IntersectY = abs(deltaY) - thisHalfSize.y;

    mouseOnStats = (IntersectX < 0 && IntersectY < 0);

    // boton cambiar musica
    thisPosition = changeMusicRect.getPosition();
    thisHalfSize = changeMusicRect.getSize() / 2.0f;

    deltaX = mousePos.x - thisPosition.x;
    deltaY = mousePos.y - thisPosition.y;
    IntersectX = abs(deltaX) - thisHalfSize.x;
    IntersectY = abs(deltaY) - thisHalfSize.y;

    mouseOnMusic = (IntersectX < 0 && IntersectY < 0);
}

// devuelve codigo segun boton clickeado, 0 si ninguno
int Menu::getOptionPressed()
{
    if (mouseOnPlay && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return 3;
    }
    else if (mouseOnStats && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return 6;
    }
    else if (mouseOnMusic && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return 10;
    }
    return 0;
}