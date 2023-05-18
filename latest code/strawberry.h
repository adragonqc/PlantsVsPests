#ifndef STRAWBERRY_H
#define STRAWBERRY_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

class Strawberry{

    public:
        Strawberry(float x, float y, sf::Texture& texture) ;
        //void draw();
        void draw(sf::RenderWindow& window);
        const sf::FloatRect getGB();

    private:
        sf::Sprite sprite;

};
#endif