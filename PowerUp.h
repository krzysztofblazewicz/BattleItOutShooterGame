#pragma once
#include <SFML/Graphics.hpp>

/**
 * @class PowerUp
 * @brief Manages power-up items using Factory pattern
 */

class PowerUp {
public:
    enum class Type { Health, Ammo, Speed };

    PowerUp(Type type, sf::Vector2f position);
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    sf::FloatRect GetBounds() const;

    Type GetType() const;

private:
    Type powerType;
    sf::Sprite sprite;
    sf::Texture texture;
};