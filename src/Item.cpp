#include <string>
#include <iostream>
#include "../inc/Item.h"

Item::Item():
    GameObject(),
    writing("Nothing written")/*, turnOnAct()*/{}

Item::~Item() {}

void Item::setTrigger(Trigger *t) {
    this->turnOnTrigger = t;
}

void Item::setWriting(string writing){
    this->writing = writing;
}

string Item::getWriting(){
    return writing;
}

void Item::turnOn(){
    if(!turnOnTrigger) cout << "you cannot turn on " << name << endl;
    else if(turnOnTrigger->checkCondition("turn on")){
        turnOnTrigger->fire();
    }
    else cout << "not now..." << endl;
}
