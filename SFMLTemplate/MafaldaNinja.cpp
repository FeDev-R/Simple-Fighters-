#include "MafaldaNinja.h"

MafaldaNinja::MafaldaNinja(sf::RenderWindow& window, bool esJugador1):
    Characters(esJugador1)
{
    //body.setTexture(&texture);
    hpMax = 600.0f;
    hp = 600.0f;
    jumpForce = 700.0f;
    baseDmg = 11;
    speed = 4;
    setAnimations();



    this->estadoActual = estadoPj::Idle;


    body.setScale(3.0f, 3.0f);
    character = 3;

    
    spriteOffsetsY[estadoPj::Idle] = -186;
    spriteOffsetsY[estadoPj::Move] = -186;
    spriteOffsetsY[estadoPj::Jump] = -186;
    spriteOffsetsY[estadoPj::Attack] = -294;
    spriteOffsetsY[estadoPj::Attack2] = -294;
    //body.setTextureRect({ 100,20,50,20 });
    //body.setSize(sf::Vector2f(100.0f, 200.0f));

    DmgAttack1 = 150;
    DmgAttack2 = 150;
}

void MafaldaNinja::Update(float deltaTime, const std::vector<sf::RectangleShape>& plataformas)
{


   
    Characters::Update(deltaTime, plataformas );
   
}

void MafaldaNinja::draw(sf::RenderWindow& window) 
{
    //std::cout << "SCALE X: " << body.getScale().x << " SCALE Y: " << body.getScale().y;

    Characters::draw(window);
}

void MafaldaNinja::setAnimations()
{
    // IDLE
    textures[estadoPj::Idle].loadFromFile("./assets/mafalda/AnimeWarrior/Warrior/Idle.png");
    animations[estadoPj::Idle] = Animation(&textures[estadoPj::Idle], 12, 0.15f);

    // MOVE
    textures[estadoPj::Move].loadFromFile("./assets/mafalda/AnimeWarrior/Warrior/Run.png");
    animations[estadoPj::Move] = Animation(&textures[estadoPj::Move], 8, 0.1f);

    // JUMP
    textures[estadoPj::Jump].loadFromFile("./assets/mafalda/AnimeWarrior/Warrior/Jump.png");
    animations[estadoPj::Jump] = Animation(&textures[estadoPj::Jump], 2, 0.5f);

    // ATTACK
    textures[estadoPj::Attack2].loadFromFile("./assets/mafalda/AnimeWarrior/Warrior/Sword-Combo.png");
    animations[estadoPj::Attack2] = Animation(&textures[estadoPj::Attack2], 14, 0.06f);

    textures[estadoPj::Attack].loadFromFile("./assets/mafalda/AnimeWarrior/Warrior/Attack-2.png");
    animations[estadoPj::Attack] = Animation(&textures[estadoPj::Attack], 7, 0.05f);
}


float MafaldaNinja::getJumpForce() const
{
    return 0.0f;
}



void MafaldaNinja::setHP(float value)
{
}

void MafaldaNinja::setJumpForce(float value)
{
}


