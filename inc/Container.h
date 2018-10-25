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
public:
    Container();
    Container(const Container& orig);
	Container(string na, string sts, string des);
	virtual ~Container();

    void addAccept(string);
    void addItem(Item*);
};
#endif
