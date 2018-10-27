#include "../inc/Action.h"

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
    target->addToCollection(origItem, ITEM);
}


DelAction::DelAction(GameObject* target, string nameToDelete):
    Action(target), nameToDelete(nameToDelete){}

DelAction::~DelAction(){}

void DelAction::exec(){
    target->deleteFromCollection(nameToDelete, ITEM);
}
