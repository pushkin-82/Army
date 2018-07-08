#include "Wizard.h"
#include "../spellbooks/WizardSpellbook.h"

Wizard::Wizard(std::string title, int hitPointsLimit, int damage, int mana)
    : Spellcaster(title, hitPointsLimit, damage, mana) {
        this->spell = new MagicArrow();
        this->spellbook = new WizardSpellbook();
        this->setBattleMageState(true);
    }

Wizard::~Wizard() {}

