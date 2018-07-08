#include "NecromancerSpellbook.h"

NecromancerSpellbook::NecromancerSpellbook() : Spellbook() {
    this->addSpell(MAGIC_ARROW);
    this->addSpell(DEATH_WAVE);
}

NecromancerSpellbook::~NecromancerSpellbook() {}