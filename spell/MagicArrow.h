#ifndef MAGIC_ARROW_H
#define MAGIC_ARROW_H

#include "Spell.h"

class MagicArrow : public Spell {
    public:
        MagicArrow(std::string title="Magic Arrow", int cost=5, int points=10);
        virtual ~MagicArrow();

        virtual void action(Unit* target);
};

#endif // MAGIC_ARROW_H