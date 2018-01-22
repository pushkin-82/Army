#ifndef ABILITY_H
#define ABILITY_H

#include "../unit/Unit.h"

class Unit;

class Ability {
    protected:
        Unit* unit;
    public:
        Ability(Unit* unit);
        virtual ~Ability();
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

#endif //ABILITY_H
