#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.h"

/**
 * @class Player
 * @brief Manages player entity including movement, shooting, and power-ups
 *
 * Uses Observer pattern for stat updates
 */

class Player {
public:
    Player();
    void Update(float deltaTime, sf::Vector2f mousePos);
    void Draw(sf::RenderWindow& window);
    void ApplyPowerUp(std::string type, float value);
    sf::FloatRect GetBounds() const;

    // getters
    int GetHealth() const { return health; }
    int GetAmmo() const { return ammo; }

private:
    sf::Sprite sprite;
    sf::Texture texture;
    float moveSpeed;
    int health;
    int ammo;
    std::vector<Bullet> bullets;

    void HandleMovement(float deltaTime);
    void HandleShooting(sf::Vector2f mousePos);
};