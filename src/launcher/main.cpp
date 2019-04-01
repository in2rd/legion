#include "globals/Dice.hpp"
#include <iostream>
#include <spdlog/spdlog.h>

int main(int argc, char* argv[])
{
    spdlog::set_level(spdlog::level::debug);
    spdlog::set_pattern("[%H:%M:%S%z][%m/%d/%Y]-[%^ %l %$]-[process %P]-[thread %t]::[ %v ]");
    Dice dice = Dice();
    std::cout << dice.roll(dice_t::D100) << std::endl;
    return 0;
}