#include "../inc/Trigger.h"

Trigger::Trigger() : type(""), print(""),command(""),owner(""),sta("") {}
Trigger::Trigger(const Trigger& trig) :
		type(trig.type),print(trig.type),command(trig.type),owner(trig.owner),sta(trig.sta) {}

Trigger::~Trigger(){}

void Trigger::setType(string type){this->type = type;}
void Trigger::setPrint(string print){this->print = print;}
void Trigger::setCommand(string command){this->command = command;}
void Trigger::setOwner(string owner){this->owner = owner;}
void Trigger::setStatus(string sta){this->sta = sta;}

string Trigger::getType() {return type;}
string Trigger::getPrint() {return print;}
string Trigger::getCommand() {return command;}
string Trigger::getOwner() {return owner;}
string Trigger::getStatus() {return sta;}
