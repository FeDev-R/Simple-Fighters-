#include <SFML/Graphics.hpp>

int main()
{
    // Crear una ventana de 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Hello World");

    // Crear un círculo
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Green);

    // Bucle principal de la ventana
    while (window.isOpen())
    {
        // Comprobar los eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana
        window.clear();

        // Dibujar el círculo
        window.draw(shape);

        // Mostrar lo que se ha dibujado
        window.display();
    }

    return 0;
}
