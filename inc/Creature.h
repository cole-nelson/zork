#ifndef INC_CREATURE_H_
#define INC_CREATURE_H_

#include <vector>
#include <unordered_set>
#include "GameObject.h"

using namespace std;

class Creature : public GameObject {
private:
	unordered_set<string> vulnerabilities;
    Trigger* attackTrigger;
public:
    Creature();
    Creature(const Creature&);
	virtual ~Creature();

    void addVulnerability(string);
    void setAttackTrigger(Trigger*);
    void attack(string);
};
#endif
