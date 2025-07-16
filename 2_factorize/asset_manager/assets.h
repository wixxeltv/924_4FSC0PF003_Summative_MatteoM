//
// Created by WIXXEL on 16.07.2025.
//

#ifndef ASSETS_H
#define ASSETS_H
#include "asset_manager.h"
#include <SFML/Graphics/Texture.hpp>
namespace assets {
inline manager::AssetManager<sf::Texture> textureManager;
inline manager::AssetManager<sf::Font> fontManager;
}
#endif //ASSETS_H
