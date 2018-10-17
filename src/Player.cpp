#include "../inc/Player.h"

Player::Player(){}
Player::~Player(){}

Room* Player::move(Direction dir, Room* from, 
        unordered_map<string, GameObject*>& gameObjs)
{
    string room_name = from->get_neighbor(dir); 
    if(room_name == "NULL"){
        cout << "Can't go that way" << endl;
        return from;
    }
    

    Room* ret = dynamic_cast<Room*>(gameObjs[room_name]);
    cout << ret -> getDescription() << endl;
    return ret;
}

void Player::open_inventory(){
    for(auto item:inventory){
        cout << item->getName() << " ";
    }
    cout << endl;
}
