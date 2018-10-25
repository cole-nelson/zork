#include <string>
#include <iostream>
#include "../inc/Container.h"

Container::Container():GameObject(){
    collection["items"] = &items;
    stat = "closed";
}

Container::Container(const Container& orig):
    GameObject(orig),
    items(orig.items),
    accept(orig.accept)
{}

Container::Container(string na, string st, string des):
    GameObject(na, st, des)
{}

Container::~Container() {}

void Container::addAccept(string name){
    accept.insert(name);
}

void Container::addItem(Item* obj){
    Item* newItem = new Item(*obj);
    items.push_back(newItem);
}
