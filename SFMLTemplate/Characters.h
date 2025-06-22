#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Animation.h"
#include "Attacks.h"

class Characters
{

protected:
	enum class estadoPj {
		Idle,
		Move,
		Jump,
		Attack,
	};

	estadoPj estadoActual= estadoPj::Idle;
	std::map<estadoPj, Animation> animations;
	std::map<estadoPj, sf::Texture> textures;
	std::map<estadoPj, float> spriteOffsetsY;
	sf::RectangleShape hitbox;
	Attacks Ataque;
	float hp;
	float moveSpeed;
	float jumpForce;
	float baseDmg;
	sf::Vector2f velocity;
	bool checkIfAttack = false;
	float gravity = 980.0f;
	bool isOnGround = false;
	////
	sf::Sprite body;
	sf::Texture texture;
	sf::RenderWindow window;
	float cooldown = 0.5f;
	float attackTimer;
	int row;
	int column;
	float speed;
	bool movingLeft = 0;
	////

	bool player1 = 1;

	sf::Sprite sprite;
	sf::Vector2f POS{1.0f, 1.0f};

	
	
	
public:
	Characters(bool esJugador1);

	virtual float getHP() const = 0;
	virtual float getJumpForce() const = 0;
	virtual float getDMG() const = 0;

	virtual void setHP(float value) = 0;
	virtual void setJumpForce(float value) = 0;
	virtual void setDMG(float value) = 0;
	void actualizarEstado(sf::Vector2f movement);
	void setEstado(estadoPj nuevoEstado);
	float spriteOffsetY = 0;
	

	void Update(float deltaTime, int column, int row, const std::vector<sf::RectangleShape>& plataformas);
	virtual bool loadFromFile(const std::string& path);
	virtual void draw(sf::RenderWindow& window) ; //QUITE EL CONST
	virtual void setPosition(sf::Vector2f pos);
	virtual sf::Vector2f getPosition() const;
	virtual sf::FloatRect getBounds() const;
	virtual bool collidesWith(const sf::FloatRect& other) const;
	virtual void setAnimations() = 0;


};

