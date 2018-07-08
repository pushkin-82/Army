#include "DeathWave.h"
#include "../spellcaster/Spellcaster.h"

DeathWave::DeathWave(std::string title, int cost, int points) : Spell(title, cost, points) {}
DeathWave::~DeathWave() {}

void DeathWave::action(Unit* target) {
    if ( target->isUndead() ) {
        std::cout << "Death wave doesn't affect the undead" << std::endl;
    } else {
        if ( this->getSpellcaster()->isBattleMage() ) {
            target->takeMagicDamage(this->points);
        } else {
            target->takeMagicDamage(this->points/2);
        }
    }
}
