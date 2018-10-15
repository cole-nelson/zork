/*
 * GameObject.h
 *
 *  Created on: Oct 3, 2018
 *      Author: cole
 */

#ifndef INC_GAMEOBJECT_H_
#define INC_GAMEOBJECT_H_

#include <string>
using namespace std;

enum Args{
    NAME,
    STATUS,
    TYPE,
    DESCRIPTION,
    WRITING,
    TURN_ON,
    ATTACK
};

class GameObject {
protected:
    string name;
    string stat;
    string desp;
public:
	GameObject(){};
	GameObject(string, string, string);
	virtual ~GameObject();
    virtual string getName();
	virtual string getStatus(); 
	virtual string getDescription();
};



#endif /* INC_GAMEOBJECT_H_ */
