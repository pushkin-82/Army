#include "Ability.h"

Ability::Ability(Unit* unit) {
	this->unit = unit;
}

Ability::~Ability() {}

void Ability::attack(Unit* enemy) {
	this->unit->ensureIsAlive();
	enemy->takeDamage(this->unit->getDamage());
	enemy->counterAttack(this->unit);
}

void Ability::counterAttack(Unit* enemy) {
	this->unit->ensureIsAlive();
	enemy->takeDamage(this->unit->getDamage() / 2);
}
