#ifndef SOLDIER_ABILITY_H
#define SOLDIER_ABILITY_H

#include "Ability.h"

class SoldierAbility : public Ability {
    public:
        SoldierAbility(Unit* unit);
        virtual ~SoldierAbility();
};

#endif // SOLDIER_ABILITY_H
