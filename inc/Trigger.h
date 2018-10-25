#ifndef TRIGGER_H_
#define TRIGGER_H_
#include <string>
#include <vector>
#include <iostream>
#include "Common.h"
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
    string owner;
public:
    HasCondition(GameObject*, bool, string, string);
    virtual ~HasCondition();
    bool checkCondition();
};

class StatCondition : public Condition{
private:
    string stat;
public:
    StatCondition(GameObject*, string);
    virtual ~StatCondition();
    bool checkCondition();
};

class Trigger{
private:
    string cmd;
	string type;
	string print;
	vector <string> action;
    string owner;
	string stat;
    Condition* cond;
public:
    Trigger();
	Trigger(const Trigger&);
	virtual ~Trigger();

	virtual void setType(string);
	virtual void setPrint(string);
	virtual void setCommand(string);
	virtual void setStatus(string);
	virtual void setCondition(Condition*);

    string getType();
	string getPrint();
	string getCommand();
	string getStatus();

    bool checkCondition(string);
    void fire();
};

#endif
