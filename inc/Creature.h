#ifndef INC_CREATURE_H_
#define INC_CREATURE_H_
#include <vector>
#include "GameObject.h"
using namespace std;
class Creature : public GameObject {
private:
	vector<string> vulnerability;
public:
	Creature(string na, string sts, string des);
	virtual ~Creature();
	string getName() {return name;}
	string getStatus() {return stat;}
	string getDescription() {return desp;}
};
#endif
