#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Tilemap.h"
#include "CollisionManager.h"
#include "UIManager.h"
#include "AudioManager.h"

/**
 * @class GameManager
 * @brief Main game controller using Singleton pattern
 *
 * Manages game loop and subsystem coordination
 */

class GameManager {
public:
    static GameManager& GetInstance();
    void Run();

private:
    GameManager();
    void ProcessInput();
    void Update(float deltaTime);
    void Render();

    sf::RenderWindow window;
    Player player;
    std::vector<Enemy> enemies;
    Tilemap tilemap;
    CollisionManager collisionManager;
    UIManager uiManager;
    AudioManager audioManager;
    sf::Clock gameClock;
};