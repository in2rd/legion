#include <map>

#ifndef DICE_H_
#define DICE_H_

enum class dice_t {
    D4,
    D6,
    D8,
    D10,
    D12,
    D20,
    D100
};

class Dice {
private:
    std::map<dice_t, int> die_values;
    int generate(int);

public:
    Dice();
    ~Dice();
    int roll(dice_t);
};

#endif