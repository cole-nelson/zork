#include "../inc/GameObject.h"

GameObject::GameObject(string name, string stat, string desp):
    name(name),stat(stat),desp(desp)
{
    //not really need to do anything here
}

GameObject::~GameObject() {}

string GameObject::getName() {return name;}
string GameObject::getStatus() {return stat;} 
string GameObject::getDescription() {return desp;}
