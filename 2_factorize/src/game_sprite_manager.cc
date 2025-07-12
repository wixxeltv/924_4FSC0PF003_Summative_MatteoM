//
// Created by sebas on 07/07/2025.
//

#include "game_sprite_manager.h"

#include <iostream>
#include <random>

GameSpriteManager::GameSpriteManager(const sf::Vector2u winSize)
    : window_size_(winSize) {
    gen_ = std::mt19937(rd_());
    type_dist_ = std::uniform_int_distribution<>(0, 2);
    pos_dist_ = std::uniform_real_distribution<float>(0.0, 1.0);
}


void GameSpriteManager::AddRandomSprite() {
    AddSprite({
            pos_dist_(gen_) * static_cast<float>(window_size_.x - 100) + 50,
            pos_dist_(gen_) * static_cast<float>(window_size_.y - 100) + 50
        });
}

void GameSpriteManager::AddSpriteAtMouse(sf::Vector2f mousePos) {
    AddSprite(mousePos);
}

void GameSpriteManager::AddSprite(sf::Vector2f position) {
    sprites_.push_back(std::make_unique<GameSprite>(position));
}

void GameSpriteManager::Update(float deltaTime) {
    // Mise à jour de tous les sprites
    for (auto& sprite : sprites_) {
        sprite->Update(deltaTime);
    }

    // Suppression des sprites inactifs
    sprites_.erase(
        std::remove_if(sprites_.begin(), sprites_.end(),
            [](const std::unique_ptr<GameSprite>& sprite) {
                return !sprite->is_active();
            }),
        sprites_.end()
    );
}

void GameSpriteManager::Draw(sf::RenderWindow& window) const{
    for (auto& sprite : sprites_) {
        sprite->Draw(window);
    }
}

size_t GameSpriteManager::GetActiveSpritesCount() const {
    return sprites_.size();
}

void GameSpriteManager::ClearAllSprites() {
    sprites_.clear();
}


