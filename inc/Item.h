/*
 * Item.h
 *
 *  Created on: Oct 3, 2018
 *      Author: cole
 */

#ifndef INC_ITEM_H_
#define INC_ITEM_H_

#include "GameObject.h"

class Item : public GameObject {
private:
	std::string name;
	std::string status;
	std::string description;
	std::string writing;
public:
	Item();
	virtual ~Item();

	std::string getName() {return name;}
	std::string getStatus() {return status;}
	std::string getDescription() {return description;}
	std::string getWriting() {return writing;}
};



#endif /* INC_ITEM_H_ */
