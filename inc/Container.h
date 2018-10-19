#ifndef INC_CONTAINER_H_
#define INC_CONTAINER_H_
#include <vector>
#include <unordered_set>
#include "GameObject.h"

using namespace std;

class Container : public GameObject {
private:
	vector<string> item;
    unordered_set<string> accept;
public:
    Container();
    Container(const Container& orig);
	Container(string na, string sts, string des);
	virtual ~Container();

    void addAccept(string);
};
#endif
