#include "races/Human.hpp"
#include "sentient/Sentient.hpp"

Human::Human()
    : Sentient()
{
    num_arms = 2;
    num_legs = 1;
    num_heads = 1;

    size = entity_size_t::AVERAGE;
    classification = sentient_classification_t::HUMANOID;
};

Human::~Human() {};