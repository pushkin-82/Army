#include "RogueAbility.h"

RogueAbility::RogueAbility(Unit* unit): Ability(unit) {}
RogueAbility::~RogueAbility() {}

void RogueAbility::attack(Unit* enemy) {
	this->unit->ensureIsAlive();
	enemy->takeDamage(this->unit->getDamage());
}
