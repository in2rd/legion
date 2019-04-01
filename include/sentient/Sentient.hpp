#include "entity/Entity.hpp"
#include "sentient/SentientClassification.hpp"

#ifndef SENTIENT_H_
#define SENTIENT_H_

class Sentient : public Entity {
protected:
    sentient_classification_t classification;

    bool num_legs;
    bool num_arms;
    bool num_heads;

public:
    Sentient();
    ~Sentient();
    int get_arms(void);
    int get_legs(void);
    int get_heads(void);
};

#endif