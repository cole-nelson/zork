#include "../inc/util.h"
#include "../inc/Trigger.h"

Trigger::Trigger(): 
    cmd(""), type("single"), print(""),
    stat(""), cond(NULL) {}


Trigger::~Trigger(){
    if(cond) delete cond;
}

void Trigger::setType(string type){this->type = type;}      // this is probably unnecessary
                                                            // since every trigger should
                                                            // have a type ...
void Trigger::setPrint(string print){this->print = print;}
void Trigger::setCommand(string cmd){this->cmd = cmd;}
void Trigger::setStatus(string stat){this->stat = stat;}
void Trigger::setCondition(Condition *c){this->cond = c;}
void Trigger::addAction(Action* act){actions.push_back(act);}

string Trigger::getType() {return type;}
string Trigger::getPrint() {return print;}
string Trigger::getCommand() {return cmd;}
string Trigger::getStatus() {return stat;}

bool Trigger::checkCondition(string input_cmd){
    cerr << "$" << input_cmd << "$ $" << cmd << "$" << endl;
    if(cmd != "" && cmd != input_cmd) return false; // nothing to do with this trigger
    return cond?cond->checkCondition():false;
}

void Trigger::fire(){
    if(print != ""){
        cout << print << endl;
    }
    // take action
    for(auto actionPtr:actions){
        actionPtr->exec();
    }
}

Condition::Condition(){}
Condition::~Condition(){}

HasCondition::HasCondition(bool hs, std::string name, GameObject* owner):
    has(hs), hasName(name), owner(owner) {}

HasCondition::~HasCondition(){}

bool HasCondition::checkCondition(){
    return (owner->searchCollection(hasName) != NULL) == has;
}

StatCondition::StatCondition(GameObject *target, std::string stat) :
	target(target), stat(stat){}

StatCondition::~StatCondition(){}

bool StatCondition::checkCondition(){
    if(target->getStatus() == stat) return true;
    return false;
}

