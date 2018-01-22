#include "VampireAbility.h"

#define SOAKED_BLOOD_COEF 4

VampireAbility::VampireAbility(Unit* unit): Ability(unit) {}
VampireAbility::~VampireAbility() {}

void VampireAbility::attack(Unit* enemy) {
	int soakedBlood;
	int enemyHP = enemy->getHitPoints();
	int damage = this->unit->getDamage();

	this->unit->ensureIsAlive();

	if ( enemyHP < damage ) {
		soakedBlood = ( damage - enemyHP ) / SOAKED_BLOOD_COEF;
	} else {
		soakedBlood = damage / SOAKED_BLOOD_COEF;
	}
	enemy->takeDamage(this->unit->getDamage());
	this->unit->addHitPoints(soakedBlood);
	// enemy = Vampire::turnToVampire(enemy);
}

void VampireAbility::counterAttack(Unit* enemy) {
	int soakedBlood;
	int enemyHP = enemy->getHitPoints();
	int damage = this->unit->getDamage();

 	this->unit->ensureIsAlive();
 	
	if ( enemyHP < damage ) {
		soakedBlood = ( damage - enemyHP ) / SOAKED_BLOOD_COEF;
	} else {
		soakedBlood = damage / SOAKED_BLOOD_COEF;
	}

	enemy->takeDamage(this->unit->getDamage() / 2);
}
