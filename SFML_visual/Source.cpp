#include "Window.h"

int main() {
    sf::Music music;
    if (!music.openFromFile("chiptronical.ogg"))
    {
        std::cout << "Music failed to load!" << '\n';
    }
    music.play();
    Window game(800, "SFML Snake");
    game.openWindow();
    return 0;
}
