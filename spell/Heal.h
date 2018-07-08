#ifndef HEAL_H
#define HEAL_H

#include "Spell.h"

class Heal : public Spell {
    public:
        Heal(std::string title="Heal", int cost=5, int points=10);
        virtual ~Heal();

        virtual void action(Unit* target);
};

#endif // HEAL_H