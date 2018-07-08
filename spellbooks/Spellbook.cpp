#include "Spellbook.h"

Spellbook::Spellbook() {
    this->spellbook = new std::map<spells, Spell*>();
}

Spellbook::~Spellbook() {}

void Spellbook::addSpell(spells spell) {
    switch(spell) {
        case(MAGIC_ARROW):
            this->spellbook->insert(std::pair<spells, Spell*>(spell, new MagicArrow()));
            break;
        case(HEAL):
            this->spellbook->insert(std::pair<spells, Spell*>(spell, new Heal()));
            break;
        case(SUMMON):
            this->spellbook->insert(std::pair<spells, Spell*>(spell, new Summon()));
            break;
        case(DEATH_WAVE):
            this->spellbook->insert(std::pair<spells, Spell*>(spell, new DeathWave()));
            break;
    }
}

void Spellbook::deleteSpell(spells spell) {
    this->spellbook->erase(spell);
}

std::ostream& operator<<(std::ostream& out, const Spellbook& spellbook) {
    std::map<spells, Spell*>::iterator it;
    out << "Spells in the Spellbook: " << "\n";
    for ( it = spellbook.spellbook->begin(); it != spellbook.spellbook->end(); ++it ) {
        out << it->second->getTitle() << "\n";
    }

    return out;
}
