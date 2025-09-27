#include "CollisionManager.h"
#include "AudioManager.h"

void CollisionManager::CheckCollisions(Player& player,
    std::vector<Enemy>& enemies,
    std::vector<Bullet>& bullets,
    const Map& map) {
    PlayerEnemyCollisions(player, enemies);
    BulletCollisions(bullets, enemies, player);
    MapCollisions(player, map);
}

void CollisionManager::PlayerEnemyCollisions(Player& player, std::vector<Enemy>& enemies) {
    sf::FloatRect playerBounds = player.GetBounds();

    for (auto& enemy : enemies) {
        if (playerBounds.intersects(enemy.GetBounds())) {
            player.TakeDamage(10);
            AudioManager::GetInstance().PlayHitSound();
        }
    }
}

void CollisionManager::BulletCollisions(std::vector<Bullet>& bullets,
    std::vector<Enemy>& enemies,
    Player& player) {
    for (auto bullet = bullets.begin(); bullet != bullets.end();) {
        bool bulletRemoved = false;

        // Check enemy collisions
        for (auto enemy = enemies.begin(); enemy != enemies.end();) {
            if (bullet->GetBounds().intersects(enemy->GetBounds())) {
                if (bullet->IsPlayerBullet()) {
                    enemy = enemies.erase(enemy);
                    bullet = bullets.erase(bullet);
                    bulletRemoved = true;
                    break;
                }
            }
            ++enemy;
        }

        if (bulletRemoved) continue;

        // Check player collision
        if (!bullet->IsPlayerBullet() &&
            bullet->GetBounds().intersects(player.GetBounds())) {
            player.TakeDamage(20);
            bullet = bullets.erase(bullet);
            AudioManager::GetInstance().PlayHitSound();
            continue;
        }

        ++bullet;
    }
}

void CollisionManager::MapCollisions(Player& player, const Map& map) {
    // Implement tile-based collision using Map::GetBinning()
    // ...
}