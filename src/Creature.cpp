#include <string>
#include <iostream>
#include "../inc/Creature.h"

Creature::Creature():
    GameObject(){}

Creature::Creature(const Creature& orig):
    GameObject(orig),
    vulnerabilities(orig.vulnerabilities)
{}

Creature::~Creature() {}

void Creature::addVulnerability(string vulner){
    vulnerabilities.insert(vulner);
}

void Creature::attack(string name){

}
