#include "elfa.h"
elfa::elfa(sf::RenderWindow& window, bool esJugador1) :
    Characters(esJugador1)
{
    //body.setTexture(&texture);
    character = 1;
    hp = 600.0f;
    hpMax = 600.0f;
    jumpForce = 700.0f;
    baseDmg = 11;
    this->speed = 4;
    setAnimations();
    this->estadoActual = estadoPj::Idle;
    spriteBaseScale = { 4.5,4.5 };
    
    DmgAttack1 = 300;
    DmgAttack2 = 150;


    spriteOffsetsY[estadoPj::Idle] = -80;
    spriteOffsetsY[estadoPj::Move] = -80;
    spriteOffsetsY[estadoPj::Jump] = -80;
    spriteOffsetsY[estadoPj::Attack] = -80;
    spriteOffsetsY[estadoPj::Attack2] = -80;

    spriteOffsetsX[estadoPj::Idle] = 0;
    spriteOffsetsX[estadoPj::Move] = 0;
    spriteOffsetsX[estadoPj::Jump] = 0;
    //spriteOffsetsX[estadoPj::Attack] = 0;


     //body.setTextureRect({ 100,20,50,20 });
    //body.setSize(sf::Vector2f(100.0f, 200.0f));
}

void elfa::Update(float deltaTime, const std::vector<sf::RectangleShape>& plataformas)
{



    if (estadoActual == estadoPj::Attack) {
        float avance = 70.0f * deltaTime;

        if (movingLeft) {
            hitbox.move(-avance, 0.f);  
            spriteOffsetsX[estadoPj::Attack] = 50.0f;
            

        }
        else {
            hitbox.move(avance, 0.f);  
            spriteOffsetsX[estadoPj::Attack] = -50.0f;
            

        }

        if (velocity.x > 0 && movingLeft) {
            hitbox.move(-addedSpeed, 0.f);
        }
        else if (velocity.x > 0 && !movingLeft) {
            hitbox.move(addedSpeed, 0.f);
            }

    }

    if (estadoActual == estadoPj::Attack2) {

        if (movingLeft) {
            spriteOffsetsX[estadoPj::Attack2] = 50.0f;

        }
        else {
            spriteOffsetsX[estadoPj::Attack2] = -50.0f;

        }
    }

    Characters::Update(deltaTime, plataformas);

   
}

void elfa::draw(sf::RenderWindow& window)
{
    //std::cout << "SCALE X: " << body.getScale().x << " SCALE Y: " << body.getScale().y;

    Characters::draw(window);
}

void elfa::setAnimations()
{
    // IDLE
    textures[estadoPj::Idle].loadFromFile("./assets/elf_png/elf_idle.png");
    animations[estadoPj::Idle] = Animation(&textures[estadoPj::Idle], 6, 0.2f);

    // MOVE
    textures[estadoPj::Move].loadFromFile("./assets/elf_png/elf_run.png");
    animations[estadoPj::Move] = Animation(&textures[estadoPj::Move], 10, 0.1f);

    // JUMP
    textures[estadoPj::Jump].loadFromFile("./assets/elf_png/elf_jump.png");
    animations[estadoPj::Jump] = Animation(&textures[estadoPj::Jump], 11, 0.15f);

    // ATTACK
    textures[estadoPj::Attack].loadFromFile("./assets/elf_png/elf_attack.png");
    animations[estadoPj::Attack] = Animation(&textures[estadoPj::Attack], 10, 0.1f);

    textures[estadoPj::Attack2].loadFromFile("./assets/elf_png/elf_attack2.png");
    animations[estadoPj::Attack2] = Animation(&textures[estadoPj::Attack2], 5, 0.15f);
}


float elfa::getJumpForce() const
{
    return 0.0f;
}



void elfa::setHP(float value)
{
}

void elfa::setJumpForce(float value)
{
}

void elfa::setDmg(int value)
{
    currentDmg = value;
}


