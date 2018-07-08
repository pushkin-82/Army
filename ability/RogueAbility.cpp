#include "RogueAbility.h"

RogueAbility::RogueAbility(Unit* unit): Ability(unit) {}
RogueAbility::~RogueAbility() {}

void RogueAbility::attack(Unit* enemy) {
	this->unit->ensureIsAlive();

    std::cout << this->unit->getTitle() << " attacks " << enemy->getTitle() << "\n" << std::endl;

    enemy->takeDamage(this->unit->getDamage());

    std::cout << enemy->getTitle() << " can't counterattacks " << this->unit->getTitle() << "\n" << std::endl;

    std::cout << *(this->unit) << std::endl;
    std::cout << *enemy << std::endl;
    std::cout << "----------------" << std::endl;

}
