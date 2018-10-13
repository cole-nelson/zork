#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../inc/rapidxml.hpp"
#include "../inc/GameObject.h"
#include "../inc/Zork.h"
#include "../inc/Item.h"

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
	while(root != NULL) {
		rapidxml::xml_node<> *attr;

		std::string name, status, description, writing;
		for(attr = root->first_node(); attr != NULL; attr = attr->next_sibling()) {
			if(attr->name() == (std::string)"name") {
				name = attr->value();
			} else if(attr->name() == (std::string)"status") {
				status = attr->value();
			} else if(attr->name() == (std::string)"description") {
				description = attr->value();
			} else {
				if(root->name() == (std::string)"item") {
					if(attr->name() == (std::string)"writing") {
						writing = attr->value();
					}
				}
			}
		}
		if(root->name() == (std::string)"item") {
			gameObjs[name] = new Item(name, status, description, writing);
		}
		root = root->next_sibling();
	}

}

void Zork::playGame() {

}
