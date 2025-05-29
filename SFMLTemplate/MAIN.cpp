#include <SFML/Graphics.hpp>
#include"mapa.h"
#include"Animation.h"
#include"Game.h"
#include"Stage.h"
#include"Characters.h"
#include"MafaldaNinja.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Plantilla SFML");

    bool yes = 1, no = 0;
    Stage stage;
    mapa bosque;
    mapa bosque2;


    bosque.loadFromFile("D:/Repos/SimpleF/x64/Debug/assets/piso.png");
    bosque.setName("bosque");
    //bosque.setPosXY(400.0f, 240);
    //bosque.setOrigin(0, 0, 1);
    bosque.fitToWindow(window);
    bosque.setHitbox(yes);

    bosque2.loadFromFile("D:/Repos/SimpleF/assets/game_background_3/bosque2.PNG");
    bosque2.setName("bosque2");
    bosque2.fitToWindow(window);
    bosque2.setHitbox(yes);

    stage.addMap(bosque);
    stage.addMap(bosque2);
    stage.setCurrentMap(0);

    MafaldaNinja mafalda;

    
    
    
    
    while (window.isOpen())
    {
        
       


        
        
        
        
        
        
        
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();






        window.clear();
        stage.draw(window);
        window.display();
    }

    return 0;
}