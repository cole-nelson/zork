#include <string>
#include <iostream>
#include "../inc/Item.h"

Item::Item():
    GameObject(),
    writing("Nothing written"), turnOnAct(NULL){}

Item::Item(const Item& orig):
    GameObject(orig),
    writing(orig.writing), turnOnAct(orig.turnOnAct){}

Item::~Item() {}

void Item::setWriting(string writing){
    this->writing = writing;
}

string Item::getWriting(){
    return writing;
}

void Item::turnOn(){
    if(turnOnAct) turnOnAct->exec();
    else cout << "cannot turn on " << getName() << endl;
}
