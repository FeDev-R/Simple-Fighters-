#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"mapa.h"
#include<map>
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
	std::map<estadoPj, float> spriteOffsetsX;
	sf::Vector2f spriteBaseScale = { 3.0f, 3.0f };
	bool mousePresionadoAntes = false;
	int lastFrameWidth = 0;
	estadoPj estadoAnterior = estadoPj::Idle;

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

	bool estabaEnElAire = false;
	
	
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
	float spriteOffSetY = 0;
	

	void Update(float deltaTime, int column, int row, const std::vector<sf::RectangleShape>& plataformas);
	virtual bool loadFromFile(const std::string& path);
	virtual void draw(sf::RenderWindow& window) ; //QUITE EL CONST ---- NO IMPORTA ES UN TECNICISMO NO SOMOS PERFECTOS...
	virtual void setPosition(sf::Vector2f pos);
	virtual sf::Vector2f getPosition() const;
	virtual sf::FloatRect getBounds() const;
	virtual bool collidesWith(const sf::FloatRect& other) const;
	virtual void setAnimations() = 0;
	
	virtual float getAttackOffSetX() const {
		return 0.f;
	}
	void controlsPlayer(bool Jugador, sf::Vector2f& movement);

	virtual bool elfaa() const { return false; }
};

