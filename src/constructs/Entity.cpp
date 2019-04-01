#include "entity/Entity.hpp"
#include "entity/EntityAlignment.hpp"
#include "entity/EntityAttributes.hpp"
#include "entity/EntityGender.hpp"
#include "globals/DamageState.hpp"
#include "globals/TransitionState.hpp"

Entity::Entity()
{
    attributes = EntityAttributes();

    size = entity_size_t::AVERAGE;
    gender = entity_gender_t::UNKNOWN;

    damage_state = damage_state_t::HEALTHY;
    transition_state = transition_state_t::STATIONARY;

    alignment = EntityAlignment(alignment_core_t::NEUTRAL, alignment_adherence_t::NEUTRAL);
};

Entity::~Entity()
{
    attributes.~EntityAttributes();
};

bool Entity::update_transition(transition_state_t new_state)
{
    if (damage_state != damage_state_t::DEAD || damage_state != damage_state_t::OFF) {
        transition_state = new_state;
        return true;
    }
    return false;
}

int Entity::update_health(int amount)
{
    // Is the entity's health 0 or less? i.e. dead?
    bool is_zero = attributes.update("health", amount);
    if (is_zero == true) {
        damage_state = damage_state_t::DEAD;
        transition_state = transition_state_t::STATIONARY;
    }

    return attributes.get("health");
};