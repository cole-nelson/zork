#ifndef TRIGGER_H_
#define TRIGGER_H_
#include <string>
#include <vector>
#include "GameObject.h"

using namespace std;

class Conditation{
private:
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
public:
    bool checkConditation();
};

class StatConditation : public Conditation{
private:
    string stat;
public:
    bool checkConditation();
};


class Trigger{
private:
    string cmd;
	string type;
	string print;
	vector <string> action;
	string command;
	GameObject* owner;
    Conditation* cond;
	string stat;
public:
	Trigger();
	Trigger(const Trigger& );
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

    void fire(string);
};

#endif
