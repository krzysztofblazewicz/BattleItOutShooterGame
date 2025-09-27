#include "PowerUp.h"

PowerUp::PowerUp(Type type, sf::Vector2f position) : powerType(type) {
    switch (type) {
    case Type::Health:
        texture.loadFromFile("resources/textures/health_pu.png");
        break;
    case Type::Ammo:
        texture.loadFromFile("resources/textures/ammo_pu.png");
        break;
    case Type::Speed:
        texture.loadFromFile("resources/textures/speed_pu.png");
        break;
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void PowerUp::Update(float deltaTime) {
    // animation logic here
}

void PowerUp::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect PowerUp::GetBounds() const {
    return sprite.getGlobalBounds();
}

PowerUp::Type PowerUp::GetType() const {
    return powerType;
}