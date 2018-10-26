#include <string>
#include <iostream>
#include "../inc/Container.h"

Container::Container():
    GameObject(), isOpen(false){
    collection[ITEM] = &items;
}

Container::Container(const Container& orig):
    GameObject(orig),
    items(orig.items), accept(orig.accept), isOpen(orig.isOpen)
{}

Container::~Container() {}

void Container::addAccept(string name){
    accept.insert(name);
}

void Container::addItem(Item* obj){
    Item* newItem = new Item(*obj);
    items.push_back(newItem);
}

void Container::open(){
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
