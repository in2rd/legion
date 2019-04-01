
#include "entity/EntityAlignment.hpp"
#include "entity/EntityAttributes.hpp"
#include "entity/EntityGender.hpp"
#include "entity/EntityName.hpp"
#include "entity/EntitySize.hpp"
#include "globals/DamageState.hpp"
#include "globals/TransitionState.hpp"

#ifndef ENTITY_H_
#define ENTITY_H_

class Entity {
protected:
    entity_name_t name;
    entity_gender_t gender;
    entity_size_t size;

    EntityAttributes attributes;
    EntityAlignment alignment;

    damage_state_t damage_state;
    transition_state_t transition_state;

public:
    Entity();
    ~Entity();

    bool update_transition(transition_state_t);
    int update_health(int amount);
};

#endif