#ifndef TRIGGER_H_
#define TRIGGER_H_
#include <string>
#include <vector>
#include "GameObject.h"

using namespace std;
class Trigger{
private:
	string type;
	string print;
	vector <string> action;
	string command;
	GameObject* owner;
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
};
#endif
