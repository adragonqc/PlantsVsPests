#include "plant.h"

#include <SFML/Graphics/Rect.hpp>
#include <iostream>
using namespace std;

Plant::Plant(float x,float y, int healthPoints, sf::Texture texture) {
    //sf::Texture texture;
    // if (!texture.loadFromFile("graphics/plant.png")) {
    //     // handle error
    // }
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
    hP = healthPoints;
    amountOfWaterings=0;

}

void Plant::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Plant::update(sf::Time dt) {
    if (isGrowing) {
        growTimer += dt;
        number++;
        //cout<<number<<endl;

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
        hP==15;
    }

    amountOfWaterings++;
    std::cout << "The plant has been watered!" << std::endl;
}

void Plant::decreaseHP(int incriment){
    hP-=incriment;
}

int Plant::getHP(){
    return hP;
}
