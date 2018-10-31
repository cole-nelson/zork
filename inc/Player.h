#ifndef INC_PLAYER_H_
#define INC_PLAYER_H_


#include <unordered_map>
#include <iostream>
#include <string>
#include "Container.h"
#include "Room.h"

using namespace std;

class Player{
    Container* inventory;
public:
    Player(Container*);
    virtual ~Player();

    Room* move(Direction, Room*, unordered_map<string, Room*>&);
    void readItem(string);
    void takeItem(string, Room*);
    void dropItem(string, Room*);
    void openInventory();
friend class Zork;
};

#endif
