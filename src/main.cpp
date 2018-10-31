#include <iostream>
#include <unordered_map>

#include "../inc/Trigger.h"
#include "../inc/GameObject.h"
#include "../inc/Zork.h"

int main(int argc, char **argv) {

	if(argc < 2) {
		std::cerr << "Usage: ./zork <xml file>" << std::endl;
		return EXIT_FAILURE;
	}

	Zork *zork;

	try {
		zork = new Zork(argv[1]);
	} catch(const char *e) {
		std::cout << e << std::endl;
		return EXIT_FAILURE;
	}
    zork->playGame();

    /*
	Zork zork = Zork((char *)"test.xml");
	zork.playGame();
    */

    return 0;
}
