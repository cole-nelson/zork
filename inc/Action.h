#ifndef INC_ACTION_H_
#define INC_ACTION_H_

#include "GameObject.h"

class Action{
protected:
    GameObject* target;
    string printedText;
public:
    Action(GameObject* target): target(target){};
    Action(const Action& orig): target(orig.target){};
    virtual ~Action(){};
    virtual void setTarget(GameObject* target){this->target = target;};
    virtual void exec()=0;
    void setPrint(string updatePrint) {printedText = updatePrint;}
};

class UpdateAction: public Action{
    string stat;
public:
    UpdateAction(GameObject*, string);
    UpdateAction(const UpdateAction&);
    virtual ~UpdateAction();
    virtual void exec();
};

class AddAction: public Action{
    GameObject* origItem;
public:
    AddAction(GameObject*, GameObject*);
    AddAction(const AddAction&);
    virtual ~AddAction();
    virtual void exec();
};

class DelAction: public Action{
    string nameToDelete;
public:
    DelAction(GameObject*, string);
    DelAction(const DelAction&);
    virtual ~DelAction();
    virtual void exec();
};


#endif
