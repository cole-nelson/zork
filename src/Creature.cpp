#include <string>
#include <iostream>
#include "../inc/Creature.h"

Creature::Creature():
    GameObject(){}

Creature::Creature(const Creature& orig):
    GameObject(orig),
    vulnerabilities(orig.vulnerabilities)
{}

Creature::Creature(string na, string st, string des):
    GameObject(na, st, des)
{}

Creature::~Creature() {}

void Creature::addVulnerability(string vulner){
    vulnerabilities.insert(vulner);
}
