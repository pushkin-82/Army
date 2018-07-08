#ifndef HEALER_H
#define HEALER_H

#include "Spellcaster.h"
#include "../spell/Heal.h"

class Healer : public Spellcaster {
    public:
        Healer(std::string title="Healer", int hitPointsLimit=100, int damage=10, int mana=50);
        virtual ~Healer();
};

#endif // HEALER_H