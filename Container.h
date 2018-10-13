#ifndef INC_ITEM_H_
#define INC_ITEM_H_
#include <vector>
#include "GameObject.h"
using namespace std;
class container : public GameObject {
private:
	string name;
	string status;
	string description;
	vector<string> item;
	vector<string> accept;
public:
	container(string na, string sts, string des);
	virtual ~container();
	string getName() {return name;}
	string getStatus() {return status;}
	string getDescription() {return description;}
};
#endif
