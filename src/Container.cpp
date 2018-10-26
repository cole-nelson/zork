#include <string>
#include <iostream>
#include "../inc/Container.h"

Container::Container():
    GameObject(), open_stat(false){
    collection[ITEM] = &items;
}

Container::Container(const Container& orig):
    GameObject(orig),
    items(orig.items), accept(orig.accept), open_stat(orig.open_stat)
{}

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
    auto it = items.begin();
    for(;it != items.end();it++){
        if((*it)->getName() == name) break; 
    }
    if(it == items.end()) return NULL;
    
    Item* newItem = new Item(*static_cast<Item*>(*it));
    items.erase(it);
    return newItem;
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
