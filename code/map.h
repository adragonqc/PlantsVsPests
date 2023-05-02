#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

class Map {
public:
    Map();

    void draw(sf::RenderWindow& window);

private:
    int mapWidth;
    int mapHeight;
    int tileSize;
    sf::Texture grassTexture;
    sf::Texture dirtTexture;
    sf::Sprite sprite;
    
    sf::Sprite tiles[10][10];
};

#endif

