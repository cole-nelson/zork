#ifndef INC_PLAYER_H_
#define INC_PLAYER_H_

#include "GameObject.h"
#include "Container.h"
#include "Item.h"
#include "Room.h"

#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

class Player{
    Container* inventory;
public:
    Player(Container*);
    virtual ~Player();

    Room* move(Direction, Room*, unordered_map<string, Room*>&);
    void addItem(Item*);
    Item* delItem(string);
    void readItem(string);
    void takeItem(string, Room*);
    void dropItem(string, Room*);
    void openInventory();
friend class Zork;
};

#endif
