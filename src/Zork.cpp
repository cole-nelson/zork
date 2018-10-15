#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../inc/rapidxml.hpp"
#include "../inc/GameObject.h"
#include "../inc/Zork.h"
#include "../inc/Room.h"
#include "../inc/Container.h"
#include "../inc/Creature.h"
#include "../inc/Item.h"

std::vector<std::string> _SplitString(const std::string& s, const std::string& c){

    std::vector<std::string> v;
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2){
        v.push_back(s.substr(pos1, pos2-pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length()) v.push_back(s.substr(pos1));

    return v;
}

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
    std::cout << "Welcome to Zork" << std::endl;
    // initialization
    Room* loc_now = dynamic_cast<Room*>(gameObjs["Entrance"]); //kinda ugly
    
    while(true){
        if(gameOver) break;
        string cmd, target;
        getline(cin, cmd);
        cout << cmd << endl;
        
        vector<string> cmd_ls = _SplitString(cmd, " ");
        if(cmd_ls.size() == 2){
            cmd = cmd_ls[0];
            target = cmd_ls[1];
        }
        
        if(cmd == "n"){
            loc_now = player.move(NORTH, loc_now, gameObjs);
        }
        else if(cmd == "s"){
            loc_now = player.move(SOUTH, loc_now, gameObjs);
        }
        else if(cmd == "w"){
            loc_now = player.move(WEST, loc_now, gameObjs);
        }
        else if(cmd == "e"){
            loc_now = player.move(EAST, loc_now, gameObjs);
        }
        else if(cmd == "i"){
        }
        else if(cmd == "take"){
        }
        else if(cmd == "open"){
        }
        else if(cmd == "read"){
        }
        else if(cmd == "drop"){
        }
        else if(cmd == "put"){
        }
        else if(cmd == "turn" && target == "on"){
        }
        else if(cmd == "attack"){
        }
        else{
            cout << "not recognized" << endl;
        }
    }
}
