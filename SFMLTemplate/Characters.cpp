#include "Characters.h"
#include <iostream>


Characters::Characters(bool esJugador1)
    
{
    player1 = esJugador1;

    sf::Vector2u texSize = textures[estadoActual].getSize();
    //body.setOrigin(texSize.x / 2.f, texSize.y /2);
    
    body.setScale(3.0f, 3.0f);

    hitbox.setPosition(200.f, 300.f);
    body.setPosition(hitbox.getPosition().x, hitbox.getPosition().y + hitbox.getSize().y / 2.f);
    hitbox.setSize(sf::Vector2f(40.0f, 140.0f)); 
    hitbox.setOrigin(hitbox.getSize() / 2.f);
    hitbox.setOutlineColor(sf::Color::Green);
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineThickness(2.0f);
   
 
    
    //body.setPosition(50.0f, 50.0f);
    //body.setScale(1.0f, 0.25f);
   
   

    if (player1) {
        body.setPosition(sf::Vector2f(200.0f,100.0f));
        hitbox.setPosition(body.getPosition().x, body.getPosition().y - hitbox.getSize().y / 2.f);
    }
    else {
        body.setPosition(sf::Vector2f(820.0f, 100.0f));
        hitbox.setPosition(body.getPosition().x, body.getPosition().y - hitbox.getSize().y / 2.f);
    }
    estadoActual = estadoPj::Idle;
}

void Characters::actualizarEstado(sf::Vector2f movement) {
    if (checkIfAttack) return;

    if ((movement.x != 0.0f) && (movement.y == 0)) {
        estadoActual = estadoPj::Move;
    }
    else if (movement.x == 0.0f && movement.y == 0.0f) {
        estadoActual = estadoPj::Idle;
    }
}

void Characters::setEstado(estadoPj nuevoEstado)
{
    estadoActual = nuevoEstado;
}

void Characters::Update(float deltaTime, int column, int row, const std::vector<sf::RectangleShape>& plataformas)
{
    sf::Vector2f movement(0.0f, 0.0f);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= 2;
        body.setScale(-3.0f, 3.0f);
        movingLeft = true;
       
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += 2;
        body.setScale(3.0f, 3.0f);
        movingLeft = false;
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        Characters::estadoActual = estadoPj::Attack;
        Ataque.attackAction(hitbox);
        if (movingLeft) {
            body.setScale(-3.0f, 3.0f);
        }
        else{ body.setScale(3.0f, 3.0f); }

        checkIfAttack = true;
        attackTimer = 0.0f;
        //std::cout << "Botón clickeado!" << std::endl;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isOnGround) {
        velocity.y =-jumpForce;
        isOnGround = false;
        Characters::estadoActual = estadoPj::Jump;

    }
    if (!isOnGround) {
       velocity.y += gravity * deltaTime;

    }
    if (checkIfAttack) {
        attackTimer += deltaTime;

        if (attackTimer >= cooldown) {
            checkIfAttack = false;
            Characters::estadoActual = estadoPj::Idle; 
        }
    }
   
    movement.y = velocity.y * deltaTime;
    isOnGround = false;
    std::cout << "DeltaTime: " << deltaTime
        << " | Velocity.y: " << velocity.y
        << " | Movement.y: " << movement.y << std::endl;


    hitbox.move(movement.x, 0);
    //aca agrego las colisiones horizontales
    bool onGroundThisFrame = false;
    float movimientoVerticalRestante = movement.y;
    float paso = 1.0f;
    const float tolerancia = 5.0f;

    while (std::abs(movimientoVerticalRestante) > 0.0f) {
        float deltaPaso = std::min(paso, std::abs(movimientoVerticalRestante));
        float signo = movimientoVerticalRestante > 0 ? 1.f : -1.f;
        hitbox.move(0, signo * deltaPaso);

        for (const auto& plataforma : plataformas) {
            if (hitbox.getGlobalBounds().intersects(plataforma.getGlobalBounds())) {
                sf::FloatRect personajeBounds = hitbox.getGlobalBounds();
                sf::FloatRect plataformaBounds = plataforma.getGlobalBounds();

                float personajeBottom = personajeBounds.top + personajeBounds.height;
                float plataformaTop = plataformaBounds.top;

                if (velocity.y >= 0 && personajeBottom <= plataformaTop + tolerancia) {
                    float nuevaY = plataformaTop - hitbox.getSize().y / 2.f;
                    hitbox.setPosition(hitbox.getPosition().x, nuevaY);
                    velocity.y = 0;
                    onGroundThisFrame = true;
                    goto FIN_CAIDA; // salimos del while
                }
            }
        }

        movimientoVerticalRestante -= signo * deltaPaso;
    }
FIN_CAIDA:
    isOnGround = onGroundThisFrame;


    ///QUIETO O EN MOVIMIENTO
    actualizarEstado(movement);

    this->column = column;
    this->row = row;

    //std::cout << "\nSIZE X: " << body.getSize().x << " SIZE Y: " << body.getSize().y;

    auto& anim = animations[estadoActual];
    sf::IntRect rect = anim.getCurrentFrameRect();
   
 
    anim.update(deltaTime);
    body.setTexture(textures[estadoActual]);
    body.setTextureRect(rect);
    //body.setOrigin(rect.width / 2.f, rect.height);
   body.setOrigin(rect.width / 2.f, static_cast<float>(rect.height));
    //body.setOrigin(rect.width / 2.f, 135);

   
   float offset = spriteOffsetsY[estadoActual];
   body.setPosition(hitbox.getPosition().x, hitbox.getPosition().y - offset);


    //std::cout << "body top: " << body.getGlobalBounds().top<<"hitbox top: "<<hitbox.getGlobalBounds().top << std::endl;
    //std::cout << "TextureRect: left=" << rect.left << ", top=" << rect.top << ", width=" << rect.width << ", height=" << rect.height << std::endl;

}


bool Characters::loadFromFile(const std::string& path) {
    if (!texture.loadFromFile(path))
        return false;
    sprite.setTexture(texture);
    return true;
}

void Characters::draw(sf::RenderWindow& window) {

   
    window.draw(body);
    window.draw(hitbox);
   if (checkIfAttack) {
        window.draw(Ataque.GetHitBox());
    }
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