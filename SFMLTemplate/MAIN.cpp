#include <SFML/Graphics.hpp>
#include "clsMenu.h"
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

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Simple Fighters", sf::Style::Default);
    
    sf::View view(sf::FloatRect(0, 0, 1080, 720));
    window.setView(view);
    window.setFramerateLimit(60);

    bool esJugador1 = 1;
    bool esJugador2 = 0;

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


    sf::Texture textMenu;
    textMenu.loadFromFile("./assets/themeMenu.png");
   if(!textMenu.loadFromFile("./assets/themeMenu.png")) {
            std::cout << "NO FUNCA";
    }
   sf::Vector2u sizeImage = textMenu.getSize();
   std::cout << sizeImage.x;
   std::cout << sizeImage.y;

   Menu mainMenu(&textMenu);



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
    //MafaldaNinja mafalda(window, esJugador1);
    elfa elfa(window, esJugador1);
    Necromancer necromancer(window, esJugador2);
    Knight knight(window, esJugador2);

    sf::RectangleShape cursor(sf::Vector2f(20.0f, 20.0f));
    cursor.setOrigin(20.0f / 2.0f, 20.0f / 2.0f);
    cursor.setFillColor(sf::Color::Red);
    
    //USAR UNA CLASE INTERFAZ
    Interface Interfaz(knight.getHp(), elfa.getHp());
   

    auto& plataformasActuales = stage.getCurrentMap().getPlataformas();

    float deltaTime = 0.0f;
    
    sf::Clock clock;
    
    /// BUCLE DE JUEGO

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
       


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        switch (gameState)
        {
        case MENU:
            mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            cursor.setPosition(mousePos);
            mainMenu.update(mousePos);
            mainMenu.draw(window);
            window.draw(cursor);
            if (mainMenu.getOptionPressed() == 3) {
                gameState = GAME;
            }
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
            elfa.Update(deltaTime, plataformasActuales);
            //mafalda.Update(deltaTime,plataformasActuales);
            knight.Update(deltaTime, plataformasActuales);


            //USA SOLO UN INTERFAZ.UPDATEHPBAR 
            Juego.checkCollision(knight, elfa, deltaTime);
            Interfaz.UpdateHpBar(knight.getHp(), elfa.getHp());



            //DRAW

            stage.draw(window);
            //mafalda.draw(window);
            //necromancer.draw(window);
            knight.draw(window);

            elfa.draw(window);
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