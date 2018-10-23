/*
 * Zork.h
 *
 *  Created on: Oct 3, 2018
 *      Author: cole
 */

#ifndef INC_ZORK_H_
#define INC_ZORK_H_

#include "Player.h"
#include "Trigger.h"
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Zork {
private:
	bool gameOver;
	unordered_map<string, GameObject*> originalObjs;    // reserved
    unordered_map<string, Room*> Rooms;                 // all Room objects
    vector<GameObject*> gameObjs;                       // all game objects
    vector<Trigger*> triggerPool;						// all triggers
    Room* entrance;
    Player player;
public:
	Zork(char *fname);
	virtual ~Zork();
	void constructGame(const char *fname);
	void playGame();
};



#endif /* INC_ZORK_H_ */
