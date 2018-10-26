#include <string>
#include <iostream>
#include "../inc/Room.h"

Room::Room():
    type("regular"),
    north("NULL"),south("NULL"),east("NULL"),west("NULL")
{
    collection[ITEM] = &items;
    collection[CONTAINER] = &containers;
    collection[CREATURE] = &creatures;
}

// TODO: write proper descructor
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

void Room::addItem(Item* item){
    Item* newItem = new Item(*item);
    items.push_back(newItem);
}

void Room::addContainer(Container* container){
    Container* newContainer = new Container(*container);
    containers.push_back(newContainer);
}

void Room::addCreature(Creature* creature){
    Creature* newCreature = new Creature(*creature);
    creatures.push_back(newCreature); 
}

Item* Room::delItem(string name){
    for(auto it = items.begin(); it != items.end(); it++){
        if((*it)->getName() == name){
            Item* ret = new Item(*static_cast<Item*>(*it));
            items.erase(it);
            return ret; 
        }
    }
    cout << "item does not exist" << endl;
    return NULL;
}

// TODO: implement those
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
