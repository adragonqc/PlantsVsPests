#ifndef STRAWBERRY_H
#define STRAWBERRY_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

class Strawberry{

    public:
        Strawberry(float x, float y) ;
        //void draw();
        void draw(sf::RenderWindow& window);

    private:
        sf::Texture texture;
        sf::Sprite sprite;

};
#endif