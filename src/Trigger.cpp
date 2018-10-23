#include "../inc/util.h"
#include "../inc/Trigger.h"

Trigger::Trigger() : cmd(""), type("permanent"), print(""),command(""),owner(NULL),stat("") {}
Trigger::Trigger(const Trigger& trig) :
		type(trig.type),print(trig.type),command(trig.type),owner(trig.owner),stat(trig.stat) {}

Trigger::~Trigger(){}

void Trigger::setType(string type){this->type = type;}
void Trigger::setPrint(string print){this->print = print;}
void Trigger::setCommand(string command){this->command = command;}
void Trigger::setOwner(GameObject* owner){this->owner = owner;}
void Trigger::setStatus(string stat){this->stat = stat;}

string Trigger::getType() {return type;}
string Trigger::getPrint() {return print;}
string Trigger::getCommand() {return command;}
GameObject* Trigger::getOwner() {return owner;}
string Trigger::getStatus() {return stat;}

bool Trigger::checkCond(){
    return cond->checkConditation();
}

void Trigger::fire(string input_cmd){

    if(cmd != "" && cmd != input_cmd) return; // nothing to do with this trigger

    // action
    vector<string> cmd_ls = SplitString(input_cmd," ");

}

Conditation::Conditation(){}
Conditation::~Conditation(){}

HasConditation::HasConditation(){}
HasConditation::~HasConditation(){}
bool HasConditation::checkConditation(){
    return target->searchCollection(hasName,containerName) == has;
}

StatConditation::StatConditation(){}
StatConditation::~StatConditation(){}
bool StatConditation::checkConditation(){
    if(target->getStatus() == stat) return true;
    return false;
}

