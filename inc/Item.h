/*
 * Item.h
 *
 *  Created on: Oct 3, 2018
 *      Author: cole
 */

#ifndef INC_ITEM_H_
#define INC_ITEM_H_

#include "GameObject.h"
#include "Action.h"

using namespace std;
class Item : public GameObject {
private:
	string writing;
    Trigger *turnOnTrigger;
public:
    Item();
    Item(const Item&);
	virtual ~Item();

    void setWriting(string);
    void addAction(Action*);
    void setTrigger(Trigger *t);
	string getWriting();
    
    void turnOn();
};


#endif /* INC_ITEM_H_ */
