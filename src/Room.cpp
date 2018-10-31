#include <string>
#include <iostream>
#include "../inc/Room.h"
#include "../inc/Container.h"

Room::Room():
    type("regular"),
    north("NULL"),south("NULL"),east("NULL"),west("NULL")
{
    collection[ITEM] = &items;
    collection[CONTAINER] = &containers;
    collection[CREATURE] = &creatures;
}

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

GameObject* Room::searchContainers(const string& name){
    for(auto cont: containers){
        if(!static_cast<Container*>(cont)->isOpen())continue;
        GameObject* ret = cont->searchCollection(name,ITEM);
        if(ret) return ret;
    }
    return NULL;
}

void Room::setType(string type){
    this->type = type;
}

bool Room::isExit(){
    // cout << type << endl;
    return type=="exit"?true:false;
}
