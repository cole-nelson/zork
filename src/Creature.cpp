#include <string>
#include <iostream>
#include "../inc/Creature.h"

Creature::Creature(string na, string st, string des)
    :GameObject(na, st, des)
{
}

Creature::~Creature() {}
