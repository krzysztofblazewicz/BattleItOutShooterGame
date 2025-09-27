#include "GameManager.h"

int main() {
    GameManager& game = GameManager::GetInstance();
    game.Run();
    return 0;
}