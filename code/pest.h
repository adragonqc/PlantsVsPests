#ifndef PEST_H
#define PEST_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

#pragma once
#include "plant.h"

class Pest {
    public:
        Pest();
        void move(Time::time dt);
        void draw(sf::RenderWindow& window);
        void collisionWithPlant(Plant* plant);
        

    private:
        sf::Texture texture;
        sf::Sprite sprite;
        float speed;
        sf::Vector2f velocity;
        bool isOnScreen;
        int attackDamage;


}
#endif