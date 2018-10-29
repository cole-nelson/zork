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
