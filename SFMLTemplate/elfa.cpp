#include "elfa.h"
elfa::elfa(sf::RenderWindow& window, bool esJugador1) :
    Characters(esJugador1)
{
    //body.setTexture(&texture);
    hp = 300.0f;
    hpMax = 300.0f;
    jumpForce = 500.0f;
    baseDmg = 11;
    setAnimations();
    this->estadoActual = estadoPj::Idle;
    spriteBaseScale = { 4.5,4.5 };


    spriteOffsetsY[estadoPj::Idle] = -80;
    spriteOffsetsY[estadoPj::Move] = -80;
    spriteOffsetsY[estadoPj::Jump] = -80;
    spriteOffsetsY[estadoPj::Attack] = -80;

    spriteOffsetsX[estadoPj::Idle] = 0;
    spriteOffsetsX[estadoPj::Move] = 0;
    spriteOffsetsX[estadoPj::Jump] = 0;
    //spriteOffsetsX[estadoPj::Attack] = 0;


     //body.setTextureRect({ 100,20,50,20 });
    //body.setSize(sf::Vector2f(100.0f, 200.0f));
}

void elfa::Update(float deltaTime, const std::vector<sf::RectangleShape>& plataformas)
{



    if (estadoActual == estadoPj::Attack ) {
        float avance = 70.0f * deltaTime;

        if (movingLeft) {
            hitbox.move(-avance, 0.f);  
            spriteOffsetsX[estadoPj::Attack] = 50.0f;

        }
        else {
            hitbox.move(avance, 0.f);  
            spriteOffsetsX[estadoPj::Attack] = -50.0f;

        }
       
    }

    Characters::Update(deltaTime, column, row, plataformas);

   
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
    animations[estadoPj::Jump] = Animation(&textures[estadoPj::Jump], 11, 0.1f);

    // ATTACK
    textures[estadoPj::Attack].loadFromFile("./assets/elf_png/elf_attack.png");
    animations[estadoPj::Attack] = Animation(&textures[estadoPj::Attack], 10, 0.2f);
}

float elfa::getHP() const
{
    return 0.0f;
}

float elfa::getJumpForce() const
{
    return 0.0f;
}

float elfa::getDMG() const
{
    return 0.0f;
}

void elfa::setHP(float value)
{
}

void elfa::setJumpForce(float value)
{
}

void elfa::setDMG(float value)
{
}
