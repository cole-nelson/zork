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
#include <vector>

using namespace std;

class GameObject {
protected:
    string name;
    string stat;
    string desp;
    unordered_map<string, vector<GameObject*>> collection;

public:
	GameObject();
    GameObject(const GameObject&);
	GameObject(string, string, string); // dont really need
	virtual ~GameObject();              

    virtual void setName(string);             // these are better
    virtual void setStatus(string);
    virtual void setDescription(string);

    virtual string getName();
	virtual string getStatus(); 
	virtual string getDescription();

    virtual bool searchCollection(string, const string&);
    virtual void addToCollection(GameObject*, const string&);
};



#endif /* INC_GAMEOBJECT_H_ */
