#include "farmer.h"
#include "plant.h"
#include "pest.h"
#include <iostream>
#include <SFML/Graphics/Rect.hpp>
using namespace std;

Farmer::Farmer() {
    //load farmer poses
    if (!spriteTexture.loadFromFile("graphics/farmerPoses.png")) {
        // handle error
    }

    sprite.setTexture(spriteTexture);//set texture
    sprite.setTextureRect(sf::IntRect(0, 40, 56, 108));//set texture size
    sprite.setScale(sf::Vector2f(0.75f, 0.75f));

    speed = 100.f;
    velocity = {0.f, 0.f};
    isMoving = false;
}

void Farmer::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Farmer::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Farmer::setTextureRect(sf::IntRect rect) {
    sprite.setTextureRect(rect);
}

void Farmer::move(sf::Vector2f offset) {
    sprite.move(offset);
}

void Farmer::update(sf::Time dt, sf::RenderWindow& window) {
    if (isMoving) {
        sf::Vector2f movement = speed * dt.asSeconds() * velocity;
        move(movement);

        // Get the global bounds of the sprite
        sf::FloatRect spriteBounds = sprite.getGlobalBounds();

        // Check if the sprite is going out of the window bounds
        if (spriteBounds.left < 0.f) {
            // Stop the sprite from moving further left
            sprite.setPosition(0.f, sprite.getPosition().y);
        } else if (spriteBounds.left + spriteBounds.width > window.getSize().x) {
            // Stop the sprite from moving further right
            sprite.setPosition(window.getSize().x - spriteBounds.width, sprite.getPosition().y);
        }
        if (spriteBounds.top < 0.f) {
            // Stop the sprite from moving further up
            sprite.setPosition(sprite.getPosition().x, 0.f);
        } else if (spriteBounds.top + spriteBounds.height > window.getSize().y) {
            // Stop the sprite from moving further down
            sprite.setPosition(sprite.getPosition().x, window.getSize().y - spriteBounds.height);
        }
    }
}


void Farmer::handleEvent(sf::Event event, std::vector<Plant>& plants, std::vector<Pest>& pests) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::W:
            case sf::Keyboard::Up:
                velocity.y = -1.f;
                break;
            case sf::Keyboard::S:
            case sf::Keyboard::Down:
                velocity.y = 1.f;
                break;
            case sf::Keyboard::A:
            case sf::Keyboard::Left:
                velocity.x = -1.f;
                break;
            case sf::Keyboard::D:
            case sf::Keyboard::Right:
                velocity.x = 1.f;
                break;
            case sf::Keyboard::E:
                // Check if the farmer is on top of a plant and use waterSpell on that plant
                for (Plant& plant : plants) {
                    if (sprite.getGlobalBounds().intersects(plant.getGB())) {
                        waterSpell(plant);
                        break;
                    }
                }
                break;
            case sf::Keyboard::X:
                sprite.setTextureRect(sf::IntRect(824, 40, 108, 137));
                // Check if the farmer is on top of a plant and use waterSpell on that plant
                for (Pest& pest : pests) {
                    
                    if (sprite.getGlobalBounds().intersects(pest.getGB())) {
                        attackSpell(pests);
                        break;
                    }
                }
                break;
            default:
                break;
        }
        isMoving = true;
    } else if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
            case sf::Keyboard::W:
            case sf::Keyboard::Up:
                velocity.y = 0.f;
                break;
            case sf::Keyboard::S:
            case sf::Keyboard::Down:
                velocity.y = 0.f;
                break;
            case sf::Keyboard::A:
            case sf::Keyboard::Left:
                velocity.x = 0.f;
                break;
            case sf::Keyboard::D:
            case sf::Keyboard::Right:
                velocity.x = 0.f;
                break;
            case sf::Keyboard::E:
                sprite.setTextureRect(sf::IntRect(0, 40, 56, 108));
                break;
            case sf::Keyboard::X:
                sprite.setTextureRect(sf::IntRect(0, 40, 56, 108));
                break;
            default:
                break;
        }
        if (velocity == sf::Vector2f(0.f, 0.f)) {
            isMoving = false;
        }
    }
}


void Farmer::waterSpell(Plant& plant) {
    // Check if the farmer's sprite is intersecting with the plant's sprite
    if (sprite.getGlobalBounds().intersects(plant.getGB())) {
        // Call the startGrowing() function on the plant
        plant.increaseHP(3);
        // Print a message to the console
    }
}

void Farmer::attackSpell(std::vector<Pest>& pests) {
    for (int i = 0; i < pests.size(); i++) {
        if (sprite.getGlobalBounds().intersects(pests[i].getGB())) {
            // Decrease the health of the plant by 10
            pests[i].decreaseHP(10);

            // If the health of the plant reaches 0 or below, remove it from the vector
            if (pests[i].getHP() <= 0) {
                pests.erase(pests.begin() + i);
            }

            // Only attack one pest at a time
            break;
        }
    }
}


