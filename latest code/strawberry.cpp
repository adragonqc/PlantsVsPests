#include "strawberry.h"

#include <SFML/Graphics/Rect.hpp>
#include <iostream>
using namespace std;

Strawberry::Strawberry(float x, float y, sf::Texture& texture) 
{
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(326, 28, 109, 103));
        sprite.setPosition(x, y);
}



void Strawberry::draw(sf::RenderWindow& window) {
        window.draw(sprite);
}

const sf::FloatRect Strawberry::getGB(){
    return sprite.getGlobalBounds();
}