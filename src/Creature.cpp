#include <string>
#include <iostream>
#include "../inc/Creature.h"

Creature::Creature():
    GameObject(),attackTrigger(NULL){}

/* 
Creature::Creature(const Creature& orig):
    GameObject(orig),
    vulnerabilities(orig.vulnerabilities),
    attackTrigger(orig.attackTrigger)
{}
*/


Creature::~Creature() {}

void Creature::addVulnerability(string vulner){
    vulnerabilities.insert(vulner);
}

void Creature::setAttackTrigger(Trigger* attackTrigger){
    this -> attackTrigger = attackTrigger;
}

void Creature::attack(string name){
    if(vulnerabilities.find(name) == vulnerabilities.end()){
        cout << "not really effective..." << endl;
    }
    else{
        if(attackTrigger->checkCondition("")) attackTrigger->fire();
        else cout << "not really effective..." << endl;
    }
}
