#include "MagicArrow.h"
#include "../spellcaster/Spellcaster.h"

MagicArrow::MagicArrow(std::string title, int cost, int points) : Spell(title, cost, points) {}
MagicArrow::~MagicArrow() {}

void MagicArrow::action(Unit* target) {
    if ( this->getSpellcaster()->isBattleMage() ) {
        target->takeMagicDamage(this->points);
    } else {
        target->takeMagicDamage(this->points/2);
    }
}
