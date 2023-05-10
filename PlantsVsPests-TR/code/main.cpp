#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <string>
#include<iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Rect.hpp>

#include "map.h"
#include "farmer.h"
#include "plant.h"
#include "pest.h"
/*
recources:
https://en.sfml-dev.org/forums/index.php?topic=20625.0

*/

int main() {
    sf::RenderWindow window(sf::VideoMode(64*9, 64*9), "Farmland");
    window.setFramerateLimit(10);

    //music added:  Reflected Light by SergePavkinMusic 
    sf::Music music;
    if (!music.openFromFile("reflected-light.wav"))
    {
        std::cerr << "Failed to load music file." << std::endl;
    }
    else
    {
        music.setLoop(true);
        music.play();
    }


    // create map and farmer objects
    Map map;
    Farmer farmer;
    farmer.setPosition(120.f, 120.f);

    sf::Texture texture;
    if (!texture.loadFromFile("graphics/spriteSheet.png")) {
        std::cout<<"error not printed"<<std::endl;
    }

    std::vector<Plant> plants;
   //for (int i = 0; i < 5; i++) {
       // Plant plant((i+2)*64, 5*64, 15, texture); 
        //plants.push_back(plant); // add the new plant to the vector
    //} 
    for (int i = 0; i < 5; i++) {
        Plant plant((i+2)*64, 6*64, 15, texture); 
        plants.push_back(plant); // add the new plant to the vector
    }

    std::vector<Pest> pests;
    for (int i = 0; i < 5; i++) {

        Pest pest(((i+2)*64), 0*64, 20, texture); 
        pests.push_back(pest); // add the new plant to the vector
    }

    window.clear();
    sf::Texture titleTexture;
    //display title
    if (!titleTexture.loadFromFile("graphics/titleScreen.jpg")) {
        // handle error loading image
    }
    sf::Sprite titleSprite(titleTexture);
    titleSprite.setPosition(0.f, 0.f);
    titleSprite.setScale(sf::Vector2f(0.4565f, 0.4565f));//has to be this number
    // draw title screen
    window.clear();
    window.draw(titleSprite);
    window.display();

    // texture.loadFromFile("graphics/plant.png");

    sf::Clock clock;
    while (clock.getElapsedTime().asSeconds() < 10) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                // exit loop on any key press
               goto exit_loop1;
            }
        }
    }
    exit_loop1:


    while (window.isOpen()) {
        sf::Time dt = clock.restart();
        
        // handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            farmer.handleEvent(event, plants, pests);
        }
        farmer.update(dt,window);
        

/**** TR CHANGES = int i+1 & i++****/
        int i=1;
      for (auto& pest : pests) {
        std::cout<<"Priting pests"<<std::endl;
        //for (size_t i = 0; i < pests.size(); i++) {
        //Pest& pest = pests[i]; // get a reference to the i-th element in the vector
       // pest.updatePosition(); // call a member function to update the position

            if (pest.getHP()<1){
                pests.erase(pests.begin() + i);
            }i++;
        }
/**** TR CHANGES****/

/**** TR CHANGES i stops at 5 instead of 10 ****/
        for(int i=0; i<5; i++){
            plants[i].update(dt);
        std::cout<<"Priting pests12"<<std::endl;
        }
        
        for(int i=0; i<5; i++){

            pests[i].update(dt,plants);
            std::cout<<"Priting 1231"<<std::endl;
        }
/**** TR CHANGES i stops at 5 instead of 10 ****/

        // pest.update(dt,plants);
        // plant.update(dt);

        // draw objects
        window.clear();
        map.draw(window);
        farmer.draw(window);
       // pest.draw(window);

/**** TR CHANGES i stops at 5 instead of 10 ****/

        for(int i=0; i<5; i++){
            std::cout<<"Priting pplantqwew"<<std::endl;
            plants[i].draw(window);
        }
        for(int i=0; i<5; i++){
            pests[i].draw(window);
        }
        //plant.draw(window);
        
        window.display();
    }

    //stop music when window closed
    music.stop();
    music.openFromFile("");


    return 0;
}
