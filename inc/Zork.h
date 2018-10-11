/*
 * Zork.h
 *
 *  Created on: Oct 3, 2018
 *      Author: cole
 */

#ifndef INC_ZORK_H_
#define INC_ZORK_H_


class Zork {
private:
	bool gameOver;
	std::unordered_map<std::string, GameObject> gameObjs;
public:
	Zork();
	virtual ~Zork();
	void constructGame(const char *fname);
	void playGame();
};



#endif /* INC_ZORK_H_ */
