#include <string>
#include <iostream>
#include "../inc/Room.h"

Room::Room(string (&args)[4], string (&dirs)[4]):
    GameObject(args[NAME],args[STATUS],args[DESCRIPTION]),
    type(args[TYPE]),
    north(dirs[0]),south(dirs[1]),west(dirs[2]),east(dirs[3])
{
}

Room::~Room(){
}
