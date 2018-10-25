#ifndef INC_PLAYER_H_
#define INC_PLAYER_H_

#include "GameObject.h"
#include "Item.h"
#include "Room.h"

#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

class Player{
    vector<Item*> inventory;
    vector<Item*>::iterator searchInventory(string);
public:
    Player();
    virtual ~Player();

    Room* move(Direction, Room*, unordered_map<string, Room*>&);
    void addItem(Item*);
    Item* delItem(string);
    void readItem(string);
    void openInventory();
};
#endif
