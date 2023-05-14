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

#include <random>
/*
recources:
https://en.sfml-dev.org/forums/index.php?topic=20625.0

*/

int main() {
    sf::RenderWindow window(sf::VideoMode(64*9, 64*9), "Farmland");
    window.setFramerateLimit(10);

    // music added:  Reflected Light by SergePavkinMusic 
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
    // for (int i = 0; i < 5; i++) {

    //     Pest pest(((i+2)*64), 0*64, 20, texture); 
    //     pests.push_back(pest); // add the new plant to the vector
    // }

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

    window.clear();
    sf::Texture inTexture;
    //display title
    if (!inTexture.loadFromFile("graphics/instructionPage.jpg")) {
        // handle error loading image
    }
    
    sf::Sprite inSprite(inTexture);
    inSprite.setPosition(0.f, 0.f);
    inSprite.setScale(sf::Vector2f(0.4565f, 0.4565f));//has to be this number
    // draw title screen
    window.clear();
    window.draw(inSprite);
    window.display();

    // texture.loadFromFile("graphics/plant.png");

    clock.restart();
    while (clock.getElapsedTime().asSeconds() < 10) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                // exit loop on any key press
                window.clear();
               goto exit_loop2;
            }
        }
    }
    exit_loop2:


    //load score stuffs
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("Minecraft.ttf")){//find a font
        std::cerr<<"failed to load font"<<std::endl;
    }

    text.setFont(font);


    // Timer for spawning new pests
    sf::Clock pestSpawnTimer;
    float pestSpawnInterval = 2.f; // Spawn a new pest every 5 seconds
    float increaseSpeedTimer = 1;
    int squirrelKillCount =0;

    text.setString("SCRORE : " +std::to_string(squirrelKillCount));
    // set the character size
    text.setCharacterSize(16); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::Magenta);

    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

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
    
    

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(2, 5);
        //randomly generate squirrels
        int random_number = dis(gen);

        if (pestSpawnTimer.getElapsedTime().asSeconds() > pestSpawnInterval && pests.size() < 10) {
            pests.emplace_back(random_number*64, 0, 10, texture); // Add a new pest to the vector //put random number between 2 and 5 *64 here
            pestSpawnTimer.restart(); // Restart the timer
        }
        

/**** TR CHANGES = int i+1 & i++****/
    //   for (auto& pest : pests) {
        for(int i=0;i<pests.size();i++){
        std::cout<<"Priting pests"<<std::endl;
        //for (size_t i = 0; i < pests.size(); i++) {
        //Pest& pest = pests[i]; // get a reference to the i-th element in the vector
       // pest.updatePosition(); // call a member function to update the position
            std::cout<<"hp of pests== " <<pests[i].getHP()<<std::endl;
            if (pests[i].getHP()<1){
                pests.erase(pests.begin()+i);
                squirrelKillCount++;
                text.setString("SCRORE : " +std::to_string(squirrelKillCount));
            }
        }

/**** TR CHANGES****/

/**** TR CHANGES i stops at 5 instead of 10 ****/
        for(int i=0; i<plants.size(); i++){
            plants[i].update(dt);
        // std::cout<<"Priting pests12"<<std::endl;
        }
        
        increaseSpeedTimer++;
        for(int i=0; i<pests.size(); i++){
            bool status = pests[i].update(dt, plants, increaseSpeedTimer);
            if(status){
                pests.erase(pests.begin()+i);
            }
            std::cout<<"Priting 1231"<<std::endl;
        }

        for(int i=0;i<plants.size();i++){
        std::cout<<"Priting plants"<<std::endl;
        //for (size_t i = 0; i < pests.size(); i++) {
        //Pest& pest = pests[i]; // get a reference to the i-th element in the vector
       // pest.updatePosition(); // call a member function to update the position
            std::cout<<"hp of plants== " <<plants[i].getHP()<<std::endl;
            if (plants[i].getHP()<1){
                plants.erase(plants.begin()+i);
            }
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

        for(int i=0; i<plants.size(); i++){
            // std::cout<<"Priting pplantqwew"<<std::endl;
            plants[i].draw(window);
        }
        for(int i=0; i<pests.size(); i++){
            pests[i].draw(window);
        }
        //plant.draw(window);
        window.draw(text);
        
        window.display();
        
    }

    //stop music when window closed
    music.stop();
    music.openFromFile("");


    return 0;
}


/**
https://github.com/SFML/SFML/wiki/Source%3A-Letterbox-effect-using-a-view


Compares the aspect ratio of the window to the aspect ratio of the view,
and sets the view's viewport accordingly in order to archieve a letterbox effect.
A new view (with a new viewport set) is returned.
*/
sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight) {

    // Compares the aspect ratio of the window to the aspect ratio of the view,
    // and sets the view's viewport accordingly in order to archieve a letterbox effect.
    // A new view (with a new viewport set) is returned.

    float windowRatio = windowWidth / (float) windowHeight;
    float viewRatio = view.getSize().x / (float) view.getSize().y;
    float sizeX = 1;
    float sizeY = 1;
    float posX = 0;
    float posY = 0;

    bool horizontalSpacing = true;
    if (windowRatio < viewRatio)
        horizontalSpacing = false;

    // If horizontalSpacing is true, the black bars will appear on the left and right side.
    // Otherwise, the black bars will appear on the top and bottom.

    if (horizontalSpacing) {
        sizeX = viewRatio / windowRatio;
        posX = (1 - sizeX) / 2.f;
    }

    else {
        sizeY = windowRatio / viewRatio;
        posY = (1 - sizeY) / 2.f;
    }

    view.setViewport( sf::FloatRect(posX, posY, sizeX, sizeY) );

    return view;
}