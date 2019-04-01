#include "entity/EntityAlignment.hpp"
#include <string>

EntityAlignment::EntityAlignment()
{
    core_score = 0;
    adherence_score = 0;

    core = alignment_core_t::NEUTRAL;
    adherence = alignment_adherence_t::NEUTRAL;
};

EntityAlignment::EntityAlignment(
    alignment_core_t assigned_core,
    alignment_adherence_t assigned_adherence)
{
    core = assigned_core;
    assigned_adherence = assigned_adherence;

    switch (assigned_core) {
    case alignment_core_t::NEUTRAL:
        core_score = 0;
        break;
    case alignment_core_t::GOOD:
        core_score = 25;
        break;
    case alignment_core_t::EVIL:
        core_score = -25;
        break;
    }

    switch (assigned_adherence) {
    case alignment_adherence_t::NEUTRAL:
        adherence_score = 0;
        break;
    case alignment_adherence_t::LAWFUL:
        adherence_score = 25;
        break;
    case alignment_adherence_t::CHAOTIC:
        adherence_score = -25;
        break;
    }
};

alignment_t EntityAlignment::update()
{
    if (core_score <= -25) {
        core = alignment_core_t::EVIL;
    }

    if (core_score > -25 && core_score < 25) {
        core = alignment_core_t::NEUTRAL;
    }

    if (core_score >= 25) {
        core = alignment_core_t::GOOD;
    }

    if (adherence_score <= -25) {
        adherence = alignment_adherence_t::CHAOTIC;
    }

    if (adherence_score > -25 && adherence_score < 25) {
        adherence = alignment_adherence_t::NEUTRAL;
    }

    if (adherence_score >= 25) {
        adherence = alignment_adherence_t::LAWFUL;
    }

    alignment_t new_alignment;
    new_alignment.core = core;
    new_alignment.adherence = adherence;
    return new_alignment;
};

int EntityAlignment::determine_modifier(alignment_impact_t impact)
{
    int score_modifier = 0;
    switch (impact) {
    case alignment_impact_t::MINISCULE:
        score_modifier = 1;
        break;
    case alignment_impact_t::MINOR:
        score_modifier = 3;
        break;
    case alignment_impact_t::MAJOR:
        score_modifier = 10;
        break;
    case alignment_impact_t::VISIONARY:
        score_modifier = 25;
        break;
    }

    return score_modifier;
};

alignment_t EntityAlignment::negative(
    alignment_impact_t impact,
    bool affects_core,
    bool affects_adherence)
{
    int score_modifier = determine_modifier(impact);

    if (affects_core == true) {
        core_score -= score_modifier;
    }

    if (affects_adherence == true) {
        adherence_score -= score_modifier;
    }

    update();

    alignment_t new_alignment;
    new_alignment.core = core;
    new_alignment.adherence = adherence;
    return new_alignment;
};

alignment_t EntityAlignment::positive(alignment_impact_t impact, bool affects_core, bool affects_adherence)
{
    int score_modifier = determine_modifier(impact);

    if (affects_core == true) {
        core_score += score_modifier;
    }

    if (affects_adherence == true) {
        adherence_score += score_modifier;
    }

    update();

    alignment_t new_alignment;
    new_alignment.core = core;
    new_alignment.adherence = adherence;
    return new_alignment;
};

std::string EntityAlignment::to_string()
{
    std::string core_str = "";
    std::string adherence_str = "";

    switch (adherence) {
    case alignment_adherence_t::NEUTRAL:
        adherence_str = "Neutral";
        break;
    case alignment_adherence_t::LAWFUL:
        adherence_str = "Lawful";
        break;
    case alignment_adherence_t::CHAOTIC:
        adherence_str = "Chaotic";
        break;
    }

    switch (core) {
    case alignment_core_t::NEUTRAL:
        core_str = "Neutral";
        break;
    case alignment_core_t::GOOD:
        core_str = "Good";
        break;
    case alignment_core_t::EVIL:
        core_str = "Evil";
        break;
    }

    if (core_str == "Neutral" && adherence_str == "Neutral") {
        core_str = "";
    }

    return adherence_str + core_str;
};