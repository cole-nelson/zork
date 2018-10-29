#ifndef INC_CONTAINER_H_
#define INC_CONTAINER_H_
#include <vector>
#include <unordered_set>
#include "GameObject.h"
#include "Item.h"

using namespace std;

class Container: public GameObject {
private:
	vector<GameObject*> items;
    unordered_set<string> accept;
    bool open_stat;
public:
    Container();
    //Container(const Container& orig);
	virtual ~Container();

    void addAccept(string);
    bool isOpen(){return open_stat;}

    void open();
};
#endif
