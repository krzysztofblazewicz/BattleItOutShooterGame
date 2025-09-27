#include "GameManager.h"

GameManager& GameManager::GetInstance() {
    static GameManager instance;
    return instance;
}

GameManager::GameManager() :
    window(sf::VideoMode(800, 600), "SFML Shooter"),
    tilemap(),
    collisionManager(),
    uiManager(),
    audioManager() {

    window.setVerticalSyncEnabled(true);

    // initialize game state
    if (tilemap.LoadFromFile("resources/maps/level1.map")) {
        enemies.emplace_back(sf::Vector2f(100, 100));
        enemies.emplace_back(sf::Vector2f(700, 500));
    }
}

void GameManager::Run() {
    sf::Clock clock;
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        ProcessInput();
        Update(deltaTime);
        Render();
    }
}

void GameManager::ProcessInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void GameManager::Update(float deltaTime) {
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    // update player
    player.Update(deltaTime, mousePos);

    // update enemies
    for (auto& enemy : enemies) {
        enemy.Update(deltaTime, player.GetPosition());
    }

    // check collisions
    collisionManager.CheckCollisions(player, enemies);

    // update UI
    uiManager.Update(player.GetHealth(), player.GetAmmo());
}

void GameManager::Render() {
    window.clear();

    // draw game world
    tilemap.Draw(window);
    player.Draw(window);
    for (auto& enemy : enemies) enemy.Draw(window);

    // draw UI
    uiManager.Draw(window);

    window.display();
}