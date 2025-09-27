#include "Bullet.h"

Bullet::Bullet(sf::Vector2f startPos, sf::Vector2f direction, bool isPlayerBullet) :
    direction(direction),
    speed(600.0f),
    playerBullet(isPlayerBullet) {

    if (texture.loadFromFile("resources/textures/bullet.png")) {
        sprite.setTexture(texture);
        sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
        sprite.setPosition(startPos);
    }
    lifetimeClock.restart();
}

void Bullet::Update(float deltaTime) {
    sprite.move(direction * speed * deltaTime);
}

void Bullet::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

bool Bullet::IsExpired() const {
    return lifetimeClock.getElapsedTime().asSeconds() > 2.0f;
}

sf::FloatRect Bullet::GetBounds() const {
    return sprite.getGlobalBounds();
}

bool Bullet::IsPlayerBullet() const {
    return playerBullet;
}