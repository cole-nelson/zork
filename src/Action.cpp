#include "../inc/Action.h"

UpdateAction::UpdateAction(GameObject* target, string stat):
    Action(target), stat(stat){}

UpdateAction::~UpdateAction(){}

void UpdateAction::exec(){
    target->setStatus(stat);
    cout << printedText << endl;
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
