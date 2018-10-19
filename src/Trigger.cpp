#include "../inc/Trigger.h"

Trigger::Trigger() : type(""), print(""),command(""),owner(""),sta("") {}
Trigger::Trigger(const Trigger& trig) :
		type(trig.type),print(trig.type),command(trig.type),owner(trig.owner),sta(trig.sta) {}

Trigger::~Trigger(){}

void Trigger::gettype(string type){this->type = type;}
void Trigger::getprint(string print){this->print = print;}
void Trigger::getcommand(string command){this->command = command;}
void Trigger::getowner(string owner){this->owner = owner;}
void Trigger::getstatus(string sta){this->sta = sta;}

string Trigger::gettype() {return type;}
string Trigger::getprint() {return print;}
string Trigger::getcommand() {return command;}
string Trigger::getowner() {return owner;}
string Trigger::getstatus() {return sta;}
