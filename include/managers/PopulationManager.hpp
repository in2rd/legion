#include "entity/Entity.hpp"
#include <list>

#ifndef POPULATIONMANAGER_H_
#define POPULATIONMANAGER_H_

class PopulationManager {
private:
    std::list<Entity*> population;

public:
    PopulationManager();
    PopulationManager(std::list<Entity*>);
    ~PopulationManager();
    bool add_entity(Entity);
    bool clear(void);
    int count(void);
};

#endif