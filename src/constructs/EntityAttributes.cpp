#include "entity/EntityAttributes.hpp"
#include <string>
#include <utility>
#include <vector>

using namespace std;

EntityAttributes::EntityAttributes()
{
    vector<string> attr_list = {
        "health",
        "stamina",
        "agility",
        "strength",
        "logic",
        "charisma",
        "luck",
        "willpower",
        "interconnect"
    };

    for (string name : attr_list) {
        Attribute attr = Attribute(name, 100, 0);
        attributes.insert(pair<string, Attribute>(name, attr));
    };
};

EntityAttributes::~EntityAttributes()
{
    attributes.~map();
};

int EntityAttributes::get(string name)
{
    map<string, Attribute>::iterator attr = attributes.find(name);
    return attr->second.get();
};

int EntityAttributes::update(string name, int delta)
{
    map<string, Attribute>::iterator attr = attributes.find(name);
    bool is_zero = attr->second.update_current(delta);

    if (is_zero == true) {
        return 0;
    } else {
        return attr->second.get();
    }
};

int EntityAttributes::base(string name, string reason, int delta)
{
    map<string, Attribute>::iterator attr = attributes.find(name);
    return attr->second.update_base(reason, delta);
};

int EntityAttributes::modifier(string name, string reason, int value)
{
    map<string, Attribute>::iterator attr = attributes.find(name);
    return attr->second.update_modifier(reason, value);
};