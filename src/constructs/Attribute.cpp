#include "entity/Attribute.hpp"
#include <spdlog/spdlog.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

Attribute::Attribute()
{
    name = "unknown";
    current = 0;
    base_lineage = vector<pair<string, int>>();
    modifier_lineage = vector<pair<string, int>>();
};

Attribute::Attribute(string called, int base, int modifier)
{
    // Assign the name of the attribute
    name = called;

    // Create the initial base value pair
    pair<string, int> initial_base = pair<string, int>("Initial base value", base);
    base_lineage.push_back(initial_base);

    // Create the initial modifier value pair
    pair<string, int> initial_modifier = pair<string, int>("Initial modifier value", base);
    base_lineage.push_back(initial_modifier);
    spdlog::debug("Created new <Attribute> -> '{}' -> [base:{}][modifier:{}]", name, initial_base, initial_modifier);
};

Attribute::~Attribute()
{
    spdlog::debug("Destroying <Attribute> -> '{}'", name);
    vector<pair<string, int>>::iterator b_it;
    for (b_it = base_lineage.begin(); b_it != base_lineage.end(); b_it++) {
        delete &b_it;
    }

    vector<pair<string, int>>::iterator m_it;
    for (m_it = modifier_lineage.begin(); m_it != modifier_lineage.end(); m_it++) {
        delete &m_it;
    }
};

void Attribute::set_name(string called)
{
    name = called;
};

int Attribute::get()
{
    return current;
};

int Attribute::total()
{
    pair<string, int> latest_base = *base_lineage.begin();
    pair<string, int> latest_modifier = *modifier_lineage.begin();
    return latest_base.second + latest_modifier.second;
};

int Attribute::get_base()
{
    pair<string, int> latest = *base_lineage.begin();
    return latest.second;
};

int Attribute::get_modifier()
{
    pair<string, int> latest = *modifier_lineage.begin();
    return latest.second;
};

int Attribute::update_base(string reason, int delta)
{
    pair<string, int> latest_base = *base_lineage.begin();
    int new_value = latest_base.second += delta;
    pair<string, int> new_base = pair<string, int>(reason, new_value);
    base_lineage.push_back(new_base);

    int delta = new_base.second - latest_base.second;
    current += delta;
};

int Attribute::update_modifier(string reason, int new_value)
{
    pair<string, int> latest_modifier = *modifier_lineage.begin();
    pair<string, int> new_modifier = pair<string, int>(reason, new_value);
    modifier_lineage.push_back(new_modifier);

    int delta = new_modifier.second - latest_modifier.second;
    current += delta;
};

bool Attribute::update_current(int delta)
{
    bool is_zero = false;
    if (current + delta <= 0) {
        is_zero = true;
        current = 0;
    } else {
        current += delta;
    }
    return is_zero;
};