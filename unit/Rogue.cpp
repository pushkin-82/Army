#include "Rogue.h"

Rogue::Rogue(std::string title, int hitPointsLimit, int damage):
	Unit(title, hitPointsLimit, damage) {
		this->ability = new RogueAbility(this);
	}
    
Rogue::~Rogue() {
    delete this->ability;
}
