#include "Priest.h"
#include "../spellbooks/PriestSpellbook.h"

Priest::Priest(std::string title, int hitPointsLimit, int damage, int mana)
    : Spellcaster(title, hitPointsLimit, damage, mana) {
        this->spell = new Heal();
        this->spellbook = new PriestSpellbook();
    }

Priest::~Priest() {}
