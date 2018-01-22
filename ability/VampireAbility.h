#ifndef VAMPIRE_ABILITY_H
#define VAMPIRE_ABILITY_H

#include "Ability.h"
#include "../unit/Vampire.h"

class Vampire;

class VampireAbility : public Ability {
    public:
        VampireAbility(Unit* unit);
        virtual ~VampireAbility();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

#endif // VAMPIRE_ABILITY_H