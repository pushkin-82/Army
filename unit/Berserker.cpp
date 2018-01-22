#include "Berserker.h"

Berserker::Berserker(const char* title, int hitPointsLimit, int damage):
	Unit(title, hitPointsLimit, damage) {
		this->ability = new BerserkerAbility(this);
}
Berserker::~Berserker() {}

void Berserker::addHitPoints(int hp) {
	this->ensureIsAlive();
	throw TotalMagicResistanceException();
}
void Berserker::takeMagicDamage(int dmg) {
	this->ensureIsAlive();
	throw TotalMagicResistanceException();
}
