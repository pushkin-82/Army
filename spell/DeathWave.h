#ifndef ARMY_DEATHWAVE_H
#define ARMY_DEATHWAVE_H

#include "Spell.h"

class DeathWave : public Spell {
    public:
    DeathWave(std::string title="Death Wave", int cost=5, int points=10);
    virtual ~DeathWave();
    
    virtual void action(Unit* target);
};

#endif //ARMY_DEATHWAVE_H
