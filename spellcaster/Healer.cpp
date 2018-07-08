#include "Healer.h"
#include "../spellbooks/HealerSpellbook.h"

Healer::Healer(std::string title, int hitPointsLimit, int damage, int mana)
    : Spellcaster(title, hitPointsLimit, damage, mana) {
        this->spell = new Heal();
        this->spellbook = new HealerSpellbook();
    }

Healer::~Healer() {}
