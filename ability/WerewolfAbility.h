#ifndef WEREWOLF_ABILITY_H
#define WEREWOLF_ABILITY_H

#include "Ability.h"

class Werewolf;

class WerewolfAbility : public Ability {
    public:
        WerewolfAbility(Unit* unit);
        virtual ~WerewolfAbility();
};

#endif // WEREWOLF_ABILITY_H