#pragma once
#include <SFML/Audio.hpp>

/**
 * @class AudioManager
 * @brief Handles all audio operations using Singleton pattern
 *
 * Manages sound effects and background music
 */

class AudioManager {
public:
    static AudioManager& GetInstance();

    void PlayShootSound();
    void PlayHitSound();
    void PlayPowerUpSound();
    void PlayBackgroundMusic();

private:
    AudioManager();  // private constructor for Singleton

    // sound buffers
    sf::SoundBuffer shootBuffer;
    sf::SoundBuffer hitBuffer;
    sf::SoundBuffer powerUpBuffer;

    // sound objects
    sf::Sound shootSound;
    sf::Sound hitSound;
    sf::Sound powerUpSound;

    // music
    sf::Music backgroundMusic;
};