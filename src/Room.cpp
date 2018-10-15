#include <string>
#include <iostream>
#include "../inc/Room.h"

Room::Room(string name, string stat, string des, string type, 
            string north, string south, string west, string east):
    GameObject(name, stat, des),type(type),
    north(north),south(south),west(west),east(east)
{
}

Room::~Room(){
}

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
