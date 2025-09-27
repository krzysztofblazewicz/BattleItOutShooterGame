#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "tilemap.h"  

/**
 * @class CollisionManager
 * @brief Handles all collision detection using Strategy pattern
 */

class CollisionManager {
public:
    static void CheckCollisions(Player& player,
        std::vector<Enemy>& enemies,
        std::vector<Bullet>& bullets,
        const Map& map);

private:
    static void PlayerEnemyCollisions(Player& player, std::vector<Enemy>& enemies);
    static void BulletCollisions(std::vector<Bullet>& bullets,
        std::vector<Enemy>& enemies,
        Player& player);
    static void MapCollisions(Player& player, const Map& map);
};