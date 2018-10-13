#ifndef INC_CONTAINER_H_
#define INC_CONTAINER_H_
#include <vector>
#include "GameObject.h"
using namespace std;
class Container : public GameObject {
private:
	vector<string> item;
	vector<string> accept;
public:
	Container(string na, string sts, string des);
	virtual ~Container();
	string getName() {return name;}
	string getStatus() {return stat;}
	string getDescription() {return desp;}
};
#endif
