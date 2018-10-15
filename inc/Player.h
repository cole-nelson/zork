#ifndef INC_PLAYER_H_
#define INC_PLAYER_H_

#include "GameObject.h"
#include "Item.h"
#include "Room.h"
#include <unordered_set>
#include <iostream>
#include <string>

using namespace std;

class Player{
    unordered_set<Item*> inventory;
public:
    Player();
    virtual ~Player();

    Room* move(Direction, Room*, unordered_map<string, GameObject*>&);
    void open_inventory();
};
#endif
