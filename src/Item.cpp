#include <string>
#include <iostream>
#include "../inc/Item.h"

Item::Item():
    GameObject(),
    writing("Nothing written"){}

Item::Item(const Item& orig):
    GameObject(orig),
    writing(orig.writing){}

Item::Item(std::string na, std::string st, std::string des, std::string wr) :
    GameObject(na,st,des),
	writing(wr) {}

Item::~Item() {}

void Item::setWriting(string writing){
    this->writing = writing;
}

string Item::getWriting(){
    return writing;
}
