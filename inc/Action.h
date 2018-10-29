#ifndef INC_ACTION_H_
#define INC_ACTION_H_

#include <string>
#include "GameObject.h"

using namespace std;

class Action{
protected:
    GameObject* target;
public:
    Action(GameObject* target): target(target){};
    virtual ~Action(){};
    virtual void setTarget(GameObject* target){this->target = target;};
    virtual void exec()=0;
};

class UpdateAction: public Action{
    string stat;
public:
    UpdateAction(GameObject*, string);
    virtual ~UpdateAction();
    virtual void exec();
};

class AddAction: public Action{
    GameObject* origItem;
public:
    AddAction(GameObject*, GameObject*);
    virtual ~AddAction();
    virtual void exec();
};

class DelAction: public Action{
    string nameToDelete;
public:
    DelAction(GameObject*, string);
    virtual ~DelAction();
    virtual void exec();
};


#endif
