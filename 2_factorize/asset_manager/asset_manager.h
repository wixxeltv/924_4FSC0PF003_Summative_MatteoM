//
// Created by WIXXEL on 16.07.2025.
//

#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <iostream>
#include <SFML/Graphics.hpp>

namespace manager {

template<typename TAsset>
class AssetManager {
public:
    void LoadAllFromFolder(const std::string& folderPath);
    const TAsset& Get(const std::string& id) const;

private:
    std::hash<std::string> hasher_;
    std::unordered_map<size_t, TAsset> assets_;
    TAsset errorAsset;
};

template<typename TAsset>
void AssetManager<TAsset>::LoadAllFromFolder(const std::string& folderPath) {

  if (!std::filesystem::exists(folderPath)) {
    std::cerr << "Folder not found: " << folderPath << "\n";
    return;
  }

  for (const auto& entry : std::filesystem::directory_iterator(folderPath)) {
    if (entry.is_regular_file()) {
      std::string path = entry.path().string();
      std::string filename = entry.path().stem().string();

      TAsset asset;
      if constexpr (std::is_same_v<TAsset, sf::Font>) {
        if (asset.openFromFile(path)) {
          assets_[hasher_(filename)] = std::move(asset);
        } else {
          std::cerr << "Failed to open font: " << path << "\n";
        }
      } else {
        if (asset.loadFromFile(path)) {
          assets_[hasher_(filename)] = std::move(asset);
        } else {
          std::cerr << "Failed to load: " << path << "\n";
        }
      }
    }
  }
}
template<typename TAsset>
const TAsset& AssetManager<TAsset>::Get(const std::string& id) const {
    auto it = assets_.find(hasher_(id));
    if (it != assets_.end()) {
        return it->second;
    }
    std::cerr << "Asset not found: " << id << ".\n";
    return errorAsset;
}

}

#endif // ASSET_MANAGER_H
