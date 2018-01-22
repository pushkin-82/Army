#ifndef ROGUE_ABILITY_H
#define ROGUE_ABILITY_H

#include "Ability.h"

class RogueAbility : public Ability {
    public:
        RogueAbility(Unit* unit);
        virtual ~RogueAbility();

        virtual void attack(Unit* enemy);
};

#endif // ROGUE_ABILITY_H
