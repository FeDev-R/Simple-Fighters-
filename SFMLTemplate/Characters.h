#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <map>            
#include <vector>         
#include <string>         
#include "Animation.h"    
#include "Attacks.h" 


class Characters
{

public:

	enum class estadoPj {
		Idle,
		Move,
		Jump,
		Attack,
		Attack2,
	};

	Characters(bool esJugador1);

	virtual float getJumpForce() const = 0;
	

	virtual void setHP(float value) = 0;
	virtual void setJumpForce(float value) = 0;
	

	float currentDmg;
	virtual int getDmg() const { return static_cast<int>(currentDmg); }
	virtual int getHpMax() const { return static_cast<int>(hpMax); }
	virtual void setDmg(int value);

	void takeDmg(int takenDmg);
	void actualizarEstado(sf::Vector2f movement);
	void setEstado(estadoPj nuevoEstado);
	float spriteOffSetY = 0;
	sf::RectangleShape getHitbox();
	int getHp();

	void controlsPlayer(bool Jugador, sf::Vector2f& movement);


	virtual void Update(float deltaTime,const std::vector<sf::RectangleShape>& plataformas);
	virtual bool loadFromFile(const std::string& path);
	virtual void draw(sf::RenderWindow& window); //QUITE EL CONST ---- NO IMPORTA ES UN TECNICISMO NO SOMOS PERFECTOS...// SO
	virtual void setPosition(sf::Vector2f pos);
	virtual sf::Vector2f getPosition() const;
	virtual sf::FloatRect getBounds() const;
	virtual bool collidesWith(const sf::FloatRect& other) const;
	virtual void setAnimations() = 0;
	

	virtual sf::RectangleShape getHitboxAttack();

	virtual float getAttackOffSetX() const {
		return 0.f;
	}

	virtual bool elfaa() const { return false; }
protected:
	

	estadoPj estadoActual= estadoPj::Idle;
	std::map<estadoPj, Animation> animations;
	std::map<estadoPj, sf::Texture> textures;
	std::map<estadoPj, float> spriteOffsetsY;
	std::map<estadoPj, float> spriteOffsetsX;
	sf::Vector2f spriteBaseScale = { 3.0f, 3.0f };
	bool NPresionadoAntes = false;
	bool MPresionadoAntes = false;
	bool mousePresionadoAntes = false;
	bool mousePresionadoAntes2 = false;
	int attackNum;
	float DmgAttack1;
	float DmgAttack2;


	int lastFrameWidth = 0;
	estadoPj estadoAnterior = estadoPj::Idle;

	sf::RectangleShape hitbox;
	Attacks Ataque;
	Attacks Ataque2;
	float hp;
	float hpMax;
	float moveSpeed;
	float jumpForce;
	float baseDmg;
	sf::Vector2f velocity;
	bool checkIfAttack = false;
	bool checkIfAttack2 = false;
	float gravity = 980.0f;
	bool isOnGround = false;
	////
	sf::Sprite body;
	sf::Texture texture;
	sf::RenderWindow window;
	float cooldown = 0.5f;
	float attackTimer;
	float attackTimer2;
	int row;
	int column;
	float speed = 2;
	
	bool movingLeft = 0;
	int character = 0;
	////

	bool player1 = 1;

	sf::Sprite sprite;
	sf::Vector2f POS{1.0f, 1.0f};

	bool estabaEnElAire = false;
	
	

};

