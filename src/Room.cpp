#include <string>
#include <iostream>
#include "../inc/Room.h"

Room::Room(string name, string stat, string des, string type, 
            unordered_map<string, string>& borders,
            unordered_map<string, Item*>& inventory):
    GameObject(name, stat, des),type(type),
    north(borders["north"]),south(borders["south"]),
    west(borders["west"]),east(borders["east"]),
    inventory(inventory)
{}

Room::~Room(){}

string Room::get_neighbor(Direction dir){
    switch(dir){
        case NORTH:
            return north;
        case SOUTH:
            return south;
        case WEST:
            return west;
        case EAST:
            return east;
        default:
            return "NULL";
    }
    
}
