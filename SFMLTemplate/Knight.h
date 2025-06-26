#pragma once
#include "Characters.h"
    class Knight :
        public Characters
    {
    public:
        Knight(sf::RenderWindow& window, bool esJugador1);

        void Update(float deltaTime, const std::vector<sf::RectangleShape>& plataformas) ;
        void draw(sf::RenderWindow& window);

        void setAnimations() override;

       
        float getJumpForce() const override;
       
        

        void setHP(float value) override;
        void setJumpForce(float value) override;
    

        float ataqueOffSetVisualX = 0.f;

        float getAttackOffSetX() const override {
            if (estadoActual == estadoPj::Attack)
                return ataqueOffSetVisualX;
            return 0.f;
        }



    private:
        sf::RectangleShape body;
        sf::Texture texture;
        sf::RenderWindow window;
        int row;
        
    };


