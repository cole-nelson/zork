#ifndef INC_ROOM_H_
#define INC_ROOM_H_

#include <string>
#include <unordered_map>
#include "../inc/GameObject.h"
#include "../inc/Container.h"
#include "../inc/Item.h"
#include "../inc/Creature.h"

using namespace std;

enum Direction{
    NORTH,
    SOUTH,
    WEST,
    EAST
};

class Room: public GameObject {
private:
    string type;
    string north;
    string south;
    string west;
    string east;
    unordered_map<string, Container*> containers;
    unordered_map<string, Item*> inventory;
    unordered_map<string, Creature*> creatures;

public:
    Room(string, string, string, string,
    //   ^name   ^status ^des    ^type
         unordered_map<string, string>&,
    //      ^directions
         unordered_map<string, Item*>&);
    //      ^inventory
	virtual ~Room();
    string get_neighbor(Direction);
};

#endif /* INC_GAMEOBJECT_H_ */
