#pragma once
#include <SFML/Graphics.hpp>

/**
 * @class Bullet
 * @brief Manages bullet physics and rendering
 *
 * Implements Flyweight pattern for shared properties
 */

class Bullet {
public:
    Bullet(sf::Vector2f startPos, sf::Vector2f direction, bool isPlayerBullet);
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    bool IsExpired() const;
    sf::FloatRect GetBounds() const;
    bool IsPlayerBullet() const;

private:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f direction;
    float speed;
    bool playerBullet;
    sf::Clock lifetimeClock;
};