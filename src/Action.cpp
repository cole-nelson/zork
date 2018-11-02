#include "../inc/Action.h"
#include "../inc/GameObject.h"
#include "../inc/Zork.h"

UpdateAction::UpdateAction(GameObject* target, string stat):
    Action(target), stat(stat){}

UpdateAction::~UpdateAction(){}

void UpdateAction::exec(){
    target->setStatus(stat);
}


AddAction::AddAction(GameObject* target, GameObject* origItem):
    Action(target), origItem(origItem){}

AddAction::~AddAction(){}

void AddAction::exec(){
    cout << "Adding " << origItem->getName() << " to " << target->getName() << endl;
    target->addToCollection(origItem, ITEM);
    origItem->setBelongsTo(target);
}


DelAction::DelAction(GameObject* target, string nameToDelete):
    Action(target), nameToDelete(nameToDelete){}

DelAction::~DelAction(){}

void DelAction::exec(){
   if(target)target->deleteFromCollection(nameToDelete);
}


RegularAction::RegularAction(string cmd, Zork* game):
    Action(NULL), cmd(cmd), game(game){}

RegularAction::~RegularAction(){}

void RegularAction::exec(){
    if(cmd == "Game Over"){
        game->Won();
        game->GameOver();
    }
    else game->execCmd(cmd);
}
