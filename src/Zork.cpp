#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <string>

#include "../inc/util.h"
#include "../inc/Zork.h"
#include "../inc/Trigger.h"
#include "../inc/Creature.h"
#include "../inc/Item.h"

Zork::Zork(char *fname) : 
    gameOver(false), player(new Container()){
    originalObjs["inventory"] = player.inventory;
    player.inventory->setName("inventory");
	constructGame(fname);
}

Zork::~Zork() {
	for(auto obj:originalObjs) if(obj.second) delete obj.second;
}

Trigger * Zork::constructTrigger(rapidxml::xml_node<> *trig_node, GameObject *context, bool directAppend) {
	/**************************************************
	 * Search file for triggers, construct separately
	 * due to different handling
	 ***************************************************/
	Trigger *t = new Trigger();
    if(directAppend)context -> addTriggers(t);
	std::string has = "", owner, stat, object;
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
					stat = cAttr->value();
				}
			} // ********************END FOR**************************
            
            
            GameObject* targetObj = NULL;
			if(has == (std::string)"") {
                // object-status condition
                if(originalObjs.find(object) == originalObjs.end()){
                    //cerr << "object name: " << object << "cannot be found" << endl;
                    exit(1);
                }
                targetObj = originalObjs[object];
				t->setCondition(new StatCondition(targetObj, stat));
			} else {
                //cout << "search " << owner << " in " << context->getName() << endl;
                targetObj = originalObjs[owner];
                t->setCondition(new HasCondition(has == "yes", object, targetObj));
            }

		} else if(tAttr->name() == std::string ("action")) {
            vector<std::string> x = SplitString(tAttr->value(), " ");
            Action *a;
            if(x[0] == "Update") {
                assert(originalObjs[x[1]]);
                //cout << "update action " << context -> getName() << endl;
                a = new UpdateAction(originalObjs[x[1]], x[3]); //Update[0] <object>[1] to[2] <status>[3]
            } else if(x[0] == "Delete") {
                a = new DelAction(originalObjs[x[1]]->getBelongsTo(), x[1]); // Delete[0] <object>[1]
            } else if(x[0] == "Add") { 
                a = new AddAction(originalObjs[x[3]], originalObjs[x[1]]); // Add[0] <object>[1] to[2] <container>[3]
            } else {
                //cout << "regular action: " << tAttr->value() << endl;
                a = new RegularAction(tAttr->value(),this);
            }
            t->addAction(a);
        }  
	}
	return t;
}

void Zork::linkTriggers(rapidxml::xml_node<>* root){
    while(root != NULL) {
        string name;
        for(rapidxml::xml_node<> *attr = root->first_node(); 
                attr != NULL; attr = attr->next_sibling()) {
            
            string attrName(attr->name());
            string attrValue(attr->value());
            if(attrName == "name") {
                name = attrValue;
            }
            else if(attrName == "trigger") {
                GameObject* obj = originalObjs[name]; 
                constructTrigger(attr, obj, true);
            }
            else if(attrName == "attack") {
                Creature* obj = static_cast<Creature*>(originalObjs[name]);
                obj->setAttackTrigger(constructTrigger(attr, obj, false));
            }
            else if(attrName == "turnon") {
                Item* obj = static_cast<Item*>(originalObjs[name]);
                assert(obj);
                Trigger *t = constructTrigger(attr, obj, false);
                t->setCondition(new TrueCondition());
                t->setCommand("turn on");
                obj->setTrigger(t); 
            }

        }
        root = root->next_sibling();
    }
}
/*

void Zork::turnOnSetup(rapidxml::xml_node<> *aRoot, Item *context) {
	Trigger *t = constructTrigger(aRoot, context, false);
	t->setCondition(new TrueCondition());
    t->setCommand("turn on");
    context->setTrigger(t);
}

*/
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

    // spawn all items
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
                } else if(attrName == "item"){
                    assert(originalObjs[attrValue]);
                    new_container->addToCollection(originalObjs[attrValue],ITEM);
                    originalObjs[attrValue]->setBelongsTo(new_container);
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
                } else if(attrName == "description") {
                    new_room->setDescription(attrValue);
                } else if(attrName == "type") {
                    new_room->setType(attrValue);
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
                    new_room->addToCollection(originalObjs[attrValue], ITEM);
                    originalObjs[attrValue]->setBelongsTo(new_room);
                } else if(attrName == "container") {
                    new_room->addToCollection(originalObjs[attrValue], CONTAINER); 
                    originalObjs[attrValue]->setBelongsTo(new_room);
                } else if(attrName == "creature"){
                    new_room->addToCollection(originalObjs[attrValue], CREATURE);
                    originalObjs[attrValue]->setBelongsTo(new_room);
                }
            }
            originalObjs[new_room->getName()] = new_room;
        }
        root = root->next_sibling();
    }
    linkTriggers(doc.first_node()->first_node());
}

