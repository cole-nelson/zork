#ifndef TRIGGER_H_
#define TRIGGER_H_
#include <string>
#include <vector>
#include "GameObject.h"

using namespace std;

class Condition{
protected:
    GameObject* target;
public:
    Condition(GameObject *t);
    virtual ~Condition();
    virtual bool checkCondition()=0;
};

class HasCondition : public Condition{
private:
    bool has;
    string hasName;
    string containerName;
public:
    HasCondition(GameObject *target, bool hs, string name, string container);
    virtual ~HasCondition();
    bool checkCondition();
};

class StatCondition : public Condition{
private:
    string stat;
public:
    StatCondition(GameObject *target, string status);
    virtual ~StatCondition();
    bool checkCondition();
};

class Trigger{
private:
    string cmd;
	string type;
	string print;
	vector <string> action;
	GameObject* owner;
	string stat;
    Condition* cond;
public:
    Trigger(GameObject*);
	Trigger(const Trigger&);
	virtual ~Trigger();

	virtual void setType(string);
	virtual void setPrint(string);
	virtual void setCommand(string);
	virtual void setOwner(GameObject*);
	virtual void setStatus(string);
	virtual void setCondition(Condition *c);

    string getType();
	string getPrint();
	string getCommand();
	GameObject* getOwner();
	string getStatus();

    bool checkCond();
    void fire(string);
};

#endif
