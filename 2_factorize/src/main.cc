#include <iostream>
#include "game.h"

// Fonction principale
int main() {

    try {
        Game game;
        game.Run();

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
