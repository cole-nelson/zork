#include "../inc/util.h"
#include "../inc/Trigger.h"

Trigger::Trigger(GameObject* owner): 
    cmd(""), type("permanent"), print(""),
    owner(owner),stat(""), cond(NULL) {}

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
void Trigger::setOwner(GameObject* owner){this->owner = owner;} // same for this
void Trigger::setStatus(string stat){this->stat = stat;}

string Trigger::getType() {return type;}
string Trigger::getPrint() {return print;}
string Trigger::getCommand() {return cmd;}
GameObject* Trigger::getOwner() {return owner;}
string Trigger::getStatus() {return stat;}

bool Trigger::checkCond(){

    return cond?cond->checkCondition():false;
}

void Trigger::fire(string input_cmd){

    if(cmd != "" && cmd != input_cmd) return; // nothing to do with this trigger

    // action
    vector<string> cmd_ls = SplitString(input_cmd," ");

}

Condition::Condition(){}
Condition::~Condition(){}

HasCondition::HasCondition(){}
HasCondition::~HasCondition(){}
bool HasCondition::checkCondition(){
    return target->searchCollection(hasName,containerName) == has;
}

StatCondition::StatCondition(){}
StatCondition::~StatCondition(){}
bool StatCondition::checkCondition(){
    if(target->getStatus() == stat) return true;
    return false;
}

