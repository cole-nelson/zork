#include "../inc/GameObject.h"

GameObject::GameObject():
    name("nameless"),stat("off"),desp("No description")
{}

GameObject::GameObject(const GameObject& orig):
    name(orig.name),stat(orig.stat),desp(orig.desp),triggers(orig.triggers)
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
    for(auto item: *collection[containerName]){
        if(item->name == target) return true;
    }

    return false;
}

void GameObject::addToCollection(GameObject* item, const string& containerName){
    
    if(collection.find(containerName) == collection.end()){
        cout << "no such collection " << containerName << endl;
        return;
    }
    // make a copy and push back
    collection[containerName]->push_back(item);

}

void GameObject::addTriggers(Trigger* trig){
    triggers.insert(trig);
}

// check all trigger in current object and in 
// the collection of current object
// return true if something happen
// false if nothing match
// @cmd: input command from commandline
bool GameObject::checkAllTriggers(string cmd){
    // check current obj
    for(auto triggersIt = triggers.begin(); 
            triggersIt != triggers.end(); triggersIt++){

        if((*triggersIt) -> checkCondition(cmd)){
            (*triggersIt) -> fire();
            if((*triggersIt) -> getType() == "single"){
                triggersIt = triggers.erase(triggersIt); 
            }
            return true;
        }
    }

    // check all obj belongs to current obj
    cout << "checking triggers for " << name << endl;
    for(auto collect: collection){
        cout << "collect name: " << collect.first << endl;
        for(auto objPtr: *collect.second){
            if(objPtr->checkAllTriggers(cmd)) return true;
        }
    }

    return false;
}
