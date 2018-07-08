#ifndef WIZARD_H
#define WIZARD_H

#include "Spellcaster.h"
#include "../spell/MagicArrow.h"

class Wizard : public Spellcaster {
    public:
        Wizard(std::string title="Wizard", int hitPointsLimit=100, int damage=10, int mana=50);
        virtual ~Wizard();
};

#endif // WIZARD_H