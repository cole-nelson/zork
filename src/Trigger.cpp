#include "../inc/util.h"
#include "../inc/Trigger.h"

Trigger::Trigger(): 
    cmd(""), type("single"), print(""),
    owner(""),stat(""), cond(NULL) {}

Trigger::Trigger(const Trigger& trig) :
    cmd(trig.cmd), type(trig.type), print(trig.type),
    owner(trig.owner),stat(trig.stat), cond(trig.cond) {}

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

string Trigger::getType() {return type;}
string Trigger::getPrint() {return print;}
string Trigger::getCommand() {return cmd;}
string Trigger::getStatus() {return stat;}

bool Trigger::checkCondition(string input_cmd){
    if(cmd != "" && cmd != input_cmd) return false; // nothing to do with this trigger
    return cond?cond->checkCondition():false;
}

void Trigger::fire(){
    cout << "Trigger Fire!!!" << endl;
    if(print != ""){
        cout << print << endl;
    }
    // take action
}

Condition::Condition(GameObject *t) : target(t){}
Condition::~Condition(){}

HasCondition::HasCondition(GameObject *target, bool hs, std::string name, std::string owner):
	Condition(target), has(hs), hasName(name), owner(owner) {}

HasCondition::~HasCondition(){}

bool HasCondition::checkCondition(){
    return target->searchCollection(hasName,owner) == has;
}

StatCondition::StatCondition(GameObject *target, std::string stat) :
	Condition(target), stat(stat){}

StatCondition::~StatCondition(){}

bool StatCondition::checkCondition(){
    if(target->getStatus() == stat) return true;
    return false;
}

