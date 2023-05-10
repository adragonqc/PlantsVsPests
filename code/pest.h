#ifndef PEST_H
#define PEST_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

// #pragma once
#include "plant.h"

class Pest {
    public:
        Pest(float x, float y,int hP_);
        void update(sf::Time dt, std::vector<Plant> plants);
        void draw(sf::RenderWindow& window);
        const sf::FloatRect getGB();
        void attackSpell(std::vector<Plant>& plants);
        void decreaseHP(int amount);
        int getHP();
        // void collisionWithPlant(Plant* plant);
        

    private:
        sf::Texture texture;
        sf::Sprite sprite;
        float speed;
        sf::Vector2f velocity;
        bool isOnScreen;
        int attackDamage;
        int hP;


};
#endif