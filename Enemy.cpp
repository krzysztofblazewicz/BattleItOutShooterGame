#include "Enemy.h"
#include <cmath>

Enemy::Enemy(sf::Vector2f startPos) :
    currentState(State::Idle),
    moveSpeed(150.0f),
    attackRange(200.0f) {

    if (texture.loadFromFile("resources/textures/enemy.png")) {
        sprite.setTexture(texture);
        sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
        sprite.setPosition(startPos);
    }
}

void Enemy::Update(float deltaTime, sf::Vector2f playerPos) {
    UpdateState(playerPos);
    ExecuteState(deltaTime, playerPos);

    // Update bullets
    for (auto it = bullets.begin(); it != bullets.end();) {
        it->Update(deltaTime);
        if (it->IsExpired()) {
            it = bullets.erase(it);
        }
        else {
            ++it;
        }
    }
}

void Enemy::UpdateState(sf::Vector2f playerPos) {
    float distance = std::sqrt(
        std::pow(playerPos.x - sprite.getPosition().x, 2) +
        std::pow(playerPos.y - sprite.getPosition().y, 2)
    );

    if (distance < attackRange) {
        currentState = State::Attack;
    }
    else if (distance < 500.0f) {
        currentState = State::Chase;
    }
    else {
        currentState = State::Idle;
    }
}

void Enemy::ExecuteState(float deltaTime, sf::Vector2f playerPos) {
    switch (currentState) {
    case State::Chase: {
        sf::Vector2f direction = playerPos - sprite.getPosition();
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length != 0) direction /= length;
        sprite.move(direction * moveSpeed * deltaTime);
        break;
    }
    case State::Attack:
        if (attackTimer.getElapsedTime().asSeconds() > 1.0f) {
            sf::Vector2f direction = playerPos - sprite.getPosition();
            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
            if (length != 0) direction /= length;

            bullets.emplace_back(sprite.getPosition(), direction, false);
            attackTimer.restart();
        }
        break;
    default: break;
    }
}

void Enemy::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
    for (auto& bullet : bullets) bullet.Draw(window);
}

sf::FloatRect Enemy::GetBounds() const {
    return sprite.getGlobalBounds();
}