#ifndef INC_ROOM_H_
#define INC_ROOM_H_

#include <string>
#include <unordered_map>
#include <vector>
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
    string east;
    string west;
    vector<GameObject*> items;          // vector is fine for now...
    vector<GameObject*> containers;     // probably change these three to multi set...
    vector<GameObject*> creatures;      // since might sotre same object multiple times
public:
    Room();
	virtual ~Room();
    void setNeighbor(string, string);
    string getNeighbor(Direction);
    void setType(string);

    void addItem(Item*);
    void addContainer(Container*);
    void addCreature(Creature*);
    Item*       delItem     (string);
    Container*  delContainer(string);
    Creature*   delCreature (string);
    bool isExit();
};

#endif /* INC_GAMEOBJECT_H_ */
