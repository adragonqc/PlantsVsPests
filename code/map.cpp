#include "map.h"

Map::Map() {
    mapWidth = 9;
    mapHeight = 9;
    tileSize = 32;
    // Load the texture for the tiles
    if (!grassTexture.loadFromFile("graphics/grass.jpg")) {
        // handle error
    }

    // Load the texture for the tiles
    if (!dirtTexture.loadFromFile("graphics/dirt.jpg")) {
        // handle error
    }
    // Set the size of the tile sprite
    //sprite.setTexture(grassTexture);
    // Set the size of the tile sprite
    int newTileSize = 64;
    sprite.setTexture(grassTexture);
    sprite.setScale(sf::Vector2f(2.f, 2.f));
    // sprite.setTextureRect(sf::IntRect(0, 0, newTileSize, newTileSize));
    // sprite.setTextureRect(sf::IntRect(0, 0, tileSize, tileSize));

    // Create the tile grid
    for (int i = 0; i < mapWidth; i++) {
        for (int j = 0; j < mapHeight; j++) {
            // Position the tile based on its index in the grid
            if(i>1&&i<7){
                if(j>4&& j <7){
                    sprite.setTexture(dirtTexture);
                    sprite.setTextureRect(sf::IntRect(0, 0, newTileSize, newTileSize));
                }
                else{
                    sprite.setTexture(grassTexture);
                    sprite.setTextureRect(sf::IntRect(0, 0, newTileSize, newTileSize));

                }
            }
            sprite.setPosition(i * newTileSize, j * newTileSize);

            // Add the tile to the tile array
            tiles[i][j] = sprite;
    }
}
}

void Map::draw(sf::RenderWindow& window) {
    // Draw all the tiles
    for (int i = 0; i < mapWidth; i++) {
        for (int j = 0; j < mapHeight; j++) {
            window.draw(tiles[i][j]);
        }
    }
}
