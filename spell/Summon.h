#ifndef SUMMON_DAEMON_H
#define SUMMON_DAEMON_H

#include "Spell.h"

class Summon : public Spell {
    public:
        Summon(std::string title = "Summon daemon", int cost = 20, int points = 80);
        virtual ~Summon();
};

#endif // SUMMON_DAEMON_H