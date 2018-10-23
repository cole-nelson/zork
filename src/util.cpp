#include "../inc/util.h"

vector<string> SplitString(const string& s, const string& c){

    vector<string> v;
    string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(string::npos != pos2){
        v.push_back(s.substr(pos1, pos2-pos1));
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length()) v.push_back(s.substr(pos1));

    return v;
}

void Update(GameObject* obj, const string stat){
    obj->setStatus(stat);
}

void Add(GameObject* obj, GameObject* item, const string collectionName){
}


