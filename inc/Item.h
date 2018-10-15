/*
 * Item.h
 *
 *  Created on: Oct 3, 2018
 *      Author: cole
 */

#ifndef INC_ITEM_H_
#define INC_ITEM_H_

#include "GameObject.h"

using namespace std;
class Item : public GameObject {
private:
	string writing;
public:
	Item(string na, string st, string des, string wr);
	virtual ~Item();

	string getWriting() {return writing;}
};



#endif /* INC_ITEM_H_ */
