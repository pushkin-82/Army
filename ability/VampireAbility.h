#ifndef VAMPIRE_ABILITY_H
#define VAMPIRE_ABILITY_H

#define SOAKED_BLOOD_COEF 2

#include "Ability.h"
#include "../exceptions.h"

class Vampire;

class VampireAbility : public Ability {
    public:
        VampireAbility(Unit* unit);
        virtual ~VampireAbility();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
    private:
        void turnToVampire(Unit* enemy);
};

#endif // VAMPIRE_ABILITY_H