#include <string>
#include <iostream>
#include "../inc/Item.h"

Item::Item():
    GameObject(),
    writing("Nothing written")/*, turnOnAct()*/{}

Item::Item(const Item& orig):
    GameObject(orig),
    writing(orig.writing)/*, turnOnAct(orig.turnOnAct)*/{}

Item::~Item() {}

/*void Item::addAction(Action *a) {
	turnOnAct.push_back(a);
}*/

void Item::setWriting(string writing){
    this->writing = writing;
}

string Item::getWriting(){
    return writing;
}

void Item::turnOn(){
	turnOnTrigger->fire();
	/*if(turnOnAct.size() != 0) {
		for(auto act : turnOnAct) {
			act->exec();
		}
	} else cout << "cannot turn on " << getName() << endl;*/
}
