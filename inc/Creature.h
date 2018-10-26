#ifndef INC_CREATURE_H_
#define INC_CREATURE_H_
#include <vector>
#include <unordered_set>
#include "GameObject.h"

using namespace std;

class Creature : public GameObject {
private:
	unordered_set<string> vulnerabilities;
public:
    Creature();
    Creature(const Creature&);
	virtual ~Creature();

    void addVulnerability(string);
};
#endif
