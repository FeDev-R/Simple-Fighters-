#include "Characters.h"
#include <iostream>

Characters::Characters(bool esJugador1)
{
    player1 = esJugador1;

    sf::Vector2u texSize = textures[estadoActual].getSize();

    hitbox.setPosition(200.f, 600.f);
    body.setPosition(hitbox.getPosition().x, hitbox.getPosition().y + hitbox.getSize().y / 2.f);
    hitbox.setSize(sf::Vector2f(40.0f, 140.0f));
    hitbox.setOrigin(hitbox.getSize() / 2.f);
    body.setOrigin(hitbox.getOrigin());

    hitbox.setOutlineColor(sf::Color::Green);
    hitbox.setOutlineThickness(0.0f);
    hitbox.setFillColor(sf::Color::Transparent);

    if (player1) {
        body.setPosition(sf::Vector2f(260.0f, 600.0f));
        hitbox.setPosition(body.getPosition().x, body.getPosition().y - hitbox.getSize().y / 2.f);
        movingLeft = false;
    }
    else {
        body.setPosition(sf::Vector2f(820.0f, 600.0f));
        hitbox.setPosition(body.getPosition().x, body.getPosition().y - hitbox.getSize().y / 2.f);
        movingLeft = true;
    }

    body.setScale(movingLeft ? -spriteBaseScale.x : spriteBaseScale.x, spriteBaseScale.y);

    estadoActual = estadoPj::Idle;
}

void Characters::controlsPlayer(bool Jugador, sf::Vector2f& movement) {

    if (Jugador) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            movement.x -= speed;
            movingLeft = true;
            body.setScale(movingLeft ? -spriteBaseScale.x : spriteBaseScale.x, spriteBaseScale.y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            movement.x += speed;
            movingLeft = false;
            body.setScale(movingLeft ? -spriteBaseScale.x : spriteBaseScale.x, spriteBaseScale.y);
        }

        bool NAhora = sf::Keyboard().isKeyPressed(sf::Keyboard::N);

        // controla ataque 1 (tecla N)
        if (NAhora && !NPresionadoAntes && !checkIfAttack) {
            estadoActual = estadoPj::Attack;
            currentDmg = DmgAttack1;
            setDmg(currentDmg);
            Ataque.attackAction(hitbox, movingLeft, character, 1);
            checkIfAttack = true;
            attackTimer = 0.0f;
            body.setScale(movingLeft ? -spriteBaseScale.x : spriteBaseScale.x, spriteBaseScale.y);
        }
        NPresionadoAntes = NAhora;

        bool MAhora = sf::Keyboard::isKeyPressed(sf::Keyboard::M);

        // controla ataque 2 (tecla M)
        if (MAhora && !MPresionadoAntes && !checkIfAttack) {
            estadoActual = estadoPj::Attack2;
            currentDmg = DmgAttack2;
            setDmg(currentDmg);
            Ataque.attackAction(hitbox, movingLeft, character, 2);
            checkIfAttack = true;
            attackTimer = 0.0f;
            body.setScale(movingLeft ? -spriteBaseScale.x : spriteBaseScale.x, spriteBaseScale.y);
        }
        MPresionadoAntes = NAhora;

        // salto si está en el suelo
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && isOnGround) {
            velocity.y = -jumpForce;
            isOnGround = false;
            if (!checkIfAttack) {
                estadoActual = estadoPj::Jump;
            }
        }
    }
    else {
        // controles para jugador 2 (flechas y mouse)
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            movement.x -= speed;
            movingLeft = true;
            body.setScale(movingLeft ? -spriteBaseScale.x : spriteBaseScale.x, spriteBaseScale.y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            movement.x += speed;
            movingLeft = false;
            body.setScale(movingLeft ? -spriteBaseScale.x : spriteBaseScale.x, spriteBaseScale.y);
        }

        bool mouseAhora = sf::Mouse::isButtonPressed(sf::Mouse::Right);

        // ataque 1 con click derecho
        if (mouseAhora && !mousePresionadoAntes && !checkIfAttack) {
            estadoActual = estadoPj::Attack;
            currentDmg = DmgAttack1;
            setDmg(currentDmg);
            Ataque.attackAction(hitbox, movingLeft, character, 2);
            checkIfAttack = true;
            attackTimer2 = 0.0f;
            body.setScale(movingLeft ? -spriteBaseScale.x : spriteBaseScale.x, spriteBaseScale.y);
        }
        mousePresionadoAntes = mouseAhora;

        // salto jugador 2
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isOnGround) {
            velocity.y = -jumpForce;
            isOnGround = false;
            if (!checkIfAttack) {
                estadoActual = estadoPj::Jump;
            }
        }

        bool mouseAhora2 = sf::Mouse::isButtonPressed(sf::Mouse::Left);

        // ataque 2 con click izquierdo
        if (mouseAhora2 && !mousePresionadoAntes2 && !checkIfAttack2) {
            estadoActual = estadoPj::Attack2;
            currentDmg = DmgAttack2;
            setDmg(currentDmg);
            Ataque.attackAction(hitbox, movingLeft, character, 1);
            checkIfAttack = true;
            attackTimer2 = 0.0f;
            body.setScale(movingLeft ? -spriteBaseScale.x : spriteBaseScale.x, spriteBaseScale.y);
        }
        mousePresionadoAntes2 = mouseAhora2;
    }
}

