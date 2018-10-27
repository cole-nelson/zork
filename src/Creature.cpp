#include <string>
#include <iostream>
#include "../inc/Creature.h"

Creature::Creature():
    GameObject(){}

Creature::Creature(const Creature& orig):
    GameObject(orig),
    vulnerabilities(orig.vulnerabilities),
    attackActions(orig.attackActions)
{}


Creature::~Creature() {}

void Creature::addVulnerability(string vulner){
    vulnerabilities.insert(vulner);
}

void Creature::AddAction(Action* attackPtr){
	attackActions.push_back(attackPtr);
}

void Creature::attack(string name){
    if(vulnerabilities.find(name) == vulnerabilities.end()){
        cout << "not really effective..." << endl;
    }
    else{
        for(auto actionPtr: attackActions){
            actionPtr -> exec();
        }
    }
}
