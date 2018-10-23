#ifndef TRIGGER_H_
#define TRIGGER_H_
#include <string>
#include <vector>
#include "GameObject.h"

using namespace std;

class Conditation{
protected:
    GameObject* target;
public:
    Conditation();
    virtual ~Conditation();
    virtual bool checkConditation()=0;
};

class HasConditation : public Conditation{
private:
    bool has;
    string hasName;
    string containerName;
public:
    HasConditation();
    virtual ~HasConditation();
    bool checkConditation();
};

class StatConditation : public Conditation{
private:
    string stat;
public:
    StatConditation();
    virtual ~StatConditation();
    bool checkConditation();
};

class Trigger{
private:
    string cmd;
	string type;
	string print;
	vector <string> action;
	GameObject* owner;
	string stat;
    Conditation* cond;
public:
    Trigger(GameObject*);
	Trigger(const Trigger&);
	virtual ~Trigger();

	virtual void setType(string);
	virtual void setPrint(string);
	virtual void setCommand(string);
	virtual void setOwner(GameObject*);
	virtual void setStatus(string);

    string getType();
	string getPrint();
	string getCommand();
	GameObject* getOwner();
	string getStatus();

    bool checkCond();
    void fire(string);
};

#endif
