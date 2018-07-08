#include "Berserker.h"

Berserker::Berserker(std::string title, int hitPointsLimit, int damage):
	Unit(title, hitPointsLimit, damage) {
		this->ability = new BerserkerAbility(this);
    }

Berserker::~Berserker() {
    delete this->ability;
}

void Berserker::addHitPoints(int hp) {
	this->ensureIsAlive();
	throw TotalMagicResistanceException();
}
void Berserker::takeMagicDamage(int dmg) {
	this->ensureIsAlive();
	throw TotalMagicResistanceException();
}
