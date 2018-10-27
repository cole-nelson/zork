/*
 * GameObject.h
 *
 *  Created on: Oct 3, 2018
 *      Author: cole
 */

#ifndef INC_GAMEOBJECT_H_
#define INC_GAMEOBJECT_H_

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "Common.h"
#include "Trigger.h"

using namespace std;

enum ObjectType{
    ITEM,
    CONTAINER,
    CREATURE,
    INVENTORY
};

class GameObject {
protected:
    string name;
    string stat;
    string desp;
    unordered_map<ObjectType, vector<GameObject*>*> collection;
    unordered_set<Trigger*> triggers;

public:
	GameObject();
    GameObject(const GameObject&);
	virtual ~GameObject();              

    virtual void setName(string);             // these are better
    virtual void setStatus(string);
    virtual void setDescription(string);

    virtual string getName();
	virtual string getStatus(); 
	virtual string getDescription();

    virtual GameObject* searchCollection(const string&);
    virtual GameObject* searchCollection(const string&, ObjectType);

    // This two probably could serve a purpose that generalize delete and
    // add action to some GameObject
    // TODO: decide and probably implement those...
    // probably no work...
    virtual void addToCollection(GameObject*, ObjectType); 
    virtual void deleteFromCollection(string, ObjectType);

    virtual void addTriggers(Trigger*);
    virtual bool checkAllTriggers(string);
};



#endif /* INC_GAMEOBJECT_H_ */
