#ifndef DAEMON_ABILITY_H
#define DAEMON_ABILITY_H

#include "Ability.h"

class DaemonAbility : public Ability {
    public:
        DaemonAbility(Unit* unit);
        virtual ~DaemonAbility();
};

#endif // DAEMON_ABILITY_H
