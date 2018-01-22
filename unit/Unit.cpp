#include "Unit.h"

Unit::Unit(const char* title, int hitPointsLimit, int damage) {
	this->state = new State(title, hitPointsLimit, damage);
}

Unit::~Unit() {}

const char* Unit::getTitle() const {
	return this->state->getTitle();
}

int Unit::getHitPoints() const {
	return this->state->getHitPoints();
}

int Unit::getHitPointsLimit() const {
	return this->state->getHitPointsLimit();
}

int Unit::getDamage() const {
	return this->state->getDamage();
}


void Unit::ensureIsAlive() {
	this->state->ensureIsAlive();
}


void Unit::addHitPoints(int hp) {
	this->state->addHitPoints(hp);
}

void Unit::takeDamage(int dmg) {
	this->state->takeDamage(dmg);
}

void Unit::takeMagicDamage(int dmg) {
	this->state->takeMagicDamage(dmg);
}

void Unit::attack(Unit* enemy) {
	this->ability->attack(enemy);
}

void Unit::counterAttack(Unit* enemy) {
	this->ability->counterAttack(enemy);
}
