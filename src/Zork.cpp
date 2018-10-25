#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../inc/util.h"
#include "../inc/Trigger.h"
#include "../inc/rapidxml.hpp"
#include "../inc/GameObject.h"
#include "../inc/Zork.h"
#include "../inc/Room.h"
#include "../inc/Container.h"
#include "../inc/Creature.h"
#include "../inc/Item.h"

Zork::Zork(char *fname) : gameOver(false) {
	constructGame(fname);
}

Zork::~Zork() {
	for(auto obj:originalObjs) delete obj.second;
    for(auto room:Rooms)       delete room.second;
    for(auto obj:gameObjs)     delete obj;
    for(auto tri:triggerPool)  delete tri;
}

Trigger * Zork::constructTrigger(rapidxml::xml_node<> *trig_node, GameObject *context) {
	/**************************************************
	 * Search file for triggers, construct separately
	 * due to different handling
	 ***************************************************/
	Trigger *t = new Trigger(context);
	std::string has = "", owner, status, object;
	for(rapidxml::xml_node<> *tAttr = trig_node->first_node();
			tAttr != NULL; tAttr = tAttr->next_sibling()) {

		if(tAttr->name() == (std::string)"type") {
			t->setType(tAttr->value());
		} else if(tAttr->name() == (std::string)"command") {
			t->setCommand(tAttr->value());
		} else if(tAttr->name() == (std::string)"print") {
			t->setPrint(tAttr->value());
		} else if(tAttr->name() == (std::string)"condition") {
			for(rapidxml::xml_node<> *cAttr = tAttr->first_node();
					cAttr != NULL; cAttr = cAttr->next_sibling()) {
				if(cAttr->name() == (std::string)"has") {
					has = cAttr->value();
				} else if(cAttr->name() == (std::string)"owner") {
					owner = cAttr->value();
				} else if(cAttr->name() == (std::string)"object") {
					object = cAttr->value();
				} else if(cAttr->name() == (std::string)"status") {
					status = cAttr->value();
				}
			} // ********************END FOR**************************

			if(has == (std::string)"") {
				// object-status condition
				t->setCondition(new StatCondition(context, status));
			} else {
				t->setCondition(new HasCondition(context, has == (std::string)"yes", object, owner));
			}

		}//****************END CONDITION CONSTRUCTION*****************
	}

	return t;
}

void Zork::constructGame(const char *fname) {

    // Open XML file
    std::ifstream fp = std::ifstream(fname);
    if(!fp) {
        throw "File could not be opened.";
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
        if(root->name() == (string)"item"){
            Item* new_Item = new Item();
            for(rapidxml::xml_node<> *attr = root->first_node(); 
                    attr != NULL; attr = attr->next_sibling()) {

                string attrName(attr->name());
                string attrValue(attr->value());
                if(attrName == "name") {
                    new_Item->setName(attrValue);
                } else if(attrName == "status") {
                    new_Item->setStatus(attrValue);
                } else if(attrName == "description") {
                    new_Item->setDescription(attrValue);
                } else if(attrName == "writing") {
                    new_Item->setWriting(attrValue);
                } else if(attrName == "turn on") {
                    // do something
                }
            }
            originalObjs[new_Item->getName()] = new_Item; 
        }
        root = root->next_sibling();
    }

    // spawn all base containers
    root = doc.first_node()->first_node();
    while(root != NULL) {

        //unordered_set<string>* accept = new unordered_set<string>;
        if(root->name() == (string)"container"){
            Container* new_container = new Container();
            for(rapidxml::xml_node<> *attr = root->first_node(); 
                    attr != NULL; attr = attr->next_sibling()) {


                string attrName(attr->name());
                string attrValue(attr->value());
                if(attrName == "name") {
                    new_container->setName(attrValue);
                } else if(attrName == "status") {
                    new_container->setStatus(attrValue);
                } else if(attrName == "description") {
                    new_container->setDescription(attrValue);
                } else if(attrName ==  "accept") {
                    new_container->addAccept(attrValue);
                } else if(attrName == "trigger") {
                	//triggerPool.push_back(constructTrigger(attr, new_container));
                }
            }
            //spawn a new container
            originalObjs[new_container->getName()] = new_container;
        }
        root = root->next_sibling();
    }

    // spawn all base creature
    root = doc.first_node()->first_node();
    while(root != NULL) {

        if(root->name() == (string)"creature"){
            Creature* new_creature = new Creature();
            for(rapidxml::xml_node<> *attr = root->first_node(); 
                    attr != NULL; attr = attr->next_sibling()) {

                string attrName(attr->name());
                string attrValue(attr->value());
                if(attrName == "name") {
                    new_creature->setName(attrValue);
                } else if(attrName == "status") {
                    new_creature->setStatus(attrValue);
                } else if(attrName == "description") {
                    new_creature->setDescription(attrValue);
                } else if(attrName == "vulnerability") {
                    new_creature->addVulnerability(attrValue);
                } else if(attrName ==  "attack") {
                    // do something
                } else if(attrName == "trigger") {
                    //triggerPool.push_back(constructTrigger(attr, new_creature));
                }
            }
            //spwan a new creature
            originalObjs[new_creature->getName()] = new_creature;
        }
        root = root->next_sibling();
    }

    // spwan all room
    root = doc.first_node()->first_node();
    while(root != NULL){
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
                } else if(attrName == "type") {
                    new_room->setType(attrValue);
                } else if(attrName == "description") {
                    new_room->setDescription(attrValue);
                } else if(attrName == "trigger") {
                    //triggerPool.push_back(constructTrigger(attr, new_room));
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
                } else if(attrName == "item") {
                    new_room->addItem(dynamic_cast<Item*>(originalObjs[attrValue]));
                }
            }
        }
        root = root->next_sibling();
    }

}

void Zork::playGame() {
    cout << "Welcome to Zork" << endl << endl;
    // initialization
    Room* loc_now = entrance;
    cout << loc_now->getDescription() << endl;
    while(!gameOver){
        string cmd, target1, target2;
        cout << '>';
        getline(cin, cmd);
        
        // checkTtrigger();
        for(auto triggerPtr : triggerPool){
           if(triggerPtr->checkCond()){
               triggerPtr->fire(cmd);
           }
        }
        
        vector<string> cmd_ls = SplitString(cmd, " ");
        if(cmd_ls.size() == 2){// take <item> | drop <itemp> | 
                               // read <item> | turn on
            cmd = cmd_ls[0];
            target1 = cmd_ls[1];
        }

        if(cmd_ls.size() == 4) // put <item> in <container>
        {
            cmd = cmd_ls[0];
            target1 = cmd_ls[1];
            target2 = cmd_ls[3];
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
            Item* targetItem = loc_now->delItem(target1);

            if(!targetItem) continue;
            player.addItem(targetItem);
            //delete targetItem;
        }
        else if(cmd == "open"){
            if(target1 == "exit"){
                if(loc_now->isExit()) {
                	gameOver = true;
                }
            }
        }
        else if(cmd == "read"){
            player.readItem(target1);  
        }
        else if(cmd == "drop"){
            Item* targetItem = player.delItem(target1);

            if(!targetItem) continue;
            loc_now->addItem(targetItem);
            delete targetItem;
        }
        else if(cmd == "put" && cmd_ls[3] == "in"){
        }
        else if(cmd == "turn" && target1 == "on"){
        }
        else if(cmd == "attack" && cmd_ls[3] == "with"){
        }
        else{
            cout << "error" << endl;
        }
    }

    cout << "Victory!" << endl;
}
