#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
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
    // Pest pest(2*64, 1*64,20);
    farmer.setPosition(120.f, 120.f);
    // Plant plant1(2*64, 5*64, 15);
    // Plant plant2(3*64, 5*64, 15);
    // Plant plant3(4*64, 5*64, 15);
    // Plant plant4(5*64, 5*64, 15);
    // Plant plant5(6*64, 5*64, 15);

    sf::Texture texture;
    if (!texture.loadFromFile("graphics/plant.png")) {
        std::cout<<"error not printed"<<std::endl;
    }
    // std::cout<<"error not printed"<<std::endl;

    // Plant plants[10]
    // Plant plant(2*64,4*64,15, texture); //tester

    std::vector<Plant> plants;
    for (int i = 0; i < 5; i++) {
        Plant plant((i+2)*64, 5*64, 15, texture); 
        plants.push_back(plant); // add the new plant to the vector
    }
    for (int i = 0; i < 5; i++) {
        Plant plant((i+2)*64, 6*64, 15, texture); 
        plants.push_back(plant); // add the new plant to the vector
    }

    std::vector<Pest> pests;
    for (int i = 0; i < 5; i++) {
        Pest pest((i+2)*64, 0*64, 20); 
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

    
    /*
    sf::Texture instructionsTexture;
    //display title
    if (!instructionsTexture.loadFromFile("graphics/instructionPage.jpg")) {
        // handle error loading image
    }
    sf::Sprite instructionsSprite(instructionsTexture);
    instructionsSprite.setPosition(0.f, 0.f);
    instructionsSprite.setScale(sf::Vector2f(0.4565f, 0.4565f));
    // titleSprite.setPosition(window.getSize().x / 2 - titleSprite.getLocalBounds().width / 2, window.getSize().y / 2 - titleSprite.getLocalBounds().height / 2);
    // draw title screen
    window.clear();
    window.draw(instructionsSprite);
    window.display();
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            // exit loop on any key press
            goto exit_loop2;
        }
    }

    exit_loop2:
    */


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
        for(int i=0; i<10; i++){
            plants[i].update(dt);
        }
        for(int i=0; i<5; i++){
            pests[i].update(dt,plants);
        }
        // pest.update(dt,plants);
        // plant.update(dt);

        // draw objects
        window.clear();
        map.draw(window);
        farmer.draw(window);
        // pest.draw(window);
        for(int i=0; i<10; i++){
            plants[i].draw(window);
        }
        for(int i=0; i<10; i++){
            pests[i].draw(window);
        }
        // plant.draw(window);
        
        window.display();
    }

    //stop music when window closed
    music.stop();
    music.openFromFile("");


    return 0;
}
