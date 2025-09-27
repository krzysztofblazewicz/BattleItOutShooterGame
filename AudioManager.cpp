#include "AudioManager.h"

AudioManager& AudioManager::GetInstance() {
    static AudioManager instance;
    return instance;
}

AudioManager::AudioManager() {
    // load sound buffers
    shootBuffer.loadFromFile("resources/audio/shoot.wav");
    hitBuffer.loadFromFile("resources/audio/hit.wav");
    powerUpBuffer.loadFromFile("resources/audio/powerup.wav");

    // assign buffers to sounds
    shootSound.setBuffer(shootBuffer);
    hitSound.setBuffer(hitBuffer);
    powerUpSound.setBuffer(powerUpBuffer);

    // configure background music
    backgroundMusic.openFromFile("resources/audio/background.ogg");
    backgroundMusic.setLoop(true);
    backgroundMusic.setVolume(50);
}

void AudioManager::PlayShootSound() {
    shootSound.play();
}

void AudioManager::PlayHitSound() {
    hitSound.play();
}

void AudioManager::PlayPowerUpSound() {
    powerUpSound.play();
}

void AudioManager::PlayBackgroundMusic() {
    backgroundMusic.play();
}