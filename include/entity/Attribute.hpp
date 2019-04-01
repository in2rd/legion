#include <string>
#include <utility>
#include <vector>

#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

using namespace std;

class Attribute {
private:
    string name;
    int current;
    vector<pair<string, int>> base_lineage;
    vector<pair<string, int>> modifier_lineage;

public:
    Attribute();
    Attribute(std::string, int, int);
    ~Attribute();
    void set_name(string);
    int get(void);
    int total(void);
    int get_base(void);
    int get_modifier(void);
    int update_base(std::string, int);
    int update_modifier(std::string, int);
    bool update_current(int);
};

#endif