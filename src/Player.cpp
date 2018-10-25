#include "../inc/Player.h"

Player::Player():
    GameObject(){
    collection["inventory"] = &inventory;
}

Player::~Player(){}

vector<GameObject*>::iterator Player::searchInventory(string name){
    for(auto it = inventory.begin(); it != inventory.end(); it++){
        if((*it)->getName() == name){
            return it; 
        }
    }
    cout << "item does not exist" << endl;
    return inventory.end();
}

Room* Player::move(Direction dir, Room* from, 
        unordered_map<string, Room*>& rooms)
{
    string room_name = from->getNeighbor(dir); 
    if(room_name == "NULL"){
        cout << "Can't go that way" << endl;
        return from;
    }
    

    Room* ret = rooms[room_name];
    cout << ret -> getDescription() << endl;
    return ret;
}

void Player::addItem(Item* item){
    Item* newItem = new Item(*item);
    inventory.push_back(newItem);
}

Item* Player::delItem(string name){
    auto it = searchInventory(name);
    if(it != inventory.end()){
        Item* ret = new Item(*static_cast<Item*>(*it));
        inventory.erase(it);
        return ret; 
    }
    
    return NULL;
}

void Player::readItem(string name){
    auto it = searchInventory(name);
    if(it != inventory.end()){
        cout << static_cast<Item*>(*it)->getWriting() << endl;
    }
}

void Player::openInventory(){
    for(auto item:inventory){
        cout << static_cast<Item*>(item)->getName() << " ";
    }
    cout << endl;
}


