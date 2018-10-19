#include <string>
#include <iostream>
#include "../inc/Container.h"

Container::Container():GameObject(){stat = "closed";}

Container::Container(const Container& orig):
    GameObject(orig),
    accept(orig.accept)
{}

Container::Container(string na, string st, string des):
    GameObject(na, st, des)
{}

Container::~Container() {}

void Container::addAccept(string name){
    accept.insert(name);
}
