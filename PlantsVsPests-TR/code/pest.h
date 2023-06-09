#ifndef PEST_H
#define PEST_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

// #pragma once
#include "plant.h"

/**** TR CHANGES the constructor did not have the same parameters at the one in .cpp ****/

class Pest {
    public:
        Pest(float x, float y, int hP_,sf::Texture& texture); //changed
        bool update(sf::Time dt, std::vector<Plant>& plants, float increaseSpeedTimer);
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
        float nummy;


};
#endif