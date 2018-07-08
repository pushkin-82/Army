#include "WarlockSpellbook.h"

WarlockSpellbook::WarlockSpellbook() : Spellbook() {
    this->addSpell(MAGIC_ARROW);
    this->addSpell(SUMMON);
}

WarlockSpellbook::~WarlockSpellbook() {}