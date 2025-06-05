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
    sf::RenderWindow window(sf::VideoMode(800, 600), "Plantilla SFML");
    window.setFramerateLimit(60);

    bool yes = 1, no = 0;
    Stage stage;
    mapa bosque;
    mapa bosque2;


    bosque.loadFromFile("./assets/piso.png");
    bosque.setName("bosque");
    //bosque.setPosXY(400.0f, 240);
    //bosque.setOrigin(0, 0, 1);
    //bosque.fitToWindow(window);
    bosque.setHitbox(yes);

    bosque2.loadFromFile("assets/game_background_3/bosque2.png");
    bosque2.setName("bosque2");
    //bosque2.fitToWindow(window);
    bosque2.setHitbox(yes);

    stage.addMap(bosque);
    stage.addMap(bosque2);
    stage.setCurrentMap(0);
    
    sf::Texture Mafalda_Texture;
    Mafalda_Texture.loadFromFile("./assets/Warrior_spritesheet2.png");
    if (!Mafalda_Texture.loadFromFile("./assets/Warrior_spritesheet2.png")) {
        std::cout << "Error: No se pudo cargar la textura" << std::endl;
    }

    MafaldaNinja mafalda(&Mafalda_Texture, window, sf::Vector2u(5,6), 0.2f);

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



        window.clear();
        mafalda.Update(deltaTime);
        //DRAW
        stage.draw(window);
        mafalda.draw(window);
        window.display();
    }

    return 0;
}