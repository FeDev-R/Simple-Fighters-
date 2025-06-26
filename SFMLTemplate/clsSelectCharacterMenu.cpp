#include "clsSelectCharacterMenu.h"
#include <iostream>

selectCharacterMenu::selectCharacterMenu()
{
    float scaleX = float(1080) / 640;
    float scaleY = float(720) / 480;
    if (!backgroundImage.loadFromFile("./assets/backgroundSelectCharacter.jpg")) {
        std::cout << "Error al cargar "<< std::endl;
    }
    backgroundSelectCharacters.setTexture(backgroundImage);
    backgroundSelectCharacters.setScale(scaleX, scaleY);
}

void selectCharacterMenu::addPortrait(const std::string& texturePath, const std::string& id, sf::Vector2f position) {
    Profiles.emplace_back(std::make_unique<ProfileCharacters>(texturePath, id, position));
}


void selectCharacterMenu::update(sf::Vector2f mousePos, float deltaTime)
{
    sf::Vector2f mousePosition = mousePos;
    sf::Vector2f thisHalfSize = sf::Vector2f(32.0f, 32.0f);

	cdClick -= deltaTime;
	bool mouseOverProfile = false;
	bool mouseOverProfile2 = false;

	bool canClick = false;
    if(cdClick <= 0.0f) {
        canClick = true;
	}
    for (auto& p : Profiles) {

        if (p->getGlobalBounds().contains(mousePosition)) {
            p->setSelected(true);
           //std::cout << "HOLA, SI ESTAN LOS DOS ACA";
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                checkCharacters(*p);
            }
               if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && canClick && Personajes < 2) {
				   cdClick = 0.5f; // Cooldown de 0.5 segundos

                   if (Personajes == 0) {
                       Id1 = p->getCharacterID();
                       Personajes++;
                       std::cout << "SE HA GUARDADO EXITOSAMENTE EL PERSONAJE" << std::endl << Id1;
                   }
                   else if (Personajes == 1) {
                       Id2 = p->getCharacterID();
                       Personajes++;
                       std::cout << "SE HA GUARDADO EXITOSAMENTE EL PERSONAJE" << std::endl << Id2;
                   }
                  
               }
              // std::cout << Personajes;
              
           
        }
        else {
            p->setSelected(false);
        }
       
    }

}

void selectCharacterMenu::draw(sf::RenderWindow& window) {
    window.draw(backgroundSelectCharacters);
    for (auto& p : Profiles) {
        p->draw(window);
        //std::cout << "Dibujando personaje: " << p->getCharacterID() << std::endl;
            
    }
    if (checkCharacter) {
        window.draw(pj1);
    }
}

void selectCharacterMenu::checkCharacters(ProfileCharacters& p)
{
    pj1.setTexture(p.getTexture());
    pj1.setPosition(20.0f, 300.0f);
    pj1.setScale(4.0f, 7.0f);
    checkCharacter = true;
    //Personajes++;
}

std::string selectCharacterMenu::saveCharactersID(bool esJugador1)
{
    if (esJugador1) {
        return Id1;
    }
    return Id2;
}


