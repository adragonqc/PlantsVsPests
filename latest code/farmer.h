#ifndef FARMER_H
#define FARMER_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "plant.h"
#include "pest.h"

class Farmer {
public:
    Farmer();

    void draw(sf::RenderWindow& window);
    void setPosition(float x, float y);
    void setTextureRect(sf::IntRect rect);
    void move(sf::Vector2f offset);
    void update(sf::Time dt, sf::RenderWindow& window);
    void handleEvent(sf::Event event, std::vector<Plant>& plants, std::vector<Pest>& pests);
    void waterSpell(Plant& plant);
    void attackSpell(std::vector<Pest>& pests);

private:
    sf::Texture spriteTexture;
    sf::Sprite sprite;
    float speed;
    sf::Vector2f velocity;
    bool isMoving;
};

#endif
