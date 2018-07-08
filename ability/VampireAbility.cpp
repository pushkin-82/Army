#include "VampireAbility.h"

VampireAbility::VampireAbility(Unit* unit): Ability(unit) {}
VampireAbility::~VampireAbility() {}

void VampireAbility::turnToVampire(Unit* enemy) {
	VampireAbility* vampireAbility = new VampireAbility(enemy);

	std::string newName = "Undead_";

    if ( enemy->isUndead() ) {
        // throw CanNotTurnToVampireException();
        std::cout << enemy->getTitle() << " can't turn to vampire" << std::endl;
    } else {
		std::cout << enemy->getTitle() << " became Undead" << std::endl;
	    enemy->setAbility(vampireAbility);
	    enemy->setUndeadState(true);
	    newName.append(enemy->getTitle());
	    enemy->setTitle(newName);
    }

}

void VampireAbility::attack(Unit* enemy) {
	int soakedBlood;
	int enemyHP = enemy->getHitPoints();
	int damage = this->unit->getDamage();

	this->unit->ensureIsAlive();

    std::cout << this->unit->getTitle() << " attacks " << enemy->getTitle() << "\n" << std::endl;

	if ( enemyHP < damage ) {
		soakedBlood = ( damage - enemyHP ) / SOAKED_BLOOD_COEF;
	} else {
		soakedBlood = damage / SOAKED_BLOOD_COEF;
	}
	
	enemy->takeDamage(this->unit->getDamage());
	this->unit->addHitPoints(soakedBlood);
	this->turnToVampire(enemy);

    std::cout << enemy->getTitle() << " can't counterattacks " << this->unit->getTitle() << "\n" << std::endl;

    std::cout << *(this->unit) << std::endl;
    std::cout << *enemy << std::endl;
    std::cout << "----------------" << std::endl;
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
