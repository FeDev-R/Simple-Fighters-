#include <SFML/Graphics.hpp>
#include "clsMenu.h"
#include "clsSelectCharacterMenu.h"
#include"mapa.h"
#include"Animation.h"
#include"Game.h"
#include"Stage.h"
#include"Characters.h"
#include"MafaldaNinja.h"
#include"iostream"
#include"elfa.h"
#include "Interface.h"
#include "Necromancer.h"
#include"Knight.h"
#include<SFML/Audio.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Simple Fighters", sf::Style::Default);
    
    sf::View view(sf::FloatRect(0, 0, 1080, 720));
    window.setView(view);
    window.setFramerateLimit(60);

    bool esJugador1 = 1;
    bool esJugador2 = 0;

    selectCharacterMenu menuCharacters;
    menuCharacters.addPortrait("./assets/ProfileCharacters/profileElf.png", "1", sf::Vector2f(800.0f, 500.0f));
    menuCharacters.addPortrait("./assets/ProfileCharacters/profileKnight.png", "2", sf::Vector2f(350.0f, 500.0f));
    menuCharacters.addPortrait("./assets/ProfileCharacters/profileWarrior.png", "3", sf::Vector2f(500.0f, 500.0f));
    menuCharacters.addPortrait("./assets/ProfileCharacters/profileNecromancer.png", "4", sf::Vector2f(650.0f, 500.0f));

    Game Juego;
   // Interface Interfaz;
    enum GAMESTATE {

        MENU,
        PAUSE,
        GAME,
        LOSS,
        WIN,
        STATS,
        MENUCHARACTER,

    };

    GAMESTATE gameState = MENU;
    GAMESTATE previousState = PAUSE;
    ///////////////MAPAS/////////////////////////////////
    
  
    sf::Vector2f mousePos;
    Stage stage;
    mapa bosque;
    mapa bosque2;
    mapa bosque3;
    mapa sky;
    mapa hill;
    mapa utn;
    mapa country;

    sf::Music musicMenu;
    sf::Music musicCharacterSelect;
    sf::Music musicGame;

    musicMenu.openFromFile("./assets/menu.ogg");
    musicCharacterSelect.openFromFile("./assets/character.ogg");
    musicGame.openFromFile("./assets/game.ogg");

    sf::Texture textMenu;
    textMenu.loadFromFile("./assets/themeMenu.png");
   if(!textMenu.loadFromFile("./assets/themeMenu.png")) {
            std::cout << "NO FUNCA";
    }
   sf::Vector2u sizeImage = textMenu.getSize();
   std::cout << sizeImage.x;
   std::cout << sizeImage.y;

   Menu mainMenu;
   


    ///////bosque
    bosque.loadFromFile("./assets/bosqueRojo/bosqueRojo.png");
    bosque.loadPlatformTexture("./assets/piso2.png");
    bosque.setName("bosque");
    bosque.fitToWindow(window);
    //bosque.setHitbox(yes);
    bosque.addPlatform({ 1080.0f, 70.0f }, { 0.0f, 650 });

   
    //////BOSQUE 2
    bosque2.loadFromFile("./assets/game_background_3/bosque2.png");
    bosque2.setName("bosque2");
    bosque2.fitToWindow(window);
    //bosque2.setHitbox(yes);
    bosque2.loadPlatformTexture("./assets/Graveyard.png");
    bosque2.addPlatform({ 1080.0f, 70.0f }, { 0.0f, 650 });


    //////CIELO
    sky.loadFromFile("./assets/sky/gradient/gradient1.png");
    sky.fitToWindow(window);
    sky.loadPlatformTexture("./assets/piso2.png");
    sky.addPlatform({ 680, 70.0f }, { 200,650 });
    sky.addPlatform({ 680, 30.0f }, { 200,210 });
    sky.addPlatform({ 140, 20.0f }, { 50,540 });
    sky.addPlatform({ 140, 20.0f }, { 70,430 });
    sky.addPlatform({ 140, 20.0f }, { 90,320 });
    sky.addPlatform({ 140, 20.0f }, { 1080-170,540 });
    sky.addPlatform({ 140, 20.0f }, { 1080-190,430 });
    sky.addPlatform({ 140, 20.0f }, { 1080-200,320 });
    
    //sky.addPlatform({ 140, 20.0f}, {50,550});
    
    //////paisaje       
    hill.loadFromFile("./assets/hill/PREVIEWS/hill.PNG");
    hill.fitToWindow(window);
    hill.loadPlatformTexture("./assets/hill/PNG/5.PNG");
    hill.addPlatform({ 1080.0f, 70.0f }, { 0.0f, 650 });
    
   ////bosque3
    bosque3.loadFromFile("./assets/otrobosque/Background.png");
    bosque3.fitToWindow(window);
    bosque3.loadPlatformTexture("./assets/otrobosque/piso.png");
    bosque3.addPlatform({ 1080.0f, 70.0f }, { 0.0f, 650 });

    /////utn
    utn.loadFromFile("./assets/utn.jpg");
    utn.fitToWindow(window);
    utn.loadPlatformTexture("./assets/piso3.png");
    //utn.loadPlatformTexture("./assets/utn2.png");

    /*utn.addPlatform({ 1080.0f, 90.0f }, { 0.0f, 650 });*/
    utn.addPlatform({ 680, 70.0f }, { 200,650 });
    utn.addPlatform({ 680, 70.0f }, { 200,250 });
    utn.addPlatform({ 140, 40.0f }, { 50,540 });
    utn.addPlatform({ 140, 40.0f }, { 70,430 });
    utn.addPlatform({ 140, 40.0f }, { 90,320 });
    utn.addPlatform({ 140, 40.0f }, { 1080 - 170,540 });
    utn.addPlatform({ 140, 40.0f }, { 1080 - 190,430 });
    utn.addPlatform({ 140, 40.0f }, { 1080 - 200,320 });
    
    ///////country
    country.loadFromFile("./assets/country.png");
    country.fitToWindow(window);
    country.setUsarCapasSeparadas(1);
    country.addPlatform({ 1080.0f, 70.0f }, { 0.0f, 600 });



    stage.addMap(bosque);//0
    stage.addMap(bosque2);//1
    stage.addMap(sky);//2
    stage.addMap(hill);//3
    stage.addMap(bosque3);//4
    stage.addMap(utn);//5 
    stage.addMap(country); //6
    stage.setCurrentMap(4);

   ///////////////////////////////////////////////////////
	elfa elfa2(window, esJugador2);
    MafaldaNinja mafalda(window, esJugador1);
    elfa elfa(window, esJugador1);
    Necromancer necromancer(window, esJugador1);
    Knight knight(window, esJugador1);
    MafaldaNinja mafalda2(window, esJugador2);
    Necromancer necromancer2(window, esJugador2);
    Knight knight2(window, esJugador2);

    sf::RectangleShape cursor(sf::Vector2f(20.0f, 20.0f));
    cursor.setOrigin(20.0f / 2.0f, 20.0f / 2.0f);
    cursor.setFillColor(sf::Color::Red);
    
    //USAR UNA CLASE INTERFAZ
    Characters* jugador1 = nullptr;//std::unique_ptr<Characters> jugador1; // O tambien puede ser  c:
    Characters* jugador2 = nullptr;
    Interface Interfaz(knight.getHp(), elfa.getHp());
    std::string selectedID = "0";
   

    auto& plataformasActuales = stage.getCurrentMap().getPlataformas();

    float deltaTime = 0.0f;
    
    sf::Clock clock;
    
    /// BUCLE DE JUEGO

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (gameState != previousState) {
            musicMenu.stop();
            musicCharacterSelect.stop();
            musicGame.stop();

            switch (gameState) {
            case MENU:
                musicMenu.setLoop(true);
                musicMenu.play();
                break;
            case MENUCHARACTER:
                musicCharacterSelect.setLoop(true);
                musicCharacterSelect.play();
                break;
            case GAME:
                musicGame.setLoop(true);
                musicGame.play();
                break;
            default:
                break;
            }
            previousState = gameState;
        }

        switch (gameState)
        {
        case MENU:
            
          
            cursor.setPosition(mousePos);
            mainMenu.update(mousePos);
            mainMenu.draw(window);
            window.draw(cursor);
            if (mainMenu.getOptionPressed() == 3) {
                gameState = MENUCHARACTER;
            }
            window.display();
            break;


        case MENUCHARACTER:
            window.clear(sf::Color::Transparent);
            cursor.setPosition(mousePos);
            menuCharacters.update(mousePos, deltaTime);


            if (menuCharacters.checkPersonajes() == 1) {
                selectedID = menuCharacters.saveCharactersID(true);
                if (selectedID == "1") {
                    jugador1 = &elfa;
                }
                else if (selectedID == "2") {
                    jugador1 = &knight;
                }
                else if (selectedID == "3") {
                    jugador1 = &mafalda;
                }
                else if (selectedID == "4") {
                    jugador1 = &necromancer;
                }
            }
            else if (menuCharacters.checkPersonajes() == 2) {
                selectedID = menuCharacters.saveCharactersID(false);
                if (selectedID == "1") {
                    jugador2 = &elfa2;
                }
                else if (selectedID == "2") {
                    jugador2 = &knight2;
                }
                else if (selectedID == "3") {
                    jugador2 = &mafalda2;
                }
                else if (selectedID == "4") {
                    jugador2 = &necromancer2;
                }
            }

            if (menuCharacters.checkPersonajes() == 2) {
                gameState = GAME;
                break;
            }
            menuCharacters.draw(window);
            window.draw(cursor);
            window.display();
            break;
        case GAME:

            //CMD - Joy


            //UPDATE

          /* float ratio = static_cast<float>(window.getSize().x) / window.getSize().y;

          view.setSize(1080.0f * ratio, 720.0f);
          window.setView(view);*/

            window.clear(sf::Color::Transparent);
            //necromancer.Update(deltaTime, plataformasActuales);
            if (jugador1 != nullptr) {
                jugador1->Update(deltaTime, plataformasActuales);
            } else {
                std::cerr << "Error: jugador1 is not initialized!" << std::endl;
            }
            //mafalda.Update(deltaTime,plataformasActuales);
            if (jugador2 != nullptr) {
                jugador2->Update(deltaTime, plataformasActuales);
            }
            else {
                std::cerr << "Error jugador2 is not initialized!" << std::endl;
            }


            //USA SOLO UN INTERFAZ.UPDATEHPBAR 
            Juego.checkCollision(*jugador1, *jugador2, deltaTime);
            Interfaz.UpdateHpBar(jugador1->getHp(), jugador2->getHp());


            //Juego.checkCollision(necromancer, mafalda, deltaTime);
            //Interfaz.UpdateHpBar(mafalda.getHp(),necromancer.getHp());

            //DRAW

            stage.draw(window);
            //mafalda.draw(window);
            //necromancer.draw(window);
            jugador2->draw(window);

            jugador1->draw(window);
            Interfaz.Draw(window);
            window.display();
            break;
        case WIN:
            break;
        case LOSS:
            break;
        
        default:
            break;
        }
        
    }

    return 0;
}