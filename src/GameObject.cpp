#include "../inc/GameObject.h"

GameObject::GameObject():
    name("nameless"),stat("off"),desp("No description")
{}

/*
GameObject::GameObject(const GameObject& orig):
    name(orig.name),stat(orig.stat),desp(orig.desp),
    collection(orig.collection), triggers(orig.triggers)
{}
*/

GameObject::~GameObject() {}

void GameObject::setName(string name){ this->name = name;}
void GameObject::setStatus(string stat){ this->stat = stat;}
void GameObject::setDescription(string desp){ this->desp = desp;}
string GameObject::getName() {return name;}
string GameObject::getStatus() {return stat;} 
string GameObject::getDescription() {return desp;}


GameObject* GameObject::searchCollection(const string& target){
    
    for(auto collect: collection){
        for(auto item: *collect.second){
            if(item->getName() == target) return item;
        }
    }

    return NULL;
}

GameObject* GameObject::searchCollection(const string& target, ObjectType type){
     
    for(auto collect: collection){
        for(auto item: *collect.second){
            if(item->getName() == target) return item;
        }
    }

    return NULL;
}

void GameObject::addToCollection(GameObject* item, ObjectType type){
    
    
    if(collection.find(type) == collection.end()){
        cout << "no such collection in " << name << endl;
        return;
    }
   
    collection[type]->push_back(item);

}

void GameObject::deleteFromCollection(string item, ObjectType type){

    if(collection.find(type) == collection.end()){
        cout << "no such collection in " << name << endl;
        return;
    }

    for(auto it = collection[type]->begin();it != collection[type]->end(); it++){
        if((*it)->getName() == item){
            it = collection[type]->erase(it);
            return;
        }
    }
}

void GameObject::deleteFromCollection(string item){

    cout << "deleting " << item << " from " << name << endl;
    for(auto collect: collection){
        for(auto it = collect.second->begin();it != collect.second->end(); it++){
            if((*it)->getName() == item){
                it = collect.second->erase(it);
                return;
            }
        }
    }

    cout << "no such item" << endl;
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
                delete * triggersIt;
                triggersIt = triggers.erase(triggersIt); 
            }
            return true;
        }
    }

    for(auto collect: collection){
        for(auto objPtr: *collect.second){
            if(objPtr->checkAllTriggers(cmd)) return true;
        }
    }

    return false;
}
