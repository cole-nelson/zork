#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../inc/rapidxml.hpp"
#include "../inc/GameObject.h"
#include "../inc/Zork.h"

Zork::Zork() : gameOver(false) {}

Zork::~Zork() {}

void Zork::constructGame(const char *fname) {

	// Open XML file
	std::ifstream fp = std::ifstream(fname);
	if(!fp) {
		throw "File could not be opened";
	}

	std::stringstream ss;
	ss << fp.rdbuf();
	std::string xml = ss.str();
	fp.close();

	// Setup xml parser
	rapidxml::xml_document<> doc;
	doc.parse<0>(&xml[0]);
	rapidxml::xml_node<> *root = doc.first_node()->first_node();


	// Iterate, spawn items, add to Zork table
	std::cout << root->name() << std::endl;
	while(root != doc.last_node()) {
		if(root->name() == "item") {
			gameObjs[] = Item();
		}
		root = root->next_sibling();
	}

}

void Zork::playGame() {
	while(!gameOver) {
		std::cout << "お前はもう死んでいる" << std::endl;
	}
}
