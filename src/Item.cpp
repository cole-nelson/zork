#include <string>
#include <iostream>
#include "../inc/Item.h"

Item::Item(std::string na, std::string st, std::string des, std::string wr) :
	name(na), status(st), description(des), writing(wr) {}

Item::~Item() {}

void run() {
	std::cout << "Hi" << std::endl;
}
