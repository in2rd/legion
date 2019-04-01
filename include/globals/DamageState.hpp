#ifndef DAMAGESTATE_H_
#define DAMAGESTATE_H_

enum class damage_state_t {
    HEALTHY = 0x01,
    SLIGHT_INJURY = 0x02,
    MAJOR_INJURY = 0x03,
    MORTAL_INJURY = 0x04,
    DEAD = 0x0f,
    OFF = 0x1f
};

#endif