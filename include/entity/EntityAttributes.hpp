#include "Attribute.hpp"
#include <map>
#include <string>

using namespace std;

#ifndef ENTITYATTRIBUTES_H_
#define ENTITYATTRIBUTES_H_

class EntityAttributes {
private:
    map<string, Attribute> attributes;

public:
    EntityAttributes();
    ~EntityAttributes();
    int get(string);
    int update(string, int);
    int base(string, string, int);
    int modifier(string, string, int);
};

#endif