#include "../inc/Player.h"

Player::Player(Container* inventory):
    inventory(inventory){}

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

void Player::readItem(string name){
    Item* ret = static_cast<Item*>(inventory->searchCollection(name,ITEM));
    if(ret) cout << ret->getWriting() << endl;
}

void Player::takeItem(string name, Room* context){
    GameObject* targetItem = context->searchCollection(name);
   
    if(!targetItem) cout << name << " does not exist..." << endl;
    else {
        inventory->addToCollection(targetItem, ITEM); 
        targetItem->setBelongsTo(inventory);
    }
}

void Player::dropItem(string name, Room* context){
    GameObject* ret = inventory->searchCollection(name, ITEM);
    inventory->deleteFromCollection(name,ITEM);
    if(ret){
        context->addToCollection(ret,ITEM);
        ret->setBelongsTo(inventory);
    }
}

void Player::openInventory(){
    inventory->open();
}


