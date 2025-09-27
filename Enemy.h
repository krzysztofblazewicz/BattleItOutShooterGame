#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.h"

/**
 * @class Enemy
 * @brief Implements AI with finite state machine (Idle/Chase/Attack)
 *
 * Uses Strategy pattern for different behaviors
 */

class Enemy {
public:
    enum class State { Idle, Chase, Attack };

    Enemy(sf::Vector2f startPos);
    void Update(float deltaTime, sf::Vector2f playerPos);
    void Draw(sf::RenderWindow& window);
    sf::FloatRect GetBounds() const;

private:
    sf::Sprite sprite;
    sf::Texture texture;
    State currentState;
    float moveSpeed;
    float attackRange;
    sf::Clock attackTimer;
    std::vector<Bullet> bullets;

    void UpdateState(sf::Vector2f playerPos);
    void ExecuteState(float deltaTime, sf::Vector2f playerPos);
};