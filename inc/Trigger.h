#ifndef TRIGGER_H_
#define TRIGGER_H_
#include <string>
#include <vector>

using namespace std;
class Trigger{
private:
	string type;
	string print;
	vector <string> action;
	string command;
	string owner;
	string sta;
public:
	Trigger();
	Trigger(const Trigger& );
	virtual ~Trigger();
	virtual void setType(string);
	virtual void getPrint(string);
	virtual void getCommand(string);
	virtual void getOwner(string);
	virtual void getStatus(string);
	string setType();
	string getPrint();
	string getCommand();
	string getOwner();
	string getStatus();
};
#endif
