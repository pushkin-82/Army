#include "Rogue.h"

Rogue::Rogue(const char* title, int hitPointsLimit, int damage):
	Unit(title, hitPointsLimit, damage) {
		this->ability = new RogueAbility(this);
	}
Rogue::~Rogue() {}
