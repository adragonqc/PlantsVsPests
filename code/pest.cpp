#include "pest.h"

#include <SFML/Graphics/Rect.hpp>

Pest::Pest(float x,float y) {
    texture.loadFromFile("graphics/squirrel.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(8, 197, 15, 24));
    // sprite.setScale(sf::Vector2f(0.75f, 0.75f));


}

void Pest::draw(sf::RenderWindow& window){
    window.draw(sprite);
}

void Pest::move(Time::time dt) {


}

void Pest::collisionWithPlant(Plant* plant)