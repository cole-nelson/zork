#include <string>
#include <iostream>
#include "../inc/Trigger.h"
#include "../inc/Creature.h"

Creature::Creature():
    GameObject(),attackTrigger(NULL){}

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
        cout << "You assult " << this->name << " with " << name << endl;
        if(attackTrigger){
            if(attackTrigger->checkCondition("")) attackTrigger->fire();
            else cout << "not really effective..." << endl;
        }
    }
}
