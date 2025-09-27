#pragma once
#include <SFML/Graphics.hpp>

/**
 * @class UIManager
 * @brief Handles HUD display using Observer pattern
 */

class UIManager {
public:
    UIManager();
    void Update(int health, int ammo, int score);
    void Draw(sf::RenderWindow& window);

private:
    sf::Font gameFont;
    sf::Text healthText;
    sf::Text ammoText;
    sf::Text scoreText;

    void InitializeText(sf::Text& text, float posX, float posY);
};