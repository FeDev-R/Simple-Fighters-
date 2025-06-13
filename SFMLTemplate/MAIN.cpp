#include <SFML/Graphics.hpp>
#include"mapa.h"
#include"Animation.h"
#include"Game.h"
#include"Stage.h"
#include"Characters.h"
#include"MafaldaNinja.h"
#include"iostream"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "Plantilla SFML");
   
    window.setFramerateLimit(60);

    bool yes = 1, no = 0;
    Stage stage;
    mapa bosque;
    mapa bosque2;
    

    bosque.loadFromFile("./assets/bosqueRojo/bosqueRojo.png");
    bosque.loadPlatformTexture("./assets/piso2.png");
    bosque.setName("bosque");
    //bosque.setPosXY(400.0f, 240);
    //bosque.setOrigin();
    bosque.fitToWindow(window);
    //bosque.setHitbox(yes);
    bosque.addPlatform({ 1080.0f, 70.0f }, { 0.0f, 650 });
   
    bosque2.loadFromFile("./assets/game_background_3/bosque2.png");
    bosque2.setName("bosque2");
    //bosque2.fitToWindow(window);
    //bosque2.setHitbox(yes);
   // bosque2.setPosXY(500, 500);
   
    bosque2.loadPlatformTexture("./assets/piso.png");
    bosque2.addPlatform({ 300, 150 }, { 500, 200 });

    stage.addMap(bosque);
    stage.addMap(bosque2);
    stage.setCurrentMap(0);
    
    sf::Texture Mafalda_Texture;
    Mafalda_Texture.loadFromFile("./assets/Warrior-Spritesheet5.png");
    if (!Mafalda_Texture.loadFromFile("./assets/Warrior-Spritesheet5.png")) {
        std::cout << "Error: No se pudo cargar la textura" << std::endl;
    }

    MafaldaNinja mafalda(&Mafalda_Texture, window, sf::Vector2u(14,6), 0.15f);
    auto& plataformasActuales = stage.getCurrentMap().getPlataformas();

    float deltaTime = 0.0f;
    
    sf::Clock clock;
    
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
       


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //CMD - Joy

        //UPDATE



        window.clear(sf::Color(150,150,150));
        mafalda.Update(deltaTime,plataformasActuales);
        //DRAW
        stage.draw(window);
        mafalda.draw(window);
        window.display();
    }

    return 0;
}