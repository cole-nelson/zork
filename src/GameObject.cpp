#include "../inc/GameObject.h"

GameObject::GameObject():
    name("nameless"),stat("off"),desp("No description")
{}

GameObject::GameObject(const GameObject& orig):
    name(orig.name),stat(orig.stat),desp(orig.desp)
{}

GameObject::GameObject(string name, string stat, string desp):
    name(name),stat(stat),desp(desp)
{
    //not really need to do anything here
}

GameObject::~GameObject() {}

void GameObject::setName(string name){ this->name = name;}
void GameObject::setStatus(string stat){ this->stat = stat;}
void GameObject::setDescription(string desp){ this->desp = desp;}
string GameObject::getName() {return name;}
string GameObject::getStatus() {return stat;} 
string GameObject::getDescription() {return desp;}


bool GameObject::searchCollection(string target, const string& containerName){
    
    if(collection.find(containerName) == collection.end()) return false;
    for(auto item: collection[containerName]){
        if(item->name == target) return true;
    }

    return false;
}

void GameObject::addToCollection(GameObject* item, const string& containerName){
    
    if(collection.find(containerName) == collection.end()) return;
    collection[containerName].push_back(item);
    
}