void Characters::takeDmg(int takenDmg)
{
    hp -= takenDmg;
    std::cout << hp << std::endl;
}

sf::RectangleShape Characters::getHitbox()
{
    return hitbox;
}

int Characters::getHp()
{
    return hp;
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

// update: se encarga de mover, actualizar animacion y chequear colisiones
void Characters::Update(float deltaTime, const std::vector<sf::RectangleShape>& plataformas)
{
    sf::Vector2f movement(0.0f, 0.0f);
    body.setScale(movingLeft ? -spriteBaseScale.x : spriteBaseScale.x, spriteBaseScale.y);

    controlsPlayer(player1, movement);

    // aplica gravedad si no esta en el suelo
    if (!isOnGround) {
        velocity.y += gravity * deltaTime;
    }

    if (!estabaEnElAire && !isOnGround) {
        estabaEnElAire = true;
    }

    if (estabaEnElAire && isOnGround) {
        // aterrizo despues de saltar
        if (estadoActual == estadoPj::Jump) {
            estadoActual = estadoPj::Idle;
            animations[estadoPj::Jump].Reset();
        }
        estabaEnElAire = false;
    }

    // manejo de animacion y temporizador de ataques
    if (checkIfAttack) {
        attackTimer += deltaTime;

        if (estadoActual == estadoPj::Attack) {
            if (animations[estadoPj::Attack].isLastFrame()) {
                checkIfAttack = false;
                estadoActual = estadoPj::Idle;
                animations[estadoPj::Attack].Reset();
                Ataque.reset();
            }
        }
        else if (estadoActual == estadoPj::Attack2) {
            if (animations[estadoPj::Attack2].isLastFrame()) {
                checkIfAttack = false;
                estadoActual = estadoPj::Idle;
                animations[estadoPj::Attack2].Reset();
                Ataque.reset();
            }
        }
    }

    movement.y = velocity.y * deltaTime;
    isOnGround = false;

    hitbox.move(movement.x, 0);

    // chequeo colisiones verticales con plataformas con paso fino para evitar que el personaje atraviese plataformas
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
                    goto FIN_CAIDA; // salto para salir del loop ya que se detecto suelo
                }
            }
        }
        movimientoVerticalRestante -= signo * deltaPaso;
    }
FIN_CAIDA:
    isOnGround = onGroundThisFrame;

    if (checkIfAttack) {
        Ataque.updateAttack(hitbox, movingLeft);
    }
    if (checkIfAttack2) {
        Ataque.updateAttack(hitbox, movingLeft);
    }

    actualizarEstado(movement);

    auto& anim = animations[estadoActual];
    sf::IntRect rect = anim.getCurrentFrameRect();

    // ajustar posicion para cambios en ancho del sprite al cambiar de animacion
    if (estadoActual != estadoAnterior) {
        int deltaWidth = rect.width - lastFrameWidth;
        body.move((deltaWidth / 2.f) * (movingLeft ? -1.f : 1.f), 0.f);
        lastFrameWidth = rect.width;
        estadoAnterior = estadoActual;
    }

    anim.update(deltaTime);
    body.setTexture(textures[estadoActual]);
    body.setTextureRect(rect);
    body.setOrigin(rect.width / 2.f, float(rect.height));

    float offsetY = spriteOffsetsY[estadoActual];
    float offsetX = spriteOffsetsX[estadoActual];

    // posicion del sprite con offsets, especial caso para animacion de ataque de elfaa
    if (elfaa() == true && estadoActual == estadoPj::Attack) {
        if (movingLeft)
            body.setPosition(hitbox.getPosition().x - 50, hitbox.getPosition().y - offsetY);
        else
            body.setPosition(hitbox.getPosition().x + 50, hitbox.getPosition().y - offsetY);
    }
    else {
        body.setPosition(hitbox.getPosition().x - offsetX, hitbox.getPosition().y - offsetY);
    }
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

sf::RectangleShape Characters::getHitboxAttack()
{
    return sf::RectangleShape(Ataque.GetHitBox());
}

void Characters::setDmg(int value) {
    currentDmg = value;
}