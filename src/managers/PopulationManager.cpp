#include "managers/PopulationManager.hpp"
#include "entity/Entity.hpp"
#include <list>

PopulationManager::PopulationManager()
{
    population = std::list<Entity*>();
};

PopulationManager::PopulationManager(std::list<Entity*> existing)
{
    population = existing;
};

PopulationManager::~PopulationManager()
{
    // Destroy Entity objects via references in list
    for (std::list<Entity*>::iterator it = population.begin(); it != population.end(); ++it) {
        delete *it;
    }
};
