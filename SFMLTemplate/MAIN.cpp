#include <SFML/Graphics.hpp>
#include "clsMenu.h"
#include "clsSelectCharacterMenu.h"
#include "clsArchStats.h"
#include "mapa.h"
#include "Animation.h"
#include "Game.h"
#include "Stage.h"
#include "Characters.h"
#include "MafaldaNinja.h"
#include "iostream"
#include "elfa.h"
#include "Interface.h"
#include "Necromancer.h"
#include"Knight.h"
#include<SFML/Audio.hpp>
#include <cstdlib> 
#include <ctime>   
#include "clsArchivoStatistics.h"
#include "gameFunctions.h"

//boton para cambiar musica y poner texto de la vida qaue tiene cada jugador, y nombre dfe personajes
sf::Music* pickRandom(std::vector<sf::Music*>& list) {
    int index = rand() % list.size();
    return list[index];
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Simple Fighters", sf::Style::Default);

    sf::View view(sf::FloatRect(0, 0, 1080, 720));
	sf::View vieWinner(sf::FloatRect(0, 0, 540, 360));
    window.setView(view);
    window.setFramerateLimit(60);

    bool esJugador1 = 1;
    bool esJugador2 = 0;
    bool mousePressedLastFrame = false;
    bool buttonJustPressed = false;
    sf::Font winnerFont;
    if(!winnerFont.loadFromFile("./assets/Fonts/GravityBold8.ttf")) {
        std::cout << "Error al cargar la fuente del ganador" << std::endl;
	}
	sf::Text winnerText;
	winnerText.setFont(winnerFont);
	winnerText.setString("Winner!");

    selectCharacterMenu menuCharacters;
    menuCharacters.addPortrait("./assets/ProfileCharacters/profileElf.png", "1", sf::Vector2f(220.0f, 500.0f));
    menuCharacters.addPortrait("./assets/ProfileCharacters/profileKnight.png", "2", sf::Vector2f(380.0f, 500.0f));
    menuCharacters.addPortrait("./assets/ProfileCharacters/profileWarrior.png", "3", sf::Vector2f(540.0f, 500.0f));
    menuCharacters.addPortrait("./assets/ProfileCharacters/profileNecromancer.png", "4", sf::Vector2f(700.0f, 500.0f));

    Game Juego;
    enum GAMESTATE {
        MENU,
        GAME,
        WIN,
        STATS,
        MENUCHARACTER,
        PAUSE,


    };

    GAMESTATE gameState = MENU;
    GAMESTATE previousState = MENU;

    sf::Vector2f mousePos;
    Stage stage;
    mapa bosque, bosque2, bosque3, sky, hill, utn, country;

    srand(static_cast<unsigned>(time(nullptr)));
    sf::Music* currentMusic = nullptr;

    sf::Music musicMenu, musicMenu2, musicMenu3, musicCharacterSelect, musicCharacterSelect2;
    sf::Music musicGame, musicGame2, musicGame3, musicGame4, musicGame5, musicGame6, musicGame7;
    sf::Music musicVictory, musicVictory2;
    sf::Music musicStats;

    std::vector<sf::Music*> menuMusics = { &musicMenu, &musicMenu2,&musicMenu3   };
    std::vector<sf::Music*> characterMusics = { &musicCharacterSelect };
    std::vector<sf::Music*> gameMusics = { &musicGame, &musicGame2, &musicGame3, &musicGame4, &musicGame5,&musicGame6,&musicGame7 };
    std::vector<sf::Music*> VictoryMusics = { &musicVictory,&musicVictory2 };
    std::vector<sf::Music*> StatsMusics = { &musicStats };

    musicMenu.openFromFile("./assets/music/menu.ogg");
    musicMenu2.openFromFile("./assets/music/menu2.ogg");
    musicMenu3.openFromFile("./assets/music/menu3.ogg");
    musicCharacterSelect.openFromFile("./assets/music/character.ogg");
    musicCharacterSelect2.openFromFile("./assets/music/character2.ogg");
    musicGame.openFromFile("./assets/music/game.ogg");
    musicGame2.openFromFile("./assets/music/game2.ogg");
    musicGame3.openFromFile("./assets/music/game3.ogg");
    musicGame4.openFromFile("./assets/music/game4.ogg");
    musicGame5.openFromFile("./assets/music/game5.ogg");
    musicGame6.openFromFile("./assets/music/game6.ogg");
    musicGame7.openFromFile("./assets/music/game7.ogg");
    musicVictory.openFromFile("./assets/music/victory.ogg");
    musicVictory2.openFromFile("./assets/music/victory2.ogg");
    musicStats.openFromFile("./assets/music/stats.ogg");

    sf::Texture textMenu;
    if (!textMenu.loadFromFile("./assets/themeMenu.png")) {
        std::cout << "NO FUNCA";
    }
    sf::Vector2u sizeImage = textMenu.getSize();
    std::cout << sizeImage.x;
    std::cout << sizeImage.y;

   Menu mainMenu;
   ArchStats archStats(getLastRecordedStats(), &textMenu);


    ///////bosque
  

    bosque.loadFromFile("./assets/bosqueRojo/bosqueRojo.png");
    bosque.loadPlatformTexture("./assets/piso2.png");
    bosque.setName("bosque");
    bosque.fitToWindow(window);
    bosque.addPlatform({ 1080.0f, 70.0f }, { 0.0f, 650 });

    bosque2.loadFromFile("./assets/game_background_3/bosque2.png");
    bosque2.setName("bosque2");
    bosque2.fitToWindow(window);
    bosque2.loadPlatformTexture("./assets/Graveyard.png");
    bosque2.addPlatform({ 1080.0f, 70.0f }, { 0.0f, 650 });

    sky.loadFromFile("./assets/sky/gradient/gradient1.png");
    sky.fitToWindow(window);
    sky.loadPlatformTexture("./assets/piso2.png");
    sky.addPlatform({ 680, 70.0f }, { 200,650 });
    sky.addPlatform({ 680, 30.0f }, { 200,210 });
    sky.addPlatform({ 140, 20.0f }, { 50,540 });
    sky.addPlatform({ 140, 20.0f }, { 70,430 });
    sky.addPlatform({ 140, 20.0f }, { 90,320 });
    sky.addPlatform({ 140, 20.0f }, { 1080 - 170,540 });
    sky.addPlatform({ 140, 20.0f }, { 1080 - 190,430 });
    sky.addPlatform({ 140, 20.0f }, { 1080 - 200,320 });

    hill.loadFromFile("./assets/hill/PREVIEWS/hill.PNG");
    hill.fitToWindow(window);
    hill.loadPlatformTexture("./assets/hill/PNG/5.PNG");
    hill.addPlatform({ 1080.0f, 70.0f }, { 0.0f, 650 });

    bosque3.loadFromFile("./assets/otrobosque/Background.png");
    bosque3.fitToWindow(window);
    bosque3.loadPlatformTexture("./assets/otrobosque/piso.png");
    bosque3.addPlatform({ 1080.0f, 70.0f }, { 0.0f, 650 });

    utn.loadFromFile("./assets/utn.jpg");
    utn.fitToWindow(window);
    utn.loadPlatformTexture("./assets/piso3.png");
    utn.addPlatform({ 680, 70.0f }, { 200,650 });
    utn.addPlatform({ 680, 70.0f }, { 200,250 });
    utn.addPlatform({ 140, 40.0f }, { 50,540 });
    utn.addPlatform({ 140, 40.0f }, { 70,430 });
    utn.addPlatform({ 140, 40.0f }, { 90,320 });
    utn.addPlatform({ 140, 40.0f }, { 1080 - 170,540 });
    utn.addPlatform({ 140, 40.0f }, { 1080 - 190,430 });
    utn.addPlatform({ 140, 40.0f }, { 1080 - 200,320 });

    country.loadFromFile("./assets/country.png");
    country.fitToWindow(window);
    country.setUsarCapasSeparadas(1);
    country.addPlatform({ 1080.0f, 70.0f }, { 0.0f, 600 });

    stage.addMap(bosque);
    stage.addMap(bosque2);
    stage.addMap(sky);
    stage.addMap(hill);
    stage.addMap(bosque3);
    stage.addMap(utn);
    stage.addMap(country);

	int mapaRandom = rand() % 6;
    ////////// ESTADISTICAS PARA TODO LAS STATS
    /*-VECES QUE GANO PJ1
	  - VECES QUE GANO PJ2
	  - VECES QUE EMPATARON
	  -VECES QUE JUGARON
	  - VECES QUE JUGARON CON ELFA
	  - VECES QUE JUGARON CON MAFALDA
	  - VECES QUE JUGARON CON NECROMANCER
	  - VECES QUE JUGARON CON KNIGHT
        */

    int timesWinPj1=0;
    int timesWinPj2=0;
    int timesDraw=0;
    int timesPlayed=0;
    int timesPlayedElf=0;
    int timesPlayedMafalda=0;
    int timesPlayedNecromancer=0;
    int timesPlayedKnight=0;

	stage.setCurrentMap(mapaRandom);
    elfa elfa2(window, esJugador2);
    MafaldaNinja mafalda(window, esJugador1);
    elfa elfa(window, esJugador1);
    Necromancer necromancer(window, esJugador1);
    Knight knight(window, esJugador1);
    MafaldaNinja mafalda2(window, esJugador2);
    Necromancer necromancer2(window, esJugador2);
    Knight knight2(window, esJugador2);

    sf::RectangleShape cursor(sf::Vector2f(20.0f, 20.0f));
    cursor.setOrigin(10.0f, 10.0f);
    cursor.setFillColor(sf::Color::Transparent);

    Characters* jugador1 = nullptr;
    Characters* jugador2 = nullptr;
    Interface* Interfaz = nullptr;
    
    std::string selectedID = "0";
    bool firstTime = true;
    auto& plataformasActuales = stage.getCurrentMap().getPlataformas();

    bool winPj1 = false;

    float deltaTime = 0.0f;
    sf::Clock clock;
    sf::Clock winnerClock;
    
    /// BUCLE DE JUEGO
    previousState = static_cast<GAMESTATE>(-1); // valor inválido para forzar el cambio la primera vez
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (gameState == MENU && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                buttonJustPressed = true;
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                if (gameState == GAME) {
                    gameState = PAUSE;
                }
                else if (gameState == PAUSE) {
                    gameState = GAME;
                }
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape && gameState == STATS) {
				gameState = MENU;
            }
        }

        if (gameState != previousState) {
            if (gameState == PAUSE) {
               
                if (currentMusic != nullptr)
                    currentMusic->pause();
            }
            else if (previousState == PAUSE) {
                
                if (currentMusic != nullptr)
                    currentMusic->play();
            }
            else {
               
                if (currentMusic != nullptr)
                    currentMusic->stop();

                switch (gameState) {
                case MENU:
                    currentMusic = pickRandom(menuMusics);
                    break;
                case MENUCHARACTER:
                    currentMusic = pickRandom(characterMusics);
                    break;
                case GAME:
                    currentMusic = pickRandom(gameMusics);
                    break;
                case WIN:
                    currentMusic = pickRandom(VictoryMusics);
                    break;
                case STATS:
                    currentMusic = pickRandom(StatsMusics);
					break;
                default:
                    currentMusic = nullptr;
                    break;
                }

                if (currentMusic != nullptr) {
                    currentMusic->setLoop(true);
                    currentMusic->play();
                }
            }

            previousState = gameState;
        }
       
        switch (gameState) {
        case MENU: {
            window.clear(sf::Color::Transparent);
            cursor.setPosition(mousePos);
            mainMenu.update(mousePos);

            window.setView(view);
            mainMenu.draw(window);
            window.draw(cursor);

            int optionUnderMouse = mainMenu.getOptionUnderMouse();
            bool mousePressedNow = sf::Mouse::isButtonPressed(sf::Mouse::Left);
            bool buttonJustPressed = mousePressedNow && !mousePressedLastFrame;

            if (buttonJustPressed) {
                if (optionUnderMouse == 3) {
                    gameState = MENUCHARACTER;
                }
                else if (optionUnderMouse == 6) {
                    window.clear(sf::Color::Black);
                    gameState = STATS;

                }
                else if (optionUnderMouse == 10) {
                    /*if (currentMusic != nullptr)
                        currentMusic->stop();

                    currentMusic = pickRandom(menuMusics);
                    if (currentMusic != nullptr) {
                        currentMusic->setLoop(true);
                        currentMusic->play();
                    }*/
                    // No cambies el gameState acá para evitar loops

                    currentMusic->stop();
                }
            }

            window.display();
            mousePressedLastFrame = mousePressedNow;
            break;
        }










        case MENUCHARACTER: {
            window.clear(sf::Color::Transparent);
            cursor.setPosition(mousePos);
            menuCharacters.update(mousePos, deltaTime);


            if (menuCharacters.checkPersonajes() == 1) {
                selectedID = menuCharacters.saveCharactersID(true);
                Juego.incrementCharacterPlayed(selectedID);
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

                Juego.incrementCharacterPlayed(selectedID);
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
                /*int randomMapIndex = rand() % 7;
                stage.setCurrentMap(randomMapIndex);*/
                Juego.incrementTimesPlayed();
                gameState = GAME;
                if (jugador1 != nullptr && jugador2 != nullptr && Interfaz == nullptr) {
                    Interfaz = new Interface(jugador1->getHp(), jugador2->getHp());
                }
                break;
            }

            menuCharacters.draw(window);
            window.draw(cursor);
            window.display();
            break;
        }

        case GAME: {
            sf::View vistaActual = view; // Guardar la vista actual
            //Actualizar estadisticas de los personajes seleccionados


            window.clear(sf::Color::Transparent);

            bool jugador1Muerto = jugador1->getHp() <= 0;
            bool jugador2Muerto = jugador2->getHp() <= 0;



            if (jugador1Muerto || jugador2Muerto) {
                if (jugador1Muerto && !jugador2Muerto) {
                    winPj1 = false;
                    // Actualizar estadísticas
                    Juego.incrementWinPj2();
                    saveStatisticsData("statistics.dat", Juego.getStatistics());
                    gameState = WIN;

                }
                else if (!jugador1Muerto && jugador2Muerto) {
                    winPj1 = true;
                    // Actualizar estadísticas
                    Juego.incrementWinPj1();
                    saveStatisticsData("statistics.dat", Juego.getStatistics());
                    gameState = WIN;

                }
                else {
                    //draw
                }
                winnerClock.restart().asSeconds();
                break;
            }



            window.clear(sf::Color::Transparent);

            if (firstTime) {
                Interfaz->setHpMax(jugador1->getHp(), jugador2->getHp());
                firstTime = false;
            }

            if (jugador1 != nullptr) jugador1->Update(deltaTime, plataformasActuales);
            if (jugador2 != nullptr) jugador2->Update(deltaTime, plataformasActuales);

            Juego.checkCollision(*jugador1, *jugador2, deltaTime);
            Interfaz->UpdateHpBar(jugador1->getHp(), jugador2->getHp());



            window.setView(vistaActual);
            stage.draw(window);
            jugador2->draw(window);
            jugador1->draw(window);
            Interfaz->Draw(window);

            window.display();
            break;
        }
        case WIN: {
            window.clear(sf::Color::Transparent);

            Characters* characterWinner = nullptr;
            if (winPj1) {
                characterWinner = jugador1;
            }
            else {
                characterWinner = jugador2;
            }

            if (winnerClock.getElapsedTime().asSeconds() > 8.0f) {
                gameState = MENU;
                currentMusic->stop();
                break;
            }
            sf::FloatRect bounds = characterWinner->getHitbox().getGlobalBounds();
            sf::Vector2f center(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
            vieWinner.setCenter(center);
            winnerText.setPosition(center.x - winnerText.getGlobalBounds().width / 2.0f, center.y - winnerText.getGlobalBounds().height / 2.0f);
            characterWinner->Update(deltaTime, plataformasActuales);




            window.setView(vieWinner);

            stage.draw(window);

            characterWinner->draw(window);
            window.draw(winnerText);
            window.display();
            break;
        }


        case PAUSE: {
            window.clear(sf::Color::Transparent);


            stage.draw(window);
            if (jugador1 != nullptr) jugador1->draw(window);
            if (jugador2 != nullptr) jugador2->draw(window);
            if (Interfaz != nullptr) Interfaz->Draw(window);

            // Texto de pausa
            sf::Font pauseFont;
            pauseFont.loadFromFile("./assets/Fonts/GravityBold8.ttf");
            sf::Text pauseText("PAUSA", pauseFont, 80);
            sf::Text pauseText2("Presiona ESC para continuar.", pauseFont, 10);
            pauseText.setFillColor(sf::Color::White);
            pauseText.setOutlineColor(sf::Color::Black);
            pauseText.setPosition(350, 300);
            pauseText2.setFillColor(sf::Color::White);
            pauseText2.setOutlineColor(sf::Color::Black);
            pauseText2.setPosition(400, 390);
            window.draw(pauseText);
            window.draw(pauseText2);

            window.display();
            break;
        }
        case STATS:{


            window.clear(sf::Color::Transparent);
            archStats.setArchStats(getLastRecordedStats());
            archStats.Update(mousePos);
            sf::Font statsFont;
            statsFont.loadFromFile("./assets/Fonts/GravityBold8.ttf");
            sf::Text statsText("Presiona ESC para volver.", statsFont, 10);
            statsText.setFillColor(sf::Color::White);
            statsText.setOutlineColor(sf::Color::Black);
            statsText.setPosition(100, 700);

            //DRAW MENU
            window.clear();

            archStats.Draw(window);

            window.draw(cursor);
            window.draw(statsText);



            window.display();
            break;
        }
        default:
            break;
        }
    }

    return 0;
}
