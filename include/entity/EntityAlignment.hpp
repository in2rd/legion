#include <string>

#ifndef ENTITYALIGNMENT_H_
#define ENTITYALIGNMENT_H_

enum class alignment_impact_t {
    MINISCULE,
    MINOR,
    MAJOR,
    VISIONARY
};

enum class alignment_adherence_t {
    NEUTRAL,
    LAWFUL,
    CHAOTIC
};

enum class alignment_core_t {
    NEUTRAL,
    GOOD,
    EVIL
};

struct alignment_t {
    alignment_core_t core;
    alignment_adherence_t adherence;
};

class EntityAlignment {
private:
    int core_score;
    int adherence_score;
    alignment_core_t core;
    alignment_adherence_t adherence;
    alignment_t update();
    int determine_modifier(alignment_impact_t);
    std::string to_string();

public:
    EntityAlignment();
    EntityAlignment(alignment_core_t, alignment_adherence_t);
    alignment_t negative(alignment_impact_t, bool, bool);
    alignment_t positive(alignment_impact_t, bool, bool);
};

#endif