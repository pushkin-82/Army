#include "Ability.h"

Ability::Ability(Unit* unit) {
	this->unit = unit;
}

Ability::~Ability() {}

void Ability::attack(Unit* enemy) {
	this->unit->ensureIsAlive();

    std::cout << this->unit->getTitle() << " attacks " << enemy->getTitle() << "\n" << std::endl;

	enemy->takeDamage(this->unit->getDamage());

    std::cout << enemy->getTitle() << " counterattacks " << this->unit->getTitle() << "\n" << std::endl;

	enemy->counterAttack(this->unit);

    std::cout << *(this->unit) << std::endl;
    std::cout << *enemy << std::endl;
    std::cout << "----------------" << std::endl;
}

void Ability::counterAttack(Unit* enemy) {
	this->unit->ensureIsAlive();
	enemy->takeDamage(this->unit->getDamage() / 2);
}
