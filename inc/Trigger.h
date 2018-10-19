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
	virtual void gettype(string);
	virtual void getprint(string);
	virtual void getcommand(string);
	virtual void getowner(string);
	virtual void getstatus(string);
	string gettype();
	string getprint();
	string getcommand();
	string getowner();
	string getstatus();
};
#endif
