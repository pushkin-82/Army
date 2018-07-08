#include "WizardSpellbook.h"

WizardSpellbook::WizardSpellbook() : Spellbook() {
    this->addSpell(MAGIC_ARROW);
    this->addSpell(HEAL);
}

WizardSpellbook::~WizardSpellbook() {}