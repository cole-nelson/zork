#ifndef INC_TRIGGER_H_
#define INC_TRIGGER_H_
#include <string>
#include <vector>
#include <iostream>
#include "GameObject.h"
#include "Action.h"

class GameObject;

using namespace std;

class Condition{
public:
    Condition();
    virtual ~Condition();
    virtual bool checkCondition()=0;
};

class HasCondition : public Condition{
private:
    bool has;
    string hasName;
    GameObject* owner;
public:
    HasCondition(bool, string, GameObject*);
    virtual ~HasCondition();
    bool checkCondition();
};

class StatCondition : public Condition{
private:
    GameObject* target;
    string stat;
public:
    StatCondition(GameObject*, string);
    virtual ~StatCondition();
    bool checkCondition();
};

class TrueCondition : public Condition {
public:
	TrueCondition() {};
	virtual ~TrueCondition() {};
	bool checkCondition() {cout << "this should be true" << endl; return true;}
};

class Trigger{
private:
    string cmd;
	string type;
	string print;
	vector <Action*> actions;
	string stat;
public:
    Condition* cond;
    Trigger();
	virtual ~Trigger();

	virtual void setType(string);
	virtual void setPrint(string);
	virtual void setCommand(string);
	virtual void setStatus(string);
	virtual void setCondition(Condition*);
    virtual void addAction(Action*);

    string getType();
	string getPrint();
	string getCommand();
	string getStatus();

    bool checkCondition(string);
    void fire();
};

#endif
