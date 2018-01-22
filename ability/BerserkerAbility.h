#ifndef BERSERKER_ABILITY_H
#define BERSERKER_ABILITY_H

#include "Ability.h"

class BerserkerAbility : public Ability {
    public:
        BerserkerAbility(Unit* unit);
        virtual ~BerserkerAbility();
};

#endif // BERSERKER_ABILITY_H
