#include "UIManager.h"

UIManager::UIManager() {
    if (!gameFont.loadFromFile("resources/fonts/arial.ttf")) {
        // handle error
    }

    InitializeText(healthText, 20.0f, 20.0f);
    InitializeText(ammoText, 20.0f, 60.0f);
    InitializeText(scoreText, 20.0f, 100.0f);
}

void UIManager::InitializeText(sf::Text& text, float posX, float posY) {
    text.setFont(gameFont);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(posX, posY);
}

void UIManager::Update(int health, int ammo, int score) {
    healthText.setString("Health: " + std::to_string(health));
    ammoText.setString("Ammo: " + std::to_string(ammo));
    scoreText.setString("Score: " + std::to_string(score));
}

void UIManager::Draw(sf::RenderWindow& window) {
    window.draw(healthText);
    window.draw(ammoText);
    window.draw(scoreText);
}