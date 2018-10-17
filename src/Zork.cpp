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

vector<string> _SplitString(const string& s, const string& c){

    vector<string> v;
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(string::npos != pos2){
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
    rapidxml::xml_node<> *root;


    // Iterate, spawn items, add to Zork table

    // spawn all base items
    root = doc.first_node()->first_node();
    while(root != NULL) {

        string name="", stat="", description="", writing="", type="";
        if(root->name() == (string)"item"){
            for(rapidxml::xml_node<> *attr = root->first_node(); 
                    attr != NULL; attr = attr->next_sibling()) {

                if(attr->name() == (string)"name") {
                    name = attr->value();
                } else if(attr->name() == (string)"status") {
                    stat = attr->value();
                } else if(attr->name() == (string)"description") {
                    description = attr->value();
                } else if(attr->name() == (string)"writing") {
                    writing = attr->value();
                } else if(attr->name() == (string)"turn on") {
                    // do something
                }
                originalObjs[name] = new Item(name,stat,description,writing); 
            }
        }
        root = root->next_sibling();
    }

    // spawn all base containers
    root = doc.first_node()->first_node();
    while(root != NULL) {

        string name="", stat="", description="", writing="", type="";
        unordered_set<string>* accept = new unordered_set<string>;
        if(root->name() == (string)"container"){
            for(rapidxml::xml_node<> *attr = root->first_node(); 
                    attr != NULL; attr = attr->next_sibling()) {

                if(attr->name() == (string)"name") {
                    name = attr->value();
                } else if(attr->name() == (string)"status") {
                    stat = attr->value();
                } else if(attr->name() == (string)"description") {
                    description = attr->value();
                } else if(attr->name() == (string) "accept") {
                    accept->insert(attr->value());
                } else if(attr->name() == (string)"trigger") {
                    // do something
                }
                //spwan a new container
                //originalObjs[name] = new Container(); 
            }
        }
        root = root->next_sibling();
    }

    // spawn all base creature
    root = doc.first_node()->first_node();
    while(root != NULL) {

        string name="", stat="", description="", writing="", type="";
        unordered_set<string>* vulnerabilities = new unordered_set<string>;
        if(root->name() == (string)"creature"){
            for(rapidxml::xml_node<> *attr = root->first_node(); 
                    attr != NULL; attr = attr->next_sibling()) {

                if(attr->name() == (string)"name") {
                    name = attr->value();
                } else if(attr->name() == (string)"status") {
                    stat = attr->value();
                } else if(attr->name() == (string)"description") {
                    description = attr->value();
                } else if(attr->name() == (string)"vulnerability") {
                    vulnerabilities->insert(attr->value());
                } else if(attr->name() == (string) "attack") {
                    // do something
                } else if(attr->name() == (string)"trigger") {
                    // do something
                }
                //spwan a new creature
                //originalObjs[name] = new Creature(); 
            }
        }
        root = root->next_sibling();
    }

    // spwan all room
    root = doc.first_node()->first_node();
    while(root != NULL){
        unordered_map<string, string> borders;
        if(root->name() == (string)"room"){
            Room* new_room = new Room();   
            for(rapidxml::xml_node<> *attr = root->first_node(); 
                    attr != NULL; attr = attr->next_sibling()) {
                string attrName(attr->name());
                string attrValue(attr->value());
                if(attrName == "name") {
                    new_room->setName(attrValue);
                    Rooms[attrValue] = new_room;
                    if(attrValue == "Entrance") entrance = new_room;
                } else if(attrName == "status") {
                    new_room->setStatus(attrValue);
                } else if(attrName == "description") {
                    new_room->setDescription(attrValue);
                } else if(attrName == "trigger") {
                    // do something
                } else if(attrName == "border"){
                    string dir, dir_name = "NULL";
                    for(rapidxml::xml_node<> *node = attr->first_node();
                            node != NULL; node = node->next_sibling()) {
                        string nodeName(node->name());
                        string nodeValue(node->value());
                        if(nodeName == "direction")dir = nodeValue;
                        else if(nodeName == "name")dir_name = nodeValue;
                    }
                    new_room->setNeighbor(dir,dir_name);
                } else if(attr->name() == (string)"item") {
                    new_room->addItem(*dynamic_cast<Item*>(originalObjs[attr->value()]));
                }
                if(borders.find("north") == borders.end()) borders["north"] = "NULL";
                if(borders.find("south") == borders.end()) borders["south"] = "NULL";
                if(borders.find("east") == borders.end()) borders["east"] = "NULL";
                if(borders.find("west") == borders.end()) borders["west"] = "NULL";
            }
        }
        root = root->next_sibling();
    }

}

void Zork::playGame() {
    std::cout << "Welcome to Zork" << std::endl;
    // initialization
    Room* loc_now = entrance;
    cout << loc_now->getDescription() << endl;
    while(true){
        if(gameOver) break;
        string cmd, target;
        cout << '>';
        getline(cin, cmd);
        
        vector<string> cmd_ls = _SplitString(cmd, " ");
        if(cmd_ls.size() == 2){
            cmd = cmd_ls[0];
            target = cmd_ls[1];
        }
        
        if(cmd == "n"){
            loc_now = player.move(NORTH, loc_now, Rooms);
        }
        else if(cmd == "s"){
            loc_now = player.move(SOUTH, loc_now, Rooms);
        }
        else if(cmd == "w"){
            loc_now = player.move(WEST, loc_now, Rooms);
        }
        else if(cmd == "e"){
            loc_now = player.move(EAST, loc_now, Rooms);
        }
        else if(cmd == "i"){
            player.openInventory();
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
            cout << "error" << endl;
        }
    }
}
