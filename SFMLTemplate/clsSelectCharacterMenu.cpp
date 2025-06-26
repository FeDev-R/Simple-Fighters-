#include "clsSelectCharacterMenu.h"
#include <iostream>

selectCharacterMenu::selectCharacterMenu()
{
    float scaleX = float(1080) / 640;
    float scaleY = float(720) / 480;
    if (!backgroundImage.loadFromFile("./assets/backgroundSelectCharacter.jpg")) {
        std::cout << "error al cargar " << std::endl;
    }
    backgroundSelectCharacters.setTexture(backgroundImage);
    backgroundSelectCharacters.setScale(scaleX, scaleY);
}

// agrega un retrato al menu, guardando un objeto ProfileCharacters
void selectCharacterMenu::addPortrait(const std::string& texturePath, const std::string& id, sf::Vector2f position) {
    Profiles.emplace_back(std::make_unique<ProfileCharacters>(texturePath, id, position));
}

// actualiza el estado del menu, detecta hover y clicks sobre perfiles
void selectCharacterMenu::update(sf::Vector2f mousePos, float deltaTime)
{
    sf::Vector2f mousePosition = mousePos;

    cdClick -= deltaTime;
    bool canClick = (cdClick <= 0.0f);

    for (auto& p : Profiles) {
        if (p->getGlobalBounds().contains(mousePosition)) {
            p->setSelected(true);

            // si clickea con el mouse sobre el perfil
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                checkCharacters(*p, Personajes);
            }

            // seleccion con tecla espacio y cooldown para evitar spam
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canClick && Personajes < 2) {
                cdClick = 0.5f; // cooldown de medio segundo

                if (Personajes == 0) {
                    Id1 = p->getCharacterID();
                    Personajes++;
                    std::cout << "se ha guardado exitosamente el personaje" << std::endl << Id1;
                }
                else if (Personajes == 1) {
                    Id2 = p->getCharacterID();
                    Personajes++;
                    std::cout << "se ha guardado exitosamente el personaje" << std::endl << Id2;
                }
            }
        }
        else {
            p->setSelected(false);
        }
    }
}

// dibuja el fondo, perfiles y personajes seleccionados
void selectCharacterMenu::draw(sf::RenderWindow& window) {
    window.draw(backgroundSelectCharacters);
    for (auto& p : Profiles) {
        p->draw(window);
    }
    if (checkCharacter1) {
        window.draw(pj1);
    }
    if (checkCharacter2) {
        window.draw(pj2);
    }
}

// asigna textura y posiciona el personaje seleccionado en el menu
void selectCharacterMenu::checkCharacters(ProfileCharacters& p, int Personajes)
{
    if (Personajes == 0) {
        pj1.setTexture(p.getTexture());
        pj1.setPosition(20.0f, 300.0f);
        pj1.setScale(4.0f, 7.0f);
        checkCharacter1 = true;
    }
    else if (Personajes == 1) {
        pj2.setTexture(p.getTexture());
        pj2.setPosition(1000.0f, 300.0f);
        pj2.setScale(-4.0f, 7.0f);
        checkCharacter2 = true;
    }
}

// devuelve el id del personaje segun si es jugador 1 o 2
std::string selectCharacterMenu::saveCharactersID(bool esJugador1)
{
    if (esJugador1) {
        return Id1;
    }
    return Id2;
}