#include <string>
#include <iostream>
#include "../inc/Item.h"

Item::Item():
    GameObject(),
    writing("Nothing written")/*, turnOnAct()*/{}

    /*
Item::Item(const Item& orig):
    GameObject(orig),
    writing(orig.writing), turnOnAct(orig.turnOnAct){}
*/

Item::~Item() {}

/*void Item::addAction(Action *a) {
	turnOnAct.push_back(a);
}*/

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
    if(!turnOnTrigger) cout << "cannot turn on" << endl;
    else if(turnOnTrigger->checkCondition("turn on")){
        turnOnTrigger->fire();
    }
    else cout << "not now..." << endl;
}
