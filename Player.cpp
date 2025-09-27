#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <cmath>

Player::Player() :
    moveSpeed(300.0f),
    health(100),
    ammo(50) {

    if (texture.loadFromFile("resources/textures/player.png")) {
        sprite.setTexture(texture);
        sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
        sprite.setPosition(400, 300);
    }
}

void Player::Update(float deltaTime, sf::Vector2f mousePos) {
    HandleMovement(deltaTime);
    HandleShooting(mousePos);

    // update bullets
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

void Player::HandleMovement(float deltaTime) {
    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y -= 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y += 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x -= 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x += 1.0f;

    if (movement.x != 0 || movement.y != 0) {
        float length = std::sqrt(movement.x * movement.x + movement.y * movement.y);
        movement /= length;
        sprite.move(movement * moveSpeed * deltaTime);
    }
}

void Player::HandleShooting(sf::Vector2f mousePos) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && ammo > 0) {
        sf::Vector2f direction = mousePos - sprite.getPosition();
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (length != 0) direction /= length;

        bullets.emplace_back(sprite.getPosition(), direction, true);
        ammo--;
    }
}

void Player::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
    for (auto& bullet : bullets) bullet.Draw(window);
}

void Player::ApplyPowerUp(std::string type, float value) {
    if (type == "speed") moveSpeed *= value;
    else if (type == "ammo") ammo += static_cast<int>(value);
}

sf::FloatRect Player::GetBounds() const {
    return sprite.getGlobalBounds();
}