#include "Characters.h"
#include <iostream>

Characters::Characters(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
    : Animation (texture, imageCount, switchTime)
{
    
    body.setTexture(texture);
    //body.setTextureRect({ 40,0,50,100 });

    body.setSize(sf::Vector2f(100.0f, 200.0f));
   //body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
   

    if (player1) {
        body.setPosition(sf::Vector2f(200.0f,100.0f));

    }
    else {
        body.setPosition(sf::Vector2f(820.0f, 500.0f));
    }
}


void Characters::Update(float deltaTime, int column, int row, const std::vector<sf::RectangleShape>& plataformas)
{
    sf::Vector2f movement(0.0f, 0.0f);



    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= 2;
        body.setScale(-1.0f, 1.0f);
       
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += 2;
        body.setScale(1.f, 1.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isOnGround) {
        velocity.y =-jumpForce;
        isOnGround = false;

    }
    if (!isOnGround) {
        velocity.y += gravity * deltaTime;

    }
    movement.y = velocity.y * deltaTime;

    isOnGround = false;

    body.move(movement.x, 0);
    //aca agrego las colisiones horizontales

    body.move(0, movement.y);
    bool onGroundThisFrame = false;
    const float tolerancia = 10.0f;

    for (const auto& plataforma : plataformas) {
        if (body.getGlobalBounds().intersects(plataforma.getGlobalBounds())) {
            sf::FloatRect personajeBounds = body.getGlobalBounds();
            sf::FloatRect plataformaBounds = plataforma.getGlobalBounds();

            float personajeBottom = body.getPosition().y + body.getSize().y;
            float plataformaTop = plataformaBounds.top;
            std::cout << "PJ bottom: " << personajeBottom << ", PL top: " << plataformaTop << std::endl;

            if (velocity.y >= 0 && personajeBottom <= plataformaTop + tolerancia) {
                
                body.setPosition(body.getPosition().x, plataformaTop - body.getSize().y);

                velocity.y = 0;
                onGroundThisFrame = true;
            }
        }
    }
    isOnGround = onGroundThisFrame;

    body.setOutlineColor(sf::Color::Magenta); 
    body.setOutlineThickness(1.0f);

    ///QUIETO O EN MOVIMIENTO

    if ((movement.x != 0.0f) && (movement.y == 0)) {
        Characters::estadoActual = estadoPj::Move;
    }
    else if (movement.x == 0.0f && movement.y == 0.0f) {
        Characters::estadoActual = estadoPj::Idle;
    }


    this->column = column;
    this->row = row;

    //std::cout << this->column;
    //std::cout << this->row;

    /*if (movement.x > 0.0f)
        faceRight = true;
    else if (movement.x == 0)
        ;
    else
        faceRight = false;
        */

    Animation.update(row, deltaTime, column);
    body.setTextureRect(Animation.TextureRect);
    
   


}


bool Characters::loadFromFile(const std::string& path) {
    if (!texture.loadFromFile(path))
        return false;
    sprite.setTexture(texture);
    return true;
}

void Characters::draw(sf::RenderWindow& window) const {

   
    window.draw(body);
}



void Characters::setPosition(sf::Vector2f pos) {
    sprite.setPosition(pos);
}

sf::Vector2f Characters::getPosition() const {
    return sprite.getPosition();
}

sf::FloatRect Characters::getBounds() const {
    return sprite.getGlobalBounds();
}

bool Characters::collidesWith(const sf::FloatRect& other) const {
    return getBounds().intersects(other);
}