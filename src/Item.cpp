#include <string>
#include <iostream>
#include "../inc/Item.h"

Item::Item(std::string na, std::string st, std::string des, std::string wr) :
    GameObject(na,st,des),
	writing(wr) {}

Item::~Item() {}

