#include "plant.h"

#include <SFML/Graphics/Rect.hpp>
#include <iostream>
using namespace std;

/**** TR CHANGED Plant::Plant() **/

//Plant::Plant(float x,float y, int healthPoints, sf::Texture texture) is AR implementation 

Plant::Plant(float x,float y, int healthPoints, sf::Texture& texture) {
   // sf::Texture texture;
    if (!texture.loadFromFile("graphics/plant.png")) {
    //     // handle error
     }
    sprite.setTexture(texture);
    
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
    sprite.setPosition(x, y);
    // // Get the width and height of the sprite
    // float width = sprite.getLocalBounds().width;
    // float height = sprite.getLocalBounds().height;

    // // Set the origin to the center of the sprite
    // sprite.setOrigin(width / 2, height / 2);

    isGrowing = true;
    growTimer = sf::Time::Zero;
    growTime = sf::seconds(120.f); // 1.5 minutes
    secsPassed = sf::seconds(60);
    number =0;
    maxHP=healthPoints;
    hP = healthPoints;
    amountOfWaterings=0;


    // Initialize healthBar
    healthBar.setFillColor(sf::Color::Green);
    healthBar.setSize(sf::Vector2f(sprite.getGlobalBounds().width, 5));
    healthBar.setOrigin(sf::Vector2f(sprite.getGlobalBounds().width / 2.f, 10));
    healthBar.setPosition(sprite.getPosition().x, sprite.getPosition().y - 20.f);

}

void Plant::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Plant::update(sf::Time dt) {
    // Update healthBar
    float hpRatio = (float)hP / maxHP;
    healthBar.setSize(sf::Vector2f(sprite.getGlobalBounds().width * hpRatio, 5));
    healthBar.setPosition(sprite.getPosition().x, sprite.getPosition().y - 20.f);
    if (isGrowing) {
        growTimer += dt;
        //std::cout<<growTimer<<std::endl;
        number=number +1;//time
       std::cout<<number<<std::endl;

        if(number >= 500 && amountOfWaterings > 2){//grow double size
            sprite.setScale(sf::Vector2f(2.f, 2.f));
        }

        if (number >= 1000 && hP >= 15) {//after 100 seconds the plant will sprout
            growTimer = sf::Time::Zero;
            // Create a new sprite here
            std::cout << "Plant has grown!" << std::endl;
            //isGrowing = false;
        }
    }
}

void Plant::startGrowing() {
    isGrowing = true;
}

void Plant::stopGrowing() {
    isGrowing = false;
    growTimer = sf::Time::Zero;
}

const sf::FloatRect Plant::getGB(){//get global bounds of sprite
    return sprite.getGlobalBounds();
}

void Plant::increaseHP(int incriment){
    if (hP<(15-incriment)){
        hP+=incriment;
    }else{//don't go over 15
        hP=15;
    }
//changed 
    amountOfWaterings++;
    std::cout << "The plant has been watered!" << std::endl;
}

void Plant::decreaseHP(int incriment){
    hP-=incriment;
    std::cout << "The plant has been attacked!" << std::endl;

}

int Plant::getHP(){
    return hP;
}
