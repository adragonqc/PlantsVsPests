#ifndef PLANT_H
#define PLANT_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

class Plant {
    public:
        Plant(float x, float y, int healthPoints, sf::Texture texture);

        void setPosition(float x, float y);
        // sf::Sprite getSprite() const;
        void draw(sf::RenderWindow& window);
        void update(sf::Time dt);
        void startGrowing();
        void stopGrowing();
        const sf::FloatRect getGB();//global bounds of sprite
        void increaseHP(int incriment);
        void decreaseHP(int incriment);
        int getHP();
        sf::Sprite sprite;

    private:
        // sf::Texture texture;
        
        sf::Time growTime;
        bool isGrowing;
        sf::Time growTimer;
        sf::Time secsPassed;
        int number;
        int hP;
        int amountOfWaterings;
};

#endif
