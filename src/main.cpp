#include <iostream>
#include <unordered_map>

#include "../inc/GameObject.h"
#include "../inc/Zork.h"

int main() {
    Zork zork = Zork();
    try {
        zork.constructGame("test.xml");
    } catch(const char *err) {
        std::cout << err;
    }

    zork.playGame();

    return 0;
}
