#ifndef STRAWBERRY_H
#define STRAWBERRY_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

class Strawberry{
    public:
        void draw();

    private:
        sf::Texture texture;
        sf::Sprite sprite;

}
#endif