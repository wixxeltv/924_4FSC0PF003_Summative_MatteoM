﻿//
// Created by sebas on 07/07/2025.
//

#include "game_sprite.h"

#include "../asset_manager/assets.h"

#include <SFML/Graphics.hpp>
#include <random>

GameSprite::GameSprite(const sf::Vector2f pos)
    : position_(pos), alpha_(255.0f), is_active_(true) {

    gen_ = std::mt19937(rd_());
    color_dist_ = std::uniform_int_distribution<>(0, 255);
    texture_idx_dist_ = std::uniform_int_distribution<>(0, 35);
    fade_dist_ = std::uniform_real_distribution<float>(30.0, 80.0);
    scale_dist_ = std::uniform_real_distribution<float>(0.75, 1.5);

    // Couleur aléatoire
    base_color_ = sf::Color(
        color_dist_(gen_),
        color_dist_(gen_),
        color_dist_(gen_),
        255
    );

    // Vitesse de disparition aléatoire
    fade_speed_ = fade_dist_(gen_); // Entre 30 et 80
    // Scale alèatoire
    scale_ = scale_dist_(gen_);
    // Texture alèatoire
    texture_idx_ = texture_idx_dist_(gen_);

}

void GameSprite::Update(const float deltaTime) {
    if (!is_active_) return;

    // Réduction progressive de la transparence
    alpha_ -= fade_speed_ * deltaTime;
    if (alpha_ <= 0.0f) {
        alpha_ = 0.0f;
        is_active_ = false;
    }

    // Mise à jour de la couleur avec la nouvelle transparence
    current_color_ = base_color_;
    current_color_.a = static_cast<uint8_t>(alpha_);

}

void GameSprite::Draw(sf::RenderWindow& window) {
    if (!is_active_) return;

    const sf::Texture texture(assets::textureManager.Get(std::format("splat{:02d}", texture_idx_)));

    sf::Sprite sprite(texture);
    sprite.setOrigin({static_cast<float>(texture.getSize().x) / 2.0f, static_cast<float>(texture.getSize().y) / 2.0f});
    sprite.setColor(current_color_);
    sprite.setScale({scale_, scale_});
    sprite.setPosition(position_);
    window.draw(sprite);

}

bool GameSprite::is_active() const {
    return is_active_;
}
sf::Vector2f GameSprite::position() const {
    return position_;
}
float GameSprite::alpha() const {
    return alpha_;
}

