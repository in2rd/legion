#include "globals/Dice.hpp"
#include <iostream>
#include <random>
#include <spdlog/spdlog.h>
#include <utility>

using namespace std;

Dice::Dice()
{
    die_values = {
        { dice_t::D4, 4 },
        { dice_t::D6, 6 },
        { dice_t::D8, 8 },
        { dice_t::D10, 10 },
        { dice_t::D12, 12 },
        { dice_t::D20, 20 },
        { dice_t::D100, 100 }
    };
};
Dice::~Dice()
{
    die_values.~map();
};

int Dice::generate(int max)
{
    random_device randdev;
    mt19937 engine(randdev());
    uniform_int_distribution<> distribution(0, max);
    return distribution(engine);
};

int Dice::roll(dice_t type)
{
    map<dice_t, int>::iterator it = die_values.find(type);
    int result = generate(it->second);
    spdlog::debug("Rolling a 1d{} -> {}", it->second, result);
    return result;
};