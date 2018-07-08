#ifndef MAGIC_STATE_H
#define MAGIC_STATE_H

#include <iostream>
#include "../exceptions.h"
#include "BattleMage.h"

class MagicState : public BattleMage {
    protected:
        int mana;
        int manaLimit;

    public:
        MagicState(int manaLimit);
        virtual ~MagicState();

        int getMana();
        int getManaLimit();

        int setManaLimit(int manaLimit);

        void spendMana(int cost);
        void addMana(int incMana);
};

#endif //MAGIC_STATE_H