void Zork::execCmd(string cmd){
        string target1, target2;
        
        // check triggers in the current context
        if(loc_now -> checkAllTriggers(cmd)) return;
        if(player.inventory -> checkAllTriggers(cmd)) return;

        vector<string> cmd_ls = SplitString(cmd, " ");
        if(cmd_ls.size() == 2){// take <item> | drop <itemp> | 
                               // read <item> | turn on
            cmd = cmd_ls[0];
            target1 = cmd_ls[1];
        }

        if(cmd_ls.size() == 3) {
        	cmd = cmd_ls[0];
        	target1 = cmd_ls[1];
        	target2 = cmd_ls[2];
        }

        if(cmd_ls.size() == 4) // put <item> in <container>
        {
            cmd = cmd_ls[0];
            target1 = cmd_ls[1];
            target2 = cmd_ls[3];
        }
        
        if(cmd == "n")loc_now = player.move(NORTH, loc_now, Rooms);
        else if(cmd == "s")loc_now = player.move(SOUTH, loc_now, Rooms);
        else if(cmd == "w")loc_now = player.move(WEST, loc_now, Rooms);
        else if(cmd == "e")loc_now = player.move(EAST, loc_now, Rooms);
        else if(cmd == "i")     player.openInventory();
        else if(cmd == "take")  player.takeItem(target1, loc_now);
        else if(cmd == "read")  player.readItem(target1);  
        else if(cmd == "drop")  player.dropItem(target1, loc_now);
        else if(cmd == "open" && target1 == "exit"){
            if(loc_now->isExit()) GameOver();
            else cout << "this room is not the exit" << endl;
        }
        else if(cmd == "open"){
            Container* cont = static_cast<Container*>(loc_now->searchCollection(target1, CONTAINER));
            if(!cont) cout << "container " << target1 << " does not exist" << endl;
            else cont->open();
        }
        else if(cmd == "put" && cmd_ls[2] == "in"){
            GameObject* retCont = loc_now->searchCollection(target2, CONTAINER);
            GameObject* retItem = player.inventory->searchCollection(target1, ITEM);
            if(!retCont) cout << "there is no " << target1 << " in this room..." << endl;
            else if (!retItem) cout << "you do not have " << target2 << " in your inventory..." << endl;
            else{
                player.inventory->deleteFromCollection(target1, ITEM);
                retCont->addToCollection(originalObjs[target1], ITEM);
            }
        }
        else if(cmd == "turn" && target1 == "on"){
        	Item *ret = static_cast<Item*>(player.inventory->searchCollection(target2, ITEM));
        	if(ret)ret->turnOn();
            else cout << "you do not have " << target2 << " in your inventory..." << endl;
        }
        else if(cmd == "attack" && cmd_ls[2] == "with"){
            Creature *retCreature = static_cast<Creature*>(loc_now->searchCollection(target1, CREATURE));
            Item *retItem = static_cast<Item*>(player.inventory->searchCollection(target2, ITEM));
            if(retCreature == NULL) cout << "there is no creature " << target1 << " in this room..." << endl;
            else if(retItem == NULL) cout << "you do not have " << target2 << " in your inventory..." << endl;
            else {
                retCreature->attack(target2);
                //player.inventory->deleteFromCollection(target2, ITEM);
            }
        }
        else{
            cout << "error" << endl;
        }

        if(loc_now -> checkAllTriggers("")) return;
        if(player.inventory -> checkAllTriggers("")) return;

}

void Zork::playGame() {
    cout << "Welcome to Zork" << endl << endl;
    // initialization
    loc_now = entrance;
    cout << loc_now->getDescription() << endl;
    while(!gameOver){
        cout << endl << '>';
        string cmd;
        getline(cin, cmd);
        execCmd(cmd);

    }

    cout << "Victory!" << endl;
}
