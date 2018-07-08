#include "Heal.h"
#include "../spellcaster/Spellcaster.h"

Heal::Heal(std::string title, int cost, int points) : Spell(title, cost, points) {}
Heal::~Heal() {}

void Heal::action(Unit* target) {
    if ( this->getSpellcaster()->isBattleMage() ) {
        target->addHitPoints(this->points/2);
    } else {
        target->addHitPoints(this->points);
    }
}
