#include "sentient/Sentient.hpp"

Sentient::Sentient()
    : Entity()
{
    num_legs = 0;
    num_arms = 0;
    num_heads = 0;

    classification = sentient_classification_t::UNKNOWN;
};

Sentient::~Sentient() {};

int Sentient::get_arms(void)
{
    return num_arms;
};

int Sentient::get_legs(void)
{
    return num_legs;
};

int Sentient::get_heads(void)
{
    return num_heads;
};