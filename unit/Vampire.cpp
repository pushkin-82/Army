#include "Vampire.h"

Vampire::Vampire(std::string title, int hitPointsLimit, int damage) :
	Unit(title, hitPointsLimit, damage) {
		this->ability = new VampireAbility(this);
		this->setUndeadState(true);
	}

Vampire::~Vampire() {
    delete this->ability;
}

// void Vampire::turnToVampire(Unit* enemy) {
//     this->ability->turnToVampire(enemy);
// }