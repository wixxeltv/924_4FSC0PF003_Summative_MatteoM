#include "../asset_manager/assets.h"
#include "game.h"
#include <iostream>

// Fonction principale
int main() {
    assets::textureManager.LoadAllFromFolder("_assets/splats");
    assets::fontManager.LoadAllFromFolder("_assets/fonts");
    try {
        Game game;
        game.Run();

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
