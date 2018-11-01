#include <string>
#include <iostream>
#include "../inc/Container.h"

Container::Container():
    GameObject(), open_stat(false){
    collection[ITEM] = &items;
}

Container::~Container() {}

void Container::addAccept(string name){
    accept.insert(name);
}

bool Container::accepts(string name) {
    return accept.find(name) != accept.end(); // in the set?
}

void Container::open(){
    open_stat = true;
    if(!items.size()){
        cout << name << " is empty" << endl;
    }
    else{
        for(auto item:items){
            cout << item->getName() << " ";
        }
        cout << endl; 
    } 
}
