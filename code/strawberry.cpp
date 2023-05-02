#include "strawberry.h"

#include <SFML/Graphics/Rect.hpp>
#include <iostream>
using namespace std;

Strawberry::Strawberry(float x, float y) {
        if (!texture.loadFromFile("items.png")) {
            // error loading texture
        }

        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(5, 89, 18, 17));
        sprite.setPosition(x, y);
    }

}

void Strawberry::draw(sf::RenderWindow& window) {
        window.draw(sprite);
}