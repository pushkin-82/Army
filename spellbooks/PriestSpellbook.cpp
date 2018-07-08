#include "PriestSpellbook.h"

PriestSpellbook::PriestSpellbook() : Spellbook() {
    this->addSpell(HEAL);
    this->addSpell(MAGIC_ARROW);
}

PriestSpellbook::~PriestSpellbook() {}