#include "../inc/Player.h"

Player::Player(){}
Player::~Player(){}

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

void Player::addItem(Item& item){
    inventory.push_back(item);
}

Item* Player::delItem(string name){
    for(auto it = inventory.begin(); it != inventory.end(); it++){
        if(it->getName() == name){
            Item* ret = new Item(*it);
            inventory.erase(it);
            return ret; 
        }
    }
    cout << "item does not exist" << endl;
    return NULL;
}

void Player::openInventory(){
    for(auto item:inventory){
        cout << item.getName() << " ";
    }
    cout << endl;
}
