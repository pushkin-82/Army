#ifndef PRIEST_H
#define PRIEST_H

#include "Spellcaster.h"
#include "../spell/Heal.h"

class Priest : public Spellcaster {
    public:
        Priest(std::string title="Priest", int hitPointsLimit=100, int damage=10, int mana=50);
        virtual ~Priest();
};

#endif // PRIEST_H