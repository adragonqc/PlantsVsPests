#include "pest.h"
#include "plant.h"

#include <SFML/Graphics/Rect.hpp>
#include <iostream>
#include <cmath>

/**** TR CHANGED ****/


Pest::Pest(float x, float y, int hP_,sf::Texture& texture) //changed 
{
    // if (!texture.loadFromFile("graphics/squirrel.png")) {
    // //     // handle error
    //  }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(74, 227, 15, 25));
    // sprite.setScale(sf::Vector2f(0.75f, 0.75f));
    velocity = sf::Vector2f(0.f, 100.f);
    sprite.setPosition(x,y);
    hP=hP_;
    float nummy = 12;

}

void Pest::draw(sf::RenderWindow& window){
    window.draw(sprite);
}

bool Pest::update(sf::Time dt, std::vector<Plant>& plants,float increaseSpeedTimer) {
    velocity.y = 2.f;
    float five = 10;
    if(fmod(increaseSpeedTimer,five)==0.0){
        nummy = nummy+increaseSpeedTimer/10;
    }
    sprite.move(velocity * dt.asSeconds()*nummy);
    
    // Check for collision with the plant
    for(int i = 0; i<plants.size(); i++){
        if (sprite.getGlobalBounds().intersects(plants[i].getGB())) {
            plants[i].decreaseHP(5);
            std::cout<<"plant lost 5 hp"<<std::endl;
            return true;
        }
    }
    return false;


}

const sf::FloatRect Pest::getGB(){
    return sprite.getGlobalBounds();
}

int Pest::getHP(){
    return hP;
}

void Pest::decreaseHP(int amount){
    hP-=amount;
}


void Pest::attackSpell(std::vector<Plant>& plants) {
    for (int i = 0; i < plants.size(); i++) {
        if (sprite.getGlobalBounds().intersects(plants[i].getGB())) {
            // Decrease the health of the plant by 10
            plants[i].decreaseHP(5);
            std::cout<<"plant lost 5 hp"<<std::endl;

            // If the health of the plant reaches 0 or below, remove it from the vector
            // if (plants[i].getHP() <= 0) {
            //     plants.erase(plants.begin() + i);
            // }

            // Only attack one pest at a time
            break;
        }
    }
}



// void Plant::decreaseHP(int incriment){
//     ;
//     std::cout << "The pest has been attacked!" << std::endl;

// }

// void Pest::collisionWithPlant(Plant* plant)