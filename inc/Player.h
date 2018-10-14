#ifndef INC_PLAYER_H_
#define INC_PLAYER_H_

#include "Item.h"
#include <unordered_set>

using namespace std;

class Player{
public:
    Player();
    virtual ~Player();
    unordered_set<Item*> inventory;
};
#endif
