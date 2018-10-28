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

void Container::addItem(Item* obj){
    Item* newItem = new Item(*obj);
    items.push_back(newItem);
}

Item* Container::delItem(string name){
    if(!open_stat) return NULL;
    for(auto it = items.begin();it != items.end();it++){
        if((*it)->getName() == name){
            Item* ret = static_cast<Item*>(*it);
            it = items.erase(it);
            return ret;
        }
    }
    return NULL; 
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
