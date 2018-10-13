#ifndef INC_ROOM_H_
#define INC_ROOM_H_

#include <string>
#include "../inc/GameObject.h"

using namespace std;
class Room: public GameObject {
private:
    string type;
    string north;
    string south;
    string west;
    string east;
public:
    Room(string, string, string, string,
    //   ^name   ^status ^des    ^type
         string, string, string, string);
    //   ^north  ^south  ^west   ^east
	virtual ~Room();
};

#endif /* INC_GAMEOBJECT_H_ */
