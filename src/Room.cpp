#include <string>
#include <iostream>
#include "../inc/Room.h"

Room::Room():
    type("regular"),
    north("NULL"),south("NULL"),east("NULL"),west("NULL"){}

Room::~Room(){}

void Room::setNeighbor(string dir, string roomName){
    if(dir == "north")      north = roomName;
    else if(dir == "south") south = roomName;
    else if(dir == "east")  east = roomName;
    else                    west = roomName;
}

string Room::getNeighbor(Direction dir){
    if(dir == NORTH)        return north;
    else if(dir == SOUTH)   return south;
    else if(dir == EAST)    return east;
    else                    return west;
}

void Room::addItem(Item *item){
    inventory.push_back(item);
}

void Room::addContainer(Container *container){
    containers.push_back(container);
}

void Room::addCreature(Creature *creature){
    creatures.push_back(creature); 
}

Item* Room::delItem(string name){
    for(auto it = inventory.begin(); it != inventory.end(); it++){
        if((*it)->getName() == name){
            Item* ret = new Item((**it));
            inventory.erase(it);
            return ret; 
        }
    }
    cout << "item does not exist" << endl;
    return NULL;
}

Container* Room::delContainer(string name){
    return NULL;
}

Creature* Room::delCreature (string name){
    return NULL;
}

void Room::setType(string type){
    this->type = type;
}
bool Room::isExit(){
    cout << type << endl;
    return type=="exit"?true:false;
}
